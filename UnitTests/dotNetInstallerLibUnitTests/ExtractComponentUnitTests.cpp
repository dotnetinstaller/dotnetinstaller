#include "StdAfx.h"
#include "ExtractComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ExtractComponentUnitTests);

using namespace DVLib::UnitTests;

class ExtractComponentStdOut : public ExtractComponent
{
public:
	ExtractComponentStdOut(HMODULE h, const InstallConfigurationPtr& configuration)
		: ExtractComponent(h)
	{

	}

	void OnStatus(const std::wstring& status)
	{
		std::wcout << std::endl << status;
	}
};


void ExtractComponentUnitTests::testExtract()
{
	InstallConfigurationPtr configuration(new InstallConfiguration());
	ExtractComponentStdOut extract(::GetModuleHandle(NULL), configuration);
	extract.Exec();
	std::wstring readmetxt = DVLib::DirectoryCombine(InstallerSession::GetSessionTempPath(), L"readme.txt");
	CPPUNIT_ASSERT(DVLib::FileExists(readmetxt));
	CPPUNIT_ASSERT(DVLib::GetFileSize(readmetxt) == 18);
	std::wcout << std::endl << readmetxt << L" - " << DVLib::FormatBytesW(DVLib::GetFileSize(readmetxt));
	DVLib::DirectoryDelete(InstallerSession::GetSessionTempPath());
}
