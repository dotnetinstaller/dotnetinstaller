#include "StdAfx.h"
#include "InstallerSessionUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallerSessionUnitTests);

using namespace DVLib::UnitTests;

void InstallerSessionUnitTests::testExpandPathVariables()
{
	CPPUNIT_ASSERT(InstallerSession::Instance->GetSessionTempPath() == InstallerSession::Instance->ExpandPathVariables(L"#CABPATH"));
	CPPUNIT_ASSERT(DVLib::GetModuleDirectoryW() == InstallerSession::Instance->ExpandPathVariables(L"#APPPATH"));
	CPPUNIT_ASSERT(DVLib::GetSystemDirectoryW() == InstallerSession::Instance->ExpandPathVariables(L"#SYSTEMPATH"));
	CPPUNIT_ASSERT(DVLib::GetWindowsDirectoryW() == InstallerSession::Instance->ExpandPathVariables(L"#WINDOWSPATH"));
	CPPUNIT_ASSERT(DVLib::GetSystemWindowsDirectory() == InstallerSession::Instance->ExpandPathVariables(L"#SYSTEMWINDOWSPATH"));
	CPPUNIT_ASSERT(DVLib::GetTemporaryDirectoryW() == InstallerSession::Instance->ExpandPathVariables(L"#TEMPPATH"));
	CPPUNIT_ASSERT(DVLib::towstring(::GetCurrentProcessId()) == InstallerSession::Instance->ExpandPathVariables(L"#PID"));
	CPPUNIT_ASSERT(DVLib::GetTemporaryDirectoryW() + DVLib::GetTemporaryDirectoryW() == 
		InstallerSession::Instance->ExpandPathVariables(L"#TEMPPATH#TEMPPATH"));
	CPPUNIT_ASSERT(L"{" + DVLib::GetTemporaryDirectoryW() + L"|" + DVLib::GetTemporaryDirectoryW() + L"}" == 
		InstallerSession::Instance->ExpandPathVariables(L"{#TEMPPATH|#TEMPPATH}"));
}

void InstallerSessionUnitTests::testExpandPathVariablesBackslashes()
{
	// don't introduce double-backslashes in path varables, bug 4378
	std::wstring path_without_bs = DVLib::trimright(DVLib::GetTemporaryDirectoryW(), L"\\");
	std::wstring path_with_bs = path_without_bs + L"\\";
	// without
	std::wcout << std::endl << L"Path: " << path_without_bs;
	InstallerSession::Instance->SessionCABPath = path_without_bs;
	std::wstring path_without_bs_subdir = DVLib::DirectoryCombine(path_without_bs, L"s1\\s2");
	std::wcout << std::endl << L"Subdir: " << path_without_bs_subdir;
	std::wstring path_without_bs_expanded = InstallerSession::Instance->ExpandPathVariables(L"#CABPATH\\s1\\s2");
	std::wcout << std::endl << L"Expanded: " << path_without_bs_expanded;
	CPPUNIT_ASSERT(path_without_bs_subdir == path_without_bs_expanded);
	// more without combinations
	InstallerSession::Instance->SessionCABPath = path_without_bs;
	CPPUNIT_ASSERT(path_without_bs == InstallerSession::Instance->ExpandPathVariables(L"#CABPATH"));
	CPPUNIT_ASSERT(path_with_bs == InstallerSession::Instance->ExpandPathVariables(L"#CABPATH\\"));
	// with
	std::wcout << std::endl << L"Path: " << path_with_bs;
	InstallerSession::Instance->SessionCABPath = path_with_bs;
	std::wstring path_with_bs_subdir = DVLib::DirectoryCombine(path_with_bs, L"s1\\s2");
	std::wcout << std::endl << L"Subdir: " << path_with_bs_subdir;
	std::wstring path_with_bs_expanded = InstallerSession::Instance->ExpandPathVariables(L"#CABPATH\\s1\\s2");
	std::wcout << std::endl << L"Expanded: " << path_with_bs_expanded;
	CPPUNIT_ASSERT(path_with_bs_subdir == path_with_bs_expanded);
	// more with combinations
	InstallerSession::Instance->SessionCABPath = path_with_bs;
	CPPUNIT_ASSERT(path_with_bs == InstallerSession::Instance->ExpandPathVariables(L"#CABPATH"));
	CPPUNIT_ASSERT(path_with_bs == InstallerSession::Instance->ExpandPathVariables(L"#CABPATH\\"));
}

void InstallerSessionUnitTests::testExpandEnvironmentVariables()
{
	CPPUNIT_ASSERT(DVLib::GetWindowsDirectoryW() == InstallerSession::Instance->ExpandVariables(L"%SystemRoot%"));
	CPPUNIT_ASSERT(DVLib::GetWindowsDirectoryW() + DVLib::GetWindowsDirectoryW() == 
		InstallerSession::Instance->ExpandVariables(L"%SystemRoot%%SystemRoot%"));
	CPPUNIT_ASSERT(L"{" + DVLib::GetWindowsDirectoryW() + L"|" + DVLib::GetWindowsDirectoryW() + L"}" == 
		InstallerSession::Instance->ExpandVariables(L"{%SystemRoot%|%SystemRoot%}"));
}

void InstallerSessionUnitTests::testExpandRegistryVariables()
{
	std::wstring common_files_dir = DVLib::RegistryGetStringValue(
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", L"CommonFilesDir");
	CPPUNIT_ASSERT(common_files_dir == InstallerSession::Instance->ExpandRegistryVariables(L"@[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CommonFilesDir]"));
	CPPUNIT_ASSERT(common_files_dir + common_files_dir == 
		InstallerSession::Instance->ExpandRegistryVariables(L"@[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CommonFilesDir]@[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CommonFilesDir]"));
	CPPUNIT_ASSERT(L"{" + common_files_dir + L"|" + common_files_dir + L"}" == 
		InstallerSession::Instance->ExpandRegistryVariables(L"{@[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CommonFilesDir]|@[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CommonFilesDir]}"));
	// missing value, missing default
	try
	{
		InstallerSession::Instance->ExpandRegistryVariables(L"@[HKEY_LOCAL_MACHINE\\SOFTWARE\\" + DVLib::GenerateGUIDStringW() + L"]");
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
	}
	// with default
	CPPUNIT_ASSERT(L"DefaultValue" == InstallerSession::Instance->ExpandRegistryVariables(
		L"@[HKEY_LOCAL_MACHINE\\SOFTWARE\\" + DVLib::GenerateGUIDStringW() + L",DefaultValue]"));
}

void InstallerSessionUnitTests::testEnableRunOnReboot()
{
	InstallerSession::Instance->EnableRunOnReboot();

	std::wstring registryRunCmd = DVLib::RegistryGetStringValue(
		HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		DVLib::GetFileNameW(DVLib::GetModuleFileNameW()));

	std::wcout << std::endl << "Reboot cmd: " << registryRunCmd;
	CPPUNIT_ASSERT(! registryRunCmd.empty());
	CPPUNIT_ASSERT(registryRunCmd.find(L"/Reboot") != registryRunCmd.npos);

	InstallerSession::Instance->DisableRunOnReboot();

	CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(
		HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		DVLib::GetFileNameW(DVLib::GetModuleFileNameW())));
}

void InstallerSessionUnitTests::testGetRebootCmd()
{
	struct TestData
	{
		LPCWSTR path;
		LPCWSTR args;
		LPCWSTR add;
		std::wstring cmd;
	};

	std::wstring module = L"\"" + DVLib::GetModuleFileNameW() + L"\"";
	std::wstring args = DVLib::trim((::GetCommandLineW() + wcslen(__targv[0]) + 
			(::GetCommandLineW()[0] == '\"' ? 2 : 0)));
	if (! args.empty()) args = L" " + args;

	TestData testdata[] = 
	{
		{ L"", L"", L"", module + args + L" /Reboot" },
		{ L"path", L"", L"", L"\"path\"" + args + L" /Reboot" },
		{ L"", L"args", L"", module + args + L" args /Reboot" },
		{ L"path", L"args", L"", L"\"path\"" + args + L" args /Reboot" },
		{ L"", L"", L"add", module + args + L" add /Reboot" },
		{ L"path", L"", L"add", L"\"path\"" + args + L" add /Reboot" },
		{ L"", L"args", L"add", module + args + L" args add /Reboot" },
		{ L"path", L"args", L"add", L"\"path\"" + args + L" args add /Reboot" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		InstallerLauncher::Instance->SetLauncherPath(testdata[i].path);
		InstallerLauncher::Instance->SetLauncherArgs(testdata[i].args);
		std::wstring cmd = InstallerSession::Instance->GetRebootCmd(testdata[i].add);
		std::wcout << std::endl << i << ": " << cmd;
		CPPUNIT_ASSERT(cmd == testdata[i].cmd);
	}
}