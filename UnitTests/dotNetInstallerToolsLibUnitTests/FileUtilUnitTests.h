#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class FileUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( FileUtilUnitTests );
			CPPUNIT_TEST( testFileExists );
			CPPUNIT_TEST( testGetTemporaryFileName );
			CPPUNIT_TEST( testFileDelete );
			CPPUNIT_TEST( testFileCopy );
			CPPUNIT_TEST( testGetFileSize );
			CPPUNIT_TEST( testFileWrite );
			CPPUNIT_TEST( testFileCreate );
			CPPUNIT_TEST( testFileReadToEnd );
			CPPUNIT_TEST( testGetFileVersionInfo );
			CPPUNIT_TEST( testGetFileVersion );
			CPPUNIT_TEST( testLoadResourceData );
			CPPUNIT_TEST( testResourceExists );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testFileExists();
			void testGetTemporaryFileName();
			void testFileDelete();
			void testFileCopy();
			void testGetFileSize();
			void testFileWrite();
			void testFileCreate();
			void testFileReadToEnd();
			void testGetFileVersionInfo();
			void testGetFileVersion();
			void testLoadResourceData();
			void testResourceExists();
		};
	}
}
