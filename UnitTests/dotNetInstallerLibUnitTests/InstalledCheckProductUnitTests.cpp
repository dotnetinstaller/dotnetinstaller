#include "StdAfx.h"
#include "InstalledCheckProductUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckProductUnitTests::testProductCode()
{
    typedef struct
    {
        LPCWSTR pszGuid;
    } TestData;

    TestData data[] = 
    {
        // Microsoft Visual C++ 2010 x64 Redistributable - 10.0.40219 Upgrade Code
        { L"5b75f761-bac8-33bc-a381-464dddd813a3" },
        { L"{5b75f761-bac8-33bc-a381-464dddd813a3}" },
    };

    for (int i = 0; i < ARRAYSIZE(data); i++)
    {
        std::wcout << std::endl << L"ProductCode: " << data[i].pszGuid;

        std::vector<DVLib::MsiProductInfo> relatedproducts = DVLib::MsiGetRelatedProducts(
            DVLib::string2guid(data[i].pszGuid));
        Assert::IsTrue(relatedproducts.size() > 0);
        for each(const DVLib::MsiProductInfo& product in relatedproducts)
        {
            std::wcout << std::endl << L" " << product.GetProductName() << L": " << product.GetVersionString();
            InstalledCheckProductPtr check(new InstalledCheckProduct());
            check->id_type = L"productcode";
            check->id = DVLib::guid2wstring(product.product_id);
            check->propertyname = L"VersionString";
            check->propertyvalue = L"1.0.0.0";
            check->comparison = L"exists";
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"contains";
            Assert::IsTrue(! check->IsInstalled());
            check->comparison = L"match";
            Assert::IsTrue(! check->IsInstalled());
            check->propertyvalue = product.GetVersionString();
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"contains";
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"version";
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"version_eq";
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"version_lt";
            Assert::IsTrue(! check->IsInstalled());
            check->comparison = L"version_le";
            Assert::IsTrue(check->IsInstalled());
            check->comparison = L"version_gt";
            Assert::IsTrue(! check->IsInstalled());
            check->comparison = L"version_ge";
            Assert::IsTrue(check->IsInstalled());
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
        // Microsoft Visual C++ 2010 x64 Redistributable - 10.0.40219 Upgrade Code
        { L"5b75f761-bac8-33bc-a381-464dddd813a3" },
        { L"{5b75f761-bac8-33bc-a381-464dddd813a3}" },
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
        Assert::IsTrue(check->IsInstalled());
        check->comparison = L"contains";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"match";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"contains";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"version";
        Assert::IsTrue(check->IsInstalled());
        check->comparison = L"version_eq";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"version_lt";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"version_le";
        Assert::IsTrue(! check->IsInstalled());
        check->comparison = L"version_gt";
        Assert::IsTrue(check->IsInstalled());
        check->comparison = L"version_ge";
        Assert::IsTrue(check->IsInstalled());
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
        Assert::IsTrue(data[i].expected_result == check->IsInstalled());
    }
}