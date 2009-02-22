#pragma once

#include <afxtempl.h>
#include <xstring>
#include "Split.h"

namespace DVLib
{
	WORD GetProcessorArchitecture(const std::wstring &p_TypePA);
	WORD GetProcessorArchitecture();
	bool IsProcessorArchitecture(const CString & p_FilterPA);
    BOOL IsWow64();
    void GetNativeSystemInfo(LPSYSTEM_INFO p);
    CString GetProcessorArchitectureString();
}
