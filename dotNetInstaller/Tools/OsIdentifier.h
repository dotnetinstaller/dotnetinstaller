
#pragma once

#include <windows.h>
#include <stdio.h>
#include "split.h"
#include "File.h"

namespace DVLib
{
    enum LcidType
    {
        LcidUserExe = 0, // System32\user.exe lcid
        LcidSystem, // GetSystemDefaultLCID
        LcidUser // GetUserDefaultLCID
    };

	enum OperatingSystem
	{
		winNotValid = 0,

		win95 = 5,
		win95osr2 = 10,

		win98 = 15,
		win98se = 20,

		winME = 25,

		winNT4 = 30,
		winNT4sp6 = 35,
		winNT4sp6a = 40,

		win2000 = 45,
		win2000sp1 = 50,
		win2000sp2 = 55,
		win2000sp3 = 60,
		win2000sp4 = 65, //or Later

		winXP = 75,
		winXPsp1 = 80, 
		winXPsp2 = 82,
		winXPsp3 = 84, //or Later

		winServer2003 = 90,
		winServer2003sp1 = 92,
		winServer2003sp2 = 94, //or Later

		winVista = 100,
		winVistaSp1 = 102, 

		winServer2008 = 110, //or Later

		winLater = 200
	};

	inline OperatingSystem GetOsVersion()
	{
		OperatingSystem l_Os;

		OSVERSIONINFOEX osvi;
		BOOL bOsVersionInfoEx;

		// Try calling GetVersionEx using the OSVERSIONINFOEX structure.
		// If that fails, try using the OSVERSIONINFO structure.
		ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
		if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
		{
			osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
			if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
				return winNotValid;
		}

		switch (osvi.dwPlatformId)
		{
			// Test for the Windows NT product family.
			case VER_PLATFORM_WIN32_NT:

				// Windows Vista 
				if ( (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion > 0) || 
					osvi.dwMajorVersion > 6)
				{
					l_Os = winLater; // Windows version later than what this program is able to test for
				}
				// Windows Server 2008
				else if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0 && osvi.wProductType == 3)
				{
					l_Os = winServer2008;
				}
				else if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0 && osvi.wProductType == 1)
				{
					l_Os = winVista;

					if (osvi.wServicePackMajor >= 1)
						l_Os = winVistaSp1;
				}
				// Windows Server 2003 versions
				else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && osvi.wProductType == 3)
				{
					l_Os = winServer2003;

					if (osvi.wServicePackMajor >= 2)
						l_Os = winServer2003sp2;
					else if (osvi.wServicePackMajor == 1)
						l_Os = winServer2003sp1;
				}
				// Windows XP 64 bit versions
				else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 && osvi.wProductType == 1)
				{
					l_Os = winXP;

					if (osvi.wServicePackMajor == 2)
						l_Os = winXPsp2;
					else if (osvi.wServicePackMajor == 1)
						l_Os = winXPsp1;
				}
				// Windows XP 32 bit versions
				else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
				{
					l_Os = winXP;

					if (osvi.wServicePackMajor >= 3)
						l_Os = winXPsp3;
					else if (osvi.wServicePackMajor == 2)
						l_Os = winXPsp2;
					else if (osvi.wServicePackMajor == 1)
						l_Os = winXPsp1;
				}
				// Windows 2000 versions
				else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
				{
					l_Os = win2000;

					if (osvi.wServicePackMajor >= 4)
						l_Os = win2000sp4;
					else if (osvi.wServicePackMajor == 3)
						l_Os = win2000sp3;
					else if (osvi.wServicePackMajor == 2)
						l_Os = win2000sp2;
					else if (osvi.wServicePackMajor == 1)
						l_Os = win2000sp1;

				}
				// Windows NT versions
				else if ( osvi.dwMajorVersion = 4 )
				{
					l_Os = winNT4;
					//check if Sp6a
					if(lstrcmpi( osvi.szCSDVersion, TEXT("Service Pack 6") ) == 0 )
					{
						HKEY hKey;
						LONG lRet;

						// Test for SP6 versus SP6a.
						lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
							TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009"),
							0, KEY_QUERY_VALUE, &hKey );

						if( lRet == ERROR_SUCCESS ) //sp6a
							l_Os = winNT4sp6a;
						else // Windows NT 4.0 prior to SP6a
							l_Os = winNT4sp6;

						RegCloseKey( hKey );
					}
				}
				else
				{
					l_Os = winNotValid;
				}

			break;

			// Test for the Windows 95 product family.
			case VER_PLATFORM_WIN32_WINDOWS:

				if ( (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion > 90) ||
					osvi.dwMajorVersion > 4) 
				{
					l_Os = winLater;
				}
				else if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90)
				{
					l_Os = winME;
				}
				else if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10)
				{
					l_Os = win98;
					//test windows 98 se
					if ( osvi.szCSDVersion[1] == 'A' )
						l_Os = win98se;
				}
				else if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
				{
					l_Os = win95;
					//test Win95 osr2
					if ( osvi.szCSDVersion[1] == 'C' || osvi.szCSDVersion[1] == 'B' )
						l_Os = win95osr2;
				} 
				else
				{
					l_Os = winNotValid;
				}
			break;

		case VER_PLATFORM_WIN32s:

			l_Os = winNotValid;

			break;
	}

	return l_Os; 
	}

	inline CString GetOsVersionString()
	{
		OperatingSystem l_os = GetOsVersion();

		switch(l_os)
		{
		case winNotValid:
			return TEXT("Not Valid Operating System");
		case win95:
			return TEXT("Windows 95");
		case win95osr2:
			return TEXT("Windows 95 osr2");
		case win98:
			return TEXT("Windows 98");
		case win98se:
			return TEXT("Windows 98 Second Edition");
		case winME:
			return TEXT("Windows ME");
		case winNT4:
			return TEXT("Windows NT 4");
		case winNT4sp6:
			return TEXT("Windows NT 4 Sp6");
		case winNT4sp6a:
			return TEXT("Windows NT 4 Sp6a");
		case win2000:
			return TEXT("Windows 2000");
		case win2000sp1:
			return TEXT("Windows 2000 Sp1");
		case win2000sp2:
			return TEXT("Windows 2000 Sp2");
		case win2000sp3:
			return TEXT("Windows 2000 Sp3");
		case win2000sp4:
			return TEXT("Windows 2000 Sp4");
		case winXP:
			return TEXT("Windows XP");
		case winXPsp1:
			return TEXT("Windows XP Sp1");
		case winXPsp2:
			return TEXT("Windows XP Sp2");
		case winXPsp3:
			return TEXT("Windows XP Sp3");
		case winServer2003:
			return TEXT("Windows Server 2003");
		case winServer2003sp1:
			return TEXT("Windows Server 2003 Sp1");
		case winServer2003sp2:
			return TEXT("Windows Server 2003 Sp2");
		case winServer2008:
			return TEXT("Windows Server 2008");
		case winVista:
			return TEXT("Windows Vista");
		case winVistaSp1:
			return TEXT("Windows Vista Sp1");
		case winLater:
			return TEXT("Unknown Windows version");
		default:
			return TEXT("Error");
		}
	}

	// This function returns true if the current operating system is between the minor and major bounds (estremi esclusi)
	// p_CurrentOs = current operating sistem
	// p_GreaterThan = minor bound to check (if "" no check performed)
	// p_SmallerThan = major bound to check (if "" no check performed)
	// example: 
	//  IsInRangedOs(50, "49", "59") == true
	//  IsInRangedOs(50, "50", "59") == false
	//  IsInRangedOs(50, "49", "50") == false
	//  IsInRangedOs(50, "39", "49") == false
	//  IsInRangedOs(50, "49", "") == true
	//  IsInRangedOs(50, "", "55") == true
	// so to check for example an operating system with NT, 2000, XP or later use:
	//  IsInRangedOs(currentOS, "29", "")
	inline bool IsInRangedOs(OperatingSystem p_CurrentOs, const CString & p_GreaterThan, const CString & p_SmallerThan)
	{
		int l_GreaterThan = -10000;
		int l_SmallerThan = 10000;

		CString l_tmp;
		int l_retScanf;

		l_tmp = p_GreaterThan;
		l_tmp.Trim();
		if (l_tmp.GetLength() > 0)
		{
			l_retScanf = _stscanf(l_tmp, TEXT("%d"), &l_GreaterThan);
			if (l_retScanf != 1)
            {
                throw std::exception("IsInRangeOS failed");
            }
		}

		l_tmp = p_SmallerThan;
		l_tmp.Trim();
		if (l_tmp.GetLength() > 0)
		{
			l_retScanf = _stscanf(l_tmp, TEXT("%d"), &l_SmallerThan);
			if (l_retScanf != 1)
            {
                throw std::exception("IsInRangeOS failed");
            }
		}

		if (p_CurrentOs > l_GreaterThan && p_CurrentOs < l_SmallerThan)
			return true;
		else
			return false;
	}


	// Structure used to store enumerated languages and code pages.
	struct LANGANDCODEPAGE 
	{
	unsigned short wLanguage; //WORD
	unsigned short wCodePage; //WORD
	};

	inline LCID GetOperatingSystemLCID(LcidType lcidtype)
	{
        switch(lcidtype)
        {
        case LcidSystem:
            return ::GetSystemDefaultLCID();
        case LcidUser:
            return ::GetUserDefaultLCID();
        case LcidUserExe:
        default:
		    //per ulteriori informazioni vedere :
		    // http://support.microsoft.com/kb/q181604/
		    // Microsoft Knowledge Base Article - 181604
		    // HOWTO: Determine Default Language ID of Windows 95 or WinNT
		    //
		    //return GetSystemDefaultLCID(); NO Questa funzione restituisce la lingua impostata di default dal pannello di controllo

		    unsigned long dwVerHnd, dwVerInfoSize = 0;
		    void * l_bufferVersionInfo = NULL;
		    VS_FIXEDFILEINFO* lpvi = NULL;
		    unsigned int iLen = 0;

		    LANGANDCODEPAGE translation;

		    //SystemPath
		    TCHAR l_bufferSystem[MAX_PATH+1];
		    ZeroMemory(l_bufferSystem,MAX_PATH+1);
		    GetSystemDirectory(l_bufferSystem, MAX_PATH+1);
		    CString l_UserExePath = PathCombineCustom(l_bufferSystem, TEXT("user.exe"));

		    dwVerInfoSize = GetFileVersionInfoSize(l_UserExePath, &dwVerHnd);
		    if (dwVerInfoSize <= 0)
                throw std::exception("GetOperatingSystemLCID failed in GetFileVersionInfoSize");

		    l_bufferVersionInfo = malloc( dwVerInfoSize );
		    if (l_bufferVersionInfo == NULL)
                throw std::exception("GetOperatingSystemLCID failed in malloc");

		    BOOL l_ret = GetFileVersionInfo(l_UserExePath, dwVerHnd, dwVerInfoSize,l_bufferVersionInfo);
		    if (l_ret == FALSE)
                throw std::exception("GetOperatingSystemLCID failed in GetFileVersionInfo");

		    if (  VerQueryValue(l_bufferVersionInfo,TEXT("\\VarFileInfo\\Translation"),(void**)&lpvi, &iLen) 
			    && iLen >= sizeof(LANGANDCODEPAGE))
		    {
			    translation = *(LANGANDCODEPAGE*)lpvi;

			    free(l_bufferVersionInfo);
			    l_bufferVersionInfo = NULL;

			    return translation.wLanguage;
		    } 

            throw std::exception("GetOperatingSystemLCID failed in VerQueryValue");
        }
	}

	//determina se nella stringa passata in formato: 1033,1040,!2033 (in pratica i LCID separati da virgolo supportando anche il ! (not)
	// è presente il locale del sistema operativo
	inline bool IsOperatingSystemLCID(LcidType lcidtype, const CString & p_FilterLCID)
	{
		if (p_FilterLCID.GetLength() <= 0)
			return true;

		LCID l_id = GetOperatingSystemLCID(lcidtype);
		LCID l_filterId;

		bool l_bIsOperatingSystemLCID = false;

		stlvectorstring l_ArrayLcid;
		split_string((LPCTSTR)p_FilterLCID, ',', l_ArrayLcid);

		for (size_t i = 0; i < l_ArrayLcid.size(); i++)
		{
			if (l_ArrayLcid[i].size() > 0)
			{
				stlstring l_CheckNot = l_ArrayLcid[i];
				stlstring l_LCID;
				bool l_bNot;
				if ( _tcscmp(TEXT("!"), l_CheckNot.substr(0,1).data() ) == 0  )
				{
					l_LCID = l_ArrayLcid[i].substr(1, l_ArrayLcid[i].size()-1);
					l_bNot = true;
				}
				else
				{
					l_LCID = l_ArrayLcid[i];
					l_bNot = false;
				}

				l_filterId = -1;
				if ( _stscanf(l_LCID.data(), TEXT("%d"), &l_filterId)!= 1)
                    throw std::exception("IsOperatingSystemLCID failed");

				if (l_bNot)
				{
					if (l_id == l_filterId)
						l_bIsOperatingSystemLCID = l_bIsOperatingSystemLCID;
					else
						l_bIsOperatingSystemLCID = true;
				}
				else
				{
					if (l_id == l_filterId)
						l_bIsOperatingSystemLCID = true;
					else
						l_bIsOperatingSystemLCID = l_bIsOperatingSystemLCID;
				}
			}
			else
				l_bIsOperatingSystemLCID = l_bIsOperatingSystemLCID;
		}

		return l_bIsOperatingSystemLCID;
	}
}
 	  	 
