#include "stdafx.h"
#include "ConfigFile.h"
#include "InstallerLog.h"

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
			p_Configuration.Components.Add(l_DownloadComp);

			ApplicationLog.Write( TEXT("--Readed download component :"), l_DownloadComp.SourceURL );
		}
	}

	if (p_Configuration.Components.GetCount() <= 0)
	{
		AfxMessageBox(TEXT("No download components found. downloads node is empty."), MB_OK|MB_ICONSTOP);
		throw -1;
	}
}

void LoadInstallConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting)
{
	DVLib::OperatingSystem l_CurrentOs = DVLib::GetOsVersion();

	ApplicationLog.Write( TEXT("Start reading configuration attributes") );

	p_Setting.cancel_caption = p_Node->AttributeT("cancel_caption").data();
	p_Setting.dialog_bitmap = ValidatePath(p_Node->AttributeT("dialog_bitmap").data());
	p_Setting.dialog_caption = p_Node->AttributeT("dialog_caption").data();
	p_Setting.dialog_message = p_Node->AttributeT("dialog_message").data();
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

	ApplicationLog.Write( TEXT("End reading configuration attributes") );

	//caricamento componenti
	p_Setting.components.clear();

	TiXmlElement * l_Node_components = p_Node->FirstChildElement("components");
	TiXmlNode * child = NULL;
	while ( (child = l_Node_components->IterateChildren(child)) != NULL)
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
			if ( DVLib::IsInRangedOs(l_CurrentOs, l_new_component->os_filter_greater, l_new_component->os_filter_smaller) 
				&& DVLib::IsOperatingSystemLCID(l_new_component->os_filter_lcid) )
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
	}//while l_Node_component != NULL
}

void LoadReferenceConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting, CWnd * p_Parent)
{
	TiXmlElement * l_NodeDownloadDialog = p_Node->FirstChildElement("downloaddialog");

	DVLib::DownloadGroupConfiguration l_DownloadConfig;
	LoadDownloadConfiguration(l_NodeDownloadDialog, l_DownloadConfig);

	if (RunDownloadDialog(l_DownloadConfig, p_Parent))
	{
		TiXmlElement * l_Node_configfile = p_Node->FirstChildElement("configfile");

		CString l_configfile_filename = ValidatePath(l_Node_configfile->AttributeT("filename").data());
		//CString l_configfile_banner = ValidatePath(l_Node_configfile->GetAttrValue("banner"));

		LoadConfigFile(l_configfile_filename, p_Setting, p_Parent);
	}
	else
	{
		throw -1;
	}
}

void LoadConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting, CWnd * p_Parent)
{
	bool l_bFound = false;
	if (strcmp(p_Node->Value(), "configurations") != 0)
		throw TEXT("Invalid configuration file, node name not supported, expected 'configurations'.");

	TiXmlNode * child = NULL;
	while( (child = p_Node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * l_Node_configuration = child->ToElement();
		if ( l_Node_configuration != NULL && 
			strcmp(l_Node_configuration->Value(),"configuration") == 0 )
		{
			CString l_Config_LCID = l_Node_configuration->AttributeT("lcid").data();

			ApplicationLog.Write( TEXT("Reading configuration node with LCID:"), l_Config_LCID);

			if (DVLib::IsOperatingSystemLCID(l_Config_LCID))
			{
				CString l_type = l_Node_configuration->AttributeT("type").data();
				if (l_type =="reference")
				{
					ApplicationLog.Write( TEXT("Loading reference configuration."));
					LoadReferenceConfigNode(l_Node_configuration, p_Setting, p_Parent);
				}
				else if (l_type =="install")
				{
					ApplicationLog.Write( TEXT("Loading install configuration."));
					LoadInstallConfigNode(l_Node_configuration, p_Setting);
				}
				else
					throw TEXT("Invalid configuration file, configuration type not supported.");

				l_bFound = true;
				break;
			}
			else
			{
				ApplicationLog.Write( TEXT("Configuration node skipped for the current LCID"));
			}
		}
	}

	if (l_bFound== false)
		throw TEXT("System not supported or invalid configuration, no valid 'configuration' node found.");
}

bool LoadDocumentFromFile(const CString & p_FileName, TiXmlDocument * document)
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

	document->Parse(l_Buffer);
	if (document->Error())
	{
		ApplicationLog.Write(TEXT("Parsing error: "), DVLib::string2Tstring(document->ErrorDesc()).data() );

		return false;
	}

	delete [] l_Buffer;

	ApplicationLog.Write(TEXT("Parse OK."));

	return true;
}

void LoadConfigFile(const CString & p_FileName, installerSetting & p_Setting, CWnd * p_Parent)
{
	TiXmlDocument document;
	//I don't use the default LoadFrom file because is not Unicode
	bool l_ret = LoadDocumentFromFile(p_FileName, &document);
	if (l_ret==false)
	{
		ApplicationLog.Write(TEXT("Failed to load configuration file."));

		throw TEXT("Invalid configuration file, failed to parse XML elements.");
	}

	LoadConfigNode(document.FirstChildElement(), p_Setting, p_Parent);
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

void LoadConfigFromResource(HMODULE p_Module, installerSetting & p_Setting, CWnd * p_Parent)
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
	
	TiXmlDocument document;
	document.Parse(l_bufferXml);
	
	if (document.Error())
	{
		ApplicationLog.Write( TEXT("Failed parsing xml configuration from resource") );
		throw TEXT("Resource RES_CONFIGURATION is not a valid xml.");
	}

	ApplicationLog.Write( TEXT("Parse xml configuration from resource OK") );

	LoadConfigNode(document.FirstChildElement(), p_Setting, p_Parent);

	delete [] l_bufferXml;
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
