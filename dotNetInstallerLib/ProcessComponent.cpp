#include "StdAfx.h"
#include "ProcessComponent.h"
#include "InstallConfiguration.h"

ProcessComponent::ProcessComponent(component_type t)
	: Component(t)
{
	ZeroMemory(& m_process_info, sizeof(PROCESS_INFORMATION));
}

DWORD ProcessComponent::GetProcessExitCode() const
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

void ProcessComponent::Wait(DWORD tt)
{
	CHECK_WIN32_BOOL(WAIT_OBJECT_0 == WaitForSingleObject(m_process_info.hProcess, INFINITE),
		L"WaitForSingleObject");
}
