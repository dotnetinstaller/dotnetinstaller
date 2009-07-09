#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DownloadComponentUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( DownloadComponentUnitTests );
			CPPUNIT_TEST( testDownload );
			CPPUNIT_TEST( testCopyFromSource );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDownload();
			void testCopyFromSource();
		};
	}
}
