#pragma once

#include "ResponseFileUnitTests.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ResponseFileIniUnitTests), public ResponseFileUnitTests<ResponseFileIni>
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testExec );
		};
	}
}
