/*
 * Shared_Utils.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef SHARED_UTILS_H_
#define SHARED_UTILS_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
//STL imports
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif

#include <vector>
#include <map>
//WX Widgets imports
#include <wx/listctrl.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/arrstr.h>
#include <wx/textfile.h>
#include <wx/wxprec.h>
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

//library imports
//#include <expat.h>
//#include <curl/curl.h>

struct MCraftXmlContents;
class MinecraftUtils;
//Project Imports
#include "MinecraftUpdater.h"
#include "types.h"

struct MCraftXmlContents{
	MCraftXmlContents(wxXmlNode * contentnode);
	wxString Key;
	wxString LastModified;
	wxString ETag;
	wxString Size;
	wxString StorageClass;
	wxString toString();
};

class MinecraftUtils{
public:
	static void UpdateList(wxListCtrl*,wxArrayString&);
	static void UpdateList(wxListCtrl*,std::vector<wxArrayString>&);
	static bool Read1ColFile(wxFileName& filename,wxArrayString& data);
	static bool ReadNColFile(wxFileName& filename,std::vector<wxArrayString>& data, size_t cols);
	static bool WriteNColFile(wxFileName& path, std::vector<wxArrayString>& data,size_t cols);
	static bool Write1ColFile(wxFileName& path, wxArrayString& data);
	static size_t get_string_from_curl(char *ptr, size_t size, size_t nmemb,void *userdata);
//	static bool ConfirmFile(wxString& parentpath,wxFileName& file,wxString& etag);
	static bool GetXMLPageContent(wxString& URL, std::vector<MCraftXmlContents> &page);
	static bool GetPageContent(wxString& URL, std::string &page);
	static bool GetFile(wxString& URL, wxFileName& dest);
};

#endif /* SHARED_UTILS_H_ */
