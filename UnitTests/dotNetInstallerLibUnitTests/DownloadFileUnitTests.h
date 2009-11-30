#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DownloadFileUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( DownloadFileUnitTests );
			CPPUNIT_TEST( testDownload );
			CPPUNIT_TEST( testCopyFromSource );
			CPPUNIT_TEST( testClearCache );
			// test can only run online, \todo: need a local web server
			// CPPUNIT_TEST( testDownloadCache );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDownload();
			void testCopyFromSource();
			void testClearCache();
			void testDownloadCache();
		};
	}
}
