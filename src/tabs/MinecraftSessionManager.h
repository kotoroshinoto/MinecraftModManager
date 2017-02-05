/*
 * ClientInstance.h
 *
 *  Created on: Aug 21, 2012
 *      Author: mgooch
 */

#ifndef CLIENTINSTANCE_H_
#define CLIENTINSTANCE_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
//#define CURL_STATICLIB
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <cstdio>
#include <vector>
#include <memory>
#include <utility>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/utils.h>
#include <wx/log.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <wx/wfstream.h>
#include "MinecraftUpdater.h"
#include "MinecraftUtils.h"



class MinecraftSessionManager {
public:
	struct LoginSession{
		unsigned long timestamp;
		wxString ErrMsg;
		wxString user;
		wxString sessionID;
		wxString UniqueID;
		wxString password;
		static wxString version;
		bool is_valid;
	};
	MinecraftSessionManager(wxString& user, wxString& password);
	LoginSession* GetLoginSession();
protected:
	bool EstablishSession();
	LoginSession session_info;
	static wxString loginsite;
};
#endif /* CLIENTINSTANCE_H_ */
