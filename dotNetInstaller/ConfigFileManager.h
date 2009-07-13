#pragma once

class ConfigFileManager : public Configurations
{
private:
	InstallUILevel saved_ui_level;
public:
	// download reference configuratoins
	std::vector<ConfigurationPtr> DownloadReferenceConfigurations(const std::vector<ConfigurationPtr>&);
	ConfigFileManager();
	void SaveAppState();
	void RestoreAppState();
	void Load();
	void Run();
};
