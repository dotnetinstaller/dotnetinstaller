#include "StdAfx.h"
#include "MsuComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::MsuComponentUnitTests);

using namespace DVLib::UnitTests;

void MsuComponentUnitTests::testExecInstall()
{
	MsuComponent component;
	component.package = L"msidoesntexist.msu"; 
	component.cmdparameters = L"/quiet";
	component.Exec();
	try
	{
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// msu file cannot be opened
		CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
	}
}

void MsuComponentUnitTests::testExecInstallSilent()
{
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
	MsuComponent component;
	component.package = L"msidoesntexist.msu";
	component.cmdparameters_silent = L"/quiet";
	component.Exec();
	try
	{
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// msu file cannot be opened
		CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
	}
}

void MsuComponentUnitTests::testExecUninstall()
{
	InstallSequenceState state;
	InstallerSession::Instance->sequence = SequenceUninstall;
	MsuComponent component;
	try
	{
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// sequence is not supported
	}
}

void MsuComponentUnitTests::testExecUninstallSilent()
{
	InstallSequenceState state;
	InstallerSession::Instance->sequence = SequenceUninstall;
	InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
	MsuComponent component;
	component.package = L"msidoesntexist.msu";
	component.cmdparameters_silent = L"/quiet";
	try
	{
		component.Exec();
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{
		// sequence is not supported
	}
}