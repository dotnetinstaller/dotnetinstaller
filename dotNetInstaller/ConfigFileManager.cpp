#include "StdAfx.h"
#include "ConfigFileManager.h"
#include "dotNetInstallerDlg.h"

ConfigFileManager::ConfigFileManager()
{
}

std::vector<ConfigurationPtr> ConfigFileManager::DownloadReferenceConfigurations(const std::vector<ConfigurationPtr>& configurations)
{
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
			std::vector<ConfigurationPtr> refs = DownloadReferenceConfigurations(downloadedconfig.GetSupportedConfigurations());
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
	if (NULL != ::FindResource(AfxGetApp()->m_hInstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM")))
		config.LoadResource(AfxGetApp()->m_hInstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
	else if (DVLib::FileExists(configfile))
		config.LoadFile(configfile);
	else 
	{
		THROW_EX(L"Missing '" << configfile << L"'");
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
			if (! dlg.RunInstallConfiguration((* this)[i], i + 1 != size()))
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