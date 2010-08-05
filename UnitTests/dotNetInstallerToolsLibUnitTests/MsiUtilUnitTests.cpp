#include "StdAfx.h"
#include "MsiUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(MsiUtilUnitTests);

// MSBuild Community Tasks required to build this project
#define WELLKNOWN_UPGRADECODE "{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}"

void MsiUtilUnitTests::testGetInstalledProducts()
{
	std::vector<DVLib::MsiProductInfo> installedproducts = DVLib::MsiGetInstalledProducts();
	CPPUNIT_ASSERT(installedproducts.size() > 0);
	for each(const DVLib::MsiProductInfo& product in installedproducts)
	{
		// std::wcout << std::endl << DVLib::guid2wstring(product.product_id);
		// std::wcout << std::endl << L" Name: " << product.GetProductName();
		// std::wcout << std::endl << L" Version: " << product.GetVersionString();
		// std::wcout << std::endl << L" Package: " << product.GetProperty(L"LocalPackage");
		CPPUNIT_ASSERT(wcslen(product.GetProductName().c_str()) == product.GetProductName().length());
		if (product.HasProperty(INSTALLPROPERTY_VERSIONSTRING))
		{
			CPPUNIT_ASSERT(wcslen(product.GetVersionString().c_str()) == product.GetVersionString().length());
		}
	}
}

void MsiUtilUnitTests::testGetAnyInstalledProducts()
{
	int index = 0;
	UINT rc = 0;
	std::vector<wchar_t> buffer;
	buffer.resize(39);
	while ((rc = ::MsiEnumProducts(index, & * buffer.begin())) != ERROR_NO_MORE_ITEMS)
	{
		try
		{
			CHECK_WIN32_DWORD(rc, L"MsiEnumProducts");

			MsiProductInfo product(DVLib::string2guid(& * buffer.begin()));
			std::wcout << std::endl << index << L" - " << DVLib::guid2wstring(product.product_id) 
				<< L": " << product.GetProductName() << L" (" << product.GetLocalPackage() << L")";
		}
		catch(std::exception& ex)
		{
			std::cout << std::endl << " ERROR:" << ex.what();
		}
		
		index++;
	}
}

void MsiUtilUnitTests::testGetRelatedProducts()
{
	std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
		DVLib::string2guid(WELLKNOWN_UPGRADECODE));
	CPPUNIT_ASSERT(relatedproducts.size() >= 1);
	for each(const DVLib::MsiProductInfo& product in relatedproducts)
	{		
		std::wcout << std::endl << DVLib::guid2wstring(product.product_id);
		std::wcout << std::endl << L" Version: " << product.GetVersionString();
		std::wcout << std::endl << L" Package: " << product.GetProperty(L"LocalPackage");
	}
}

void MsiUtilUnitTests::testIsProductInstalled()
{
	// MSBuild Community Tasks 1.3, required to build this project
	std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
		DVLib::string2guid(WELLKNOWN_UPGRADECODE));
	for each(const DVLib::MsiProductInfo& product in relatedproducts)
	{
		CPPUNIT_ASSERT(DVLib::MsiIsProductInstalled(product.product_id));
	}
	CPPUNIT_ASSERT(! DVLib::MsiIsProductInstalled(DVLib::string2guid(L"{00000000-0000-0000-0000-000000000000}")));
}

void MsiUtilUnitTests::testGetQuotedPathOrGuid()
{
	struct TestData
	{
		std::wstring package;
		std::wstring expected_result;
	};

	TestData testdata[] = 
	{
		{ L"{5BA68255-FD99-4f7b-99DE-78270969F8A2}", L"\"{5BA68255-FD99-4f7b-99DE-78270969F8A2}\"" },
		{ L"5BA68255-FD99-4f7b-99DE-78270969F8A2", L"\"5BA68255-FD99-4f7b-99DE-78270969F8A2\"" },
		{ L"file", L"\"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"file") + L"\"" }, 
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		std::wcout << std::endl << testdata[i].package;
		CPPUNIT_ASSERT(testdata[i].expected_result == DVLib::GetQuotedPathOrGuid(testdata[i].package));
	}
}

void MsiUtilUnitTests::testGetUpgradeCodes()
{
	GUID wellknown_upgradecode = DVLib::string2guid(WELLKNOWN_UPGRADECODE);
	std::vector<DVLib::MsiProductInfo> products = DVLib::MsiGetRelatedProducts(wellknown_upgradecode);
	CPPUNIT_ASSERT(products.size() > 0);
	bool found = false;
	for each(const DVLib::MsiProductInfo& product in products)
	{
		std::wcout << std::endl << DVLib::guid2wstring(product.product_id) << L": " << product.GetProductName()
			<< L" (" << product.GetLocalPackage() << L")";
		std::vector<GUID> upgrade_codes = product.GetUpgradeCodes();
		for each(const GUID& upgrade_code in upgrade_codes)
		{
			if (upgrade_code == wellknown_upgradecode)
				found = true;

			std::wcout << std::endl << L"  " << DVLib::guid2wstring(upgrade_code);
		}
	}
	CPPUNIT_ASSERT(found);
}

void MsiUtilUnitTests::testGetRelatedInstalledProducts()
{
	std::vector<DVLib::MsiProductInfo> installedproducts = DVLib::MsiGetInstalledProducts();
	CPPUNIT_ASSERT(installedproducts.size() > 0);
	for each(const DVLib::MsiProductInfo& product in installedproducts)
	{
		std::wcout << std::endl << L"-----------------------------------------------------------------------------";
		std::wcout << std::endl << DVLib::guid2wstring(product.product_id) << L": " << product.GetProductName()
			<< L" (" << product.GetLocalPackage() << L")";
		try
		{
			std::vector<GUID> upgrade_codes = product.GetUpgradeCodes();
			for each(const GUID& upgrade_code in upgrade_codes)
			{
				std::wcout << std::endl << L" * Upgrade code: " << DVLib::guid2wstring(upgrade_code);
				std::vector<DVLib::MsiProductInfo> related_products = DVLib::MsiGetRelatedProducts(upgrade_code);
				for each(const DVLib::MsiProductInfo& related_product in related_products)
				{					
					if (related_product.product_id == product.product_id)
						continue;

					std::wcout << std::endl << L"  - Related product: " << DVLib::guid2wstring(product.product_id) << 
						L": " << related_product.GetProductName();
				}
			}
		}
		catch(std::exception& ex)
		{
			std::cout << std::endl << " ERROR:" << ex.what();
		}
	}
}
