#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ImageUtilUnitTests)
		{
			TEST_METHOD(testLoadBitmapFromFile);
			TEST_METHOD(testLoadBitmapFromBuffer);
			TEST_METHOD(testLoadBitmapFromResource);
		};
	}
}
