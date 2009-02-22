#include "stdafx.h"
#include "ConfigFile.h"
#include "InstallerLog.h"
#include "DniMessageBox.h"
#include "SilentInstall.h"
#include "dotNetInstallerDlg.h"
#include "ProcessorIdentifier.h"

bool ConvBoolString(const char * p_BoolString, bool defaultValue = false)
{
	if (p_BoolString != NULL && _stricmp(p_BoolString, "true") == 0 )
		return true;
	else if (p_BoolString != NULL && _stricmp(p_BoolString, "false") == 0 )
		return false;
	else
	{
		_ASSERT(false); //non riconosciuto (default)
		return defaultValue;
	}
}

void LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DVLib::DownloadGroupConfiguration & p_Configuration)
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

	TiXmlElement * l_Node_downloads = p_Node_downloaddialog->FirstChildElement("downloads");
	TiXmlNode * child = NULL;
	while ( (child = l_Node_downloads->IterateChildren(child)) != NULL)
	{
		TiXmlElement * l_Node_download = child->ToElement();
		if ( l_Node_download != NULL &&
			strcmp(l_Node_download->Value(), "download") == 0 )
		{
			ApplicationLog.Write( TEXT("--Reading Download component ..."));

			DVLib::DownloadComponentInfo l_DownloadComp;
			l_DownloadComp.ComponentName = l_Node_download->AttributeT("componentname").data();
			l_DownloadComp.SourceURL = ValidatePath(l_Node_download->AttributeT("sourceurl").data());
			l_DownloadComp.DestinationPath = ValidatePath(l_Node_download->AttributeT("destinationpath").data());
			l_DownloadComp.DestinationFileName = ValidatePath(l_Node_download->AttributeT("destinationfilename").data());
			l_DownloadComp.AlwaysDownload = ConvBoolString(l_Node_download->Attribute("alwaysdownload"), true);
			p_Configuration.Components.Add(l_DownloadComp);

			ApplicationLog.Write( TEXT("--Readed download component :"), l_DownloadComp.SourceURL );
		}
	}

	if (p_Configuration.Components.GetCount() <= 0)
	{
		throw TEXT("No download components found. Downloads node is empty.");
	}
}

// Populate the p_Setting object
void LoadInstallConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting)
{
	DVLib::OperatingSystem l_CurrentOs = DVLib::GetOsVersion();

	ApplicationLog.Write( TEXT("Start reading configuration attributes") );

	p_Setting.cancel_caption = p_Node->AttributeT("cancel_caption").data();
	p_Setting.dialog_bitmap = ValidatePath(p_Node->AttributeT("dialog_bitmap").data());
	p_Setting.dialog_caption = p_Node->AttributeT("dialog_caption").data();
	p_Setting.dialog_message = p_Node->AttributeT("dialog_message").data();
	p_Setting.skip_caption = p_Node->AttributeT("skip_caption").data();
	p_Setting.install_caption = p_Node->AttributeT("install_caption").data();
	p_Setting.status_installed = p_Node->AttributeT("status_installed").data();
	p_Setting.status_notinstalled = p_Node->AttributeT("status_notinstalled").data();
	p_Setting.failed_exec_command_continue = p_Node->AttributeT("failed_exec_command_continue").data();
	p_Setting.installation_completed = p_Node->AttributeT("installation_completed").data();
	p_Setting.reboot_required = p_Node->AttributeT("reboot_required").data();
	p_Setting.installing_component_wait = p_Node->AttributeT("installing_component_wait").data();

	p_Setting.advanced_caption = p_Node->AttributeT("advanced_caption").data();
	p_Setting.dialog_selector_caption = p_Node->AttributeT("dialog_selector_caption").data();
	p_Setting.dialog_selector_message = p_Node->AttributeT("dialog_selector_message").data();
	p_Setting.dialog_selector_ok = p_Node->AttributeT("dialog_selector_ok").data();
	p_Setting.dialog_selector_cancel = p_Node->AttributeT("dialog_selector_cancel").data();

	p_Setting.dialog_otherinfo_caption = p_Node->AttributeT("dialog_otherinfo_caption").data();
	p_Setting.dialog_otherinfo_link = ValidatePath(p_Node->AttributeT("dialog_otherinfo_link").data());

	p_Setting.complete_command = ValidatePath(p_Node->AttributeT("complete_command").data());
	p_Setting.auto_close_if_installed = ConvBoolString(p_Node->Attribute("auto_close_if_installed"), true);

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
	
	ApplicationLog.Write( TEXT("End reading configuration attributes") );

	//caricamento componenti
	p_Setting.components.clear();

	TiXmlElement * l_Node_components = p_Node->FirstChildElement("components");
	if (NULL == l_Node_components)
	{
		throw TEXT("Invalid configuration file, no valid 'components' node found");
	}
	else
	{
		TiXmlNode * child = NULL;
		while ( (child = l_Node_components->IterateChildren("component", child)) != NULL)
		{
			TiXmlElement * l_Node_component = child->ToElement();

			if (l_Node_component != NULL)
			{
				CString l_comp_type = l_Node_component->AttributeT("type").data();

				component * l_new_component;

				if (l_comp_type == "msi")
				{
					msi_component * l_msi_Comp = new msi_component();
					l_msi_Comp->package = ValidatePath(l_Node_component->AttributeT("package").data());
					l_msi_Comp->type = msi;
					l_msi_Comp->cmdparameters = ValidatePath(l_Node_component->AttributeT("cmdparameters").data());

					l_new_component = l_msi_Comp;

					ApplicationLog.Write(TEXT("--Reading MSI component: "), l_msi_Comp->package);
				}
				else if (l_comp_type == "cmd")
				{
					cmd_component * l_cmd_Comp = new cmd_component();
					l_cmd_Comp->command = ValidatePath(l_Node_component->AttributeT("command").data());
					l_cmd_Comp->type = cmd;

					l_new_component = l_cmd_Comp;

					ApplicationLog.Write(TEXT("--Reading COMMAND component: "), l_cmd_Comp->command);
				}
				else if (l_comp_type == "openfile")
				{
					openfile_component * l_openfile_Comp = new openfile_component();
					l_openfile_Comp->file = ValidatePath(l_Node_component->AttributeT("file").data());
					l_openfile_Comp->type = openfile;

					l_new_component = l_openfile_Comp;

					ApplicationLog.Write(TEXT("--Reading OPENFILE component: "), l_openfile_Comp->file);
				}
				else
				{
					throw TEXT("Invalid configuration file, component type not supported");
				}

				l_new_component->description = l_Node_component->AttributeT("description").data();
				l_new_component->os_filter_greater = l_Node_component->AttributeT("os_filter_greater").data();
				l_new_component->os_filter_smaller = l_Node_component->AttributeT("os_filter_smaller").data();
				l_new_component->os_filter_lcid = l_Node_component->AttributeT("os_filter_lcid").data();
				l_new_component->installcompletemessage = l_Node_component->AttributeT("installcompletemessage").data();
				l_new_component->mustreboot = ConvBoolString(l_Node_component->Attribute("mustreboot"), false);
			l_new_component->processor_architecture_filter = l_Node_component->AttributeT("processor_architecture_filter").data();

				// installed checks
				TiXmlNode * childInstalled = NULL;
				while ( (childInstalled = l_Node_component->IterateChildren(childInstalled)) != NULL)
				{
					TiXmlElement * l_Node_installedcheck = childInstalled->ToElement();
					if (l_Node_installedcheck != NULL && 
						strcmp(l_Node_installedcheck->Value(), "installedcheck") == 0)
					{
						CString l_installedcheck_type = l_Node_installedcheck->AttributeT("type").data();
						installedcheck * l_new_installedcheck;
						if(l_installedcheck_type == "check_registry_value")
						{
							installedcheck_check_registry_value * l_new_check_registry_value = new installedcheck_check_registry_value;

							l_new_check_registry_value->fieldname = l_Node_installedcheck->AttributeT("fieldname").data();
							l_new_check_registry_value->fieldtype = l_Node_installedcheck->AttributeT("fieldtype").data();
							l_new_check_registry_value->fieldvalue = l_Node_installedcheck->AttributeT("fieldvalue").data();
							l_new_check_registry_value->path = l_Node_installedcheck->AttributeT("path").data();
							l_new_check_registry_value->comparison = l_Node_installedcheck->AttributeT("comparison").data();
							l_new_check_registry_value->rootkey = l_Node_installedcheck->AttributeT("rootkey").data();

							l_new_installedcheck = l_new_check_registry_value;

							ApplicationLog.Write(TEXT("----Reading REGISTRY installed check: "), l_new_check_registry_value->path);
						}
						else if(l_installedcheck_type == "check_file")
						{
							installedcheck_check_file * l_new_check_file = new installedcheck_check_file;

							l_new_check_file->filename = ValidatePath(l_Node_installedcheck->AttributeT("filename").data());
							l_new_check_file->fileversion = l_Node_installedcheck->AttributeT("fileversion").data();
							l_new_check_file->comparison = l_Node_installedcheck->AttributeT("comparison").data();

							l_new_installedcheck = l_new_check_file;

							ApplicationLog.Write(TEXT("----Reading CHECKFILE installed check: "), l_new_check_file->filename);
						}
						else
						{
							throw TEXT("Invalid configuration file, installed check type not supported");
						}

						l_new_component->installedchecks.insert(l_new_component->installedchecks.end(), l_new_installedcheck);
					}
				}



				// download dialog
				l_new_component->ContainsDownloadComponent = false; //default viene messo a falso e poi guardo se è presente il nodo
				TiXmlElement * l_Node_downloaddialog = l_Node_component->FirstChildElement("downloaddialog");
				if (l_Node_downloaddialog!=NULL)
				{
					LoadDownloadConfiguration(l_Node_downloaddialog, l_new_component->DownloadDialogConfiguration);
					l_new_component->ContainsDownloadComponent = true;
				}

				l_new_component->selected = false;
				//verifico che il componente sia supportato nel sistema operativo

				if ( CheckConfigFilter(l_new_component->os_filter_lcid, l_new_component->os_filter_greater, l_new_component->os_filter_smaller, l_new_component->processor_architecture_filter) )
				{
					if (l_new_component->IsInstalled() == false)
						l_new_component->selected = true;

					p_Setting.components.insert(p_Setting.components.end(), l_new_component);

					ApplicationLog.Write( TEXT("--Component OK") );
				}
				else
				{
					FreeComponent(l_new_component);

					ApplicationLog.Write( TEXT("--Component SKIPPED") );
				}

			} //if l_Node_component != NULL
		}//while l_Node_components != NULL
	} // if l_Node_components != NULL
}

bool LoadReferenceConfigNode(TiXmlElement * p_Node, TiXmlDocument & p_Document, CWnd * p_Parent)
{
	bool l_bSuccess = false;
	TiXmlElement * l_NodeDownloadDialog = p_Node->FirstChildElement("downloaddialog");

	DVLib::DownloadGroupConfiguration l_DownloadConfig;
	LoadDownloadConfiguration(l_NodeDownloadDialog, l_DownloadConfig);

	l_bSuccess = RunDownloadDialog(l_DownloadConfig, p_Parent);
	if (l_bSuccess)
	{
		TiXmlElement * l_Node_configfile = p_Node->FirstChildElement("configfile");

		CString l_configfile_filename = ValidatePath(l_Node_configfile->AttributeT("filename").data());
		//CString l_configfile_banner = ValidatePath(l_Node_configfile->GetAttrValue("banner"));

		LoadConfigFromFile(l_configfile_filename, p_Document);
	}

	return l_bSuccess;
}

void LoadConfigsNode(TiXmlElement * p_Node, installerSetting & p_Setting, bool p_Caller_Has_Additional_Config)
{
	bool l_bFound = false;
	bool l_bAbort = false;

	if (strcmp(p_Node->Value(), "configurations") != 0)
	{
		throw TEXT("Invalid configuration file, node name not supported, expected 'configurations'.");
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

			ApplicationLog.Write( TEXT("Reading configuration node with LCID:"), l_Config_LCID);

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
					ApplicationLog.Write( TEXT("Loading reference configuration."));

					// Matthew Sheets - 2007-09-24: Load the reference config file and process recursively
					TiXmlDocument l_RefDocument;
					installerSetting l_RefSetting;

					if (LoadReferenceConfigNode(l_Node_configuration, l_RefDocument, &dlg))
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
					ApplicationLog.Write( TEXT("Loading install configuration."));
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
					throw TEXT("Invalid configuration file, configuration type not supported.");

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
		throw TEXT("System not supported or invalid configuration, no valid 'configuration' node found.");
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
	ApplicationLog.Write(TEXT("Calling CreateFile(GENERIC_READ) method."), p_FileName);

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

	ApplicationLog.Write(TEXT("Calling XmlDocument::Parse method."));

	document.Parse(l_Buffer);
	if (document.Error())
	{
		ApplicationLog.Write(TEXT("Parsing error: "), DVLib::string2Tstring(document.ErrorDesc()).data() );

		return false;
	}

	delete [] l_Buffer;

	ApplicationLog.Write(TEXT("Parse OK."));

	return true;
}

void LoadConfigFromFile(const CString & p_FileName, TiXmlDocument & p_Document)
{
	//I don't use the default LoadFrom file because is not Unicode
	bool l_ret = LoadDocumentFromFile(p_FileName, p_Document);
	if (l_ret==false)
	{
		ApplicationLog.Write(TEXT("Failed to load configuration file."));

		throw TEXT("Invalid configuration file, failed to parse XML elements.");
	}
}

void LoadConfigFromResource(HMODULE p_Module, TiXmlDocument & p_Document)
{
	ApplicationLog.Write( TEXT("Loading configuration from resource ...") );

	HRSRC l_res = FindResource(p_Module, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
	if (l_res == NULL)
		throw TEXT("Resource RES_CONFIGURATION not found.");
	HGLOBAL l_hRes = LoadResource(p_Module, l_res);
	if (l_hRes == NULL)
		throw TEXT("Failed to load resource RES_CONFIGURATION.");
	LPVOID l_buffer = LockResource(l_hRes);
	if (l_buffer == NULL)
		throw TEXT("Failed to lock resource RES_CONFIGURATION.");
	DWORD l_size = SizeofResource(p_Module, l_res);
	char * l_bufferXml = new char[l_size+1];
	memset(l_bufferXml,0,l_size+1);
	memcpy(l_bufferXml, l_buffer, l_size);
	
	p_Document.Parse(l_bufferXml);
	
	if (p_Document.Error())
	{
		ApplicationLog.Write( TEXT("Failed parsing xml configuration from resource") );
		throw TEXT("Resource RES_CONFIGURATION is not a valid xml.");
	}

	ApplicationLog.Write( TEXT("Parse xml configuration from resource OK") );

	delete [] l_bufferXml;
}

HBITMAP LoadBannerFromResource(HMODULE p_Module)
{
	try
	{
		//leggo la risorsa
		HRSRC l_res = FindResource(p_Module, TEXT("RES_BANNER"), TEXT("CUSTOM"));
		if (l_res == NULL)
			throw -1;
		HGLOBAL l_hRes = LoadResource(p_Module, l_res);
		if (l_hRes == NULL)
			throw -1;
		DWORD l_size = SizeofResource(p_Module, l_res);

		LPVOID l_buffer = LockResource(l_hRes);
		if (l_buffer == NULL)
			throw -1;

		return DVLib::LoadBitmapFromBuffer(l_buffer, l_size);
	/*	
		// n.B. Questo pezzo di codice usava GDI+ e quindi non andava bene su sistemi operativi precedenti a Win XP

		HGLOBAL l_hGlobal = GlobalAlloc(GMEM_MOVEABLE, l_size);
		if (l_hGlobal==NULL)
			throw -1;
		LPVOID l_gBuffer = GlobalLock(l_hGlobal);
		CopyMemory(l_gBuffer, l_buffer, l_size);
		GlobalUnlock(l_hGlobal);

		CComPtr<IStream> l_pStream;
		HRESULT l_hrRet = CreateStreamOnHGlobal(l_hGlobal, FALSE, &l_pStream);
		if (FAILED(l_hrRet))
			throw -1;

		CImage l_Image;
		l_hrRet = l_Image.Load(l_pStream);
		if (FAILED(l_hrRet))
			throw -1;

		l_pStream.Release();
		//TODO controllare se è possibile liberare anche HGLOBAL - GlobalFree(l_hGlobal)
		return l_Image.Detach();
		*/
	}
	catch(...)
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

void FreeComponent(component * c)
{
	if (c != NULL)
	{
		for (size_t j = 0; j < c->installedchecks.size(); j++)
		{
			installedcheck * ic = c->installedchecks[j];
			c->installedchecks[j] = NULL;
			if (ic != NULL)
				delete ic;
		}
		delete c;
	}
}
