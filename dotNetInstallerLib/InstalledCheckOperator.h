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
    std::vector<InstalledCheck *> installed_checks;
public:	
    InstalledCheckOperator();
	bool IsInstalled() const;
    void Load(TiXmlElement * node, InstallerSetting & setting);
};
