#include "StdAfx.h"
#include "ComponentsStatusUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ComponentsStatusUnitTests);

using namespace DVLib::UnitTests;

void ComponentsStatusUnitTests::testEqual()
{
    ComponentsStatus s1;
    CPPUNIT_ASSERT(s1.all_required());
    CPPUNIT_ASSERT(s1.all_optional());
    ComponentsStatus s2(s1);
    CPPUNIT_ASSERT(s2.all_required());
    CPPUNIT_ASSERT(s2.all_optional());
    s1.add_required(false);
    ComponentsStatus s3 = s1;
    CPPUNIT_ASSERT(! s3.all_required());
    CPPUNIT_ASSERT(s3.all_optional());
    s1.add_optional(false);
    ComponentsStatus s4(s1);
    CPPUNIT_ASSERT(! s4.all_required());
    CPPUNIT_ASSERT(! s4.all_optional());
}

void ComponentsStatusUnitTests::testAllRequired()
{
    ComponentsStatus s;
    CPPUNIT_ASSERT(s.all());
    s.add_required(false);
    CPPUNIT_ASSERT(! s.all());
}

void ComponentsStatusUnitTests::testAllOptional()
{
    ComponentsStatus s;
    CPPUNIT_ASSERT(s.all());
    s.add_optional(false);
    CPPUNIT_ASSERT(! s.all());
}

void ComponentsStatusUnitTests::testAll()
{
    ComponentsStatus s;
    CPPUNIT_ASSERT(s.all());
    s.add_required(false);
    s.add_optional(false);
    CPPUNIT_ASSERT(! s.all());
}
