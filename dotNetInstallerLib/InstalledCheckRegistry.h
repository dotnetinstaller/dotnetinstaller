#pragma once

#include "XmlAttribute.h"
#include "InstalledCheck.h"

class InstalledCheckRegistry : public InstalledCheck
{
public:
	// percorso del registry
	XmlAttribute path; 
	// nome del campo del registry
	XmlAttribute fieldname; 
	// valore del registry bisogna convertirlo in base al tipo
	XmlAttribute fieldvalue;
	// tipo del campo nel registry : REG_DWORD (long) o REG_SZ (string)
	XmlAttribute fieldtype; 
	// tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta è minore bisogna installare altrimenti no)
	XmlAttribute comparison;
	XmlAttribute rootkey;
	// support for KEY_WOW64_32KEY and KEY_WOW64_64KEY
	XmlAttribute wowoption; 
	// default value when the registry key is not found
	XmlAttribute defaultvalue;
public:
    InstalledCheckRegistry();
    void Load(TiXmlElement * node);
	bool IsInstalled() const;
private:
	DWORD GetKeyOption() const;
	std::wstring GetKeyPath() const;
	bool IsInstalledExists() const;
	bool IsInstalledValue() const;
	bool IsInstalledKeyExists() const;
	bool IsInstalledValueExists() const;
};

typedef shared_any<InstalledCheckRegistry *, close_delete> InstalledCheckRegistryPtr;
