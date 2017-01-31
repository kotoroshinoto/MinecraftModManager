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



#include "Minecraft_Mod_ManagerApp.h"
#include <wx/msgdlg.h>

#include "src/GUI/GUIFrame.h"

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
