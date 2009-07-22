#include "StdAfx.h"
#include "OsUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"
#include "PathUtil.h"
#include "FileUtil.h"
#include "RegistryUtil.h"

DVLib::OperatingSystem DVLib::GetOperatingSystemVersion()
{
	DVLib::OperatingSystem os = winNotSupported;
	OSVERSIONINFOEX osvi = { 0 };

	// use GetVersionEx, fallback on GetVersion when unavaialble
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if(! ::GetVersionEx(reinterpret_cast<LPOSVERSIONINFO>(& osvi)))
	{
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		CHECK_WIN32_BOOL(GetVersionEx(reinterpret_cast<LPOSVERSIONINFO>(& osvi)),
			L"GetVersionEx");
	}

    SYSTEM_INFO si = { 0 };
	::GetSystemInfo(& si);

	switch (osvi.dwPlatformId)
	{
		// Test for the Windows NT product family.
		case VER_PLATFORM_WIN32_NT:
			// Windows 7
			if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1 && osvi.wProductType == VER_NT_WORKSTATION)
			{
				os = win7;
			}
			// Windows Server 2008 R2
			else if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1 && osvi.wProductType != VER_NT_WORKSTATION)
			{
				os = winServer2008R2;
			}
			// Windows Server 2008
			else if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0 && osvi.wProductType != VER_NT_WORKSTATION)
			{
				os = winServer2008;
			}
			else if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0 && osvi.wProductType == VER_NT_WORKSTATION)
			{
				os = winVista;

				if (osvi.wServicePackMajor == 1) 
					os = winVistaSp1;
				else if (osvi.wServicePackMajor >= 2) 
					os = winVistaSp2;
			}
			// Windows Server 2003 versions
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && GetSystemMetrics(89 /* SM_SERVERR2 */) != 0)
			{
				os = winServer2003;

				if (osvi.wServicePackMajor == 1)
					os = winServer2003sp1;
				else if (osvi.wServicePackMajor >= 2)
					os = winServer2003sp2;
			}
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && GetSystemMetrics(89 /* SM_SERVERR2 */) == 0)
			{
				os = winServer2003R2;

				if (osvi.wServicePackMajor == 1)
					os = winServer2003R2sp1;
				else if (osvi.wServicePackMajor >= 2)
					os = winServer2003R2sp2;
			}
			// Windows XP 64 bit Professional
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && osvi.wProductType == VER_NT_WORKSTATION && si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			{
				os = winXP;

				if (osvi.wServicePackMajor == 1)
					os = winXPsp1;
				else if (osvi.wServicePackMajor == 2)
					os = winXPsp2;
				else if (osvi.wServicePackMajor >= 3)
					os = winXPsp3;
			}
			// Windows XP 32 bit versions
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
			{
				os = winXP;

				if (osvi.wServicePackMajor == 1)
					os = winXPsp1;
				else if (osvi.wServicePackMajor == 2)
					os = winXPsp2;
				else if (osvi.wServicePackMajor >= 3)
					os = winXPsp3;
			}
			// Windows 2000 versions
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
			{
				os = win2000;

				if (osvi.wServicePackMajor == 1)
					os = win2000sp1;
				else if (osvi.wServicePackMajor == 2)
					os = win2000sp2;
				else if (osvi.wServicePackMajor == 3)
					os = win2000sp3;
				else if (osvi.wServicePackMajor >= 4)
					os = win2000sp4;
			}
			// Windows NT versions
			else if ( osvi.dwMajorVersion == 4 )
			{
				os = winNT4;
				// check if Sp6a
				if(0 == _wcsicmp(osvi.szCSDVersion, L"Service Pack 6"))
				{
					// Test for SP6 versus SP6a.
					if (DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009"))
					{
						os = winNT4sp6a;
					}
					else // Windows NT 4.0 prior to SP6a
					{
						os = winNT4sp6;
					}
				}
			}

			break;
		// Test for the Windows 95 product family.
		case VER_PLATFORM_WIN32_WINDOWS:
			if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90)
			{
				os = winME;
			}
			else if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10)
			{
				os = win98;
				//test windows 98 se
				if ( osvi.szCSDVersion[1] == 'A' )
					os = win98se;
			}
			else if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
			{
				os = win95;
				//test Win95 osr2
				if ( osvi.szCSDVersion[1] == 'C' || osvi.szCSDVersion[1] == 'B' )
					os = win95osr2;
			} 
			break;
	}

	CHECK_BOOL(os != winNotSupported, 
		L"Unsupported operating system, major=" << osvi.dwMajorVersion 
			<< L", version=" << osvi.dwMinorVersion << L"." << osvi.dwMinorVersion
			<< L", sp=" << osvi.wServicePackMajor << L"." << osvi.wServicePackMinor
			<< L", type=" << osvi.wProductType);
	
	return os;
}

std::wstring DVLib::GetOperatingSystemVersionString()
{
	return os2wstring(GetOperatingSystemVersion());
}

bool DVLib::IsInOperatingSystemInRange(OperatingSystem os, const std::wstring& l, const std::wstring& r)
{
	long min = l.empty() ? winMin : DVLib::wstring2long(l);
	long max = r.empty() ? winMax : DVLib::wstring2long(r);
	return os > min && os < max;
}

LCID DVLib::GetOperatingSystemLCID(LcidType lcidtype)
{
	switch(lcidtype)
	{
	case LcidSystem:
		return ::GetSystemDefaultLCID();
	case LcidUser:
		return ::GetUserDefaultLCID();
	case LcidUserExe:
	default:
		// see http://support.microsoft.com/kb/q181604/
		std::wstring userexepath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"user.exe");
		DVLib::FileVersionInfo versioninfo = DVLib::GetFileVersionInfo(userexepath);
		return versioninfo.translation_info.wLanguage;
	}
}

// \todo: this should probably move to dotNetInstallerLib since lcid is dotNetInstaller-format-specific
bool DVLib::IsOperatingSystemLCID(LcidType lcidtype, const std::wstring& lcid)
{
	if (lcid.empty())
		return true;

	LCID pa = GetOperatingSystemLCID(lcidtype);
	std::vector<std::wstring> lcids = DVLib::split(lcid, L",");

	for (size_t i = 0; i < lcids.size(); i++)
	{
		if (lcids[i].empty())
			continue; // tolerate an empty value

		bool not = false;
		LCID lcid = 0;
		if (lcids[i][0] == L'!')
		{
			not = true;
			lcid = DVLib::wstring2long(lcids[i].substr(1));
		}
		else
		{
			lcid = DVLib::wstring2long(lcids[i]);
		}

		if (lcid == pa && ! not)
			return true;
		else if (lcid != pa && not)
			return true;
	}

	return false;
}

WORD DVLib::wstring2pa(const std::wstring& pa)
{
	for (int i = 0; i < ARRAYSIZE(DVLib::processor_architectures); i++)
	{
		if (pa == DVLib::processor_architectures[i].name)
		{
			return DVLib::processor_architectures[i].pa;
		}
	}

	THROW_EX("Invalid processor architecture: " << pa);
}

std::wstring DVLib::pa2wstring(WORD pa)
{
    for (int i = 0; i < ARRAYSIZE(DVLib::processor_architectures); i++)
    {
		if (pa == DVLib::processor_architectures[i].pa)
			return DVLib::processor_architectures[i].name;
    }

	THROW_EX("Invalid processor architecture: " << pa);
}

bool DVLib::IsWow64()
{
    BOOL bIsWow64 = FALSE;

	typedef BOOL (WINAPI * LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
    LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
  
    if (NULL != fnIsWow64Process)
    {
        fnIsWow64Process(GetCurrentProcess(), & bIsWow64);
    }

	return bIsWow64 ? true : false;
}

bool GetNativeSystemInfo(LPSYSTEM_INFO p)
{
	typedef void (WINAPI * LPFN_GETSYSTEMINFO)(LPSYSTEM_INFO);
    LPFN_GETSYSTEMINFO pGetNativeSystemInfo = (LPFN_GETSYSTEMINFO) GetProcAddress(
        GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");

    if (NULL == pGetNativeSystemInfo)
		return false;

	pGetNativeSystemInfo(p);
	return true;
}

WORD DVLib::GetProcessorArchitecture()
{
    SYSTEM_INFO info = {0};
	::GetSystemInfo(&info);

    if (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
    {
        if (IsWow64())
        {
            GetNativeSystemInfo(& info);
        }
    }

    return info.wProcessorArchitecture;
}
	
bool DVLib::IsProcessorArchitecture(WORD pa, const std::wstring& pa_list)
{
	if (pa_list.empty())
		return true;

	std::vector<std::wstring> pa_vector = DVLib::split(pa_list, L",");

	for (size_t i = 0; i < pa_vector.size(); i++)
	{
		// tolerate blanks
		if (pa_vector[i].empty())
			continue;

		bool not = false;
		std::wstring pa_s;
		if (pa_vector[i][0] == L'!')
		{
			not = true;
			pa_s = pa_vector[i].substr(1);
		}
		else
		{
			pa_s = pa_vector[i];
		}

		WORD pa_c = wstring2pa(pa_s);
		if (not && pa_c == pa)
			return false;
		else if (! not && pa_c == pa)
			return true;
	}

	return false;
}

void DVLib::ExitWindowsSystem(DWORD ulFlags, DWORD ulReason)
{
    HANDLE hprocess = NULL; // handle to process token 
	TOKEN_PRIVILEGES tkp = { 0 }; // pointer to token structure     
	
    // get the current process token handle so we can get shutdown privilege         
	CHECK_WIN32_BOOL(::OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hprocess),
		L"OpenProcessToken");

	auto_handle hprocess_ptr(hprocess);

	// get the LUID for shutdown privilege         
	CHECK_WIN32_BOOL(::LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, & tkp.Privileges[0].Luid),
		L"LookupPrivilegeValue(SE_SHUTDOWN_NAME)"); 
         
	tkp.PrivilegeCount = 1;  // one privilege to set    
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
         
	// set shutdown privilege for this process
	CHECK_WIN32_BOOL(::AdjustTokenPrivileges(hprocess, FALSE, & tkp, 0, NULL, 0),
		L"AdjustTokenPrivileges");

	CHECK_WIN32_BOOL(::ExitWindowsEx(ulFlags, ulReason),
		L"ExitWindowsEx");
}


DVLib::LcidType DVLib::wstring2lcidtype(const std::wstring& name, LcidType defaultvalue)
{
	if (name.empty()) 
	{
		return defaultvalue;
	}

	for (int i = 0; i < ARRAYSIZE(LcidType2wstringMap); i++)
	{
		if (LcidType2wstringMap[i].name == name)
			return LcidType2wstringMap[i].lcidtype;
	}

	THROW_EX(L"Invalid LCID type: " << name);
}

std::wstring DVLib::lcidtype2wstring(LcidType lcidtype)
{
	for (int i = 0; i < ARRAYSIZE(LcidType2wstringMap); i++)
	{
		if (LcidType2wstringMap[i].lcidtype == lcidtype)
			return LcidType2wstringMap[i].name;
	}

	THROW_EX(L"Invalid LCID type: " << lcidtype);
}

std::wstring DVLib::os2wstring(OperatingSystem os)
{
	for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
	{
		if (Os2StringMap[i].os == os)
		{
			return Os2StringMap[i].name;
		}
	}

	THROW_EX(L"Unsupported operating system, os=" << os);
}