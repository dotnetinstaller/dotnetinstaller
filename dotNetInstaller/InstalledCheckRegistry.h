#pragma once
#include "InstalledCheck.h"

class InstalledCheckRegistry : public InstalledCheck
{
public:
    InstalledCheckRegistry();
public:
	CString path; //percorso del registry
	CString fieldname; //nome del campo del registry
	CString fieldvalue; //valore del registry bisogna convertirlo in base al tipo
	CString fieldtype; //tipo del campo nel registry : REG_DWORD (long) o REG_SZ  (string)
	CString comparison; //tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta è minore bisogna installare altrimenti no)
	CString rootkey;
	CString wowoption; //support for KEY_WOW64_32KEY and KEY_WOW64_64KEY						
public:
	HKEY GetRootKey() const;
    void Load(TiXmlElement * l_Node, InstallerSetting& p_Setting);
	bool IsInstalled();
};

