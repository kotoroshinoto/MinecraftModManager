/*
 * JarTab.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#include "JarTab.h"

JarTab::JarTab(ParentApp* p){
	// TODO Auto-generated constructor stub
	this->parent_app=p;

	this->jar_version=p->gui->jars_version_number;
	this->picker=p->gui->jars_jar_filepicker;

	this->client_radio=p->gui->jars_client_radio;
	this->clientjarlist=p->gui->jars_client_list;

	this->server_radio=p->gui->jars_server_radio;
	this->serverjarlist=p->gui->jars_server_list;

	wxListItem clientjarcol;
	clientjarcol.SetId(0);
	clientjarcol.SetText(wxT("Client Jar Version"));
	clientjarcol.SetWidth(200);
	wxListItem serverjarcol;
	serverjarcol.SetId(0);
	serverjarcol.SetText(wxT("Server Jar Version"));
	serverjarcol.SetWidth(200);
	this->clientjarlist->InsertColumn(0,clientjarcol);
	this->serverjarlist->InsertColumn(0,serverjarcol);
}

JarTab::~JarTab() {
	// TODO Auto-generated destructor stub
}
bool JarTab::Load()
{
    bool client=this->LoadClientJars();
    bool server=this->LoadServerJars();
    if(!client)
    {
        wxLogWarning(wxT("Encountered a problem loading the client jars!"));
    }
    if(!server)
    {
        wxLogWarning(wxT("Encountered a problem loading the server jars!"));
    }
    return client && server;
}

bool JarTab::Save()
{
    bool server=this->SaveServerJars();
    bool client=this->SaveClientJars();
    if(!server)
    {
        wxLogWarning(wxT("Encountered a problem saving the server jars list!"));
    }
    if(!client)
    {
        wxLogWarning(wxT("Encountered a problem saving the client jars list!"));
    }
    return server && client;
}

bool JarTab::LoadClientJars()
{
	bool retval=true;
	wxFileName path=this->parent_app->settings_tab->getFreshClientJarPath();
	path.SetFullName(wxT("clientjars.conf"));
	wxLogMessage(wxT("trying to load: ")+path.GetFullPath());
	if(path.FileExists())
	{
		if(! MinecraftUtils::Read1ColFile(path,clientjars))
		{
			wxLogMessage(wxT("client jar list could not be read, will create a new one!"));
			retval=false;
		}
	}
	else
	{
		wxLogMessage(wxT("client jar list not found, had to create a new one!"));
		retval=false;
	}
	return retval;
}
bool JarTab::LoadServerJars()
{
	bool retval=true;
	wxFileName path=this->parent_app->settings_tab->getFreshServerJarPath();
	path.SetFullName(wxT("serverjars.conf"));
	wxLogMessage(wxT("trying to load: ")+path.GetFullPath());
	if(path.FileExists())
	{
		if(! MinecraftUtils::Read1ColFile(path,serverjars))
		{
			wxLogMessage(wxT("server jar list could not be read, will create a new one!"));
			retval=false;
		}
	}
	else
	{
		wxLogMessage(wxT("server jar list not found, have to create a new one!"));
		retval=false;
	}
	return retval;
}

bool JarTab::SaveClientJars()
{
	wxFileName path=this->parent_app->settings_tab->getFreshClientJarPath();
	path.SetFullName(wxT("clientjars.conf"));
	wxLogMessage(wxT("trying to save: ")+path.GetFullPath());
	return MinecraftUtils::Write1ColFile(path,clientjars);
}
bool JarTab::SaveServerJars()
{

	wxFileName path=this->parent_app->settings_tab->getFreshServerJarPath();
	path.SetFullName(wxT("serverjars.conf"));
	wxLogMessage(wxT("trying to save: ")+path.GetFullPath());
	return MinecraftUtils::Write1ColFile(path,serverjars);
}



bool JarTab::Add()
{
	bool server_selected=this->server_radio->GetValue();
	bool client_selected=this->client_radio->GetValue();
	wxFileName jarpath=wxFileName::FileName(this->picker->GetPath());
	wxString version=this->jar_version->GetLineText(0);
	wxFileName dest;
	if(!jarpath.FileExists())
	{
		return false;
	}
	if(server_selected)
	{
		dest=this->parent_app->settings_tab->getFreshServerJarPath();
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft_server.jar"));
		wxLogMessage(wxT("attempting to add server jar:")+jarpath.GetFullPath()+wxT(" as ")+dest.GetFullPath() + wxT(" version: ")+version);
	}
	if(client_selected)
	{
		dest=this->parent_app->settings_tab->getFreshClientJarPath();
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft.jar"));
		wxLogMessage(wxT("attempting to add client jar:")+jarpath.GetFullPath()+wxT(" as ")+dest.GetFullPath() + wxT(" version: ")+version);
	}

	if(client_selected || server_selected){
		if(!dest.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL ))
		{
			return false;
		}
		if(!wxCopyFile(jarpath.GetFullPath(),dest.GetFullPath()))
		{
			return false;
		}
	}
	if(client_selected)
	{
		this->clientjars.Add(version);
		return true;
	}
	if(server_selected)
	{
		this->serverjars.Add(version);
		return true;
	}
	return false;
}

bool JarTab::Replace()
{
	bool server_selected=this->server_radio->GetValue();
	bool client_selected=this->client_radio->GetValue();
	wxFileName jarpath=wxFileName::FileName(this->picker->GetPath());
	wxString version;//=this->jar_compat_choice->GetString(this->jar_compat_choice->GetSelection());;
	wxFileName dest;
	long selected;
	wxListItem row_info;
	row_info.m_col=0;
	row_info.m_mask= wxLIST_MASK_TEXT;
	if(server_selected)
	{
		dest=this->parent_app->settings_tab->getFreshServerJarPath();
		selected=this->serverjarlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		row_info.m_itemId=selected;
		this->serverjarlist->GetItem(row_info);
		version=row_info.m_text;
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft_server.jar"));
		wxLogMessage(wxT("attempting to replace server jar:")+dest.GetFullPath()+wxT(" with ")+jarpath.GetFullPath() + wxT(" version: ")+version);
	}
	if(client_selected)
	{
		dest=this->parent_app->settings_tab->getFreshClientJarPath();
		selected=this->clientjarlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		row_info.m_itemId=selected;
		this->clientjarlist->GetItem(row_info);
		version=row_info.m_text;
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft.jar"));
		wxLogMessage(wxT("attempting to replace client jar:")+dest.GetFullPath()+wxT(" with ")+jarpath.GetFullPath() + wxT(" version: ")+version);
	}
	if(server_selected || client_selected)
	{
		if(!jarpath.FileExists())
		{
			return false;
		}
		if(!wxCopyFile(jarpath.GetFullPath(),dest.GetFullPath()))
		{
			return false;
		}
		return true;
	}
	return false;
}

bool JarTab::Remove()
{
	bool server_selected=this->server_radio->GetValue();
	bool client_selected=this->client_radio->GetValue();
	long selected;
	wxFileName dest;
	wxString version;
	wxListItem row_info;
	row_info.m_col=0;
	row_info.m_mask= wxLIST_MASK_TEXT;
	if(server_selected)
	{
		dest=this->parent_app->settings_tab->getFreshServerJarPath();
		selected=this->serverjarlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		row_info.m_itemId=selected;
		this->serverjarlist->GetItem(row_info);
		version=row_info.m_text;
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft_server.jar"));
		if(!dest.FileExists()) //already gone
		{
			wxLogWarning(wxT("Target server jar file doesnt exist"));
			dest.Rmdir(wxPATH_RMDIR_RECURSIVE);
			this->serverjars.Remove(version);
			return true;
		}
		wxLogMessage(wxT("attempting to remove server jar:")+dest.GetFullPath() + wxT(" version: ")+version);
	}
	if(client_selected)
	{
		dest=this->parent_app->settings_tab->getFreshClientJarPath();
		selected=this->clientjarlist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		row_info.m_itemId=selected;
		this->clientjarlist->GetItem(row_info);
		version=row_info.m_text;
		dest.AppendDir(version);
		dest.SetFullName(wxT("minecraft.jar"));
		if(!dest.FileExists()) //already gone
		{
			wxLogWarning(wxT("Target client jar file doesnt exist"));
			dest.Rmdir(wxPATH_RMDIR_RECURSIVE);
			this->clientjars.Remove(version);
			return true;
		}
		wxLogMessage(wxT("attempting to remove client jar:")+dest.GetFullPath() + wxT(" version: ")+version);
	}
	if(server_selected || client_selected)
	{
		if(!dest.Rmdir(wxPATH_RMDIR_RECURSIVE))
		{
			return false;
		}
	}
	if(server_selected)
	{
		this->serverjars.Remove(version);
		return true;
	}
	if(client_selected)
	{
		this->clientjars.Remove(version);
		return true;
	}
	return false;
}

void JarTab::Update()
{
    UpdateClientJars();
    UpdateServerJars();
}
void JarTab::UpdateClientJars()
{
    MinecraftUtils::UpdateList(this->clientjarlist,this->clientjars);
}

void JarTab::UpdateServerJars()
{
	MinecraftUtils::UpdateList(this->serverjarlist,this->serverjars);
}
