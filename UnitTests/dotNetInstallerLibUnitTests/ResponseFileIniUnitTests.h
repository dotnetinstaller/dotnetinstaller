#pragma once

#include "ResponseFileUnitTests.h"

namespace DVLib
{
	namespace UnitTests 
	{
		class ResponseFileIniUnitTests : public ResponseFileUnitTests<ResponseFileIni>
		{
			CPPUNIT_TEST_SUITE( ResponseFileIniUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
		};
	}
}
