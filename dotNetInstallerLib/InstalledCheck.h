#pragma once
#include "InstallerTypes.h"
#include "InstallerSetting.h"

class InstalledCheck
{
public:
    InstalledCheck(void);
    virtual ~InstalledCheck(void);
	virtual bool IsInstalled() = 0;
    virtual void Load(TiXmlElement * l_Node, InstallerSetting & p_Setting) = 0;
    static InstalledCheck * LoadFromXml(TiXmlElement * l_Node, InstallerSetting & p_Setting);
};
