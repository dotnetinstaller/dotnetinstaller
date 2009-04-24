#pragma once

#ifndef __AFXWIN_H__
	#error: inclusione di "stdafx.h" prima dell'inclusione di questo file per PCH
#endif

#include "resource.h"		// simboli principali

class CdotNetInstallerApp : public CWinApp
{
private:
	int m_rc;
public:
	CdotNetInstallerApp();
	BOOL InitInstance();
	int ExitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CdotNetInstallerApp theApp;
