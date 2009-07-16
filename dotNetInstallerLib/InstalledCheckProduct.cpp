#include "StdAfx.h"
#include "InstalledCheckProduct.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

InstalledCheckProduct::InstalledCheckProduct()
{
}

void InstalledCheckProduct::Load(TiXmlElement * node)
{
	id_type = node->AttributeW("id_type");
	id = node->AttributeW("id");
	propertyname = node->AttributeW("propertyname");
	comparison = node->AttributeW("comparison");
	propertyvalue = node->AttributeW("propertyvalue");
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
			LOG(L"Product '" << pi.GetProductName() 
				<< L"', id=" << id 
				<< L", version=" << pi.GetVersionString() << L" is installed");
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
			LOG(L"Product '" << pi.GetProductName() 
				<< L"', id=" << DVLib::guid2wstring(pi.product_id)
				<< L", upgradecode=" << id 
				<< L", version=" << pi.GetVersionString()
				<< L" found");
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
		return false;		

	if (comparison == L"match")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (pi_propertyvalue != propertyvalue)
			{
				LOG(L"Check value '" << propertyvalue << L"' doesn't match.");
				return false;
			}
		}

		return true;
	}
	else if (comparison == L"contains")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (pi_propertyvalue == propertyvalue)
			{
				LOG(L"Check value '" << propertyvalue << L"' found.");
				return true;
			}
		}

		return false;
	}
	else if (comparison == L"version")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (DVLib::CompareVersion(pi_propertyvalue, propertyvalue) >= 0) 
			{
				LOG(L"Check value '" << propertyvalue << L"' version match.");
				return true;
			}
		}

		return false;
	}
	else if (comparison == L"version_eq")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (DVLib::CompareVersion(pi_propertyvalue, propertyvalue) == 0) 
			{
				LOG(L"Check value '" << propertyvalue << L"' version equals.");
				return true;
			}
		}

		return false;
	}
	else if (comparison == L"version_lt")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (DVLib::CompareVersion(pi_propertyvalue, propertyvalue) < 0)
			{
				LOG(L"Check value '" << propertyvalue << L"' version lesser match.");
				return true;
			}
		}

		return false;
	}
	else if (comparison == L"version_gt")
	{
		for each(const DVLib::MsiProductInfo& pi in products)
		{
			std::wstring pi_propertyvalue = pi.GetProperty(propertyname);
			LOG(L"Product '" << pi.GetProductName() << L"', " << propertyname << L"='" << pi_propertyvalue << L"'");
			if (DVLib::CompareVersion(pi_propertyvalue, propertyvalue) > 0) 
			{
				LOG(L"Check value '" << propertyvalue << L"' version greater match.");
				return true;
			}
		}

		return false;
	}
	else
	{
		THROW_EX(L"Invalid comparison: " << comparison);
	}
}
