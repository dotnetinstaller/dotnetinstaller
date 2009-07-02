#pragma once

#include "dotNetInstallerDlg.h"

class ConfigFile
{
private:
	DVLib::LcidType m_lcidtype;
    TiXmlDocument m_XmlDocument;
	InstallerSetting m_Setting;
	CString schema_generator;
	CString schema_version;
public:
    ConfigFile();
    int Load();
private:
    void LoadXmlSettings();
    bool LoadReferenceConfigNode(TiXmlElement * p_Node, CdotNetInstallerDlg * p_Parent);
    void LoadConfigFile(const CString& p_FileName, CdotNetInstallerDlg * p_Parent);
    void LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DownloadGroupConfiguration & p_Configuration);
    void LoadInstallConfigNode(TiXmlElement * p_Node);
    int LoadConfigsNode(TiXmlElement * p_Node, bool p_Caller_Has_Additional_Config);
    void SaveAppState(configSetting & p_Config);
    void RestoreAppState(configSetting & p_Config);
    bool CheckConfigFilter(const CString& p_Config_LCID, const CString& p_os_filter_greater, const CString& p_os_filter_smaller, const CString& p_processor_architecture_filter);
    bool LoadDocumentFromFile(const CString& p_FileName);
    void LoadConfigFromFile(const CString& p_FileName);
	bool HasConfigResource(HMODULE p_Module);
    void LoadConfigFromResource(HMODULE p_Module);
    void ProcessUILevel(InstallUILevel value);
    void ProcessLcidType(const CString& value);
	void LoadSchemaVersion(TiXmlElement * p_Node);
};
