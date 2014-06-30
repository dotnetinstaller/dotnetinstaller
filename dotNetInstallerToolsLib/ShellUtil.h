#pragma once

namespace DVLib
{
	enum CommandExecutionMethod
	{
		CemCreateProcess = 0,
		CemShellExecute = 1,
	};

	struct CommandExecutionMethod2wstringMapEntry
	{
		CommandExecutionMethod command_execution_method;
		LPCWSTR name;
	};

	static const CommandExecutionMethod2wstringMapEntry CommandExecutionMethod2wstringMap[] = 
	{
		{ CemCreateProcess, L"CreateProcess" },
		{ CemShellExecute, L"ShellExecute" },
	};

	CommandExecutionMethod wstring2cem(const std::wstring& name, CommandExecutionMethod defaultValue = CemCreateProcess);
	std::wstring cem2wstring(CommandExecutionMethod commandExecutionMethod);

	// return the value of an environment variable
	std::wstring GetEnvironmentVariable(const std::wstring& name);
	// expand environment variables
	std::wstring ExpandEnvironmentVariables(const std::wstring& cmd);
	// detach a command, return process information
	void DetachCmd(const std::wstring& cmd, LPPROCESS_INFORMATION lpi = NULL);
	// run a command, return process information
	void RunCmd(const std::wstring& cmd, LPPROCESS_INFORMATION lpi = NULL, int flags = 0, const std::wstring& working_directory = L"", int nShow = SW_SHOWNORMAL);
	// execute a process, wait and return exit code
	DWORD ExecCmd(const std::wstring& cmd, const std::wstring& working_directory = L"", int nShow = SW_SHOWNORMAL);
	// shell-execute a process
	void ShellCmd(const std::wstring& cmd, int * rc = NULL, LPHANDLE lpProcessHandle = NULL, HWND hWnd = NULL, const std::wstring& working_directory = L"", int nShow = SW_SHOWNORMAL);
}
