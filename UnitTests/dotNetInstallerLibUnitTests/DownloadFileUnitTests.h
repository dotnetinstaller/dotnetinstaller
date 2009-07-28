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
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDownload();
			void testCopyFromSource();
		};
	}
}
