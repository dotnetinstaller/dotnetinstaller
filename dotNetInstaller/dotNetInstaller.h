#pragma once
#include "Resource.h"

class CdotNetInstallerApp : public CWinApp
{
private:
	int m_rc;
	void DisplayHelp();
    void ExtractCab();
	void DisplayCab();
	void DisplayConfig();
public:
	CdotNetInstallerApp();
	BOOL InitInstance();
	int ExitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CdotNetInstallerApp theApp;
