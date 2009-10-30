#pragma once
#include "ControlText.h"

class ControlLicense : public ControlText
{
public:
    ControlLicense();
public:
	std::wstring resource_id;
	std::wstring license_file;
	std::wstring accept_message;
	bool accepted;
	void Load(TiXmlElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlLicense *, close_delete> ControlLicensePtr;
