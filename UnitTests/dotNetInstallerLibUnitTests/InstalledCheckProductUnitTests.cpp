#include "StdAfx.h"
#include "InstalledCheckProductUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckProductUnitTests);

using namespace DVLib::UnitTests;

void InstalledCheckProductUnitTests::testProductCode()
{
	// MSBuild Community Tasks
	std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
		DVLib::string2guid(L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}"));
	CPPUNIT_ASSERT(relatedproducts.size() > 0);
	for each(const DVLib::MsiProductInfo& product in relatedproducts)
	{
		std::wcout << std::endl << L" " << product.GetProductName() << L": " << product.GetVersionString();
		InstalledCheckProductPtr check(new InstalledCheckProduct());
		check->id_type = L"productcode";
		check->id = DVLib::guid2wstring(product.product_id);
		check->propertyname = L"VersionString";
		check->propertyvalue = L"1.0.0.0";
		check->comparison = L"exists";
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"contains";
		CPPUNIT_ASSERT(! check->IsInstalled());
		check->comparison = L"match";
		CPPUNIT_ASSERT(! check->IsInstalled());
		check->propertyvalue = product.GetVersionString();
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"contains";
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"version";
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"version_eq";
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"version_lt";
		CPPUNIT_ASSERT(! check->IsInstalled());
		check->comparison = L"version_le";
		CPPUNIT_ASSERT(check->IsInstalled());
		check->comparison = L"version_gt";
		CPPUNIT_ASSERT(! check->IsInstalled());
		check->comparison = L"version_ge";
		CPPUNIT_ASSERT(check->IsInstalled());
	}
}

void InstalledCheckProductUnitTests::testUpgradeCode()
{
	// MSBuild Community Tasks
	InstalledCheckProductPtr check(new InstalledCheckProduct());
	check->id_type = L"upgradecode";
	check->id = L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}";
	check->propertyname = L"VersionString";
	check->propertyvalue = L"1.0.0.0";
	check->comparison = L"exists";
	CPPUNIT_ASSERT(check->IsInstalled());
	check->comparison = L"contains";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"match";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"contains";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"version";
	CPPUNIT_ASSERT(check->IsInstalled());
	check->comparison = L"version_eq";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"version_lt";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"version_le";
	CPPUNIT_ASSERT(! check->IsInstalled());
	check->comparison = L"version_gt";
	CPPUNIT_ASSERT(check->IsInstalled());
	check->comparison = L"version_ge";
	CPPUNIT_ASSERT(check->IsInstalled());
}
