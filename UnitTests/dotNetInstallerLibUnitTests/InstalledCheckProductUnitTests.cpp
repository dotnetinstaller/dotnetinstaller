#include "StdAfx.h"
#include "InstalledCheckProductUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckProductUnitTests);

using namespace DVLib::UnitTests;

void InstalledCheckProductUnitTests::testProductCode()
{
	typedef struct
	{
		LPCWSTR pszGuid;
	} TestData;

	TestData data[] = 
	{
		{ L"F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E" }, // MSBuild Community Tasks
		{ L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}" }, // MSBuild Community Tasks		
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << L"ProductCode: " << data[i].pszGuid;

		std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
			DVLib::string2guid(data[i].pszGuid));
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
}

void InstalledCheckProductUnitTests::testUpgradeCode()
{
	typedef struct
	{
		LPCWSTR pszGuid;
	} TestData;

	TestData data[] = 
	{
		{ L"F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E" }, // MSBuild Community Tasks
		{ L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}" }, // MSBuild Community Tasks		
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << L"UpgradeCode: " << data[i].pszGuid;

		InstalledCheckProductPtr check(new InstalledCheckProduct());
		check->id_type = L"upgradecode";
		check->id = data[i].pszGuid;
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
}
