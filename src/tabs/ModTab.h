/*
 * ModTab.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef MODTAB_H_
#define MODTAB_H_
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
#include <vector>
struct ModTab {
	ModTab(bool,ParentApp*);
	virtual ~ModTab();
	bool isclient;
	ParentApp* parent_app;
	wxRadioButton *jarmod_radio,*zipmod_radio;
	wxListCtrl *jarmodlist,*zipmodlist;
	wxTextCtrl *modname;
	wxChoice* jar_compat_choice;
	wxFilePickerCtrl* picker;
	std::vector<wxArrayString> jarmods,zipmods;
	bool Add();
	bool Replace();
	bool Remove();
	bool Save();
	bool SaveJarMods();
	bool SaveZipMods();
	bool Load();
	bool LoadJarMods();
	bool LoadZipMods();
	void Update();
	void UpdateJarMods();
	void UpdateZipMods();
};
#endif /* MODTAB_H_ */
