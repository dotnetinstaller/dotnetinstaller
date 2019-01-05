#include "StdAfx.h"
#include "StringUtilUnitTests.h"

using namespace DVLib::UnitTests::String;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
        Assert::IsTrue(s == testData[i].testOut);

        std::string sL = DVLib::trimleft(testData[i].testIn, testData[i].testWhitespace);
        Assert::IsTrue(sL == testData[i].testOutL);

        std::string sR = DVLib::trimright(testData[i].testIn, testData[i].testWhitespace);
        Assert::IsTrue(sR == testData[i].testOutR);
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
        std::wstringstream s;
        s << "[" << (testData[i].testIn ? testData[i].testIn : "NULL") << "] => [" << result << "] (expected: " 
            << testData[i].testOut << ", base: " << testData[i].base << ")";
        Assert::IsTrue(result == testData[i].testOut, s.str().c_str());
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
        std::wstringstream s;
        s << "[" << exceptionTestData[i].testIn << "] => [" << result << "], base: " 
            << exceptionTestData[i].base << " - expected: std::exception";
        Assert::Fail(s.str().c_str());
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
        std::wstringstream s;
        s << "[" << (testData[i].testIn ? testData[i].testIn : "NULL") << "] => [" << result << "] (expected: " 
            << testData[i].testOut << ", base: " << testData[i].base << ")";
        Assert::IsTrue(result == testData[i].testOut, s.str().c_str());
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
        std::wstringstream s;
        s << "[" << exceptionTestData[i].testIn << "] => [" << result << "], base: " 
            << exceptionTestData[i].base << " - expected: std::exception";
        Assert::Fail(s.str().c_str());
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
        Assert::IsTrue(parts.size() == testData[i].numParts, DVLib::string2wstring(testData[i].testStr).c_str());
        std::string s = DVLib::join(parts, testData[i].testDelim);
        std::cout << std::endl << testData[i].testStr << " vs. " << s.c_str();
        Assert::IsTrue(s == testData[i].testStr, DVLib::string2wstring(s).c_str());
    }

    //Test that correct tokens are returned
    std::string sTest, delim1, delim2;

    sTest = "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query;;";
    delim1 = ";;";
    delim2 = ";";

    std::vector<std::string> parts = DVLib::split( sTest, delim1 );

    Assert::IsTrue( parts[0] == "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
    Assert::IsTrue( parts[1] == "" );

    sTest = parts[0];
    parts = DVLib::split( sTest, delim2 );

    Assert::IsTrue( parts[0] == "ServerName" );
    Assert::IsTrue( parts[1] == "WINGMAN" );
    Assert::IsTrue( parts[2] == "InstanceName" );
    Assert::IsTrue( parts[3] == "APPSECINC" );
    Assert::IsTrue( parts[4] == "IsClustered" );
    Assert::IsTrue( parts[5] == "No" );
    Assert::IsTrue( parts[6] == "Version" );
    Assert::IsTrue( parts[7] == "8.00.194" );
    Assert::IsTrue( parts[8] == "tcp" );
    Assert::IsTrue( parts[9] == "1091" );
    Assert::IsTrue( parts[10] == "np" );
    Assert::IsTrue( parts[11] == "\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
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
        std::wstringstream message;
        message << "'" << testData[i].testIn << "'.replace('" << 
            testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
            testData[i].testExpectedResult << "'";

        std::string output = DVLib::replace(testData[i].testIn, testData[i].testFrom, testData[i].testTo);
        // todo: test number of replacements made

        message << "'" << testData[i].testIn << "'.replace('" << 
            testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
            testData[i].testExpectedOutput << "' (returned '" << DVLib::string2wstring(output) << "')";

        Assert::IsTrue(testData[i].testExpectedOutput == output,
            message.str().c_str());
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
        std::wstringstream message;
        USES_CONVERSION;
        message << "wstring2string('" << W2A(testData[i].testIn) << "')" << 
            " != '" << testData[i].testOut << "'";

        std::string output = DVLib::wstring2string(testData[i].testIn);
        Assert::IsTrue(strlen(testData[i].testOut) == output.length(), message.str().c_str());
        Assert::IsTrue(testData[i].testOut == output, message.str().c_str());
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
        std::wstringstream message;
        USES_CONVERSION;
        message << "string2wstring('" << testData[i].testIn << "')" << 
            " != '" << W2A(testData[i].testOut) << "'";

        std::wstring output = DVLib::string2wstring(testData[i].testIn);
        Assert::IsTrue(wcslen(testData[i].testOut) == output.length(), message.str().c_str());
        Assert::IsTrue(testData[i].testOut == output, message.str().c_str());
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
        Assert::IsTrue(testData[i].testOut == number);
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
        Assert::IsTrue(testData[i].testOut == number);
    }
}

void StringUtilUnitTests::testtostring(void)
{
    Assert::IsTrue(DVLib::tostring(0) == "0");
}

void StringUtilUnitTests::testtowstring(void)
{
    Assert::IsTrue(DVLib::towstring(0) == L"0");
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
        std::wstringstream message;
        message << "'" << testData[i].testIn << "'.startswith('" << 
            testData[i].testWhat << "') didn't return '" << 
            (testData[i].testExpectedResult ? "true" : "false") << "'";

        Assert::IsTrue(testData[i].testExpectedResult == DVLib::startswith(
            testData[i].testIn, testData[i].testWhat),
            message.str().c_str());
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
        std::wstringstream message;
        message << "'" << testData[i].testIn << "'.endswith('" << 
            testData[i].testWhat << "') didn't return '" << 
            (testData[i].testExpectedResult ? "true" : "false") << "'";

        Assert::IsTrue(testData[i].testExpectedResult == DVLib::endswith(
            testData[i].testIn, testData[i].testWhat),
            message.str().c_str());
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
        Assert::IsTrue(output.length() == testData[i].len);
    }
}