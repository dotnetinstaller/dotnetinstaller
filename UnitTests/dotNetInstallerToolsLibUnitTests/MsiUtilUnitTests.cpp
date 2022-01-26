#include "StdAfx.h"
#include "MsiUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Microsoft Visual C++ 2010 x64 Redistributable - 10.0.40219
// Microsoft Visual C++ Redistributables MSI Product Codes (2005 – 2017)
// https://qtechbabble.wordpress.com/2017/08/08/microsoft-visual-c-redistributables-msi-product-codes/
// How to extract the upgrade code for a known product code from the registry.
// https://stackoverflow.com/a/17936065/90287
#define WELLKNOWN_UPGRADECODE "{5b75f761-bac8-33bc-a381-464dddd813a3}"

void MsiUtilUnitTests::testGetInstalledProducts()
{
    std::vector<DVLib::MsiProductInfo> installedproducts = DVLib::MsiGetInstalledProducts();
    Assert::IsTrue(installedproducts.size() > 0);
    for each(const DVLib::MsiProductInfo& product in installedproducts)
    {
        // std::wcout << std::endl << DVLib::guid2wstring(product.product_id);
        // std::wcout << std::endl << L" Name: " << product.GetProductName();
        // std::wcout << std::endl << L" Version: " << product.GetVersionString();
        // std::wcout << std::endl << L" Package: " << product.GetProperty(L"LocalPackage");
        Assert::IsTrue(wcslen(product.GetProductName().c_str()) == product.GetProductName().length());
        if (product.HasProperty(INSTALLPROPERTY_VERSIONSTRING))
        {
            Assert::IsTrue(wcslen(product.GetVersionString().c_str()) == product.GetVersionString().length());
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
                << L": " << product.GetProductName();
            
            if (product.HasProperty(INSTALLPROPERTY_LOCALPACKAGE))
            {
                std::wcout << L" (" << product.GetLocalPackage() << L")";
            }
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
    Assert::IsTrue(relatedproducts.size() >= 1);
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
        Assert::IsTrue(DVLib::MsiIsProductInstalled(product.product_id));
    }
    Assert::IsTrue(! DVLib::MsiIsProductInstalled(DVLib::string2guid(L"{00000000-0000-0000-0000-000000000000}")));
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
        Assert::IsTrue(testdata[i].expected_result == DVLib::GetQuotedPathOrGuid(testdata[i].package));
    }
}

void MsiUtilUnitTests::testGetUpgradeCodes()
{
    GUID wellknown_upgradecode = DVLib::string2guid(WELLKNOWN_UPGRADECODE);
    std::vector<DVLib::MsiProductInfo> products = DVLib::MsiGetRelatedProducts(wellknown_upgradecode);
    Assert::IsTrue(products.size() > 0);
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
    Assert::IsTrue(found);
}

void MsiUtilUnitTests::testGetRelatedInstalledProducts()
{
    GUID wellknown_upgradecode = DVLib::string2guid( WELLKNOWN_UPGRADECODE );
    std::vector<DVLib::MsiProductInfo> related_products = DVLib::MsiGetRelatedProducts( wellknown_upgradecode );
    Assert::AreEqual((size_t)1, related_products.size());
    const DVLib::MsiProductInfo& related_product = related_products.at(0);
    Assert::AreEqual(L"Microsoft Visual C++ 2010  x64 Redistributable - 10.0.40219", related_product.GetProductName().c_str());
    Assert::AreEqual("{1D8E6291-B0D5-35EC-8441-6616F567A0F7}", DVLib::guid2string(related_product.product_id).c_str());
}
