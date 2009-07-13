#pragma once
#include "InstalledCheck.h"

class InstalledCheckFile : public InstalledCheck
{
public:
	// percorso del file da cercare
	std::wstring filename;
	// versione del file (se "" non viene verificata la versione ma solo la presenza del file)
	std::wstring fileversion; 
	// tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta è minore bisogna installare altrimenti no)
	std::wstring comparison; 
public:
    InstalledCheckFile();
    void Load(TiXmlElement * node);
	virtual bool IsInstalled() const;
};
