#include "stdafx.h"
#include "WmiUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Any
void WmiUtilUnitTests::Any_WithNoResults_ReturnsFalse()
{
    Assert::IsFalse(DVLib::WmiUtil::Any(L"SELECT * FROM Win32_Process WHERE ProcessId < 0"));
}

void WmiUtilUnitTests::Any_WithOneResult_ReturnsTrue()
{
    Assert::IsTrue(DVLib::WmiUtil::Any(L"SELECT * FROM Win32_OperatingSystem"));
}

void WmiUtilUnitTests::Any_SelectSinglePropertyWithOneResult_ReturnsTrue()
{
    Assert::IsTrue(DVLib::WmiUtil::Any(L"SELECT Name FROM Win32_ComputerSystem"));
}

void WmiUtilUnitTests::Any_WithMultipleResults_ReturnsTrue()
{
    Assert::IsTrue(DVLib::WmiUtil::Any(L"SELECT * FROM Win32_Service"));
}

// Get
void WmiUtilUnitTests::Get_WithNoResults_ReturnsEmptyString()
{
    Assert::AreEqual(L"", DVLib::WmiUtil::Get(L"SELECT * FROM Win32_Process WHERE ProcessId < 0", L"ProcessId").c_str());
}

void WmiUtilUnitTests::Get_WithOneResult_ReturnsExpectedString()
{
    Assert::IsTrue(DVLib::startswith(DVLib::WmiUtil::Get(L"SELECT * FROM Win32_OperatingSystem", L"Caption"), L"Microsoft"));
}

void WmiUtilUnitTests::Get_WithSelectSinglePropertyWithOneResult_ReturnsExpectedString()
{
    Assert::IsTrue(DVLib::startswith(DVLib::WmiUtil::Get(L"SELECT Caption FROM Win32_OperatingSystem", L"Caption"), L"Microsoft"));
}

void WmiUtilUnitTests::Get_WithWithMultipleResults_ReturnsExpectedString()
{
    Assert::AreEqual(L"Auto", DVLib::WmiUtil::Get(L"SELECT * FROM Win32_Service WHERE StartMode = 'Auto'", L"StartMode").c_str());
}