#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DownloadComponentsUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( DownloadComponentsUnitTests );
			CPPUNIT_TEST( testIsCopyDownloadRequiredEmpty );
			CPPUNIT_TEST( testIsCopyDownloadRequired );
			CPPUNIT_TEST( testDownload );
			CPPUNIT_TEST( testDownloadMultiple );
			CPPUNIT_TEST( testDownloadMultipleError );
			CPPUNIT_TEST( testCopyFromSource );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testIsCopyDownloadRequiredEmpty();
			void testIsCopyDownloadRequired();
			void testDownload();
			void testDownloadMultiple();
			void testDownloadMultipleError();
			void testCopyFromSource();
		};
	}
}
