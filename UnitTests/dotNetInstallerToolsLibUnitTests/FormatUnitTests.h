#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class FormatUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( FormatUnitTests );
			CPPUNIT_TEST(testFormatMessageA);
			CPPUNIT_TEST(testFormatMessageW);
			CPPUNIT_TEST(testFormatMessageFromLastErrorCodeA);
			CPPUNIT_TEST(testFormatMessageFromLastErrorCodeW);
			CPPUNIT_TEST(testFormatMessageFromHRA);
			CPPUNIT_TEST(testFormatMessageFromHRW);
			CPPUNIT_TEST(testFormatBytes);
			CPPUNIT_TEST(testFormatDateTime);
			CPPUNIT_TEST(testFormatCurrentDateTime);
			CPPUNIT_TEST_SUITE_END();
		public:
			void testFormatMessageA();
			void testFormatMessageW();
			void testFormatMessageFromLastErrorCodeA();
			void testFormatMessageFromLastErrorCodeW();
			void testFormatMessageFromHRA();
			void testFormatMessageFromHRW();
			void testFormatBytes();
			void testFormatDateTime();
			void testFormatCurrentDateTime();
		};
	}
}
