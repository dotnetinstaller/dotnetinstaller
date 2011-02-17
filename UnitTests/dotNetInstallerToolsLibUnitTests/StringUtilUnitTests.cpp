#include "StdAfx.h"
#include "StringUtilUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::String::StringUtilUnitTests);

using namespace DVLib::UnitTests::String;

void StringUtilUnitTests::testtrim(void)
{
	typedef struct
	{
		LPCSTR testIn;
        LPCSTR testWhitespace;
		LPCSTR testOut;
        LPCSTR testOutL;
        LPCSTR testOutR;
	} TrimTestData;

	TrimTestData testData[] = 
	{
		{ "", "", "", "", "" },
        { "x", "x", "", "", "" },
        { "xxxxx", "x", "", "", "" },
        { "xxyyxx", "x", "yy", "yyxx", "xxyy" },
        { "\r\n\r", "\r", "\n", "\n\r", "\r\n" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::string s = DVLib::trim(testData[i].testIn, testData[i].testWhitespace);
		CPPUNIT_ASSERT(s == testData[i].testOut);

        std::string sL = DVLib::trimleft(testData[i].testIn, testData[i].testWhitespace);
        CPPUNIT_ASSERT(sL == testData[i].testOutL);
        
        std::string sR = DVLib::trimright(testData[i].testIn, testData[i].testWhitespace);
        CPPUNIT_ASSERT(sR == testData[i].testOutR);
	}
}

void StringUtilUnitTests::teststring2long(void)
{
	typedef struct  
	{
		LPCSTR testIn;
        long testOut;
		int base;
	} TestData;

	TestData testData[] = 
	{
		{ "-2147483647", LONG_MIN + 1, 10},
		{ "2147483646", LONG_MAX - 1, 10},
		{ "-2147483648", LONG_MIN, 10},
		{ "2147483647", LONG_MAX, 10},
		{ "0", 0, 10},
		{ "-65", -65 , 10},
		{ "65", 65 , 10},
		{ "-1", -1 , 10},
		// base 2
		{ "1100100", 100, 2 },
		{ "0", 0, 2 },
		{ "-0", 0, 2 },
		{ "-100", -4, 2 },
		// base 8
		{ "40", 32, 8 },
		{ "0", 0, 8 },
		{ "-40", -32, 8 },
		// base 16
		{ "40", 64, 16 },
		{ "0", 0, 16 },
		{ "0xabcd", 43981, 16 },
		// auto base (works with dec and hex)
		{ "0", 0, 0},
		{ "16", 16, 0},
		{ "-2147483648", LONG_MIN, 0},
		{ "2147483647", LONG_MAX, 0},
		{ "0x0", 0, 0},
		{ "0x10", 16, 0},
		//{ "0x80000000", LONG_MIN, 0},
		{ "0x7FFFFFFF", LONG_MAX, 0},
	};

	for (unsigned int i = 0; i < ARRAYSIZE(testData); i++)
	{
        long result = DVLib::string2long(testData[i].testIn, testData[i].base);
		std::stringstream s;
		s << "[" << (testData[i].testIn ? testData[i].testIn : "NULL") << "] => [" << result << "] (expected: " 
			<< testData[i].testOut << ", base: " << testData[i].base << ")";
		CPPUNIT_ASSERT_MESSAGE(s.str().c_str(), result == testData[i].testOut);
	}

	// Test exceptions
	TestData exceptionTestData[] = 
	{
		{ "-2147483649", 0, 10},
		{ "2147483648", 0, 10},
		{ "0x80000000", 0, 16 },
		{ "0xF80000000", 0, 16 },
		{ "none", 0, 10},
	};

	for (unsigned int i = 0; i < ARRAYSIZE(exceptionTestData); i++)
	{
		long result;
		try
		{
			result = DVLib::string2long(exceptionTestData[i].testIn, exceptionTestData[i].base);
		}
		catch (std::exception&)
		{
			// expected
			continue;
		}
		std::stringstream s;
		s << "[" << exceptionTestData[i].testIn << "] => [" << result << "], base: " 
			<< exceptionTestData[i].base << " - expected: std::exception";
		CPPUNIT_FAIL(s.str().c_str());
	}
}

void StringUtilUnitTests::teststring2ulong(void)
{
	typedef struct  
	{
		LPCSTR testIn;
        unsigned long testOut;
		int base;
	} TestData;

	TestData testData[] = 
	{
		{ "0", 0, 10},
		{ "4294967295", ULONG_MAX, 10},
		{ "0", 0, 10},
		{ "65", 65 , 10},
		{ "-1", ULONG_MAX, 10}, // converts signed strings to unsigned equivalent
		{ "-16", ULONG_MAX - 15, 10},
		// base 2
		{ "1100100", 100, 2 },
		{ "0", 0, 2 },
		// base 8
		{ "40", 32, 8 },
		{ "0", 0, 8 },
		// base 16
		{ "40", 64, 16 },
		{ "0", 0, 16 },
		{ "0xabcd", 43981, 16 },
		{ "0xFFFFFFFF", 4294967295, 16 },
		// auto base (works with dec and hex)
		{ "0", 0, 0},
		{ "16", 16, 0},
		{ "4294967295", ULONG_MAX, 0},
		{ "0x0", 0, 0},
		{ "0x10", 16, 0},
		{ "0xFFFFFFFF", ULONG_MAX, 0},
	};

	for (unsigned int i = 0; i < ARRAYSIZE(testData); i++)
	{
		unsigned long result = DVLib::string2ulong(testData[i].testIn, testData[i].base);
		std::stringstream s;
		s << "[" << (testData[i].testIn ? testData[i].testIn : "NULL") << "] => [" << result << "] (expected: " 
			<< testData[i].testOut << ", base: " << testData[i].base << ")";
		CPPUNIT_ASSERT_MESSAGE(s.str().c_str(), result == testData[i].testOut);
	}

	// Test exceptions
	TestData exceptionTestData[] = 
	{
		{ "4294967296", 0, 10},
		{ "0x100000000", 0, 16 },
		{ "0xFFFFFFFFF", 0, 16 },
		{ "none", 0, 10},
	};

	for (unsigned int i = 0; i < ARRAYSIZE(exceptionTestData); i++)
	{
		unsigned long result;
		try
		{
			result = DVLib::string2ulong(exceptionTestData[i].testIn, exceptionTestData[i].base);
		}
		catch (std::exception&)
		{
			// expected
			continue;
		}
		std::stringstream s;
		s << "[" << exceptionTestData[i].testIn << "] => [" << result << "], base: " 
			<< exceptionTestData[i].base << " - expected: std::exception";
		CPPUNIT_FAIL(s.str().c_str());
	}
}

void StringUtilUnitTests::testsplitjoin(void)
{

	typedef struct  
	{

		LPCSTR testStr;
		LPCSTR testDelim;

		int maxParts;
		size_t numParts;

	} TokenizeTestData;

	TokenizeTestData testData[] = 
	{
		{ "", ";", -1, 1 },
		{ ";", ";", -1, 2 },
		{ "t.$.y.$.x.$f", ".$.", -1, 3 },
		{ "4<<8<>15<>16<>23<>42", "<>", -1, 5 },
		{ ";;t;;o;;k;;e;;n;;i;;z;;e;;", ";;", -1, 10 },
		{ ";;t;;o;;k;;e;;n;;i;;z;;e", ";;", -1, 9 },
		{ "t;;o;;k;;e;;n;;i;;z;;e;;", ";;", -1, 9 },
		{ "t;;o;;k;;", ";;", 2, 2 },
	};

	for( int i = 0; i < sizeof(testData)/sizeof(TokenizeTestData); i++ )
	{
		std::vector<std::string> parts = DVLib::split(testData[i].testStr, testData[i].testDelim, testData[i].maxParts);
		CPPUNIT_ASSERT_MESSAGE(testData[i].testStr, parts.size() == testData[i].numParts);
		std::string s = DVLib::join(parts, testData[i].testDelim);
		std::cout << std::endl << testData[i].testStr << " vs. " << s.c_str();
		CPPUNIT_ASSERT_MESSAGE(s.c_str(), s == testData[i].testStr);
	}

	//Test that correct tokens are returned
	std::string sTest, delim1, delim2;

	sTest = "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query;;";
	delim1 = ";;";
	delim2 = ";";

	std::vector<std::string> parts = DVLib::split( sTest, delim1 );

	CPPUNIT_ASSERT( parts[0] == "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
	CPPUNIT_ASSERT( parts[1] == "" );

	sTest = parts[0];
	parts = DVLib::split( sTest, delim2 );

	CPPUNIT_ASSERT( parts[0] == "ServerName" );
	CPPUNIT_ASSERT( parts[1] == "WINGMAN" );
	CPPUNIT_ASSERT( parts[2] == "InstanceName" );
	CPPUNIT_ASSERT( parts[3] == "APPSECINC" );
	CPPUNIT_ASSERT( parts[4] == "IsClustered" );
	CPPUNIT_ASSERT( parts[5] == "No" );
	CPPUNIT_ASSERT( parts[6] == "Version" );
	CPPUNIT_ASSERT( parts[7] == "8.00.194" );
	CPPUNIT_ASSERT( parts[8] == "tcp" );
	CPPUNIT_ASSERT( parts[9] == "1091" );
	CPPUNIT_ASSERT( parts[10] == "np" );
	CPPUNIT_ASSERT( parts[11] == "\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
}

void StringUtilUnitTests::testreplace()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testFrom;
		LPCSTR testTo;
		int testExpectedResult;
		LPCSTR testExpectedOutput;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", "", 0, "" },
		{ "x", "x", "y", 1, "y" },
		{ "x", "xx", "y", 0, "x" },
		{ "foo", "fo", "f", 1, "fo" },
		{ "{source}\r", "source", "target", 1, "{target}\r" },
		{ "{source}\r", "source", "target", 1, "{target}\r" },
		{ "\n{source}\r", "source", "target", 1, "\n{target}\r" },
		{ "\n{source}{source}\r", "source", "target", 2, "\n{target}{target}\r" },
		{ "\n{source}XZY{source}\r", "source", "target", 2, "\n{target}XZY{target}\r" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.replace('" << 
			testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
			testData[i].testExpectedResult << "'";
		
		std::string output = DVLib::replace(testData[i].testIn, testData[i].testFrom, testData[i].testTo);
		// todo: test number of replacements made

		message << "'" << testData[i].testIn << "'.replace('" << 
			testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
			testData[i].testExpectedOutput << "' (returned '" << output << "')";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedOutput == output);
	}
}

void StringUtilUnitTests::testwstring2string(void)
{
	typedef struct  
	{
		LPCWSTR testIn;
		LPCSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		{ L"", "" },
		{ L"x", "x" },
		{ L"hello world", "hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		USES_CONVERSION;
		message << "wstring2string('" << W2A(testData[i].testIn) << "')" << 
			" != '" << testData[i].testOut << "'";
		
		std::string output = DVLib::wstring2string(testData[i].testIn);
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), strlen(testData[i].testOut) == output.length());
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testOut == output);
	}
}

void StringUtilUnitTests::teststring2wstring(void)
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCWSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		{ "", L"" },
		{ "x", L"x" },
		{ "hello world", L"hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		USES_CONVERSION;
		message << "string2wstring('" << testData[i].testIn << "')" << 
			" != '" << W2A(testData[i].testOut) << "'";
		
		std::wstring output = DVLib::string2wstring(testData[i].testIn);
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), wcslen(testData[i].testOut) == output.length());
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testOut == output);
	}
}

void StringUtilUnitTests::testlong2string(void)
{
	struct TestData 
	{
		unsigned long int testIn;
		std::string testOut;
	};
	
	TestData testData[] = {
		{0, "0"},
		{121, "121"},
		{111111118, "111111118"},
		{0x00, "0"},
		{0x11, "17"},
		{0xA, "10"}
	};
	
	for (int i=0; i < ARRAYSIZE(testData); i++)
	{
        std::string number = DVLib::tostring(testData[i].testIn);
        std::cout << std::endl << testData[i].testIn << " => " << number << " (expecting " << testData[i].testOut << ")";
		CPPUNIT_ASSERT(testData[i].testOut == number);
	}
}

void StringUtilUnitTests::testlong2wstring(void)
{
	struct TestData 
	{
		unsigned long int testIn;
        std::wstring testOut;
	};
	
	TestData testData[] = {
		{0, L"0"},
		{121, L"121"},
		{111111118, L"111111118"},
		{0x00, L"0"},
		{0x11, L"17"},
		{0xA, L"10"}
	};
	
	for (int i=0; i < ARRAYSIZE(testData); i++)
	{
        std::wstring number = DVLib::towstring(testData[i].testIn);
        std::cout << std::endl << testData[i].testIn << " => " << DVLib::wstring2string(number) << " (expecting " << DVLib::wstring2string(testData[i].testOut) << ")";
		CPPUNIT_ASSERT(testData[i].testOut == number);
	}
}

void StringUtilUnitTests::testtostring(void)
{
	CPPUNIT_ASSERT(DVLib::tostring(0) == "0");
}

void StringUtilUnitTests::testtowstring(void)
{
	CPPUNIT_ASSERT(DVLib::towstring(0) == L"0");
}

void StringUtilUnitTests::teststartswith()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testWhat;
        bool testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", true },
		{ "x", "x", true },
		{ "x", "X", false },
		{ "X", "x", false },
		{ "x", "y", false },
		{ "xx", "xy", false },
		{ "xx", "yx", false },
		{ "xxx", "", true },
		{ "x x x", "x x", true },
		{ "123", "231", false },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.startswith('" << 
			testData[i].testWhat << "') didn't return '" << 
			(testData[i].testExpectedResult ? "true" : "false") << "'";
		
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == DVLib::startswith(
				testData[i].testIn, testData[i].testWhat));
	}
}

void StringUtilUnitTests::testendswith()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testWhat;
        bool testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", true },
		{ "x", "x", true },
		{ "X", "x", false },
		{ "x", "X", false },
		{ "x", "y", false },
		{ "xx", "xy", false },
		{ "xx", "yx", false },
		{ "xxx", "", true },
		{ "x x x", "x x", true },
		{ "xyz", "yz", true },
		{ "xyz", "xxxxxxxxxxyz", false },
		{ "123", "231", false },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.endswith('" << 
			testData[i].testWhat << "') didn't return '" << 
			(testData[i].testExpectedResult ? "true" : "false") << "'";
		
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == DVLib::endswith(
				testData[i].testIn, testData[i].testWhat));
	}
}

void StringUtilUnitTests::testUTF82wstring()
{
	typedef struct  
	{
		LPCSTR testIn;
		size_t len;
	} TestData;

	TestData testData[] = 
	{
		{ "\xe6\x97\xa5\xd1\x88", 2 },
		{ "\xe6\x97\xa5\xd1\x88\xf0\x9d\x84\x9e", 4 }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::wstring output = DVLib::UTF8string2wstring(testData[i].testIn);
		CPPUNIT_ASSERT(output.length() == testData[i].len);
	}
}