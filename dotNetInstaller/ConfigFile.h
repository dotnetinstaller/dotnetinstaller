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

void LoadReferenceConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting, CWnd * p_Parent);

void LoadConfigNode(TiXmlElement * p_Node, installerSetting & p_Setting, CWnd * p_Parent);

bool LoadDocumentFromFile(const CString & p_FileName, TiXmlDocument * document);

void LoadConfigFile(const CString & p_FileName, installerSetting & p_Setting, CWnd * p_Parent);

HBITMAP LoadBannerFromResource(HMODULE p_Module);

void LoadConfigFromResource(HMODULE p_Module, installerSetting & p_Setting, CWnd * p_Parent);

void FreeComponent(component * component);
