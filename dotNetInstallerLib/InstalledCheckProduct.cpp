#include "StdAfx.h"
#include "XmlAttribute.h"
#include "InstalledCheckProduct.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

InstalledCheckProduct::InstalledCheckProduct()
{
}

void InstalledCheckProduct::Load(tinyxml2::XMLElement * node)
{
    id_type = DVLib::UTF8string2wstring(node->Attribute("id_type"));
    id = node->Attribute("id");
    propertyname = node->Attribute("propertyname");
    comparison = DVLib::UTF8string2wstring(node->Attribute("comparison"));
    propertyvalue = node->Attribute("propertyvalue");
    defaultvalue = node->Attribute("defaultvalue");
    LOG(L"Loaded 'product' installed check '" << id << L"'");
}

bool InstalledCheckProduct::IsInstalled() const
{
    GUID id_guid = DVLib::string2guid(id);
    std::vector<DVLib::MsiProductInfo> products;
    if (id_type == L"productcode")
    {
        if (DVLib::MsiIsProductInstalled(id_guid))
        {
            DVLib::MsiProductInfo pi(id_guid);
            try
            {
                LOG(L"Product '" << pi.GetProductName() << L"', id=" << id << L", version=" << pi.GetVersionString() << L" is installed");
            }
            catch(std::exception& ex)
            {
                LOG("Warning: product id=" << DVLib::guid2wstring(pi.product_id) << L"GetProductName/Version - " 
                    << DVLib::string2wstring(ex.what()));
            }

            products.push_back(pi);
        }
        else
        {
            LOG(L"Product id=" << id << L" is not installed.");
        }
    }
    else if (id_type == L"upgradecode")
    {
        products = DVLib::MsiGetRelatedProducts(id_guid);
        for each(const DVLib::MsiProductInfo& pi in products)
        {
            try
            {
                LOG(L"Product '" << pi.GetProductName() << L"', id=" << DVLib::guid2wstring(pi.product_id)
                    << L", upgradecode=" << id << L", version=" << pi.GetVersionString() << L" found");
            }
            catch(std::exception& ex)
            {
                LOG("Warning: product id=" << DVLib::guid2wstring(pi.product_id) << L"GetProductName/Version - " 
                    << DVLib::string2wstring(ex.what()));
            }
        }
    }
    else
    {
        THROW_EX(L"Invalid id_type: " << id_type);
    }

    // the product/upgrade code exists
    if (comparison == L"exists")
        return products.size() > 0;

    // match, version or contains
    if (products.size() == 0) 
    {
        bool result = defaultvalue.GetBoolValue(false); 
        LOG(L"Product id=" << id << L" not found, returning default value: " << (result ? L"True" : L"False"));
        return result;
    }

    std::list<std::wstring> pi_propertyvalues;
    for each(const DVLib::MsiProductInfo& pi in products)
    {
        try
        {
            std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
            LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
            pi_propertyvalues.push_back(pi_propertyvalue);
        }
        catch(std::exception& ex)
        {
            LOG("Warning: product id=" << DVLib::guid2wstring(pi.product_id) << L"GetProperty(" << propertyname << L") - " 
                << DVLib::string2wstring(ex.what()));
        }
    }

    if (comparison == L"match")
    {
        for each(const std::wstring& pi_propertyvalue in pi_propertyvalues)
        {
            if (propertyvalue != pi_propertyvalue)
            {
                LOG(L"Check value '" << propertyvalue << L"' doesn't match '" << pi_propertyvalue << L"'");
                return false;
            }
            else
            {
                LOG(L"Check value '" << propertyvalue << L"' matches '" << pi_propertyvalue << L"'");
            }
        }

        return true;
    }
    else if (comparison == L"contains")
    {
        for each (const std::wstring & pi_propertyvalue in pi_propertyvalues)
        {
            if (propertyvalue == pi_propertyvalue)
            {
                LOG(L"Check value '" << propertyvalue << L"' found in '" << pi_propertyvalue << L"'");
                return true;
            }
            else
            {
                LOG(L"Check value '" << propertyvalue << L"' not found in '" << pi_propertyvalue << L"'");
            }
        }

        return false;
    }
    else
    {
        return DVLib::CompareVersion(comparison, pi_propertyvalues, propertyvalue);
    }
}
