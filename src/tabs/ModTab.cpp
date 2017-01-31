/*
 * ModTab.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#include "ModTab.h"

ModTab::ModTab(bool client,ParentApp* p) {
	this->isclient=client;
	this->parent_app=p;
	if(this->isclient){
		this->jar_compat_choice=p->gui->client_mod_compatible_jar_version_choice;
		this->jarmod_radio=p->gui->clientmod_jarmod_radio;
		this->jarmodlist=p->gui->clientmod_jarmod_list;
		this->modname=p->gui->client_mod_name_textctrl;
		this->zipmod_radio=p->gui->clientmod_zipmod_radio;
		this->zipmodlist=p->gui->clientmod_zipmod_list;
		this->picker=p->gui->clientmod_filepicker;
	} else {
		this->jar_compat_choice=p->gui->server_mod_compatible_jar_version_choice;
		this->jarmod_radio=p->gui->servermod_jarmod_radio;
		this->jarmodlist=p->gui->servermod_jarmod_list;
		this->modname=p->gui->server_mod_name_textctrl;
		this->zipmod_radio=p->gui->servermod_zipmod_radio;
		this->zipmodlist=p->gui->servermod_zipmod_list;
		this->picker=p->gui->servermod_filepicker;
	}

	wxListItem name_list_item;
	name_list_item.SetId(0);
	name_list_item.SetText(wxT("Name"));
	name_list_item.SetWidth(130);

	wxListItem version_list_item;
	version_list_item.SetId(1);
	version_list_item.SetText(wxT("Version"));
	version_list_item.SetWidth(70);
	this->jarmodlist->InsertColumn(0, name_list_item);
	this->jarmodlist->InsertColumn(1, version_list_item);
	this->zipmodlist->InsertColumn(0, name_list_item);
	this->zipmodlist->InsertColumn(1, version_list_item);
}

ModTab::~ModTab() {}


bool ModTab::Load(){
	bool jarmods=this->LoadJarMods();
	bool zipmods=this->LoadZipMods();
	if(this->isclient){
		if(!jarmods)
		{
			wxLogWarning(wxT("Encountered a problem loading the client jar mods!"));
		}
		if(!zipmods)
		{
			wxLogWarning(wxT("Encountered a problem loading the client directory mods!"));
		}
	} else {
		if(!jarmods)
		{
			wxLogWarning(wxT("Encountered a problem loading the server jar mods!"));
		}
		if(!zipmods)
		{
			wxLogWarning(wxT("Encountered a problem loading the server directory mods!"));
		}

	}
	return jarmods && zipmods;
}

bool ModTab::LoadJarMods(){
	wxFileName path;
	if(this->isclient){
		path=this->parent_app->settings_tab->getClientJarModsPath();
		path.SetFullName(wxT("clientjarmods.conf"));
	} else {
		path=this->parent_app->settings_tab->getServerJarModsPath();
		path.SetFullName(wxT("serverjarmods.conf"));
	}
	if(path.FileExists())
	{
		if(! MinecraftUtils::ReadNColFile(path,this->jarmods,3))
		{
			wxLogMessage(path.GetFullPath() + wxT(" could not be read, will create a new one!"));
			return false;
		}
		return true;
	}
	else
	{
		wxLogMessage(path.GetFullPath() + wxT(" not found, have to create a new one!"));
		return false;
	}
}
bool ModTab::LoadZipMods(){
	wxFileName path;
	if(this->isclient){
		path=this->parent_app->settings_tab->getClientZipModsPath();
		path.SetFullName(wxT("clientzipmods.conf"));
	} else {
		path=this->parent_app->settings_tab->getServerZipModsPath();
		path.SetFullName(wxT("serverzipmods.conf"));
	}
	if(path.FileExists())
	{
		if(! MinecraftUtils::ReadNColFile(path,this->zipmods,3))
		{
			wxLogMessage(path.GetFullPath() + wxT(" could not be read, will create a new one!"));
			return false;
		}
		return true;
	}
	else
	{
		wxLogMessage(path.GetFullPath() + wxT(" not found, have to create a new one!"));
		return false;
	}
}

bool ModTab::Save()
{
	bool jar=this->SaveJarMods(),zip=this->SaveZipMods();
	return  jar && zip ;
}

bool ModTab::SaveJarMods()
{
	wxFileName path;

	if(this->isclient){
		path=this->parent_app->settings_tab->getClientJarModsPath();
		path.SetFullName(wxT("clientjarmods.conf"));
	} else {
		path=this->parent_app->settings_tab->getServerJarModsPath();
		path.SetFullName(wxT("serverjarmods.conf"));
	}

	return MinecraftUtils::WriteNColFile(path,this->jarmods,3);

}
bool ModTab::SaveZipMods()
{
	wxFileName path;
	if(this->isclient){
		path=this->parent_app->settings_tab->getClientZipModsPath();
		path.SetFullName(wxT("clientzipmods.conf"));
	} else {
		path=this->parent_app->settings_tab->getServerZipModsPath();
		path.SetFullName(wxT("serverzipmods.conf"));
	}
	return MinecraftUtils::WriteNColFile(path,this->zipmods,3);
}

bool ModTab::Add()
{
	wxFileName modpath;
	bool jarsel=this->jarmod_radio->GetValue(),zipsel=this->zipmod_radio->GetValue();
	wxString name=this->modname->GetLineText(0);
	wxString version=this->jar_compat_choice->GetString(this->jar_compat_choice->GetSelection());
	wxArrayString entry;
	wxFileName path,zippath;
	name=name.Trim();
	version=version.Trim();
	zippath=wxFileName::FileName(this->picker->GetPath());
	std::vector<wxArrayString>* mods;
	wxListCtrl* modlist;
	if(!zippath.FileExists())
	{
		return false;
	}
	if(name.IsEmpty())
	{
		return false;    //no name specified or one with identical name is already in list
	}
	if(jarsel)
	{
		modlist=this->jarmodlist;
		mods=&(this->jarmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientJarModsPath();

		} else {
			modpath=this->parent_app->settings_tab->getServerJarModsPath();
		}
	}
	if(zipsel)
	{
		modlist=this->zipmodlist;
		mods=&(this->zipmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientZipModsPath();
		} else
		{
			modpath=this->parent_app->settings_tab->getServerZipModsPath();
		}
	}
	if(jarsel || zipsel)
	{
		for(size_t i=0; i<(*mods).size(); ++i)
		{
			if((*mods)[i][0]==name&&(*mods)[i][1]==version)
			{
				return false;
			}
		}
		path=modpath;
		path.SetFullName(name+wxT("_")+version+wxT(".")+zippath.GetExt());
		wxLogMessage(wxT("Attempting to store mod:")+zippath.GetFullPath() + wxT(" as ")+path.GetFullPath());
		if(!wxCopyFile(zippath.GetFullPath(),path.GetFullPath()))
		{
			return false;
		}
		entry.Add(name);
		entry.Add(version);
		entry.Add(zippath.GetExt());
	}
	if(jarsel)
	{
		this->jarmods.push_back(entry);
		return true;
	}
	if(zipsel)
	{
		this->zipmods.push_back(entry);
		return true;
	}
	return false;
}
bool ModTab::Replace()
{
	wxFileName modpath;
	bool jarsel=this->jarmod_radio->GetValue(),zipsel=this->zipmod_radio->GetValue();
	wxString name=this->modname->GetLineText(0);
	wxString version=this->jar_compat_choice->GetString(this->jar_compat_choice->GetSelection());
	wxArrayString entry;
	wxFileName path,zippath;
	name=name.Trim();
	version=version.Trim();
	zippath=wxFileName::FileName(this->picker->GetPath());
	long selected;
	wxListItem row_info;
	std::vector<wxArrayString>* mods;
	wxListCtrl* modlist;
	if(!zippath.FileExists())
	{
		return false;
	}
	if(name.IsEmpty())
	{
		return false;    //no name specified
	}
	path=modpath;
	if(jarsel)
	{
		modlist=this->jarmodlist;
		mods=&(this->jarmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientJarModsPath();

		} else {
			modpath=this->parent_app->settings_tab->getServerJarModsPath();
		}
	}
	if(zipsel)
	{
		modlist=this->zipmodlist;
		mods=&(this->zipmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientZipModsPath();
		} else
		{
			modpath=this->parent_app->settings_tab->getServerZipModsPath();
		}
	}
	if(jarsel || zipsel)
	{
		selected=modlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		if(selected==-1)
		{
			return false;
		}
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		modlist->GetItem(row_info);
		name=row_info.m_text;

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		modlist->GetItem(row_info);
		version=row_info.m_text;
		for(size_t i=0; i<mods->size(); ++i)
		{
			if((*mods)[i][0]==name && (*mods)[i][1]==version)
			{
				path.SetFullName(name+wxT("_")+version+wxT(".")+zippath.GetExt());
				if(!wxCopyFile(zippath.GetFullPath(),path.GetFullPath()))
				{
					return false;
				}
				(*mods)[i][2]=zippath.GetExt();
				return true;
			}
		}//shouldn't be able to get here, info was grabbed from list
	}
	return false;
}
bool ModTab::Remove()
{
	wxFileName modpath;
	bool jarsel=this->jarmod_radio->GetValue(),zipsel=this->zipmod_radio->GetValue();
	wxString name;
	wxString version;
	long selected;
	wxFileName path;
	path=modpath;
	wxListItem row_info;
	std::vector<wxArrayString>* mods;
	wxListCtrl* modlist;
	if(jarsel){
		modlist=this->jarmodlist;
		mods=&(this->jarmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientJarModsPath();

		} else {
			modpath=this->parent_app->settings_tab->getServerJarModsPath();
		}
	}
	if(zipsel){
		modlist=this->zipmodlist;
		mods=&(this->zipmods);
		if(this->isclient)
		{
			modpath=this->parent_app->settings_tab->getClientZipModsPath();
		} else
		{
			modpath=this->parent_app->settings_tab->getServerZipModsPath();
		}
	}
	if(jarsel || zipsel)
	{
		selected=modlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		if(selected==-1)
		{
			return false;
		}
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		modlist->GetItem(row_info);
		name=row_info.m_text;

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		modlist->GetItem(row_info);
		version=row_info.m_text;
		for(size_t i=0; i<(*mods).size(); ++i)
		{
			if((*mods)[i][0]==name && (*mods)[i][1]==version)
			{
				path.SetFullName(name+wxT("_")+version+wxT(".")+(*mods)[i][2]);
				if(!path.FileExists())
				{
					(*mods).erase((*mods).begin()+i);
					return true;
				}
				if(!wxRemoveFile(path.GetFullPath()))
				{
					return false;
				}
				(*mods).erase((*mods).begin()+i);
				return true;
			}
		}
	}
	return false;
}

void ModTab::Update()
{
	UpdateJarMods();
	UpdateZipMods();
}
void ModTab::UpdateJarMods()
{
	MinecraftUtils::UpdateList(this->jarmodlist,this->jarmods);
}
void ModTab::UpdateZipMods()
{
	MinecraftUtils::UpdateList(this->zipmodlist,this->zipmods);
}
