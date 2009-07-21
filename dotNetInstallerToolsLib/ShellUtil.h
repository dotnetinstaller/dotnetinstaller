#pragma once

namespace DVLib
{
	// return the value of an environment variable
	std::wstring GetEnvironmentVariable(const std::wstring& name);
	// expand environment variables
	std::wstring ExpandEnvironmentVariables(const std::wstring& cmd);
	// detach a command, return process information
	void DetachCmd(const std::wstring& cmd, LPPROCESS_INFORMATION lpi = NULL);
	// execute a process, wait and return exit code
	DWORD ExecCmd(const std::wstring& cmd);
	// shell-execute a process
	void ShellCmd(const std::wstring& cmd, int * rc = NULL);
}
