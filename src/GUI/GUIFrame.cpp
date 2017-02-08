///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////
#include <winsock2.h>
#include <windows.h>
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* frame_boxsizer;
	frame_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	frame_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	client_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* client_tab_boxsizer;
	client_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	client_notebook = new wxNotebook( client_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	client_select_tab = new wxPanel( client_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* client_select_boxsizer;
	client_select_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* client_select_sizer;
	client_select_sizer = new wxGridBagSizer( 0, 0 );
	client_select_sizer->SetFlexibleDirection( wxBOTH );
	client_select_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* client_select_button_sizer;
	client_select_button_sizer = new wxGridBagSizer( 0, 0 );
	client_select_button_sizer->SetFlexibleDirection( wxBOTH );
	client_select_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_launch_button = new wxButton( client_select_tab, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_button_sizer->Add( client_launch_button, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_create_new_button = new wxButton( client_select_tab, wxID_ANY, wxT("Create New"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_button_sizer->Add( client_create_new_button, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_delete_button = new wxButton( client_select_tab, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_button_sizer->Add( client_delete_button, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	rename_client_button = new wxButton( client_select_tab, wxID_ANY, wxT("Rename"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_button_sizer->Add( rename_client_button, wxGBPosition( 0, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_select_sizer->Add( client_select_button_sizer, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* client_select_options_sizer;
	client_select_options_sizer = new wxGridBagSizer( 0, 0 );
	client_select_options_sizer->SetFlexibleDirection( wxBOTH );
	client_select_options_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_check_min_RAM = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Memory Min"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_check_min_RAM, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_min_RAM = new wxTextCtrl( client_select_tab, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_min_RAM, wxGBPosition( 0, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	wxString client_max_memunitChoices[] = { wxT("MiB"), wxT("KiB"), wxT("GiB") };
	int client_max_memunitNChoices = sizeof( client_max_memunitChoices ) / sizeof( wxString );
	client_max_memunit = new wxChoice( client_select_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, client_max_memunitNChoices, client_max_memunitChoices, 0 );
	client_max_memunit->SetSelection( 2 );
	client_select_options_sizer->Add( client_max_memunit, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_check_max_RAM = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Memory Max"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_check_max_RAM, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_max_RAM = new wxTextCtrl( client_select_tab, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_max_RAM, wxGBPosition( 1, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	wxString client_min_memunitChoices[] = { wxT("MiB"), wxT("KiB"), wxT("GiB") };
	int client_min_memunitNChoices = sizeof( client_min_memunitChoices ) / sizeof( wxString );
	client_min_memunit = new wxChoice( client_select_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, client_min_memunitNChoices, client_min_memunitChoices, 0 );
	client_min_memunit->SetSelection( 2 );
	client_select_options_sizer->Add( client_min_memunit, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_check_window_size = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Set Window Size"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_check_window_size, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_window_width = new wxTextCtrl( client_select_tab, wxID_ANY, wxT("854"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_window_width, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText1 = new wxStaticText( client_select_tab, wxID_ANY, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	client_select_options_sizer->Add( m_staticText1, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );
	
	client_window_height = new wxTextCtrl( client_select_tab, wxID_ANY, wxT("480"), wxDefaultPosition, wxDefaultSize, 0 );
	client_select_options_sizer->Add( client_window_height, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* client_fscreen_max_sizer;
	client_fscreen_max_sizer = new wxGridBagSizer( 0, 0 );
	client_fscreen_max_sizer->SetFlexibleDirection( wxBOTH );
	client_fscreen_max_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_check_maximize = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Maximize"), wxDefaultPosition, wxDefaultSize, 0 );
	client_fscreen_max_sizer->Add( client_check_maximize, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_check_fullscreen = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Fullscreen"), wxDefaultPosition, wxDefaultSize, 0 );
	client_fscreen_max_sizer->Add( client_check_fullscreen, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	username_label = new wxStaticText( client_select_tab, wxID_ANY, wxT("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
	username_label->Wrap( -1 );
	client_fscreen_max_sizer->Add( username_label, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	username_text = new wxTextCtrl( client_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	client_fscreen_max_sizer->Add( username_text, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	password_text = new wxTextCtrl( client_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	client_fscreen_max_sizer->Add( password_text, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	password_label = new wxStaticText( client_select_tab, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	password_label->Wrap( -1 );
	client_fscreen_max_sizer->Add( password_label, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	check_force_update = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Force Update"), wxDefaultPosition, wxDefaultSize, 0 );
	client_fscreen_max_sizer->Add( check_force_update, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	purge_instance_contents = new wxCheckBox( client_select_tab, wxID_ANY, wxT("Purge Files"), wxDefaultPosition, wxDefaultSize, 0 );
	client_fscreen_max_sizer->Add( purge_instance_contents, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_select_options_sizer->Add( client_fscreen_max_sizer, wxGBPosition( 3, 0 ), wxGBSpan( 1, 4 ), wxEXPAND, 5 );
	
	client_select_sizer->Add( client_select_options_sizer, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxEXPAND, 0 );
	
	client_instances_label = new wxStaticText( client_select_tab, wxID_ANY, wxT("Instances"), wxDefaultPosition, wxDefaultSize, 0 );
	client_instances_label->Wrap( -1 );
	client_select_sizer->Add( client_instances_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	client_instance_list = new wxListCtrl( client_select_tab, wxID_ANY, wxDefaultPosition, wxSize( 325,300 ), wxLC_HRULES|wxLC_NO_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_select_sizer->Add( client_instance_list, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* gbSizer38;
	gbSizer38 = new wxGridBagSizer( 0, 0 );
	gbSizer38->SetFlexibleDirection( wxBOTH );
	gbSizer38->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_instance_name_textctrl = new wxTextCtrl( client_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	client_instance_name_textctrl->SetMinSize( wxSize( 300,-1 ) );
	
	gbSizer38->Add( client_instance_name_textctrl, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText40 = new wxStaticText( client_select_tab, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	gbSizer38->Add( m_staticText40, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_select_sizer->Add( gbSizer38, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* client_terminal_sizer;
	client_terminal_sizer = new wxGridBagSizer( 0, 0 );
	client_terminal_sizer->SetFlexibleDirection( wxBOTH );
	client_terminal_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_terminal_term = new wxTextCtrl( client_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	client_terminal_term->SetFont( wxFont( 9, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Terminal") ) );
	client_terminal_term->SetForegroundColour( wxColour( 0, 255, 0 ) );
	client_terminal_term->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	client_terminal_term->SetMinSize( wxSize( 450,440 ) );
	
	client_terminal_sizer->Add( client_terminal_term, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_terminal_prompt = new wxTextCtrl( client_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RICH2 );
	client_terminal_prompt->SetFont( wxFont( 9, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Terminal") ) );
	client_terminal_prompt->SetForegroundColour( wxColour( 0, 255, 0 ) );
	client_terminal_prompt->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	client_terminal_prompt->SetMinSize( wxSize( 450,30 ) );
	
	client_terminal_sizer->Add( client_terminal_prompt, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_select_sizer->Add( client_terminal_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 4, 1 ), wxEXPAND, 5 );
	
	client_select_boxsizer->Add( client_select_sizer, 1, wxEXPAND, 5 );
	
	client_select_tab->SetSizer( client_select_boxsizer );
	client_select_tab->Layout();
	client_select_boxsizer->Fit( client_select_tab );
	client_notebook->AddPage( client_select_tab, wxT("Select Instance"), true );
	client_edit_tab = new wxPanel( client_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* client_edit_boxsizer;
	client_edit_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* client_edit_sizer;
	client_edit_sizer = new wxGridBagSizer( 0, 0 );
	client_edit_sizer->SetFlexibleDirection( wxBOTH );
	client_edit_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* client_jarmod_sizer;
	client_jarmod_sizer = new wxGridBagSizer( 0, 0 );
	client_jarmod_sizer->SetFlexibleDirection( wxBOTH );
	client_jarmod_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_jarmod_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Jar Mods"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	client_jarmod_label->Wrap( -1 );
	client_jarmod_sizer->Add( client_jarmod_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	unused_jarmods_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Unused"), wxDefaultPosition, wxDefaultSize, 0 );
	unused_jarmods_label->Wrap( -1 );
	client_jarmod_sizer->Add( unused_jarmods_label, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* client_jarmod_list_sizer;
	client_jarmod_list_sizer = new wxGridBagSizer( 0, 0 );
	client_jarmod_list_sizer->SetFlexibleDirection( wxBOTH );
	client_jarmod_list_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_jarmod_installed = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_jarmod_list_sizer->Add( client_jarmod_installed, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_editlist = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_jarmod_list_sizer->Add( client_jarmod_editlist, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_installed_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Currently Installed"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_installed_label->Wrap( -1 );
	client_jarmod_list_sizer->Add( client_jarmod_installed_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_editlist_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Edited List"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_editlist_label->Wrap( -1 );
	client_jarmod_list_sizer->Add( client_jarmod_editlist_label, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_sizer->Add( client_jarmod_list_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* client_jarmod_button_sizer;
	client_jarmod_button_sizer = new wxGridBagSizer( 0, 0 );
	client_jarmod_button_sizer->SetFlexibleDirection( wxBOTH );
	client_jarmod_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_jarmod_add_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_button_sizer->Add( client_jarmod_add_button, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_up_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_button_sizer->Add( client_jarmod_up_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_down_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_button_sizer->Add( client_jarmod_down_button, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_remove_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_button_sizer->Add( client_jarmod_remove_button, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_buildjar_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Rebuild Jar"), wxDefaultPosition, wxDefaultSize, 0 );
	client_jarmod_button_sizer->Add( client_buildjar_button, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString client_jar_selectChoices;
	client_jar_select = new wxChoice( client_edit_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, client_jar_selectChoices, 0 );
	client_jar_select->SetSelection( 0 );
	client_jar_select->SetToolTip( wxT("Select Desired Client Jar Version") );
	
	client_jarmod_button_sizer->Add( client_jar_select, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_jarmod_sizer->Add( client_jarmod_button_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	client_jarmod_unused = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_jarmod_sizer->Add( client_jarmod_unused, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_edit_sizer->Add( client_jarmod_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* zipModSizer;
	zipModSizer = new wxGridBagSizer( 0, 0 );
	zipModSizer->SetFlexibleDirection( wxBOTH );
	zipModSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_zipmod_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Mod Directory Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_label->Wrap( -1 );
	zipModSizer->Add( client_zipmod_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxGridBagSizer* client_zipmod_list_sizer;
	client_zipmod_list_sizer = new wxGridBagSizer( 0, 0 );
	client_zipmod_list_sizer->SetFlexibleDirection( wxBOTH );
	client_zipmod_list_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	client_zipmod_installed = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_zipmod_list_sizer->Add( client_zipmod_installed, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_zipmod_editlist = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	client_zipmod_list_sizer->Add( client_zipmod_editlist, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_zipmod_installed_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Currently Installed"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_installed_label->Wrap( -1 );
	client_zipmod_list_sizer->Add( client_zipmod_installed_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_zipmod_editlist_label = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Edited List"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_editlist_label->Wrap( -1 );
	client_zipmod_list_sizer->Add( client_zipmod_editlist_label, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	zipModSizer->Add( client_zipmod_list_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* client_zipmod_button_sizer;
	client_zipmod_button_sizer = new wxGridBagSizer( 0, 0 );
	client_zipmod_button_sizer->SetFlexibleDirection( wxBOTH );
	client_zipmod_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	client_zipmod_button_sizer->Add( 0, 30, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	client_zipmod_add_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_button_sizer->Add( client_zipmod_add_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_zipmod_remove_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_button_sizer->Add( client_zipmod_remove_button, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_zipmod_apply_button = new wxButton( client_edit_tab, wxID_ANY, wxT("Apply Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	client_zipmod_button_sizer->Add( client_zipmod_apply_button, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	zipModSizer->Add( client_zipmod_button_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	client_zipmod_unused = new wxListCtrl( client_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	zipModSizer->Add( client_zipmod_unused, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	unused_jarmods_label1 = new wxStaticText( client_edit_tab, wxID_ANY, wxT("Unused"), wxDefaultPosition, wxDefaultSize, 0 );
	unused_jarmods_label1->Wrap( -1 );
	zipModSizer->Add( unused_jarmods_label1, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_edit_sizer->Add( zipModSizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	client_edit_boxsizer->Add( client_edit_sizer, 1, wxEXPAND, 5 );
	
	client_edit_tab->SetSizer( client_edit_boxsizer );
	client_edit_tab->Layout();
	client_edit_boxsizer->Fit( client_edit_tab );
	client_notebook->AddPage( client_edit_tab, wxT("Edit Instance"), false );
	
	client_tab_boxsizer->Add( client_notebook, 1, wxEXPAND | wxALL, 5 );
	
	client_tab->SetSizer( client_tab_boxsizer );
	client_tab->Layout();
	client_tab_boxsizer->Fit( client_tab );
	frame_notebook->AddPage( client_tab, wxT("Client Configurations"), false );
	clientmod_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* clientmod_tab_boxsizer;
	clientmod_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* clientmod_tab_sizer;
	clientmod_tab_sizer = new wxGridBagSizer( 0, 0 );
	clientmod_tab_sizer->SetFlexibleDirection( wxBOTH );
	clientmod_tab_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	clientmod_jarmod_list = new wxListCtrl( clientmod_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	clientmod_tab_sizer->Add( clientmod_jarmod_list, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	clientmod_zipmod_list = new wxListCtrl( clientmod_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	clientmod_tab_sizer->Add( clientmod_zipmod_list, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* clientmod_jarmod_radio_sizer;
	clientmod_jarmod_radio_sizer = new wxGridBagSizer( 0, 0 );
	clientmod_jarmod_radio_sizer->SetFlexibleDirection( wxBOTH );
	clientmod_jarmod_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	clientmod_jarmod_radio = new wxRadioButton( clientmod_tab, wxID_ANY, wxT("JarMods"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	clientmod_jarmod_radio_sizer->Add( clientmod_jarmod_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	clientmod_tab_sizer->Add( clientmod_jarmod_radio_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridBagSizer* clientmod_zipmod_radio_sizer;
	clientmod_zipmod_radio_sizer = new wxGridBagSizer( 0, 0 );
	clientmod_zipmod_radio_sizer->SetFlexibleDirection( wxBOTH );
	clientmod_zipmod_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	clientmod_zipmod_radio = new wxRadioButton( clientmod_tab, wxID_ANY, wxT("Mod Folder Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	clientmod_zipmod_radio_sizer->Add( clientmod_zipmod_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	clientmod_tab_sizer->Add( clientmod_zipmod_radio_sizer, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	clientmod_tab_sizer->Add( 20, 0, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* clientmod_buttons_sizer;
	clientmod_buttons_sizer = new wxGridBagSizer( 0, 0 );
	clientmod_buttons_sizer->SetFlexibleDirection( wxBOTH );
	clientmod_buttons_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	clientmod_filepicker = new wxFilePickerCtrl( clientmod_tab, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.zip"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_USE_TEXTCTRL );
	clientmod_filepicker->SetMinSize( wxSize( 200,30 ) );
	
	clientmod_buttons_sizer->Add( clientmod_filepicker, wxGBPosition( 1, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	client_mod_name_label = new wxStaticText( clientmod_tab, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	client_mod_name_label->Wrap( -1 );
	clientmod_buttons_sizer->Add( client_mod_name_label, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_mod_name_textctrl = new wxTextCtrl( clientmod_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	clientmod_buttons_sizer->Add( client_mod_name_textctrl, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	clientmod_add_button = new wxButton( clientmod_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	clientmod_buttons_sizer->Add( clientmod_add_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxALL|wxEXPAND, 5 );
	
	clientmod_replace_button = new wxButton( clientmod_tab, wxID_ANY, wxT("Replace"), wxDefaultPosition, wxDefaultSize, 0 );
	clientmod_buttons_sizer->Add( clientmod_replace_button, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	clientmod_remove_button = new wxButton( clientmod_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	clientmod_buttons_sizer->Add( clientmod_remove_button, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_mod_version_label = new wxStaticText( clientmod_tab, wxID_ANY, wxT("Version"), wxDefaultPosition, wxDefaultSize, 0 );
	client_mod_version_label->Wrap( -1 );
	clientmod_buttons_sizer->Add( client_mod_version_label, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString client_mod_compatible_jar_version_choiceChoices;
	client_mod_compatible_jar_version_choice = new wxChoice( clientmod_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, client_mod_compatible_jar_version_choiceChoices, 0 );
	client_mod_compatible_jar_version_choice->SetSelection( 0 );
	clientmod_buttons_sizer->Add( client_mod_compatible_jar_version_choice, wxGBPosition( 2, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	clientmod_tab_sizer->Add( clientmod_buttons_sizer, wxGBPosition( 2, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	clientmod_tab_boxsizer->Add( clientmod_tab_sizer, 1, wxEXPAND, 5 );
	
	clientmod_tab->SetSizer( clientmod_tab_boxsizer );
	clientmod_tab->Layout();
	clientmod_tab_boxsizer->Fit( clientmod_tab );
	frame_notebook->AddPage( clientmod_tab, wxT("Client Mods"), false );
	server_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* server_tab_sizer;
	server_tab_sizer = new wxBoxSizer( wxVERTICAL );
	
	server_notebook = new wxNotebook( server_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	server_select_tab = new wxPanel( server_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* server_select_boxsizer;
	server_select_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* server_select_sizer;
	server_select_sizer = new wxGridBagSizer( 0, 0 );
	server_select_sizer->SetFlexibleDirection( wxBOTH );
	server_select_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_instance_list = new wxListCtrl( server_select_tab, wxID_ANY, wxDefaultPosition, wxSize( 325,300 ), wxLC_HRULES|wxLC_NO_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_select_sizer->Add( server_instance_list, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* gbSizer39;
	gbSizer39 = new wxGridBagSizer( 0, 0 );
	gbSizer39->SetFlexibleDirection( wxBOTH );
	gbSizer39->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_instance_name_textctrl = new wxTextCtrl( server_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	server_instance_name_textctrl->SetMinSize( wxSize( 300,-1 ) );
	
	gbSizer39->Add( server_instance_name_textctrl, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_instance_name_label = new wxStaticText( server_select_tab, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	server_instance_name_label->Wrap( -1 );
	gbSizer39->Add( server_instance_name_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_select_sizer->Add( gbSizer39, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* server_select_button_sizer;
	server_select_button_sizer = new wxGridBagSizer( 0, 0 );
	server_select_button_sizer->SetFlexibleDirection( wxBOTH );
	server_select_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_launch_button = new wxButton( server_select_tab, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_button_sizer->Add( server_launch_button, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_create_new_button = new wxButton( server_select_tab, wxID_ANY, wxT("Create New"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_button_sizer->Add( server_create_new_button, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_delete_button = new wxButton( server_select_tab, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_button_sizer->Add( server_delete_button, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_rename_button = new wxButton( server_select_tab, wxID_ANY, wxT("Rename"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_button_sizer->Add( server_rename_button, wxGBPosition( 0, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_select_sizer->Add( server_select_button_sizer, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* server_select_options_sizer;
	server_select_options_sizer = new wxGridBagSizer( 0, 0 );
	server_select_options_sizer->SetFlexibleDirection( wxBOTH );
	server_select_options_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_check_min_RAM = new wxCheckBox( server_select_tab, wxID_ANY, wxT("Memory Min"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_options_sizer->Add( server_check_min_RAM, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_min_RAM = new wxTextCtrl( server_select_tab, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_options_sizer->Add( server_min_RAM, wxGBPosition( 0, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	wxString server_max_memunitChoices[] = { wxT("MiB"), wxT("KiB"), wxT("GiB") };
	int server_max_memunitNChoices = sizeof( server_max_memunitChoices ) / sizeof( wxString );
	server_max_memunit = new wxChoice( server_select_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, server_max_memunitNChoices, server_max_memunitChoices, 0 );
	server_max_memunit->SetSelection( 2 );
	server_select_options_sizer->Add( server_max_memunit, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_check_max_RAM = new wxCheckBox( server_select_tab, wxID_ANY, wxT("Memory Max"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_options_sizer->Add( server_check_max_RAM, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_max_RAM = new wxTextCtrl( server_select_tab, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	server_select_options_sizer->Add( server_max_RAM, wxGBPosition( 1, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	wxString server_min_memunitChoices[] = { wxT("MiB"), wxT("KiB"), wxT("GiB") };
	int server_min_memunitNChoices = sizeof( server_min_memunitChoices ) / sizeof( wxString );
	server_min_memunit = new wxChoice( server_select_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, server_min_memunitNChoices, server_min_memunitChoices, 0 );
	server_min_memunit->SetSelection( 2 );
	server_select_options_sizer->Add( server_min_memunit, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_select_sizer->Add( server_select_options_sizer, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxEXPAND, 0 );
	
	server_instances_label = new wxStaticText( server_select_tab, wxID_ANY, wxT("Instances"), wxDefaultPosition, wxDefaultSize, 0 );
	server_instances_label->Wrap( -1 );
	server_select_sizer->Add( server_instances_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxGridBagSizer* server_terminal_sizer;
	server_terminal_sizer = new wxGridBagSizer( 0, 0 );
	server_terminal_sizer->SetFlexibleDirection( wxBOTH );
	server_terminal_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_terminal_term = new wxTextCtrl( server_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	server_terminal_term->SetFont( wxFont( 9, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Terminal") ) );
	server_terminal_term->SetForegroundColour( wxColour( 0, 255, 0 ) );
	server_terminal_term->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	server_terminal_term->SetMinSize( wxSize( 450,440 ) );
	
	server_terminal_sizer->Add( server_terminal_term, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_terminal_prompt = new wxTextCtrl( server_select_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RICH2 );
	server_terminal_prompt->SetFont( wxFont( 9, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Terminal") ) );
	server_terminal_prompt->SetForegroundColour( wxColour( 0, 255, 0 ) );
	server_terminal_prompt->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	server_terminal_prompt->SetMinSize( wxSize( 450,30 ) );
	
	server_terminal_sizer->Add( server_terminal_prompt, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_select_sizer->Add( server_terminal_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 4, 1 ), wxEXPAND, 5 );
	
	server_select_boxsizer->Add( server_select_sizer, 1, wxEXPAND, 5 );
	
	server_select_tab->SetSizer( server_select_boxsizer );
	server_select_tab->Layout();
	server_select_boxsizer->Fit( server_select_tab );
	server_notebook->AddPage( server_select_tab, wxT("Select Instance"), true );
	server_edit_tab = new wxPanel( server_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* server_edit_boxsizer;
	server_edit_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* server_edit_sizer;
	server_edit_sizer = new wxGridBagSizer( 0, 0 );
	server_edit_sizer->SetFlexibleDirection( wxBOTH );
	server_edit_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* server_jarmod_sizer;
	server_jarmod_sizer = new wxGridBagSizer( 0, 0 );
	server_jarmod_sizer->SetFlexibleDirection( wxBOTH );
	server_jarmod_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_jarmod_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Jar Mods"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	server_jarmod_label->Wrap( -1 );
	server_jarmod_sizer->Add( server_jarmod_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	server_unused_jarmod_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Unused"), wxDefaultPosition, wxDefaultSize, 0 );
	server_unused_jarmod_label->Wrap( -1 );
	server_jarmod_sizer->Add( server_unused_jarmod_label, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_unused = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_jarmod_sizer->Add( server_jarmod_unused, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* server_jarmod_list_sizer;
	server_jarmod_list_sizer = new wxGridBagSizer( 0, 0 );
	server_jarmod_list_sizer->SetFlexibleDirection( wxBOTH );
	server_jarmod_list_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_jarmod_installed_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Currently Installed"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_installed_label->Wrap( -1 );
	server_jarmod_list_sizer->Add( server_jarmod_installed_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_installed = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_jarmod_list_sizer->Add( server_jarmod_installed, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_editlist = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_jarmod_list_sizer->Add( server_jarmod_editlist, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_editlist_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Edited List"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_editlist_label->Wrap( -1 );
	server_jarmod_list_sizer->Add( server_jarmod_editlist_label, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_sizer->Add( server_jarmod_list_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* server_jarmod_button_sizer;
	server_jarmod_button_sizer = new wxGridBagSizer( 0, 0 );
	server_jarmod_button_sizer->SetFlexibleDirection( wxBOTH );
	server_jarmod_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_jarmod_add_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_button_sizer->Add( server_jarmod_add_button, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_up_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_button_sizer->Add( server_jarmod_up_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_down_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_button_sizer->Add( server_jarmod_down_button, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_remove_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_button_sizer->Add( server_jarmod_remove_button, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_buildjar_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Rebuild Jar"), wxDefaultPosition, wxDefaultSize, 0 );
	server_jarmod_button_sizer->Add( server_buildjar_button, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString server_jar_selectChoices;
	server_jar_select = new wxChoice( server_edit_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, server_jar_selectChoices, 0 );
	server_jar_select->SetSelection( 0 );
	server_jar_select->SetToolTip( wxT("Select desired server jar version") );
	
	server_jarmod_button_sizer->Add( server_jar_select, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_jarmod_sizer->Add( server_jarmod_button_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	server_edit_sizer->Add( server_jarmod_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* server_zipmod_sizer;
	server_zipmod_sizer = new wxGridBagSizer( 0, 0 );
	server_zipmod_sizer->SetFlexibleDirection( wxBOTH );
	server_zipmod_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_zipmod_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Mod Directory Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_label->Wrap( -1 );
	server_zipmod_sizer->Add( server_zipmod_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	server_unused_zipmod_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Unused"), wxDefaultPosition, wxDefaultSize, 0 );
	server_unused_zipmod_label->Wrap( -1 );
	server_zipmod_sizer->Add( server_unused_zipmod_label, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_unused = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_zipmod_sizer->Add( server_zipmod_unused, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* server_zipmod_list_sizer;
	server_zipmod_list_sizer = new wxGridBagSizer( 0, 0 );
	server_zipmod_list_sizer->SetFlexibleDirection( wxBOTH );
	server_zipmod_list_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	server_zipmod_installed_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Currently Installed"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_installed_label->Wrap( -1 );
	server_zipmod_list_sizer->Add( server_zipmod_installed_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_editlist_label = new wxStaticText( server_edit_tab, wxID_ANY, wxT("Edited List"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_editlist_label->Wrap( -1 );
	server_zipmod_list_sizer->Add( server_zipmod_editlist_label, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_installed = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_zipmod_list_sizer->Add( server_zipmod_installed, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_editlist = new wxListCtrl( server_edit_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,200 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	server_zipmod_list_sizer->Add( server_zipmod_editlist, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_sizer->Add( server_zipmod_list_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* server_zipmod_button_sizer;
	server_zipmod_button_sizer = new wxGridBagSizer( 0, 0 );
	server_zipmod_button_sizer->SetFlexibleDirection( wxBOTH );
	server_zipmod_button_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	server_zipmod_button_sizer->Add( 0, 30, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	server_zipmod_add_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_button_sizer->Add( server_zipmod_add_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_remove_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_button_sizer->Add( server_zipmod_remove_button, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_apply_button = new wxButton( server_edit_tab, wxID_ANY, wxT("Apply Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	server_zipmod_button_sizer->Add( server_zipmod_apply_button, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_zipmod_sizer->Add( server_zipmod_button_sizer, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	server_edit_sizer->Add( server_zipmod_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	server_edit_boxsizer->Add( server_edit_sizer, 1, wxEXPAND, 5 );
	
	server_edit_tab->SetSizer( server_edit_boxsizer );
	server_edit_tab->Layout();
	server_edit_boxsizer->Fit( server_edit_tab );
	server_notebook->AddPage( server_edit_tab, wxT("Edit Instance"), false );
	
	server_tab_sizer->Add( server_notebook, 1, wxEXPAND | wxALL, 5 );
	
	server_tab->SetSizer( server_tab_sizer );
	server_tab->Layout();
	server_tab_sizer->Fit( server_tab );
	frame_notebook->AddPage( server_tab, wxT("Server Configurations"), false );
	servermod_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* servermod_tab_boxsizer;
	servermod_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* servermod_tab_sizer;
	servermod_tab_sizer = new wxGridBagSizer( 0, 0 );
	servermod_tab_sizer->SetFlexibleDirection( wxBOTH );
	servermod_tab_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* servermod_jarmod_radio_sizer;
	servermod_jarmod_radio_sizer = new wxGridBagSizer( 0, 0 );
	servermod_jarmod_radio_sizer->SetFlexibleDirection( wxBOTH );
	servermod_jarmod_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	servermod_jarmod_radio = new wxRadioButton( servermod_tab, wxID_ANY, wxT("JarMods"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	servermod_jarmod_radio_sizer->Add( servermod_jarmod_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	servermod_tab_sizer->Add( servermod_jarmod_radio_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridBagSizer* servermod_zipmod_radio_sizer;
	servermod_zipmod_radio_sizer = new wxGridBagSizer( 0, 0 );
	servermod_zipmod_radio_sizer->SetFlexibleDirection( wxBOTH );
	servermod_zipmod_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	servermod_zipmod_radio = new wxRadioButton( servermod_tab, wxID_ANY, wxT("Mod Folder Mods"), wxDefaultPosition, wxDefaultSize, 0 );
	servermod_zipmod_radio_sizer->Add( servermod_zipmod_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	servermod_tab_sizer->Add( servermod_zipmod_radio_sizer, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	servermod_tab_sizer->Add( 20, 0, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* servermod_buttons_sizer;
	servermod_buttons_sizer = new wxGridBagSizer( 0, 0 );
	servermod_buttons_sizer->SetFlexibleDirection( wxBOTH );
	servermod_buttons_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	servermod_filepicker = new wxFilePickerCtrl( servermod_tab, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.zip"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_USE_TEXTCTRL );
	servermod_filepicker->SetMinSize( wxSize( 200,30 ) );
	
	servermod_buttons_sizer->Add( servermod_filepicker, wxGBPosition( 1, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	server_mod_name_label = new wxStaticText( servermod_tab, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	server_mod_name_label->Wrap( -1 );
	servermod_buttons_sizer->Add( server_mod_name_label, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_mod_name_textctrl = new wxTextCtrl( servermod_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	servermod_buttons_sizer->Add( server_mod_name_textctrl, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	servermod_add_button = new wxButton( servermod_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	servermod_buttons_sizer->Add( servermod_add_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxALL|wxEXPAND, 5 );
	
	servermod_replace_button = new wxButton( servermod_tab, wxID_ANY, wxT("Replace"), wxDefaultPosition, wxDefaultSize, 0 );
	servermod_buttons_sizer->Add( servermod_replace_button, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	servermod_remove_button = new wxButton( servermod_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	servermod_buttons_sizer->Add( servermod_remove_button, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_mod_version_label = new wxStaticText( servermod_tab, wxID_ANY, wxT("Version"), wxDefaultPosition, wxDefaultSize, 0 );
	server_mod_version_label->Wrap( -1 );
	servermod_buttons_sizer->Add( server_mod_version_label, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString server_mod_compatible_jar_version_choiceChoices;
	server_mod_compatible_jar_version_choice = new wxChoice( servermod_tab, wxID_ANY, wxDefaultPosition, wxDefaultSize, server_mod_compatible_jar_version_choiceChoices, 0 );
	server_mod_compatible_jar_version_choice->SetSelection( 0 );
	servermod_buttons_sizer->Add( server_mod_compatible_jar_version_choice, wxGBPosition( 2, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	servermod_tab_sizer->Add( servermod_buttons_sizer, wxGBPosition( 2, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	servermod_jarmod_list = new wxListCtrl( servermod_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	servermod_tab_sizer->Add( servermod_jarmod_list, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	servermod_zipmod_list = new wxListCtrl( servermod_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	servermod_tab_sizer->Add( servermod_zipmod_list, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	servermod_tab_boxsizer->Add( servermod_tab_sizer, 1, wxEXPAND, 5 );
	
	servermod_tab->SetSizer( servermod_tab_boxsizer );
	servermod_tab->Layout();
	servermod_tab_boxsizer->Fit( servermod_tab );
	frame_notebook->AddPage( servermod_tab, wxT("Server Mods"), false );
	jars_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* jars_tab_boxsizer;
	jars_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* jars_tab_sizer;
	jars_tab_sizer = new wxGridBagSizer( 0, 0 );
	jars_tab_sizer->SetFlexibleDirection( wxBOTH );
	jars_tab_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* jars_list_sizer;
	jars_list_sizer = new wxGridBagSizer( 0, 0 );
	jars_list_sizer->SetFlexibleDirection( wxBOTH );
	jars_list_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	jars_client_list = new wxListCtrl( jars_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	jars_list_sizer->Add( jars_client_list, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	jars_server_list = new wxListCtrl( jars_tab, wxID_ANY, wxDefaultPosition, wxSize( 200,300 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	jars_list_sizer->Add( jars_server_list, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	jars_list_sizer->Add( 20, 0, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* jars_client_radio_sizer;
	jars_client_radio_sizer = new wxGridBagSizer( 0, 0 );
	jars_client_radio_sizer->SetFlexibleDirection( wxBOTH );
	jars_client_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	jars_client_radio = new wxRadioButton( jars_tab, wxID_ANY, wxT("Client Jars"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_client_radio_sizer->Add( jars_client_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	jars_list_sizer->Add( jars_client_radio_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxGridBagSizer* jars_server_radio_sizer;
	jars_server_radio_sizer = new wxGridBagSizer( 0, 0 );
	jars_server_radio_sizer->SetFlexibleDirection( wxBOTH );
	jars_server_radio_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	jars_server_radio = new wxRadioButton( jars_tab, wxID_ANY, wxT("Server Jars"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_server_radio_sizer->Add( jars_server_radio, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	jars_list_sizer->Add( jars_server_radio_sizer, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	jars_tab_sizer->Add( jars_list_sizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* jars_buttons_sizer;
	jars_buttons_sizer = new wxGridBagSizer( 0, 0 );
	jars_buttons_sizer->SetFlexibleDirection( wxBOTH );
	jars_buttons_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	jars_jar_filepicker = new wxFilePickerCtrl( jars_tab, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_FILE_MUST_EXIST|wxFLP_USE_TEXTCTRL );
	jars_jar_filepicker->SetMinSize( wxSize( 250,30 ) );
	
	jars_buttons_sizer->Add( jars_jar_filepicker, wxGBPosition( 0, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	jars_version_number = new wxTextCtrl( jars_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	jars_buttons_sizer->Add( jars_version_number, wxGBPosition( 1, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	jars_filepicker_label = new wxStaticText( jars_tab, wxID_ANY, wxT("Select Jar"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_filepicker_label->Wrap( -1 );
	jars_buttons_sizer->Add( jars_filepicker_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	jars_version_label = new wxStaticText( jars_tab, wxID_ANY, wxT("Version Number"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_version_label->Wrap( -1 );
	jars_buttons_sizer->Add( jars_version_label, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	jars_add_button = new wxButton( jars_tab, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_buttons_sizer->Add( jars_add_button, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxALL|wxEXPAND, 5 );
	
	jars_replace_button = new wxButton( jars_tab, wxID_ANY, wxT("Replace"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_buttons_sizer->Add( jars_replace_button, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	jars_remove_button = new wxButton( jars_tab, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	jars_buttons_sizer->Add( jars_remove_button, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	jars_tab_sizer->Add( jars_buttons_sizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	jars_tab_boxsizer->Add( jars_tab_sizer, 1, wxEXPAND, 5 );
	
	jars_tab->SetSizer( jars_tab_boxsizer );
	jars_tab->Layout();
	jars_tab_boxsizer->Fit( jars_tab );
	frame_notebook->AddPage( jars_tab, wxT("Jars"), false );
	option_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* option_tab_boxsizer;
	option_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* option_tab_sizer;
	option_tab_sizer = new wxGridBagSizer( 0, 0 );
	option_tab_sizer->SetFlexibleDirection( wxBOTH );
	option_tab_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	javabin_dir_label = new wxStaticText( option_tab, wxID_ANY, wxT("Java Binary Directory"), wxDefaultPosition, wxDefaultSize, 0 );
	javabin_dir_label->Wrap( -1 );
	option_tab_sizer->Add( javabin_dir_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	instancedir_label = new wxStaticText( option_tab, wxID_ANY, wxT("Instance Directory"), wxDefaultPosition, wxDefaultSize, 0 );
	instancedir_label->Wrap( -1 );
	option_tab_sizer->Add( instancedir_label, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	option_clientjar_label = new wxStaticText( option_tab, wxID_ANY, wxT("Where to store client jars"), wxDefaultPosition, wxDefaultSize, 0 );
	option_clientjar_label->Wrap( -1 );
	option_tab_sizer->Add( option_clientjar_label, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	option_serverjar_label = new wxStaticText( option_tab, wxID_ANY, wxT("Where to store server jars"), wxDefaultPosition, wxDefaultSize, 0 );
	option_serverjar_label->Wrap( -1 );
	option_tab_sizer->Add( option_serverjar_label, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	wxString java_usepath_radioboxChoices[] = { wxT("Use java commands from above path"), wxT("Use raw java commands (ignore path)") };
	int java_usepath_radioboxNChoices = sizeof( java_usepath_radioboxChoices ) / sizeof( wxString );
	java_usepath_radiobox = new wxRadioBox( option_tab, wxID_ANY, wxT("Java options"), wxDefaultPosition, wxDefaultSize, java_usepath_radioboxNChoices, java_usepath_radioboxChoices, 1, wxRA_SPECIFY_COLS );
	java_usepath_radiobox->SetSelection( 0 );
	option_tab_sizer->Add( java_usepath_radiobox, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	check_java_is_JDK = new wxCheckBox( option_tab, wxID_ANY, wxT("Selected Java is a JDK"), wxDefaultPosition, wxDefaultSize, 0 );
	option_tab_sizer->Add( check_java_is_JDK, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	server_freshjar_dirpicker = new wxDirPickerCtrl( option_tab, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL );
	server_freshjar_dirpicker->SetMinSize( wxSize( 325,30 ) );
	
	option_tab_sizer->Add( server_freshjar_dirpicker, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	java_directory_picker = new wxDirPickerCtrl( option_tab, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL );
	java_directory_picker->SetMinSize( wxSize( 325,30 ) );
	
	option_tab_sizer->Add( java_directory_picker, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	client_freshjar_dirpicker = new wxDirPickerCtrl( option_tab, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL );
	client_freshjar_dirpicker->SetMinSize( wxSize( 325,30 ) );
	
	option_tab_sizer->Add( client_freshjar_dirpicker, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	instance_directory_picker = new wxDirPickerCtrl( option_tab, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL );
	instance_directory_picker->SetMinSize( wxSize( 325,30 ) );
	
	option_tab_sizer->Add( instance_directory_picker, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString client_freshjar_behavior_radioboxChoices[] = { wxT("Make Local Copy"), wxT("Use Specified Path") };
	int client_freshjar_behavior_radioboxNChoices = sizeof( client_freshjar_behavior_radioboxChoices ) / sizeof( wxString );
	client_freshjar_behavior_radiobox = new wxRadioBox( option_tab, wxID_ANY, wxT("Fresh Client Jar Select Behavior"), wxDefaultPosition, wxDefaultSize, client_freshjar_behavior_radioboxNChoices, client_freshjar_behavior_radioboxChoices, 1, wxRA_SPECIFY_COLS );
	client_freshjar_behavior_radiobox->SetSelection( 0 );
	option_tab_sizer->Add( client_freshjar_behavior_radiobox, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString server_freshjar_behavior_radioboxChoices[] = { wxT("Make Local Copy"), wxT("Use Specified Path") };
	int server_freshjar_behavior_radioboxNChoices = sizeof( server_freshjar_behavior_radioboxChoices ) / sizeof( wxString );
	server_freshjar_behavior_radiobox = new wxRadioBox( option_tab, wxID_ANY, wxT("Fresh Server Jar Select Behavior"), wxDefaultPosition, wxDefaultSize, server_freshjar_behavior_radioboxNChoices, server_freshjar_behavior_radioboxChoices, 1, wxRA_SPECIFY_COLS );
	server_freshjar_behavior_radiobox->SetSelection( 0 );
	option_tab_sizer->Add( server_freshjar_behavior_radiobox, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString instance_behavior_radioboxChoices[] = { wxT("Make Local Copy"), wxT("Use Specified Path") };
	int instance_behavior_radioboxNChoices = sizeof( instance_behavior_radioboxChoices ) / sizeof( wxString );
	instance_behavior_radiobox = new wxRadioBox( option_tab, wxID_ANY, wxT("Instance Location Behavior"), wxDefaultPosition, wxDefaultSize, instance_behavior_radioboxNChoices, instance_behavior_radioboxChoices, 1, wxRA_SPECIFY_COLS );
	instance_behavior_radiobox->SetSelection( 0 );
	option_tab_sizer->Add( instance_behavior_radiobox, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	apply_settings_button = new wxButton( option_tab, wxID_ANY, wxT("Apply Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	option_tab_sizer->Add( apply_settings_button, wxGBPosition( 9, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxGridBagSizer* gbSizer37;
	gbSizer37 = new wxGridBagSizer( 0, 0 );
	gbSizer37->SetFlexibleDirection( wxBOTH );
	gbSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	current_java_bin_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Java Executable:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_java_bin_path_label->Wrap( -1 );
	gbSizer37->Add( current_java_bin_path_label, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_java_bin_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_java_bin_path, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	instance_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Instance Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	instance_path_label->Wrap( -1 );
	gbSizer37->Add( instance_path_label, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_instance_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_instance_path, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_client_instance_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Client Instance Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_client_instance_path_label->Wrap( -1 );
	gbSizer37->Add( current_client_instance_path_label, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_client_instance_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_client_instance_path, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_client_jar_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Client Jar Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_client_jar_path_label->Wrap( -1 );
	gbSizer37->Add( current_client_jar_path_label, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_client_jar_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_client_jar_path, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_server_instance_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Server Instance Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_server_instance_path_label->Wrap( -1 );
	gbSizer37->Add( current_server_instance_path_label, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_server_instance_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_server_instance_path, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_server_jar_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Server Jar Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_server_jar_path_label->Wrap( -1 );
	gbSizer37->Add( current_server_jar_path_label, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_server_jar_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_server_jar_path, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_client_jarmods_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Client Jar Mods Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_client_jarmods_path_label->Wrap( -1 );
	gbSizer37->Add( current_client_jarmods_path_label, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_client_jarmods_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_client_jarmods_path, wxGBPosition( 6, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_client_zipmods_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Client Directory Mods Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_client_zipmods_path_label->Wrap( -1 );
	gbSizer37->Add( current_client_zipmods_path_label, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_client_zipmods_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_client_zipmods_path, wxGBPosition( 7, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_server_jarmods_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Server Jar Mods Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_server_jarmods_path_label->Wrap( -1 );
	gbSizer37->Add( current_server_jarmods_path_label, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_server_jarmods_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_server_jarmods_path, wxGBPosition( 8, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	current_server_zipmods_path_label = new wxStaticText( option_tab, wxID_ANY, wxT("Server Directory Mods Path:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	current_server_zipmods_path_label->Wrap( -1 );
	gbSizer37->Add( current_server_zipmods_path_label, wxGBPosition( 9, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	current_server_zipmods_path = new wxTextCtrl( option_tab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,30 ), wxTE_READONLY );
	gbSizer37->Add( current_server_zipmods_path, wxGBPosition( 9, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	option_tab_sizer->Add( gbSizer37, wxGBPosition( 4, 1 ), wxGBSpan( 6, 1 ), wxEXPAND, 5 );
	
	option_tab_boxsizer->Add( option_tab_sizer, 1, wxEXPAND, 5 );
	
	option_tab->SetSizer( option_tab_boxsizer );
	option_tab->Layout();
	option_tab_boxsizer->Fit( option_tab );
	frame_notebook->AddPage( option_tab, wxT("Paths && Options"), false );
	howto_tab = new wxScrolledWindow( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	howto_tab->SetScrollRate( 5, 5 );
	wxBoxSizer* howto_tab_boxsizer;
	howto_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	howto_tab->SetSizer( howto_tab_boxsizer );
	howto_tab->Layout();
	howto_tab_boxsizer->Fit( howto_tab );
	frame_notebook->AddPage( howto_tab, wxT("How To"), true );
	about_tab = new wxPanel( frame_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* about_tab_boxsizer;
	about_tab_boxsizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* about_tab_sizer;
	about_tab_sizer = new wxGridBagSizer( 0, 0 );
	about_tab_sizer->SetFlexibleDirection( wxBOTH );
	about_tab_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	about_tab_boxsizer->Add( about_tab_sizer, 1, wxEXPAND, 5 );
	
	about_tab->SetSizer( about_tab_boxsizer );
	about_tab->Layout();
	about_tab_boxsizer->Fit( about_tab );
	frame_notebook->AddPage( about_tab, wxT("About"), false );
	
	frame_boxsizer->Add( frame_notebook, 1, wxEXPAND | wxALL, 1 );
	
	this->SetSizer( frame_boxsizer );
	this->Layout();
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	frame_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::tab_changing ), NULL, this );
	client_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::client_page_changing ), NULL, this );
	client_launch_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_launch_clicked ), NULL, this );
	client_create_new_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_create_new_clicked ), NULL, this );
	client_delete_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_delete_clicked ), NULL, this );
	rename_client_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_rename_clicked ), NULL, this );
	check_force_update->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::force_update_checked ), NULL, this );
	purge_instance_contents->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::purge_files_checked ), NULL, this );
	client_instance_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_instance_selected ), NULL, this );
	client_terminal_prompt->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::client_terminal_enter_press ), NULL, this );
	client_jarmod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_add_clicked ), NULL, this );
	client_jarmod_up_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_up_clicked ), NULL, this );
	client_jarmod_down_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_down_clicked ), NULL, this );
	client_jarmod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_remove_clicked ), NULL, this );
	client_buildjar_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_buildjar_clicked ), NULL, this );
	client_jar_select->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::client_edit_jar_version_selected ), NULL, this );
	client_zipmod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_add_clicked ), NULL, this );
	client_zipmod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_remove_clicked ), NULL, this );
	client_zipmod_apply_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_apply_clicked ), NULL, this );
	clientmod_jarmod_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_jarmod_selected ), NULL, this );
	clientmod_zipmod_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_zipmod_selected ), NULL, this );
	clientmod_filepicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIFrame::client_modfile_selected ), NULL, this );
	clientmod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_add_clicked ), NULL, this );
	clientmod_replace_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_replace_clicked ), NULL, this );
	clientmod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_remove_clicked ), NULL, this );
	server_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::server_page_changing ), NULL, this );
	server_instance_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_instance_selected ), NULL, this );
	server_launch_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_launch_clicked ), NULL, this );
	server_create_new_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_create_new_clicked ), NULL, this );
	server_delete_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_delete_clicked ), NULL, this );
	server_rename_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_rename_clicked ), NULL, this );
	server_terminal_prompt->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::server_terminal_enter_press ), NULL, this );
	server_jarmod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_add_clicked ), NULL, this );
	server_jarmod_up_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_up_clicked ), NULL, this );
	server_jarmod_down_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_down_clicked ), NULL, this );
	server_jarmod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_remove_clicked ), NULL, this );
	server_buildjar_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_buildjar_clicked ), NULL, this );
	server_jar_select->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::server_edit_jar_version_selected ), NULL, this );
	server_zipmod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_add_clicked ), NULL, this );
	server_zipmod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_remove_clicked ), NULL, this );
	server_zipmod_apply_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_apply_clicked ), NULL, this );
	servermod_filepicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIFrame::server_modfile_selected ), NULL, this );
	servermod_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_add_clicked ), NULL, this );
	servermod_replace_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_replace_clicked ), NULL, this );
	servermod_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_remove_clicked ), NULL, this );
	servermod_jarmod_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_jarmod_selected ), NULL, this );
	servermod_zipmod_list->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_zipmod_selected ), NULL, this );
	jars_add_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_add_clicked ), NULL, this );
	jars_replace_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_replace_clicked ), NULL, this );
	jars_remove_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_remove_clicked ), NULL, this );
	apply_settings_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::Apply_Settings ), NULL, this );
	this->Connect( wxEVT_TIMER, wxTimerEventHandler( GUIFrame::timer_interval ));
	this->Connect( wxEVT_END_PROCESS , wxProcessEventHandler( GUIFrame::process_end ));
	parent_app= new ParentApp(this);
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	frame_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::tab_changing ), NULL, this );
	client_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::client_page_changing ), NULL, this );
	client_launch_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_launch_clicked ), NULL, this );
	client_create_new_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_create_new_clicked ), NULL, this );
	client_delete_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_delete_clicked ), NULL, this );
	rename_client_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_rename_clicked ), NULL, this );
	check_force_update->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::force_update_checked ), NULL, this );
	purge_instance_contents->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::purge_files_checked ), NULL, this );
	client_instance_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_instance_selected ), NULL, this );
	client_terminal_prompt->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::client_terminal_enter_press ), NULL, this );
	client_jarmod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_add_clicked ), NULL, this );
	client_jarmod_up_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_up_clicked ), NULL, this );
	client_jarmod_down_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_down_clicked ), NULL, this );
	client_jarmod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_jarmod_remove_clicked ), NULL, this );
	client_buildjar_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_buildjar_clicked ), NULL, this );
	client_jar_select->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::client_edit_jar_version_selected ), NULL, this );
	client_zipmod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_add_clicked ), NULL, this );
	client_zipmod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_remove_clicked ), NULL, this );
	client_zipmod_apply_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::client_zipmod_apply_clicked ), NULL, this );
	clientmod_jarmod_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_jarmod_selected ), NULL, this );
	clientmod_zipmod_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::client_zipmod_selected ), NULL, this );
	clientmod_filepicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIFrame::client_modfile_selected ), NULL, this );
	clientmod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_add_clicked ), NULL, this );
	clientmod_replace_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_replace_clicked ), NULL, this );
	clientmod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::clientmod_remove_clicked ), NULL, this );
	server_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( GUIFrame::server_page_changing ), NULL, this );
	server_instance_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_instance_selected ), NULL, this );
	server_launch_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_launch_clicked ), NULL, this );
	server_create_new_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_create_new_clicked ), NULL, this );
	server_delete_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_delete_clicked ), NULL, this );
	server_rename_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_rename_clicked ), NULL, this );
	server_terminal_prompt->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::server_terminal_enter_press ), NULL, this );
	server_jarmod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_add_clicked ), NULL, this );
	server_jarmod_up_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_up_clicked ), NULL, this );
	server_jarmod_down_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_down_clicked ), NULL, this );
	server_jarmod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_jarmod_remove_clicked ), NULL, this );
	server_buildjar_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_buildjar_clicked ), NULL, this );
	server_jar_select->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::server_edit_jar_version_selected ), NULL, this );
	server_zipmod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_add_clicked ), NULL, this );
	server_zipmod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_remove_clicked ), NULL, this );
	server_zipmod_apply_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::server_zipmod_apply_clicked ), NULL, this );
	servermod_filepicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIFrame::server_modfile_selected ), NULL, this );
	servermod_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_add_clicked ), NULL, this );
	servermod_replace_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_replace_clicked ), NULL, this );
	servermod_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::servermod_remove_clicked ), NULL, this );
	servermod_jarmod_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_jarmod_selected ), NULL, this );
	servermod_zipmod_list->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIFrame::server_zipmod_selected ), NULL, this );
	jars_add_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_add_clicked ), NULL, this );
	jars_replace_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_replace_clicked ), NULL, this );
	jars_remove_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::jars_remove_clicked ), NULL, this );
	apply_settings_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::Apply_Settings ), NULL, this );
	
}

#include "GUIFrame_events.cpp"
