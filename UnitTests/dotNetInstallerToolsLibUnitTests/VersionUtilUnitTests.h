#pragma once

namespace DVLib
{
	namespace UnitTests
	{
		TEST_CLASS(VersionUtilUnitTests)
		{
			TEST_METHOD(testwstring2version);
			TEST_METHOD(testversion2wstring);
			TEST_METHOD(testCompareVersion);
			TEST_METHOD(testCompareVersion_unknown);
			TEST_METHOD(testCompareVersion_version_and_version_ge);
			TEST_METHOD(testCompareVersion_version_eq);
			TEST_METHOD(testCompareVersion_version_lt);
			TEST_METHOD(testCompareVersion_version_le);
			TEST_METHOD(testCompareVersion_version_gt);
			TEST_METHOD(testCompareSemanticVersion);
			TEST_METHOD(testCompareSemanticVersion_invalid);
		};
	}
}