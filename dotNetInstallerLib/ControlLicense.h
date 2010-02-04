#pragma once
#include "ControlText.h"

class ControlLicense : public ControlText
{
public:
    ControlLicense();
public:
	XmlAttribute resource_id;
	XmlAttribute license_file;
	XmlAttribute accept_message;
	bool accepted;
	void Load(TiXmlElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlLicense *, close_delete> ControlLicensePtr;
