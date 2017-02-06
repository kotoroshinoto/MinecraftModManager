/*
 * ClientInstanceManager.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: mgooch
 */

#include "MinecraftSessionManager.h"

wxString MinecraftSessionManager::loginsite = "https://login.minecraft.net/";

MinecraftSessionManager::MinecraftSessionManager(wxString& user, wxString& password){
	this->session_info.user=user;
	this->session_info.password=password;
	this->EstablishSession();
}

wxString MinecraftSessionManager::LoginSession::version="13";

MinecraftSessionManager::LoginSession* MinecraftSessionManager::GetLoginSession() {
	return &(this->session_info);
}

bool MinecraftSessionManager::EstablishSession() {
	wxString pageinput;
	std::string page;
	wxString wxPage;
	std::vector<MCraftXmlContents> mc_content;
	pageinput = MinecraftSessionManager::loginsite;
	pageinput += wxT("?user=") + this->session_info.user + wxT("&password=") + this->session_info.password + wxT("&version=") + LoginSession::version;
	bool OK = MinecraftUtils::GetPageContent(pageinput, page);
	session_info.is_valid=false;
	if (!OK) {
		return false;
	}
	wxPage=page;
	if(wxPage.Contains(wxT(":"))){
		wxArrayString response_parts=wxSplit(wxPage,wxT(':'));
		this->session_info.version=response_parts[0];
		this->session_info.user = response_parts[2];
		this->session_info.sessionID = response_parts[3];
		this->session_info.UniqueID = response_parts[4];
		this->session_info.is_valid=true;
		wxLogMessage(wxT("version: ")+this->session_info.version);
		wxLogMessage(wxT("user: ")+this->session_info.user);
		wxLogMessage(wxT("sessionID: ")+this->session_info.sessionID);
		wxLogMessage(wxT("UniqueID: ")+this->session_info.UniqueID);
		return true;
	} else {
		session_info.ErrMsg=wxPage;
		return false;
	}
}

