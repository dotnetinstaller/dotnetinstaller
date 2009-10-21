#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class CmdComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( CmdComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST( testExecUISilent );
			CPPUNIT_TEST( testExecUIBasic );
			CPPUNIT_TEST( testExecXCopy );
			CPPUNIT_TEST( testReturnCodeZero );
			CPPUNIT_TEST( testReturnCodeNone );
			CPPUNIT_TEST( testReturnCodeNonZero );
			CPPUNIT_TEST( testReturnCodeNonValue );
			CPPUNIT_TEST( testReturnCodeRebootRequired );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
			void testExecUISilent();
			void testExecUIBasic();
			void testExecXCopy();
			void testReturnCodeZero();
			void testReturnCodeNone();
			void testReturnCodeNonZero();
			void testReturnCodeNonValue();
			void testReturnCodeRebootRequired();
		};
	}
}
