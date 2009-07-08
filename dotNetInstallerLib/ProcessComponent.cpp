#include "StdAfx.h"
#include "ProcessComponent.h"

ProcessComponent::ProcessComponent(void)
{
	ZeroMemory(& m_process_info, sizeof(PROCESS_INFORMATION));
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
		return (l_ExitCode == STILL_ACTIVE);
	}
	else
    {
		return false;
    }
}
