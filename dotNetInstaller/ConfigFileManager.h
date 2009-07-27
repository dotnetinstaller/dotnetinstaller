#pragma once

#include "dotNetInstallerDlg.h"

class ConfigFileManager : private ConfigFiles
{
private:
	CdotNetInstallerDlg dlg;
protected:
	bool OnVersionError(const std::wstring& version, const std::wstring& filename);
	bool OnDownload(const ConfigurationPtr& config);
	bool OnRunConfiguration(const ConfigurationPtr& configuration);
	bool OnLoad();
public:
	ConfigFileManager();
	void Load();
	int Run();
};
