/*
 * ServerInstanceTab.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#include "ServerInstanceTab.h"

ServerInstanceTab::ServerInstanceTab(ParentApp* p) {
	this->instance_tab=new InstanceTab(false,p);
	this->terminal=new Terminal(p,0);
}

ServerInstanceTab::~ServerInstanceTab() {
	delete instance_tab;
	delete terminal;
}

long ServerInstanceTab::Launch()
{
    wxString command=this->instance_tab->parent_app->settings_tab->getJavaPath().GetFullPath();
    wxFileName jarpath=this->instance_tab->parent_app->settings_tab->getServerInstancePath();
    wxString instname;
    wxExecuteEnv env;
    long selected =this->instance_tab->instancelist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    if(this->terminal->runningID)
    {
        wxMessageBox(wxT("A server instance is already running!"));
        return this->terminal->runningID;
    }
    if(selected == -1)
    {
        wxMessageBox(wxT("You must select an instance before attempting to launch!"));
        return this->terminal->runningID;
    }
    wxListItem row_info;
    row_info.m_itemId=selected;
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->instance_tab->instancelist->GetItem(row_info);
    instname=row_info.m_text;
    jarpath.AppendDir(instname);
    env.cwd=jarpath.GetFullPath();
    jarpath.SetFullName(wxT("minecraft_server.jar"));

    if(this->instance_tab->buttonsection->check_maxRAM->GetValue() && !this->instance_tab->buttonsection->maxRAM->GetLineText(0).IsEmpty())
    {
        command+=wxT(" -Xmx")+this->instance_tab->buttonsection->maxRAM->GetLineText(0)+(this->instance_tab->buttonsection->max_memunit->GetString(this->instance_tab->buttonsection->max_memunit->GetSelection())[0]);
    }
    if(this->instance_tab->buttonsection->check_minRAM->GetValue() && !this->instance_tab->buttonsection->minRAM->GetLineText(0).IsEmpty())
    {
        command+=wxT(" -Xms")+this->instance_tab->buttonsection->minRAM->GetLineText(0)+(this->instance_tab->buttonsection->min_memunit->GetString(this->instance_tab->buttonsection->min_memunit->GetSelection())[0]);
    }
    command += wxT(" -jar ")+jarpath.GetFullPath()+wxT(" nogui");
    wxLogMessage(wxT("Running command:")+ command);
    this->terminal->runningID=wxExecute(command,wxEXEC_ASYNC,this->terminal->running,&env);
    wxString num;
    num<<(this->terminal->runningID);
    wxLogMessage(wxT("Process ID: ") + num );
    if(this->terminal->runningID != 0)
    {
        this->terminal->timer->Start(100,wxTIMER_CONTINUOUS);
        wxLogMessage(wxT("Timer Started!"));
    }
    return this->terminal->runningID;
}
void ServerInstanceTab::Stop()
{
	//TODO check for any remaining output
	wxLogMessage(wxT("Server process stopped or died"));
	this->terminal->runningID =0;
	wxLogMessage(wxT("Running ID set to zero"));
	this->terminal->timer->Stop();
	wxLogMessage(wxT("Timer Stopped!"));
}
