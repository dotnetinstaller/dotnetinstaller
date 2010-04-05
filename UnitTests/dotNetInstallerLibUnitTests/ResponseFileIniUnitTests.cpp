#include "StdAfx.h"
#include "ResponseFileIniUnitTests.h"
#include "ResponseFileUnitTests.cpp"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ResponseFileIniUnitTests);

using namespace DVLib::UnitTests;

void ResponseFileIniUnitTests::testExec()
{
	ResponseFileUnitTestsTestData testdata[] = 
	{
		{ "", "" },
		{ "text", "text" },
		{ "#GUID", "#GUID" },
		{ "[section]\r\nGUID=#GUID", "[section]\r\nGUID=" + DVLib::wstring2string(
			InstallerSession::Instance->ExpandVariables(L"#GUID")) },
	};

	ResponseFileUnitTests::testExec(testdata, ARRAYSIZE(testdata));
}
