#pragma once

#include "ErrorUtil.h"

namespace DVLib
{


	/*
	< 0 stringA less than stringB 
	0 stringA identical to stringB 
	> 0 stringA greater than stringB
	*/
	inline int stringVersionCompare(LPCTSTR p_StringA, LPCTSTR p_StringB)
	{
		int l_vA_1 = 0;
		int l_vA_2 = 0;
		int l_vA_3 = 0;
		int l_vA_4 = 0;
		_stscanf_s(p_StringA,TEXT("%d.%d.%d.%d"),&l_vA_1,&l_vA_2,&l_vA_3,&l_vA_4);

		int l_vB_1 = 0;
		int l_vB_2 = 0;
		int l_vB_3 = 0;
		int l_vB_4 = 0;
		_stscanf_s(p_StringB,TEXT("%d.%d.%d.%d"),&l_vB_1,&l_vB_2,&l_vB_3,&l_vB_4);

		if (l_vA_1 < l_vB_1)
			return -1;
		else if (l_vA_1 > l_vB_1)
			return 1;
		else
		{
			if (l_vA_2 < l_vB_2)
				return -1;
			else if (l_vA_2 > l_vB_2)
				return 1;
			else
			{
				if (l_vA_3 < l_vB_3)
					return -1;
				else if (l_vA_3 > l_vB_3)
					return 1;
				else
				{
					if (l_vA_4 < l_vB_4)
						return -1;
					else if (l_vA_4 > l_vB_4)
						return 1;
					else
					{
						return 0;
					}
				}
			}
		}

	}


	// This function gets the file version info structure
	inline HRESULT GetFileVersion (LPCTSTR filename, VS_FIXEDFILEINFO *pvsf) 
	{
		DWORD dwHandle;
		DWORD cchver = GetFileVersionInfoSize(filename,&dwHandle);
		if (cchver == 0) 
			return HRESULT_FROM_WIN32(::GetLastError());
		char* pver = new char[cchver];
		BOOL bret = GetFileVersionInfo(filename,dwHandle,cchver,pver);
		if (!bret) 
			return HRESULT_FROM_WIN32(::GetLastError());
		UINT uLen;
		void *pbuf;
		bret = VerQueryValue(pver,TEXT("\\"),&pbuf,&uLen);
		if (!bret) 
			return HRESULT_FROM_WIN32(::GetLastError());
		memcpy(pvsf,pbuf,sizeof(VS_FIXEDFILEINFO));
		delete[] pver;
		return S_OK;
	}

	inline CString GetFileVersionString(LPCTSTR filename)
	{
		VS_FIXEDFILEINFO l_Info;
		HRESULT l_hrRet = GetFileVersion(filename, &l_Info);
		if (l_hrRet != S_OK)
			return TEXT("0.0.0.0");

		WORD l_Maior = HIWORD(l_Info.dwFileVersionMS);
		WORD l_Minor = LOWORD(l_Info.dwFileVersionMS);
		WORD l_Build = HIWORD(l_Info.dwFileVersionLS);
		WORD l_Revision = LOWORD(l_Info.dwFileVersionLS);

		CString l_str;
		l_str.Format(TEXT("%d.%d.%d.%d"), l_Maior, l_Minor, l_Build, l_Revision);
		return l_str;
	}

	/*
	inline bool GetVersionOfFile(LPCTSTR lptstrFilename,DWORD * p_LessSignVal, DWORD * p_MoreSignVal)
	{
		BYTE * l_Data = NULL;

		DWORD l_tmp = 0;
		DWORD l_size = GetFileVersionInfoSize(const_cast<LPTSTR>(lptstrFilename),&l_tmp);
		if (l_size != 0)
		{
			l_Data = new BYTE[l_size];
			if (GetFileVersionInfo(const_cast<LPTSTR>(lptstrFilename),NULL,l_size,(LPVOID)l_Data))
			{
				VS_FIXEDFILEINFO * l_Info= NULL;
				UINT l_VerSize;
				if (VerQueryValue(l_Data,"\\",(LPVOID*)&l_Info,&l_VerSize))
				{
					*p_MoreSignVal = l_Info->dwFileVersionMS;
					*p_LessSignVal = l_Info->dwFileVersionLS;
					
					delete l_Data;
					return true;
				}
			}	
			delete l_Data;
		}

		return false;
	};
	*/

}