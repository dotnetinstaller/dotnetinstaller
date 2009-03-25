#pragma once

#include "InstallerSetting.h"
#include "DownloadDialogSupport.h"
#include "InstallerTypes.h"

class ConfigFile
{
private:
    LcidType m_lcidtype;
    TiXmlDocument m_XmlDocument;
	InstallerSetting m_Setting;
public:
    ConfigFile();
    void Load();
private:
    void LoadXmlSettings();
    bool LoadReferenceConfigNode(TiXmlElement * p_Node, CWnd * p_Parent);
    void LoadConfigFile(const CString & p_FileName, CWnd * p_Parent);
    void LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DVLib::DownloadGroupConfiguration & p_Configuration);
    void LoadInstallConfigNode(TiXmlElement * p_Node);
    void LoadConfigsNode(TiXmlElement * p_Node, bool p_Caller_Has_Additional_Config);
    void SaveAppState(configSetting & p_Config);
    void RestoreAppState(configSetting & p_Config);
    bool CheckConfigFilter(const CString & p_Config_LCID, const CString & p_os_filter_greater, const CString & p_os_filter_smaller, const CString & p_processor_architecture_filter);
    bool LoadDocumentFromFile(const CString & p_FileName);
    void LoadConfigFromFile(const CString & p_FileName);
    void LoadConfigFromResource(HMODULE p_Module);
    void ProcessSilentInstall(LPCSTR value);
    void ProcessLcidType(LPCSTR value);
};
