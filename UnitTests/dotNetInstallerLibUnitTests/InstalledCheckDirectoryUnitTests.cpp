#include "StdAfx.h"
#include "InstalledCheckDirectoryUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckDirectoryUnitTests::testIsInstalled()
{
    std::wcout << std::endl << L"Checking " << DVLib::GetSystemDirectoryW();
    InstalledCheckDirectory check;
    check.path = DVLib::GetSystemDirectoryW();
    Assert::IsTrue(check.IsInstalled());
    check.path = DVLib::GenerateGUIDStringW();
    Assert::IsTrue(! check.IsInstalled());
}