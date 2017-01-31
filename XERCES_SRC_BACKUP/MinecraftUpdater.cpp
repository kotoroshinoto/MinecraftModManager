/*
 * MinecraftUpdater.cpp
 *
 *  Created on: Aug 31, 2012
 *      Author: Michael
 */

#include "MinecraftUpdater.h"

wxString MinecraftUpdater::updatesite =
		"http://s3.amazonaws.com/MinecraftDownload/";
wxString MinecraftUpdater::loginsite = "https://login.minecraft.net/";
MinecraftUpdateLocation MinecraftUpdater::location_info;

void MinecraftFileList::clear(){
	this->istruncated=false;
	this->list.clear();
	this->maxkeys=0;
	this->name.Clear();
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
	if(!MinecraftUpdater::location_info.manifestfull){return false;}
	return true;//TODO IMPLEMENT VERSION CHECK
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
	for(size_t i=0;OK && i<MinecraftUpdater::location_info.manifest.second.size();++i)
	{
		url=MinecraftUpdater::updatesite;
		url+=MinecraftUpdater::location_info.manifest.first.list[i].path;
		wxString message;
		//std::wcout<<"Ensuring directory location exists for:"<<manifest.second[i].GetFullPath()<<std::endl;
		message+=wxT("Downloading ")+url+wxT(" to ")+MinecraftUpdater::location_info.manifest.second[i].GetFullPath();
		std::wcout<<message<<std::endl;
		//TODO turn this back on when fixed
		OK=MinecraftUtils::GetFile(url,MinecraftUpdater::location_info.manifest.second[i]);
		if(OK){
			std::wcout<<wxT("Download Complete!")<<std::endl;
		} else {
			std::wcout<<wxT("Download Failed!")<<std::endl;
			return false;
		}
	}
	//unzip natives jar
	wxFileName nativepath=MinecraftUpdater::location_info.path;
	nativepath.AppendDir(wxT(".minecraft"));
	nativepath.AppendDir(wxT("bin"));
	nativepath.SetFullName(natives);
	std::wcout<<wxT("Unzipping the natives archive!")<<std::endl;
	if(UnzipNatives(nativepath))
	{
		std::wcout<<wxT("Unzip Complete!")<<std::endl;
	} else{
		std::wcout<<wxT("Unzip Failed!")<<std::endl;
		return false;
	}
	return OK;
}

bool MinecraftUpdater::UnzipNatives(wxFileName& natives)
{
	wxFileName sourcejar=natives,destpath,destfile;
	destpath=sourcejar;
	destpath.AppendDir(wxT("natives"));
	destpath.SetFullName(wxT(""));
	if(!destpath.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL)){
		std::wcout<<"could not create natives directory"<<std::endl;
		return false;
	}
	bool ret = true;
	bool somethingdone=false;
	//wxFileSystem fs;
	std::auto_ptr<wxZipEntry> entry(new wxZipEntry());
	std::wcout<<"attempting to extract \n"<< natives.GetFullPath() << "\n as a zip file to location: \n"<< destpath.GetFullPath() <<std::endl;
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
			std::wcout<<wxT("Examining Entry: ")<<entry->GetName()<<std::endl;
			if(! entry->GetName().StartsWith(wxT("META-INF")) ){
				std::wcout<<wxT("Entry is NOT part of META-INF, EXTRACTING IT")<<std::endl;
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
				std::wcout<<wxT("Entry is part of META-INF, IGNORING IT")<<std::endl;
			}
		}

	} while(false);
	if(!somethingdone){
		std::wcout<<"No files were extracted, first entry must have been null!"<<std::endl;
	}
	return ret;
}

std::pair<MinecraftFileList,std::vector<wxFileName> >& MinecraftUpdater::GetManifest(){
	return MinecraftUpdater::location_info.manifest;
}

MinecraftFileList& MinecraftUpdater::GetFileList(){
	return MinecraftUpdater::location_info.manifest.first;
}

bool MinecraftUpdater::ObtainFileList() {
	std::string page;
	bool bFailed=false;
	bool OK;
	OK = MinecraftUtils::GetPageContent(MinecraftUpdater::updatesite, page);
	if (!OK) {
		std::wcerr<<"Could not get page content!"<<std::endl;
		return false;
	}
	XERCES_CPP_NAMESPACE_QUALIFIER XMLPlatformUtils::Initialize();
	// create new parser instance.
	XERCES_CPP_NAMESPACE_QUALIFIER XercesDOMParser *parser = new XERCES_CPP_NAMESPACE_QUALIFIER XercesDOMParser;
	if (!parser)
	{
		//report error and die
		std::wcerr<<"Could not create XML parser"<<std::endl;
		XERCES_CPP_NAMESPACE_QUALIFIER XMLPlatformUtils::Terminate();
		return false;
	}
	parser->setValidationScheme(XERCES_CPP_NAMESPACE_QUALIFIER XercesDOMParser::Val_Auto);
	parser->setDoNamespaces(false);
	parser->setDoSchema(false);

	parser->setCreateEntityReferenceNodes(false);
	//parser->setToCreateXMLDeclTypeNode(true);
	try
	{
		XMLByte buffer[page.length()+1];
		XMLByte * buffptr;
		const char * pageptr;
		memcpy(buffer,page.c_str(),page.length()+1);

		XERCES_CPP_NAMESPACE_QUALIFIER MemBufInputSource source(buffer,((XMLSize_t) (page.length()+1)),"Minecraft Download Page XML");
		parser->parse(source);
		bFailed = parser->getErrorCount() != 0;
		if (bFailed)
		{
			wxString error;
			error << wxT("Parsing XML Document: ") << wxT(" error count: ") << parser->getErrorCount();
			std::wcerr<<error.ToStdWstring()<<std::endl;
		}
	}
	catch (const XERCES_CPP_NAMESPACE_QUALIFIER DOMException& e)
	{
		wxString error;
		error<< "DOM Exception parsing ";
		error << " reports: ";
		// was message provided?
		if (e.msg)
		{
			// yes: display it as ascii.
			char *strMsg = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(e.msg);
			error << strMsg;
			XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&strMsg);
		}
		else {// no: just display the error code.
			error << e.code;
		}
		std::wcerr<<error.ToStdWstring()<<std::endl;
		bFailed = true;
	}
	catch (const XERCES_CPP_NAMESPACE_QUALIFIER XMLException& e)
	{
		wxString error;
		error << "XML Exception parsing ";
		error << " reports: ";
		error << ((wchar_t *)(e.getMessage()));
		std::wcerr<<error.ToStdWstring()<<std::endl;
		bFailed = true;
	}
	catch (const XERCES_CPP_NAMESPACE_QUALIFIER SAXException& e)
	{
		wxString error;
		error << "SAX Exception parsing ";
		error << " reports: ";
		error << ((wchar_t *)(e.getMessage()));
		std::wcerr<<error.ToStdWstring()<<std::endl;
		bFailed = true;
	}
	catch (...)
	{
		wxString error;
		error << "An exception parsing ";
		std::wcerr<<error.ToStdWstring()<<std::endl;
		bFailed = true;
	}
	// did the input document parse okay?
	if (bFailed)
	{
		XERCES_CPP_NAMESPACE_QUALIFIER XMLPlatformUtils::Terminate();
		std::wcerr<<wxT("Failed Parsing XML Document!")<<std::endl;
		return false;
		//report error and die
	}
	XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *pDoc = parser->getDocument();
	XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *pNode;
	XERCES_CPP_NAMESPACE_QUALIFIER DOMNodeList *pNodeList;
	XMLCh *xmlstr;
	char * cstr;
	//Name
	xmlstr= XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode("Name");
	pNodeList=pDoc->getElementsByTagName(xmlstr);
	if(pNodeList->getLength() != 1)
	{
		//chop your face off with a cheese grater
		std::wcerr<<wxT("ERROR READING XML!!")<<std::endl;
	} else {
		cstr = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(pNodeList->item(0)->getFirstChild()->getTextContent());
		MinecraftUpdater::location_info.manifest.first.name=wxString::FromUTF8(cstr);
		std::wcout<<wxT("DocName:")+MinecraftUpdater::location_info.manifest.first.name<<std::endl;
		XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&cstr);
	}
	XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&xmlstr);
	//MaxKeys
	xmlstr= XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode("MaxKeys");
	pNodeList=pDoc->getElementsByTagName(xmlstr);
	if(pNodeList->getLength() != 1)
	{
		//chop your face off with a cheese grater
		std::wcerr<<wxT("ERROR READING XML!!")<<std::endl;
	} else {
		cstr = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(pNodeList->item(0)->getFirstChild()->getTextContent());
		wxString tmp=wxString::FromUTF8(cstr);
		XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&cstr);
		if(tmp.ToULong(&MinecraftUpdater::location_info.manifest.first.maxkeys))
		{
			//TODO error
		}
		std::wcout<<wxT("DocName:")+tmp<<std::endl;
	}
	XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&xmlstr);
	//IsTruncated
	xmlstr= XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode("IsTruncated");
	pNodeList=pDoc->getElementsByTagName(xmlstr);
	if(pNodeList->getLength() != 1)
	{
		//chop your face off with a cheese grater
		std::wcerr<<wxT("ERROR READING XML!!")<<std::endl;
	} else {
		cstr = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(pNodeList->item(0)->getFirstChild()->getTextContent());
		wxString tmp=wxString::FromUTF8(cstr);
		XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&cstr);
		MinecraftUpdater::location_info.manifest.first.istruncated=tmp.IsSameAs(wxT("true"));
		std::wcout<<wxT("DocName:")+tmp<<std::endl;
	}
	XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&xmlstr);
	//Contents
	xmlstr= XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode("Contents");
	pNodeList=pDoc->getElementsByTagName(xmlstr);
	XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&xmlstr);
	size_t selector;
	MinecraftFile f;
	wxString tmp;
	for(size_t i=0;i<pNodeList->getLength();++i){
		XERCES_CPP_NAMESPACE_QUALIFIER DOMNodeList *members=pNodeList->item(i)->getChildNodes();
		f.clear();
		selector=0;
		for(size_t j=0;j<members->getLength();++j)
		{
			cstr = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(members->item(j)->getNodeName());
			tmp=wxString::FromUTF8(cstr);
			XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&cstr);
			std::cout<<"\tNODE NAME: "<<tmp.ToStdString()<<std::endl;
			if(tmp.IsSameAs(wxT("Key"))){selector=1;}
			else if(tmp.IsSameAs(wxT("LastModified"))){selector=2;}
			else if(tmp.IsSameAs(wxT("ETag"))){selector=3;}
			else if(tmp.IsSameAs(wxT("Size"))){selector=4;}
			else if(tmp.IsSameAs(wxT("StorageClass"))){selector=5;}
			else{selector=0;}
			XERCES_CPP_NAMESPACE_QUALIFIER DOMNodeList *values=members->item(j)->getChildNodes();
			for(size_t k =0;k<values->getLength();++k)
			{
				cstr = XERCES_CPP_NAMESPACE_QUALIFIER XMLString::transcode(values->item(k)->getTextContent());
				tmp=wxString::FromUTF8(cstr);
				XERCES_CPP_NAMESPACE_QUALIFIER XMLString::release(&cstr);
				std::cout<<"\t\tNODE Content: "<<tmp.ToStdString()<<std::endl;
				switch(selector){
				case 0:
				default:
					//TODO indicate error
					break;
				case 1:
					f.path=tmp;
					break;
				case 2:
					f.lastmodified=tmp;
					break;
				case 3:
					f.etag=tmp;
					break;
				case 4:
					tmp.ToULong(&f.size);
					break;
				case 5:
					f.storageclass=tmp;
					break;
				}
			}
		}
		MinecraftUpdater::location_info.manifest.first.list.push_back(f);
	}
	// insert code to do something with the DOM document here.
	XERCES_CPP_NAMESPACE_QUALIFIER XMLPlatformUtils::Terminate();
	MinecraftUpdater::location_info.manifest.first.CleanList();
	return true;
}

void MinecraftUpdater::FillManifest()
{
	wxFileName path=MinecraftUpdater::location_info.path;
	wxFileName dest;
	path.AppendDir(".minecraft");
	std::pair<MinecraftFileList,std::vector<wxFileName> >& manifest=MinecraftUpdater::location_info.manifest;
	for(size_t i=0;i<manifest.first.list.size();++i)
	{
		dest=path;
		if(manifest.first.list[i].path.EndsWith(".jar")||manifest.first.list[i].path.EndsWith(".sig")){
			dest.AppendDir("bin");
			dest.SetFullName(manifest.first.list[i].path);
		} else {
			wxFileName webpath(manifest.first.list[i].path);
			wxArrayString dirs=webpath.GetDirs();
			for(size_t i=0;i<dirs.Count();++i)
			{
				dest.AppendDir(dirs[i]);
			}
			dest.SetFullName(webpath.GetFullName());
		}
		manifest.second.push_back(dest);
	}
	if(manifest.first.list.size()>0 && manifest.first.list.size() == manifest.second.size())
	{
		MinecraftUpdater::location_info.manifestfull=true;
	}
}


void MinecraftFileList::CleanList()
{
	for(size_t i=0;i<this->list.size();++i)
	{

		if(!MinecraftFileList::keepEntry(list[i]))
		{
			list.erase(list.begin()+i);
			--i;//now that there is one less, need to hit the same index again
		}
	}
}
bool MinecraftFileList::keepEntry(MinecraftFile& entry)
{
	//drop directory names, will auto-create any necessary dirs
	//drop any file in a subdirectory that isn't resources
	std::wcout<<wxT("Deciding whether to keep:") + entry.path<<std::endl;
	if(entry.path.EndsWith(wxT("/")) || ((entry.path.Find(wxT("/")) != wxNOT_FOUND) && !entry.path.StartsWith(wxT("resources")) && !entry.path.IsSameAs(wxT("resources/")))){return false;}
	if(entry.path.EndsWith(wxT(".lzma"))){return false;}
	if(entry.path.IsSameAs(wxT("minecraft_classic_server.zip"))){return false;}
	//drop natives & extensions from different OS's
	if(entry.path.IsSameAs(wxT("AppleJavaExtensions.jar")) && this->OS!=ISMACOSX)
	{
		return false;
	}
	switch(this->OS){
	case MinecraftFileList::ISWINDOWS:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("windows_"))
		{
			return false;
		}
		break;
	case MinecraftFileList::ISMACOSX:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("macosx_"))
		{
			return false;
		}
		break;
	case MinecraftFileList::ISLINUX:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("linux_"))
		{
			return false;
		}
		break;
	case MinecraftFileList::ISSOLARIS:
		if(entry.path.Find(wxT("_natives")) != wxNOT_FOUND  && !entry.path.StartsWith("solaris_"))
		{
			return false;
		}
		break;
	case MinecraftFileList::UNSUPPORTED:
		return false;
	}
	//any file that makes it past the checks is ok
	return true;
}
MinecraftFileList::MinecraftFileList(): maxkeys(0),istruncated(false)
{
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
