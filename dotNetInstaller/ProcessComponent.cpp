#include "StdAfx.h"
#include "ProcessComponent.h"

ProcessComponent::ProcessComponent(void)
{

}

DWORD ProcessComponent::GetExitCode()
{
	DWORD l_ExitCode;
	if (! GetExitCodeProcess(m_process_info.hProcess, &l_ExitCode))
        throw std::exception("Error getting exit code from process");

    return l_ExitCode;
}

bool ProcessComponent::IsExecuting()
{
	DWORD l_ExitCode;
	if (GetExitCodeProcess(m_process_info.hProcess, &l_ExitCode))
	{
		if (l_ExitCode == STILL_ACTIVE)
			return true;
		else
			return false;
	}
	else
    {
		return false;
    }
}

void ProcessComponent::Init()
{
	ZeroMemory(& m_process_info, sizeof(PROCESS_INFORMATION));
}
