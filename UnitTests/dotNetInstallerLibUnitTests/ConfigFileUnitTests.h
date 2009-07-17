#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ConfigFileUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ConfigFileUnitTests );
			CPPUNIT_TEST( testLoadPackagedSetup );
			CPPUNIT_TEST( testLoadInstallCheckOperators );
			CPPUNIT_TEST( testLoadStandaloneSetup );
			CPPUNIT_TEST( testLoadDownloadSetup );
			CPPUNIT_TEST( testLoadReferenceSetup );
			CPPUNIT_TEST( testLoadInstallCheckProductSetup );
			CPPUNIT_TEST( testLoadOsFiltersSetup );
			CPPUNIT_TEST( testLoadResource );
			CPPUNIT_TEST( testGetSupportedConfigurations );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testLoadPackagedSetup();
			void testLoadInstallCheckOperators();
			void testLoadInstallCheckProductSetup();
			void testLoadStandaloneSetup();
			void testLoadDownloadSetup();
			void testLoadReferenceSetup();
			void testLoadOsFiltersSetup();
			void testLoadResource();
			void testGetSupportedConfigurations();
		};
	}
}
