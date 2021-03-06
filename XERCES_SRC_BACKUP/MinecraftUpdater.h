/*
 * MinecraftUpdater.h
 *
 *  Created on: Aug 31, 2012
 *      Author: Michael
 */

#ifndef MINECRAFTUPDATER_H_
#define MINECRAFTUPDATER_H_
#define UNICODE
#define _UNICODE
//#define CURL_STATICLIB
#include <cstdio>
#include <vector>
#include <memory>
#include <utility>
#include <xercesc/util/Xerces_autoconf_config.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/sax/SAXException.hpp>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/utils.h>
#include <wx/log.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include "MinecraftUtils.h"

class MinecraftFile{
public:
	wxString path;
	wxString lastmodified;
	wxString etag;
	wxString storageclass;
	unsigned long size;
	void clear();
};

class MinecraftFileList{
private:
	enum WHICH_OS{
		UNSUPPORTED,
		ISWINDOWS,
		ISMACOSX,
		ISLINUX,
		ISSOLARIS
	};
public:
	void CleanList();
	MinecraftFileList();
	void clear();
	wxString name;
	unsigned long maxkeys;
	bool istruncated;
	std::vector<MinecraftFile> list;
private:
	bool keepEntry(MinecraftFile& entry);
	WHICH_OS OS;
};

struct MinecraftUpdateLocation{
	wxFileName path;
	std::pair<MinecraftFileList,std::vector<wxFileName> > manifest;
	bool manifestfull;
};

class MinecraftUpdater {
public:

	static void SetLocation(wxString& location);
	static void SetLocation(wxFileName& location);
	static bool Update(); //check for needs update, then update if it does, unless skipupdate is set true
	static bool NeedsUpdate();
	static std::pair<MinecraftFileList,std::vector<wxFileName> >& GetManifest();
	static MinecraftFileList& GetFileList();
protected:
	static bool ObtainFileList();
	static bool UnzipNatives(wxFileName& natives);
	static void FillManifest();
	static wxString updatesite;
	static wxString loginsite;
	static MinecraftUpdateLocation location_info;
private:
	MinecraftUpdater();
};

#endif /* MINECRAFTUPDATER_H_ */
