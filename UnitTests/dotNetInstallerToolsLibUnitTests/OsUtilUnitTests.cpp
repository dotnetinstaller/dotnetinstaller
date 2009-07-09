#include "StdAfx.h"
#include "OsUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(OsUtilUnitTests);

void OsUtilUnitTests::testGetOperatingSystemVersion()
{
	DVLib::OperatingSystem os = DVLib::GetOperatingSystemVersion();
	CPPUNIT_ASSERT(os != winMin && os != winMax && os != winNotSupported);
}

void OsUtilUnitTests::testGetOperatingSystemVersionString()
{
	std::wstring os_string = DVLib::GetOperatingSystemVersionString();
	std::wcout << std::endl << "Operating system: " << os_string;
	CPPUNIT_ASSERT(! os_string.empty());
}

void OsUtilUnitTests::testIsInOperatingSystemInRange()
{
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"49", L"59"));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"50", L"59"));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"49", L"50"));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"39", L"49"));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"49", L""));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(static_cast<OperatingSystem>(50), L"", L"55"));
}

void OsUtilUnitTests::testGetOperatingSystemLCID()
{
	LCID lcid_system = DVLib::GetOperatingSystemLCID(LcidSystem);
	LCID lcid_user = DVLib::GetOperatingSystemLCID(LcidUser);
	LCID lcid_userexe = DVLib::GetOperatingSystemLCID(LcidUserExe);
	std::wcout << std::endl << "system lcid: " << lcid_system;
	std::wcout << std::endl << "user lcid: " << lcid_user;
	std::wcout << std::endl << "userexe lcid: " << lcid_userexe;
	CPPUNIT_ASSERT(lcid_system != 0);
	CPPUNIT_ASSERT(lcid_system == lcid_user);
	CPPUNIT_ASSERT(lcid_system == lcid_userexe);
}

void OsUtilUnitTests::testIsOperatingSystemLCID()
{
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCID(LcidSystem, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCID(LcidUser, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUser))));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCID(LcidUserExe, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUserExe))));
	CPPUNIT_ASSERT(! DVLib::IsOperatingSystemLCID(LcidSystem, L"!" + DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCID(LcidSystem, L"123," + DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
	CPPUNIT_ASSERT(! DVLib::IsOperatingSystemLCID(LcidSystem, L"123,456"));
}

void OsUtilUnitTests::testCompareVersion()
{
	struct TestData
	{
		LPCWSTR l;
		LPCWSTR r;
		int cmp;
	};

	TestData testdata[] = 
	{
		{ L"", L"", 0 },
		{ L"1", L"", 1 },
		{ L"", L"1", -1 },
		{ L"1.0", L"0.9", 1 },
		{ L"0.1", L"0.9", -1 },
		{ L"1.1", L"1.0", 1 },
		{ L"1.1", L"1.1", 0 },
		{ L"1.0", L"1.1", -1 },
		{ L"1.0.0", L"1", 0 },
		{ L"1.0.0.0", L"1", 0 },
		{ L"1.0.0.0", L"1.0.0.1", -1 },
	};

	for(int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		int cmp = DVLib::CompareVersion(testdata[i].l, testdata[i].r);
		std::wcout << std::endl << testdata[i].l << L" vs. " << testdata[i].r << L" => " << cmp;
		CPPUNIT_ASSERT(cmp == testdata[i].cmp);
	}
}

void OsUtilUnitTests::testGetProcessorArchitecture()
{
	WORD pa = DVLib::GetProcessorArchitecture();
	std::wcout << std::endl << L"Processor: " << DVLib::pa2wstring(pa);
	CPPUNIT_ASSERT(pa >= 0);
}

void OsUtilUnitTests::testProcessorArchitectureToFromString()
{
	for (int i = 0; i < ARRAYSIZE(processor_architectures); i++)
	{
		CPPUNIT_ASSERT(DVLib::wstring2pa(processor_architectures[i].name) == processor_architectures[i].pa);
		CPPUNIT_ASSERT(DVLib::pa2wstring(processor_architectures[i].pa) == processor_architectures[i].name);
	}
}

void OsUtilUnitTests::testIsProcessorArchitecture()
{
	for (int i = 0; i < ARRAYSIZE(processor_architectures); i++)
	{
		CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(processor_architectures[i].pa, processor_architectures[i].name));
		CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(processor_architectures[i].pa, std::wstring(L"!") + processor_architectures[i].name));
	}

	// some known ones
	CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64"));
	CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64,arm"));
}

void OsUtilUnitTests::testIsWow64()
{
	std::wcout << std::endl << L"Wow64: " << DVLib::towstring(DVLib::IsWow64());
}

void OsUtilUnitTests::testExistWindowsSystem()
{
	DVLib::ExitWindowsSystem(EWX_LOGOFF);
}

void OsUtilUnitTests::testwstring2lcidtype()
{
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidUserExe) == L"LcidUserExe");
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidSystem) == L"LcidSystem");
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidUser) == L"LcidUser" );
}

void OsUtilUnitTests::testlcidtype2wstring()
{
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"LcidUserExe") == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"LcidSystem") == DVLib::LcidSystem);
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"LcidUser") == DVLib::LcidUser);
}
