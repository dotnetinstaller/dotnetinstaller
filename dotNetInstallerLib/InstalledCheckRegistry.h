#pragma once
#include "InstalledCheck.h"

class InstalledCheckRegistry : public InstalledCheck
{
public:
	// percorso del registry
	std::wstring path; 
	// nome del campo del registry
	std::wstring fieldname; 
	// valore del registry bisogna convertirlo in base al tipo
	std::wstring fieldvalue;
	// tipo del campo nel registry : REG_DWORD (long) o REG_SZ (string)
	std::wstring fieldtype; 
	// tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta è minore bisogna installare altrimenti no)
	std::wstring comparison;
	std::wstring rootkey;
	//support for KEY_WOW64_32KEY and KEY_WOW64_64KEY
	std::wstring wowoption; 
public:
    InstalledCheckRegistry();
    void Load(TiXmlElement * node, Configuration& setting);
	bool IsInstalled() const;
};
