#pragma once
#include "InstallerTypes.h"
#include "InstallerSetting.h"

class InstalledCheck
{
public:
    InstalledCheck(void);
    virtual ~InstalledCheck(void);
	virtual bool IsInstalled() const = 0;
    virtual void Load(TiXmlElement * node, InstallerSetting & setting) = 0;
    static InstalledCheck * LoadFromXml(TiXmlElement * node, InstallerSetting & setting);
};
