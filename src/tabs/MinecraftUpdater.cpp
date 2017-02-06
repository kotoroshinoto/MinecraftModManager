/*
 * MinecraftUpdater.cpp
 *
 *  Created on: Aug 31, 2012
 *      Author: Michael
 */

#include "MinecraftUpdater.h"

wxString MinecraftUpdater::updatesite = "http://s3.amazonaws.com/MinecraftDownload/";
wxString MinecraftUpdater::loginsite = "https://login.minecraft.net/";
MinecraftUpdateLocation MinecraftUpdater::location_info;

void MinecraftFileList::clear(){
//	this->istruncated=false;
	this->list.clear();
//	this->maxkeys=0;
//	this->name.Clear();
}

void MinecraftFile::clear(){
	this->path.clear();
	this->lastmodified.clear();
	this->etag.clear();
	this->size=0;
	this->storageclass.clear();
}

void MinecraftUpdater::SetLocation(wxString& location){
	MinecraftUpdater::location_info.manifestfull=false;
	MinecraftUpdater::location_info.manifest.first.clear();
	MinecraftUpdater::location_info.manifest.second.clear();
	MinecraftUpdater::location_info.path=wxFileName::DirName(location);
}

void MinecraftUpdater::SetLocation(wxFileName& location){
	MinecraftUpdater::location_info.manifestfull=false;
	MinecraftUpdater::location_info.manifest.first.clear();
	MinecraftUpdater::location_info.manifest.second.clear();
	MinecraftUpdater::location_info.path=location;
}

bool MinecraftUpdater::NeedsUpdate() {
	MinecraftUpdater::ObtainFileList();
	MinecraftUpdater::FillManifest();
	return MinecraftUpdater::location_info.manifestfull;
	//TODO IMPLEMENT VERSION CHECK
}

bool MinecraftUpdater::Update() {
	MinecraftUpdater::ObtainFileList();
	MinecraftUpdater::FillManifest();
	if(! MinecraftUpdater::location_info.manifestfull){
		wxLogMessage(wxT("Manifest Not Populated!"));
		return false;
	}
	bool OK=true;
	wxString url;
	wxString natives;
#if defined(__WINDOWS__)
	natives=wxT("windows_natives.jar");
#elif defined(__APPLE__)
	natives=wxT("macosx_natives.jar");
#elif defined(__LINUX__)
	natives=wxT("linux_natives.jar");
#elif defined(__SOLARIS__)
	natives=wxT("solaris_natives.jar");
#else
	natives=wxT("");
	wxLogFatalError(wxT("YOUR OS IS NOT SUPPORTED BY MINECRAFT!!!!"));
#endif
	for(size_t i=0; OK && i<MinecraftUpdater::location_info.manifest.second.size(); ++i) {
		url = MinecraftUpdater::updatesite;
		url += MinecraftUpdater::location_info.manifest.first.list[i].path;
		wxString message;
		//std::wcout << "Ensuring directory location exists for:" << manifest.second[i].GetFullPath() << std::endl;
		message += wxT("Downloading ") + url + wxT(" to ") + MinecraftUpdater::location_info.manifest.second[i].GetFullPath();
		std::wcout << message << std::endl;
		//TODO turn this back on when fixed
		OK=MinecraftUtils::GetFile(url, MinecraftUpdater::location_info.manifest.second[i]);
		if(OK){
			std::wcout << wxT("Download Complete!") << std::endl;
		} else {
			std::wcout << wxT("Download Failed!") << std::endl;
			return false;
		}
	}
	//unzip natives jar
	wxFileName nativepath=MinecraftUpdater::location_info.path;
	nativepath.AppendDir(wxT(".minecraft"));
	nativepath.AppendDir(wxT("bin"));
	nativepath.SetFullName(natives);
	std::wcout << wxT("Unzipping the natives archive!") << std::endl;
	if(UnzipNatives(nativepath)) {
		std::wcout << wxT("Unzip Complete!") << std::endl;
	} else{
		std::wcout << wxT("Unzip Failed!") << std::endl;
		return false;
	}
	return OK;
}

bool MinecraftUpdater::UnzipNatives(wxFileName& natives) {
	wxFileName sourcejar=natives,destpath,destfile;
	destpath=sourcejar;
	destpath.AppendDir(wxT("natives"));
	destpath.SetFullName(wxT(""));
	if(!destpath.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL)){
		std::wcout << "could not create natives directory" << std::endl;
		return false;
	}
	bool ret = true;
	bool somethingdone=false;
	//wxFileSystem fs;
	std::unique_ptr<wxZipEntry> entry(new wxZipEntry());
	std::wcout << "attempting to extract \n" <<  natives.GetFullPath() << "\n as a zip file to location: \n" <<  destpath.GetFullPath()  << std::endl;
	//TODO why is this do/while loop even here?
	do {

		wxFileInputStream in((natives.GetFullPath()));

		if (!in) {
			wxLogError(_T("Can not open file '")+natives.GetFullPath()+_T("'."));
			ret = false;
			break;
		}
		wxZipInputStream zip(in);

		while (entry.reset(zip.GetNextEntry()), entry.get() != NULL) {
			somethingdone=true;
			// access meta-data
			wxString name = entry->GetName();
			name = destpath.GetFullPath() + wxFileName::GetPathSeparator() + name;

			// read 'zip' to access the entry's data
			std::wcout << wxT("Examining Entry: ") << entry->GetName() << std::endl;
			if(! entry->GetName().StartsWith(wxT("META-INF")) ){
				std::wcout << wxT("Entry is NOT part of META-INF, EXTRACTING IT") << std::endl;
				if (entry->IsDir()) {
					int perm = entry->GetMode();
					wxFileName::Mkdir(name, perm, wxPATH_MKDIR_FULL);
				} else {
					zip.OpenEntry(*entry.get());
					if (!zip.CanRead()) {
						wxLogError(_T("Can not read zip entry '") + entry->GetName() + _T("'."));
						ret = false;
						break;
					}

					wxFileOutputStream file(name);

					if (!file) {
						wxLogError(_T("Can not create file '")+name+_T("'."));
						ret = false;
						break;
					}
					zip.Read(file);
				}
			} else {
				std::wcout << wxT("Entry is part of META-INF, IGNORING IT") << std::endl;
			}
		}
	} while(false);//TODO <--- WHY?
	if(!somethingdone){
		std::wcout << "No files were extracted, first entry must have been null!" << std::endl;
	}
	return ret;
}

std::pair<MinecraftFileList,std::vector<wxFileName> >& MinecraftUpdater::GetManifest(){
	return MinecraftUpdater::location_info.manifest;
}

MinecraftFileList& MinecraftUpdater::GetFileList(){
	return MinecraftUpdater::location_info.manifest.first;
}

MinecraftFile::MinecraftFile(MCraftXmlContents input){
	this->path=input.Key;
	this->lastmodified=input.LastModified;
	this->etag=input.ETag;
	this->storageclass=input.StorageClass;
	wxStringInputStream sis(input.Size);
	wxStdInputStream ss(sis);
	ss >> this->size;
}

bool MinecraftUpdater::ObtainFileList(){
	std::vector<MCraftXmlContents> content_nodes;
	bool success = MinecraftUtils::GetXMLPageContent(MinecraftUpdater::updatesite, content_nodes);
	if(!success){return false;}
	for(std::size_t i=0; i < content_nodes.size() ;i++){
		{
			MinecraftFile f(content_nodes[i]);
			MinecraftUpdater::location_info.manifest.first.list.push_back(f);
		}
	}
	MinecraftUpdater::location_info.manifest.first.CleanList();
	return true;
}

void MinecraftUpdater::FillManifest() {
	wxFileName path=MinecraftUpdater::location_info.path;
	wxFileName dest;
	path.AppendDir(".minecraft");
	std::pair<MinecraftFileList,std::vector<wxFileName> >& manifest=MinecraftUpdater::location_info.manifest;
	for(size_t i=0;i<manifest.first.list.size();++i) {
		dest=path;
		if(manifest.first.list[i].path.EndsWith(".jar")||manifest.first.list[i].path.EndsWith(".sig")) {
			dest.AppendDir("bin");
			dest.SetFullName(manifest.first.list[i].path);
		} else {
			wxFileName webpath(manifest.first.list[i].path);
			wxArrayString dirs=webpath.GetDirs();
			for(size_t i=0;i<dirs.Count();++i) {
				dest.AppendDir(dirs[i]);
			}
			dest.SetFullName(webpath.GetFullName());
		}
		manifest.second.push_back(dest);
	}
	if(manifest.first.list.size()>0 && manifest.first.list.size() == manifest.second.size()) {
		MinecraftUpdater::location_info.manifestfull=true;
	}
}

void MinecraftFileList::CleanList() {
	for(size_t i=0;i<this->list.size();++i) {

		if(!MinecraftFileList::keepEntry(list[i])) {
			list.erase(list.begin()+i);
			--i;//now that there is one less, need to hit the same index again
		}
	}
}

bool MinecraftFileList::keepEntry(MinecraftFile& entry) {
	//drop directory names, will auto-create any necessary dirs
	//drop any file in a subdirectory that isn't resources
	std::wcout << wxT("Deciding whether to keep:") + entry.path << std::endl;
	if(entry.path.EndsWith(wxT("/")) || ((entry.path.Find(wxT("/")) != wxNOT_FOUND) && !entry.path.StartsWith(wxT("resources")) && !entry.path.IsSameAs(wxT("resources/")))){return false;}
	if(entry.path.EndsWith(wxT(".lzma"))){return false;}
	if(entry.path.IsSameAs(wxT("minecraft_classic_server.zip"))){return false;}
	//drop natives & extensions from different OS's
	if(entry.path.IsSameAs(wxT("AppleJavaExtensions.jar")) && this->OS!=ISMACOSX) {
		return false;
	}
	switch(this->OS){
	case MinecraftFileList::ISWINDOWS:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("windows_")) {
			return false;
		}
		break;
	case MinecraftFileList::ISMACOSX:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("macosx_")) {
			return false;
		}
		break;
	case MinecraftFileList::ISLINUX:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("linux_")) {
			return false;
		}
		break;
	case MinecraftFileList::ISSOLARIS:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("solaris_")) {
			return false;
		}
		break;
	case MinecraftFileList::UNSUPPORTED:
		return false;
	}
	//any file that makes it past the checks is ok
	return true;
}

MinecraftFileList::MinecraftFileList()/*: maxkeys(0),istruncated(false)*/ {
#if defined(__WINDOWS__)
	this->OS=MinecraftFileList::ISWINDOWS;
#elif defined(__APPLE__)
	this->OS=MinecraftFileList::ISMACOSX;
#elif defined(__LINUX__)
	this->OS=MinecraftFileList::ISLINUX;
#elif defined(__SOLARIS__)
	this->OS=MinecraftFileList::ISSOLARIS;
#else
	this->OS=MinecraftFileList::UNSUPPORTED;
	wxLogFatalError(wxT("YOUR OS IS NOT SUPPORTED BY MINECRAFT!!!!"));
#endif
}
