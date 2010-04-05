#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		struct ResponseFileUnitTestsTestData
		{
			std::string source;
			std::string expected;
		};

		template <class T>
		class ResponseFileUnitTests : public dotNetInstallerLibUnitTestFixture
		{
		protected:
			void testExec(ResponseFileUnitTestsTestData testdata[], int size);
		};
	}
}
