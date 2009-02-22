#pragma once

#include "ConfigFile.h"
#include "Tools/Cab/ExtractResourceT.hpp"
#include "Tools/Cab/CompressT.hpp"
#include "Tools/Guid.h"
#include "Tools/Cab/ExtractT.hpp"
#include "ThreadComponent.h"

struct ExtractCABComponent;

class ExtractCABProcessor : public Cabinet::CExtractT<ExtractCABProcessor> 
{
private:
    ExtractCABComponent * m_pComponent;
public:
    ExtractCABProcessor(ExtractCABComponent * pComponent);
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param);
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


