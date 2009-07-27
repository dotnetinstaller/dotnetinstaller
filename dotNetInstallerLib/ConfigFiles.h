#pragma once
#include "Configurations.h"
#include "ConfigFile.h"

class ConfigFiles : public Configurations
{
protected:
    ConfigFile config;
private:
	static const int max_levels = 10;
	InstallUILevel saved_ui_level;
	std::vector<ConfigurationPtr> DownloadReferenceConfigurations(
		const std::vector<ConfigurationPtr>&, int level = 0);
protected:
	virtual bool OnLoad() = 0;
	virtual bool OnVersionError(const std::wstring& version, const std::wstring& filename) = 0;
	virtual bool OnDownload(const ConfigurationPtr& config) = 0;
	virtual bool OnRunConfiguration(const ConfigurationPtr& configuration) = 0;
public:
	ConfigFiles();
	void SaveAppState();
	void RestoreAppState();
	void Load();
	void Run();
};
