#include "StdAfx.h"
#include "ExtractComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ExtractComponentUnitTests);

using namespace DVLib::UnitTests;

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
	ExtractComponentStdOut extract(::GetModuleHandle(NULL), L"");
	extract.Exec();
	std::wstring readmetxt = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionCabPath(), L"readme.txt");
	CPPUNIT_ASSERT(DVLib::FileExists(readmetxt));
	CPPUNIT_ASSERT(DVLib::GetFileSize(readmetxt) == 18);
	std::wcout << std::endl << readmetxt << L" - " << DVLib::FormatBytesW(DVLib::GetFileSize(readmetxt));
	DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
}

void ExtractComponentUnitTests::testExtractWithComponentId()
{
	ExtractComponentStdOut extract(::GetModuleHandle(NULL), L"TEST");
	extract.Exec();
	std::wstring readmetxt = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionCabPath(), L"readme.txt");
	CPPUNIT_ASSERT(DVLib::FileExists(readmetxt));
	CPPUNIT_ASSERT(DVLib::GetFileSize(readmetxt) == 18);
	std::wcout << std::endl << readmetxt << L" - " << DVLib::FormatBytesW(DVLib::GetFileSize(readmetxt));
	DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
}


void ExtractComponentUnitTests::testExtractWithStatus()
{
	ExtractComponentStdOut extract(::GetModuleHandle(NULL), L"");
	extract.status_interval = 0;
	extract.Exec();
	DVLib::DirectoryDelete(InstallerSession::Instance->GetSessionCabPath());
	CPPUNIT_ASSERT(extract.last_status == L"readme.txt - 100%");
}
