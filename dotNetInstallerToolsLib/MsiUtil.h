#pragma once

namespace DVLib
{
	class MsiProductInfo
	{
	public:
		GUID product_id;
		// retrieve a property value for a given product
		std::wstring GetProperty(const std::wstring& property_name) const;
		bool HasProperty(const std::wstring& property_name) const;
		MsiProductInfo& operator=(const MsiProductInfo&);
		MsiProductInfo(GUID guid);
		MsiProductInfo(const MsiProductInfo&);
		std::wstring GetProductName() const { return GetProperty(INSTALLPROPERTY_PRODUCTNAME); }
		std::wstring GetVersionString() const { return GetProperty(INSTALLPROPERTY_VERSIONSTRING); }
		std::wstring GetLocalPackage() const { return GetProperty(INSTALLPROPERTY_LOCALPACKAGE); }
	};

	// is the product installed
	bool MsiIsProductInstalled(GUID guid);
	// the list of installed products
	std::vector<MsiProductInfo> MsiGetInstalledProducts();
	// the list of related products
	std::vector<MsiProductInfo> MsiGetRelatedProducts(GUID upgradecode);
	// quote a path or guid
	std::wstring GetQuotedPathOrGuid(const std::wstring& package);
}
