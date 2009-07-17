#include "StdAfx.h"
#include "ConfigFileManager.h"
#include "dotNetInstallerDlg.h"
#include "DniMessageBox.h"
#include <Version/Version.h>

ConfigFileManager::ConfigFileManager()
{
}

std::vector<ConfigurationPtr> ConfigFileManager::DownloadReferenceConfigurations(
	const std::vector<ConfigurationPtr>& configurations, int level)
{
	if (level >= max_levels)
	{
		THROW_EX(L"Maximum nested reference configuration level of " << max_levels 
			<< L" reached. Do you have a circular reference?");
	}

	std::vector<ConfigurationPtr> result;
	for (size_t i = 0; i < configurations.size(); i++)
	{
		if (configurations[i]->type == configuration_reference)
		{
			CdotNetInstallerDlg dlg;
			ReferenceConfiguration * p = reinterpret_cast<ReferenceConfiguration *>(get(configurations[i]));
			LOG(L"Downloading reference configuration to '" << p->filename << L"'");
			dlg.RunDownloadConfiguration(* get(p->downloadconfiguration));
			ConfigFile downloadedconfig;
			downloadedconfig.LoadFile(p->filename);

			if (downloadedconfig.schema.version != TEXT(VERSION_VALUE))
			{
				std::wstring version_message = DVLib::FormatMessageW(
					L"Downloaded configuration %s version %s does not match bootstrapper version.\r\n" \
					L"Open and re-save configuration.xml with editor version %s.\r\n" \
					L"Continue with installation?", 
					p->filename.c_str(), downloadedconfig.schema.version.c_str(), TEXT(VERSION_VALUE));

				if (DniSilentMessageBox(version_message, MB_YESNO|MB_ICONQUESTION, IDYES) != IDYES)
				{
					THROW_EX(L"Downloaded configuration " << p->filename << L" version " 
						<< downloadedconfig.schema.version.c_str() << L" does not match bootstrapper version " 
						<< TEXT(VERSION_VALUE));
				}
			}

			std::vector<ConfigurationPtr> refs = DownloadReferenceConfigurations(
				downloadedconfig.GetSupportedConfigurations(), level + 1);
			result.insert(result.end(), refs.begin(), refs.end());
		}
		else
		{
			result.push_back(configurations[i]);
		}
	}
	return result;
}

void ConfigFileManager::Load()
{
	// load configuration
    ConfigFile config;
	std::wstring configfile = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), TEXT("configuration.xml"));
	if (NULL != DVLib::ResourceExists(AfxGetApp()->m_hInstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM")))
		config.LoadResource(AfxGetApp()->m_hInstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
	else if (DVLib::FileExists(configfile))
		config.LoadFile(configfile);
	else 
	{
		THROW_EX(L"Missing '" << configfile << L"'");
	}

	if (config.schema.version != TEXT(VERSION_VALUE))
	{
		std::wstring version_message = DVLib::FormatMessageW(
			L"Configuration version %s does not match bootstrapper version.\r\n" \
			L"Open and re-save configuration.xml with editor version %s.\r\n" \
			L"Continue with installation?", config.schema.version.c_str(), TEXT(VERSION_VALUE));

		if (DniSilentMessageBox(version_message, MB_YESNO|MB_ICONQUESTION, IDYES) != IDYES)
		{
			THROW_EX(L"Configuration version " << config.schema.version << L" does not match bootstrapper version " 
				<< TEXT(VERSION_VALUE));
		}
	}

	// donwload reference configurations
	std::vector<ConfigurationPtr> refs = DownloadReferenceConfigurations(config.GetSupportedConfigurations());
	Configurations::insert(end(), refs.begin(), refs.end());

	// select the set of configurations appropriate for this run
	std::vector<ConfigurationPtr> supportedconfigurations = config.GetSupportedConfigurations();
	if (supportedconfigurations.size() == 0)
	{
		THROW_EX(L"No configuration matching locale and operating system found within " << size() << L" configuration(s)");
	}
}

void ConfigFileManager::Run()
{
	CdotNetInstallerDlg dlg;
	for (size_t i = 0; i < size(); i++)
	{
		if ((* this)[i]->type == configuration_install)
		{
			SaveAppState();
			if (! dlg.RunInstallConfiguration(lcidtype, (* this)[i], i + 1 != size()))
				break;
			RestoreAppState();
		}
		else
		{
			THROW_EX(L"Unexpected configuration type " << (* this)[i]->type);
		}
	}
}

void ConfigFileManager::SaveAppState()
{
	saved_ui_level = CurrentInstallUILevel.GetUILevel();
}

void ConfigFileManager::RestoreAppState()
{
	if (saved_ui_level != InstallUILevelNotSet)
	{
		CurrentInstallUILevel.SetConfigLevel(saved_ui_level);
	}
	else
	{
		CurrentInstallUILevel.SetConfigLevel(InstallUILevelNotSet);
	}
}