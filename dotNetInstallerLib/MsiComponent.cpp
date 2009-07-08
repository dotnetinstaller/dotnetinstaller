#include "StdAfx.h"
#include "MsiComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"

MsiComponent::MsiComponent()
{

}

void MsiComponent::Exec()
{
	std::wstring l_command = TEXT("msiexec /I ");
	l_command.append(L"\"");
	l_command += package;
	l_command.append(L"\"");

	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (! cmdparameters_silent.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_silent);
		}
		else if (! cmdparameters_basic.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_basic);
		}
		break;
	case InstallUILevelBasic:
		if (! cmdparameters_basic.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_basic);
		}
		else if (! cmdparameters_silent.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_silent);
		}
		break;
	default:
		if (! cmdparameters.empty())
		{
			l_command.append(L" ");
			l_command.append(cmdparameters);
		}
		break;
	}
	
    LOG(L"Executing: " << l_command);
	DVLib::DetachCmd(l_command, &m_process_info);
};

