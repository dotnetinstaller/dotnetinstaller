#include "StdAfx.h"
#include "OpenFileComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::OpenFileComponentUnitTests);

using namespace DVLib::UnitTests;

void OpenFileComponentUnitTests::testExec()
{
	OpenFileComponent component;
	component.file = L"cmd.exe /C";
	component.Exec();
}

void OpenFileComponentUnitTests::testMustReboot()
{
	OpenFileComponent component;
	CPPUNIT_ASSERT(! component.IsRebootRequired());
	component.mustreboot = L"True";
	CPPUNIT_ASSERT(component.IsRebootRequired());
}
