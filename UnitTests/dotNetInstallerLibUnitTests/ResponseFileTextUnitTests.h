#pragma once

#include "ResponseFileUnitTests.h"

namespace DVLib
{
	namespace UnitTests 
	{
		class ResponseFileTextUnitTests : public ResponseFileUnitTests<ResponseFileText>
		{
			CPPUNIT_TEST_SUITE( ResponseFileTextUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
		};
	}
}
