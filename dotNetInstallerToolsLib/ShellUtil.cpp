#include "StdAfx.h"
#include "ShellUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

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
	int i = 0, j = 0;	
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
	// expand command line, using ShellExecuteEx API function with setting the flag 
	// SEE_MASK_DOENVSUBST does not work because environment variables can also be 
	// placed in the parameters for the new process
	STARTUPINFO si = { 0 };
	si.cb = sizeof(si);

	PROCESS_INFORMATION pi = { 0 };

	std::wstring cmd_expanded = DVLib::ExpandEnvironmentVariables(cmd);
	CHECK_WIN32_BOOL(::CreateProcessW(NULL, & * cmd_expanded.begin(), NULL, NULL, FALSE, 0, NULL, NULL, & si, lpi == NULL ? & pi : lpi),
		L"CreateProcessW: " << cmd_expanded);

	if (lpi == NULL)
	{
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
	}
}

DWORD DVLib::ExecCmd(const std::wstring& cmd)
{
	PROCESS_INFORMATION pi = { 0 };
	DetachCmd(cmd, & pi);
	auto_handle pi_thread(pi.hThread);
	auto_handle pi_process(pi.hProcess);
	CHECK_WIN32_BOOL(WAIT_OBJECT_0 == WaitForSingleObject(pi.hProcess, INFINITE),
		L"WaitForSingleObject");
	DWORD dwExitCode = 0;
	CHECK_WIN32_BOOL(::GetExitCodeProcess(pi.hProcess, & dwExitCode),
		L"GetExitCodeProcess");
	return dwExitCode;
}

void DVLib::ShellCmd(const std::wstring& cmd)
{
	std::wstring cmd_expanded = DVLib::ExpandEnvironmentVariables(cmd);
	CHECK_BOOL(! cmd_expanded.empty(), L"Missing command");

	// split arguments
	std::vector<std::wstring> cmd_args;
	cmd_args = DVLib::split(cmd_expanded, (cmd_expanded[0] == L'\"') ? L"\" " : L" ", 2);

	HINSTANCE h = ::ShellExecuteW(NULL, NULL, DVLib::trim(cmd_args[0], L"\"").c_str(), 
		cmd_args.size() == 2 ? cmd_args[1].c_str() : NULL, NULL, SW_SHOWNORMAL);

	if (h <= (HINSTANCE) 32) 
	{
		CHECK_WIN32_DWORD((DWORD) h, L"Error running " <<  cmd_expanded);
	}
}
