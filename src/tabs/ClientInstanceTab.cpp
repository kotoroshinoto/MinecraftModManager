/*
 * ClientInstanceTab.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#include "ClientInstanceTab.h"

ClientInstanceTab::ClientInstanceTab(ParentApp* p){
	this->instance_tab=new InstanceTab(true,p);
	this->terminal=new Terminal(p,1);
	this->clientbuttonsection=new ClientInstanceButtonSection(p);
	this->client_instance_handler=NULL;
}
ClientInstanceTab::~ClientInstanceTab()
{
	delete instance_tab;
	delete terminal;
	delete clientbuttonsection;
	if(this->client_instance_handler){delete this->client_instance_handler;}
}

ClientInstanceTab::ClientInstanceButtonSection::ClientInstanceButtonSection(ParentApp* p)
{
	this->check_forceupdate=p->gui->check_force_update;
	this->check_fullscreen=p->gui->client_check_fullscreen;
	this->check_maximize=p->gui->client_check_maximize;
	this->check_purgefiles=p->gui->purge_instance_contents;
	this->check_window_size=p->gui->client_check_window_size;
	this->password=p->gui->password_text;
	this->username=p->gui->username_text;
	this->window_height=p->gui->client_window_height;
	this->window_width=p->gui->client_window_width;
}

long ClientInstanceTab::Launch()
{
	//*
	wxString jpath=this->instance_tab->parent_app->settings_tab->getJavaPath().GetFullPath();
    wxString command=jpath;
    wxFileName jarpath=this->instance_tab->parent_app->settings_tab->getClientInstancePath();
    wxFileName launcherpath=wxFileName::FileName(wxT("../multimc_new_launcher.jar"));
    wxString instname;
    wxString minecraftpath;
    long selected=this->instance_tab->instancelist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);

    if(this->terminal->runningID)
    {
        wxMessageBox(wxT("A client instance is already running!"));
        return 0;
    }
    if(selected == -1)
    {
        wxMessageBox(wxT("You must select an instance before attempting to launch!"));
        return 0;
    }
    wxListItem row_info;
    row_info.m_itemId=selected;
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->instance_tab->instancelist->GetItem(row_info);
    instname=row_info.m_text;
    jarpath.AppendDir(instname);
    minecraftpath=jarpath.GetFullPath();
    jarpath.AppendDir(wxT(".minecraft"));
    //C:\Program Files\Java\jre6\bin\java.exe
    //-Xmx4096m -Xms2048m
    //-cp "C:\Users\Michael\Desktop" MultiMCLauncher
    //"C:\Users\Michael\Desktop\instances\TerraFirma\.minecraft"
    // "kotoroshinoto" 9204230471799094963
    wxString username,password;
    username=this->clientbuttonsection->username->GetLineText(0);
    password=this->clientbuttonsection->password->GetLineText(0);
    this->client_instance_handler=new MinecraftSessionManager(username,password);

    MinecraftSessionManager::LoginSession* sessionID=this->client_instance_handler->GetLoginSession();
    MinecraftUpdater::SetLocation(minecraftpath);
    if(this->instance_tab->buttonsection->check_maxRAM->GetValue() && !this->instance_tab->buttonsection->maxRAM->GetLineText(0).IsEmpty())
        {
            command+=wxT(" -Xmx")+this->instance_tab->buttonsection->maxRAM->GetLineText(0)+(this->instance_tab->buttonsection->max_memunit->GetString(this->instance_tab->buttonsection->max_memunit->GetSelection())[0]);
        }
        if(this->instance_tab->buttonsection->check_minRAM->GetValue() && !this->instance_tab->buttonsection->minRAM->GetLineText(0).IsEmpty())
        {
            command+=wxT(" -Xms")+this->instance_tab->buttonsection->minRAM->GetLineText(0)+(this->instance_tab->buttonsection->min_memunit->GetString(this->instance_tab->buttonsection->min_memunit->GetSelection())[0]);
        }


    	wxString exepath;
    	wxStandardPaths& stdpaths=wxStandardPaths::Get();
    	exepath=stdpaths.GetExecutablePath();
    	wxFileName launchjarpath=wxFileName::FileName(exepath);
    	launchjarpath.SetFullName(wxT("MultiMC_Launcher.jar"));

        command += wxT(" -jar ") +  launchjarpath.GetFullPath()+ wxT(" ");
        command +=jarpath.GetFullPath();

    //TODO handle purge
    if(this->clientbuttonsection->check_forceupdate->GetValue()){
    	wxLogMessage(wxT("Forcing Update!"));
    	if(MinecraftUpdater::Update())
    	{
    		wxLogMessage(wxT("Update Success!"));
    	} else {
    		wxLogMessage(wxT("Update Failure!"));
    	}
    } else {
    	wxLogMessage(wxT("Skipping Update!"));
    }
    if(sessionID->sessionID.IsEmpty())
    {
        wxMessageBox(wxT("Could Not Obtain SessionID!"));
        wxLogError(sessionID->ErrMsg);
        return 0;
    }
    command+=wxT(" \"")+username+wxT("\" ");
    command+=(sessionID->sessionID);
    command+=" \"Minecraft Instance: "+this->instance_tab->GetSelectedInstanceName()+ wxT("\"");

    this->terminal->terminal->AppendText(wxT(">")+command+wxT("\n"));
    wxLogMessage(wxT("Running command:")+ command);
    this->terminal->runningID=wxExecute(command,wxEXEC_ASYNC,this->terminal->running);
    wxString num;
    num<<(this->terminal->runningID);
    wxLogMessage(wxT("Process ID: ") + num );
    if(this->terminal->runningID != 0)
    {
    	this->terminal->timer->Start(100,wxTIMER_CONTINUOUS);
    	wxLogMessage(wxT("Timer Started!"));
    }
    return this->terminal->runningID;
    //*/
}

void ClientInstanceTab::Stop()
{
	//TODO check for any remaining output
	wxLogMessage(wxT("Client process stopped or died"));
	this->terminal->runningID =0;
	wxLogMessage(wxT("Running ID set to zero"));
	this->terminal->timer->Stop();
	wxLogMessage(wxT("Timer Stopped!"));
	delete this->client_instance_handler;
	this->client_instance_handler=NULL;
	wxLogMessage(wxT("Session Handler Deleted!"));
}
