#include "StdAfx.h"
#include "ShellUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

DVLib::CommandExecutionMethod DVLib::wstring2cem(const std::wstring& name, CommandExecutionMethod defaultValue)
{
	if (name.empty()) 
	{
		return defaultValue;
	}

	for (int i = 0; i < ARRAYSIZE(CommandExecutionMethod2wstringMap); i++)
	{
		if (CommandExecutionMethod2wstringMap[i].name == name)
			return CommandExecutionMethod2wstringMap[i].command_execution_method;
	}

	THROW_EX(L"Invalid command execution method: " << name);
}
 
std::wstring DVLib::cem2wstring(DVLib::CommandExecutionMethod commandExecutionMethod)
{
	for (int i = 0; i < ARRAYSIZE(CommandExecutionMethod2wstringMap); i++)
	{
		if (CommandExecutionMethod2wstringMap[i].command_execution_method == commandExecutionMethod)
			return CommandExecutionMethod2wstringMap[i].name;
	}

	THROW_EX(L"Invalid command execution method: " << commandExecutionMethod);
}

std::wstring DVLib::GetEnvironmentVariable(const std::wstring& name)
{
	DWORD size = ::GetEnvironmentVariableW(name.c_str(), NULL, 0);
	
	if (! size)
	{
		DWORD dwErr = ::GetLastError();
		// no such environment variable
		if (dwErr == ERROR_ENVVAR_NOT_FOUND) 
			return L"";
		// other error
		CHECK_WIN32_DWORD(dwErr, 
			L"GetEnvironmentVariableW");
	}

	std::vector<wchar_t> value;
	value.resize(size);
	CHECK_WIN32_BOOL(0 != (size = ::GetEnvironmentVariableW(name.c_str(), & * value.begin(), value.size())),
		L"GetEnvironmentVariableW");
	return std::wstring(& * value.begin(), value.size() - 1);
}

std::wstring DVLib::ExpandEnvironmentVariables(const std::wstring& s_in)
{
	std::wstring s(s_in);
	std::wstring::size_type i = 0, j = 0;	
	while (((i = s.find(L"%", i)) != s.npos) && ((j = s.find(L"%", i + 1)) != s.npos))
	{
		if (i + 1 != j)
		{
			std::wstring name = s.substr(i + 1, j - i - 1);
			std::wstring value = DVLib::GetEnvironmentVariable(name);
			s.replace(i, j - i + 1, value);
			i += value.length();
		}
		else
		{
			i = j + 1;
		}
	}
	return s;
}

void DVLib::DetachCmd(const std::wstring& cmd, LPPROCESS_INFORMATION lpi)
{
	RunCmd(cmd, lpi, DETACHED_PROCESS);
}

void DVLib::RunCmd(const std::wstring& cmd, LPPROCESS_INFORMATION lpi, int flags, bool hideWindow)
{
	// expand command line, using ShellExecuteEx API function with setting the flag 
	// SEE_MASK_DOENVSUBST does not work because environment variables can also be 
	// placed in the parameters for the new process

	STARTUPINFO si = { 0 };
	si.cb = sizeof(si);

	if (hideWindow)
	{
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_HIDE;
        flags |= CREATE_NO_WINDOW;
	}

	PROCESS_INFORMATION pi = { 0 };

	std::wstring cmd_expanded = DVLib::ExpandEnvironmentVariables(cmd);
	CHECK_WIN32_BOOL(::CreateProcessW(NULL, & * cmd_expanded.begin(), NULL, NULL, FALSE, flags, NULL, NULL, & si, lpi == NULL ? & pi : lpi),
		L"CreateProcessW: " << cmd_expanded);

	if (lpi == NULL)
	{
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
	}
}

DWORD DVLib::ExecCmd(const std::wstring& cmd, bool hideWindow)
{
	PROCESS_INFORMATION pi = { 0 };
	RunCmd(cmd, & pi, 0, hideWindow);
	auto_handle pi_thread(pi.hThread);
	auto_handle pi_process(pi.hProcess);
	CHECK_WIN32_BOOL(WAIT_OBJECT_0 == WaitForSingleObject(pi.hProcess, INFINITE),
		L"WaitForSingleObject");
	DWORD dwExitCode = 0;
	CHECK_WIN32_BOOL(::GetExitCodeProcess(pi.hProcess, & dwExitCode),
		L"GetExitCodeProcess");
	return dwExitCode;
}

void DVLib::ShellCmd(const std::wstring& cmd, int * rc, LPHANDLE lpProcessHandle, HWND hWnd, bool hideWindow)
{
	std::wstring cmd_expanded = DVLib::ExpandEnvironmentVariables(cmd);
	CHECK_BOOL(! cmd_expanded.empty(), L"Missing command");

	// split arguments
	std::vector<std::wstring> cmd_args;
	cmd_args = DVLib::split(cmd_expanded, (cmd_expanded[0] == L'\"') ? L"\" " : L" ", 2);
	std::wstring cmd_file = DVLib::trimleft(cmd_args[0], L"\"");

	SHELLEXECUTEINFO sei = { 0 };
	sei.cbSize = sizeof(sei);
	sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_UNICODE;
	sei.hwnd = hWnd;

    int nShow = SW_SHOWNORMAL;

    if (hideWindow)
    {
        nShow = SW_HIDE;
    }

	sei.lpFile = cmd_file.c_str();
	sei.lpParameters = cmd_args.size() == 2 ? cmd_args[1].c_str() : NULL;
	sei.nShow = nShow;

	CHECK_WIN32_BOOL(::ShellExecuteExW(&sei), 
		L"Error running " << cmd_expanded);
 
	if (NULL != rc)
	{
		* rc = reinterpret_cast<int>(sei.hInstApp);
	}

	if (NULL != lpProcessHandle)
	{
		* lpProcessHandle = sei.hProcess;
	}
}
