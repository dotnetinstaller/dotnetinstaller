#pragma once

//! A CPPUnit test runner
class CppUnitTestRunner
{
public:
	CppUnitTestRunner();
	~CppUnitTestRunner();

    //! runs all tests or allows to specify which test(s) to run; using -? on the command line shows a list of tests
	int Run(int argc, wchar_t * argv[]);
    //! runs all tests
	int Run();

    //! list all unit tests and command line help
    std::wstring Help();
    //! returns xml configuration file path
	const static std::wstring& XmlPath() { return s_XmlPath; }

private:
    //! Runs all tests. Xml output will be generated at the xmlPath with the testSuiteName.xml
    int Run(std::vector<CPPUNIT_NS::Test *>& tests);
    //! list all unit tests and command line help
	std::wstring Help(CPPUNIT_NS::Test *, int level = 0);
    //! the path where the XML output should be created
    static std::wstring s_XmlPath;
    //! the name of the unit test suite and will become the filename for the xml output
	std::wstring m_TestSuiteName;
};
