#include "StdAfx.h"
#include "ConfigFileManager.h"
#include "InstallerWindow.h"
#include <Version/Version.h>

ConfigFileManager::ConfigFileManager()
	: m_pInstallerWindow(NULL)
{
}

ConfigFileManager::~ConfigFileManager()
{
	if (m_pInstallerWindow != NULL)
	{
		delete m_pInstallerWindow;
		m_pInstallerWindow = NULL;
	}
}

bool ConfigFileManager::OnVersionError(const std::wstring& version, const std::wstring& filename)
{
	std::wstring version_message = DVLib::FormatMessageW(
		L"Configuration %s version %s does not match bootstrapper version.\r\n" \
		L"Open and re-save configuration.xml with editor version %s.\r\n" \
		L"Continue with installation?", filename.c_str(), version.c_str(), TEXT(VERSION_VALUE));

	return (IDYES != DniMessageBox::Show(version_message, MB_YESNO|MB_ICONQUESTION, IDYES));
}

bool ConfigFileManager::OnDownload(const ConfigurationPtr& config)
{
	ASSERT(m_pInstallerWindow != NULL);
	ReferenceConfiguration * p = reinterpret_cast<ReferenceConfiguration *>(get(config));
	LOG(L"Downloading reference configuration to '" << p->filename << L"'");
	return m_pInstallerWindow->RunDownloadConfiguration(p->downloaddialog);
}

bool ConfigFileManager::OnRunConfiguration(const ConfigurationPtr& config)
{
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(config));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
	CreateInstallerWindow(p_configuration->dialog_caption);
	return m_pInstallerWindow->RunInstallConfiguration(config, config != (* this)[size() - 1]);
}

void ConfigFileManager::Load()
{
	ConfigFiles::Load();
}

bool ConfigFileManager::OnLoad()
{
	if (! InstallerCommandLineInfo::Instance->configFile.empty())
	{
		CHECK_BOOL(DVLib::FileExists(InstallerCommandLineInfo::Instance->configFile),
			L"Missing '" << InstallerCommandLineInfo::Instance->configFile << L"'");

		config.LoadFile(InstallerCommandLineInfo::Instance->configFile);
		return true;
	}
	else if (NULL != DVLib::ResourceExists(HtmlWindow::s_hinstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM")))
	{
		config.LoadResource(HtmlWindow::s_hinstance, TEXT("RES_CONFIGURATION"), TEXT("CUSTOM"));
		return true;
	}

	return false;
}

void ConfigFileManager::CreateInstallerWindow(const std::wstring& title)
{
	if (m_pInstallerWindow != NULL)
	{
		delete m_pInstallerWindow;
		m_pInstallerWindow = NULL;
	}

	MONITORINFO mi = { 0 };
	mi.cbSize = sizeof(mi);
	CHECK_WIN32_BOOL(GetMonitorInfo(MonitorFromWindow(NULL, MONITOR_DEFAULTTOPRIMARY), & mi),
		L"GetMonitorInfo");

	int cx = 640;
	int cy = 480;

	m_pInstallerWindow = new InstallerWindow(); // deletes itself
	m_pInstallerWindow->Create(
		(mi.rcWork.left + mi.rcWork.right) / 2 - cx / 2, 
		(mi.rcWork.top + mi.rcWork.bottom) / 2 - cy / 2, 
		cx, cy, title.c_str());

	CHECK_BOOL(m_pInstallerWindow->hwnd != NULL,
		L"InstallerWindow::Create");
}

void ConfigFileManager::Run()
{
	ConfigFiles::Run();
}

bool ConfigFileManager::OnSelectLanguage()
{
	if (InstallerCommandLineInfo::Instance->DisplayConfig())
		return false;

	if (config.show_language_selector && ! InstallUILevelSetting::Instance->IsSilent())
	{
		//TODO:

		//CLanguageSelectorDialog lsdlg(config);
		//switch(lsdlg.DoModal())
		//{
		//case IDOK:
		//	return true;
		//case IDCANCEL:
		//	THROW_EX(L"Language selection cancelled by user");
		//}
	}

	return false;
}

std::wstring ConfigFileManager::GetString() const
{
	return ConfigFiles::GetString();
}

std::vector<ConfigurationPtr> ConfigFileManager::DownloadReferenceConfigurations(
	LCID oslcid, const std::vector<ConfigurationPtr>& configs, int level)
{
	if (InstallerCommandLineInfo::Instance->DisplayConfig())
		return config; // return this configuration, all components

	return ConfigFiles::DownloadReferenceConfigurations(oslcid, configs, level);
}

