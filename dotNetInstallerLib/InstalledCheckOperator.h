#pragma once
#include "InstalledCheck.h"

class InstalledCheckOperator : public InstalledCheck
{
public:
	// operator type
	XmlAttribute type;
	// operator description
    XmlAttribute description; 
	// installed checks
	std::vector< InstalledCheckPtr > installedchecks;
public:	
    InstalledCheckOperator();
	bool IsInstalled() const;
    void Load(tinyxml2::XMLElement * node);
};

typedef shared_any<InstalledCheckOperator *, close_delete> InstalledCheckOperatorPtr;
