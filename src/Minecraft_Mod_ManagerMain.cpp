/***************************************************************
 * Name:      Minecraft_Mod_ManagerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2012-07-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Minecraft_Mod_ManagerMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


Minecraft_Mod_ManagerFrame::Minecraft_Mod_ManagerFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

Minecraft_Mod_ManagerFrame::~Minecraft_Mod_ManagerFrame()
{
}

void Minecraft_Mod_ManagerFrame::OnClose(wxCloseEvent &event)
{
	this->parent_app->settings_tab->SaveSettings();
	this->parent_app->jar_tab->Save();
	this->parent_app->client_mod_tab->Save();
	this->parent_app->server_mod_tab->Save();
	this->parent_app->client_tab->instance_tab->SaveInstances();
	this->parent_app->server_tab->instance_tab->SaveInstances();
    Destroy();
}

void Minecraft_Mod_ManagerFrame::OnQuit(wxCommandEvent &event)
{
	this->parent_app->settings_tab->SaveSettings();
	this->parent_app->jar_tab->Save();
	this->parent_app->client_mod_tab->Save();
	this->parent_app->server_mod_tab->Save();
	this->parent_app->client_tab->instance_tab->SaveInstances();
	this->parent_app->server_tab->instance_tab->SaveInstances();
    Destroy();
}

void Minecraft_Mod_ManagerFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
