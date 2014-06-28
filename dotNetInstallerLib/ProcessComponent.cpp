#include "StdAfx.h"
#include "ProcessComponent.h"
#include "InstallConfiguration.h"
#include "Wow64NativeFS.h"

ProcessComponent::ProcessComponent(component_type t)
	: Component(t)
	, m_process_handle(NULL)
{
}

DWORD ProcessComponent::GetProcessExitCode() const
{
	DWORD l_ExitCode = 0xFFFFFF;
	if (m_process_handle != NULL)
	{
		CHECK_WIN32_BOOL(::GetExitCodeProcess(m_process_handle, & l_ExitCode),
			L"GetExitCodeProcess");
	}
    return l_ExitCode;
}

int ProcessComponent::GetExitCode() const 
{ 
	return GetProcessExitCode(); 
}

bool ProcessComponent::IsExecuting() const
{
	DWORD l_ExitCode;
	if (m_process_handle != NULL && GetExitCodeProcess(m_process_handle, &l_ExitCode))
	{
		return (l_ExitCode == STILL_ACTIVE);
	}
	else
    {
		return false;
    }
}

void ProcessComponent::Wait(DWORD /* tt */)
{
	CHECK_WIN32_BOOL(WAIT_OBJECT_0 == WaitForSingleObject(m_process_handle, INFINITE),
		L"WaitForSingleObject");
}

void ProcessComponent::ExecCmd(std::wstring command, DVLib::CommandExecutionMethod executionMethod, bool disableWow64FsRedirection, int nShow)
{
	if (disableWow64FsRedirection)
	{
		auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
		ExecCmdCore(command, executionMethod, nShow);
	}
	else
	{
		ExecCmdCore(command, executionMethod, nShow);
	}
}

void ProcessComponent::ExecCmdCore(std::wstring command, DVLib::CommandExecutionMethod executionMethod, int nShow)
{
	PROCESS_INFORMATION process_info;
	switch (executionMethod)
	{
		case DVLib::CemCreateProcess:
			DVLib::RunCmd(command, & process_info, 0, nShow);
			m_process_handle = process_info.hProcess;
			::CloseHandle(process_info.hThread);
			break;
		case DVLib::CemShellExecute:
			DVLib::ShellCmd(command, NULL, & m_process_handle, main_window, nShow);
			break;
	}
}