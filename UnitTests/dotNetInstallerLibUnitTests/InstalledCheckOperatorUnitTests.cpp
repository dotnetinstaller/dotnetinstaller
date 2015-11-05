#include "StdAfx.h"
#include "InstalledCheckOperatorUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckOperatorUnitTests);

using namespace DVLib::UnitTests;

class InstalledCheckTrue : public InstalledCheck
{
public:
    InstalledCheckTrue() {  }
    bool IsInstalled() const { return true; }
    void Load(TiXmlElement * /*node*/) { }
};

class InstalledCheckFalse : public InstalledCheck
{
public:
    InstalledCheckFalse() {  }
    bool IsInstalled() const { return false; }
    void Load(TiXmlElement * /*node*/) { }
};

void InstalledCheckOperatorUnitTests::testAnd()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"And";
    CPPUNIT_ASSERT(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    CPPUNIT_ASSERT(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(! check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(! check->IsInstalled());
}

void InstalledCheckOperatorUnitTests::testOr()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"Or";
    CPPUNIT_ASSERT(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    CPPUNIT_ASSERT(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(! check->IsInstalled());
}

void InstalledCheckOperatorUnitTests::testNot()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"Not";
    CPPUNIT_ASSERT(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    CPPUNIT_ASSERT(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(! check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    CPPUNIT_ASSERT(check->IsInstalled());
}