#pragma once

#include "dotNetInstallerDlg.h"

class ConfigFile
{
private:
	DVLib::LcidType m_lcidtype;
    TiXmlDocument m_XmlDocument;
	InstallerSetting m_Setting;
	std::wstring schema_generator;
	std::wstring schema_version;
public:
    ConfigFile();
    int Load();
private:
    void LoadXmlSettings();
    bool LoadReferenceConfigNode(TiXmlElement * node, CdotNetInstallerDlg * p_Parent);
    void LoadConfigFile(const std::wstring& filename, CdotNetInstallerDlg * p_Parent);
    void LoadDownloadConfiguration(TiXmlElement * node_downloaddialog, DownloadGroupConfiguration & p_Configuration);
    void LoadInstallConfigNode(TiXmlElement * node);
    int LoadConfigsNode(TiXmlElement * node, bool p_Caller_Has_Additional_Config);
    void SaveAppState(configSetting & p_Config);
    void RestoreAppState(configSetting & p_Config);
    bool CheckConfigFilter(const std::wstring& p_Config_LCID, const std::wstring& p_os_filter_greater, const std::wstring& p_os_filter_smaller, const std::wstring& p_processor_architecture_filter);
    void LoadConfigFromFile(const std::wstring& filename);
	bool HasConfigResource(HMODULE p_Module);
    void LoadConfigFromResource(HMODULE p_Module);
    void ProcessUILevel(InstallUILevel value);
    void ProcessLcidType(const std::wstring& value);
	void LoadSchemaVersion(TiXmlElement * node);
};
