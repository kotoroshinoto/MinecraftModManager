/***************************************************************
 * Name:      Minecraft_Mod_ManagerApp.cpp
 * Purpose:   Code for Application Class
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

#include "Minecraft_Mod_ManagerApp.h"
#include "Minecraft_Mod_ManagerMain.h"

IMPLEMENT_APP(Minecraft_Mod_ManagerApp);

bool Minecraft_Mod_ManagerApp::OnInit()
{
	//initialize libcurl for use
//	curl_global_init(CURL_GLOBAL_ALL);
    Minecraft_Mod_ManagerFrame* frame = new Minecraft_Mod_ManagerFrame(0L);
    frame->Show();
    
    return true;
}

int Minecraft_Mod_ManagerApp::OnExit()
{
	//clean up libcurl resources
//	curl_global_cleanup();
	return wxApp::OnExit();
}
