#include "StdAfx.h"
#include "InstalledCheckOperatorUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckOperatorUnitTests);

using namespace DVLib::UnitTests;

class InstalledCheckTrue : public InstalledCheck
{
public:
	bool IsInstalled() const { return true; }
	void Load(TiXmlElement * node, InstallerSetting & setting) { }
	static InstalledCheckTrue Instance;
};

class InstalledCheckFalse : public InstalledCheck
{
public:
	bool IsInstalled() const { return false; }
	void Load(TiXmlElement * node, InstallerSetting & setting) { }
	static InstalledCheckFalse Instance;
};

InstalledCheckFalse InstalledCheckFalse::Instance;
InstalledCheckTrue InstalledCheckTrue::Instance;

void InstalledCheckOperatorUnitTests::testAnd()
{
	InstalledCheckOperator check;
	check.type = L"And";
	CPPUNIT_ASSERT(! check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckTrue::Instance);
	CPPUNIT_ASSERT(check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(! check.IsInstalled());
	check.installed_checks.clear();
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(! check.IsInstalled());
}

void InstalledCheckOperatorUnitTests::testOr()
{
	InstalledCheckOperator check;
	check.type = L"Or";
	CPPUNIT_ASSERT(! check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckTrue::Instance);
	CPPUNIT_ASSERT(check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(check.IsInstalled());
	check.installed_checks.clear();
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(! check.IsInstalled());
}

void InstalledCheckOperatorUnitTests::testNot()
{
	InstalledCheckOperator check;
	check.type = L"Not";
	CPPUNIT_ASSERT(check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckTrue::Instance);
	CPPUNIT_ASSERT(! check.IsInstalled());
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(! check.IsInstalled());
	check.installed_checks.clear();
	check.installed_checks.push_back(& InstalledCheckFalse::Instance);
	CPPUNIT_ASSERT(check.IsInstalled());
}