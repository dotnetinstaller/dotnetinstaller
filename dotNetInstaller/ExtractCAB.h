#pragma once

#include "ConfigFile.h"

struct ExtractCABComponent;

class ExtractCABProcessor : public Cabinet::CExtractT<ExtractCABProcessor> 
{
private:
    ExtractCABComponent * m_pComponent;
public:
    ExtractCABProcessor(ExtractCABComponent * pComponent);
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param);
	void OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param);
};

struct ExtractCABComponent : public thread_component
{
    friend class ExtractCABProcessor;
public:
    ExtractCABComponent(InstallerSetting& settings);
	static int GetCabCount(HMODULE p_Module);
private:
    InstallerSetting& m_Settings;
	UINT ExecOnThread();
    void ExtractCab(HMODULE p_Module, Component * pComponent);
};


