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
#include "types.h"
#include <curl/curl.h>
#include <vector>
#include <wx/listctrl.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/arrstr.h>
#include <wx/textfile.h>
#include "MinecraftUpdater.h"
#include <map>
#include <expat.h>
struct XMLEntity{
	XMLEntity(XMLEntity* parent);
	~XMLEntity();
	bool istag;
	wxString text;//if ISTAG==true text is tag name; otherwise is text content
	std::vector<XMLEntity*> children;
	XMLEntity* parent;
	std::map<wxString,wxString> attrs;
	wxString GetContainedXMLText();
};

class XML_Handler{
public:
	XMLEntity* ParsePage(wxString& URL);
	XML_Handler();
	~XML_Handler();
private:
	long eventcnt;
	long depth;
	XMLEntity* currentpage;
	XMLEntity* ptr;
	static void start_hndl(void *userdata,const XML_Char * s, const XML_Char **attr);
	static void end_hndl(void *userdata, const XML_Char  *s);
	static void char_hndl(void *userdata, const XML_Char  *txt, int txtlen);
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
	static bool ConfirmFile(wxString& parentpath,wxFileName& file,wxString& etag);
	static bool GetPageContent(wxString& URL, std::string& page);
	static bool GetFile(wxString& URL, wxFileName& dest);
};

#endif /* SHARED_UTILS_H_ */
