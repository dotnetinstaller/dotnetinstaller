#pragma once
#include "InstalledCheck.h"

class InstalledCheckOperator : public InstalledCheck
{
public:
	// operator type
	std::wstring type;
	// operator description
    std::wstring description; 
	// installed checks
	std::vector< InstalledCheckPtr > installedchecks;
public:	
    InstalledCheckOperator();
	bool IsInstalled() const;
    void Load(TiXmlElement * node);
};

typedef shared_any<InstalledCheckOperator *, close_delete> InstalledCheckOperatorPtr;
