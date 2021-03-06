/*
 * ParentApp.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef PARENTAPP_H_
#define PARENTAPP_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include "types.h"
#include "../GUI/GUIFrame.h"
#include "ModTab.h"
#include "ClientInstanceTab.h"
#include "ServerInstanceTab.h"
#include "JarTab.h"
#include "SettingsTab.h"
#include "MinecraftUtils.h"
#include "Terminal.h"
#include <wx/log.h>
#include <wx/utils.h>
#include <wx/process.h>
struct ParentApp{
	ParentApp(GUIFrame* const app);
	virtual ~ParentApp();
	ModTab* client_mod_tab;
	ModTab* server_mod_tab;
	ClientInstanceTab* client_tab;
	ServerInstanceTab* server_tab;
	JarTab* jar_tab;
	SettingsTab* settings_tab;
	GUIFrame* gui;
	wxLogWindow* logwindow;
};


#endif /* PARENTAPP_H_ */
