#include "StdAfx.h"
#include "MsiUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"
#include "GuidUtil.h"

std::vector<DVLib::MsiProductInfo> DVLib::MsiGetInstalledProducts()
{
	std::vector<MsiProductInfo> products;
	int index = 0;
	UINT rc = 0;
	std::vector<wchar_t> buffer;
	buffer.resize(39);
	while ((rc = ::MsiEnumProducts(index, & * buffer.begin())) == ERROR_SUCCESS)
	{
		MsiProductInfo info(DVLib::string2guid(& * buffer.begin()));
		products.push_back(info);
		index++;
	}

	if (rc != ERROR_NO_MORE_ITEMS)
	{
		CHECK_WIN32_DWORD(rc, L"MsiEnumProducts");
	}

	return products;
}

std::vector<DVLib::MsiProductInfo> DVLib::MsiGetRelatedProducts(GUID upgradecode)
{
	std::vector<MsiProductInfo> products;
	std::wstring upgradecode_s = DVLib::guid2wstring(upgradecode);
	int index = 0;
	UINT rc = 0;
	std::vector<wchar_t> buffer;
	buffer.resize(39);
	while ((rc = ::MsiEnumRelatedProducts(upgradecode_s.c_str(), 0, index, & * buffer.begin())) == ERROR_SUCCESS)
	{
		MsiProductInfo info(DVLib::string2guid(& * buffer.begin()));
		products.push_back(info);
		index++;
	}

	if (rc != ERROR_NO_MORE_ITEMS)
	{
		CHECK_WIN32_DWORD(rc, L"MsiEnumRelatedProducts");
	}

	return products;
}

DVLib::MsiProductInfo& DVLib::MsiProductInfo::operator=(const MsiProductInfo& info)
{
	product_id = info.product_id;
	return * this;
}

DVLib::MsiProductInfo::MsiProductInfo(GUID guid)
{
	product_id = guid;
}

DVLib::MsiProductInfo::MsiProductInfo(const MsiProductInfo& info)
{
	operator=(info);
}

std::wstring DVLib::MsiProductInfo::GetProperty(const std::wstring& property_name) const
{
	std::wstring product_id_string = DVLib::guid2wstring(product_id);
	std::vector<wchar_t> property_value;
	DWORD property_size = 0;
	DWORD property_rc = ::MsiGetProductInfo(product_id_string.c_str(), property_name.c_str(), NULL, & property_size);
	if (property_rc != ERROR_MORE_DATA)
	{
		CHECK_WIN32_DWORD(property_rc, 
			L"MsiGetProductInfo");
	}

	if (property_size > 0)
	{
		property_value.resize(property_size + 1);
		property_size = property_value.size();
		CHECK_WIN32_DWORD(::MsiGetProductInfo(product_id_string.c_str(), property_name.c_str(), 
			& * property_value.begin(), & property_size),
			L"MsiGetProductInfo");
		return std::wstring(& * property_value.begin(), property_size);
	}
	else
	{
		return L"";
	}
}

bool DVLib::MsiIsProductInstalled(GUID guid)
{
	for each(const MsiProductInfo& pi in MsiGetInstalledProducts())
	{
		if (pi.product_id == guid)
			return true;
	}

	return false;
}