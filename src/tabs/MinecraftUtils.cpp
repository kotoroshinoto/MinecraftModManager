/*
 * Shared_Utils.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */
#include "MinecraftUtils.h"

//TODO change this so that it uses wxXmlDocument class instead

void MinecraftUtils::UpdateList(wxListCtrl* list,wxArrayString& data)
{
	list->DeleteAllItems();
	for(size_t i=0; i<data.Count(); ++i)
	{
		list->InsertItem(i,data[i]);
		//wxLogMessage(data[i]);
	}
}
void MinecraftUtils::UpdateList(wxListCtrl* list,std::vector<wxArrayString>& data)
{
	list->DeleteAllItems();
	for(size_t i=0; i<data.size(); ++i)
	{
		list->InsertItem(i,data[i][0]);
		list->SetItem(i,1,data[i][1]);
		//wxLogMessage(data[i][0]+wxT("\t")+data[i][1]);
	}
}

bool MinecraftUtils::Read1ColFile(wxFileName& filename,wxArrayString& data)
{

	wxString line,tmp;
	data.Clear();
	if(filename.FileExists())
	{
		wxTextFile file(filename.GetFullPath());
		if(file.Open())
		{
			for(size_t i=0; i < file.GetLineCount(); ++i)
			{
				if(!file[i].IsEmpty())
				{
					data.Add(file[i]);
				}
			}
			file.Close();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

bool MinecraftUtils::ReadNColFile(wxFileName& filename,std::vector<wxArrayString>& data, size_t cols)
{
	wxString line;
	data.clear();
	if(filename.FileExists())
	{
		wxTextFile file(filename.GetFullPath());
		if(file.Open())
		{
			for(size_t i=0; i < file.GetLineCount(); ++i)
			{
				wxArrayString arr=wxSplit(file[i],'\t');
				if(arr.Count()==cols)//require # ofcols
				{
					if(!arr[0].IsEmpty())
					{
						data.push_back(arr);    //first entry can't be empty
					}
				}
			}
			file.Close();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

bool MinecraftUtils::Write1ColFile(wxFileName& path, wxArrayString& data)
{
	wxTextFile file(path.GetFullPath());
	if(file.Exists())
	{
		file.Open();
		file.Clear();
	}
	else
	{
		file.Create();
		file.Open();
		file.Clear();
	}
	if(file.IsOpened())
	{
		for(size_t i=0; i<data.Count(); ++i)
		{
			file.AddLine(data[i]);
		}
		if(!file.Write())
		{
			return false;
		}
		file.Close();
		return true;
	}
	else
	{
		return false;
	}
}

bool MinecraftUtils::WriteNColFile(wxFileName& path, std::vector<wxArrayString>& data,size_t cols)
{
	wxTextFile file(path.GetFullPath());
	if(file.Exists())
	{
		file.Open();
		file.Clear();
	}
	else
	{
		file.Create();
		file.Open();
		file.Clear();
	}
	if(file.IsOpened())
	{
		for(size_t i=0; i<data.size(); ++i)
		{
			wxString line;
			for(size_t j=0; j<cols; ++j)
			{
				line+=data[i][j];
				if(j+1 != cols)
				{
					line+=wxT("\t");
				}
			}
			file.AddLine(line);
		}
		if(!file.Write())
		{
			return false;
		}
		file.Close();
		return true;
	}
	else
	{
		return false;
	}
}
bool MinecraftUtils::GetFile(wxString& URL, wxFileName& dest)
{
	if(!dest.DirExists() && !dest.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL)){return false;}//TODO error message why it failed. dir doesn exist && couldnt be created
	wxString fname=dest.GetFullPath();
	wxFFileOutputStream wxffout(stdout);
	wxStdOutputStream wxout(wxffout);
	wxURL mcdl(URL);
	if(mcdl.GetError() != wxURL_NOERR){
		wxout << "wxURL error: " << mcdl.GetError()<<std::endl;
		return false;
	}
	wxInputStream *mcdl_strm =mcdl.GetInputStream();
	if(!mcdl_strm || !mcdl_strm->IsOk()){return false;}

	wxFileOutputStream fos(fname);
	if(!fos.IsOk()){return false;}//TODO error message for file could not be created/opened

	try {
		mcdl_strm->Read(fos);
	} catch(...){
		wxout << "an exception occurred"<< std::endl;
		return false;
	}
	return true;
}
bool MinecraftUtils::GetPageContent(wxString& URL, std::string &page){
	//TODO implement something for this
	page = "";
	return false;
}

bool MinecraftUtils::GetXMLPageContent(wxString& URL, std::vector<MCraftXmlContents> &page){
	page.clear();
	wxFFileOutputStream wxffout(stdout);
	wxStdOutputStream wxout(wxffout);
	wxStringOutputStream ss;

	wxURL mcdl(wxT("http://s3.amazonaws.com/MinecraftDownload"));
	if(mcdl.GetError() != wxURL_NOERR){return false;}
	wxInputStream & mcdl_strm(*mcdl.GetInputStream());
	if(!mcdl_strm.IsOk()){return false;}
	try{mcdl_strm.Read(ss);}catch(...){return false;}
//	wxout << ss.GetString() << std::endl;
	wxStringInputStream ssi(ss.GetString());
	wxXmlDocument mcxml(ssi);
	wxXmlNode * node = mcxml.GetRoot();
	if(node == NULL){return false;}
//	wxout << node->GetType() << std::endl;
//	wxout << node->GetName() << std::endl;
	wxXmlNode * childNode = node->GetChildren();
	if(childNode == NULL) {return false;}
	while(childNode){
		try {
			MCraftXmlContents mxc(childNode);
			page.push_back(mxc);
		} catch(std::runtime_error &e){
			wxout<<e.what()<<std::endl;
			return false;
		}
		childNode = childNode->GetNext();
	}
	return true;
}

size_t MinecraftUtils::get_string_from_curl(char *ptr, size_t size,
		size_t nmemb, void *userdata) {
	std::stringstream& ss = (*((std::stringstream*) userdata));
	for (size_t i = 0; i < size * nmemb; ++i) {
		ss<< *ptr;
		ptr++;
	}
	return size * nmemb;
}

bool ConfirmFile(wxString& parentpath,wxFileName& file,wxString& etag)
{
	return true;
}

MCraftXmlContents::MCraftXmlContents(wxXmlNode * contentnode){
	if(contentnode == NULL){return;}
	if(contentnode->GetName() != "Contents"){return;}
	wxXmlNode * child = contentnode->GetChildren();
	while(child){
		wxString name = child->GetName();
//		std::cout << child->GetNodeContent() << std::endl;
		if (name == "Key") {
			if(this->Key.length() != 0){throw new std::runtime_error("duplicate xml value: Key");}
			this->Key=child->GetNodeContent();
		} else if (name == "LastModified") {
			if(this->LastModified.length() != 0){throw new std::runtime_error("duplicate xml value: LastModified");}
			this->LastModified=child->GetNodeContent();
		} else if (name == "ETag") {
			if(this->ETag.length() != 0){throw new std::runtime_error("duplicate xml value: ETag");}
			this->ETag=child->GetNodeContent();
		} else if (name == "Size") {
			if(this->Size.length() != 0){throw new std::runtime_error("duplicate xml value: Size");}
			this->Size=child->GetNodeContent();
		} else if (name == "StorageClass") {
			if(this->StorageClass.length() != 0){throw new std::runtime_error("duplicate xml value: StorageClass");}
			this->StorageClass=child->GetNodeContent();
		} else {
			throw new std::runtime_error("unexpected xml value");
		}

		child = child->GetNext();
	}
}
wxString MCraftXmlContents::toString(){
	wxStringOutputStream sos;
	wxStdOutputStream ss(sos);
	ss << "<Contents>"<<std::endl;
	ss << "\t<Key>"<<this->Key<<"</Key>"<<std::endl;
	ss << "\t<LastModified>"<<this->LastModified<<"</LastModified>"<<std::endl;
	ss << "\t<ETag>"<<this->ETag<<"</ETag>"<<std::endl;
	ss << "\t<Size>"<<this->Size<<"</Size>"<<std::endl;
	ss << "\t<StorageClass>"<<this->StorageClass<<"</StorageClass>"<<std::endl;
	ss << "</Contents>"<<std::endl;
	return sos.GetString();
}
