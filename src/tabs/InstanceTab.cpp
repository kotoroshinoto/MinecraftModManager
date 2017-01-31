/*
 * tabs.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */
#include "InstanceTab.h"
InstanceTab::InstanceTab(bool client,ParentApp* p)
{
	this->parent_app=p;
	this->isClient=client;
	if(this->isClient){	this->instancelist=this->parent_app->gui->client_instance_list;}
	else {this->instancelist=this->parent_app->gui->server_instance_list;}
	this->edit_tab=new EditTab(this);
	this->buttonsection=new InstanceButtonSection(this);
	if(buttonsection == NULL){throw new std::bad_alloc();}

	wxListItem name_list_item;
	name_list_item.SetId(0);
	name_list_item.SetText(wxT("Name"));
	name_list_item.SetWidth(325);

	wxListItem version_list_item;
	version_list_item.SetId(1);
	version_list_item.SetText(wxT("Version"));
	version_list_item.SetWidth(70);
	this->instancelist->InsertColumn(0,name_list_item);
}
InstanceTab::InstanceButtonSection::InstanceButtonSection(InstanceTab* p)
{
	if(p->isClient){
		this->check_maxRAM=p->parent_app->gui->client_check_max_RAM;
		this->check_minRAM=p->parent_app->gui->client_check_min_RAM;
		this->instanceName=p->parent_app->gui->client_instance_name_textctrl;
		this->maxRAM=p->parent_app->gui->client_max_RAM;
		this->minRAM=p->parent_app->gui->client_min_RAM;
		this->max_memunit=p->parent_app->gui->client_max_memunit;
		this->min_memunit=p->parent_app->gui->client_min_memunit;
	} else {
		this->check_maxRAM=p->parent_app->gui->server_check_max_RAM;
		this->check_minRAM=p->parent_app->gui->server_check_min_RAM;
		this->instanceName=p->parent_app->gui->server_instance_name_textctrl;
		this->maxRAM=p->parent_app->gui->server_max_RAM;
		this->minRAM=p->parent_app->gui->server_min_RAM;
		this->max_memunit=p->parent_app->gui->server_max_memunit;
		this->min_memunit=p->parent_app->gui->server_min_memunit;
	}
}
InstanceTab::~InstanceTab(){if(buttonsection != NULL){delete buttonsection;}}

//Instance tab stuff

bool InstanceTab::LoadInstances()
{
    bool retval=true;
    wxFileName path=(this->isClient ? this->parent_app->settings_tab->getClientInstancePath() :  this->parent_app->settings_tab->getServerInstancePath());
    path.SetFullName(wxT("instances.conf"));
    wxLogMessage(wxT("Trying to load ")+path.GetFullPath());
    if(path.FileExists())
    {
        if(! MinecraftUtils::Read1ColFile(path,this->instances))
        {
            wxLogMessage(path.GetFullPath() + wxT(" could not be read, will create a new one!"));
            retval=false;
        }
    }
    else
    {
        wxLogMessage(path.GetFullPath() + wxT(" not found, have to create a new one!"));
        retval=false;
    }
    return retval;
}

bool InstanceTab::SaveInstances()
{
    wxFileName path=(this->isClient ? this->parent_app->settings_tab->getClientInstancePath() :  this->parent_app->settings_tab->getServerInstancePath());
    path.SetFullName(wxT("instances.conf"));
    wxLogMessage(wxT("Trying to save ")+path.GetFullPath());
    return MinecraftUtils::Write1ColFile(path,this->instances);
}


bool InstanceTab::CreateInstance()
{
	//wxTextCtrl* text,wxArrayString& list,wxFileName& instpath
	wxFileName path=(this->isClient ? this->parent_app->settings_tab->getClientInstancePath() :  this->parent_app->settings_tab->getServerInstancePath());
	wxString name=this->buttonsection->instanceName->GetLineText(0);
    name=name.Trim();
    if(name.IsEmpty()||this->instances.Index(name)!=wxNOT_FOUND)
    {
        return false;    //no name specified or one with identical name is already in list
    }

    path.AppendDir(name);
    if(path.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL))
    {
    	this->instances.Add(name);
        return true;
    }
    return false;
}
bool InstanceTab::RenameInstance()
{
    long selected=this->instancelist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    if(selected==-1)
    {
        return false;
    }
    wxString name1=this->instancelist->GetItemText(selected);
    wxString name2=this->buttonsection->instanceName->GetLineText(0);
    name2=name2.Trim();
    wxFileName path1=(this->isClient ? this->parent_app->settings_tab->getClientInstancePath() :  this->parent_app->settings_tab->getServerInstancePath());
    wxFileName path2=path1;
    path1.AppendDir(name1);
    path2.AppendDir(name2);
    if(name1 == name2  || name2.IsEmpty() || this->instances.Index(name2)!=wxNOT_FOUND)//same name, empty, or clobber
    {
        return false;
    }
    if(! wxRenameFile(path1.GetFullPath(), path2.GetFullPath()))
    {
        return false;
    }
    this->instances.Remove(name1);//remove old name from clientlist
    this->instances.Add(name2);//add new name to listcontrol
    return true;
}
bool InstanceTab::DeleteInstance()
{
    long selected=this->instancelist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    if(selected==-1)
    {
        return false;
    }
    wxString name=this->instancelist->GetItemText(selected);
    wxFileName path=(this->isClient ? this->parent_app->settings_tab->getClientInstancePath() :  this->parent_app->settings_tab->getServerInstancePath());
    path.AppendDir(name);
    if(!path.DirExists())
    {
    	instances.Remove(name);
        return true;
    }
    if(!path.Rmdir(wxPATH_RMDIR_RECURSIVE))//remove from filesystem
    {
        return false;
    }
    instances.Remove(name);//remove from client list
    return true;

}

//EDIT TAB STUFF

InstanceTab::EditTab::EditTab(InstanceTab* p)
{
	parent_instance_tab=p;
	this->zipmods=new Sublist(false,this);
	this->jarmods=new Sublist(true,this);
	if(p->isClient){
		this->jars=this->parent_instance_tab->parent_app->gui->client_jar_select;
	} else {
		this->jars=this->parent_instance_tab->parent_app->gui->server_jar_select;
	}
}

wxString InstanceTab::GetSelectedInstanceName()
{
	return this->instancelist->GetItemText(this->instancelist->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED));
}

void InstanceTab::EditTab::Populate()
{
	InstanceTab *IT=this->parent_instance_tab;
	wxFileName instpath=(IT->isClient ? IT->parent_app->settings_tab->getClientInstancePath() :  IT->parent_app->settings_tab->getServerInstancePath());
	instpath.AppendDir(IT->GetSelectedInstanceName());
    wxFileName usesjar=instpath;
    //check for jar version
    this->jars->Clear();
    if(this->parent_instance_tab->isClient){
    	this->jars->Append(this->parent_instance_tab->parent_app->jar_tab->clientjars);
    } else {
    	this->jars->Append(this->parent_instance_tab->parent_app->jar_tab->serverjars);
    }
    usesjar.SetFullName(wxT("usesjar.conf"));
    wxString jarversion;
    wxArrayString jarversionlines;
    //try to read jar version from conf file
    if(usesjar.FileExists())
    {
        MinecraftUtils::Read1ColFile(usesjar,jarversionlines);
        jarversion=jarversionlines[0];
    }
    //if the jar version is set, set selected jar version
    std::wcout<<"test1"<<std::endl;
    if(!jarversion.IsEmpty())
    {
    	std::wcout<<"test2"<<std::endl;
        int i=this->jars->FindString(jarversion);
        if(i>=0)
        {
        	this->jars->SetSelection(i);
        }
    }
    std::wcout<<"test3"<<std::endl;
}

void InstanceTab::EditTab::Sublist::Populate()
{
	InstanceTab *IT=this->parent_edit_tab->parent_instance_tab;
	wxFileName instpath=(IT->isClient ? IT->parent_app->settings_tab->getClientInstancePath() :  IT->parent_app->settings_tab->getServerInstancePath());
	instpath.AppendDir(IT->GetSelectedInstanceName());
	wxFileName confpath=instpath;
	std::vector<wxArrayString>* mods;
	if(this->parent_edit_tab->parent_instance_tab->isClient){
		if(this->arejarmods){
			mods=&(this->parent_edit_tab->parent_instance_tab->parent_app->client_mod_tab->jarmods);
		} else {
			mods=&(this->parent_edit_tab->parent_instance_tab->parent_app->client_mod_tab->zipmods);
		}
	} else {
		if(this->arejarmods){
			mods=&(this->parent_edit_tab->parent_instance_tab->parent_app->server_mod_tab->jarmods);
		} else {
			mods=&(this->parent_edit_tab->parent_instance_tab->parent_app->server_mod_tab->zipmods);
		}
	}
	if(this->arejarmods){
		confpath.SetFullName(wxT("jarmods.conf"));
	}else{
    	confpath.SetFullName(wxT("zipmods.conf"));
    }
    bool found;
    this->curr.clear();
    this->edit.clear();
    this->unused.clear();
    if(confpath.FileExists())
    {
        //wxLogMessage("Loading Config File: "+confpath.GetFullPath());
        MinecraftUtils::ReadNColFile(confpath, this->curr,3);
        for(size_t i=0; i< this->curr.size(); ++i)
        {
            found=false;
            for(size_t j=0; j < mods->size() && !found; ++j)
            {
                if((*mods)[j][0]==this->curr[i][0] && (*mods)[j][1]==this->curr[i][1])
                {
                    found=true;
                }
            }
            if(found)
            {
                //only add known mods to edit list

                this->edit.push_back(this->curr[i]);
            }
        }
        //edit list starts out same as installed
    }
    //existing install list & edit list taken care of
    for(size_t i=0; i< mods->size(); ++i)
    {
        found=false;
        for(size_t j=0; j < this->edit.size() && !found; ++j)
        {
            if((*mods)[i][0]==this->edit[j][0] && (*mods)[i][1]==this->edit[j][1])
            {
                found=true;
            }
        }
        if(!found)
        {
            this->unused.push_back((*mods)[i]);//only known mods that are not in edit list should be in unused list
        }
    }
}

void InstanceTab::EditTab::Update()
{
	this->jarmods->Update();
	this->zipmods->Update();
}

InstanceTab::EditTab::Sublist::Sublist(bool rjars,EditTab* p)
{
	arejarmods=rjars;
	this->parent_edit_tab=p;
	if(p->parent_instance_tab->isClient)
	{
		if(rjars)
		{
			//Client JARS
			this->curr_list=p->parent_instance_tab->parent_app->gui->client_jarmod_installed;
			this->edit_list=p->parent_instance_tab->parent_app->gui->client_jarmod_editlist;
			this->unused_list=p->parent_instance_tab->parent_app->gui->client_jarmod_unused;

		} else {
			//Client ZIPMODS
			this->curr_list=p->parent_instance_tab->parent_app->gui->client_zipmod_installed;
			this->edit_list=p->parent_instance_tab->parent_app->gui->client_zipmod_editlist;
			this->unused_list=p->parent_instance_tab->parent_app->gui->client_zipmod_unused;
		}
	} else {
		if(rjars)
		{
			//server JARS
			this->curr_list=p->parent_instance_tab->parent_app->gui->server_jarmod_installed;
			this->edit_list=p->parent_instance_tab->parent_app->gui->server_jarmod_editlist;
			this->unused_list=p->parent_instance_tab->parent_app->gui->server_jarmod_unused;

		} else {
			//server ZIPMODS
			this->curr_list=p->parent_instance_tab->parent_app->gui->server_zipmod_installed;
			this->edit_list=p->parent_instance_tab->parent_app->gui->server_zipmod_editlist;
			this->unused_list=p->parent_instance_tab->parent_app->gui->server_zipmod_unused;
		}
	}
	wxListItem name_list_item;
	name_list_item.SetId(0);
	name_list_item.SetText(wxT("Name"));
	name_list_item.SetWidth(130);

	wxListItem version_list_item;
	version_list_item.SetId(1);
	version_list_item.SetText(wxT("Version"));
	version_list_item.SetWidth(70);

	this->curr_list->InsertColumn(0, name_list_item);
		this->curr_list->InsertColumn(1, version_list_item);
		this->edit_list->InsertColumn(0, name_list_item);
		this->edit_list->InsertColumn(1, version_list_item);
		this->unused_list->InsertColumn(0, name_list_item);
		this->unused_list->InsertColumn(1, version_list_item);
}

void InstanceTab::EditTab::Sublist::Add()
{
    wxListItem row_info;
    wxString name,version;
    long selected=this->unused_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    if(selected==-1)
    {
        return;
    }
    row_info.m_itemId=selected;
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->unused_list->GetItem(row_info);
    name=row_info.m_text;

    row_info.m_itemId=selected;
    row_info.m_col=1;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->unused_list->GetItem(row_info);
    version=row_info.m_text;
    for(size_t i=0; i<this->unused.size(); ++i)
    {
        if(this->unused[i][0]==name && this->unused[i][1]==version)
        {
            this->edit.push_back(this->unused[i]);
            this->unused.erase(this->unused.begin()+i);
            this->Update();
            return;
        }
    }
}
void InstanceTab::EditTab::Sublist::Remove()
{
    wxListItem row_info;
    wxString name,version;
    long selected=this->edit_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    row_info.m_itemId=selected;
    if(selected==-1)
    {
        return;
    }
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    name=row_info.m_text;

    row_info.m_itemId=selected;
    row_info.m_col=1;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    version=row_info.m_text;
    for(size_t i=0; i<this->edit.size(); ++i)
    {
        if(this->edit[i][0]==name && this->edit[i][1]==version)
        {
            this->unused.push_back(this->edit[i]);
            this->edit.erase(this->edit.begin()+i);
            this->Update();
            return;
        }
    }
}
void InstanceTab::EditTab::Sublist::Up()
{
    if(this->edit.size()<2)
    {
        return;
    }
    wxListItem row_info;
    wxString name,version;
    long selected=this->edit_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    row_info.m_itemId=selected;
    if(selected==-1)
    {
        return;
    }
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    name=row_info.m_text;

    row_info.m_itemId=selected;
    row_info.m_col=1;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    version=row_info.m_text;
    for(size_t i=0; i<this->edit.size(); ++i)
    {
        if(this->edit[i][0]==name && this->edit[i][1]==version)
        {
            if(i==0)
            {
                return;
            }
            this->edit.insert(this->edit.begin()+i-1,this->edit[i]);
            this->edit.erase(this->edit.begin()+i+1);
            this->Update();
            return;
        }
    }
}
void InstanceTab::EditTab::Sublist::Down()
{
    if(this->edit.size()<2)
    {
        return;
    }
    wxListItem row_info;
    wxString name,version;
    long selected=this->edit_list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    row_info.m_itemId=selected;
    if(selected==-1)
    {
        return;
    }
    row_info.m_col=0;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    name=row_info.m_text;

    row_info.m_itemId=selected;
    row_info.m_col=1;
    row_info.m_mask= wxLIST_MASK_TEXT;
    this->edit_list->GetItem(row_info);
    version=row_info.m_text;
    for(size_t i=0; i<this->edit.size(); ++i)
    {
        if(this->edit[i][0]==name && this->edit[i][1]==version)
        {
            if(i==this->edit.size()-1)
            {
                return;
            }
            this->edit.insert(this->edit.begin()+i+2,this->edit[i]);
            this->edit.erase(this->edit.begin()+i);
            this->Update();
            return;
        }
    }
}

wxString InstanceTab::EditTab::GetSelectedVersion()
{
	wxString version=this->jars->GetString(this->jars->GetSelection());
	wxLogMessage(wxT("Current Selected Jar Version is: ")+version);
	return version;
}

void InstanceTab::EditTab::RebuildJar()
{
    wxFileName sourcejar,destjar=currentEditedInstance,modpath;
    std::vector<wxFileName> modfiles;//original jar is modfiles[0]
    std::vector<wxArrayString> allEntries;//each list of entries refers back to a modfile
    std::auto_ptr<wxZipInputStream> zipin;
    std::auto_ptr<wxZipEntry> entry;
    wxString jarversion,jarname;
    std::vector<wxArrayString>& modlist=(this->jarmods->edit);
    //wxFFileInputStream* istr;
    //wxFFileOutputStream* ostr;
    //generate filenames for input jar and output jar
    if(! this->parent_instance_tab->isClient)
    {
    	jarversion=this->GetSelectedVersion();
        if(jarversion.Length() == 0)
        {
        	//TODO error message
            return;
        }
        sourcejar=this->parent_instance_tab->parent_app->settings_tab->getFreshServerJarPath();
        modpath=this->parent_instance_tab->parent_app->settings_tab->getServerJarModsPath();
        jarname=wxT("minecraft_server.jar");
    }
    else
    {
    	jarversion=this->GetSelectedVersion();
        if(jarversion.Length() == 0)
        {
        	//TODO error message
            return;
        }
        sourcejar=this->parent_instance_tab->parent_app->settings_tab->getFreshClientJarPath();
        modpath=this->parent_instance_tab->parent_app->settings_tab->getClientJarModsPath();
        destjar.AppendDir(wxT(".minecraft"));
        destjar.AppendDir(wxT("bin"));
        jarname=wxT("minecraft.jar");
    }
    sourcejar.AppendDir(jarversion);
    sourcejar.SetFullName(jarname);
    destjar.SetFullName(jarname);
    modfiles.push_back(sourcejar);
    //generate fullpath filenames for mods
    for(size_t i=0; i<modlist.size(); ++i)
    {
        wxFileName fn=modpath;
        fn.SetFullName(modlist[i][0]+wxT("_")+modlist[i][1]+wxT(".")+modlist[i][2]);
        modfiles.push_back(fn);
    }
    wxLogMessage(wxT("Attempting to generate modded jar"));
    wxLogMessage(wxT("Destination Jar:")+destjar.GetFullPath());
    wxLogMessage(wxT("Source files:"));
    for(size_t i=0; i<modfiles.size(); ++i)
    {
        wxLogMessage(modfiles[i].GetFullPath());
    }
    if(!destjar.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL ))
    {
        wxLogWarning(destjar.GetFullPath()+wxT(" did not exist and could not create it!"));
        return;
    }
    wxFFileOutputStream out(destjar.GetFullPath());
    wxZipOutputStream zipout(out);
    std::auto_ptr<wxFFileInputStream> in;
    //Need to scan input files to get a listing of which wxZipEntries will be used from which files to create the final output
    wxArrayString arr;
    for(size_t i=0; i<modfiles.size(); ++i)
    {
        arr.Clear();
        in.reset(new wxFFileInputStream(modfiles[i].GetFullPath()));
        zipin.reset(new wxZipInputStream(*in));
        if(i==0)
        {
            zipout.CopyArchiveMetaData(*zipin);
        }
        wxLogMessage(modfiles[i].GetFullPath());
        while(entry.reset(zipin->GetNextEntry()), entry.get() != NULL)
        {
            //arr.Add(entry->GetName());
            if(! entry->GetName().StartsWith(wxT("META-INF")) || ! this->parent_instance_tab->isClient )
            {
                zipout.CopyEntry(entry.release(),*zipin);
            }
        }
        allEntries.push_back(arr);
    }
    bool success = zipin->Eof() && zipout.Close();
    this->jarmods->ApplySave();
    this->jarmods->Update();
}
void InstanceTab::EditTab::ApplyZipMods()
{
    wxArrayString Old;
    wxArrayString New;
    wxFileName modloc;
    std::vector<wxArrayString> &oldmodlist=this->zipmods->curr,&newmodlist=this->zipmods->edit;
    for(size_t i=0; i<oldmodlist.size(); ++i)
    {
        Old.Add(oldmodlist[i][0]+wxT("_")+oldmodlist[i][1]+wxT(".")+oldmodlist[i][2]);
    }
    for(size_t i=0; i<newmodlist.size(); ++i)
    {
        New.Add(newmodlist[i][0]+wxT("_")+newmodlist[i][1]+wxT(".")+newmodlist[i][2]);
    }
    wxArrayString needthese=New;//needthese == New - already existing
    wxArrayString rmthese=Old;
    for(size_t i=0; i<Old.Count(); ++i)
    {
        needthese.Remove(Old[i]);
    }
    for(size_t i=0; i<New.Count(); ++i) //rmthese == Old - New == leftovers
    {
        rmthese.Remove(New[i]);
    }
    wxFileName moddir=currentEditedInstance;
    moddir.AppendDir(wxT("mods"));
    moddir.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL );
    //remove any existing mods that are in current list but not edit list
    //copy in mods that are on edit list but not current list
    if(!this->parent_instance_tab->isClient)
    {
        modloc=this->parent_instance_tab->parent_app->settings_tab->getServerZipModsPath();
    }
    else
    {
        modloc=this->parent_instance_tab->parent_app->settings_tab->getClientZipModsPath();
    }
    for(size_t i=0; i<needthese.Count(); ++i)
    {
        wxFileName src=modloc;
        wxFileName dest=moddir;
        dest.SetFullName(needthese[i]);
        src.SetFullName(needthese[i]);
        wxCopyFile(src.GetFullPath(),dest.GetFullPath());
    }

    for(size_t i=0; i<rmthese.Count(); ++i)
    {
        wxRemoveFile(rmthese[i]);
    }
    this->zipmods->ApplySave();
    this->zipmods->Update();
}

void InstanceTab::EditTab::Sublist::Update()
{
    MinecraftUtils::UpdateList(this->curr_list,this->curr);
    MinecraftUtils::UpdateList(this->edit_list,this->edit);
    MinecraftUtils::UpdateList(this->unused_list,this->unused);
}

void InstanceTab::EditTab::Sublist::ApplySave()
{
	wxFileName savepath=this->parent_edit_tab->currentEditedInstance;
	if(this->arejarmods)
	{
		savepath.SetFullName(wxT("jarmods.conf"));
	} else {
		savepath.SetFullName(wxT("zipmods.conf"));
	}
	this->curr.clear();
	this->curr=this->edit;
	MinecraftUtils::WriteNColFile(savepath,this->curr,3);
	wxFileName usesjar=this->parent_edit_tab->currentEditedInstance;
	usesjar.SetFullName(wxT("usesjar.conf"));
	wxTextFile ver(usesjar.GetFullPath());
	if(ver.Exists())
	{
		if(ver.Open()){
			wxLogMessage(usesjar.GetFullPath()+wxT(" was opened"));
		} else {
			wxLogError(usesjar.GetFullPath()+wxT(" exists but could not be opened"));
		}
	}
	else
	{
		if(ver.Create()){
			wxLogMessage(usesjar.GetFullPath()+wxT(" was created"));
			if(ver.Open()){
				wxLogMessage(usesjar.GetFullPath()+wxT(" was opened"));
			} else {
				wxLogError(usesjar.GetFullPath()+wxT(" exists but could not be opened"));
			}
		} else {
			wxLogError(usesjar.GetFullPath()+wxT(" did not exist and could not be created"));
		}
	}
	if(ver.IsOpened())
	{
		wxString version=this->parent_edit_tab->GetSelectedVersion();
		wxLogMessage(wxT("Jar Version Applied: ") + version);
		ver.Clear();
		ver.AddLine(version);
		if(ver.Write()){
			wxLogMessage(wxT("Changes in ") + usesjar.GetFullPath()+wxT(" written to disk"));
		} else {
			wxLogError(wxT("Changes in ") + usesjar.GetFullPath()+wxT(" could not be written to disk"));
		}
		ver.Close();
	}
	this->Update();
}

void  InstanceTab::UpdateInstances()
{
	MinecraftUtils::UpdateList(this->instancelist,this->instances);
}
