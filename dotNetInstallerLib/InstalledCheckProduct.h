#pragma once
#include "InstalledCheck.h"

class InstalledCheckProduct : public InstalledCheck
{
public:
	// UpgradeCode or ProductCode
	std::wstring id_type;
	// product/upgrade code
	std::wstring id;
	// product property to check
	std::wstring propertyname;
	// one of version, match, etc.
	std::wstring comparison;
	// property value to match
	std::wstring propertyvalue;
public:
    InstalledCheckProduct();
    void Load(TiXmlElement * node);
	virtual bool IsInstalled() const;
};

typedef shared_any<InstalledCheckProduct *, close_delete> InstalledCheckProductPtr;

