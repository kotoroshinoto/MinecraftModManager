/*
 * tabs.h
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#ifndef TABS_H_
#define TABS_H_
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <winsock2.h>
#include <windows.h>
#include "types.h"
struct InstanceTab;
#include "ParentApp.h"
#include "JarTab.h"
#include "SettingsTab.h"
#include "MinecraftUtils.h"
#include "../GUI/GUIFrame.h"
#include <wx/radiobut.h>
#include <wx/listctrl.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/log.h>
#include <wx/stream.h>
#include <memory>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <wx/textfile.h>
#include <wx/string.h>

struct InstanceTab{
	struct EditTab
	{
		wxFileName currentEditedInstance;
		EditTab(InstanceTab*);
		struct Sublist
		{
			Sublist(bool,EditTab*);
			bool arejarmods;
			EditTab *parent_edit_tab;
		    std::vector<wxArrayString> curr;
		    wxListCtrl *curr_list;
		    std::vector<wxArrayString> edit;
		    wxListCtrl *edit_list;
		    std::vector<wxArrayString> unused;
		    wxListCtrl *unused_list;
		    void Populate();
		    void Update();
		    void Add();
		    void Remove();
		    void Up();
		    void Down();
		    void ApplySave();
		};
		InstanceTab *parent_instance_tab;
	    wxChoice* jars;
	    EditTab::Sublist* jarmods;
	    EditTab::Sublist* zipmods;
	    void Populate();
	    void Update();
	    void ApplyZipMods();
	    void RebuildJar();
	    wxString GetSelectedVersion();
	};
	struct InstanceButtonSection{
		InstanceButtonSection(InstanceTab*);
		wxTextCtrl* instanceName;
		wxTextCtrl* minRAM, *maxRAM;
		wxCheckBox* check_minRAM, *check_maxRAM;
		wxChoice *min_memunit,*max_memunit;
	};
	InstanceTab(bool,ParentApp*);
	bool isClient;
	ParentApp* parent_app;
	virtual ~InstanceTab();
	InstanceButtonSection *buttonsection;
	wxListCtrl *instancelist;
	EditTab *edit_tab;
	wxArrayString instances;
	wxString GetSelectedInstanceName();
	bool CreateInstance();
	bool RenameInstance();
	bool DeleteInstance();
	bool SaveInstances();
	bool LoadInstances();
	void UpdateInstances();
};

#endif /* TABS_H_ */
