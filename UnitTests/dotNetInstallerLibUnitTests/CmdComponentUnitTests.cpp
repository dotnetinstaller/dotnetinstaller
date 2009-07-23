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
