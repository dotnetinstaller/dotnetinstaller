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
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidUserExe) == L"UserExe");
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidSystem) == L"System");
	CPPUNIT_ASSERT(DVLib::lcidtype2wstring(LcidUser) == L"User" );
}

void OsUtilUnitTests::testlcidtype2wstring()
{
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"") == DVLib::LcidUser);
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"UserExe") == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"System") == DVLib::LcidSystem);
	CPPUNIT_ASSERT(DVLib::wstring2lcidtype(L"User") == DVLib::LcidUser);
}

void OsUtilUnitTests::testos2wstring()
{
	for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
	{
		std::wstring os_s = DVLib::os2wstring(Os2StringMap[i].os);
		CPPUNIT_ASSERT(os_s == Os2StringMap[i].name);
	}

	OperatingSystem KnownOperatingSystems[] = 
	{
		win95, win95osr2, win98, win98se, winME,
		winNT4, winNT4sp6, winNT4sp6a,
		win2000, win2000sp1, win2000sp2, win2000sp3, win2000sp4,
		winXP, winXPsp1, winXPsp2, winXPsp3,
		winServer2003, winServer2003R2, winServer2003sp1, winServer2003R2sp1, winServer2003sp2, winServer2003R2sp2,
		winVista, winVistaSp1, winVistaSp2,
		winServer2008, winServer2008R2, 
		win7
	};

	for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
	{
		std::wstring os_s = DVLib::os2wstring(KnownOperatingSystems[i]);
		CPPUNIT_ASSERT(! os_s.empty());
	}
}