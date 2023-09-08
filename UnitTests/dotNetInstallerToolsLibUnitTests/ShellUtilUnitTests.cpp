#include "StdAfx.h"
#include "ShellUtilUnitTests.h"
#include "FindWindow.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ShellUtilUnitTests::testGetEnvironmentVariable()
{
    wchar_t computername_s[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD computername_size = ARRAYSIZE(computername_s);
    Assert::IsTrue(::GetComputerNameW(computername_s, & computername_size));
    std::wstring computername = DVLib::GetEnvironmentVariable(L"COMPUTERNAME");
    std::wcout << std::endl << L"Computer name: " << computername;
    Assert::IsTrue(computername.length() > 0);
    Assert::IsTrue(computername.length() == wcslen(computername.c_str()));
    Assert::IsTrue(computername == computername_s);
}

void ShellUtilUnitTests::testExpandEnvironmentVariables()
{
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"") == L"");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%%") == L"%%");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%%%") == L"%%%");

    std::wstring guid = DVLib::GenerateGUIDStringW();
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%" + guid + L"%") == L"%" + guid + L"%");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%cd%") == L"%cd%");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME%") == DVLib::GetEnvironmentVariableW(L"COMPUTERNAME"));
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME%%COMPUTERNAME%") == DVLib::GetEnvironmentVariableW(L"COMPUTERNAME") + DVLib::GetEnvironmentVariableW(L"COMPUTERNAME"));
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"%COMPUTERNAME") == L"%COMPUTERNAME");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"COMPUTERNAME%") == L"COMPUTERNAME%");
    Assert::IsTrue(DVLib::ExpandEnvironmentVariables(L"{%COMPUTERNAME%}") == L"{" + DVLib::GetEnvironmentVariableW(L"COMPUTERNAME") + L"}");
}

void ShellUtilUnitTests::testDetachCmd()
{
    // test timer runs for 2 seconds
    std::wstring testTimerExe = DVLib::DirectoryCombine(
#ifdef DEBUG
        DVLib::GetCurrentModuleDirectoryW(), L"..\\..\\TestTimer\\bin\\Debug\\net20\\TestTimer.exe"
#else
        DVLib::GetCurrentModuleDirectoryW(), L"..\\..\\TestTimer\\bin\\Release\\net20\\TestTimer.exe"
#endif
        );
    Assert::IsTrue(DVLib::FileExists(testTimerExe));
    // detach without pi
    DWORD c1 = ::GetTickCount();
    DVLib::DetachCmd(testTimerExe);
    Assert::IsTrue((::GetTickCount() - c1) < 2 * 1000);
    // run with process information
    PROCESS_INFORMATION pi = { 0 };
    DWORD c2 = ::GetTickCount();
    DVLib::DetachCmd(testTimerExe, & pi);
    auto_handle pi_thread(pi.hThread);
    auto_handle pi_process(pi.hProcess);
    Assert::IsTrue(pi.dwProcessId > 0);
    Assert::IsTrue((::GetTickCount() - c2) < 2 * 1000);
}

void ShellUtilUnitTests::testRunCmd()
{
    // run without pi
    DVLib::RunCmd(L"cmd.exe /C exit /b 0");
    // with process information
    PROCESS_INFORMATION pi = { 0 };
    DVLib::RunCmd(L"cmd.exe /C exit /b 0", & pi);
    auto_handle pi_thread(pi.hThread);
    auto_handle pi_process(pi.hProcess);
    Assert::IsTrue(pi.dwProcessId > 0);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(pi.hProcess, INFINITE));
}

void ShellUtilUnitTests::testExecCmd()
{
    Assert::IsTrue(0 == DVLib::ExecCmd(L"cmd.exe /C"));
    Assert::IsTrue(123 == DVLib::ExecCmd(L"cmd.exe /C exit /b 123"));

    // hide window
    Assert::IsTrue(456 == DVLib::ExecCmd(L"cmd.exe /C exit /b 456", L"", SW_HIDE));
}

void ShellUtilUnitTests::testShellCmd()
{
    DVLib::ShellCmd(L"cmd.exe /C");
    DVLib::ShellCmd(L"\"" + DVLib::GetEnvironmentVariable(L"SystemRoot") + L"\\system32\\cmd.exe\" /C");
    HANDLE hProcess;
    DVLib::ShellCmd(L"\"cmd.exe\" /C dir", NULL, &hProcess);
    auto_handle pi_process(hProcess);
    Assert::IsTrue(hProcess != NULL);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(hProcess, INFINITE));
}

void ShellUtilUnitTests::testRunCmdWithHiddenWindow()
{
    // Arrange
    int nShow = SW_HIDE;

    // Act
    PROCESS_INFORMATION pi = { 0 };
    DVLib::RunCmd(L"cmd.exe /C ping -n 6 127.0.0.1 > nul && exit /b 0", & pi, 0, L"", nShow);
    auto_handle pi_thread(pi.hThread);
    auto_handle pi_process(pi.hProcess);

    // Assert
    Assert::IsTrue(pi.dwProcessId > 0);
    Assert::IsTrue(NULL == FindWindow::FindWindowFromProcessId(pi.dwProcessId));
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(pi.hProcess, INFINITE));
}

void ShellUtilUnitTests::testShellCmdWithHiddenWindow()
{
    // Arrange
    int nShow = SW_HIDE;

    HANDLE hProcess;

    // Act
    DVLib::ShellCmd(L"\"cmd.exe\" /C ping -n 6 127.0.0.1 > nul", NULL, &hProcess, NULL, L"", nShow);
    auto_handle pi_process(hProcess);

    // Assert
    Assert::IsTrue(hProcess != NULL);
    Assert::IsTrue(NULL == FindWindow::FindWindowFromProcess(hProcess));
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(hProcess, INFINITE));
}

void ShellUtilUnitTests::testRunCmdWithoutWorkingDirectorySpecified()
{
    // Arrange
    std::wstring working_directory = DVLib::GetCurrentDirectoryW();
    PROCESS_INFORMATION pi = { 0 };
    std::wstring command = DVLib::FormatMessage(
        L"cmd.exe /C if '%%cd%%'=='%s' (exit /b 0) else (echo '%%cd%%'!='%s' && exit /b 1)",
        working_directory.c_str(),
        working_directory.c_str());

    // Act
    DVLib::RunCmd(command, &pi, 0);
    auto_handle pi_thread(pi.hThread);
    auto_handle pi_process(pi.hProcess);

    // Assert
    Assert::IsTrue(pi.dwProcessId > 0);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(pi.hProcess, INFINITE));

    DWORD exitCode = 0;
    CHECK_WIN32_BOOL(::GetExitCodeProcess(pi.hProcess, &exitCode),
        L"GetExitCodeProcess");
    Assert::IsTrue(exitCode == 0);
}

void ShellUtilUnitTests::testRunCmdWithWorkingDirectorySpecified()
{
    // Arrange
    std::wstring working_directory = DVLib::GetTemporaryDirectoryW();

    // Act
    PROCESS_INFORMATION pi = { 0 };
    DVLib::RunCmd(L"cmd.exe /C if '%%cd%%'=='%%temp%%' (exit /b 0) else (echo '%%cd%%'!='%%temp%%' && exit /b 1)", &pi, 0, working_directory);
    auto_handle pi_thread(pi.hThread);
    auto_handle pi_process(pi.hProcess);

    // Assert
    Assert::IsTrue(pi.dwProcessId > 0);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(pi.hProcess, INFINITE));

    DWORD exitCode = 0;
    CHECK_WIN32_BOOL(::GetExitCodeProcess(pi.hProcess, &exitCode),
        L"GetExitCodeProcess");
    Assert::IsTrue(exitCode == 0);
}

void ShellUtilUnitTests::testShellCmdWithoutWorkingDirectorySpecified()
{
    // Arrange
    std::wstring working_directory = DVLib::GetCurrentDirectoryW();
    std::wstring command = DVLib::FormatMessage(
        L"cmd.exe /C if '%%cd%%'=='%s' (exit /b 0) else (echo '%%cd%%'!='%s' && exit /b 1)",
        working_directory.c_str(),
        working_directory.c_str());
    HANDLE hProcess;

    // Act
    DVLib::ShellCmd(command.c_str(), NULL, &hProcess, NULL);
    auto_handle pi_process(hProcess);

    // Assert
    Assert::IsTrue(hProcess != NULL);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(hProcess, INFINITE));

    DWORD exitCode = 0;
    CHECK_WIN32_BOOL(::GetExitCodeProcess(hProcess, &exitCode),
        L"GetExitCodeProcess");
    Assert::IsTrue(exitCode == 0);
}

void ShellUtilUnitTests::testShellCmdWithWorkingDirectorySpecified()
{
    // Arrange
    std::wstring working_directory = DVLib::GetTemporaryDirectoryW();
    HANDLE hProcess;

    // Act
    DVLib::ShellCmd(L"\"cmd.exe\" /C if '%%cd%%'=='%%temp%%' (exit /b 0) else (echo '%%cd%%'!='%%temp%%' && exit /b 1)", NULL, &hProcess, NULL, working_directory);
    auto_handle pi_process(hProcess);

    // Assert
    Assert::IsTrue(hProcess != NULL);
    Assert::IsTrue(WAIT_OBJECT_0 == ::WaitForSingleObject(hProcess, INFINITE));

    DWORD exitCode = 0;
    CHECK_WIN32_BOOL(::GetExitCodeProcess(hProcess, &exitCode),
        L"GetExitCodeProcess");
    Assert::IsTrue(exitCode == 0);
}