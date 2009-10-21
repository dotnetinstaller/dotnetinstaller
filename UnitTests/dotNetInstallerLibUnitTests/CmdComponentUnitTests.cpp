#include "StdAfx.h"
#include "CmdComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::CmdComponentUnitTests);

using namespace DVLib::UnitTests;

void CmdComponentUnitTests::testExec()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
	try
	{
		component.command = L"cmd.exe /C exit /b 1";
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
	}
}

void CmdComponentUnitTests::testExecUISilent()
{
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 0";
	component.command_basic = L"cmd.exe /C exit /b 3";
	component.Exec();
	component.Wait();
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelNotSet);
}

void CmdComponentUnitTests::testExecUIBasic()
{
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelBasic);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 2";
	component.command_basic = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelNotSet);
}


void CmdComponentUnitTests::testExecXCopy()
{
	CmdComponent component;
	std::wstring from = DVLib::GetModuleFileNameW();
	std::wstring todir = DVLib::GetTemporaryDirectoryW() + L"\\" + DVLib::GenerateGUIDStringW();
	std::wstring tofile = DVLib::DirectoryCombine(todir, DVLib::GetFileNameW(from));
	std::wcout << std::endl << tofile;
	DVLib::DirectoryCreate(todir);
	CPPUNIT_ASSERT(! DVLib::FileExists(tofile));
	component.command = L"xcopy \"" + ::DVLib::GetModuleFileNameW() + L"\" \"" + todir + L"\" /Y";
	std::wcout << std::endl << component.command;
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(DVLib::FileExists(tofile));
	DVLib::DirectoryDelete(todir);
}

void CmdComponentUnitTests::testReturnCodeZero()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
}

void CmdComponentUnitTests::testReturnCodeNonZero()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	try
	{
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// expected
	}
}

void CmdComponentUnitTests::testReturnCodeNonValue()
{
	CmdComponent component;
	// a success value
	component.returncodes_failure = L"!4";
	component.command = L"cmd.exe /C exit /b 4";
	component.Exec();
	component.Wait();
	// a failure value
	component.command = L"cmd.exe /C exit /b 5";
	try
	{
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// expected
	}
}

void CmdComponentUnitTests::testReturnCodeNone()
{
	// a 'none' failure code says that the component cannot return any failure
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.returncodes_failure = L"none";
	component.Exec();
	component.Wait();
}

void CmdComponentUnitTests::testReturnCodeRebootRequired()
{
	CmdComponent component;
	// a success value
	component.command = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	component.returncodes_reboot = L"0";
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(component.IsRebootRequired());
	component.command = L"cmd.exe /C exit /b 1053";
	component.returncodes_reboot = L"0,1053";
	component.Exec();
	component.Wait();
	// component will succeed, since this is a reboot return code
	CPPUNIT_ASSERT(component.IsRebootRequired());
	// component will fail since the return code is neither a default success (0) nor a reboot error code
	component.command = L"cmd.exe /C exit /b 1055";
	try
	{
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// expected
	}
	CPPUNIT_ASSERT(! component.IsRebootRequired());
}