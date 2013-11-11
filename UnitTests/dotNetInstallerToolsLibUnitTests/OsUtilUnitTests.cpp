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

	// Validate empty filters
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003, L"winServer2003,,winServer2003R2", DVLib::winNone, DVLib::winNone));

	// If current OS is newer than Windows 7 it should still install if there is a filter set
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"+winXPsp2", DVLib::winNone, DVLib::winNone));
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"win7,winMax", DVLib::winNone, DVLib::winNone));
	// If current OS is newer than Windows 7 and filter is Windows 7 then it shouldn't install
	CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"win7", DVLib::winNone, DVLib::winNone));
	// If current OS is newer than Windows 7 and no range or filter is used then it should install
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"", DVLib::winNone, DVLib::winNone));
	// Check that the range works with the winMax value
	CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"", DVLib::winVista, DVLib::winMax));
	CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"", DVLib::winVista, DVLib::winMax));

	// Test ambiguous OS filter values
	{
		try
		{
			// Test ambiguous OS filter - combination of filter types
			DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"win2000sp1,!win2000sp2", DVLib::winNone, DVLib::winNone);
			throw "IsInOperatingSystemInRange was expected to throw std::exception";
		}
		catch(std::exception& ex)
		{
			// Expected exception
			std::cout << std::endl << "Expected exception: " << ex.what();
		}

		try
		{
			// Test ambiguous OS filter - filter and range values
			DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"win2000sp1,win2000sp2", DVLib::win7, DVLib::winNone);
			throw "IsInOperatingSystemInRange was expected to throw std::exception";
		}
		catch(std::exception& ex)
		{
			// Expected exception
			std::cout << std::endl << "Expected exception: " << ex.what();
		}

		try
		{
			// Test ambiguous OS filter - filter and range values
			DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"win2000sp1,win2000sp2", DVLib::winNone, DVLib::win7);
			throw "IsInOperatingSystemInRange was expected to throw std::exception";
		}
		catch(std::exception& ex)
		{
			// Expected exception
			std::cout << std::endl << "Expected exception: " << ex.what();
		}
	}

	// Test '+' filter using "+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista". This means install on Windows XP with SP3 or later, 
	// Windows Server 2003 with SP2 or later, Windows Server 2003 R2 with SP2 or later and any OS later than Windows Vista.
	{
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winNT4, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::win2000, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winXPsp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winXPsp3, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003Max, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVistaMax, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win7, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win7sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::win7Max, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
	}

	// Test '-' filter using "-winVistaSp2,-winServer2008R2". This means only install if OS is less than Windows Vista SP2 or less Windows Server 2008 R2.
	{
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp1, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008sp2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2008R2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::win7, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
		CPPUNIT_ASSERT(!DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
	}
}

void OsUtilUnitTests::testIsOperatingSystemID()
{
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemID(DVLib::winME, L""));
	CPPUNIT_ASSERT(DVLib::IsOperatingSystemID(DVLib::winME, L"winME"));
	CPPUNIT_ASSERT(! DVLib::IsOperatingSystemID(DVLib::winME, L"winXP"));
}

void OsUtilUnitTests::testGetOperatingSystemLCID()
{
	// there're serveral ways to obtain the operating system LCID, all should produce some LCID value
	CPPUNIT_ASSERT(0 != DVLib::GetOperatingSystemLCID(LcidSystem));
	CPPUNIT_ASSERT(0 != DVLib::GetOperatingSystemLCID(LcidUser));
	CPPUNIT_ASSERT(0 != DVLib::GetOperatingSystemLCID(LcidUserExe));
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

void OsUtilUnitTests::testGetLocale()
{
	std::wstring oslanguage = DVLib::GetLocale(DVLib::GetOperatingSystemLCID(LcidSystem), LOCALE_SISO639LANGNAME); // ISO language name
	CPPUNIT_ASSERT(oslanguage.length() > 0);
	CPPUNIT_ASSERT(oslanguage.length() == wcslen(oslanguage.c_str()));
	std::wstring osregion = DVLib::GetLocale(DVLib::GetOperatingSystemLCID(LcidSystem), LOCALE_SISO3166CTRYNAME); // ISO country name
	CPPUNIT_ASSERT(osregion.length() > 0);
	CPPUNIT_ASSERT(osregion.length() == wcslen(osregion.c_str()));
	std::wcout << std::endl << L"Locale: " << oslanguage << L"-" << osregion;
	CPPUNIT_ASSERT(DVLib::GetLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)) == L"en");
	CPPUNIT_ASSERT(DVLib::GetLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), LOCALE_SISO3166CTRYNAME) == L"US");
}

void OsUtilUnitTests::testGetISOLocale()
{
	CPPUNIT_ASSERT(DVLib::GetISOLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)) == L"en-US");
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
	// current processor architecture
	CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L""));
	CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L",mips"));
	CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L"!" + DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L",!mips"));
	CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64"));
	CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64,arm"));
	CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64, L"!x86"));
	CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64, L"!x64"));

	// known processor architectures
	for (int i = 0; i < ARRAYSIZE(processor_architectures); i++)
	{
		CPPUNIT_ASSERT(DVLib::IsProcessorArchitecture(processor_architectures[i].pa, processor_architectures[i].name));
		CPPUNIT_ASSERT(! DVLib::IsProcessorArchitecture(processor_architectures[i].pa, std::wstring(L"!") + processor_architectures[i].name));
	}

	{
		try
		{
			// ambiguous negation
			DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L"mips,!x86");
			throw "IsProcessorArchitecture was expected to throw std::exception";
		}
		catch(std::exception& ex)
		{
			std::cout << std::endl << "Expected exception: " << ex.what();
		}

		try
		{
			// invalid filter
			DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L"mips,foobar,!x86");
			throw "IsProcessorArchitecture was expected to throw std::exception";
		}
		catch(std::exception& ex)
		{
			std::cout << std::endl << "Expected exception: " << ex.what();
		}

	}
}

void OsUtilUnitTests::testIsWow64()
{
	std::wcout << std::endl << L"Wow64: " << DVLib::towstring(DVLib::IsWow64());
}

void OsUtilUnitTests::testWow64DisableWow64FsRedirection()
{
	LPVOID old_value = (LPVOID) 0xDEADBEEF;
	if (DVLib::IsWow64())
	{
		CPPUNIT_ASSERT(DVLib::Wow64DisableWow64FsRedirection(& old_value));
		CPPUNIT_ASSERT(old_value == NULL);
		CPPUNIT_ASSERT(DVLib::Wow64DisableWow64FsRedirection(& old_value));
		CPPUNIT_ASSERT(old_value != NULL);
		CPPUNIT_ASSERT(DVLib::Wow64RevertWow64FsRedirection(old_value));
	}
	else
	{
		CPPUNIT_ASSERT(! DVLib::Wow64DisableWow64FsRedirection(& old_value));
		CPPUNIT_ASSERT(! DVLib::Wow64RevertWow64FsRedirection(old_value));
	}
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
		L"winServer2008", L"winServer2008sp2", L"winServer2008R2", L"winServer2008Max",
		L"win7", L"win7sp1", L"win7Max",
		L"win8", L"win8_1", L"win8Max",
		L"win8Server", L"win8ServerR2", L"win8ServerMax",
		L"winMax"
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
		winServer2008, winServer2008sp2, winServer2008R2, winServer2008Max,
		win7, win7sp1, win7Max,
		win8, win8_1, win8Max,
		win8Server, win8ServerR2, win8ServerMax,
		winMax,
	};

	for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
	{
		std::wstring os_s = DVLib::os2wstring(KnownOperatingSystems[i]);
		CPPUNIT_ASSERT(! os_s.empty());
	}
}

void OsUtilUnitTests::testMuiGetUserDefaultUILCID()
{
	LCID lcid = DVLib::MuiGetUserDefaultUILCID();
	CPPUNIT_ASSERT(::GetUserDefaultUILanguage() == LANGIDFROMLCID(lcid));
}

void OsUtilUnitTests::testMuiGetSystemDefaultUILCID()
{
	LCID lcid = DVLib::MuiGetSystemDefaultUILCID();
	CPPUNIT_ASSERT(::GetSystemDefaultUILanguage() == LANGIDFROMLCID(lcid));
}

void OsUtilUnitTests::testOperatingSystemType()
{
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win95) == winNone);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winME) == winNone);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winNT4sp6a) == winNT4);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win2000sp4) == win2000);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winXP) == winXP);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winXPsp1) == winXP);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winXPsp2) == winXP);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winXPsp3) == winXP);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003) == winServer2003);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003sp1) == winServer2003);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003sp2) == winServer2003);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003R2) == winServer2003R2);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003R2sp1) == winServer2003R2);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003R2sp2) == winServer2003R2);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2003Max) == winServer2003);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winVista) == winVista);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winVistaSp1) == winVista);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winVistaSp1) == winVista);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2008) == winServer2008);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2008sp2) == winServer2008);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winServer2008R2) == winServer2008);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win7) == win7);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win7sp1) == win7);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win8) == win8);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win8_1) == win8);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win8Server) == win8Server);
	CPPUNIT_ASSERT(DVLib::OperatingSystemType(win8ServerR2) == win8Server);

	CPPUNIT_ASSERT(DVLib::OperatingSystemType(winMax) == winMax);
}
