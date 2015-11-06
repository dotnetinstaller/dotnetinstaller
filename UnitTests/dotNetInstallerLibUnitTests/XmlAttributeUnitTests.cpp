#include "StdAfx.h"
#include "XmlAttributeUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::XmlAttributeUnitTests);

using namespace DVLib::UnitTests;

void XmlAttributeUnitTests::testEmpty()
{
    XmlAttribute attr;
    CPPUNIT_ASSERT(attr.GetValue().empty());
    CPPUNIT_ASSERT(false == attr.GetBoolValue(false));
    CPPUNIT_ASSERT(true == attr.GetBoolValue(true));
}

void XmlAttributeUnitTests::testGetValue()
{
    XmlAttribute attr(L"2");
    CPPUNIT_ASSERT(L"2" == attr.GetValue());
    CPPUNIT_ASSERT(2 == attr.GetLongValue());
    attr = L"3";
    CPPUNIT_ASSERT(L"3" == attr.GetValue());
    CPPUNIT_ASSERT(3 == attr.GetLongValue());
    attr = XmlAttribute(L"4");
    CPPUNIT_ASSERT(L"4" == attr.GetValue());
    CPPUNIT_ASSERT(4 == attr.GetLongValue());
}
