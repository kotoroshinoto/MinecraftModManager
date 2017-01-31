///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/gbsizer.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/radiobut.h>
#include <wx/filepicker.h>
#include <wx/radiobox.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include "SupplementaryIncludes.h"
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
#include "GUIFrame_additional_setup.h"
		wxNotebook* frame_notebook;
		wxPanel* client_tab;
		wxNotebook* client_notebook;
		wxPanel* client_select_tab;
		wxButton* client_launch_button;
		wxButton* client_create_new_button;
		wxButton* client_delete_button;
		wxButton* rename_client_button;
		wxCheckBox* client_check_min_RAM;
		wxTextCtrl* client_min_RAM;
		wxChoice* client_max_memunit;
		wxCheckBox* client_check_max_RAM;
		wxTextCtrl* client_max_RAM;
		wxChoice* client_min_memunit;
		wxCheckBox* client_check_window_size;
		wxTextCtrl* client_window_width;
		wxStaticText* m_staticText1;
		wxTextCtrl* client_window_height;
		wxCheckBox* client_check_maximize;
		wxCheckBox* client_check_fullscreen;
		wxStaticText* username_label;
		wxTextCtrl* username_text;
		wxTextCtrl* password_text;
		wxStaticText* password_label;
		wxCheckBox* check_force_update;
		wxCheckBox* purge_instance_contents;
		wxStaticText* client_instances_label;
		wxListCtrl* client_instance_list;
		wxTextCtrl* client_instance_name_textctrl;
		wxStaticText* m_staticText40;
		wxTextCtrl* client_terminal_term;
		wxTextCtrl* client_terminal_prompt;
		wxPanel* client_edit_tab;
		wxStaticText* client_jarmod_label;
		wxStaticText* unused_jarmods_label;
		wxListCtrl* client_jarmod_installed;
		wxListCtrl* client_jarmod_editlist;
		wxStaticText* client_jarmod_installed_label;
		wxStaticText* client_jarmod_editlist_label;
		wxButton* client_jarmod_add_button;
		wxButton* client_jarmod_up_button;
		wxButton* client_jarmod_down_button;
		wxButton* client_jarmod_remove_button;
		wxButton* client_buildjar_button;
		wxChoice* client_jar_select;
		wxListCtrl* client_jarmod_unused;
		wxStaticText* client_zipmod_label;
		wxListCtrl* client_zipmod_installed;
		wxListCtrl* client_zipmod_editlist;
		wxStaticText* client_zipmod_installed_label;
		wxStaticText* client_zipmod_editlist_label;
		
		wxButton* client_zipmod_add_button;
		wxButton* client_zipmod_remove_button;
		wxButton* client_zipmod_apply_button;
		wxListCtrl* client_zipmod_unused;
		wxStaticText* unused_jarmods_label1;
		wxPanel* clientmod_tab;
		wxListCtrl* clientmod_jarmod_list;
		wxListCtrl* clientmod_zipmod_list;
		wxRadioButton* clientmod_jarmod_radio;
		wxRadioButton* clientmod_zipmod_radio;
		
		wxFilePickerCtrl* clientmod_filepicker;
		wxStaticText* client_mod_name_label;
		wxTextCtrl* client_mod_name_textctrl;
		wxButton* clientmod_add_button;
		wxButton* clientmod_replace_button;
		wxButton* clientmod_remove_button;
		wxStaticText* client_mod_version_label;
		wxChoice* client_mod_compatible_jar_version_choice;
		wxPanel* server_tab;
		wxNotebook* server_notebook;
		wxPanel* server_select_tab;
		wxListCtrl* server_instance_list;
		wxTextCtrl* server_instance_name_textctrl;
		wxStaticText* server_instance_name_label;
		wxButton* server_launch_button;
		wxButton* server_create_new_button;
		wxButton* server_delete_button;
		wxButton* server_rename_button;
		wxCheckBox* server_check_min_RAM;
		wxTextCtrl* server_min_RAM;
		wxChoice* server_max_memunit;
		wxCheckBox* server_check_max_RAM;
		wxTextCtrl* server_max_RAM;
		wxChoice* server_min_memunit;
		wxStaticText* server_instances_label;
		wxTextCtrl* server_terminal_term;
		wxTextCtrl* server_terminal_prompt;
		wxPanel* server_edit_tab;
		wxStaticText* server_jarmod_label;
		wxStaticText* server_unused_jarmod_label;
		wxListCtrl* server_jarmod_unused;
		wxStaticText* server_jarmod_installed_label;
		wxListCtrl* server_jarmod_installed;
		wxListCtrl* server_jarmod_editlist;
		wxStaticText* server_jarmod_editlist_label;
		wxButton* server_jarmod_add_button;
		wxButton* server_jarmod_up_button;
		wxButton* server_jarmod_down_button;
		wxButton* server_jarmod_remove_button;
		wxButton* server_buildjar_button;
		wxChoice* server_jar_select;
		wxStaticText* server_zipmod_label;
		wxStaticText* server_unused_zipmod_label;
		wxListCtrl* server_zipmod_unused;
		wxStaticText* server_zipmod_installed_label;
		wxStaticText* server_zipmod_editlist_label;
		wxListCtrl* server_zipmod_installed;
		wxListCtrl* server_zipmod_editlist;
		
		wxButton* server_zipmod_add_button;
		wxButton* server_zipmod_remove_button;
		wxButton* server_zipmod_apply_button;
		wxPanel* servermod_tab;
		wxRadioButton* servermod_jarmod_radio;
		wxRadioButton* servermod_zipmod_radio;
		
		wxFilePickerCtrl* servermod_filepicker;
		wxStaticText* server_mod_name_label;
		wxTextCtrl* server_mod_name_textctrl;
		wxButton* servermod_add_button;
		wxButton* servermod_replace_button;
		wxButton* servermod_remove_button;
		wxStaticText* server_mod_version_label;
		wxChoice* server_mod_compatible_jar_version_choice;
		wxListCtrl* servermod_jarmod_list;
		wxListCtrl* servermod_zipmod_list;
		wxPanel* jars_tab;
		wxListCtrl* jars_client_list;
		wxListCtrl* jars_server_list;
		
		wxRadioButton* jars_client_radio;
		wxRadioButton* jars_server_radio;
		wxFilePickerCtrl* jars_jar_filepicker;
		wxTextCtrl* jars_version_number;
		wxStaticText* jars_filepicker_label;
		wxStaticText* jars_version_label;
		wxButton* jars_add_button;
		wxButton* jars_replace_button;
		wxButton* jars_remove_button;
		wxPanel* option_tab;
		wxStaticText* javabin_dir_label;
		wxStaticText* instancedir_label;
		wxStaticText* option_clientjar_label;
		wxStaticText* option_serverjar_label;
		wxRadioBox* java_usepath_radiobox;
		wxCheckBox* check_java_is_JDK;
		wxDirPickerCtrl* server_freshjar_dirpicker;
		wxDirPickerCtrl* java_directory_picker;
		wxDirPickerCtrl* client_freshjar_dirpicker;
		wxDirPickerCtrl* instance_directory_picker;
		wxRadioBox* client_freshjar_behavior_radiobox;
		wxRadioBox* server_freshjar_behavior_radiobox;
		wxRadioBox* instance_behavior_radiobox;
		wxButton* apply_settings_button;
		wxStaticText* current_java_bin_path_label;
		wxTextCtrl* current_java_bin_path;
		wxStaticText* instance_path_label;
		wxTextCtrl* current_instance_path;
		wxStaticText* current_client_instance_path_label;
		wxTextCtrl* current_client_instance_path;
		wxStaticText* current_client_jar_path_label;
		wxTextCtrl* current_client_jar_path;
		wxStaticText* current_server_instance_path_label;
		wxTextCtrl* current_server_instance_path;
		wxStaticText* current_server_jar_path_label;
		wxTextCtrl* current_server_jar_path;
		wxStaticText* current_client_jarmods_path_label;
		wxTextCtrl* current_client_jarmods_path;
		wxStaticText* current_client_zipmods_path_label;
		wxTextCtrl* current_client_zipmods_path;
		wxStaticText* current_server_jarmods_path_label;
		wxTextCtrl* current_server_jarmods_path;
		wxStaticText* current_server_zipmods_path_label;
		wxTextCtrl* current_server_zipmods_path;
		wxScrolledWindow* howto_tab;
		wxPanel* about_tab;
		wxStatusBar* statusBar;
		
		// Virtual event handlers, overide them in your derived class
		void tab_changing( wxNotebookEvent& event );
		void client_page_changing( wxNotebookEvent& event );
		void client_launch_clicked( wxCommandEvent& event );
		void client_create_new_clicked( wxCommandEvent& event );
		void client_delete_clicked( wxCommandEvent& event );
		void client_rename_clicked( wxCommandEvent& event );
		void force_update_checked( wxCommandEvent& event );
		void purge_files_checked( wxCommandEvent& event );
		void client_instance_selected( wxListEvent& event );
		void client_terminal_enter_press( wxCommandEvent& event );
		void client_jarmod_add_clicked( wxCommandEvent& event );
		void client_jarmod_up_clicked( wxCommandEvent& event );
		void client_jarmod_down_clicked( wxCommandEvent& event );
		void client_jarmod_remove_clicked( wxCommandEvent& event );
		void client_buildjar_clicked( wxCommandEvent& event );
		void client_edit_jar_version_selected( wxCommandEvent& event );
		void client_zipmod_add_clicked( wxCommandEvent& event );
		void client_zipmod_remove_clicked( wxCommandEvent& event );
		void client_zipmod_apply_clicked( wxCommandEvent& event );
		void client_jarmod_selected( wxListEvent& event );
		void client_zipmod_selected( wxListEvent& event );
		void client_modfile_selected( wxFileDirPickerEvent& event );
		void clientmod_add_clicked( wxCommandEvent& event );
		void clientmod_replace_clicked( wxCommandEvent& event );
		void clientmod_remove_clicked( wxCommandEvent& event );
		void server_page_changing( wxNotebookEvent& event );
		void server_instance_selected( wxListEvent& event );
		void server_launch_clicked( wxCommandEvent& event );
		void server_create_new_clicked( wxCommandEvent& event );
		void server_delete_clicked( wxCommandEvent& event );
		void server_rename_clicked( wxCommandEvent& event );
		void server_terminal_enter_press( wxCommandEvent& event );
		void server_jarmod_add_clicked( wxCommandEvent& event );
		void server_jarmod_up_clicked( wxCommandEvent& event );
		void server_jarmod_down_clicked( wxCommandEvent& event );
		void server_jarmod_remove_clicked( wxCommandEvent& event );
		void server_buildjar_clicked( wxCommandEvent& event );
		void server_edit_jar_version_selected( wxCommandEvent& event );
		void server_zipmod_add_clicked( wxCommandEvent& event );
		void server_zipmod_remove_clicked( wxCommandEvent& event );
		void server_zipmod_apply_clicked( wxCommandEvent& event );
		void server_modfile_selected( wxFileDirPickerEvent& event );
		void servermod_add_clicked( wxCommandEvent& event );
		void servermod_replace_clicked( wxCommandEvent& event );
		void servermod_remove_clicked( wxCommandEvent& event );
		void server_jarmod_selected( wxListEvent& event );
		void server_zipmod_selected( wxListEvent& event );
		void jars_add_clicked( wxCommandEvent& event );
		void jars_replace_clicked( wxCommandEvent& event );
		void jars_remove_clicked( wxCommandEvent& event );
		void Apply_Settings( wxCommandEvent& event );
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Minecraft Mod Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 920,740 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

#endif //__GUIFrame__
