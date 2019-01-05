#include "StdAfx.h"
#include "XmlAttributeUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void XmlAttributeUnitTests::testEmpty()
{
    XmlAttribute attr;
    Assert::IsTrue(attr.GetValue().empty());
    Assert::IsTrue(false == attr.GetBoolValue(false));
    Assert::IsTrue(true == attr.GetBoolValue(true));
}

void XmlAttributeUnitTests::testGetValue()
{
    XmlAttribute attr(L"2");
    Assert::IsTrue(L"2" == attr.GetValue());
    Assert::IsTrue(2 == attr.GetLongValue());
    attr = L"3";
    Assert::IsTrue(L"3" == attr.GetValue());
    Assert::IsTrue(3 == attr.GetLongValue());
    attr = XmlAttribute(L"4");
    Assert::IsTrue(L"4" == attr.GetValue());
    Assert::IsTrue(4 == attr.GetLongValue());
}
