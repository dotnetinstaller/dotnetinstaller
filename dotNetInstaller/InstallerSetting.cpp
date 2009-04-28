#include "StdAfx.h"
#include "InstallerSetting.h"
#include "InstallerCommandLineInfo.h"
#include "InstallerTypes.h"
#include "ConfigFile.h"

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

void InstallerSetting::ExecuteCompleteCode(bool componentsInstalled) const
{
	ApplicationLog.Write(TEXT("--Complete Command"));

    CString message = installation_completed;
	// installation completed, but no components have been installed
	if (! componentsInstalled && installation_none.GetLength())
	{
		message = installation_none;
	}

	if (message.Trim().GetLength() > 0)
    {
		DniMessageBox(message, MB_OK|MB_ICONINFORMATION);
    }

	CString l_complete_command = complete_command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (complete_command_silent.GetLength()) l_complete_command = complete_command_silent;
		else if (complete_command_basic.GetLength()) l_complete_command = complete_command_basic;
		break;
	case InstallUILevelBasic:
		if (complete_command_basic.GetLength()) l_complete_command = complete_command_basic;
		else if (complete_command_silent.GetLength()) l_complete_command = complete_command_silent;
		break;
	}

    if (commandLineInfo.GetCompleteCommandArgs().GetLength())
    {
        l_complete_command.Append(L" ");
        l_complete_command.Append(commandLineInfo.GetCompleteCommandArgs());
    }

	if (l_complete_command.Trim().GetLength())
	{
		ApplicationLog.Write( TEXT("Executing complete command: "), l_complete_command);
        DWORD dwExitCode = 0;
        if (! DVLib::ExecCmdAndWait(l_complete_command, & dwExitCode))
        {
            std::string error = "***Error executing complete command: ";
            error.append(DVLib::Tstring2string((LPCWSTR) l_complete_command));
            throw std::exception(error.c_str());
	    }
	}
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
    tmp.Replace(c_TEMPPATH, DVLib::GetTempPathCustom());
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
