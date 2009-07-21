#pragma once

class InstalledCheck
{
public:
    InstalledCheck();
    virtual ~InstalledCheck();
	virtual bool IsInstalled() const = 0;
    virtual void Load(TiXmlElement * node) = 0;
	static shared_any<InstalledCheck *, close_delete> Create(const std::wstring& installedcheck_type);
};

typedef shared_any<InstalledCheck *, close_delete> InstalledCheckPtr;
