#pragma once

class InstalledCheck
{
public:
    InstalledCheck();
    virtual ~InstalledCheck();
	virtual bool IsInstalled() const = 0;
    virtual void Load(TiXmlElement * node) = 0;
};

typedef shared_any<InstalledCheck *, close_delete> InstalledCheckPtr;
