#pragma once

class ConfigFileManager : public Configurations
{
private:
    ConfigFile config;
	static const int max_levels = 10;
	InstallUILevel saved_ui_level;
public:
	std::vector<ConfigurationPtr> DownloadReferenceConfigurations(
		const std::vector<ConfigurationPtr>&, int level = 0);
	ConfigFileManager();
	void SaveAppState();
	void RestoreAppState();
	void Load();
	int Run();
};
