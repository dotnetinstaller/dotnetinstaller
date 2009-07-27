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
}
