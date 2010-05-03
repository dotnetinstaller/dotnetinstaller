#include "StdAfx.h"
#include "OsUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(OsUtilUnitTests);

void OsUtilUnitTests::testGetOperatingSystemVersion()
{
	DVLib::OperatingSystem os = DVLib::GetOperatingSystemVersion();
	CPPUNIT_ASSERT(os != DVLib::winNone);
}

void OsUtilUnitTests::testGetOperatingSystemVersionString()
{
	std::wstring os_string = DVLib::GetOperatingSystemVersionString();
	std::wcout << std::endl << "Operating system: " << os_string;
	CPPUNIT_ASSERT(! os_string.empty());
}

void OsUtilUnitTests::testIsInOperatingSystemInRange()
{
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", DVLib::winNone, DVLib::winNone));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"win2000sp1,win2000sp2", DVLib::winNone, DVLib::winNone));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", 
		static_cast<DVLib::OperatingSystem>(DVLib::win2000sp1 + 1), static_cast<DVLib::OperatingSystem>(DVLib::win2000sp3 - 1)));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", DVLib::win2000sp1, DVLib::win2000sp1));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", 
		static_cast<DVLib::OperatingSystem>(DVLib::winNT4sp6a - 1), static_cast<DVLib::OperatingSystem>(DVLib::win2000sp1 - 1)));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"",
		static_cast<DVLib::OperatingSystem>(DVLib::winNT4sp6a - 1), DVLib::win2000sp1));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", DVLib::win2000sp1, DVLib::winNone));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"", DVLib::winNone, DVLib::win2000sp2));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"win2000sp1", DVLib::winNone, DVLib::winNone));
	CPPUNIT_ASSERT(! DVLib::IsInOperatingSystemInRange(DVLib::win2000sp1, L"!win2000sp1", DVLib::winNone, DVLib::winNone));	
}

void OsUtilUnitTests::testIsOperatingSystemID()
{
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemID(DVLib::winME, L""));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemID(DVLib::winME, L"winME"));
	CPPUNIT_ASSERT(! DVLib::IsOperatingSystemID(DVLib::winME, L"winXP"));
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

void OsUtilUnitTests::testIsOperatingSystemLCIDValue()
{
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidSystem), 
		DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidUser), 
		DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUser))));
	CPPUNIT_ASSERT(! DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidSystem), 
		L"123,456"));
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

void OsUtilUnitTests::testoscode2os()
{
	for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
	{
		OperatingSystem os = DVLib::oscode2os(Os2StringMap[i].oscode);
		CPPUNIT_ASSERT(os == Os2StringMap[i].os);
	}

	LPCWSTR KnownOperatingSystems[] = 
	{
		L"win95", L"win95osr2", L"win95Max",
		L"win98", L"win98se", L"win98Max",
		L"winME", L"winMEMax",
		L"winNT4", L"winNT4sp6", L"winNT4sp6a", L"winNT4Max",
		L"win2000", L"win2000sp1", L"win2000sp2", L"win2000sp3", L"win2000sp4", L"win2000Max",
		L"winXP", L"winXPsp1", L"winXPsp2", L"winXPsp3", L"winXPMax",
		L"winServer2003", L"winServer2003R2", L"winServer2003sp1", L"winServer2003R2sp1", L"winServer2003sp2", L"winServer2003R2sp2", L"winServer2003Max",
		L"winVista", L"winVistaSp1", L"winVistaSp2", L"winVistaMax",
		L"winServer2008", L"winServer2008R2", L"winServer2008Max",
		L"win7", L"win7Max",
	};

	for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
	{
		OperatingSystem os = DVLib::oscode2os(KnownOperatingSystems[i]);
		CPPUNIT_ASSERT(os != winNone);
	}
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
		win95, win95osr2, win95Max,
		win98, win98se, win98Max,
		winME, winMEMax,
		winNT4, winNT4sp6, winNT4sp6a, winNT4Max,
		win2000, win2000sp1, win2000sp2, win2000sp3, win2000sp4, win2000Max,
		winXP, winXPsp1, winXPsp2, winXPsp3, winXPMax,
		winServer2003, winServer2003R2, winServer2003sp1, winServer2003R2sp1, winServer2003sp2, winServer2003R2sp2, winServer2003Max,
		winVista, winVistaSp1, winVistaSp2, winVistaMax,
		winServer2008, winServer2008R2, winServer2008Max,
		win7, win7Max,
	};

	for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
	{
		std::wstring os_s = DVLib::os2wstring(KnownOperatingSystems[i]);
		CPPUNIT_ASSERT(! os_s.empty());
	}
}