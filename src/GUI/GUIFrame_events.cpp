#include <GUIFrame.h>
void GUIFrame::purge_files_checked(wxCommandEvent&){
	if(this->parent_app->client_tab->clientbuttonsection->check_purgefiles->IsChecked())
	{
		this->parent_app->client_tab->clientbuttonsection->check_forceupdate->SetValue(true);
	}
}

void GUIFrame::force_update_checked(wxCommandEvent&){
	if(! this->parent_app->client_tab->clientbuttonsection->check_forceupdate->IsChecked())
	{
		this->parent_app->client_tab->clientbuttonsection->check_purgefiles->SetValue(false);
	}
}

void GUIFrame::client_instance_selected(wxListEvent&){
	wxListCtrl* list=this->parent_app->client_tab->instance_tab->instancelist;
	wxTextCtrl* text=this->parent_app->client_tab->instance_tab->buttonsection->instanceName;
	long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
	text->Clear();
	text->AppendText(list->GetItemText(selected));
}

void GUIFrame::client_jarmod_selected(wxListEvent&){
	if(this->parent_app->client_mod_tab->jarmod_radio->GetValue()){
		wxListItem row_info;
		wxListCtrl* list=this->parent_app->client_mod_tab->jarmodlist;
		wxTextCtrl* text=this->parent_app->client_mod_tab->modname;
		wxChoice* choice=this->parent_app->client_mod_tab->jar_compat_choice;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		text->AppendText(row_info.m_text);

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		int i;
		i=choice->FindString(row_info.m_text,true);
		if(i!=wxNOT_FOUND){choice->SetSelection(i);}
	}
}

void GUIFrame::client_zipmod_selected(wxListEvent&){
	if(this->parent_app->client_mod_tab->zipmod_radio->GetValue()){
		wxListItem row_info;
		wxListCtrl* list=this->parent_app->client_mod_tab->zipmodlist;
		wxTextCtrl* text=this->parent_app->client_mod_tab->modname;
		wxChoice* choice=this->parent_app->client_mod_tab->jar_compat_choice;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		text->AppendText(row_info.m_text);

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		int i;
		i=choice->FindString(row_info.m_text,true);
		if(i!=wxNOT_FOUND){choice->SetSelection(i);}
	}
}


void GUIFrame::server_jarmod_selected(wxListEvent&){
	if(this->parent_app->server_mod_tab->jarmod_radio->GetValue()){
		wxListItem row_info;
		wxListCtrl* list=this->parent_app->server_mod_tab->jarmodlist;
		wxTextCtrl* text=this->parent_app->server_mod_tab->modname;
		wxChoice* choice=this->parent_app->server_mod_tab->jar_compat_choice;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		text->AppendText(row_info.m_text);

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		int i;
		i=choice->FindString(row_info.m_text,true);
		if(i!=wxNOT_FOUND){choice->SetSelection(i);}
	}
}

void GUIFrame::server_zipmod_selected(wxListEvent&){
	if(this->parent_app->server_mod_tab->zipmod_radio->GetValue()){
		wxListItem row_info;
		wxListCtrl* list=this->parent_app->server_mod_tab->zipmodlist;
		wxTextCtrl* text=this->parent_app->server_mod_tab->modname;
		wxChoice* choice=this->parent_app->server_mod_tab->jar_compat_choice;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		row_info.m_itemId=selected;
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		text->AppendText(row_info.m_text);

		row_info.m_itemId=selected;
		row_info.m_col=1;
		row_info.m_mask= wxLIST_MASK_TEXT;
		list->GetItem(row_info);
		int i;
		i=choice->FindString(row_info.m_text,true);
		if(i!=wxNOT_FOUND){choice->SetSelection(i);}
	}
}

void GUIFrame::server_instance_selected(wxListEvent&){
	wxListCtrl* list=this->parent_app->server_tab->instance_tab->instancelist;
	wxTextCtrl* text=this->parent_app->server_tab->instance_tab->buttonsection->instanceName;
	long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
	text->Clear();
	text->AppendText(list->GetItemText(selected));
}

void GUIFrame::client_edit_jar_version_selected(wxCommandEvent&){
	if(this->parent_app->jar_tab->client_radio->GetValue()){
		wxListCtrl* list=this->parent_app->jar_tab->clientjarlist;
		wxTextCtrl* text=this->parent_app->jar_tab->jar_version;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		text->AppendText(list->GetItemText(selected));
	}
}

void GUIFrame::server_edit_jar_version_selected(wxCommandEvent&){
	if(this->parent_app->jar_tab->server_radio->GetValue()){
		wxListCtrl* list=this->parent_app->jar_tab->serverjarlist;
		wxTextCtrl* text=this->parent_app->jar_tab->jar_version;
		long selected=list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		text->Clear();
		text->AppendText(list->GetItemText(selected));
	}
}

void GUIFrame::server_modfile_selected(wxFileDirPickerEvent& event)
{
	wxFilePickerCtrl* file=this->parent_app->server_mod_tab->picker;
	wxTextCtrl* text=this->parent_app->server_mod_tab->modname;
	text->Clear();
	text->AppendText(file->GetFileName().GetName());
}
void GUIFrame::client_modfile_selected(wxFileDirPickerEvent& event)
{
	wxFilePickerCtrl* file=this->parent_app->client_mod_tab->picker;
	wxTextCtrl* text=this->parent_app->client_mod_tab->modname;
	text->Clear();
	text->AppendText(file->GetFileName().GetName());
}

//tab switching events
void GUIFrame::tab_changing( wxNotebookEvent& event ){
	switch(event.GetOldSelection())
	{
	case 0://client instance tab
		//make sure the sub tab is set to the instance-select tab
		this->client_notebook->SetSelection(0);
		this->parent_app->client_tab->instance_tab->SaveInstances();
		break;
	case 1:
		this->parent_app->client_mod_tab->Save();
		break;
	case 3:
		this->parent_app->server_mod_tab->Save();
		break;
	case 2://server instance tab
		//make sure the sub tab is set to the instance-select tab
		this->server_notebook->SetSelection(0);
		this->parent_app->server_tab->instance_tab->SaveInstances();
		break;
	case 4:
		this->parent_app->jar_tab->Save();
		break;
	case 5:
		this->parent_app->settings_tab->LoadSettings(false);//override settings that weren't applied
		break;

	default://do nothing
		break;
	}
	switch(event.GetSelection()){
	case 0:
		this->parent_app->client_tab->instance_tab->LoadInstances();
		this->parent_app->client_tab->instance_tab->UpdateInstances();
	break;
	case 2:
		this->parent_app->server_tab->instance_tab->LoadInstances();
		this->parent_app->server_tab->instance_tab->UpdateInstances();
	break;

	case 1:
		this->parent_app->client_mod_tab->Load();
		this->parent_app->client_mod_tab->Update();
		break;
	case 3:
		this->parent_app->server_mod_tab->Load();
		this->parent_app->server_mod_tab->Update();
		break;
	case 4:
		this->parent_app->jar_tab->Load();
		this->parent_app->jar_tab->Update();
		break;
	default:
		break;
	}
}

//client events
void GUIFrame::client_launch_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->Launch();
}
void GUIFrame::client_create_new_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_tab->instance_tab->CreateInstance())
	{
		this->parent_app->client_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::client_delete_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_tab->instance_tab->DeleteInstance())
	{
		this->parent_app->client_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::client_rename_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_tab->instance_tab->DeleteInstance())
	{
		this->parent_app->client_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::clientmod_add_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_mod_tab->Add())
	{
		this->parent_app->client_mod_tab->Update();
	}
}
void GUIFrame::clientmod_replace_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_mod_tab->Replace())
	{
		this->parent_app->client_mod_tab->Update();
	}
}
void GUIFrame::clientmod_remove_clicked( wxCommandEvent& event )
{
	if(this->parent_app->client_mod_tab->Remove())
	{
		this->parent_app->client_mod_tab->Update();
	}
}

//client instance edit related
void GUIFrame::client_page_changing( wxNotebookEvent& event )
{
	if(event.GetSelection() == 1 && event.GetOldSelection() != event.GetSelection())
	{
		wxFileName path=this->parent_app->settings_tab->getClientInstancePath();
		wxListItem row_info;
		row_info.m_itemId=this->client_instance_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		if(row_info.m_itemId == -1)
		{
			wxMessageBox(wxT("You must select an instance before switching to the edit tab!"));
			this->client_notebook->SetSelection(0);
			return;
		}
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		this->client_instance_list->GetItem(row_info);
		path.AppendDir(row_info.m_text);
		this->parent_app->client_tab->instance_tab->edit_tab->currentEditedInstance=path;
		this->parent_app->client_tab->instance_tab->edit_tab->Populate();
		this->parent_app->client_tab->instance_tab->edit_tab->Update();
	}
}
void GUIFrame::client_jarmod_add_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->jarmods->Add();
}
void GUIFrame::client_jarmod_up_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->jarmods->Up();
}
void GUIFrame::client_jarmod_down_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->jarmods->Down();
}
void GUIFrame::client_jarmod_remove_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->jarmods->Remove();
}
void GUIFrame::client_buildjar_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->RebuildJar();
}
void GUIFrame::client_zipmod_add_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->zipmods->Add();
}
void GUIFrame::client_zipmod_remove_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->zipmods->Remove();
}
void GUIFrame::client_zipmod_apply_clicked( wxCommandEvent& event )
{
	this->parent_app->client_tab->instance_tab->edit_tab->ApplyZipMods();
}

//server events
void GUIFrame::server_launch_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->Launch();
}
void GUIFrame::server_create_new_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_tab->instance_tab->CreateInstance())
	{
		this->parent_app->server_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::server_delete_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_tab->instance_tab->DeleteInstance())
	{
		this->parent_app->server_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::server_rename_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_tab->instance_tab->DeleteInstance())
	{
		this->parent_app->server_tab->instance_tab->UpdateInstances();
	}
}
void GUIFrame::servermod_add_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_mod_tab->Add())
	{
		this->parent_app->server_mod_tab->Update();
	}
}
void GUIFrame::servermod_replace_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_mod_tab->Replace())
	{
		this->parent_app->server_mod_tab->Update();
	}
}
void GUIFrame::servermod_remove_clicked( wxCommandEvent& event )
{
	if(this->parent_app->server_mod_tab->Remove())
	{
		this->parent_app->server_mod_tab->Update();
	}
}


//server instance edit related
void GUIFrame::server_page_changing( wxNotebookEvent& event )
{
	if(event.GetSelection() == 1 && event.GetOldSelection() != event.GetSelection())
	{
		wxFileName path=this->parent_app->settings_tab->getServerInstancePath();
		wxListItem row_info;
		row_info.m_itemId=this->server_instance_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		if(row_info.m_itemId == -1)
		{
			wxMessageBox(wxT("You must select an instance before switching to the edit tab!"));
			this->server_notebook->SetSelection(0);
			return;
		}
		row_info.m_col=0;
		row_info.m_mask= wxLIST_MASK_TEXT;
		this->server_instance_list->GetItem(row_info);
		path.AppendDir(row_info.m_text);
		this->parent_app->server_tab->instance_tab->edit_tab->currentEditedInstance=path;
		this->parent_app->server_tab->instance_tab->edit_tab->Populate();
		this->parent_app->server_tab->instance_tab->edit_tab->Update();
	}
}
void GUIFrame::server_jarmod_add_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->jarmods->Add();
}
void GUIFrame::server_jarmod_up_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->jarmods->Up();
}
void GUIFrame::server_jarmod_down_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->jarmods->Down();
}
void GUIFrame::server_jarmod_remove_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->jarmods->Remove();
}
void GUIFrame::server_buildjar_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->RebuildJar();
}
void GUIFrame::server_zipmod_add_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->zipmods->Add();
}
void GUIFrame::server_zipmod_remove_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->zipmods->Remove();
}
void GUIFrame::server_zipmod_apply_clicked( wxCommandEvent& event )
{
	this->parent_app->server_tab->instance_tab->edit_tab->ApplyZipMods();
}

//jar events
void GUIFrame::jars_add_clicked( wxCommandEvent& event )
{
	if(this->parent_app->jar_tab->Add())
	{
		this->parent_app->jar_tab->Update();
	}
}
void GUIFrame::jars_replace_clicked( wxCommandEvent& event )
{
	if(this->parent_app->jar_tab->Replace())
	{
		this->parent_app->jar_tab->Update();
	}
}
void GUIFrame::jars_remove_clicked( wxCommandEvent& event )
{
	if(this->parent_app->jar_tab->Remove())
	{
		this->parent_app->jar_tab->Update();
	}
}

void GUIFrame::Apply_Settings( wxCommandEvent& event )
{
	this->parent_app->settings_tab->SaveSettings();
	this->parent_app->settings_tab->LoadSettings();
}

void GUIFrame::server_terminal_enter_press(wxCommandEvent& event)
{
	this->parent_app->server_tab->terminal->DataEntered();
}
void GUIFrame::client_terminal_enter_press(wxCommandEvent& event)
{
	this->parent_app->client_tab->terminal->DataEntered();
}

void GUIFrame::process_end(wxProcessEvent& event)
{
	int pid= event.GetPid();
	int exitcode=event.GetPid();
	if(this->parent_app->server_tab->terminal->runningID  == pid)
	{
		this->parent_app->server_tab->Stop();
	}
	if(this->parent_app->client_tab->terminal->runningID == pid)
	{
		this->parent_app->client_tab->Stop();
	}
}

void GUIFrame::timer_interval(wxTimerEvent& event)
{
	switch(event.GetTimer().GetId())
	{
	case 0:
		//check if server is still running
		//check if server has any output
		this->parent_app->server_tab->terminal->UpdateTerminal();
		break;
	case 1:
		//check if client is still running
		//check if client has any output
		this->parent_app->client_tab->terminal->UpdateTerminal();
		break;
	default:
		break;
	}
}
