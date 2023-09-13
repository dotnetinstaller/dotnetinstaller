#include "stdafx.h"
#include "WmiUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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