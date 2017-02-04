/*
 * SettingsTab.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef SETTINGSTAB_H_
#define SETTINGSTAB_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include "types.h"
#include "ParentApp.h"
#include <wx/app.h>
#include <wx/tokenzr.h>
struct SettingsTab {
public:
	ParentApp* parent_app;
	SettingsTab(ParentApp*);
	virtual ~SettingsTab();
	wxFileName getJavaPath();
	wxFileName getFreshClientJarPath();
	wxFileName getFreshServerJarPath();
	wxFileName getInstancePath();
	wxFileName getClientInstancePath();
	wxFileName getServerInstancePath();
	wxFileName getModsPath();
	wxFileName getClientModsPath();
	wxFileName getServerModsPath();
	wxFileName getClientJarModsPath();
	wxFileName getServerJarModsPath();
	wxFileName getClientZipModsPath();
	wxFileName getServerZipModsPath();
	bool LoadSettings(bool loadtab=true);
	bool SaveSettings();
	void updateSettings();
};

#endif /* SETTINGSTAB_H_ */
