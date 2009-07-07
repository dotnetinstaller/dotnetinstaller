#include "StdAfx.h"
#include "InstallerSetting.h"
#include "InstallerTypes.h"
#include "InstallerLog.h"

InstallerSetting::InstallerSetting()
    : must_reboot_required(false)
    , auto_close_if_installed(false)
    , auto_close_on_error(false)
    , dialog_show_installed(false)
    , dialog_show_required(false)
    , allow_continue_on_error(true)
    , log_enabled(false)
{

}

std::wstring InstallerSetting::ValidatePath(const std::wstring& path)
{
    //ApplicationPath
	std::wstring l_CurrentPath = DVLib::GetModuleDirectoryW();
    std::wstring l_SystemPath = DVLib::GetSystemDirectoryW();
    std::wstring l_WindowsPath = DVLib::GetWindowsDirectoryW();
    std::wstring l_SystemWindowsPath = DVLib::GetSystemWindowsDirectory();
	std::wstring l_CabPath = cab_path.empty() ? GetSessionTempPath() : cab_path;

    std::wstring tmp = path;
	tmp = DVLib::replace(tmp, c_CABPATH, l_CabPath);
    tmp = DVLib::replace(tmp, c_APPPATH, l_CurrentPath);
    tmp = DVLib::replace(tmp, c_SYSTEMPATH, l_SystemPath);
    tmp = DVLib::replace(tmp, c_WINDOWSPATH, l_WindowsPath);
    tmp = DVLib::replace(tmp, c_SYSTEMWINDOWSPATH, l_SystemWindowsPath);
	tmp = DVLib::replace(tmp, c_TEMPPATH, DVLib::GetTemporaryDirectoryW());
    tmp = DVLib::replace(tmp, c_GUID, GetSessionGUID());
	tmp = DVLib::replace(tmp, c_PID, DVLib::towstring(::GetCurrentProcessId()));
    return tmp;
}

void InstallerSetting::AddComponent(Component * c)
{
    components_map.insert(std::make_pair(c->description, c));
    components.push_back(c);
}

void InstallerSetting::ClearComponents()
{
	for (size_t i = 0; i < components.size(); i++)
	{
        delete components[i];
	}

    components.clear();
    components_map.clear();
}

std::wstring InstallerSetting::GetSessionGUID()
{
    static std::wstring s_GUID;
    if (s_GUID.empty())
    {
        s_GUID = DVLib::GenerateGUIDStringW().c_str();
    }
    return s_GUID;
}

std::wstring InstallerSetting::GetSessionTempPath(bool returnonly)
{
    // not threadsafe
    static std::wstring s_tempDirectory;

    if (s_tempDirectory.empty() && ! returnonly)
    {
		s_tempDirectory = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), GetSessionGUID());
		DVLib::DirectoryCreate(s_tempDirectory);
    }

    return s_tempDirectory;
}