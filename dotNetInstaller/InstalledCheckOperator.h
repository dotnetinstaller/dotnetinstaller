#pragma once
#include "InstalledCheck.h"

class InstalledCheckOperator : public InstalledCheck
{
public:
    InstalledCheckOperator();
public:
	CString type; // operator type
    CString description; // operator description
    //installed checks
	std::vector<InstalledCheck*> installedchecks;
	bool IsInstalled();
    void Load(TiXmlElement * p_Node, InstallerSetting & p_Setting);
};
