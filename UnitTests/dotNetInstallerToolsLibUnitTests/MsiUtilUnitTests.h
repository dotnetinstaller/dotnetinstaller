#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsiUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( MsiUtilUnitTests );
			CPPUNIT_TEST( testGetInstalledProducts );
			CPPUNIT_TEST( testGetRelatedProducts );
			CPPUNIT_TEST( testIsProductInstalled );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetInstalledProducts();
			void testGetRelatedProducts();
			void testIsProductInstalled();
		};
	}
}
