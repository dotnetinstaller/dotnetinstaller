#pragma once
#include "InstalledCheck.h"

class InstalledCheckFile : public InstalledCheck
{
public:
    InstalledCheckFile();
	CString filename; //percorso del file da cercare
	CString fileversion; //versione del file (se "" non viene verificata la versione ma solo la presenza del file)
	CString comparison; //tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta è minore bisogna installare altrimenti no)
public:
    void Load(TiXmlElement * l_Node, InstallerSetting& p_Setting);
	virtual bool IsInstalled();
};
