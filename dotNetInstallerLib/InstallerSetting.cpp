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

CString InstallerSetting::ValidatePath(LPCTSTR p_Path)
{
    //ApplicationPath
    CString l_CurrentPath = DVLib::GetAppPath();
    CString l_SystemPath = DVLib::GetSystemPath();
    CString l_WindowsPath = DVLib::GetWindowsPath();
    CString l_SystemWindowsPath = DVLib::GetSystemWindowsPath();
    CString l_CabPath = cab_path.GetLength() ? cab_path : DVLib::GetSessionTempPath();

    CString tmp = p_Path;
    tmp.Replace(c_CABPATH, l_CabPath);
    tmp.Replace(c_APPPATH, l_CurrentPath);
    tmp.Replace(c_SYSTEMPATH, l_SystemPath);
    tmp.Replace(c_WINDOWSPATH, l_WindowsPath);
    tmp.Replace(c_SYSTEMWINDOWSPATH, l_SystemWindowsPath);
    tmp.Replace(c_TEMPPATH, DVLib::GetTempPath());
    tmp.Replace(c_GUID, DVLib::GetSessionGUID());
	tmp.Replace(c_PID, DVLib::FormatNumber(::GetCurrentProcessId()));
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
