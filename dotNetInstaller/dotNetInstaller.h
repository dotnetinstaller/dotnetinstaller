// dotNetInstaller.h : file di intestazione principale per l'applicazione PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error: inclusione di "stdafx.h" prima dell'inclusione di questo file per PCH
#endif

#include "resource.h"		// simboli principali


// CdotNetInstallerApp:
// Per l'implementazione di questa classe, vedere dotNetInstaller.cpp.
//

class CdotNetInstallerApp : public CWinApp
{
public:
	CdotNetInstallerApp();

// Sostituzioni
	public:
	virtual BOOL InitInstance();

// Implementazione

	DECLARE_MESSAGE_MAP()
};

extern CdotNetInstallerApp theApp;
