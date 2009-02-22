#include "ProcessorIdentifier.h"

namespace DVLib
{
	struct TypeToPROCESSOR_ARCHITECTURE
	{
		LPCWSTR p_Type;
		WORD w_ProcessorArchitecture;
	};

	static const TypeToPROCESSOR_ARCHITECTURE types[] = {
		{ L"x86", PROCESSOR_ARCHITECTURE_INTEL },
		{ L"mips", PROCESSOR_ARCHITECTURE_MIPS },
		{ L"alpha", PROCESSOR_ARCHITECTURE_ALPHA },
		{ L"ppc", PROCESSOR_ARCHITECTURE_PPC },
		{ L"shx", PROCESSOR_ARCHITECTURE_SHX },
		{ L"arm", PROCESSOR_ARCHITECTURE_ARM },
		{ L"ia64", PROCESSOR_ARCHITECTURE_IA64 },
		{ L"alpha64", PROCESSOR_ARCHITECTURE_ALPHA64 },
		{ L"msil", PROCESSOR_ARCHITECTURE_MSIL },
		{ L"x64", PROCESSOR_ARCHITECTURE_AMD64 },
		{ L"ia32onwin64", PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 }
	};

	// finds what the numerical representation of the processor architecture passed to the function
	WORD GetProcessorArchitecture(const std::wstring &p_TypePA)
	{
		for(int i = 0; i < ARRAYSIZE(types); i++)
		{
			if(p_TypePA == types[i].p_Type)
				return types[i].w_ProcessorArchitecture;
		}

		return PROCESSOR_ARCHITECTURE_UNKNOWN;
	}

    typedef BOOL (WINAPI * LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
    typedef void (WINAPI * LPFN_GETSYSTEMINFO)(LPSYSTEM_INFO);

    BOOL IsWow64()
    {
        BOOL bIsWow64 = FALSE;

        LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
            GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
      
        if (NULL != fnIsWow64Process)
        {
            fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
        }

        return bIsWow64;
    }

    void GetNativeSystemInfo(LPSYSTEM_INFO p)
    {
        LPFN_GETSYSTEMINFO pGetNativeSystemInfo = (LPFN_GETSYSTEMINFO) GetProcAddress(
            GetModuleHandle(TEXT("kernel32.dll")), 
            "GetNativeSystemInfo");

        if (NULL != pGetNativeSystemInfo)
        {
            pGetNativeSystemInfo(p);
        }
    }

	// gets the processor architecture of the current machine
	WORD GetProcessorArchitecture()
	{
        SYSTEM_INFO info = {0};
        GetSystemInfo(&info);

        if (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
        {
            if (IsWow64())
            {
                GetNativeSystemInfo(& info);
            }
        }

        return info.wProcessorArchitecture;
	}
	
	//compares the list of include and excluded architectures to see if they match the current machine's architecture
	bool IsProcessorArchitecture(const CString & p_FilterPA)
	{
		if (p_FilterPA.GetLength() <= 0)
			return true;

		WORD l_id = GetProcessorArchitecture();
		WORD l_filterId;

		bool l_bIsProcessorArchitecture = false;

		stlvectorstring l_ArrayPa;
		split_string((LPCTSTR)p_FilterPA, ',', l_ArrayPa);

		for (size_t i = 0; i < l_ArrayPa.size(); i++)
		{
			if (l_ArrayPa[i].size() > 0)
			{
				stlstring l_CheckNot = l_ArrayPa[i];
				stlstring l_PA;
				bool l_bNot;
				if ( _tcscmp(TEXT("!"), l_CheckNot.substr(0,1).data() ) == 0  )
				{
					l_PA = l_ArrayPa[i].substr(1, l_ArrayPa[i].size()-1);
					l_bNot = true;
				}
				else
				{
					l_PA = l_ArrayPa[i];
					l_bNot = false;
				}

				l_filterId = GetProcessorArchitecture(l_PA);

				if ( l_filterId == PROCESSOR_ARCHITECTURE_UNKNOWN )
					throw -1;

				if (l_bNot)
				{
					if (l_id == l_filterId)
					{
						l_bIsProcessorArchitecture = false;
						break;
					}
					else
						l_bIsProcessorArchitecture = true;
				}
				else
				{
					if (l_id == l_filterId)
						l_bIsProcessorArchitecture = true;
					else
						l_bIsProcessorArchitecture = l_bIsProcessorArchitecture;
				}
			}
			else
				l_bIsProcessorArchitecture = l_bIsProcessorArchitecture;
		}

		return l_bIsProcessorArchitecture;
	}

    CString GetProcessorArchitectureString()
    {
		WORD pa = GetProcessorArchitecture();

        for (int i = 0; i < ARRAYSIZE(types); i++)
        {
			if(pa == types[i].w_ProcessorArchitecture)
				return types[i].p_Type;
        }

        return "";
    }
}
