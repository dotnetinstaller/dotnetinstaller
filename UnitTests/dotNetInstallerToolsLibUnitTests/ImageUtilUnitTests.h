#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ImageUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ImageUtilUnitTests );
			CPPUNIT_TEST(testLoadBitmapFromFile);
			CPPUNIT_TEST(testLoadBitmapFromBuffer);
			CPPUNIT_TEST(testLoadBitmapFromResource);
			CPPUNIT_TEST_SUITE_END();
		public:
			void testLoadBitmapFromFile();
			void testLoadBitmapFromBuffer();
			void testLoadBitmapFromResource();
		};
	}
}
