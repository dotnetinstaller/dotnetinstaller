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
    , allow_continue_on_error(false)
    , log_enabled(false)
{

}

void InstallerSetting::ExecuteCompleteCode() const
{
	ApplicationLog.Write(TEXT("--Complete Command"));

    CString message = installation_completed;
	if (message.Trim().GetLength() > 0)
    {
		DniMessageBox(message, MB_OK|MB_ICONINFORMATION);
    }

	CString command = complete_command;
    CString command_silent = complete_command_silent; 
	
    if (QuietInstall.IsSilent() && command_silent.Trim().GetLength()) 
    {
        command = complete_command_silent;
    }

    if (commandLineInfo.GetCompleteCommandArgs().GetLength())
    {
        command.Append(L" ");
        command.Append(commandLineInfo.GetCompleteCommandArgs());
    }

	if (command.Trim().GetLength())
	{
		ApplicationLog.Write( TEXT("Executing complete command: "), command);
        DWORD dwExitCode = 0;
        if (! DVLib::ExecCmdAndWait(command, & dwExitCode))
        {
            std::string error = "***Error executing complete command: ";
            error.append(DVLib::Tstring2string((LPCWSTR) command));
            throw std::exception(error.c_str());
	    }
	}
}

CString InstallerSetting::ValidatePath(LPCTSTR p_Path)
{
    //ApplicationPath
    CString l_CurrentPath = DVLib::GetAppPath();

    //SystemPath
    TCHAR l_bufferSystem[MAX_PATH+1];
    ZeroMemory(l_bufferSystem,MAX_PATH+1);
    GetSystemDirectory(l_bufferSystem, MAX_PATH+1);

    //WindowsPath
    TCHAR l_bufferWindows[MAX_PATH+1];
    ZeroMemory(l_bufferWindows,MAX_PATH+1);
    GetWindowsDirectory(l_bufferWindows, MAX_PATH+1);

    //CabPath

    CString tmp = p_Path;
    tmp.Replace(c_CABPATH, cab_path.GetLength() ? cab_path : DVLib::GetSessionTempPath());
    tmp.Replace(c_APPPATH, l_CurrentPath);
    tmp.Replace(c_SYSTEMPATH, l_bufferSystem);
    tmp.Replace(c_WINDOWSPATH, l_bufferWindows);
    tmp.Replace(c_TEMPPATH, DVLib::GetTempPathCustom());
    tmp.Replace(c_GUID, DVLib::GetSessionGUID());

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
		FreeComponent(components[i]);
	}

    components.clear();
    components_map.clear();
}
