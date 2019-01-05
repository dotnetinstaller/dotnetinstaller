#include "StdAfx.h"
#include "ExtractComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class ExtractComponentStdOut : public ExtractComponent
{
public:
    std::wstring last_status;
public:
    ExtractComponentStdOut(HMODULE h, const std::wstring& id)
        : ExtractComponent(h, id)
    {

    }

    void OnStatus(const std::wstring& status)
    {
        std::wcout << std::endl << status;
        last_status = status;
    }
};


void ExtractComponentUnitTests::testExtractWithoutComponentId()
{
    ExtractComponentStdOut extract(GetCurrentModuleHandle(), L"");
    extract.Exec();
    std::wstring readmetxt = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionCabPath(), L"readme.txt");
    Assert::IsTrue(DVLib::FileExists(readmetxt));
    Assert::IsTrue(DVLib::GetFileSize(readmetxt) == 18);
    std::wcout << std::endl << readmetxt << L" - " << DVLib::FormatBytesW(DVLib::GetFileSize(readmetxt));
    DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
}

void ExtractComponentUnitTests::testExtractWithComponentId()
{
    ExtractComponentStdOut extract(GetCurrentModuleHandle(), L"TEST");
    extract.Exec();
    std::wstring readmetxt = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionCabPath(), L"readme.txt");
    Assert::IsTrue(DVLib::FileExists(readmetxt));
    Assert::IsTrue(DVLib::GetFileSize(readmetxt) == 18);
    std::wcout << std::endl << readmetxt << L" - " << DVLib::FormatBytesW(DVLib::GetFileSize(readmetxt));
    DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
}


void ExtractComponentUnitTests::testExtractWithStatus()
{
    ExtractComponentStdOut extract(GetCurrentModuleHandle(), L"");
    extract.status_interval = 0;
    extract.Exec();
    DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
    Assert::IsTrue(extract.last_status == L"readme.txt - 100%");
}
