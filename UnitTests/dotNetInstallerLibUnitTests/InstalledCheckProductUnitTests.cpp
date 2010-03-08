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

void InstalledCheckProductUnitTests::testDefaultValue()
{
	InstalledCheckProductPtr check(new InstalledCheckProduct());
	check->id_type = L"upgradecode";
	check->id = L"{3D1871AE-5696-45d4-B1C2-C321484B8DFF}"; // new GUID
	check->propertyname = L"VersionString";
	check->propertyvalue = L"1.0.0.0";

	typedef struct
	{
		LPCWSTR comparison;
		bool defaultvalue;
		bool expected_result;
	} TestData;

	TestData data[] = 
	{
		{ L"exists", false, false },
		{ L"exists", true, false },
		{ L"contains", false, false },
		{ L"contains", true, true },
		{ L"match", false, false },
		{ L"match", true, true },
		{ L"version", false, false },
		{ L"version", true, true },
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		check->comparison = data[i].comparison;
		check->defaultvalue = (data[i].defaultvalue ? L"True" : L"False");
		CPPUNIT_ASSERT(data[i].expected_result == check->IsInstalled());
	}
}