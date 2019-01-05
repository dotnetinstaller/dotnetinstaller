#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(DirectoryUtilUnitTests)
		{
			TEST_METHOD( testDirectoryNormalize );
			TEST_METHOD( testDirectoryExists );
			TEST_METHOD( testDirectoryCreate );
			TEST_METHOD( testDirectoryDelete );
			TEST_METHOD( testGetFilesRecursive );
			TEST_METHOD( testGetFilesWithWildcard );
			TEST_METHOD( testGetFilesWithNoWildcard );
			TEST_METHOD( testGetFilesWithInvalidWildcard );
			TEST_METHOD( testDirectoryCreateMultipleSlashes );
		};
	}
}
