#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ConfigFileUnitTests : public dotNetInstallerLibUnitTestFixture
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
			CPPUNIT_TEST( testLoadMultilingualSetup );
			CPPUNIT_TEST( testLoadLicenseAgreement );
			CPPUNIT_TEST( testGetSupportedConfigurations );
			CPPUNIT_TEST( testLoadCustomInputSetup );
			CPPUNIT_TEST( testLoadMultipleSetup );
			CPPUNIT_TEST( testLoadPatchSetup );
			CPPUNIT_TEST( testLoadExeSetup );
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
			void testLoadMultilingualSetup();
			void testLoadLicenseAgreement();
			void testLoadCustomInputSetup();
			void testLoadMultipleSetup();
			void testLoadPatchSetup();
			void testLoadExeSetup();
		};
	}
}
