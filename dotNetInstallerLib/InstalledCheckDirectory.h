#pragma once

#include "XmlAttribute.h"
#include "InstalledCheck.h"

class InstalledCheckDirectory : public InstalledCheck
{
public:
	// full path to the directory to check
	std::wstring path;
	// The type of comparison.
	XmlAttribute comparison;
	// The version number to compare against.
	XmlAttribute version;
public:
    InstalledCheckDirectory();
    void Load(tinyxml2::XMLElement * node);
	virtual bool IsInstalled() const;
};

typedef shared_any<InstalledCheckDirectory *, close_delete> InstalledCheckDirectoryPtr;
