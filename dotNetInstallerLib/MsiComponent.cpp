#include "StdAfx.h"
#include "MsiComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"

MsiComponent::MsiComponent()
{

}

bool MsiComponent::Exec()
{
	CString l_command = TEXT("msiexec /I ");
	l_command += TEXT("\"");
	l_command += package;
	l_command += TEXT("\"");

	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (cmdparameters_silent.GetLength()) 
		{
			l_command += TEXT(" ");
			l_command.Append(cmdparameters_silent);
		}
		else if (cmdparameters_basic.GetLength()) 
		{
			l_command += TEXT(" ");
			l_command.Append(cmdparameters_basic);
		}
		break;
	case InstallUILevelBasic:
		if (cmdparameters_basic.GetLength()) 
		{
			l_command += TEXT(" ");
			l_command.Append(cmdparameters_basic);
		}
		else if (cmdparameters_silent.GetLength()) 
		{
			l_command += TEXT(" ");
			l_command.Append(cmdparameters_silent);
		}
		break;
	default:
		if (cmdparameters.GetLength())
		{
			l_command += TEXT(" ");
			l_command.Append(cmdparameters);
		}
		break;
	}
	
    ApplicationLog.Write(TEXT("Executing: "), l_command);
	DVLib::DetachCmd((LPCWSTR) l_command, &m_process_info);
	return true;
};

