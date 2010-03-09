#include "StdAfx.h"
#include "MsiUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(MsiUtilUnitTests);

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

void MsiUtilUnitTests::testGetRelatedProducts()
{
	// MSBuild Community Tasks, required to build this project
	std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
		DVLib::string2guid(L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}"));
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
		DVLib::string2guid(L"{F289AA13-BBAF-4EA2-97C8-BAEC7E5B743E}"));
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