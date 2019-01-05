#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ConfigFileUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testLoadPackagedSetup );
			TEST_METHOD( testLoadInstallCheckOperators );
			TEST_METHOD( testLoadStandaloneSetup );
			TEST_METHOD( testLoadDownloadSetup );
			TEST_METHOD( testLoadReferenceSetup );
			TEST_METHOD( testLoadInstallCheckProductSetup );
			TEST_METHOD( testLoadOsFiltersSetup );
			TEST_METHOD( testLoadResource );
			TEST_METHOD( testLoadMultilingualSetup );
			TEST_METHOD( testLoadLicenseAgreement );
			TEST_METHOD( testGetSupportedConfigurations );
			TEST_METHOD( testLoadCustomInputSetup );
			TEST_METHOD( testLoadMultipleSetup );
			TEST_METHOD( testLoadPatchSetup );
			TEST_METHOD( testLoadExeSetup );
		};
	}
}
