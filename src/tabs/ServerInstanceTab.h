/*
 * ServerInstanceTab.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef SERVERINSTANCETAB_H_
#define SERVERINSTANCETAB_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include "types.h"
#include "ParentApp.h"
#include "InstanceTab.h"
#include "Terminal.h"
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
struct ServerInstanceTab {
public:
	ServerInstanceTab(ParentApp* p);
	virtual ~ServerInstanceTab();
	InstanceTab* instance_tab;
	int LaunchServer();
	Terminal *terminal;
	long Launch();
	void Stop();
};

#endif /* SERVERINSTANCETAB_H_ */
