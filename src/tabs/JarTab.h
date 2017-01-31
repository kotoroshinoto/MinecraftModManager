/*
 * JarTab.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef JARTAB_H_
#define JARTAB_H_
#define UNICODE
#define _UNICODE
#include "types.h"
#include "ParentApp.h"
#include "MinecraftUtils.h"
struct JarTab {
public:
	JarTab(ParentApp*);
	virtual ~JarTab();
	wxRadioButton *client_radio,*server_radio;
	wxListCtrl *clientjarlist,*serverjarlist;
	wxTextCtrl *jar_version;
	wxArrayString serverjars,clientjars;
	wxFilePickerCtrl* picker;
	ParentApp* parent_app;
	bool Add();
	bool Replace();
	bool Remove();
	bool Save();
	bool SaveClientJars();
	bool SaveServerJars();
	bool Load();
	bool LoadClientJars();
	bool LoadServerJars();
	void Update();
	void UpdateServerJars();
	void UpdateClientJars();
};
#endif /* JARTAB_H_ */
