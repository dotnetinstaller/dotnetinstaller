#include "StdAfx.h"
#include "ProcessComponent.h"

ProcessComponent::ProcessComponent(void)
{

}

DWORD ProcessComponent::GetExitCode() const
{
	DWORD l_ExitCode;

	CHECK_WIN32_BOOL(::GetExitCodeProcess(m_process_info.hProcess, & l_ExitCode),
		L"GetExitCodeProcess");

    return l_ExitCode;
}

bool ProcessComponent::IsExecuting() const
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
