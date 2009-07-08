// dotNetInstaller.cpp : definisce i comportamenti delle classi per l'applicazione.
//

#include "stdafx.h"
#include "ConfigFile.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallerCommandLineInfo.h"
#include "DniMessageBox.h"
#include <Version/Version.h>

// CdotNetInstallerApp

BEGIN_MESSAGE_MAP(CdotNetInstallerApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// costruzione di CdotNetInstallerApp

CdotNetInstallerApp::CdotNetInstallerApp()
	: m_rc(0)
{
	// Inserire l'inizializzazione significativa in InitInstance.
}


// L'unico e solo oggetto CdotNetInstallerApp

CdotNetInstallerApp theApp;


// Inizializzazione di CdotNetInstallerApp

BOOL CdotNetInstallerApp::InitInstance()
{
	// InitCommonControls() è necessario in Windows XP se nel manifesto
	// di un'applicazione è specificato l'utilizzo di ComCtl32.dll versione 6 o successiva per attivare
	// gli stili visuali. In caso contrario, non sarà possibile creare finestre.
	InitCommonControls();

	CWinApp::InitInstance();

	//AfxEnableControlContainer();

	try
	{
		ParseCommandLine(commandLineInfo);

		LOG(L"-------------------------------------------------------------------");
		LOG(L"dotNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
		LOG(VERSION_LEGALCOPYRIGHT_VALUE);
		LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString());
		LOG(L"-------------------------------------------------------------------");

		std::map<std::wstring, std::wstring>::iterator arg = commandLineInfo.m_componentCmdArgs.begin();
		while(arg != commandLineInfo.m_componentCmdArgs.end())
		{
			LOG(L"Component arguments: \"" + arg->first + L"\": " << arg->second);
			arg ++;
		}

        ConfigFile config;
        m_rc = config.Load();
	}
	catch(std::exception& ex)
	{
        DniSilentMessageBox(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		m_rc = -1;
		return false;
	}
	catch(...)
	{
		DniSilentMessageBox(TEXT("Error loading configuration file"), MB_OK|MB_ICONSTOP);
		m_rc = -1;
		return false;
	}


	// Poiché la finestra di dialogo è stata chiusa, restituisce FALSE in modo che l'applicazione
	//  venga terminata, anziché avviare la message pump dell'applicazione.
	return FALSE;
}

int CdotNetInstallerApp::ExitInstance() 
{
	// ignore the MFC return code, which is typically the last key pressed
	CWinApp::ExitInstance();
	return m_rc;
}