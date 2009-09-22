#pragma once

#include "dotNetInstallerDlg.h"
#include "LanguageSelectorDialog.h"

class ConfigFileManager : private ConfigFiles
{
private:
	CdotNetInstallerDlg dlg;
protected:
	bool OnVersionError(const std::wstring& version, const std::wstring& filename);
	bool OnDownload(const ConfigurationPtr& config);
	bool OnRunConfiguration(const ConfigurationPtr& configuration);
	bool OnLoad();
	bool OnSelectLanguage();
	std::vector<ConfigurationPtr> DownloadReferenceConfigurations(
		DWORD oslcid, const std::vector<ConfigurationPtr>&, int level);
public:
	ConfigFileManager();
	// load configurations
	void Load();
	// run the configurations
	int Run();
	// string representation of this configuration
	std::wstring GetString() const;
};

typedef shared_any<ConfigFileManager *, close_delete> ConfigFileManagerPtr;