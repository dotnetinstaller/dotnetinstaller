#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(MsiUtilUnitTests)
		{
			TEST_METHOD( testGetInstalledProducts );
			TEST_METHOD( testGetAnyInstalledProducts );
			TEST_METHOD( testGetRelatedProducts );
			TEST_METHOD( testIsProductInstalled );
			TEST_METHOD( testGetQuotedPathOrGuid );
			TEST_METHOD( testGetUpgradeCodes );
			TEST_METHOD( testGetRelatedInstalledProducts );
		};
	}
}
