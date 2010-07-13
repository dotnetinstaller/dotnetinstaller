#pragma once

#include "InstallerWindow.h"

class ConfigFileManager : private ConfigFiles
{
private:
	InstallerWindow * m_pInstallerWindow;
protected:
	bool OnVersionError(const std::wstring& version, const std::wstring& filename);
	bool OnDownload(const ConfigurationPtr& config);
	bool OnRunConfiguration(const ConfigurationPtr& configuration);
	bool OnLoad();
	bool OnSelectLanguage();
	std::vector<ConfigurationPtr> DownloadReferenceConfigurations(
		LCID oslcid, const std::vector<ConfigurationPtr>&, int level);
public:
	ConfigFileManager();
	// load configurations
	void Load();
	// run the configurations
	int Run();
	// string representation of this configuration
	std::wstring GetString() const;
	// configuration iterators
	std::vector<ConfigurationPtr>::const_iterator begin() const { return Configurations::begin(); }
	std::vector<ConfigurationPtr>::const_iterator end() const { return Configurations::end(); }
};

typedef shared_any<ConfigFileManager *, close_delete> ConfigFileManagerPtr;