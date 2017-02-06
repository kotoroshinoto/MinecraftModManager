#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "wx/wxprec.h"
#include <wx/string.h>
#include <wx/url.h>
#include <wx/stream.h>
#include <wx/stdstream.h>
#include <wx/ffile.h>
#include <wx/wfstream.h>
#include <wx/app.h>
#include <wx/xml/xml.h>
#include <wx/sstream.h>

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

struct MCraftXmlContents{
	MCraftXmlContents(wxXmlNode * contentnode);
	wxString Key;
	wxString LastModified;
	wxString ETag;
	wxString Size;
	wxString StorageClass;
	wxString toString();
};
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

class TestConsole : public wxAppConsole {
public:
	bool OnInit();
	int OnRun();
	int OnExit();
private:
};
bool TestConsole::OnInit() {return true;}
int TestConsole::OnExit() {return 0;}
int TestConsole::OnRun() {
	wxFFileOutputStream wxffout(stdout);
	wxStdOutputStream wxout(wxffout);
	wxStringOutputStream ss;

	wxURL mcdl(wxT("http://s3.amazonaws.com/MinecraftDownload"));
	wxInputStream & mcdl_strm(*mcdl.GetInputStream());
	mcdl_strm.Read(ss);
//	wxout << ss.GetString() << std::endl;
	wxStringInputStream ssi(ss.GetString());
	wxXmlDocument mcxml(ssi);
	wxXmlNode * node = mcxml.GetRoot();
	wxout << node->GetType() << std::endl;
	wxout << node->GetName() << std::endl;
	wxXmlNode * childNode = node->GetChildren();
	wxXmlNode * contents_natives;
	wxXmlNode * contents_server_jar;
	wxXmlNode * contents_client_jar;
	while(childNode){
		{
			MCraftXmlContents mxc(childNode);
			wxout << mxc.toString() << std::endl;
		}
		childNode = childNode->GetNext();
	}

//	for(wxXmlNode * childNode = node->GetChildren(); childNode != NULL; childNode = childNode->GetNext()){
//		wxout << node->GetName() << std::endl;
//	}
	return 0;
}

IMPLEMENT_APP_CONSOLE(TestConsole)