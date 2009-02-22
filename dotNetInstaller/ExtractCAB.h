#pragma once

#include "ConfigFile.h"
#include "Tools/Cab/ExtractResourceT.hpp"
#include "Tools/Cab/CompressT.hpp"
#include "Tools/Guid.h"
#include "Tools/Cab/ExtractT.hpp"

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
    ExtractCABComponent(installerSetting& settings);
private:
    installerSetting& m_Settings;
	UINT ExecOnThread();
    void ExtractCab(HMODULE p_Module, component * pComponent);
};


