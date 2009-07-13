#include "StdAfx.h"
#include "InstallerSession.h"

std::wstring InstallerSession::s_sessioncabpath;
std::wstring InstallerSession::s_GUID;
std::wstring InstallerSession::s_tempDirectory;
std::map<std::wstring, std::wstring> InstallerSession::s_AdditionalCmdLineArgs;

std::wstring InstallerSession::GetSessionGUID()
{
    if (s_GUID.empty())
    {
        s_GUID = DVLib::GenerateGUIDStringW().c_str();
    }
    return s_GUID;
}

std::wstring InstallerSession::GetSessionTempPath(bool returnonly)
{
    if (s_tempDirectory.empty() && ! returnonly)
    {
		s_tempDirectory = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), GetSessionGUID());
		DVLib::DirectoryCreate(s_tempDirectory);
    }

    return s_tempDirectory;
}

std::wstring InstallerSession::MakePath(const std::wstring& path)
{
	std::wstring l_CurrentPath = DVLib::GetModuleDirectoryW();
    std::wstring l_SystemPath = DVLib::GetSystemDirectoryW();
    std::wstring l_WindowsPath = DVLib::GetWindowsDirectoryW();
    std::wstring l_SystemWindowsPath = DVLib::GetSystemWindowsDirectory();
	std::wstring l_CabPath = s_sessioncabpath.empty() ? InstallerSession::GetSessionTempPath() : s_sessioncabpath;

    std::wstring tmp = path;
	tmp = DVLib::replace(tmp, L"#CABPATH", l_CabPath);
    tmp = DVLib::replace(tmp, L"#APPPATH", l_CurrentPath);
    tmp = DVLib::replace(tmp, L"#SYSTEMPATH", l_SystemPath);
    tmp = DVLib::replace(tmp, L"#WINDOWSPATH", l_WindowsPath);
	tmp = DVLib::replace(tmp, L"#SYSTEMWINDOWSPATH", l_SystemWindowsPath);
	tmp = DVLib::replace(tmp, L"#TEMPPATH", DVLib::GetTemporaryDirectoryW());
    tmp = DVLib::replace(tmp, L"#GUID", InstallerSession::GetSessionGUID());
	tmp = DVLib::replace(tmp, L"#PID", DVLib::towstring(::GetCurrentProcessId()));
    return tmp;
}
