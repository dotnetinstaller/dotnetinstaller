#include "stdafx.h"
#include "ConfigFile.h"
#include "DniMessageBox.h"
#include "dotNetInstallerDlg.h"
#include "InstallerCommandLineInfo.h"
#include "DownloadDialog.h"
#include <Version/Version.h>

ConfigFile::ConfigFile()
    : m_lcidtype(DVLib::LcidUserExe)
	, schema_generator(L"dotNetInstaller InstallerEditor")
	, schema_version(L"1")
{

}

int ConfigFile::Load()
{
    LoadXmlSettings();
	return LoadConfigsNode(m_XmlDocument.FirstChildElement(), false);
}

void ConfigFile::LoadDownloadConfiguration(TiXmlElement * node_downloaddialog, DownloadGroupConfiguration & configuration)
{
	configuration.caption = node_downloaddialog->AttributeW("dialog_caption");
	configuration.help_message = node_downloaddialog->AttributeW("dialog_message");
	configuration.downloading_message = node_downloaddialog->AttributeW("dialog_message_downloading");
	configuration.start_caption = node_downloaddialog->AttributeW("buttonstart_caption");
	configuration.cancel_caption = node_downloaddialog->AttributeW("buttoncancel_caption");
	configuration.auto_start = DVLib::string2bool(node_downloaddialog->Attribute("autostartdownload"), false);

	configuration.components.clear();

	TiXmlNode * child = NULL;
	while ( (child = node_downloaddialog->IterateChildren("download", child)) != NULL)
	{
		TiXmlElement * node_download = child->ToElement();
		if (node_download != NULL)
		{

			DownloadComponentInfo l_download_component;
			l_download_component.component_name = node_download->AttributeW("componentname");			
			l_download_component.source_url = m_Setting.ValidatePath(node_download->AttributeW("sourceurl"));
			l_download_component.source_path = m_Setting.ValidatePath(node_download->AttributeW("sourcepath"));
			l_download_component.destination_path = m_Setting.ValidatePath(node_download->AttributeW("destinationpath"));
			l_download_component.destination_filename = m_Setting.ValidatePath(node_download->AttributeW("destinationfilename"));
			l_download_component.always_download = DVLib::string2bool(node_download->Attribute("alwaysdownload"), true);			
			LOG(L"--Read download component: " << l_download_component.source_url);
			configuration.components.push_back(l_download_component);
		}
	}

	if (configuration.components.empty())
	{
		THROW_EX("Invalid configuration. Download dialog \"" << configuration.caption << L"\" requires at least one download file.");
	}
}

// Populate the m_Setting object
void ConfigFile::LoadInstallConfigNode(TiXmlElement * node)
{
	DVLib::OperatingSystem l_CurrentOs = DVLib::GetOperatingSystemVersion();

	LOG(L"Reading configuration attributes");

    // auto-enabled log options
    m_Setting.log_enabled = DVLib::string2bool(node->Attribute("log_enabled"), false);
    m_Setting.log_file = node->AttributeW("log_file");

    // enable logging if log is not enabled by a command line switch and enabled in the configuration
    if (! ApplicationLogInstance.IsEnableLog() && m_Setting.log_enabled)
    {
        ApplicationLogInstance.SetLogFile(m_Setting.ValidatePath(m_Setting.log_file));
        ApplicationLogInstance.EnableLog();
    }

    // defines where to extract files and auto-delete options
    m_Setting.cab_path = node->AttributeW("cab_path");
    m_Setting.cab_path_autodelete = DVLib::string2bool(node->Attribute("cab_path_autodelete"), true);
    // positions within the dialog
    m_Setting.dialog_position.FromString(node->AttributeW("dialog_position"));
    m_Setting.dialog_components_list_position.FromString(node->AttributeW("dialog_components_list_position"));
    m_Setting.dialog_message_position.FromString(node->AttributeW("dialog_message_position"));
    m_Setting.dialog_bitmap_position.FromString(node->AttributeW("dialog_bitmap_position"));
    m_Setting.dialog_otherinfo_link_position.FromString(node->AttributeW("dialog_otherinfo_link_position"));
    m_Setting.dialog_osinfo_position.FromString(node->AttributeW("dialog_osinfo_position"));
    m_Setting.dialog_install_button_position.FromString(node->AttributeW("dialog_install_button_position"));
    m_Setting.dialog_cancel_button_position.FromString(node->AttributeW("dialog_cancel_button_position"));
    m_Setting.dialog_skip_button_position.FromString(node->AttributeW("dialog_skip_button_position"));
    // other dialog options
	m_Setting.cancel_caption = node->AttributeW("cancel_caption");
	m_Setting.dialog_bitmap = m_Setting.ValidatePath(node->AttributeW("dialog_bitmap"));
	m_Setting.dialog_caption = node->AttributeW("dialog_caption");
	m_Setting.dialog_message = node->AttributeW("dialog_message");
	m_Setting.skip_caption = node->AttributeW("skip_caption");
	m_Setting.install_caption = node->AttributeW("install_caption");
	m_Setting.status_installed = node->AttributeW("status_installed");
	m_Setting.status_notinstalled = node->AttributeW("status_notinstalled");
	m_Setting.failed_exec_command_continue = node->AttributeW("failed_exec_command_continue");
	m_Setting.installation_completed = node->AttributeW("installation_completed");
	m_Setting.installation_none = node->AttributeW("installation_none");
	m_Setting.reboot_required = node->AttributeW("reboot_required");
    m_Setting.must_reboot_required = DVLib::string2bool(node->Attribute("must_reboot_required"), false);
	m_Setting.installing_component_wait = node->AttributeW("installing_component_wait");

	m_Setting.dialog_otherinfo_caption = node->AttributeW("dialog_otherinfo_caption");
	m_Setting.dialog_otherinfo_link = m_Setting.ValidatePath(node->AttributeW("dialog_otherinfo_link"));

	m_Setting.complete_command = m_Setting.ValidatePath(node->AttributeW("complete_command"));
	m_Setting.complete_command_silent = m_Setting.ValidatePath(node->AttributeW("complete_command_silent"));
	m_Setting.auto_close_if_installed = DVLib::string2bool(node->Attribute("auto_close_if_installed"), true);
    m_Setting.auto_close_on_error = DVLib::string2bool(node->Attribute("auto_close_on_error"), false);
    m_Setting.allow_continue_on_error = DVLib::string2bool(node->Attribute("allow_continue_on_error"), true);
    m_Setting.dialog_show_installed = DVLib::string2bool(node->Attribute("dialog_show_installed"), true);
    m_Setting.dialog_show_required = DVLib::string2bool(node->Attribute("dialog_show_required"), true);

	m_Setting.os_filter_greater = node->AttributeW("os_filter_greater");
	m_Setting.os_filter_smaller = node->AttributeW("os_filter_smaller");
	
	m_Setting.processor_architecture_filter = node->AttributeW("processor_architecture_filter");

    // message and caption to show during CAB extraction
    m_Setting.cab_dialog_caption = node->AttributeW("cab_dialog_caption");
    m_Setting.cab_dialog_message = node->AttributeW("cab_dialog_message");
    m_Setting.cab_cancelled_message = node->AttributeW("cab_cancelled_message");

	LOG(L"Read configuration attributes");

	m_Setting.ClearComponents();

	TiXmlNode * child = NULL;
	while ( (child = node->IterateChildren("component", child)) != NULL)
	{
		TiXmlElement * node_component = child->ToElement();
		if (node_component != NULL)
		{
			std::wstring l_comp_type = node_component->AttributeW("type");

			Component * l_new_component;

			if (l_comp_type == L"msi")
			{
				MsiComponent * l_msi_Comp = new MsiComponent();
				l_msi_Comp->package = m_Setting.ValidatePath(node_component->AttributeW("package"));
				l_msi_Comp->type = msi;
				l_msi_Comp->cmdparameters = m_Setting.ValidatePath(node_component->AttributeW("cmdparameters"));
				l_msi_Comp->cmdparameters_silent = m_Setting.ValidatePath(node_component->AttributeW("cmdparameters_silent"));
				l_msi_Comp->cmdparameters_basic = m_Setting.ValidatePath(node_component->AttributeW("cmdparameters_basic"));

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_msi_Comp->description);
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_msi_Comp->cmdparameters += TEXT(" ");
                    l_msi_Comp->cmdparameters += cmdline->second.c_str();
                    l_msi_Comp->cmdparameters_silent += TEXT(" ");
                    l_msi_Comp->cmdparameters_silent += cmdline->second.c_str();
                    l_msi_Comp->cmdparameters_basic += TEXT(" ");
                    l_msi_Comp->cmdparameters_basic += cmdline->second.c_str();
					
					LOG(L"--Additional component arguments: " << cmdline->second);
                }

				l_new_component = l_msi_Comp;

				LOG(L"--Read msi component: " << l_msi_Comp->package);
			}
			else if (l_comp_type == L"cmd")
			{
				CmdComponent * l_cmd_Comp = new CmdComponent();
				l_cmd_Comp->command = m_Setting.ValidatePath(node_component->AttributeW("command"));
                l_cmd_Comp->command_silent = m_Setting.ValidatePath(node_component->AttributeW("command_silent"));
				l_cmd_Comp->command_basic = m_Setting.ValidatePath(node_component->AttributeW("command_basic"));
				l_cmd_Comp->type = cmd;

                // additional command line parameters
                std::map<std::wstring, std::wstring>::iterator cmdline = commandLineInfo.m_componentCmdArgs.find(l_cmd_Comp->description);
                if (cmdline != commandLineInfo.m_componentCmdArgs.end())
                {
                    l_cmd_Comp->command += TEXT(" ");
                    l_cmd_Comp->command += cmdline->second.c_str();
                    l_cmd_Comp->command_silent += TEXT(" ");
                    l_cmd_Comp->command_silent += cmdline->second.c_str();
                    l_cmd_Comp->command_basic += TEXT(" ");
                    l_cmd_Comp->command_basic += cmdline->second.c_str();
                    
					LOG("--Additional component arguments: " << cmdline->second);
                }

				LOG(L"--Read command component: " << l_cmd_Comp->command);
				l_new_component = l_cmd_Comp;
			}
			else if (l_comp_type == L"openfile")
			{
				OpenFileComponent * l_openfile_Comp = new OpenFileComponent();
				l_openfile_Comp->file = m_Setting.ValidatePath(node_component->AttributeW("file"));
				l_openfile_Comp->type = openfile;
				LOG(L"--Read openfile component: " << l_openfile_Comp->file);
				l_new_component = l_openfile_Comp;
			}
			else
			{
				throw std::exception("Invalid configuration file, component type not supported");
			}

			l_new_component->description = node_component->AttributeW("description");
			l_new_component->status_installed = node_component->AttributeW("status_installed");
			l_new_component->os_filter_greater = node_component->AttributeW("os_filter_greater");
			l_new_component->os_filter_smaller = node_component->AttributeW("os_filter_smaller");
			l_new_component->os_filter_lcid = node_component->AttributeW("os_filter_lcid");
			l_new_component->installcompletemessage = node_component->AttributeW("installcompletemessage");
			l_new_component->mustreboot = DVLib::string2bool(node_component->Attribute("mustreboot"), false);
            l_new_component->reboot_required = node_component->AttributeW("reboot_required");
			l_new_component->must_reboot_required = DVLib::string2bool(node_component->Attribute("must_reboot_required"), false);
            l_new_component->allow_continue_on_error = DVLib::string2bool(node_component->Attribute("allow_continue_on_error"), true);
            l_new_component->failed_exec_command_continue = node_component->AttributeW("failed_exec_command_continue");
			l_new_component->required = DVLib::string2bool(node_component->Attribute("required"), true);
			l_new_component->processor_architecture_filter = node_component->AttributeW("processor_architecture_filter");

			// installed checks
			TiXmlNode * childInstalled = NULL;
			while ( (childInstalled = node_component->IterateChildren(childInstalled)) != NULL)
			{
				TiXmlElement * node = childInstalled->ToElement();
				if (node != NULL && strcmp(node->Value(), "installedcheck") == 0)
				{
                    InstalledCheck * l_new_installedcheck = InstalledCheck::LoadFromXml(node, m_Setting);
					l_new_component->installedchecks.push_back(l_new_installedcheck);
				}
				else if (node != NULL && strcmp(node->Value(), "installedcheckoperator") == 0)
				{
                    InstalledCheckOperator * l_new_installedcheckoperator = new InstalledCheckOperator();
                    l_new_installedcheckoperator->Load(node, m_Setting);
					l_new_component->installedchecks.push_back(l_new_installedcheckoperator);
				}
			}

			//
			// download dialog
			l_new_component->download = false; //default viene messo a falso e poi guardo se presente il nodo
			TiXmlElement * node_downloaddialog = node_component->FirstChildElement("downloaddialog");
			if (node_downloaddialog != NULL)
			{
			    LOG(L"---Loading DownloadDialog");
				LoadDownloadConfiguration(node_downloaddialog, l_new_component->DownloadDialogConfiguration);
				l_new_component->download = true;
			}

			//verifico che il componente sia supportato nel sistema operativo
			if ( CheckConfigFilter(l_new_component->os_filter_lcid, l_new_component->os_filter_greater, l_new_component->os_filter_smaller, l_new_component->processor_architecture_filter) )
			{
				m_Setting.AddComponent(l_new_component);
                LOG(L"--Loaded component: " << l_new_component->description);
			}
			else
			{
                LOG(L"--Skipped component: " << l_new_component->description);
				delete l_new_component;
			}

		} //if node_component != NULL
	}//while node_components != NULL

    // check that /ComponentArgs doesn't contain arguments for non-existant components
    std::map<std::wstring, std::wstring>::iterator arg = commandLineInfo.m_componentCmdArgs.begin();
    while(arg != commandLineInfo.m_componentCmdArgs.end())
    {
        if (! m_Setting.HasComponent(arg->first))
        {
            LOG(L"Warning, command line argument specified for a missing component: " << arg->first);
        }
        
        arg ++;
    }
}

bool ConfigFile::LoadReferenceConfigNode(TiXmlElement * node, CdotNetInstallerDlg * p_Parent)
{
	bool l_bSuccess = false;
	TiXmlElement * nodeDownloadDialog = node->FirstChildElement("downloaddialog");

	DownloadGroupConfiguration l_DownloadConfig;
	LoadDownloadConfiguration(nodeDownloadDialog, l_DownloadConfig);

    l_bSuccess = p_Parent->RunDownloadConfiguration(l_DownloadConfig);
	if (l_bSuccess)
	{
		TiXmlElement * node_configfile = node->FirstChildElement("configfile");

		std::wstring l_configfile_filename = m_Setting.ValidatePath(node_configfile->AttributeW("filename"));
		//std::wstring l_configfile_banner = m_Setting.ValidatePath(node_configfile->GetAttrValue("banner"));
		LoadConfigFromFile(l_configfile_filename);
	}

	return l_bSuccess;
}

int ConfigFile::LoadConfigsNode(TiXmlElement * node, bool p_Caller_Has_Additional_Config)
{
	if (strcmp(node->Value(), "configurations") != 0)
	{
		throw std::exception("Invalid configuration file, node name not supported, expected 'configurations'.");
	}

	// capture configuration settings
	// (configuration settings may be modified by child "reference" configurations)
	configSetting l_ConfigSetting;
	SaveAppState(l_ConfigSetting);

    ProcessUILevel(InstallUILevelSetting::ToUILevel(node->AttributeW("ui_level")));
    ProcessLcidType(node->AttributeW("lcid_type"));

	LoadSchemaVersion(node);

	CdotNetInstallerDlg dlg;
	bool l_bFound = false;
	bool l_bAbort = false;
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * node_configuration = child->ToElement();
		if (node_configuration != NULL && strcmp(node_configuration->Value(), "configuration") == 0)
		{
			std::wstring l_Config_LCID = node_configuration->AttributeW("lcid");
			std::wstring l_os_filter_greater = node_configuration->AttributeW("os_filter_greater");
			std::wstring l_os_filter_smaller = node_configuration->AttributeW("os_filter_smaller");
            std::wstring l_processor_architecture_filter = node_configuration->AttributeW("processor_architecture_filter");

			LOG(L"Reading configuration node: lcid=" << l_Config_LCID
				<< L", os_filter_greater=" << l_os_filter_greater
				<< L", os_filter_smaller=" << l_os_filter_smaller
				<< L", processor_architecture_filter=" << l_processor_architecture_filter);

			// OS Version configuration filter (in addition to LCID)
			if (CheckConfigFilter(l_Config_LCID, l_os_filter_greater, l_os_filter_smaller, l_processor_architecture_filter))
			{
				// peek ahead to determine if other config blocks exist that match the config filters
				bool l_additional_config_found = false;
				TiXmlElement * node_next_configuration = child->NextSiblingElement();
				while (node_next_configuration != NULL && (!l_additional_config_found))
				{
					if (strcmp(node_next_configuration->Value(), "configuration") == 0)
					{
						l_additional_config_found = CheckConfigFilter(
								node_next_configuration->AttributeW("lcid"),
								node_next_configuration->AttributeW("os_filter_greater"),
								node_next_configuration->AttributeW("os_filter_smaller"),
                                node_next_configuration->AttributeW("processor_architecture_filter"));
					}
					
					node_next_configuration = node_next_configuration->NextSiblingElement();
				}

				std::wstring l_type = node_configuration->AttributeW("type");
				if (l_type == L"reference")
				{
					LOG(L"Loading reference configuration");

					// load the reference config file and process recursively
                    ConfigFile ref_config_file;
					if (ref_config_file.LoadReferenceConfigNode(node_configuration, & dlg))
					{
						ref_config_file.LoadConfigsNode(ref_config_file.m_XmlDocument.FirstChildElement(), 
                            (l_additional_config_found | p_Caller_Has_Additional_Config));
					}
					else
					{
						l_bAbort = true;
					}
				}
				else if (l_type == L"install")
				{
					LOG(L"Loading install configuration");
					LoadInstallConfigNode(node_configuration);

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
				LOG("Skipped configuration");
			}
		}
	}

	// restore configuration settings
	// (configuration settings may have been modified by child "reference" configurations)
	RestoreAppState(l_ConfigSetting);

	if ( (!l_bFound) && (!l_bAbort) )
    {
        std::wstring configuration_no_match_message = node->AttributeW("configuration_no_match_message");
        if (configuration_no_match_message.empty()) configuration_no_match_message = L"System not supported or invalid configuration.";
		THROW_EX(configuration_no_match_message);
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
    const std::wstring & p_Config_LCID, 
    const std::wstring & p_os_filter_greater, 
    const std::wstring & p_os_filter_smaller,
    const std::wstring & p_processor_architecture_filter)
{
	return (DVLib::IsOperatingSystemLCID(m_lcidtype, p_Config_LCID) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), p_processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), p_os_filter_greater, p_os_filter_smaller));
}

void ConfigFile::LoadConfigFromFile(const std::wstring & filename)
{
	LOG(L"Loading configuration file: " << filename);
	std::vector<char> xml = DVLib::FileReadToEnd(filename);
	LOG(L"Parsing: " << DVLib::FormatBytesW(xml.size()));

	m_XmlDocument.Parse(& * xml.begin());
	CHECK_BOOL(! m_XmlDocument.Error(),
		L"Error reading \"" << filename << L"\": " << DVLib::string2wstring(m_XmlDocument.ErrorDesc()));

	LOG(L"Loaded configuration: " << filename);
}

void ConfigFile::LoadConfigFromResource(HMODULE h)
{
	LOG("Loading configuration from embedded resource");
	HRSRC res = ::FindResource(h, L"RES_CONFIGURATION", L"CUSTOM");
	CHECK_WIN32_BOOL(res != NULL, L"Invalid RES_CONFIGURATION resource");
	HGLOBAL hgl = ::LoadResource(h, res);
	CHECK_WIN32_BOOL(hgl != NULL, L"Missing RES_CONFIGURATION resource");
	DWORD size = SizeofResource(h, res);
	LPVOID buffer = LockResource(hgl);
	CHECK_WIN32_BOOL(buffer != NULL, L"Cannot lock RES_CONFIGURATION resource");
	std::vector<char> data;
	data.resize(size);
	memcpy(& * data.begin(), buffer, size);
	m_XmlDocument.Parse(& * data.begin());
	CHECK_BOOL(! m_XmlDocument.Error(),
		L"Error reading RES_CONFIGURATION: " << DVLib::string2wstring(m_XmlDocument.ErrorDesc()));

	LOG(L"Loaded configuration from embedded resource");
}

bool ConfigFile::HasConfigResource(HMODULE p_Module)
{
	HRSRC l_res = FindResource(p_Module, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
	return l_res != NULL;
}

void ConfigFile::LoadXmlSettings()
{
	std::wstring settings_file = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), TEXT("configuration.xml")).c_str();
	if (DVLib::FileExists(settings_file))
	{
		LoadConfigFromFile(settings_file);
	}
	else if (HasConfigResource(AfxGetApp()->m_hInstance))
	{
		LoadConfigFromResource(AfxGetApp()->m_hInstance);
	}
	else
	{
		LOG(L"Missing configuration.xml");
		throw std::exception("Missing configuration.xml");
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
void ConfigFile::ProcessLcidType(const std::wstring& lcidtype)
{
	if (lcidtype.empty())
		return;

    if (lcidtype == L"System") m_lcidtype = DVLib::LcidSystem;
    else if (lcidtype == L"User") m_lcidtype = DVLib::LcidUser;
    else if (lcidtype == L"UserExe") m_lcidtype = DVLib::LcidUserExe;
	else THROW_EX(L"Invalid LCID type: " << lcidtype);
}

void ConfigFile::LoadSchemaVersion(TiXmlElement * node)
{
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * l_Child = child->ToElement();
		if (l_Child != NULL && strcmp(l_Child->Value(), "schema") == 0)
		{
			schema_generator = l_Child->AttributeW("generator");
			LOG(L"Configuration generator: " << schema_generator);
			schema_version = l_Child->AttributeW("version");
			LOG(L"Generator version: " << schema_version);
		}
	}

	if (schema_version != TEXT(VERSION_VALUE))
	{
		std::wstringstream version_message;
		version_message << 
			L"Configuration version " << schema_version << L" does not match bootstrapper version.\r\n" \
			L"Open and re-save configuration.xml with editor version " << TEXT(VERSION_VALUE) << L".\r\n" \
			L"Continue with installation?";

		if (DniSilentMessageBox(version_message.str().c_str(), MB_YESNO|MB_ICONQUESTION, IDYES) != IDYES)
		{
			throw std::exception("Configuration file version mismatch, skipped.");
		}
	}
}

