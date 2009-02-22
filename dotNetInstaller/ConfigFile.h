#pragma once

#include "resource.h"
#include "tinyxml.h"
#include "InstallerTypes.h"
#include "DownloadDialogSupport.h"
#include "DownloadDialog.h"
#include "OsIdentifier.h"
#include "Image.h"
//#include <atlimage.h>

void LoadConfigFile(const CString & p_FileName, installerSetting & p_Setting, CWnd * p_Parent);

bool ConvBoolString(const char * p_BoolString);

void LoadDownloadConfiguration(TiXmlElement * p_Node_downloaddialog, DVLib::DownloadGroupConfiguration & p_Configuration);

void LoadInstallConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting);

bool LoadReferenceConfigNode(TiXmlElement * p_Node, TiXmlDocument & document, CWnd * p_Parent);

void LoadConfigsNode(TiXmlElement * p_Node, installerSetting & p_Setting, bool p_Caller_Has_Additional_Config);

void SaveAppState(configSetting & p_Config);

void RestoreAppState(configSetting & p_Config);

bool CheckConfigFilter(const CString & p_Config_LCID, const CString & p_os_filter_greater, const CString & p_os_filter_smaller, const CString & p_processor_architecture_filter);

bool LoadDocumentFromFile(const CString & p_FileName, TiXmlDocument & document);

void LoadConfigFromFile(const CString & p_FileName, TiXmlDocument & p_Document);

void LoadConfigFromResource(HMODULE p_Module, TiXmlDocument & p_Document);

HBITMAP LoadBannerFromResource(HMODULE p_Module);

bool LoadXmlSettings(TiXmlDocument & p_Document);

void FreeComponent(component * component);
