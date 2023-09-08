#pragma once

namespace DVLib
{
	namespace UnitTests
	{
		TEST_CLASS(WmiUtilUnitTests)
		{
			TEST_METHOD(Any_WithNoResults_ReturnsFalse);
			TEST_METHOD(Any_WithOneResult_ReturnsTrue);
			TEST_METHOD(Any_SelectSinglePropertyWithOneResult_ReturnsTrue);
			TEST_METHOD(Any_WithMultipleResults_ReturnsTrue);
		};
	}
}