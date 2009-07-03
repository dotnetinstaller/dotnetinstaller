#include "StdAfx.h"
#include "File.h"
#include "Path.h"
#include "Guid.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

CString DVLib::GetAppFullName()
{
    TCHAR l_buffer[MAX_PATH] = { 0 };

	if (GetModuleFileName(NULL, l_buffer, MAX_PATH) == 0)
	{
		_ASSERT(false);
        throw std::exception("GetModuleFileName failed");
	}

	return l_buffer;
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
	TCHAR l_bufferWindows[MAX_PATH+1];
	ZeroMemory(l_bufferWindows,MAX_PATH+1);
	GetWindowsDirectory(l_bufferWindows, MAX_PATH+1);
	return l_bufferWindows;
}

CString DVLib::GetSystemWindowsPath()
{
	TCHAR l_bufferWindows[MAX_PATH+1];
	ZeroMemory(l_bufferWindows,MAX_PATH+1);
	GetSystemWindowsDirectory(l_bufferWindows, MAX_PATH+1);
	return l_bufferWindows;
}

CString DVLib::GetTempPath()
{
	TCHAR l_bufferTempPath[MAX_PATH+1];
	ZeroMemory(l_bufferTempPath,MAX_PATH+1);
	::GetTempPath(MAX_PATH+1, l_bufferTempPath);
	// on Win95/98 the directory does not exist, http://msdn.microsoft.com/library/default.asp?url=/library/en-us/fileio/base/gettemppath.asp
	DVLib::CreateDirectoryPath(l_bufferTempPath);
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
        s_tempDirectory = DVLib::PathCombineT(DVLib::GetTempPath(), DVLib::GetSessionGUID());
		DVLib::CreateDirectoryPath(s_tempDirectory);
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
    {
        throw std::exception("FindFirstFile failed");
    }

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
				{
                    std::string error = "Error deleting: ";
                    error.append(DVLib::wstring2string((LPCWSTR) sub));
                    throw std::exception(error.c_str());
				}
		    }
	    }

	    if (! ::FindNextFileW(h, & ffd))
	    {
		    DWORD dwErr = GetLastError();
			
		    if (dwErr != ERROR_NO_MORE_FILES)
		    {
                throw std::exception("FindNextFile failed");
		    }

		    break;
	    }
    }

    FindClose(h);
 
    ::RemoveDirectoryW((LPCWSTR) path);
}

bool DVLib::CreateDirectoryPath(const CString& path)
{
    if (DVLib::FileExists(path))
		return false;

	if (path.IsEmpty())
		return false;

    if (! ::CreateDirectory(path, NULL))
	{
		std::string error = "Error creating directory \"";
		error.append(DVLib::wstring2string((LPCWSTR) path));
		error.append("\"\r\n");
		error.append(DVLib::wstring2string((LPCWSTR) DVLib::TranslateErrorMsg(HRESULT_FROM_WIN32(::GetLastError()))));
		throw std::exception(error.c_str());
	}

	return true;
}