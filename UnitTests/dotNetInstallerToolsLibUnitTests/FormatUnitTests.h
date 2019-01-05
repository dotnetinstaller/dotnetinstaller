#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(FormatUnitTests)
		{
			TEST_METHOD(testFormatMessageA);
			TEST_METHOD(testFormatMessageW);
			TEST_METHOD(testFormatMessageFromLastErrorCodeA);
			TEST_METHOD(testFormatMessageFromLastErrorCodeW);
			TEST_METHOD(testFormatMessageFromHRA);
			TEST_METHOD(testFormatMessageFromHRW);
			TEST_METHOD(testFormatBytes);
			TEST_METHOD(testFormatDateTime);
			TEST_METHOD(testFormatCurrentDateTime);
		};
	}
}
