#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstalledCheckRegistryUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( InstalledCheckRegistryUnitTests );
			CPPUNIT_TEST( testIsInstalled );
			// \todo: WOW options tests
			// CPPUNIT_TEST( testWOW64_64 );
			// CPPUNIT_TEST( testWOW64_32 );
			CPPUNIT_TEST_SUITE_END();
		public:
			// void testWOW64_64();
			// void testWOW64_32();
			void testIsInstalled();
			void setUp();
			void tearDown();
		};
	}
}
