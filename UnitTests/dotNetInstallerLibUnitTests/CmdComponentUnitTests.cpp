#include "StdAfx.h"
#include "CmdComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::CmdComponentUnitTests);

using namespace DVLib::UnitTests;

void CmdComponentUnitTests::testExec()
{
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 0";
	component.Exec();
	CPPUNIT_ASSERT(0 == component.Wait());	
	component.command = L"cmd.exe /C exit /b 1";
	component.Exec();
	CPPUNIT_ASSERT(1 == component.Wait());
}

void CmdComponentUnitTests::testExecUISilent()
{
	CurrentInstallUILevel.SetRuntimeLevel(InstallUILevelSilent);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 2";
	component.command_basic = L"cmd.exe /C exit /b 3";
	component.Exec();
	CPPUNIT_ASSERT(2 == component.Wait());
	CurrentInstallUILevel.SetRuntimeLevel(InstallUILevelNotSet);
}

void CmdComponentUnitTests::testExecUIBasic()
{
	CurrentInstallUILevel.SetRuntimeLevel(InstallUILevelBasic);
	CmdComponent component;
	component.command = L"cmd.exe /C exit /b 1";
	component.command_silent = L"cmd.exe /C exit /b 2";
	component.command_basic = L"cmd.exe /C exit /b 3";
	component.Exec();
	CPPUNIT_ASSERT(3 == component.Wait());
	CurrentInstallUILevel.SetRuntimeLevel(InstallUILevelNotSet);
}
