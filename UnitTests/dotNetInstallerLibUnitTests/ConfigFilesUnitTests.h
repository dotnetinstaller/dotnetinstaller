#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ConfigFilesUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testSaveRestoreAppState );
			TEST_METHOD( testLoad );
			TEST_METHOD( testDownload );
			TEST_METHOD( testRun );
			TEST_METHOD( testSelectLanguageNoSelection );
			TEST_METHOD( testSelectLanguage1040 );
			TEST_METHOD( testSelectLanguageNot1040 );
			TEST_METHOD( testSelectLanguageCancelled );
			TEST_METHOD( testGetLanguages );
			TEST_METHOD( testNoMatchingConfiguration );
		};
	}
}
