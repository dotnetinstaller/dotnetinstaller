#include "StdAfx.h"
#include "CmdComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"

cmd_component::cmd_component()
{

}

void cmd_component::Exec()
{
	std::wstring l_command = command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (! command_silent.empty()) l_command = command_silent;
		else if (! command_basic.empty()) l_command = command_basic;
		break;
	case InstallUILevelBasic:
		if (! command_basic.empty()) l_command = command_basic;
		else if (! command_silent.empty()) l_command = command_silent;
		break;
	}

	LOG(L"Executing: " << l_command);
	DVLib::DetachCmd(l_command, & m_process_info);
};

