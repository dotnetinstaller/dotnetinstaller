#pragma once
#include "File.h"

namespace DVLib
{
	inline CString GetAppFullName()
	{
		TCHAR l_buffer[2000];
		ZeroMemory(l_buffer,2000);

		if (GetModuleFileName(NULL,l_buffer,2000) == 0)
		{
			_ASSERT(false);
			throw -1;
		}

		CString tmp = l_buffer;
		return tmp;
	}

	//restituisce il path dell'applicazione corrente senza il backslash finale
	inline CString GetAppPath()
	{
		return GetPathFromFullFilePath(GetAppFullName());
		/*
		CString l_FullPath = GetAppFullName();

		l_FullPath.Replace('/','\\');

		//trovo l'ultimo backslash
		int l_PosFind = -1;
		for (int i = l_FullPath.GetLength()-1; i >= 0; i--)
		{
			if (l_FullPath.GetAt(i) == '\\')
			{
				l_PosFind = i;
				break;
			}
		}

		if (l_PosFind == -1)
		{
			_ASSERT(false);
			throw -1;
		}

		CString tmp = l_FullPath.Mid(0,l_PosFind);
		return tmp;*/
	}

	inline CString GetSystemPath()
	{
		//SystemPath
		TCHAR l_bufferSystem[MAX_PATH+1];
		ZeroMemory(l_bufferSystem,MAX_PATH+1);
		GetSystemDirectory(l_bufferSystem, MAX_PATH+1);

		return l_bufferSystem;
	}

	inline CString GetWindowsPath()
	{
		//WindowsPath
		TCHAR l_bufferWindows[MAX_PATH+1];
		ZeroMemory(l_bufferWindows,MAX_PATH+1);
		GetWindowsDirectory(l_bufferWindows, MAX_PATH+1);

		return l_bufferWindows;
	}

	inline CString GetTempPathCustom()
	{
		//TempPath
		TCHAR l_bufferTempPath[MAX_PATH+1];
		ZeroMemory(l_bufferTempPath,MAX_PATH+1);
		::GetTempPath(MAX_PATH+1, l_bufferTempPath);

		if (DVLib::FileExistsCustom(l_bufferTempPath) == false)
			//Try to create the directory (because on Win95/98 the directory cannot exist, see : http://msdn.microsoft.com/library/default.asp?url=/library/en-us/fileio/base/gettemppath.asp )
			::CreateDirectory(l_bufferTempPath, NULL);

		return l_bufferTempPath;
	}

	inline CString GetTempFullFileName()
	{
		TCHAR l_bufferTempPath[MAX_PATH+1];
		ZeroMemory(l_bufferTempPath,MAX_PATH+1);
		GetTempFileName(GetTempPathCustom(), TEXT("tmp"), 0, l_bufferTempPath);
		return l_bufferTempPath;
	}
}