#include "StdAfx.h"
#include "MsiComponent.h"

MsiComponent::MsiComponent()
{

}

bool MsiComponent::Exec()
{
	CString l_command = TEXT("msiexec /I ");
	l_command += TEXT("\"");
	l_command += package;
	l_command += TEXT("\"");
	l_command += TEXT(" ");

    if (QuietInstall.IsSilent() && cmdparameters_silent.GetLength())
    {
        l_command += cmdparameters_silent;
    }
    else
    {
	    l_command += cmdparameters;
    }
	
	//if (suppressreboot)
	//	l_command += " REBOOT=ReallySuppress";

    ApplicationLog.Write(TEXT("Executing: "), l_command);

	return DVLib::ExecCmd(l_command, &m_process_info);
};

