#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(DownloadDialogUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testIsCopyDownloadRequiredEmpty );
			TEST_METHOD( testIsCopyDownloadRequired );
			TEST_METHOD( testDownload );
			TEST_METHOD( testDownloadMultiple );
			TEST_METHOD( testDownloadMultipleError );
			TEST_METHOD( testCopyFromSource );
			TEST_METHOD( testShowDialogOnDownloadFile );
			TEST_METHOD( testShowDialogOnCopyFile );
			TEST_METHOD( testNoDialogOnNoDownloadOrCopy );
		};
	}
}
