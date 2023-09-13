#pragma once

#include "XmlAttribute.h"
#include "InstalledCheck.h"

class InstalledCheckWmi : public InstalledCheck
{
public:
	// WMI Query Language (WQL) statement to run
	XmlAttribute query;
public:
	void Load(tinyxml2::XMLElement* node);
	bool IsInstalled() const;
};

typedef shared_any<InstalledCheckWmi*, close_delete> InstalledCheckWmiPtr;