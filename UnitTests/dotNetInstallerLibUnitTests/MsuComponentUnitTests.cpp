#include "StdAfx.h"
#include "MsuComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::MsuComponentUnitTests);

using namespace DVLib::UnitTests;

void MsuComponentUnitTests::testExec()
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
