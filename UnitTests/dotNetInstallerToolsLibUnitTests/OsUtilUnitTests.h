#pragma once

namespace DVLib
{
    namespace UnitTests 
    {
        TEST_CLASS(OsUtilUnitTests)
        {
            TEST_METHOD( testGetOperatingSystemVersion );
            TEST_METHOD( testGetOperatingSystemVersionString );
            TEST_METHOD( testIsOperatingSystemID );
            TEST_METHOD( testIsInOperatingSystemInRange );
            TEST_METHOD( testGetOperatingSystemLCID );
            TEST_METHOD( testIsOperatingSystemLCID );
            TEST_METHOD( testGetLocale );
            TEST_METHOD( testGetISOLocale );
            TEST_METHOD( testIsOperatingSystemLCIDValue );
            TEST_METHOD( testGetProcessorArchitecture );
            TEST_METHOD( testProcessorArchitectureToFromString );
            TEST_METHOD( testIsProcessorArchitecture );
            TEST_METHOD( testIsWow64 );
            TEST_METHOD( testWow64DisableWow64FsRedirection );
            TEST_METHOD( testwstring2lcidtype );
            TEST_METHOD( testlcidtype2wstring );
            TEST_METHOD( testos2wstring );
            TEST_METHOD( testoscode2os );
            TEST_METHOD( testMuiGetUserDefaultUILCID );
            TEST_METHOD( testMuiGetSystemDefaultUILCID );
            TEST_METHOD( testOperatingSystemType );
        };
    }
}
