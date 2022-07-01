#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(FileUtilUnitTests)
		{
			TEST_METHOD( testFileExists );
			TEST_METHOD( testGetTemporaryFileName );
			TEST_METHOD( testFileDelete );
			TEST_METHOD( testFileCopy );
			TEST_METHOD( testFileMove );
			TEST_METHOD( testGetFileSize );
			TEST_METHOD( testFileWrite );
			TEST_METHOD( testFileCreate );
			TEST_METHOD( testFileReadToEnd );
			TEST_METHOD( testGetFileVersionInfo );
			TEST_METHOD( testGetFileVersion );
			TEST_METHOD( testLoadResourceData );
			TEST_METHOD( testResourceExists );
		};
	}
}
