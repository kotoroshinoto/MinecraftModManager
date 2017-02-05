/*
 * ClientInstanceTab.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef CLIENTINSTANCETAB_H_
#define CLIENTINSTANCETAB_H_
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
#include "ParentApp.h"
#include "InstanceTab.h"
#include "MinecraftUtils.h"
#include "MinecraftSessionManager.h"
#include "Terminal.h"
struct ClientInstanceTab{
	struct ClientInstanceButtonSection{
		ClientInstanceButtonSection(ParentApp* p);
			//also has window size, full/max screen, user/pass purge/forceupdate
			wxCheckBox *check_window_size;
			wxTextCtrl *window_width,*window_height;
			wxCheckBox *check_fullscreen,*check_maximize;
			wxTextCtrl *username,*password;
			wxCheckBox *check_purgefiles,*check_forceupdate;
		};
	ClientInstanceTab(ParentApp* p);
	virtual ~ClientInstanceTab();
	MinecraftSessionManager* client_instance_handler;
	InstanceTab* instance_tab;
	Terminal *terminal;
	ClientInstanceButtonSection *clientbuttonsection;
	void Stop();
	long Launch();
};

#endif /* CLIENTINSTANCETAB_H_ */
