#pragma once

#include "resource.h"

class CHtmlInstallerApp : public CWinApp
{
private:
	int m_rc;
	void DisplayHelp();
    void ExtractAllCabs();
	void ExtractCab(const std::wstring& id);
	void DisplayCab();
	void DisplayConfig();
public:
	CHtmlInstallerApp();
	BOOL InitInstance();
	int ExitInstance();
	BOOL PreTranslateMessage(MSG *);
	DECLARE_MESSAGE_MAP()
};

extern CHtmlInstallerApp theApp;
