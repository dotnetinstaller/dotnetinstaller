#include "StdAfx.h"
#include "ComponentsStatusUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ComponentsStatusUnitTests::testEqual()
{
    ComponentsStatus s1;
    Assert::IsTrue(s1.all_required());
    Assert::IsTrue(s1.all_optional());
    ComponentsStatus s2(s1);
    Assert::IsTrue(s2.all_required());
    Assert::IsTrue(s2.all_optional());
    s1.add_required(false);
    ComponentsStatus s3 = s1;
    Assert::IsTrue(! s3.all_required());
    Assert::IsTrue(s3.all_optional());
    s1.add_optional(false);
    ComponentsStatus s4(s1);
    Assert::IsTrue(! s4.all_required());
    Assert::IsTrue(! s4.all_optional());
}

void ComponentsStatusUnitTests::testAllRequired()
{
    ComponentsStatus s;
    Assert::IsTrue(s.all());
    s.add_required(false);
    Assert::IsTrue(! s.all());
}

void ComponentsStatusUnitTests::testAllOptional()
{
    ComponentsStatus s;
    Assert::IsTrue(s.all());
    s.add_optional(false);
    Assert::IsTrue(! s.all());
}

void ComponentsStatusUnitTests::testAll()
{
    ComponentsStatus s;
    Assert::IsTrue(s.all());
    s.add_required(false);
    s.add_optional(false);
    Assert::IsTrue(! s.all());
}
