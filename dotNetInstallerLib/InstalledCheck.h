#pragma once
#include "InstallerTypes.h"
#include "Configuration.h"

class InstalledCheck
{
public:
    InstalledCheck(void);
    virtual ~InstalledCheck(void);
	virtual bool IsInstalled() const = 0;
    virtual void Load(TiXmlElement * node, Configuration & setting) = 0;
    static InstalledCheck * LoadFromXml(TiXmlElement * node, Configuration & setting);
};
