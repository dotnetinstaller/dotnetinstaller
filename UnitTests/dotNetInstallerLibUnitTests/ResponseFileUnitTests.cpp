#include "StdAfx.h"
#include "ResponseFileUnitTests.h"

using namespace DVLib::UnitTests;

template <class T>
void ResponseFileUnitTests<T>::testExec(ResponseFileUnitTestsTestData testdata[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::wstring s = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), L"template_source.txt");
        std::wstring t = s + L".out";
        if (DVLib::FileExists(s)) DVLib::FileDelete(s);
        if (DVLib::FileExists(t)) DVLib::FileDelete(t);
        std::vector<char> source_data(testdata[i].source.begin(), testdata[i].source.end());
        DVLib::FileWrite(s, source_data);
        T r(s, t);
        r.Exec();
        CPPUNIT_ASSERT(DVLib::FileExists(t));
        std::vector<char> written_data = DVLib::FileReadToEnd(t);
        std::string written_data_s(written_data.begin(), written_data.end());
        CPPUNIT_ASSERT(written_data_s == testdata[i].expected);
        DVLib::FileDelete(s);
        DVLib::FileDelete(t);
    }
}
