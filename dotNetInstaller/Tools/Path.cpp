#include "StdAfx.h"
#include "File.h"
#include "Path.h"
#include "Guid.h"

CString DVLib::GetAppFullName()
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

CString DVLib::GetAppPath()
{
    return DVLib::GetPathFromFullFilePath(DVLib::GetAppFullName());
}

CString DVLib::GetSystemPath()
{
	//SystemPath
	TCHAR l_bufferSystem[MAX_PATH+1];
	ZeroMemory(l_bufferSystem,MAX_PATH+1);
	GetSystemDirectory(l_bufferSystem, MAX_PATH+1);

	return l_bufferSystem;
}

CString DVLib::GetWindowsPath()
{
	//WindowsPath
	TCHAR l_bufferWindows[MAX_PATH+1];
	ZeroMemory(l_bufferWindows,MAX_PATH+1);
	GetWindowsDirectory(l_bufferWindows, MAX_PATH+1);

	return l_bufferWindows;
}

CString DVLib::GetTempPathCustom()
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

CString DVLib::GetSessionGUID()
{
    static CString s_GUID;
    if (! s_GUID.GetLength())
    {
        s_GUID = DVLib::GenerateGUIDString();
    }
    return s_GUID;
}

CString DVLib::GetSessionTempPath(bool returnonly)
{
    // not threadsafe
    static CString s_tempDirectory;
    if (s_tempDirectory.GetLength() == 0 && ! returnonly)
    {
        s_tempDirectory = DVLib::PathCombineCustom(DVLib::GetTempPathCustom(), DVLib::GetSessionGUID());
	    if (DVLib::FileExistsCustom(s_tempDirectory) == false)
        {
		    ::CreateDirectory(s_tempDirectory, NULL);
        }
    }

    return s_tempDirectory;
}

CString DVLib::GetTempFullFileName()
{
	TCHAR l_bufferTempPath[MAX_PATH+1];
	ZeroMemory(l_bufferTempPath,MAX_PATH+1);
	GetTempFileName(DVLib::GetSessionTempPath(), TEXT("tmp"), 0, l_bufferTempPath);
	return l_bufferTempPath;
}

void DVLib::DeleteDirectoryDeep(const CString& path)
{
    WIN32_FIND_DATAW ffd;

    CString wildcard = path;
    wildcard.TrimRight(L"\\");
    wildcard.Append(L"\\*");

    HANDLE h = FindFirstFileW((LPCWSTR) wildcard, & ffd); // find the first file

    if(h == INVALID_HANDLE_VALUE)
        throw _TEXT("FindFirstFileW");

    while(true)
    {
        if (::wcscmp(ffd.cFileName, L".") != 0 && wcscmp(ffd.cFileName, L"..") != 0)
	    {
		    CString sub = path;
            sub.TrimRight(L"\\");
		    sub.Append(L"\\");
		    sub.Append(ffd.cFileName);

		    if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		    {
			    DVLib::DeleteDirectoryDeep(sub);
		    }
		    else
		    {
			    if (! ::DeleteFileW((LPCWSTR) sub))
                    throw (LPCWSTR) sub;
		    }
	    }

	    if (! ::FindNextFileW(h, & ffd))
	    {
		    DWORD dwErr = GetLastError();
			
		    if (dwErr != ERROR_NO_MORE_FILES)
		    {
                throw _TEXT("FindNextFileW");
		    }

		    break;
	    }
    }

    FindClose(h);
 
    ::RemoveDirectoryW((LPCWSTR) path);
}
