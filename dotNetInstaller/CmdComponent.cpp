#include "StdAfx.h"
#include "CmdComponent.h"

cmd_component::cmd_component()
{

}

bool cmd_component::Exec()
{
	CString l_command = command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (command_silent.GetLength()) l_command = command_silent;
		else if (command_basic.GetLength()) l_command = command_basic;
		break;
	case InstallUILevelBasic:
		if (command_basic.GetLength()) l_command = command_basic;
		else if (command_silent.GetLength()) l_command = command_silent;
		break;
	}

	ApplicationLog.Write(TEXT("Executing: "), l_command);
	return DVLib::ExecCmd(l_command, & m_process_info);
};

