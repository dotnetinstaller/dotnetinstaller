// dotNetInstaller.cpp : definisce i comportamenti delle classi per l'applicazione.
//

#include "stdafx.h"
#include "ConfigFile.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallerCommandLineInfo.h"
#include <Version/Version.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdotNetInstallerApp

BEGIN_MESSAGE_MAP(CdotNetInstallerApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// costruzione di CdotNetInstallerApp

CdotNetInstallerApp::CdotNetInstallerApp()
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

	ParseCommandLine(commandLineInfo);

    ApplicationLog.Write(TEXT("-------------------------------------------------------------------"));
    ApplicationLog.Write(TEXT("dotNetInstaller (DNI) started, version "), TEXT(VERSION_VALUE));
    ApplicationLog.Write(TEXT(VERSION_LEGALCOPYRIGHT_VALUE));
    ApplicationLog.Write(TEXT("Operating system: "), DVLib::GetOsVersionString());
    ApplicationLog.Write(TEXT("-------------------------------------------------------------------"));

    std::map<std::wstring, std::wstring>::iterator arg = commandLineInfo.m_componentCmdArgs.begin();
    while(arg != commandLineInfo.m_componentCmdArgs.end())
    {
        ApplicationLog.Write((TEXT("Component arguments: \"") + arg->first + TEXT("\": ")).c_str(), arg->second.c_str());
        arg ++;
    }

	TiXmlDocument m_Document;
	InstallerSetting m_Setting;

	try
	{
		//load xml file
		bool l_bLoadSuccess = LoadXmlSettings(m_Document);

		if (l_bLoadSuccess)
		{
			// Process xml file ("additional config" parameter needs defaulted to false)
			LoadConfigsNode(m_Document.FirstChildElement(), m_Setting, false);
		}
		else
		{
			DniSilentMessageBox(TEXT("Failed to read configuration file."), MB_OK|MB_ICONSTOP);
			PostQuitMessage(-1);
		}

		return l_bLoadSuccess;
	}
	catch(std::exception& ex)
	{
        DniSilentMessageBox(DVLib::string2Tstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		return false;
	}
	catch(...)
	{
		DniSilentMessageBox(TEXT("Error loading configuration file"), MB_OK|MB_ICONSTOP);
		return false;
	}


	// Poiché la finestra di dialogo è stata chiusa, restituisce FALSE in modo che l'applicazione
	//  venga terminata, anziché avviare la message pump dell'applicazione.
	return FALSE;
}
