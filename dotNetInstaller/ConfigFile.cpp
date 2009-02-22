#include "stdafx.h"
#include "ConfigFile.h"
#include "InstallerLog.h"
#include "DniMessageBox.h"
#include "SilentInstall.h"
#include "dotNetInstallerDlg.h"
#include "ProcessorIdentifier.h"
#include "MsiComponent.h"
#include "CmdComponent.h"
#include "OpenFileComponent.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckOperator.h"
#include "InstallerCommandLineInfo.h"

bool ConvBoolString(const char * p_BoolString, bool defaultValue = false)
{
    if (NULL == p_BoolString) return defaultValue;
	else if (0 == _stricmp(p_BoolString, "true")) return true;
	else if (0 == _stricmp(p_BoolString, "false")) return false;
    else return defaultValue;
}

void LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DVLib::DownloadGroupConfiguration & p_Configuration, InstallerSetting & p_Setting)
{
	ApplicationLog.Write( TEXT("Start reading download attributes") );

	p_Configuration.Caption = p_Node_downloaddialog->AttributeT("dialog_caption").data();
	p_Configuration.HelpMessage = p_Node_downloaddialog->AttributeT("dialog_message").data();
	p_Configuration.HelpMessageDownloading = p_Node_downloaddialog->AttributeT("dialog_message_downloading").data();
	p_Configuration.ButtonStartCaption = p_Node_downloaddialog->AttributeT("buttonstart_caption").data();
	p_Configuration.ButtonCancelCaption = p_Node_downloaddialog->AttributeT("buttoncancel_caption").data();
	p_Configuration.AutoStartDownload = ConvBoolString(p_Node_downloaddialog->Attribute("autostartdownload"), false);

	ApplicationLog.Write( TEXT("End reading download attributes") );

	p_Configuration.Components.RemoveAll();

	TiXmlNode * child = NULL;
	while ( (child = p_Node_downloaddialog->IterateChildren("download", child)) != NULL)
	{
		TiXmlElement * l_Node_download = child->ToElement();
		if (l_Node_download != NULL)
		{
			ApplicationLog.Write( TEXT("--Reading Download component"));

			DVLib::DownloadComponentInfo l_DownloadComp;
			l_DownloadComp.ComponentName = l_Node_download->AttributeT("componentname").data();
			l_DownloadComp.SourceURL = p_Setting.ValidatePath(l_Node_download->AttributeT("sourceurl").data());
			l_DownloadComp.DestinationPath = p_Setting.ValidatePath(l_Node_download->AttributeT("destinationpath").data());
			l_DownloadComp.DestinationFileName = p_Setting.ValidatePath(l_Node_download->AttributeT("destinationfilename").data());
			l_DownloadComp.AlwaysDownload = ConvBoolString(l_Node_download->Attribute("alwaysdownload"), true);
			p_Configuration.Components.Add(l_DownloadComp);

			ApplicationLog.Write( TEXT("--Finished reading download component: "), l_DownloadComp.SourceURL );
		}
	}

	if (p_Configuration.Components.GetCount() <= 0)
	{
		throw std::exception("No download components found. Downloads node is empty.");
	}
}

// Populate the p_Setting object
void LoadInstallConfigNode(TiXmlElement * p_Node, InstallerSetting & p_Setting)
{
	DVLib::OperatingSystem l_CurrentOs = DVLib::GetOsVersion();

	ApplicationLog.Write( TEXT("Reading configuration attributes") );

    /* Daniel Doubrovkine - 2008-06-24: added auto-enabled log options */
    p_Setting.log_enabled = ConvBoolString(p_Node->Attribute("log_enabled"), false);
    p_Setting.log_file = p_Node->AttributeT("log_file").data();

    // enable logging if log is not enabled by a command line switch and enabled in the configuration
    if (! ApplicationLog.IsEnableLog() && p_Setting.log_enabled)
    {
        ApplicationLog.SetLogFile(p_Setting.ValidatePath(p_Setting.log_file));
        ApplicationLog.EnableLog();
    }

    /* Daniel Doubrovkine - 2008-06-12: added CABBPATH that defines where to extract files */
    p_Setting.cab_path = p_Node->AttributeT("cab_path").data();
    p_Setting.cab_path_autodelete = ConvBoolString(p_Node->Attribute("cab_path_autodelete"), true);

	p_Setting.cancel_caption = p_Node->AttributeT("cancel_caption").data();
	p_Setting.dialog_bitmap = p_Setting.ValidatePath(p_Node->AttributeT("dialog_bitmap").data());
	p_Setting.dialog_caption = p_Node->AttributeT("dialog_caption").data();
	p_Setting.dialog_message = p_Node->AttributeT("dialog_message").data();
	p_Setting.skip_caption = p_Node->AttributeT("skip_caption").data();
	p_Setting.install_caption = p_Node->AttributeT("install_caption").data();
	p_Setting.status_installed = p_Node->AttributeT("status_installed").data();
	p_Setting.status_notinstalled = p_Node->AttributeT("status_notinstalled").data();
	p_Setting.failed_exec_command_continue = p_Node->AttributeT("failed_exec_command_continue").data();
	p_Setting.installation_completed = p_Node->AttributeT("installation_completed").data();
	p_Setting.reboot_required = p_Node->AttributeT("reboot_required").data();
    p_Setting.must_reboot_required = ConvBoolString(p_Node->Attribute("must_reboot_required"), false);
	p_Setting.installing_component_wait = p_Node->AttributeT("installing_component_wait").data();

	p_Setting.dialog_otherinfo_caption = p_Node->AttributeT("dialog_otherinfo_caption").data();
	p_Setting.dialog_otherinfo_link = p_Setting.ValidatePath(p_Node->AttributeT("dialog_otherinfo_link").data());

	p_Setting.complete_command = p_Setting.ValidatePath(p_Node->AttributeT("complete_command").data());
	p_Setting.complete_command_silent = p_Setting.ValidatePath(p_Node->AttributeT("complete_command_silent").data());
	p_Setting.auto_close_if_installed = ConvBoolString(p_Node->Attribute("auto_close_if_installed"), true);
    p_Setting.allow_continue_on_error = ConvBoolString(p_Node->Attribute("allow_continue_on_error"), true);
    p_Setting.dialog_show_installed = ConvBoolString(p_Node->Attribute("dialog_show_installed"), true);
    p_Setting.dialog_show_required = ConvBoolString(p_Node->Attribute("dialog_show_required"), true);

	// Matthias Jentsch - 2006-03-06: read additional attributes
	p_Setting.os_filter_greater = p_Node->AttributeT("os_filter_greater").data();
	p_Setting.os_filter_smaller = p_Node->AttributeT("os_filter_smaller").data();
	p_Setting.os_filter_not_match_message = p_Node->AttributeT("os_filter_not_match_message").data();
	if (p_Setting.os_filter_not_match_message.GetLength() == 0)
	{
		// Matthias Jentsch - 2006-03-06: default message if no message is defined
		p_Setting.os_filter_not_match_message = TEXT("This setup cannot run under the current operating system!");
	}
	
	// Jason Biegel - 2008-04-23: read additional attributes
	p_Setting.processor_architecture_filter = p_Node->AttributeT("processor_architecture_filter").data();
	p_Setting.processor_architecture_filter_not_match_message = p_Node->AttributeT("processor_architecture_filter_not_match_message").data();
	if(p_Setting.processor_architecture_filter_not_match_message.GetLength() == 0)
	{
		// Jason Biegel - 2008-04-23: default message if no message is defined
		p_Setting.processor_architecture_filter_not_match_message = TEXT("This setup cannot run on the current processor!");
	}

    /* Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction */
    p_Setting.cab_dialog_caption = p_Node->AttributeT("cab_dialog_caption").data();
    p_Setting.cab_dialog_message = p_Node->AttributeT("cab_dialog_message").data();
    p_Setting.cab_cancelled_message = p_Node->AttributeT("cab_cancelled_message").data();

	ApplicationLog.Write( TEXT("Finished reading configuration attributes") );

	//caricamento componenti
	p_Setting.ClearComponents();

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
			    l_msi_Comp->description = l_Node_component->AttributeT("description").data();
				l_msi_Comp->package = p_Setting.ValidatePath(l_Node_component->AttributeT("package").data());
				l_msi_Comp->type = msi;
				l_msi_Comp->cmdparameters = p_Setting.ValidatePath(l_Node_component->AttributeT("cmdparameters").data());
				l_msi_Comp->cmdparameters_silent = p_Setting.ValidatePath(l_Node_component->AttributeT("cmdparameters_silent").data());

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_msi_Comp->description.GetBuffer());
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_msi_Comp->cmdparameters += TEXT(" ");
                    l_msi_Comp->cmdparameters += cmdline->second.c_str();
                    l_msi_Comp->cmdparameters_silent += TEXT(" ");
                    l_msi_Comp->cmdparameters_silent += cmdline->second.c_str();
                    ApplicationLog.Write(TEXT("--Additional component arguments: "), cmdline->second.c_str());
                }

				l_new_component = l_msi_Comp;

				ApplicationLog.Write(TEXT("--Reading MSI component: "), l_msi_Comp->package);
			}
			else if (l_comp_type == "cmd")
			{
				cmd_component * l_cmd_Comp = new cmd_component();
			    l_cmd_Comp->description = l_Node_component->AttributeT("description").data();
				l_cmd_Comp->command = p_Setting.ValidatePath(l_Node_component->AttributeT("command").data());
                l_cmd_Comp->command_silent = p_Setting.ValidatePath(l_Node_component->AttributeT("command_silent").data());
				l_cmd_Comp->type = cmd;

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_cmd_Comp->description.GetBuffer());
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_cmd_Comp->command += TEXT(" ");
                    l_cmd_Comp->command += cmdline->second.c_str();
                    l_cmd_Comp->command_silent += TEXT(" ");
                    l_cmd_Comp->command_silent += cmdline->second.c_str();
                    ApplicationLog.Write(TEXT("--Additional component arguments: "), cmdline->second.c_str());
                }

				l_new_component = l_cmd_Comp;

				ApplicationLog.Write(TEXT("--Reading COMMAND component: "), l_cmd_Comp->command);
			}
			else if (l_comp_type == "openfile")
			{
				OpenFileComponent * l_openfile_Comp = new OpenFileComponent();
				l_openfile_Comp->file = p_Setting.ValidatePath(l_Node_component->AttributeT("file").data());
				l_openfile_Comp->type = openfile;

				l_new_component = l_openfile_Comp;

				ApplicationLog.Write(TEXT("--Reading OPENFILE component: "), l_openfile_Comp->file);
			}
			else
			{
				throw std::exception("Invalid configuration file, component type not supported");
			}

			l_new_component->description = l_Node_component->AttributeT("description").data();
			l_new_component->os_filter_greater = l_Node_component->AttributeT("os_filter_greater").data();
			l_new_component->os_filter_smaller = l_Node_component->AttributeT("os_filter_smaller").data();
			l_new_component->os_filter_lcid = l_Node_component->AttributeT("os_filter_lcid").data();
			l_new_component->installcompletemessage = l_Node_component->AttributeT("installcompletemessage").data();
			l_new_component->mustreboot = ConvBoolString(l_Node_component->Attribute("mustreboot"), false);
            l_new_component->reboot_required = l_Node_component->AttributeT("reboot_required").data();
			l_new_component->must_reboot_required = ConvBoolString(l_Node_component->Attribute("must_reboot_required"), false);
			l_new_component->required = ConvBoolString(l_Node_component->Attribute("required"), true);
			l_new_component->processor_architecture_filter = l_Node_component->AttributeT("processor_architecture_filter").data();

			// installed checks
			TiXmlNode * childInstalled = NULL;
			while ( (childInstalled = l_Node_component->IterateChildren(childInstalled)) != NULL)
			{
				TiXmlElement * l_Node = childInstalled->ToElement();
				if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheck") == 0)
				{
                    InstalledCheck * l_new_installedcheck = InstalledCheck::LoadFromXml(l_Node, p_Setting);
					l_new_component->installedchecks.push_back(l_new_installedcheck);
				}
				else if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheckoperator") == 0)
				{
                    InstalledCheckOperator * l_new_installedcheckoperator = new InstalledCheckOperator();
                    l_new_installedcheckoperator->Load(l_Node, p_Setting);
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
				LoadDownloadConfiguration(l_Node_downloaddialog, l_new_component->DownloadDialogConfiguration, p_Setting);
				l_new_component->ContainsDownloadComponent = true;
			}

			l_new_component->selected = false;
			//verifico che il componente sia supportato nel sistema operativo

			if ( CheckConfigFilter(l_new_component->os_filter_lcid, l_new_component->os_filter_greater, l_new_component->os_filter_smaller, l_new_component->processor_architecture_filter) )
			{
                bool l_new_component_installed = l_new_component->IsInstalled();

				if (! l_new_component_installed)
                {
					l_new_component->selected = true;
                }

				p_Setting.AddComponent(l_new_component);

                ApplicationLog.Write( TEXT("--Component OK: "), l_new_component_installed ? TEXT("INSTALLED") : TEXT("NOT INSTALLED") );
			}
			else
			{
				FreeComponent(l_new_component);

				ApplicationLog.Write( TEXT("--Component SKIPPED") );
			}

		} //if l_Node_component != NULL
	}//while l_Node_components != NULL

    // Daniel Doubrovkine - 2008-11-08: Check that /ComponentArgs doesn't contain arguments for non-existant components
    std::map<std::wstring, std::wstring>::iterator arg = commandLineInfo.m_componentCmdArgs.begin();
    while(arg != commandLineInfo.m_componentCmdArgs.end())
    {
        if (! p_Setting.HasComponent(arg->first))
        {
            ApplicationLog.Write(TEXT("WARNING: Command line argument specified for a missing component: "), 
                (TEXT("\"") + arg->first + TEXT("\"")).c_str());
        }
        
        arg ++;
    }
}

bool LoadReferenceConfigNode(TiXmlElement * p_Node, TiXmlDocument & p_Document, CWnd * p_Parent, InstallerSetting & p_Setting)
{
	bool l_bSuccess = false;
	TiXmlElement * l_NodeDownloadDialog = p_Node->FirstChildElement("downloaddialog");

	DVLib::DownloadGroupConfiguration l_DownloadConfig;
	LoadDownloadConfiguration(l_NodeDownloadDialog, l_DownloadConfig, p_Setting);

	l_bSuccess = RunDownloadDialog(l_DownloadConfig, p_Parent);
	if (l_bSuccess)
	{
		TiXmlElement * l_Node_configfile = p_Node->FirstChildElement("configfile");

		CString l_configfile_filename = p_Setting.ValidatePath(l_Node_configfile->AttributeT("filename").data());
		//CString l_configfile_banner = p_Setting.ValidatePath(l_Node_configfile->GetAttrValue("banner"));

		LoadConfigFromFile(l_configfile_filename, p_Document);
	}

	return l_bSuccess;
}

void LoadConfigsNode(TiXmlElement * p_Node, InstallerSetting & p_Setting, bool p_Caller_Has_Additional_Config)
{
	bool l_bFound = false;
	bool l_bAbort = false;

	if (strcmp(p_Node->Value(), "configurations") != 0)
	{
		throw std::exception("Invalid configuration file, node name not supported, expected 'configurations'.");
	}

	// Matthew Sheets - 2007-09-24: Capture configuration settings
	//  (configuration settings may be modified by child "reference" configurations)
	configSetting l_ConfigSetting;
	SaveAppState(l_ConfigSetting);

	// Matthew Sheets - 2007-09-20: Process silent install setting
	//   If parent configuration is configured for a silent install,
	//   a child configuration will inherit that setting
	if (ConvBoolString(p_Node->Attribute("silent_install"), false))
	{
		QuietInstall.EnableSilentInstall();
	}


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

			// Matthew Sheets - 2007-09-25: Added OS Version to the configuration filter (in addition to LCID)
			if (CheckConfigFilter(l_Config_LCID, l_os_filter_greater, l_os_filter_smaller, l_processor_architecture_filter))
			{
				// Matthew Sheets - 2008-01-14: Peek ahead to determine
				//	 if other config blocks exist that match the config filters
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

					// Matthew Sheets - 2007-09-24: Load the reference config file and process recursively
					TiXmlDocument l_RefDocument;
					InstallerSetting l_RefSetting;

					if (LoadReferenceConfigNode(l_Node_configuration, l_RefDocument, &dlg, p_Setting))
					{
						LoadConfigsNode(l_RefDocument.FirstChildElement(), l_RefSetting, (l_additional_config_found | p_Caller_Has_Additional_Config));
					}
					else
					{
						l_bAbort = true;
					}
				}
				else if (l_type =="install")
				{
					ApplicationLog.Write( TEXT("Loading install configuration"));
					LoadInstallConfigNode(l_Node_configuration, p_Setting);

					// Matthew Sheets - 2007-09-24: Launch the installer dialog
					INT_PTR nResponse = dlg.RunDni(p_Setting, (l_additional_config_found | p_Caller_Has_Additional_Config));
					if (nResponse == IDOK)
					{
						//  tramite il pulsante OK.
					}
					else if (nResponse == IDCANCEL)
					{
						// Matthew Sheets - 2008-01-14: Stop processing of configuration file
						l_bAbort = true;
						break;

						//  tramite il pulsante Annulla.
					}
				}
				else
					throw std::exception("Invalid configuration file, configuration type not supported.");

				l_bFound = true;

//				break;

			}
			else
			{
				ApplicationLog.Write( TEXT("Configuration node skipped for the current LCID"));
			}
		}
	}

	// Matthew Sheets - 2007-09-24: Restore configuration settings
	//  (configuration settings may have been modified by child "reference" configurations)
	RestoreAppState(l_ConfigSetting);

	if ( (!l_bFound) && (!l_bAbort) )
		throw std::exception("System not supported or invalid configuration, no valid 'configuration' node found.");
}

// Matthew Sheets - 2007-09-24: Save the application state, in case it is modified by "reference" config files
void SaveAppState(configSetting & p_Config)
{
	p_Config.silent_install = QuietInstall.IsSilent();
}

// Matthew Sheets - 2007-09-24: Restore the application state after potential "reference" config file modifications
void RestoreAppState(configSetting & p_Config)
{
	if (p_Config.silent_install)
	{
		QuietInstall.EnableSilentInstall();
	}
	else
	{
		QuietInstall.DisableSilentInstall();
	}
}

// Matthew Sheets - 2008/01/14: Isolate Configuration filter checks to their own function
bool CheckConfigFilter(
    const CString & p_Config_LCID, 
    const CString & p_os_filter_greater, 
    const CString & p_os_filter_smaller,
    const CString & p_processor_architecture_filter)
{
	return (DVLib::IsOperatingSystemLCID(p_Config_LCID) &&
		DVLib::IsProcessorArchitecture(p_processor_architecture_filter) &&
		DVLib::IsInRangedOs(DVLib::GetOsVersion(), p_os_filter_greater, p_os_filter_smaller));
}

bool LoadDocumentFromFile(const CString & p_FileName, TiXmlDocument & document)
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

	document.Parse(l_Buffer);
	if (document.Error())
	{
		ApplicationLog.Write(TEXT("***Parsing error: "), DVLib::string2Tstring(document.ErrorDesc()).data() );

		return false;
	}

	delete [] l_Buffer;

    ApplicationLog.Write(TEXT("Successfully parsed: "), p_FileName);

	return true;
}

void LoadConfigFromFile(const CString & p_FileName, TiXmlDocument & p_Document)
{
	//I don't use the default LoadFrom file because is not Unicode
	bool l_ret = LoadDocumentFromFile(p_FileName, p_Document);
	if (l_ret==false)
	{
        ApplicationLog.Write(TEXT("***Failed to load configuration file: "), p_FileName);

		throw std::exception("Invalid configuration file, failed to parse XML elements.");
	}
}

void LoadConfigFromResource(HMODULE p_Module, TiXmlDocument & p_Document)
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
	
	p_Document.Parse(l_bufferXml);
	
	if (p_Document.Error())
	{
		ApplicationLog.Write( TEXT("***Failed parsing xml configuration from resource") );
        delete [] l_bufferXml;
		throw std::exception("Resource RES_CONFIGURATION is not a valid xml.");
	}

	ApplicationLog.Write( TEXT("Finished parsing xml configuration from resource") );

	delete [] l_bufferXml;
}

HBITMAP LoadBannerFromResource(HMODULE p_Module)
{
	try
	{
		//leggo la risorsa
		HRSRC l_res = FindResource(p_Module, TEXT("RES_BANNER"), TEXT("CUSTOM"));
		if (l_res == NULL)
            throw std::exception("Error locating RES_BANNER resource");

        HGLOBAL l_hRes = LoadResource(p_Module, l_res);
		if (l_hRes == NULL)
			throw std::exception("Error loading RES_BANNER resource");
		DWORD l_size = SizeofResource(p_Module, l_res);

		LPVOID l_buffer = LockResource(l_hRes);
		if (l_buffer == NULL)
			throw std::exception("Error locking RES_BANNER resource");

		return DVLib::LoadBitmapFromBuffer(l_buffer, l_size);
	}
    catch(std::exception&)
	{
		return NULL;
	}
}

//returns true if the functions sucessfully load the setting m_Setting
bool LoadXmlSettings(TiXmlDocument & p_Document)
{
	//riferimento standard
	CString l_SettingFile = DVLib::PathCombineCustom(DVLib::GetAppPath(), TEXT("configuration.xml"));

	if (DVLib::FileExistsCustom(l_SettingFile))
	{
		ApplicationLog.Write(TEXT("Loading configuration from file: "), l_SettingFile);

		LoadConfigFromFile(l_SettingFile, p_Document); //riferimento
	}
	else
	{
		ApplicationLog.Write(TEXT("Loading configuration from resource."));

		LoadConfigFromResource(AfxGetApp()->m_hInstance, p_Document);
	}

	return true;
}

void FreeComponent(Component * c)
{
	if (c != NULL)
	{
		for (size_t j = 0; j < c->installedchecks.size(); j++)
		{
			InstalledCheck * ic = c->installedchecks[j];
			c->installedchecks[j] = NULL;
			if (ic != NULL)
				delete ic;
		}
		delete c;
	}
}
