#include "stdafx.h"
#include "ConfigFile.h"
#include "InstallerLog.h"
#include "DniMessageBox.h"
#include "dotNetInstallerDlg.h"
#include "ProcessorIdentifier.h"
#include "MsiComponent.h"
#include "CmdComponent.h"
#include "OpenFileComponent.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckOperator.h"
#include "InstallerCommandLineInfo.h"
#include "DownloadDialog.h"
#include "Image.h"

ConfigFile::ConfigFile()
    : m_lcidtype(LcidUserExe)
{

}

int ConfigFile::Load()
{
    LoadXmlSettings();
	return LoadConfigsNode(m_XmlDocument.FirstChildElement(), false);
}

void ConfigFile::LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DownloadGroupConfiguration & p_Configuration)
{
	p_Configuration.Caption = p_Node_downloaddialog->AttributeT("dialog_caption").data();
	p_Configuration.HelpMessage = p_Node_downloaddialog->AttributeT("dialog_message").data();
	p_Configuration.HelpMessageDownloading = p_Node_downloaddialog->AttributeT("dialog_message_downloading").data();
	p_Configuration.ButtonStartCaption = p_Node_downloaddialog->AttributeT("buttonstart_caption").data();
	p_Configuration.ButtonCancelCaption = p_Node_downloaddialog->AttributeT("buttoncancel_caption").data();
	p_Configuration.AutoStartDownload = ConvBoolString(p_Node_downloaddialog->Attribute("autostartdownload"), false);

	p_Configuration.Components.RemoveAll();

	TiXmlNode * child = NULL;
	while ( (child = p_Node_downloaddialog->IterateChildren("download", child)) != NULL)
	{
		TiXmlElement * l_Node_download = child->ToElement();
		if (l_Node_download != NULL)
		{
			ApplicationLog.Write( TEXT("--Reading Download component"));

			DownloadComponentInfo l_DownloadComp;
			l_DownloadComp.ComponentName = l_Node_download->AttributeT("componentname").data();
			l_DownloadComp.SourceURL = m_Setting.ValidatePath(l_Node_download->AttributeT("sourceurl").data());
			l_DownloadComp.SourcePath = m_Setting.ValidatePath(l_Node_download->AttributeT("sourcepath").data());
			l_DownloadComp.DestinationPath = m_Setting.ValidatePath(l_Node_download->AttributeT("destinationpath").data());
			l_DownloadComp.DestinationFileName = m_Setting.ValidatePath(l_Node_download->AttributeT("destinationfilename").data());
			l_DownloadComp.AlwaysDownload = ConvBoolString(l_Node_download->Attribute("alwaysdownload"), true);
			p_Configuration.Components.Add(l_DownloadComp);

			ApplicationLog.Write( TEXT("--Finished reading download component: "), l_DownloadComp.SourceURL );
		}
	}

	if (p_Configuration.Components.GetCount() <= 0)
	{
        CString error;
        error.Format(TEXT("Invalid configuration. Download dialog \"%s\" requires at least one download file."),
			p_Configuration.Caption);
		throw std::exception(DVLib::Tstring2string(error).c_str());
	}
}

// Populate the m_Setting object
void ConfigFile::LoadInstallConfigNode(TiXmlElement * p_Node)
{
	DVLib::OperatingSystem l_CurrentOs = DVLib::GetOsVersion();

	ApplicationLog.Write( TEXT("Reading configuration attributes") );

    // auto-enabled log options
    m_Setting.log_enabled = ConvBoolString(p_Node->Attribute("log_enabled"), false);
    m_Setting.log_file = p_Node->AttributeT("log_file").data();

    // enable logging if log is not enabled by a command line switch and enabled in the configuration
    if (! ApplicationLog.IsEnableLog() && m_Setting.log_enabled)
    {
        ApplicationLog.SetLogFile(m_Setting.ValidatePath(m_Setting.log_file));
        ApplicationLog.EnableLog();
    }

    // defines where to extract files and auto-delete options
    m_Setting.cab_path = p_Node->AttributeT("cab_path").data();
    m_Setting.cab_path_autodelete = ConvBoolString(p_Node->Attribute("cab_path_autodelete"), true);
    // positions within the dialog
    m_Setting.dialog_position.FromString(p_Node->AttributeT("dialog_position"));
    m_Setting.dialog_components_list_position.FromString(p_Node->AttributeT("dialog_components_list_position"));
    m_Setting.dialog_message_position.FromString(p_Node->AttributeT("dialog_message_position"));
    m_Setting.dialog_bitmap_position.FromString(p_Node->AttributeT("dialog_bitmap_position"));
    m_Setting.dialog_otherinfo_link_position.FromString(p_Node->AttributeT("dialog_otherinfo_link_position"));
    m_Setting.dialog_osinfo_position.FromString(p_Node->AttributeT("dialog_osinfo_position"));
    m_Setting.dialog_install_button_position.FromString(p_Node->AttributeT("dialog_install_button_position"));
    m_Setting.dialog_cancel_button_position.FromString(p_Node->AttributeT("dialog_cancel_button_position"));
    m_Setting.dialog_skip_button_position.FromString(p_Node->AttributeT("dialog_skip_button_position"));
    // other dialog options
	m_Setting.cancel_caption = p_Node->AttributeT("cancel_caption").data();
	m_Setting.dialog_bitmap = m_Setting.ValidatePath(p_Node->AttributeT("dialog_bitmap").data());
	m_Setting.dialog_caption = p_Node->AttributeT("dialog_caption").data();
	m_Setting.dialog_message = p_Node->AttributeT("dialog_message").data();
	m_Setting.skip_caption = p_Node->AttributeT("skip_caption").data();
	m_Setting.install_caption = p_Node->AttributeT("install_caption").data();
	m_Setting.status_installed = p_Node->AttributeT("status_installed").data();
	m_Setting.status_notinstalled = p_Node->AttributeT("status_notinstalled").data();
	m_Setting.failed_exec_command_continue = p_Node->AttributeT("failed_exec_command_continue").data();
	m_Setting.installation_completed = p_Node->AttributeT("installation_completed").data();
	m_Setting.installation_none = p_Node->AttributeT("installation_none").data();
	m_Setting.reboot_required = p_Node->AttributeT("reboot_required").data();
    m_Setting.must_reboot_required = ConvBoolString(p_Node->Attribute("must_reboot_required"), false);
	m_Setting.installing_component_wait = p_Node->AttributeT("installing_component_wait").data();

	m_Setting.dialog_otherinfo_caption = p_Node->AttributeT("dialog_otherinfo_caption").data();
	m_Setting.dialog_otherinfo_link = m_Setting.ValidatePath(p_Node->AttributeT("dialog_otherinfo_link").data());

	m_Setting.complete_command = m_Setting.ValidatePath(p_Node->AttributeT("complete_command").data());
	m_Setting.complete_command_silent = m_Setting.ValidatePath(p_Node->AttributeT("complete_command_silent").data());
	m_Setting.auto_close_if_installed = ConvBoolString(p_Node->Attribute("auto_close_if_installed"), true);
    m_Setting.auto_close_on_error = ConvBoolString(p_Node->Attribute("auto_close_on_error"), false);
    m_Setting.allow_continue_on_error = ConvBoolString(p_Node->Attribute("allow_continue_on_error"), true);
    m_Setting.dialog_show_installed = ConvBoolString(p_Node->Attribute("dialog_show_installed"), true);
    m_Setting.dialog_show_required = ConvBoolString(p_Node->Attribute("dialog_show_required"), true);

	m_Setting.os_filter_greater = p_Node->AttributeT("os_filter_greater").data();
	m_Setting.os_filter_smaller = p_Node->AttributeT("os_filter_smaller").data();
	
	m_Setting.processor_architecture_filter = p_Node->AttributeT("processor_architecture_filter").data();

    // message and caption to show during CAB extraction
    m_Setting.cab_dialog_caption = p_Node->AttributeT("cab_dialog_caption").data();
    m_Setting.cab_dialog_message = p_Node->AttributeT("cab_dialog_message").data();
    m_Setting.cab_cancelled_message = p_Node->AttributeT("cab_cancelled_message").data();

	ApplicationLog.Write( TEXT("Finished reading configuration attributes") );

	m_Setting.ClearComponents();

	TiXmlNode * child = NULL;
	while ( (child = p_Node->IterateChildren("component", child)) != NULL)
	{
		TiXmlElement * l_Node_component = child->ToElement();
		if (l_Node_component != NULL)
		{
			CString l_comp_type = l_Node_component->AttributeT("type").data();

			Component * l_new_component;

			if (l_comp_type == "msi")
			{
				MsiComponent * l_msi_Comp = new MsiComponent();
				l_msi_Comp->package = m_Setting.ValidatePath(l_Node_component->AttributeT("package").data());
				l_msi_Comp->type = msi;
				l_msi_Comp->cmdparameters = m_Setting.ValidatePath(l_Node_component->AttributeT("cmdparameters").data());
				l_msi_Comp->cmdparameters_silent = m_Setting.ValidatePath(l_Node_component->AttributeT("cmdparameters_silent").data());
				l_msi_Comp->cmdparameters_basic = m_Setting.ValidatePath(l_Node_component->AttributeT("cmdparameters_basic").data());

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_msi_Comp->description.GetBuffer());
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_msi_Comp->cmdparameters += TEXT(" ");
                    l_msi_Comp->cmdparameters += cmdline->second.c_str();
                    l_msi_Comp->cmdparameters_silent += TEXT(" ");
                    l_msi_Comp->cmdparameters_silent += cmdline->second.c_str();
                    l_msi_Comp->cmdparameters_basic += TEXT(" ");
                    l_msi_Comp->cmdparameters_basic += cmdline->second.c_str();
                    ApplicationLog.Write(TEXT("--Additional component arguments: "), cmdline->second.c_str());
                }

				l_new_component = l_msi_Comp;

				ApplicationLog.Write(TEXT("--Reading MSI component: "), l_msi_Comp->package);
			}
			else if (l_comp_type == "cmd")
			{
				cmd_component * l_cmd_Comp = new cmd_component();
				l_cmd_Comp->command = m_Setting.ValidatePath(l_Node_component->AttributeT("command").data());
                l_cmd_Comp->command_silent = m_Setting.ValidatePath(l_Node_component->AttributeT("command_silent").data());
				l_cmd_Comp->command_basic = m_Setting.ValidatePath(l_Node_component->AttributeT("command_basic").data());
				l_cmd_Comp->type = cmd;

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_cmd_Comp->description.GetBuffer());
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_cmd_Comp->command += TEXT(" ");
                    l_cmd_Comp->command += cmdline->second.c_str();
                    l_cmd_Comp->command_silent += TEXT(" ");
                    l_cmd_Comp->command_silent += cmdline->second.c_str();
                    l_cmd_Comp->command_basic += TEXT(" ");
                    l_cmd_Comp->command_basic += cmdline->second.c_str();
                    ApplicationLog.Write(TEXT("--Additional component arguments: "), cmdline->second.c_str());
                }

				l_new_component = l_cmd_Comp;

				ApplicationLog.Write(TEXT("--Reading COMMAND component: "), l_cmd_Comp->command);
			}
			else if (l_comp_type == "openfile")
			{
				OpenFileComponent * l_openfile_Comp = new OpenFileComponent();
				l_openfile_Comp->file = m_Setting.ValidatePath(l_Node_component->AttributeT("file").data());
				l_openfile_Comp->type = openfile;

				l_new_component = l_openfile_Comp;

				ApplicationLog.Write(TEXT("--Reading OPENFILE component: "), l_openfile_Comp->file);
			}
			else
			{
				throw std::exception("Invalid configuration file, component type not supported");
			}

			l_new_component->description = l_Node_component->AttributeT("description").data();
			l_new_component->status_installed = l_Node_component->AttributeT("status_installed").data();
			l_new_component->os_filter_greater = l_Node_component->AttributeT("os_filter_greater").data();
			l_new_component->os_filter_smaller = l_Node_component->AttributeT("os_filter_smaller").data();
			l_new_component->os_filter_lcid = l_Node_component->AttributeT("os_filter_lcid").data();
			l_new_component->installcompletemessage = l_Node_component->AttributeT("installcompletemessage").data();
			l_new_component->mustreboot = ConvBoolString(l_Node_component->Attribute("mustreboot"), false);
            l_new_component->reboot_required = l_Node_component->AttributeT("reboot_required").data();
			l_new_component->must_reboot_required = ConvBoolString(l_Node_component->Attribute("must_reboot_required"), false);
            l_new_component->allow_continue_on_error = ConvBoolString(l_Node_component->Attribute("allow_continue_on_error"), true);
            l_new_component->failed_exec_command_continue = l_Node_component->AttributeT("failed_exec_command_continue").data();
			l_new_component->required = ConvBoolString(l_Node_component->Attribute("required"), true);
			l_new_component->processor_architecture_filter = l_Node_component->AttributeT("processor_architecture_filter").data();

			// installed checks
			TiXmlNode * childInstalled = NULL;
			while ( (childInstalled = l_Node_component->IterateChildren(childInstalled)) != NULL)
			{
				TiXmlElement * l_Node = childInstalled->ToElement();
				if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheck") == 0)
				{
                    InstalledCheck * l_new_installedcheck = InstalledCheck::LoadFromXml(l_Node, m_Setting);
					l_new_component->installedchecks.push_back(l_new_installedcheck);
				}
				else if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheckoperator") == 0)
				{
                    InstalledCheckOperator * l_new_installedcheckoperator = new InstalledCheckOperator();
                    l_new_installedcheckoperator->Load(l_Node, m_Setting);
					l_new_component->installedchecks.push_back(l_new_installedcheckoperator);
				}
			}

			//
			// download dialog
			l_new_component->ContainsDownloadComponent = false; //default viene messo a falso e poi guardo se presente il nodo
			TiXmlElement * l_Node_downloaddialog = l_Node_component->FirstChildElement("downloaddialog");
			if (l_Node_downloaddialog != NULL)
			{
			    ApplicationLog.Write( TEXT("---Loading DownloadDialog") );
				LoadDownloadConfiguration(l_Node_downloaddialog, l_new_component->DownloadDialogConfiguration);
				l_new_component->ContainsDownloadComponent = true;
			}

			//verifico che il componente sia supportato nel sistema operativo
			if ( CheckConfigFilter(l_new_component->os_filter_lcid, l_new_component->os_filter_greater, l_new_component->os_filter_smaller, l_new_component->processor_architecture_filter) )
			{
				m_Setting.AddComponent(l_new_component);
                ApplicationLog.Write( TEXT("--Component OK: "), l_new_component->description );
			}
			else
			{
				delete l_new_component;
				ApplicationLog.Write( TEXT("--Component SKIPPED") );
			}

		} //if l_Node_component != NULL
	}//while l_Node_components != NULL

    // check that /ComponentArgs doesn't contain arguments for non-existant components
    std::map<std::wstring, std::wstring>::iterator arg = commandLineInfo.m_componentCmdArgs.begin();
    while(arg != commandLineInfo.m_componentCmdArgs.end())
    {
        if (! m_Setting.HasComponent(arg->first))
        {
            ApplicationLog.Write(TEXT("WARNING: Command line argument specified for a missing component: "), 
                (TEXT("\"") + arg->first + TEXT("\"")).c_str());
        }
        
        arg ++;
    }
}

bool ConfigFile::LoadReferenceConfigNode(TiXmlElement * p_Node, CWnd * p_Parent)
{
	bool l_bSuccess = false;
	TiXmlElement * l_NodeDownloadDialog = p_Node->FirstChildElement("downloaddialog");

	DownloadGroupConfiguration l_DownloadConfig;
	LoadDownloadConfiguration(l_NodeDownloadDialog, l_DownloadConfig);

    l_bSuccess = l_DownloadConfig.Run(p_Parent);
	if (l_bSuccess)
	{
		TiXmlElement * l_Node_configfile = p_Node->FirstChildElement("configfile");

		CString l_configfile_filename = m_Setting.ValidatePath(l_Node_configfile->AttributeT("filename").data());
		//CString l_configfile_banner = m_Setting.ValidatePath(l_Node_configfile->GetAttrValue("banner"));
		LoadConfigFromFile(l_configfile_filename);
	}

	return l_bSuccess;
}

int ConfigFile::LoadConfigsNode(TiXmlElement * p_Node, bool p_Caller_Has_Additional_Config)
{
	bool l_bFound = false;
	bool l_bAbort = false;

	if (strcmp(p_Node->Value(), "configurations") != 0)
	{
		throw std::exception("Invalid configuration file, node name not supported, expected 'configurations'.");
	}

	// capture configuration settings
	// (configuration settings may be modified by child "reference" configurations)
	configSetting l_ConfigSetting;
	SaveAppState(l_ConfigSetting);

    ProcessUILevel(InstallUILevelSetting::ToUILevel(p_Node->AttributeT("ui_level").data()));
    ProcessLcidType(p_Node->AttributeT("lcid_type").data());

	CdotNetInstallerDlg dlg;
//	m_pMainWnd = &dlg;

	TiXmlNode * child = NULL;
	while( (child = p_Node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * l_Node_configuration = child->ToElement();
		if ( l_Node_configuration != NULL && 
			strcmp(l_Node_configuration->Value(), "configuration") == 0 )
		{
			CString l_Config_LCID = l_Node_configuration->AttributeT("lcid").data();
			CString l_os_filter_greater = l_Node_configuration->AttributeT("os_filter_greater").data();
			CString l_os_filter_smaller = l_Node_configuration->AttributeT("os_filter_smaller").data();
            CString l_processor_architecture_filter = l_Node_configuration->AttributeT("processor_architecture_filter").data();

			ApplicationLog.Write( TEXT("Reading configuration node with LCID: "), l_Config_LCID);

			// OS Version configuration filter (in addition to LCID)
			if (CheckConfigFilter(l_Config_LCID, l_os_filter_greater, l_os_filter_smaller, l_processor_architecture_filter))
			{
				// peek ahead to determine if other config blocks exist that match the config filters
				bool l_additional_config_found = false;
				TiXmlElement * l_Node_next_configuration = child->NextSiblingElement();
				while (l_Node_next_configuration != NULL && (!l_additional_config_found))
				{
					if (strcmp(l_Node_next_configuration->Value(), "configuration") == 0)
					{
						l_additional_config_found = CheckConfigFilter(
								l_Node_next_configuration->AttributeT("lcid").data(),
								l_Node_next_configuration->AttributeT("os_filter_greater").data(),
								l_Node_next_configuration->AttributeT("os_filter_smaller").data(),
                                l_Node_next_configuration->AttributeT("processor_architecture_filter").data());
					}
					
					l_Node_next_configuration = l_Node_next_configuration->NextSiblingElement();
				}

				CString l_type = l_Node_configuration->AttributeT("type").data();
				if (l_type =="reference")
				{
					ApplicationLog.Write( TEXT("Loading reference configuration"));

					// load the reference config file and process recursively
                    ConfigFile ref_config_file;
					if (ref_config_file.LoadReferenceConfigNode(l_Node_configuration, & dlg))
					{
						ref_config_file.LoadConfigsNode(ref_config_file.m_XmlDocument.FirstChildElement(), 
                            (l_additional_config_found | p_Caller_Has_Additional_Config));
					}
					else
					{
						l_bAbort = true;
					}
				}
				else if (l_type =="install")
				{
					ApplicationLog.Write( TEXT("Loading install configuration"));
					LoadInstallConfigNode(l_Node_configuration);

					// launch the installer dialog
					INT_PTR nResponse = dlg.RunDni(m_Setting, (l_additional_config_found | p_Caller_Has_Additional_Config));
					if (nResponse == IDOK)
					{
						
					}
					else if (nResponse == IDCANCEL)
					{
						// stop processing of configuration file
						l_bAbort = true;
						break;
					}
				}
				else
                {
					throw std::exception("Invalid configuration file, configuration type not supported.");
                }

				l_bFound = true;
			}
			else
			{
				ApplicationLog.Write( TEXT("Configuration node skipped for the current LCID"));
			}
		}
	}

	// restore configuration settings
	// (configuration settings may have been modified by child "reference" configurations)
	RestoreAppState(l_ConfigSetting);

	if ( (!l_bFound) && (!l_bAbort) )
    {
        CString configuration_no_match_message = p_Node->AttributeT("configuration_no_match_message").data();
        if (configuration_no_match_message.IsEmpty()) configuration_no_match_message = "System not supported or invalid configuration.";
        throw std::exception(DVLib::Tstring2string(configuration_no_match_message).c_str());
    }

	return dlg.GetRecordedError();
}

// save the application state, in case it is modified by "reference" config files
void ConfigFile::SaveAppState(configSetting & p_Config)
{
	p_Config.ui_level = CurrentInstallUILevel.GetUILevel();
}

// restore the application state after potential "reference" config file modifications
void ConfigFile::RestoreAppState(configSetting & p_Config)
{
	if (p_Config.ui_level != InstallUILevelNotSet)
	{
		CurrentInstallUILevel.SetConfigLevel(p_Config.ui_level);
	}
	else
	{
		CurrentInstallUILevel.SetConfigLevel(InstallUILevelNotSet);
	}
}

// isolate Configuration filter checks to their own function
bool ConfigFile::CheckConfigFilter(
    const CString & p_Config_LCID, 
    const CString & p_os_filter_greater, 
    const CString & p_os_filter_smaller,
    const CString & p_processor_architecture_filter)
{
	return (DVLib::IsOperatingSystemLCID(m_lcidtype, p_Config_LCID) &&
		DVLib::IsProcessorArchitecture(p_processor_architecture_filter) &&
		DVLib::IsInRangedOs(DVLib::GetOsVersion(), p_os_filter_greater, p_os_filter_smaller));
}

bool ConfigFile::LoadDocumentFromFile(const CString & p_FileName)
{
	HANDLE l_hFile = CreateFile(p_FileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (l_hFile == INVALID_HANDLE_VALUE)
		return false;

	DWORD l_Size = GetFileSize(l_hFile,NULL);

	//this function doesn't support unicode files or unicode compilation
	char * l_Buffer = new char[l_Size];
	ZeroMemory(l_Buffer,l_Size);

	DWORD l_ByteReaded;
	BOOL l_ret = ReadFile(l_hFile,l_Buffer, l_Size, &l_ByteReaded, NULL);
	if(l_ret==FALSE)
	{
		CloseHandle(l_hFile);
		return false;
	}
	CloseHandle(l_hFile);

    ApplicationLog.Write(TEXT("Parsing "), DVLib::FormatNumberToBytes(l_Size));

	m_XmlDocument.Parse(l_Buffer);
	if (m_XmlDocument.Error())
	{
		ApplicationLog.Write(TEXT("***Parsing error: "), DVLib::string2Tstring(m_XmlDocument.ErrorDesc()).data());
		return false;
	}

	delete [] l_Buffer;
    ApplicationLog.Write(TEXT("Successfully parsed: "), p_FileName);
	return true;
}

void ConfigFile::LoadConfigFromFile(const CString & p_FileName)
{
	// don't use the default LoadFrom file because is not Unicode
	bool l_ret = LoadDocumentFromFile(p_FileName);
	if (l_ret == false)
	{
        ApplicationLog.Write(TEXT("***Failed to load configuration file: "), p_FileName);
		throw std::exception("Invalid configuration file, failed to parse XML elements.");
	}
}

void ConfigFile::LoadConfigFromResource(HMODULE p_Module)
{
	ApplicationLog.Write( TEXT("Loading configuration from resource") );

	HRSRC l_res = FindResource(p_Module, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
	if (l_res == NULL)
		throw std::exception("Resource RES_CONFIGURATION not found.");
	HGLOBAL l_hRes = LoadResource(p_Module, l_res);
	if (l_hRes == NULL)
		throw std::exception("Failed to load resource RES_CONFIGURATION.");
	LPVOID l_buffer = LockResource(l_hRes);
	if (l_buffer == NULL)
		throw std::exception("Failed to lock resource RES_CONFIGURATION.");
	DWORD l_size = SizeofResource(p_Module, l_res);
	char * l_bufferXml = new char[l_size+1];
	memset(l_bufferXml,0,l_size+1);
	memcpy(l_bufferXml, l_buffer, l_size);
	
	m_XmlDocument.Parse(l_bufferXml);	
	if (m_XmlDocument.Error())
	{
		ApplicationLog.Write( TEXT("***Failed parsing xml configuration from resource") );
        delete [] l_bufferXml;
		throw std::exception("Resource RES_CONFIGURATION is not a valid xml.");
	}

	ApplicationLog.Write( TEXT("Finished parsing xml configuration from resource") );

	delete [] l_bufferXml;
}

void ConfigFile::LoadXmlSettings()
{
	CString settings_file = DVLib::PathCombine(DVLib::GetAppPath(), TEXT("configuration.xml"));
	if (DVLib::FileExists(settings_file))
	{
		ApplicationLog.Write(TEXT("Loading configuration from file: "), settings_file);
		LoadConfigFromFile(settings_file);
	}
	else
	{
		ApplicationLog.Write(TEXT("Loading configuration from resource."));
		LoadConfigFromResource(AfxGetApp()->m_hInstance);
	}
}

void ConfigFile::ProcessUILevel(InstallUILevel value)
{
	// if parent configuration UI level is set, a child configuration will inherit that setting
	if (value != InstallUILevelNotSet)
	{
		CurrentInstallUILevel.SetConfigLevel(value);
	}
}

// process lcidtype setting
void ConfigFile::ProcessLcidType(const CString& lcidtype)
{
	if (lcidtype.IsEmpty())
		return;

    if (lcidtype == "System") m_lcidtype = LcidSystem;
    else if (lcidtype == "User") m_lcidtype = LcidUser;
    else if (lcidtype == "UserExe") m_lcidtype = LcidUserExe;
    else throw std::exception("Invalid LCID type.");
}