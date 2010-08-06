#include "StdAfx.h"
#include "MsiUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"
#include "GuidUtil.h"
#include "PathUtil.h"

struct msi_close_handle
{
	static void close(MSIHANDLE h)
	{
		CHECK_WIN32_DWORD(::MsiCloseHandle(h),
			L"MsiCloseHandle (" << std::hex << (h) << L")");
	}
};

typedef auto_any<MSIHANDLE, msi_close_handle> MsiHandlePtr;

std::vector<DVLib::MsiProductInfo> DVLib::MsiGetInstalledProducts()
{
	std::vector<MsiProductInfo> products;
	int index = 0;
	UINT rc = 0;
	std::vector<wchar_t> buffer;
	buffer.resize(39);
	while ((rc = ::MsiEnumProducts(index, & * buffer.begin())) != ERROR_NO_MORE_ITEMS)
	{
		if (rc == ERROR_SUCCESS)
		{
			MsiProductInfo info(DVLib::string2guid(& * buffer.begin()));
			products.push_back(info);
		}

		index++;
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
		CHECK_WIN32_DWORD(rc, L"MsiEnumRelatedProducts (" << upgradecode_s << L")");
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

bool DVLib::MsiProductInfo::HasProperty(const std::wstring& property_name) const
{
	std::wstring product_id_s = DVLib::guid2wstring(product_id);
	DWORD property_size = 0;
	DWORD property_rc = ::MsiGetProductInfo(product_id_s.c_str(), property_name.c_str(), NULL, & property_size);
	
	if (property_rc == ERROR_UNKNOWN_PROPERTY)
		return false;
	
	if (property_rc != ERROR_MORE_DATA)
	{
		CHECK_WIN32_DWORD(property_rc, 
			L"MsiGetProductInfo (" << product_id_s << L")");
	}

	return true;
}

std::wstring DVLib::MsiProductInfo::GetProperty(const std::wstring& property_name) const
{
	std::wstring product_id_s = DVLib::guid2wstring(product_id);
	std::vector<wchar_t> property_value;
	DWORD property_size = 0;
	DWORD property_rc = ::MsiGetProductInfo(product_id_s.c_str(), property_name.c_str(), NULL, & property_size);
	if (property_rc != ERROR_MORE_DATA)
	{
		CHECK_WIN32_DWORD(property_rc, 
			L"MsiGetProductInfo (" << product_id_s << L", " << property_name << L")");
	}

	if (property_size > 0)
	{
		property_value.resize(property_size + 1);
		property_size = property_value.size();
		CHECK_WIN32_DWORD(::MsiGetProductInfo(product_id_s.c_str(), property_name.c_str(), 
			& * property_value.begin(), & property_size),
			L"MsiGetProductInfo (" << product_id_s << L", " << property_name << L")");
		return std::wstring(& * property_value.begin(), property_size);
	}
	else
	{
		return L"";
	}
}

std::vector<GUID> DVLib::MsiProductInfo::GetUpgradeCodes() const
{
	std::vector<GUID> upgrade_codes;
	std::wstring local_package = GetLocalPackage();

	MsiHandlePtr h;
	MsiHandlePtr hView;

	MSIHANDLE _h = NULL;
	CHECK_WIN32_DWORD(::MsiOpenDatabase(local_package.c_str(), MSIDBOPEN_READONLY, & _h),
		L"MsiOpenDatabase (" << local_package << L")");

	reset(h, _h);

	MSIHANDLE _hView = NULL;
	CHECK_WIN32_DWORD(::MsiDatabaseOpenView(get(h), L"SELECT DISTINCT `UpgradeCode` FROM `Upgrade`", & _hView),
		L"MsiDatabaseOpenView (" << local_package << L")");

	reset(hView, _hView);

	CHECK_WIN32_DWORD(::MsiViewExecute(get(hView), NULL),
		L"MsiViewExecute (" << local_package << L")");
		
	while(true)
	{
		MsiHandlePtr hRow;

		MSIHANDLE _hRow = NULL;
		UINT rc = ::MsiViewFetch(get(hView), & _hRow);
		reset(hRow, _hRow);

		if (rc == ERROR_NO_MORE_ITEMS)
		{
			break;
		}
		else if (rc != ERROR_SUCCESS)
		{
			CHECK_WIN32_DWORD(rc,
				L"MsiViewFetch (" << local_package << L")");
		}

		// read upgrade code
        std::wstring data;
        DWORD cbRead = 0;
        CHECK_WIN32_DWORD(::MsiRecordGetString(get(hRow), 1, NULL, & cbRead),
            L"MsiRecordGetString (" << local_package << L")");

		if (cbRead > 0)
		{
			data.resize(cbRead++);
			CHECK_WIN32_DWORD(::MsiRecordGetString(get(hRow), 1, & * data.begin(), & cbRead), 
				L"MsiRecordGetString (" << local_package << L"/" << cbRead << L")");
			data.resize(cbRead);
		}

		GUID upgrade_code = DVLib::string2guid(data);
		upgrade_codes.push_back(upgrade_code);
	}

	return upgrade_codes;
}


std::vector<DVLib::MsiProductInfo> DVLib::MsiProductInfo::GetRelatedProducts() const
{
	std::vector<DVLib::MsiProductInfo> products;
	std::vector<GUID> upgrade_codes = GetUpgradeCodes();
	for each(const GUID& upgrade_code in upgrade_codes)
	{
		std::vector<DVLib::MsiProductInfo> related_products = MsiGetRelatedProducts(upgrade_code);
		products.insert(products.end(), related_products.begin(), related_products.end());
	}
	return products;
}

bool DVLib::MsiIsProductInstalled(GUID guid)
{
	std::vector<MsiProductInfo> products = MsiGetInstalledProducts();
	for each(const MsiProductInfo& pi in products)
	{
		if (pi.product_id == guid)
			return true;
	}

	return false;
}

std::wstring DVLib::GetQuotedPathOrGuid(const std::wstring& package)
{
	std::wstring result;
	result.append(L"\"");
	result += (DVLib::isguid(package) ? package : DVLib::DirectoryCombine(
			DVLib::GetCurrentDirectoryW(), package));
	result.append(L"\"");
	return result;
}

