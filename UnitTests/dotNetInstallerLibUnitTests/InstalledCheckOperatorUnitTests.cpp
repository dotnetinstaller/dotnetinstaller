#include "StdAfx.h"
#include "InstalledCheckOperatorUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class InstalledCheckTrue : public InstalledCheck
{
public:
    InstalledCheckTrue() {  }
    bool IsInstalled() const { return true; }
    void Load(tinyxml2::XMLElement * /*node*/) { }
};

class InstalledCheckFalse : public InstalledCheck
{
public:
    InstalledCheckFalse() {  }
    bool IsInstalled() const { return false; }
    void Load(tinyxml2::XMLElement * /*node*/) { }
};

void InstalledCheckOperatorUnitTests::testAnd()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"And";
    Assert::IsTrue(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    Assert::IsTrue(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(! check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(! check->IsInstalled());
}

void InstalledCheckOperatorUnitTests::testOr()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"Or";
    Assert::IsTrue(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    Assert::IsTrue(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(! check->IsInstalled());
}

void InstalledCheckOperatorUnitTests::testNot()
{
    InstalledCheckOperatorPtr check(new InstalledCheckOperator());
    check->type = L"Not";
    Assert::IsTrue(check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckTrue()));
    Assert::IsTrue(! check->IsInstalled());
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(! check->IsInstalled());
    check->installedchecks.clear();
    check->installedchecks.push_back(InstalledCheckPtr(new InstalledCheckFalse()));
    Assert::IsTrue(check->IsInstalled());
}