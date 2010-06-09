#include "StdAfx.h"
#include "CmdComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::CmdComponentUnitTests);

using namespace DVLib::UnitTests;

void CmdComponentUnitTests::testExecInstall()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 0";
	component.uninstall_command = L"cmd.exe /C exit /b 1";
	component.Exec();
	component.Wait();
	try
	{
		component.command = L"cmd.exe /C exit /b 1";
		component.uninstall_command = L"cmd.exe /C exit /b 0";
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
	}
}

void CmdComponentUnitTests::testExecUninstall()
{
	InstallSequenceState state;
	InstallerSession::Instance->sequence = SequenceUninstall;
	
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.uninstall_command = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
	try
	{
		component.command = L"cmd.exe /C exit /b 0";
		component.uninstall_command = L"cmd.exe /C exit /b 1";
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
	InstallUILevelState state;
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 0";
	component.command_basic = L"cmd.exe /C exit /b 3";
	component.Exec();
	component.Wait();
}

void CmdComponentUnitTests::testExecUIBasic()
{
	InstallUILevelState state;
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelBasic);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 2";
	component.command_basic = L"cmd.exe /C exit /b 0";
	component.Exec();
	component.Wait();
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
	component.returncodes_success = L"!4";
	component.command = L"cmd.exe /C exit /b 5";
	component.Exec();
	component.Wait();
	// a failure value
	component.command = L"cmd.exe /C exit /b 4";
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

void CmdComponentUnitTests::testReturnCodeAll()
{
	// a 'all' failure code says that the component cannot return any failure
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.returncodes_success = L"all";
	component.Exec();
	component.Wait();
}

void CmdComponentUnitTests::testReturnCodeNone()
{
	// a 'none' failure code says that the component will always fail
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.returncodes_success = L"none";
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

void CmdComponentUnitTests::testReturnCodeSuccess()
{
	CmdComponent component;
	// a success value
	component.returncodes_success = L"1,3010";
	component.command = L"cmd.exe /C exit /b 1";
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	component.command = L"cmd.exe /C exit /b 3010";
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	// component will fail since the return code is not in the success list
	component.command = L"cmd.exe /C exit /b 0";
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

void CmdComponentUnitTests::testMustReboot()
{
	CmdComponent component;
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	component.mustreboot = L"True";
	CPPUNIT_ASSERT(component.IsRebootRequired());
}
