/***************************************************************
 * Name:      Minecraft_Mod_ManagerMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2012-07-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MINECRAFT_MOD_MANAGERMAIN_H
#define MINECRAFT_MOD_MANAGERMAIN_H
//STL imports
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif
//wx widgets imports
#include <wx/msgdlg.h>
//project imports
#include "Minecraft_Mod_ManagerApp.h"
#include "GUI/GUIFrame.h"

class Minecraft_Mod_ManagerFrame: public GUIFrame
{
    public:
        Minecraft_Mod_ManagerFrame(wxFrame *frame);
        ~Minecraft_Mod_ManagerFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // MINECRAFT_MOD_MANAGERMAIN_H
