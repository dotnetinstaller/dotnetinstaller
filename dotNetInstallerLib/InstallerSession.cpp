#include "StdAfx.h"
#include "InstallerSession.h"

shared_any<InstallerSession *, close_delete> InstallerSession::Instance;

std::wstring InstallerSession::GetSessionGUID()
{
	if (m_GUID.empty())
    {
        m_GUID = DVLib::GenerateGUIDStringW();
    }
    return m_GUID;
}

std::wstring InstallerSession::GetSessionTempPath(bool returnonly)
{
	if (m_tempDirectory.empty() && ! returnonly)
    {
		m_tempDirectory = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), GetSessionGUID());
		DVLib::DirectoryCreate(m_tempDirectory);
    }

    return m_tempDirectory;
}

std::wstring InstallerSession::MakePath(const std::wstring& path)
{
	std::wstring l_CurrentPath = DVLib::GetModuleDirectoryW();
    std::wstring l_SystemPath = DVLib::GetSystemDirectoryW();
    std::wstring l_WindowsPath = DVLib::GetWindowsDirectoryW();
    std::wstring l_SystemWindowsPath = DVLib::GetSystemWindowsDirectory();
	std::wstring l_CabPath = SessionCABPath.empty() ? GetSessionTempPath() : SessionCABPath;

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
