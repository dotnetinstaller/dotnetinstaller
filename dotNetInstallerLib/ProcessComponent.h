#pragma once
#include "Component.h"

class ProcessComponent : public Component
{
public:
    ProcessComponent(component_type t);
public:
	HANDLE m_process_handle;
	bool IsExecuting() const;
	DWORD GetProcessExitCode() const;
	void Wait(DWORD tt = INFINITE);
	int GetExitCode() const;
protected:
	void ExecCmd(const std::wstring& command, DVLib::CommandExecutionMethod executionMethod, bool disableWow64FsRedirection, const std::wstring& working_directory = L"", int nShow = SW_SHOWNORMAL);
private:
	void ExecCmdCore(const std::wstring& command, DVLib::CommandExecutionMethod executionMethod, const std::wstring& working_directory = L"", int nShow = SW_SHOWNORMAL);
};