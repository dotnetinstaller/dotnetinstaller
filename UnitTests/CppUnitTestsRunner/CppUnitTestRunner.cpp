#include "StdAfx.h"
#include "CppUnitTests.h"

std::wstring CppUnitTestRunner::s_XmlPath;

CppUnitTestRunner::CppUnitTestRunner(void)
{
    wchar_t moduleFileName[MAX_PATH];
    CPPUNIT_ASSERT(::GetModuleFileNameW(NULL, moduleFileName, MAX_PATH) != 0);

    std::wstring smoduleFileName = moduleFileName;
    size_t backslashPos = smoduleFileName.rfind(L'\\', smoduleFileName.length());
    CPPUNIT_ASSERT(backslashPos != smoduleFileName.npos);

    s_XmlPath = smoduleFileName.substr(0, backslashPos);
    m_TestSuiteName = smoduleFileName.substr(backslashPos + 1, 
        smoduleFileName.length() - backslashPos - ARRAYSIZE(L".exe"));
}

CppUnitTestRunner::~CppUnitTestRunner(void)
{
}

std::wstring CppUnitTestRunner::Help()
{
    return Help(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
}

std::wstring CppUnitTestRunner::Help(CPPUNIT_NS::Test * test, int level)
{
    USES_CONVERSION;
    std::wstringstream s;
    for (int i = 0; i < test->getChildTestCount(); i++)
    {
        s << std::endl;
        if (0 < level)
        {
            std::wstring spaces(level, L' ');
            s << spaces;
        }
        CPPUNIT_NS::Test * child = test->getChildTestAt(i);
        s << A2W(child->getName().c_str());
        s << Help(child, level + 1);
    }
    return s.str();
}

int CppUnitTestRunner::Run(int argc, wchar_t * argv[])
{
    std::vector<CPPUNIT_NS::Test *> tests;
    CPPUNIT_NS::Test * root = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
    for (int i = 1; i < argc; i++)
    {
        if (! wcscmp(argv[i], L"/?") || ! wcscmp(argv[i], L"-?") || ! wcscmp(argv[i], L"--help"))
        {
            std::wcout << L"usage: " << argv[0] << L" <test-suite|test> [<test-suite1|test1> ... ]";
            std::wcout << std::endl << Help();
            return 0;
        }
        else
        {
            try
            {
                CPPUNIT_NS::Test * test = NULL;
                USES_CONVERSION;
                test = root->findTest(W2A(argv[i]));
                tests.push_back(test);
            }
            catch(std::invalid_argument&) 
            { 
                std::wcout << L"invalid test: " << argv[i];
                std::wcout << std::endl << Help();
                return -1;
            }
        }
    }

    return tests.size() ? Run(tests) : Run();
}

int CppUnitTestRunner::Run()
{
    std::vector<CPPUNIT_NS::Test *> tests;
    tests.push_back(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    return Run(tests);
}

int CppUnitTestRunner::Run(std::vector<CPPUNIT_NS::Test *>& tests)
{
    CPPUNIT_NS::TestRunner runner;
    CPPUNIT_NS::TestResult controller;
    CPPUNIT_NS::TestResultCollector result;
    CPPUNIT_NS::BriefTestProgressListener progress;
    CPPUNIT_NS::CompilerOutputter outputter( &result, std::cerr );
    std::wstring xmlFileName = (s_XmlPath == L"" ? L"" : s_XmlPath + L"\\") + m_TestSuiteName + L".xml";
    std::ofstream output_file( xmlFileName.c_str() , std::ios::out );
    CPPUNIT_NS::XmlOutputter xmloutputter( &result, output_file );
    controller.addListener(& result);        
    controller.addListener(& progress);      

    for each (CPPUNIT_NS::Test * test in tests)
    {
        runner.addTest(test);
    }

    runner.run( controller );

    outputter.write();
    xmloutputter.write();

    return result.wasSuccessful() ? EXIT_SUCCESS : EXIT_FAILURE;
}
