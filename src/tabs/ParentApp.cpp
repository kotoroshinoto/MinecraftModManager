/*
 * ParentApp.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */
#include "ParentApp.h"

ParentApp::ParentApp(GUIFrame* const app)
{
	this->gui=app;
	//initialize what can be initialized directly from GUIFrame
	this->client_mod_tab=new ModTab(true,this);
	this->client_tab=new ClientInstanceTab(this);
	this->jar_tab=new JarTab(this);
	this->server_mod_tab=new ModTab(false,this);
	this->server_tab=new ServerInstanceTab(this);
	this->settings_tab=new SettingsTab(this);
	//link any remaining pointers.
	this->logwindow=new wxLogWindow(this->gui,wxT("Minecraft Mod Manager Log Window"),true,false);
	//load data
	this->jar_tab->Load();
	this->client_mod_tab->Load();
	this->server_mod_tab->Load();
	this->client_tab->instance_tab->LoadInstances();
	this->server_tab->instance_tab->LoadInstances();
	//update GUI elements
	this->jar_tab->Update();
	this->client_mod_tab->Update();
	this->server_mod_tab->Update();
	this->client_tab->instance_tab->UpdateInstances();
	this->server_tab->instance_tab->UpdateInstances();
	this->settings_tab->SaveSettings();
	this->settings_tab->LoadSettings();
}
ParentApp::~ParentApp(){
	delete this->client_mod_tab;
	delete this->client_tab;
	delete this->jar_tab;
	delete this->server_mod_tab;
	delete this->server_tab;
	delete this->settings_tab;
}
