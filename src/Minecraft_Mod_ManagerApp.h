/***************************************************************
 * Name:      Minecraft_Mod_ManagerApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2012-07-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MINECRAFT_MOD_MANAGERAPP_H
#define MINECRAFT_MOD_MANAGERAPP_H
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <wx/app.h>

//*
class Minecraft_Mod_ManagerApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
};

DECLARE_APP(Minecraft_Mod_ManagerApp);
//*/

#endif // MINECRAFT_MOD_MANAGERAPP_H
