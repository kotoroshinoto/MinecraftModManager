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
#include <wx/protocol/http.h>

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

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

	wxURL mcdl(wxT("http://s3.amazonaws.com/Minecraft.Download/versions/1.11.2/minecraft_server.1.11.2.jar"));
	if(mcdl.GetError() != wxURL_NOERR){
		wxout << "wxURL error: " << mcdl.GetError()<<std::endl;
		return 1;
	}
	wxInputStream *mcdl_strm =mcdl.GetInputStream();
	if(!mcdl_strm || !mcdl_strm->IsOk()){return 2;}

	wxFileOutputStream fos("minecraft_server.1.11.2.jar");
	try {
		mcdl_strm->Read(fos);
	} catch(...){
		wxout << "an exception occurred"<< std::endl;
	}
	return 0;
}

IMPLEMENT_APP_CONSOLE(TestConsole)