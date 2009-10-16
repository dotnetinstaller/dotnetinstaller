#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DirectoryUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( DirectoryUtilUnitTests );
			CPPUNIT_TEST( testDirectoryExists );
			CPPUNIT_TEST( testDirectoryCreate );
			CPPUNIT_TEST( testDirectoryDelete );
			CPPUNIT_TEST( testGetFilesRecursive );
			CPPUNIT_TEST( testGetFilesWithWildcard );
			CPPUNIT_TEST( testGetFilesWithNoWildcard );
			CPPUNIT_TEST( testGetFilesWithInvalidWildcard );
			CPPUNIT_TEST( testDirectoryCreateMultipleSlashes );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDirectoryExists();
			void testDirectoryCreate();
			void testDirectoryDelete();
			void testGetFilesRecursive();
			void testGetFilesWithWildcard();
			void testGetFilesWithNoWildcard();
			void testGetFilesWithInvalidWildcard();
			void testDirectoryCreateMultipleSlashes();
		};
	}
}
