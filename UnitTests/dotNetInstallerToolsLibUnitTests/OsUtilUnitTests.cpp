#include "StdAfx.h"
#include "OsUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void OsUtilUnitTests::testGetOperatingSystemVersion()
{
    DVLib::OperatingSystem os = DVLib::GetOperatingSystemVersion();
    Assert::IsTrue(os != DVLib::winNone);
}

void OsUtilUnitTests::testGetOperatingSystemVersionString()
{
    std::wstring os_string = DVLib::GetOperatingSystemVersionString();
    std::wcout << std::endl << "Operating system: " << os_string;
    Assert::IsTrue(! os_string.empty());
}

void OsUtilUnitTests::testIsInOperatingSystemInRange()
{
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", DVLib::winNone, DVLib::winNone));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"winServer2003sp1,winServer2003sp2", DVLib::winNone, DVLib::winNone));
    Assert::IsTrue(! DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", 
        static_cast<DVLib::OperatingSystem>(DVLib::winServer2003sp1 + 1), static_cast<DVLib::OperatingSystem>(DVLib::winServer2003sp2)));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", DVLib::winServer2003sp1, DVLib::winServer2003sp1));
    Assert::IsTrue(! DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", 
        static_cast<DVLib::OperatingSystem>(DVLib::winXPsp3 - 1), static_cast<DVLib::OperatingSystem>(DVLib::winServer2003sp1 - 1)));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"",
        static_cast<DVLib::OperatingSystem>(DVLib::winXPsp3 - 1), DVLib::winServer2003sp1));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", DVLib::winServer2003sp1, DVLib::winNone));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"", DVLib::winNone, DVLib::winServer2003sp2));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"winServer2003sp1", DVLib::winNone, DVLib::winNone));
    Assert::IsTrue(! DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"!winServer2003sp1", DVLib::winNone, DVLib::winNone));	

    // Validate empty filters
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003, L"winServer2003,,winServer2003R2", DVLib::winNone, DVLib::winNone));

    // If current OS is newer than Windows 7 it should still install if there is a filter set
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"+winXPsp2", DVLib::winNone, DVLib::winNone));
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"win7,winMax", DVLib::winNone, DVLib::winNone));
    // If current OS is newer than Windows 7 and filter is Windows 7 then it shouldn't install
    Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"win7", DVLib::winNone, DVLib::winNone));
    // If current OS is newer than Windows 7 and no range or filter is used then it should install
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"", DVLib::winNone, DVLib::winNone));
    // Check that the range works with the winMax value
    Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"", DVLib::winVista, DVLib::winMax));
    Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"", DVLib::winVista, DVLib::winMax));

    // Test ambiguous OS filter values
    {
        try
        {
            // Test ambiguous OS filter - combination of filter types
            DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"winServer2003sp1,!winServer2003sp2", DVLib::winNone, DVLib::winNone);
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
            DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"winServer2003sp1,winServer2003sp2", DVLib::win7, DVLib::winNone);
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
            DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"winServer2003sp1,winServer2003sp2", DVLib::winNone, DVLib::win7);
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
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winXPsp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winXPsp3, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003R2sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2003Max, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVistaMax, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008sp2, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::win7, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::win7sp1, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::win7Max, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"+winXPsp3,+winServer2003sp2,+winServer2003R2sp2,+winVista", DVLib::winNone, DVLib::winNone));
    }

    // Test '-' filter using "-winVistaSp2,-winServer2008R2". This means only install if OS is less than Windows Vista SP2 or less Windows Server 2008 R2.
    {
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winXP, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVista, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp1, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winVistaSp2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(DVLib::IsInOperatingSystemInRange(DVLib::winServer2008sp2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winServer2008R2, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));

        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::win7, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
        Assert::IsTrue(!DVLib::IsInOperatingSystemInRange(DVLib::winMax, L"-winVistaSp2,-winServer2008R2", DVLib::winNone, DVLib::winNone));
    }
}

void OsUtilUnitTests::testIsOperatingSystemID()
{
    Assert::IsTrue(DVLib::IsOperatingSystemID(DVLib::winXP, L""));
    Assert::IsTrue(DVLib::IsOperatingSystemID(DVLib::winXP, L"winXP"));
    Assert::IsTrue(!DVLib::IsOperatingSystemID(DVLib::winServer2003, L"winXP"));
}

void OsUtilUnitTests::testGetOperatingSystemLCID()
{
    // there're serveral ways to obtain the operating system LCID, all should produce some LCID value
    Assert::IsTrue(0 != DVLib::GetOperatingSystemLCID(LcidSystem));
    Assert::IsTrue(0 != DVLib::GetOperatingSystemLCID(LcidUser));
    Assert::IsTrue(0 != DVLib::GetOperatingSystemLCID(LcidUserExe));
}

void OsUtilUnitTests::testIsOperatingSystemLCID()
{
    Assert::IsTrue(DVLib::IsOperatingSystemLCID(LcidSystem, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
    Assert::IsTrue(DVLib::IsOperatingSystemLCID(LcidUser, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUser))));
    Assert::IsTrue(DVLib::IsOperatingSystemLCID(LcidUserExe, DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUserExe))));
    Assert::IsTrue(! DVLib::IsOperatingSystemLCID(LcidSystem, L"!" + DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
    Assert::IsTrue(DVLib::IsOperatingSystemLCID(LcidSystem, L"123," + DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
    Assert::IsTrue(! DVLib::IsOperatingSystemLCID(LcidSystem, L"123,456"));
}

void OsUtilUnitTests::testIsOperatingSystemLCIDValue()
{
    Assert::IsTrue(DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidSystem), 
        DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidSystem))));
    Assert::IsTrue(DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidUser), 
        DVLib::towstring(DVLib::GetOperatingSystemLCID(LcidUser))));
    Assert::IsTrue(! DVLib::IsOperatingSystemLCIDValue(DVLib::GetOperatingSystemLCID(LcidSystem), 
        L"123,456"));
}

void OsUtilUnitTests::testGetLocale()
{
    std::wstring oslanguage = DVLib::GetLocale(DVLib::GetOperatingSystemLCID(LcidSystem), LOCALE_SISO639LANGNAME); // ISO language name
    Assert::IsTrue(oslanguage.length() > 0);
    Assert::IsTrue(oslanguage.length() == wcslen(oslanguage.c_str()));
    std::wstring osregion = DVLib::GetLocale(DVLib::GetOperatingSystemLCID(LcidSystem), LOCALE_SISO3166CTRYNAME); // ISO country name
    Assert::IsTrue(osregion.length() > 0);
    Assert::IsTrue(osregion.length() == wcslen(osregion.c_str()));
    std::wcout << std::endl << L"Locale: " << oslanguage << L"-" << osregion;
    Assert::IsTrue(DVLib::GetLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)) == L"en");
    Assert::IsTrue(DVLib::GetLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), LOCALE_SISO3166CTRYNAME) == L"US");
}

void OsUtilUnitTests::testGetISOLocale()
{
    Assert::IsTrue(DVLib::GetISOLocale(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)) == L"en-US");
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

        { L"v1", L"", 1 },
        { L"", L"v1", -1 },
        { L"v1.0", L"0.9", 1 },
        { L"0.1", L"v0.9", -1 },
        { L"1.1", L"v1.0", 1 },
        { L"1.1", L"V1.1", 0 },
        { L"1.0", L"V1.1", -1 },
        { L"V1.0.0", L"1", 0 },
        { L"v1.0.0.0", L"V1", 0 },
        { L"V1.0.0.0", L"v1.0.0.1", -1 },
    };

    for(int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        int cmp = DVLib::CompareVersion(testdata[i].l, testdata[i].r);
        std::wcout << std::endl << testdata[i].l << L" vs. " << testdata[i].r << L" => " << cmp;
        Assert::IsTrue(cmp == testdata[i].cmp);
    }
}

void OsUtilUnitTests::testGetProcessorArchitecture()
{
    WORD pa = DVLib::GetProcessorArchitecture();
    std::wcout << std::endl << L"Processor: " << DVLib::pa2wstring(pa);
    Assert::IsTrue(pa >= 0);
}

void OsUtilUnitTests::testProcessorArchitectureToFromString()
{
    for (int i = 0; i < ARRAYSIZE(processor_architectures); i++)
    {
        Assert::IsTrue(DVLib::wstring2pa(processor_architectures[i].name) == processor_architectures[i].pa);
        Assert::IsTrue(DVLib::pa2wstring(processor_architectures[i].pa) == processor_architectures[i].name);
    }
}

void OsUtilUnitTests::testIsProcessorArchitecture()
{
    // current processor architecture
    Assert::IsTrue(DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L""));
    Assert::IsTrue(DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L",mips"));
    Assert::IsTrue(! DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), L"!" + DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L",!mips"));
    Assert::IsTrue(! DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64"));
    Assert::IsTrue(DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_ARM, L"alpha64,arm"));
    Assert::IsTrue(DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64, L"!x86"));
    Assert::IsTrue(! DVLib::IsProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64, L"!x64"));

    // known processor architectures
    for (int i = 0; i < ARRAYSIZE(processor_architectures); i++)
    {
        Assert::IsTrue(DVLib::IsProcessorArchitecture(processor_architectures[i].pa, processor_architectures[i].name));
        Assert::IsTrue(! DVLib::IsProcessorArchitecture(processor_architectures[i].pa, std::wstring(L"!") + processor_architectures[i].name));
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
        Assert::IsTrue(DVLib::Wow64DisableWow64FsRedirection(& old_value));
        Assert::IsTrue(old_value == NULL);
        Assert::IsTrue(DVLib::Wow64DisableWow64FsRedirection(& old_value));
        Assert::IsTrue(old_value != NULL);
        Assert::IsTrue(DVLib::Wow64RevertWow64FsRedirection(old_value));
    }
    else
    {
        Assert::IsTrue(! DVLib::Wow64DisableWow64FsRedirection(& old_value));
        Assert::IsTrue(! DVLib::Wow64RevertWow64FsRedirection(old_value));
    }
}

void OsUtilUnitTests::testwstring2lcidtype()
{
    Assert::IsTrue(DVLib::lcidtype2wstring(LcidUserExe) == L"UserExe");
    Assert::IsTrue(DVLib::lcidtype2wstring(LcidSystem) == L"System");
    Assert::IsTrue(DVLib::lcidtype2wstring(LcidUser) == L"User" );
}

void OsUtilUnitTests::testlcidtype2wstring()
{
    Assert::IsTrue(DVLib::wstring2lcidtype(L"") == DVLib::LcidUser);
    Assert::IsTrue(DVLib::wstring2lcidtype(L"UserExe") == DVLib::LcidUserExe);
    Assert::IsTrue(DVLib::wstring2lcidtype(L"System") == DVLib::LcidSystem);
    Assert::IsTrue(DVLib::wstring2lcidtype(L"User") == DVLib::LcidUser);
}

void OsUtilUnitTests::testoscode2os()
{
    for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
    {
        OperatingSystem os = DVLib::oscode2os(Os2StringMap[i].oscode);
        Assert::IsTrue(os == Os2StringMap[i].os);
    }

    LPCWSTR KnownOperatingSystems[] = 
    {
        L"winXP", L"winXPsp1", L"winXPsp2", L"winXPsp3", L"winXPMax",
        L"winServer2003", L"winServer2003R2", L"winServer2003sp1", L"winServer2003R2sp1", L"winServer2003sp2", L"winServer2003R2sp2", L"winServer2003Max",
        L"winVista", L"winVistaSp1", L"winVistaSp2", L"winVistaMax",
        L"winServer2008", L"winServer2008sp2", L"winServer2008R2", L"winServer2008R2sp1", L"winServer2008Max",
        L"win7", L"win7sp1", L"win7Max",
        L"win8", L"win8_1", L"win8Max",
        L"win8Server", L"win8ServerR2", L"win8ServerMax",
        L"win10", L"win10_1511", L"win10_1607", L"win10_1703", L"win10_1709", L"win10_1803", L"win10_1809", L"win10_1903", L"win10_1909", L"win10_2004", L"win10_20H2", L"win10_21H1", L"win10_21H2", L"win10Max",
        L"win10Server", L"win10ServerMax",
        L"winServer2019", L"winServer2019Max",
        L"winServer2022", L"winServer2022Max",
        L"win11", L"win11Max",
        L"winMax"
    };

    for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
    {
        OperatingSystem os = DVLib::oscode2os(KnownOperatingSystems[i]);
        Assert::IsTrue(os != winNone);
    }
}

void OsUtilUnitTests::testos2wstring()
{
    for (int i = 0; i < ARRAYSIZE(Os2StringMap); i++)
    {
        std::wstring os_s = DVLib::os2wstring(Os2StringMap[i].os);
        Assert::IsTrue(os_s == Os2StringMap[i].name);
    }

    OperatingSystem KnownOperatingSystems[] = 
    {
        winXP, winXPsp1, winXPsp2, winXPsp3, winXPMax,
        winServer2003, winServer2003R2, winServer2003sp1, winServer2003R2sp1, winServer2003sp2, winServer2003R2sp2, winServer2003Max,
        winVista, winVistaSp1, winVistaSp2, winVistaMax,
        winServer2008, winServer2008sp2, winServer2008R2, winServer2008R2sp1, winServer2008Max,
        win7, win7sp1, win7Max,
        win8, win8_1, win8Max,
        win8Server, win8ServerR2, win8ServerMax,
        win10, win10_1511, win10_1607, win10_1703, win10_1709, win10_1803, win10_1809, win10_1903, win10_1909, win10_2004, win10_20H2, win10_21H1, win10_21H2, win10Max,
        win10Server, win10ServerMax,
        winServer2019, winServer2019Max,
        winServer2022, winServer2022Max,
        win11, win11Max,
        winMax,
    };

    for (int i = 0; i < ARRAYSIZE(KnownOperatingSystems); i++)
    {
        std::wstring os_s = DVLib::os2wstring(KnownOperatingSystems[i]);
        Assert::IsTrue(! os_s.empty());
    }
}

void OsUtilUnitTests::testMuiGetUserDefaultUILCID()
{
    LCID lcid = DVLib::MuiGetUserDefaultUILCID();
    Assert::IsTrue(::GetUserDefaultUILanguage() == LANGIDFROMLCID(lcid));
}

void OsUtilUnitTests::testMuiGetSystemDefaultUILCID()
{
    LCID lcid = DVLib::MuiGetSystemDefaultUILCID();
    Assert::IsTrue(::GetSystemDefaultUILanguage() == LANGIDFROMLCID(lcid));
}

void OsUtilUnitTests::testOperatingSystemType()
{
    Assert::IsTrue(DVLib::OperatingSystemType(winXP) == winXP);
    Assert::IsTrue(DVLib::OperatingSystemType(winXPsp1) == winXP);
    Assert::IsTrue(DVLib::OperatingSystemType(winXPsp2) == winXP);
    Assert::IsTrue(DVLib::OperatingSystemType(winXPsp3) == winXP);
    Assert::IsTrue(DVLib::OperatingSystemType(winXPMax) == winXP);

    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003) == winServer2003);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003sp1) == winServer2003);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003sp2) == winServer2003);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003R2) == winServer2003R2);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003R2sp1) == winServer2003R2);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003R2sp2) == winServer2003R2);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2003Max) == winServer2003);

    Assert::IsTrue(DVLib::OperatingSystemType(winVista) == winVista);
    Assert::IsTrue(DVLib::OperatingSystemType(winVistaSp1) == winVista);
    Assert::IsTrue(DVLib::OperatingSystemType(winVistaSp1) == winVista);
    Assert::IsTrue(DVLib::OperatingSystemType(winVistaMax) == winVista);

    Assert::IsTrue(DVLib::OperatingSystemType(winServer2008) == winServer2008);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2008sp2) == winServer2008);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2008R2) == winServer2008);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2008R2sp1) == winServer2008);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2008Max) == winServer2008);

    Assert::IsTrue(DVLib::OperatingSystemType(win7) == win7);
    Assert::IsTrue(DVLib::OperatingSystemType(win7sp1) == win7);
    Assert::IsTrue(DVLib::OperatingSystemType(win7Max) == win7);

    Assert::IsTrue(DVLib::OperatingSystemType(win8) == win8);
    Assert::IsTrue(DVLib::OperatingSystemType(win8_1) == win8);
    Assert::IsTrue(DVLib::OperatingSystemType(win8Max) == win8);

    Assert::IsTrue(DVLib::OperatingSystemType(win8Server) == win8Server);
    Assert::IsTrue(DVLib::OperatingSystemType(win8ServerR2) == win8Server);
    Assert::IsTrue(DVLib::OperatingSystemType(win8ServerMax) == win8Server);

    Assert::IsTrue(DVLib::OperatingSystemType(win10) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1511) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1607) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1703) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1709) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1803) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1809) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1903) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_1909) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_2004) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_20H2) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_21H1) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10_21H2) == win10);
    Assert::IsTrue(DVLib::OperatingSystemType(win10Max) == win10);

    Assert::IsTrue(DVLib::OperatingSystemType(win10Server) == win10Server);
    Assert::IsTrue(DVLib::OperatingSystemType(win10ServerMax) == win10Server);

    Assert::IsTrue(DVLib::OperatingSystemType(winServer2019) == winServer2019);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2019Max) == winServer2019);

    Assert::IsTrue(DVLib::OperatingSystemType(winServer2022) == winServer2022);
    Assert::IsTrue(DVLib::OperatingSystemType(winServer2022Max) == winServer2022);

    Assert::IsTrue(DVLib::OperatingSystemType(win11) == win11);
    Assert::IsTrue(DVLib::OperatingSystemType(win11Max) == win11);

    Assert::IsTrue(DVLib::OperatingSystemType(winMax) == winMax);
}