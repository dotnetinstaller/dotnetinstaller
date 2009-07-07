#include "StdAfx.h"
#include "ShellUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(ShellUtilUnitTests);

void ShellUtilUnitTests::testGetEnvironmentVariable()
{
	wchar_t computername_s[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD computername_size = ARRAYSIZE(computername_s);
	CPPUNIT_ASSERT(::GetComputerNameW(computername_s, & computername_size));
	std::wstring computername = DVLib::GetEnvironmentVariable(L"COMPUTERNAME");
	std::wcout << std::endl << L"Computer name: " << computername;
	CPPUNIT_ASSERT(computername.length() > 0);
	CPPUNIT_ASSERT(computername.length() == wcslen(computername.c_str()));
	CPPUNIT_ASSERT(computername == computername_s);
}

void ShellUtilUnitTests::testExpandEnvironmentVariables()
{
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"") == L"");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%%") == L"%%");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%%%") == L"%%%");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%" + DVLib::GenerateGUIDStringW() + L"%") == L"");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME%") == DVLib::GetEnvironmentVariableW(L"COMPUTERNAME"));
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME%%COMPUTERNAME%") == DVLib::GetEnvironmentVariableW(L"COMPUTERNAME") + DVLib::GetEnvironmentVariableW(L"COMPUTERNAME"));
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME") == L"%COMPUTERNAME");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"COMPUTERNAME%") == L"COMPUTERNAME%");
	CPPUNIT_ASSERT(DVLib::ExpandEnvironmentVariables(L"{%COMPUTERNAME%}") == L"{" + DVLib::GetEnvironmentVariableW(L"COMPUTERNAME") + L"}");
}

void ShellUtilUnitTests::testDetachCmd()
{
	// detach without pi
	DVLib::DetachCmd(L"cmd.exe /C");
	// with process information
	PROCESS_INFORMATION pi = { 0 };
	DVLib::DetachCmd(L"cmd.exe /C", & pi);
	auto_handle pi_thread(pi.hThread);
	auto_handle pi_process(pi.hProcess);
	CPPUNIT_ASSERT(pi.dwProcessId > 0);
	CPPUNIT_ASSERT(WAIT_OBJECT_0 == ::WaitForSingleObject(pi.hProcess, INFINITE));
}

void ShellUtilUnitTests::testExecCmd()
{
	CPPUNIT_ASSERT(0 == DVLib::ExecCmd(L"cmd.exe /C"));
	CPPUNIT_ASSERT(123 == DVLib::ExecCmd(L"cmd.exe /C exit /b 123"));
}

void ShellUtilUnitTests::testShellCmd()
{
	DVLib::ShellCmd(L"cmd.exe /C");
	DVLib::ShellCmd(L"\"" + DVLib::GetEnvironmentVariable(L"SystemRoot") + L"\\system32\\cmd.exe\" /C");
	DVLib::ShellCmd(L"\"cmd.exe\" /C dir");
}