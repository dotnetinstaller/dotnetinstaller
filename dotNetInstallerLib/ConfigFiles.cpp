#include "StdAfx.h"
#include "ConfigFiles.h"
#include "ReferenceConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include <Version/Version.h>

ConfigFiles::ConfigFiles()
{
}

std::vector<ConfigurationPtr> ConfigFiles::DownloadReferenceConfigurations(
	LCID oslcid, const std::vector<ConfigurationPtr>& configurations, int level)
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
			ReferenceConfiguration * p = reinterpret_cast<ReferenceConfiguration *>(get(configurations[i]));
			LOG(L"Downloading reference configuration to '" << p->filename << L"'");
			if (! OnDownload(configurations[i]))
			{
				p->Exec();
			}

			ConfigFile downloadedconfig;
			downloadedconfig.LoadFile(p->filename);

			if (downloadedconfig.schema.version != TEXT(VERSION_VALUE))
			{
				if (OnVersionError(downloadedconfig.schema.version, p->filename))
				{
					THROW_EX(L"Downloaded configuration " << p->filename << L" version " 
						<< downloadedconfig.schema.version.c_str() << L" does not match bootstrapper version " 
						<< TEXT(VERSION_VALUE));
				}
			}

			std::vector<ConfigurationPtr> refs = DownloadReferenceConfigurations(
				oslcid, downloadedconfig.GetSupportedConfigurations(oslcid, InstallerSession::Instance->sequence), level + 1);
			result.insert(result.end(), refs.begin(), refs.end());
		}
		else
		{
			result.push_back(configurations[i]);
		}
	}
	return result;
}

void ConfigFiles::Load()
{
	if (! OnLoad())
	{
		std::wstring configfile = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), TEXT("configuration.xml"));
		CHECK_BOOL(DVLib::FileExists(configfile),
			L"Missing '" << configfile << L"'");
		config.LoadFile(configfile);
	}

	if (config.schema.version != TEXT(VERSION_VALUE))
	{
		if (OnVersionError(config.schema.version, config.GetFilename()))
		{
			THROW_EX(L"Configuration version in '" << config.GetFilename() << L"' " << 
				config.schema.version << L" does not match bootstrapper version " 
				<< TEXT(VERSION_VALUE));
		}
	}

	LOG("Lcid type: " << DVLib::lcidtype2wstring(InstallerSession::Instance->lcidtype));
	InstallerSession::Instance->lcidtype = config.lcidtype;

	if (OnSelectLanguage())
	{
		// specific locale has been chosen
		LOG(L"Locale chosen: " << InstallerSession::Instance->languageid);
	}

	// download reference configurations
	std::vector<ConfigurationPtr> refs = DownloadReferenceConfigurations(
		InstallerSession::Instance->languageid, 
		config.GetSupportedConfigurations(InstallerSession::Instance->languageid, 
			InstallerSession::Instance->sequence));

	Configurations::insert(end(), refs.begin(), refs.end());

	// select the set of configurations appropriate for this run
	std::vector<ConfigurationPtr> supportedconfigurations = config.GetSupportedConfigurations(
		InstallerSession::Instance->languageid, InstallerSession::Instance->sequence);

	if (supportedconfigurations.size() == 0)
	{
		if (config.configuration_no_match_message.empty())
		{
			THROW_EX(L"No configuration matching locale and operating system found within " 
				<< config.size() << L" configuration(s)");
		}
		else
		{
			THROW_EX(DVLib::FormatMessage(const_cast<wchar_t *>(
				config.configuration_no_match_message.GetValue().c_str()), 
				DVLib::towstring(config.size()).c_str()));
		}
	}
}

void ConfigFiles::Run()
{
	// enable logging per configuration(s)
	if (InstallerLog::Instance->GetLogFile().empty())
		InstallerLog::Instance->SetLogFile(config.log_file);

	if (! InstallerLog::Instance->IsEnabled())
	{
		// if the log was not globally enabled, set enabled per configuration 
		// and log the dotNetInstaller header
		InstallerLog::Instance->SetEnabled(config.log_enabled);
		LOG(L"-------------------------------------------------------------------");
		LOG(L"dotNetInstaller (DNI), version " << TEXT(VERSION_VALUE));
		LOG(VERSION_LEGALCOPYRIGHT_VALUE);
		LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString());
		LOG(L"-------------------------------------------------------------------");
		LOG(L"Sequence: " << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
	}

	// set configuration install ui level per configuration
	InstallUILevelSetting::Instance->SetConfigLevel(config.uilevel);
	LOG(L"UI level: " << InstallUILevelSetting::ToString(InstallUILevelSetting::Instance->GetUILevel()));

	for (size_t i = 0; i < size(); i++)
	{
		if ((* this)[i]->type == configuration_install)
		{
			SaveAppState();

			if (! OnRunConfiguration((* this)[i]))
				break;
			
			RestoreAppState();
		}
		else
		{
			THROW_EX(L"Unexpected configuration type " << (* this)[i]->type);
		}
	}
}

void ConfigFiles::SaveAppState()
{
	saved_ui_level = InstallUILevelSetting::Instance->GetUILevel();
}

void ConfigFiles::RestoreAppState()
{
	InstallUILevelSetting::Instance->SetConfigLevel(saved_ui_level);
}
