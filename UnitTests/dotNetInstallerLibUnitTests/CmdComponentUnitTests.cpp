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

void CmdComponentUnitTests::testExecShell()
{
	std::wstring filename = DVLib::GetTemporaryFileNameW();
	DVLib::FileMove(filename, filename + L".txt");
	filename = filename + L".txt";

	CmdComponent component;
	component.command = filename;
	// default execution method is CreateProcess
	CPPUNIT_ASSERT(component.execution_method == DVLib::CemCreateProcess);
	try
	{
		component.Exec();
		throw "expected std::exception";
	}
	catch (std::exception& ex)
	{
		// expected - CreateProcess cannot run text files
		CPPUNIT_ASSERT(strstr(ex.what(), "CreateProcess") != NULL);
		CPPUNIT_ASSERT(strstr(ex.what(), "0x800700c1") != NULL);
	}

	component.execution_method = DVLib::CemShellExecute;
	component.Exec();
	::TerminateProcess(component.m_process_handle, 0);
	component.Wait();

	DVLib::FileDelete(filename);
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

	// Test legacy method of handling 0x84BE0BC2
	component.command = L"cmd.exe /C exit /b -2067919934"; // 0x84BE0BC2
	component.returncodes_reboot = L"2227047362";
	component.Exec();
	component.Wait();
	// component will succeed, since this is a reboot return code
	CPPUNIT_ASSERT(component.IsRebootRequired());

	// Test hex code
	component.command = L"cmd.exe /C exit /b 3010"; // 0xBC2
	component.returncodes_reboot = L"0x84BE0BC2,0x0BC2";
	component.Exec();
	component.Wait();
	// component will succeed, since this is a reboot return code
	CPPUNIT_ASSERT(component.IsRebootRequired());

	// Test hex code
	component.command = L"cmd.exe /C exit /b -2067919934"; // 0x84BE0BC2
	component.returncodes_reboot = L"0x84BE0BC2,0xBC2";
	component.Exec();
	component.Wait();
	// component will succeed, since this is a reboot return code
	CPPUNIT_ASSERT(component.IsRebootRequired());

	// Test hex code - E_FAIL 0x80004005
	component.command = L"cmd.exe /C exit /b 2147500037"; // 0x80004005
	component.returncodes_reboot = L"0x80004005";
	component.Exec();
	component.Wait();
	// component will succeed, since this is a reboot return code
	CPPUNIT_ASSERT(component.IsRebootRequired());
}

void CmdComponentUnitTests::testReturnCodeSuccess()
{
	CmdComponent component;
	// a success value
	component.returncodes_success = L"1,3010";
	component.command = L"cmd.exe /C exit /b 1";
	component.Exec();
	// component will succeed, return code in success list
	component.Wait();

	component.command = L"cmd.exe /C exit /b 3010";
	component.Exec();
	// component will succeed, return code in success list
	component.Wait();

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

	// Test hex code
	component.command = L"cmd.exe /C exit /b 3010"; // 0xBC2
	component.returncodes_success = L"0,0X0BC2";
	component.Exec();
	// component will succeed, return code in success list
	component.Wait();
}

void CmdComponentUnitTests::testMustReboot()
{
	CmdComponent component;
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	component.mustreboot = L"True";
	CPPUNIT_ASSERT(component.IsRebootRequired());
}

void CmdComponentUnitTests::testLoad()
{
	TiXmlDocument doc;
	doc.Parse("<component type=\"cmd\" \
			  command=\"test install\" \
			  uninstall_command=\"test uninstall\" \
			  execution_method=\"ShellExecute\"/>");
	CmdComponent component;
	component.Load(doc.RootElement());
	CPPUNIT_ASSERT(component.command.GetValue() == L"test install");
	CPPUNIT_ASSERT(component.uninstall_command.GetValue() == L"test uninstall");
	CPPUNIT_ASSERT(component.execution_method == DVLib::CemShellExecute);
}

void CmdComponentUnitTests::testWithHiddenWindow()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 0";
	component.hide_window = true;
	component.Exec();
	component.Wait();
	CPPUNIT_ASSERT(0 == component.GetExitCode());
}