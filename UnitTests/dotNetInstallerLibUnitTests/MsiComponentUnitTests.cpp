#include "StdAfx.h"
#include "MsiComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::MsiComponentUnitTests);

using namespace DVLib::UnitTests;

void MsiComponentUnitTests::testExec()
{
	MsiComponent component;
	component.package = L"msidoesntexist.msi"; 
	component.cmdparameters = L"/qn";
	component.Exec();
	try
	{
		component.Wait();
		throw "expected std::exception";
	}
	catch(std::exception& /* ex */)
	{
		// msi file cannot be opened
		CPPUNIT_ASSERT(1619 == component.GetProcessExitCode());
	}
}

void MsiComponentUnitTests::testGetCommandLine()
{
	struct TestData
	{
		std::wstring package;
		std::wstring cmdparameters;
		std::wstring command;
	};

	TestData testdata[] =
	{
		{ L"test.msi", L"", L"msiexec /I \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"test.msi") + L"\"" },
		{ L"{3DE50841-856E-4640-ABF4-0FF31560AA81}", L"", L"msiexec /I \"{3DE50841-856E-4640-ABF4-0FF31560AA81}\"" },
		{ L"3DE50841-856E-4640-ABF4-0FF31560AA81", L"", L"msiexec /I \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"3DE50841-856E-4640-ABF4-0FF31560AA81") + L"\"" },
		{ L"C:\\test.msi", L"X=Y", L"msiexec /I \"C:\\test.msi\" X=Y" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		MsiComponent component;
		component.package = testdata[i].package;
		component.cmdparameters = testdata[i].cmdparameters;
		std::wstring command = component.GetCommandLine();
		std::wcout << std::endl << L" " << command;
		CPPUNIT_ASSERT(testdata[i].command == command);
	}
}