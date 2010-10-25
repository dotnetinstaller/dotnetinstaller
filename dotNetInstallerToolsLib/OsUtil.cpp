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
	DVLib::OperatingSystem os = winNone;
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

				if (osvi.wServicePackMajor >= 1)
					os = win7sp1;
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

				if (osvi.wServicePackMajor >= 2)
					os = winServer2008sp2;
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
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && 
				osvi.wProductType != VER_NT_WORKSTATION && GetSystemMetrics(89 /* SM_SERVERR2 */) == 0)
			{
				os = winServer2003;

				if (osvi.wServicePackMajor == 1)
					os = winServer2003sp1;
				else if (osvi.wServicePackMajor >= 2)
					os = winServer2003sp2;
			}
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && 
				osvi.wProductType != VER_NT_WORKSTATION && GetSystemMetrics(89 /* SM_SERVERR2 */) != 0)
			{
				os = winServer2003R2;

				if (osvi.wServicePackMajor == 1)
					os = winServer2003R2sp1;
				else if (osvi.wServicePackMajor >= 2)
					os = winServer2003R2sp2;
			}
			// Windows XP 64 bit Professional
			else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && 
				osvi.wProductType == VER_NT_WORKSTATION)
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

	CHECK_BOOL(os != winNone, 
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

bool DVLib::IsInOperatingSystemInRange(OperatingSystem os, const std::wstring& os_filter, OperatingSystem l, OperatingSystem r)
{
	if (! os_filter.empty())
	{
		if (l != winNone || r != winNone)
		{
			THROW_EX(L"Conflicting os_filter=" << os_filter << 
				L", os_filter_min=" << DVLib::os2wstring(l) << L", os_filter_max=" << DVLib::os2wstring(r));
		}

		return IsOperatingSystemID(os, os_filter);
	}
	else if (l != winNone && r != winNone)
	{
		return os >= l && os <= r;
	}
	else if (l != winNone)
	{
		return os >= l;
	}
	else if (r != winNone)
	{
		return os <= r;
	}
	
	return true;
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

bool DVLib::IsOperatingSystemLCID(LcidType lcidtype, const std::wstring& lcid)
{
	return IsOperatingSystemLCIDValue(GetOperatingSystemLCID(lcidtype), lcid);
}

// \todo: this should probably move to dotNetInstallerLib since lcid is dotNetInstaller-format-specific
bool DVLib::IsOperatingSystemLCIDValue(LCID lcid_in, const std::wstring& filter)
{
	if (filter.empty())
		return true;

	std::vector<std::wstring> lcids = DVLib::split(filter, L",");

	std::vector<LCID> lcid_or;
	std::vector<LCID> lcid_andnot;

	for (size_t i = 0; i < lcids.size(); i++)
	{
		if (lcids[i].empty())
			continue; // tolerate an empty value

		if (lcids[i][0] == L'!')
		{
			lcid_andnot.push_back(DVLib::wstring2long(lcids[i].substr(1)));
		}
		else
		{
			lcid_or.push_back(DVLib::wstring2long(lcids[i]));
		}
	}

	if (lcid_or.size() > 0 && lcid_andnot.size() >0)
	{
		THROW_EX(L"Ambiguous LCID filter: " << filter);
	}

	if (lcid_or.size() > 0)
	{
		for each(LCID lcid in lcid_or)
		{
			if (lcid == lcid_in)
				return true;
		}

		return false;
	} 
	else 
	{
		for each(LCID lcid in lcid_andnot)
		{
			if (lcid == lcid_in)
				return false;
		}

		return true;
	}
}

bool DVLib::IsOperatingSystemID(OperatingSystem os_in, const std::wstring& filter)
{
	if (filter.empty())
		return true;

	std::vector<std::wstring> oss = DVLib::split(filter, L",");

	std::vector<OperatingSystem> os_or;
	std::vector<OperatingSystem> os_andnot;

	for (size_t i = 0; i < oss.size(); i++)
	{
		if (oss[i].empty())
			continue; // tolerate an empty value

		if (oss[i][0] == L'!')
		{
			os_andnot.push_back(static_cast<OperatingSystem>(DVLib::oscode2os(oss[i].substr(1))));
		}
		else
		{
			os_or.push_back(static_cast<OperatingSystem>(DVLib::oscode2os(oss[i])));
		}
	}

	if (os_or.size() > 0 && os_andnot.size() >0)
	{
		THROW_EX(L"Ambiguous OS filter: " << filter);
	}

	if (os_or.size() > 0)
	{
		for each(OperatingSystem os in os_or)
		{
			if (os == os_in)
				return true;
		}

		return false;
	} 
	else 
	{
		for each(OperatingSystem os in os_andnot)
		{
			if (os == os_in)
				return false;
		}

		return true;
	}
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

DVLib::OperatingSystem DVLib::oscode2os(const std::wstring& oscode)
{
	if (oscode.empty())
		return winNone;

	for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
	{
		if (Os2StringMap[i].oscode == oscode)
		{
			return Os2StringMap[i].os;
		}
	}

	THROW_EX(L"Unsupported operating system code: " << oscode);
}

std::wstring DVLib::os2wstring(OperatingSystem os)
{
	if (os == winNone)
		return L"";

	for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
	{
		if (Os2StringMap[i].os == os)
		{
			return Os2StringMap[i].name;
		}
	}

	THROW_EX(L"Unsupported operating system, os=" << (int) os);
}

std::wstring DVLib::GetISOLocale(LCID lcid)
{
	std::wstringstream ss;
	ss << GetLocale(lcid, LOCALE_SISO639LANGNAME);
	ss << L"-";
	ss << GetLocale(lcid, LOCALE_SISO3166CTRYNAME);
	return ss.str();
}

std::wstring DVLib::GetLocale(LCID lcid, int format)
{
	int size = 0;
	CHECK_WIN32_BOOL((size = ::GetLocaleInfoW(lcid, format, NULL, 0)) > 0,
		L"GetLocaleInfoW");
	std::wstring locale;
	locale.resize(size);
	CHECK_WIN32_BOOL(::GetLocaleInfoW(lcid, format, & * locale.begin(), locale.size()) > 0,
		L"GetLocaleInfoW");
	locale.resize(size - 1);
	return locale;
}

