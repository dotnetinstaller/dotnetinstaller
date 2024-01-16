#pragma once

namespace DVLib
{
	namespace UnitTests
	{
		TEST_CLASS(WmiUtilUnitTests)
		{
			// Any
			TEST_METHOD(Any_WithNoResults_ReturnsFalse);
			TEST_METHOD(Any_WithOneResult_ReturnsTrue);
			TEST_METHOD(Any_SelectSinglePropertyWithOneResult_ReturnsTrue);
			TEST_METHOD(Any_WithMultipleResults_ReturnsTrue);

			// Get
			TEST_METHOD(Get_WithNoResults_ReturnsEmptyString);
			TEST_METHOD(Get_WithOneResult_ReturnsExpectedString);
			TEST_METHOD(Get_WithSelectSinglePropertyWithOneResult_ReturnsExpectedString);
			TEST_METHOD(Get_WithWithMultipleResults_ReturnsExpectedString);
		};
	}
}