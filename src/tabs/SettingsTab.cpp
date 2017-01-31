/*
 * SettingsTab.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */

#include "SettingsTab.h"

SettingsTab::SettingsTab(ParentApp* p) {
	// TODO Auto-generated constructor stub
	this->parent_app=p;
}

SettingsTab::~SettingsTab() {
	// TODO Auto-generated destructor stub
}

bool SettingsTab::LoadSettings(bool loadtab)
{
    wxArrayString settings;
    settings.Add(wxT("selected_tab"));
    settings.Add(wxT("client-min-ram-checked"));
    settings.Add(wxT("client-max-ram-checked"));
    settings.Add(wxT("server-min-ram-checked"));
    settings.Add(wxT("server-max-ram-checked"));

    settings.Add(wxT("client-min-memunit"));
    settings.Add(wxT("client-max-memunit"));
    settings.Add(wxT("server-min-memunit"));
    settings.Add(wxT("server-max-memunit"));

    settings.Add(wxT("client-min-ram"));
    settings.Add(wxT("client-max-ram"));
    settings.Add(wxT("server-min-ram"));
    settings.Add(wxT("server-max-ram"));

    settings.Add(wxT("client-window-size-checked"));
    settings.Add(wxT("client-window-width"));
    settings.Add(wxT("client-window-height"));
    settings.Add(wxT("client-fullscreen-checked"));
    settings.Add(wxT("client-maximize-checked"));

    settings.Add(wxT("java-path"));
    settings.Add(wxT("instance-dir"));
    settings.Add(wxT("client-freshjar-dir"));
    settings.Add(wxT("server-freshjar-dir"));
    settings.Add(wxT("java-usepath"));
    settings.Add(wxT("java-isJDK"));
    settings.Add(wxT("client-freshjar-behave"));
    settings.Add(wxT("server-freshjar-behave"));
    settings.Add(wxT("instance-behave"));

    if(wxFileExists(wxT("MinecraftModMan.conf")))
    {
    	wxString exepath;
    	wxStandardPaths& stdpaths=wxStandardPaths::Get();
    	exepath=stdpaths.GetExecutablePath();
    	wxFileName path=wxFileName::FileName(exepath);
    	path.SetFullName(wxT("MinecraftModMan.conf"));
        wxFFile conf(path.GetFullPath(),wxT("r"));
        wxString str;
        conf.ReadAll (&str);
        long v;
        wxStringTokenizer tknzr(str,wxT("\n"),wxTOKEN_STRTOK);
        while(tknzr.HasMoreTokens())
        {
            str=tknzr.GetNextToken();
            wxStringTokenizer* tk= new wxStringTokenizer(str,wxT("="),wxTOKEN_RET_EMPTY_ALL);
            if(tk->CountTokens()!=2)
            {
                wxLogWarning (wxT("could not parse line: \"%s\"\n"),str.c_str());
            }
            else
            {
                wxString label=tk->GetNextToken(),value=tk->GetNextToken();
                switch(settings.Index(label))
                {
                case 0:
                    value.ToLong(&v);
                    if(loadtab)
                    {
                        this->parent_app->gui->frame_notebook->SetSelection(v);
                    }
                    break;
                case 1:
                    value.ToLong(&v);
                    this->parent_app->gui->client_check_min_RAM->SetValue((bool)v);
                    break;
                case 2:
                    value.ToLong(&v);
                    this->parent_app->gui->client_check_max_RAM->SetValue((bool)v);
                    break;
                case 3:
                    value.ToLong(&v);
                    this->parent_app->gui->server_check_min_RAM->SetValue((bool)v);
                    break;
                case 4:
                    value.ToLong(&v);
                    this->parent_app->gui->server_check_max_RAM->SetValue((bool)v);
                    break;
                case 5:
                    value.ToLong(&v);
                    this->parent_app->gui->client_min_memunit->SetSelection(v);
                    break;
                case 6:
                    value.ToLong(&v);
                    this->parent_app->gui->client_max_memunit->SetSelection(v);
                    break;
                case 7:
                    value.ToLong(&v);
                    this->parent_app->gui->server_min_memunit->SetSelection(v);
                    break;
                case 8:
                    value.ToLong(&v);
                    this->parent_app->gui->server_max_memunit->SetSelection(v);
                    break;
                case 9:
                    this->parent_app->gui->client_min_RAM->Clear();
                    this->parent_app->gui->client_min_RAM->AppendText(value);
                    break;
                case 10:
                    this->parent_app->gui->client_max_RAM->Clear();
                    this->parent_app->gui->client_max_RAM->AppendText(value);
                    break;
                case 11:
                    this->parent_app->gui->server_min_RAM->Clear();
                    this->parent_app->gui->server_min_RAM->AppendText(value);
                    break;
                case 12:
                    this->parent_app->gui->server_max_RAM->Clear();
                    this->parent_app->gui->server_max_RAM->AppendText(value);
                    break;
                case 13:
                    value.ToLong(&v);
                    this->parent_app->gui->client_check_window_size->SetValue((bool)v);
                    break;
                case 14:
                    this->parent_app->gui->client_window_width->Clear();
                    this->parent_app->gui->client_window_width->AppendText(value);
                    break;
                case 15:
                    this->parent_app->gui->client_window_height->Clear();
                    this->parent_app->gui->client_window_height->AppendText(value);
                    break;
                case 16:
                    value.ToLong(&v);
                    this->parent_app->gui->client_check_fullscreen->SetValue((bool)v);
                    break;
                case 17:
                    value.ToLong(&v);
                    this->parent_app->gui->client_check_maximize->SetValue((bool)v);
                    break;
                case 18:
                    this->parent_app->gui->java_directory_picker->SetPath(value);
                    break;
                case 19:
                    this->parent_app->gui->instance_directory_picker->SetPath(value);
                    break;
                case 20:
                    this->parent_app->gui->client_freshjar_dirpicker->SetPath(value);
                    break;
                case 21:
                    this->parent_app->gui->server_freshjar_dirpicker->SetPath(value);
                    break;
                case 22:
                    value.ToLong(&v);
                    this->parent_app->gui->java_usepath_radiobox->SetSelection(v);
                    break;
                case 23:
                    value.ToLong(&v);
                    this->parent_app->gui->check_java_is_JDK->SetValue((bool)v);
                    break;
                case 24:
                    value.ToLong(&v);
                    this->parent_app->gui->client_freshjar_behavior_radiobox->SetSelection(v);
                    break;
                case 25:
                    value.ToLong(&v);
                    this->parent_app->gui->server_freshjar_behavior_radiobox->SetSelection(v);
                    break;
                case 26:
                    value.ToLong(&v);
                    this->parent_app->gui->instance_behavior_radiobox->SetSelection(v);
                    break;
                case wxNOT_FOUND:
                    wxLogWarning(wxT("Did not recognize label: %s"),label.c_str());
                    break;
                default:
                    wxLogWarning(wxT("Did not find label: %s in arraystring, index was %u"),label.c_str(),settings.Index(label));
                    break;
                }
                //wxLogMessage (wxT("label: %s, value: %s\n"),label.c_str(),value.c_str());
            }
            delete tk;
        }

        conf.Close();
        this->updateSettings();
        return true;
    }
    this->updateSettings();
    return false;
}

void SettingsTab::updateSettings()
{
    //set textbox for java path
    this->parent_app->gui->current_java_bin_path->Clear();
    this->parent_app->gui->current_java_bin_path->AppendText(this->getJavaPath().GetFullPath());

//check for jars
    //client
    wxFileName path;
    path=this->getFreshClientJarPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Selected Fresh Client jar location does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_client_jar_path->Clear();
    this->parent_app->gui->current_client_jar_path->AppendText(path.GetFullPath());

    //server
    path=this->getFreshServerJarPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Selected Fresh Client jar location does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_server_jar_path->Clear();
    this->parent_app->gui->current_server_jar_path->AppendText(path.GetFullPath());

    path=this->getInstancePath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Selected Instance directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_instance_path->Clear();
    this->parent_app->gui->current_instance_path->AppendText(path.GetFullPath());
    //check for mods

    //client
    path=this->getClientJarModsPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Client Jar Mods directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_client_jarmods_path->Clear();
    this->parent_app->gui->current_client_jarmods_path->AppendText(path.GetFullPath());

    path=this->getClientZipModsPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Client Folder Mods directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_client_zipmods_path->Clear();
    this->parent_app->gui->current_client_zipmods_path->AppendText(path.GetFullPath());

    //server
    path=this->getServerJarModsPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Server Jar Mods directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_server_jarmods_path->Clear();
    this->parent_app->gui->current_server_jarmods_path->AppendText(path.GetFullPath());

    path=this->getServerZipModsPath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Server Folder Mods directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_server_zipmods_path->Clear();
    this->parent_app->gui->current_server_zipmods_path->AppendText(path.GetFullPath());
    //check for instances, check instances
    //client
    path=this->getClientInstancePath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Client Instances directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_client_instance_path->Clear();
    this->parent_app->gui->current_client_instance_path->AppendText(path.GetLongPath());

    //server
    path=this->getServerInstancePath();
    if(! path.DirExists())
    {
        if(! path.Mkdir(0777,wxPATH_MKDIR_FULL))
        {
            wxLogWarning(wxT("Server Instances directory does not exist and could not be created!"));
        }
    }
    this->parent_app->gui->current_server_instance_path->Clear();
    this->parent_app->gui->current_server_instance_path->AppendText(path.GetFullPath());
}

bool SettingsTab::SaveSettings()
{
	wxString exepath;
	wxStandardPaths& stdpaths=wxStandardPaths::Get();
	exepath=stdpaths.GetExecutablePath();
	wxFileName path=wxFileName::FileName(exepath);
	path.SetFullName(wxT("MinecraftModMan.conf"));
    wxFFile conf(path.GetFullPath(),wxT("w+"));
    wxString str(wxT(""));
    str<<wxT("selected_tab=")<<(this->parent_app->gui->frame_notebook->GetSelection())<<wxT("\n");
    str<<wxT("client-min-ram-checked=")<<(this->parent_app->gui->client_check_min_RAM->GetValue())<<wxT("\n");
    str<<wxT("client-max-ram-checked=")<<(this->parent_app->gui->client_check_max_RAM->GetValue())<<wxT("\n");
    str<<wxT("server-min-ram-checked=")<<(this->parent_app->gui->server_check_min_RAM->GetValue())<<wxT("\n");
    str<<wxT("server-max-ram-checked=")<<(this->parent_app->gui->server_check_max_RAM->GetValue())<<wxT("\n");

    str<<wxT("client-min-memunit=")<<(this->parent_app->gui->client_min_memunit->GetCurrentSelection())<<wxT("\n");
    str<<wxT("client-max-memunit=")<<(this->parent_app->gui->client_max_memunit->GetCurrentSelection())<<wxT("\n");
    str<<wxT("server-min-memunit=")<<(this->parent_app->gui->server_min_memunit->GetCurrentSelection())<<wxT("\n");
    str<<wxT("server-max-memunit=")<<(this->parent_app->gui->server_max_memunit->GetCurrentSelection())<<wxT("\n");

    str<<wxT("client-min-ram=")<<(this->parent_app->gui->client_min_RAM->GetLineText(0))<<wxT("\n");
    str<<wxT("client-max-ram=")<<(this->parent_app->gui->client_max_RAM->GetLineText(0))<<wxT("\n");
    str<<wxT("server-min-ram=")<<(this->parent_app->gui->server_min_RAM->GetLineText(0))<<wxT("\n");
    str<<wxT("server-max-ram=")<<(this->parent_app->gui->server_max_RAM->GetLineText(0))<<wxT("\n");

    str<<wxT("client-window-size-checked=")<<(this->parent_app->gui->client_check_window_size->GetValue())<<wxT("\n");
    str<<wxT("client-window-width=")<<(this->parent_app->gui->client_window_width->GetLineText(0))<<wxT("\n");
    str<<wxT("client-window-height=")<<(this->parent_app->gui->client_window_height->GetLineText(0))<<wxT("\n");
    str<<wxT("client-fullscreen-checked=")<<(this->parent_app->gui->client_check_fullscreen->GetValue())<<wxT("\n");
    str<<wxT("client-maximize-checked=")<<(this->parent_app->gui->client_check_maximize->GetValue())<<wxT("\n");

    str<<wxT("java-path=")<<(this->parent_app->gui->java_directory_picker->GetPath())<<wxT("\n");
    str<<wxT("instance-dir=")<<(this->parent_app->gui->instance_directory_picker->GetPath())<<wxT("\n");
    str<<wxT("client-freshjar-dir=")<<(this->parent_app->gui->client_freshjar_dirpicker->GetPath())<<wxT("\n");
    str<<wxT("server-freshjar-dir=")<<(this->parent_app->gui->server_freshjar_dirpicker->GetPath())<<wxT("\n");
    str<<wxT("java-usepath=")<<(this->parent_app->gui->java_usepath_radiobox->GetSelection())<<wxT("\n");
    str<<wxT("java-isJDK=")<<(this->parent_app->gui->check_java_is_JDK->GetValue())<<wxT("\n");
    str<<wxT("client-freshjar-behave=")<<(this->parent_app->gui->client_freshjar_behavior_radiobox->GetSelection())<<wxT("\n");
    str<<wxT("server-freshjar-behave=")<<(this->parent_app->gui->server_freshjar_behavior_radiobox->GetSelection())<<wxT("\n");
    str<<wxT("instance-behave=")<<(this->parent_app->gui->instance_behavior_radiobox->GetSelection())<<wxT("\n");
    conf.Write(str);
    conf.Close();
    return true;
}

wxFileName SettingsTab::getJavaPath()
{
    wxFileName path;
    if(this->parent_app->gui->java_usepath_radiobox->GetSelection()!=1)
    {
        path=wxFileName::DirName(this->parent_app->gui->java_directory_picker->GetPath());
    }
    path.SetName(wxT("java"));
    return path;
}

wxFileName SettingsTab::getFreshClientJarPath()
{
    wxFileName path;
    if(this->parent_app->gui->client_freshjar_behavior_radiobox->GetSelection()!=0)
    {
        path=wxFileName::DirName(this->parent_app->gui->client_freshjar_dirpicker->GetPath());
    }
    else
    {
        path=wxFileName::FileName(wxTheApp->argv[0]);
        path=wxFileName::DirName(path.GetPath());
    }
    path.AppendDir(wxT("ClientJars"));
    path.MakeAbsolute();
    return path;
}
wxFileName SettingsTab::getFreshServerJarPath()
{
    wxFileName path;
    if(this->parent_app->gui->server_freshjar_behavior_radiobox->GetSelection()!=0)
    {
        path=wxFileName::DirName(this->parent_app->gui->server_freshjar_dirpicker->GetPath());
    }
    else
    {
        path=wxFileName::FileName(wxTheApp->argv[0]);
        path=wxFileName::DirName(path.GetPath());
    }
    path.AppendDir(wxT("ServerJars"));
    path.MakeAbsolute();
    return path;
}
wxFileName SettingsTab::getInstancePath()
{
    wxFileName path;
    if(this->parent_app->gui->instance_behavior_radiobox->GetSelection()!=0)
    {
        path=wxFileName::DirName(this->parent_app->gui->instance_directory_picker->GetPath());
    }
    else
    {
        path=wxFileName::FileName(wxTheApp->argv[0]);
        path=wxFileName::DirName(path.GetPath());
    }
    path.AppendDir(wxT("Instances"));
    path.MakeAbsolute();
    return path;
}

wxFileName SettingsTab::getClientInstancePath()
{
    wxFileName path=getInstancePath();
    path.AppendDir(wxT("Clients"));
    return path;
}

wxFileName SettingsTab::getServerInstancePath()
{
    wxFileName path=getInstancePath();
    path.AppendDir(wxT("Servers"));
    return path;
}

wxFileName SettingsTab::getModsPath()
{
    wxFileName path=getInstancePath();
    path.AppendDir(wxT("ModLib"));
    return path;
}

wxFileName SettingsTab::getClientModsPath()
{
    wxFileName path=getModsPath();
    path.AppendDir(wxT("ClientMods"));
    return path;
}

wxFileName SettingsTab::getServerModsPath()
{
    wxFileName path=getModsPath();
    path.AppendDir(wxT("ServerMods"));
    return path;
}

wxFileName SettingsTab::getClientJarModsPath()
{
    wxFileName path=getClientModsPath();
    path.AppendDir(wxT("JarMods"));
    return path;
}
wxFileName SettingsTab::getServerJarModsPath()
{
    wxFileName path=getServerModsPath();
    path.AppendDir(wxT("JarMods"));
    return path;
}
wxFileName SettingsTab::getClientZipModsPath()
{
    wxFileName path=getClientModsPath();
    path.AppendDir(wxT("DirMods"));
    return path;
}
wxFileName SettingsTab::getServerZipModsPath()
{
    wxFileName path=getServerModsPath();
    path.AppendDir(wxT("DirMods"));
    return path;
}
