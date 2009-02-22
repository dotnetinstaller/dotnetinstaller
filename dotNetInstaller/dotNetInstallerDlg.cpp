// dotNetInstallerDlg.cpp : file di implementazione
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"

#include "InstallComponentDlg.h"
#include "ComponentSelector.h"

//user defined include
#include <tchar.h>
#include "OsIdentifier.h"
#include "ProcessorIdentifier.h"
#include "ConfigFile.h"
#include "InstallerLog.h"
#include "DniMessageBox.h"
#include "SilentInstall.h"
#include "ExtractCAB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// finestra di dialogo CdotNetInstallerDlg



CdotNetInstallerDlg::CdotNetInstallerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CdotNetInstallerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdotNetInstallerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SKIP, m_btnSkip);
	DDX_Control(pDX, IDC_INSTALL, m_btnInstall);
	DDX_Control(pDX, IDCANCEL, m_btCancel);
	DDX_Control(pDX, IDC_MESSAGE, m_lblMessage);
	DDX_Control(pDX, IDC_COMPONENTS_LIST, m_ListBoxComponents);
	DDX_Control(pDX, IDC_PICTUREBOX, m_PictureBox);
	DDX_Control(pDX, IDC_OPERATING_SYSTEM, m_lblOperatingSystem);
	DDX_Control(pDX, IDC_ADVANCED, m_btAdvanced);
	DDX_Control(pDX, IDC_INFO_LINK, m_InfoLink);
}

BEGIN_MESSAGE_MAP(CdotNetInstallerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SKIP, OnBnClickedSkip)
	ON_BN_CLICKED(IDC_INSTALL, OnBnClickedInstall)
	ON_BN_CLICKED(IDC_ADVANCED, OnBnClickedAdvanced)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// gestori di messaggi di CdotNetInstallerDlg

INT_PTR CdotNetInstallerDlg::RunDni(installerSetting & p_Settings, bool p_additional_config)
{
	// p_Settings must be "in scope" through the duration of the dialog display
	m_Settings = p_Settings;
	m_additional_config = p_additional_config;

	return this->DoModal();
}

BOOL CdotNetInstallerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Impostare l'icona per questa finestra di dialogo. Il framework non esegue questa operazione automaticamente
	//  se la finestra principale dell'applicazione non è una finestra di dialogo.
	SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
	SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.


	//remove the Run key if exist
	RemoveRegistryRun();

	//determinating operating system
    m_lblOperatingSystem.SetWindowText(DVLib::GetOsVersionString() + L" (" + DVLib::GetProcessorArchitectureString() + L")");

	// Matthew Sheets - 2008-01-14: Hide the "Skip" button if there are no additional configurations
	if (!m_additional_config)
	{
		m_btnSkip.ShowWindow(SW_HIDE);
	}

	//load xml file
	this->SetWindowText(m_Settings.dialog_caption);
	m_btCancel.SetWindowText(m_Settings.cancel_caption);
	m_btnSkip.SetWindowText(m_Settings.skip_caption);
	m_btnInstall.SetWindowText(m_Settings.install_caption);
	m_lblMessage.SetWindowText(m_Settings.dialog_message);
	m_btAdvanced.SetWindowText(m_Settings.advanced_caption);
	if (m_Settings.advanced_caption.GetLength() <= 0)
		m_btAdvanced.ShowWindow(SW_HIDE);

	m_InfoLink.SetCaption(m_Settings.dialog_otherinfo_caption);
	m_InfoLink.SetHyperlink(m_Settings.dialog_otherinfo_link);
	if (m_Settings.dialog_otherinfo_caption.GetLength() <= 0)
		m_InfoLink.ShowWindow(SW_HIDE);

	try
	{
		HBITMAP hBitmap;
		if ( m_Settings.dialog_bitmap.GetLength() > 0 &&
			DVLib::FileExistsCustom(m_Settings.dialog_bitmap) )
		{
			hBitmap = DVLib::LoadBitmapFromFile(m_Settings.dialog_bitmap);
		}
		else
		{
			//l'immagine non è inserita come risorsa tipo BITMAP perchè avevo dei problemi poi a chiamare UpdateResource
			// è quindi inserita come risorsa di tipo CUSTOM e letta manualmente
			//hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BANNER));
			hBitmap = LoadBannerFromResource(AfxGetApp()->m_hInstance);
		}

		m_PictureBox.SetBitmap(hBitmap);
	}
	catch(...)
	{
		//errore nel caricamento dell'immagine
	}

	if (LoadComponentsList())
	{
		if (m_Settings.auto_close_if_installed || QuietInstall.IsSilent())
		{
			m_Settings.ExecuteCompleteCode();
			OnOK();
		}
	}
	else
	{
		// Matthew Sheets - 2007-08-21: Initiate component install(s) silently, without end-user input
		if(QuietInstall.IsSilent())
		{
			m_btnInstall.EnableWindow(FALSE);
			m_btCancel.EnableWindow(FALSE);
			m_btAdvanced.EnableWindow(FALSE);

			m_InfoLink.EnableWindow(FALSE);

			// Run the button install click event
			OnBnClickedInstall();
		}
	}

	return TRUE;  // restituisce TRUE a meno che non venga impostato lo stato attivo su un controllo.
}

// Se si aggiunge alla finestra di dialogo un pulsante di riduzione a icona, per trascinare l'icona sarà necessario
//  il codice sottostante. Per le applicazioni MFC che utilizzano il modello documento/vista,
//  questa operazione viene eseguita automaticamente dal framework.

void CdotNetInstallerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contesto di periferica per il disegno

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrare l'icona nel rettangolo client.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Disegnare l'icona
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Il sistema chiama questa funzione per ottenere la visualizzazione del cursore durante il trascinamento
//  della finestra ridotta a icona.
HCURSOR CdotNetInstallerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CdotNetInstallerDlg::OnBnClickedInstall()
{
	try
	{
        ExtractCab();
		InsertRegistryRun();
		bool l_bRemoveRunOnce = true;

		for (size_t i = 0; i < m_Settings.components.size();i++)
		{
			bool l_retVal = false;
			try
			{
				if (m_Settings.components[i]->selected)
				{
					ApplicationLog.Write( TEXT("--Executing component :"), m_Settings.components[i]->description);

					if (m_Settings.components[i]->DownloadComponents(this) &&  //download component
						m_Settings.components[i]->Exec()) //execute component
					{
						InstallComponentDlg l_dg;
						l_dg.LoadComponent(&m_Settings, m_Settings.components[i]);
						l_dg.DoModal();
						
						if (m_Settings.components[i]->IsExecuting()) // se l'installazione è ancora attiva non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
						{
							ApplicationLog.Write( TEXT("---Component STILL ACTIVE") );

							l_bRemoveRunOnce = false;
							break; //esco dal for
						}
						else //setup finished
						{
							DWORD l_ExitCode = m_Settings.components[i]->GetExitCode();
							if (l_ExitCode == ERROR_SUCCESS || l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED)
							{
								//se è presente un messaggio di completamento installazione
								CString l_completeMsg = m_Settings.components[i]->installcompletemessage;
								if (l_completeMsg.Trim().GetLength() > 0)
									DniMessageBox(l_completeMsg, MB_OK|MB_ICONINFORMATION);

								if (m_Settings.components[i]->mustreboot ||
									l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED) //se l'installazione ha chiesto di riavviare non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
								{
									ApplicationLog.Write( TEXT("---Component NEED REBOOT") );

									l_bRemoveRunOnce = false;
									

									//chiedo di riavviare
									if (DniMessageBox(m_Settings.reboot_required, MB_YESNO|MB_ICONQUESTION, IDYES) == IDYES )
									{
										InitiateReboot();
										ApplicationLog.Write( TEXT("---Initiated REBOOT") );
										PostQuitMessage(ERROR_SUCCESS_REBOOT_REQUIRED);
										break;
									}
									else
									{
										l_retVal = true;
									}

									//break; //esco dal for
								}
								else //installazione completata con sucesso
								{
									ApplicationLog.Write( TEXT("---Component INSTALLED") );

									l_retVal = true;
								}
							}
							else //error restituito dal setup
							{
								ApplicationLog.Write( TEXT("---Component ERROR ON EXIT CODE") );

								l_retVal = false;
							}
						}
					}
					else //download non riuscito o eseguzione del setup non riuscita
					{
						ApplicationLog.Write( TEXT("---Component ERROR ON DOWNLOAD OR EXECUTING") );

						l_retVal = false;
					}
				}
				else //già installato
				{
					l_retVal = true;
				}
			}
			catch(...)
			{
				ApplicationLog.Write( TEXT("--ERROR on component"));

				l_retVal = false;
			}

			if (l_retVal == false)
			{
				CString l_msg;
				l_msg.Format( m_Settings.failed_exec_command_continue, m_Settings.components[i]->description );

				if (DniMessageBox(l_msg, MB_YESNO, IDNO, MB_YESNO|MB_ICONEXCLAMATION) == IDNO )
					break;
			}
		}

		if (l_bRemoveRunOnce)
		{
			RemoveRegistryRun();
		}
		else
		{
			ApplicationLog.Write( TEXT("--dotNetInstaller is configured to auto execute on the next boot."));
		}

		if (LoadComponentsList())
		{
			ApplicationLog.Write( TEXT("All components are installed succesfully!"));

			m_Settings.ExecuteCompleteCode();

			OnOK();
		}
		else
		{
			// Matthew Sheets - 2007-09-20
			// TODO: Need to determine how to handle a still-populated LoadComponentsList
			///   during silent installs, since components need not have install checks.
			if (QuietInstall.IsSilent())
			{
				// TODO: (see above) For now, just continue
				m_Settings.ExecuteCompleteCode();

				OnOK();
			}
		}
	}
    catch(TCHAR * error)
    {
		ApplicationLog.Write(error);
		DniSilentMessageBox(error, MB_OK | MB_ICONSTOP);
    }
	catch(...)
	{
		ApplicationLog.Write( TEXT("Failed to install one or more components"));
		DniSilentMessageBox(TEXT("Failed to install one or more components"), MB_OK|MB_ICONSTOP);
	}
}

//restituisce true se risultano installati tutti i componenti
bool CdotNetInstallerDlg::LoadComponentsList(void)
{
	m_ListBoxComponents.ResetContent();

	bool l_AllInstalled = true;
	for (size_t i = 0; i < m_Settings.components.size();i++)
	{
		if (m_Settings.components[i]->selected)
		{
			m_ListBoxComponents.AddString(m_Settings.components[i]->description);

			l_AllInstalled &= m_Settings.components[i]->IsInstalled();
		}
	}

	return l_AllInstalled;
}

void CdotNetInstallerDlg::OnBnClickedAdvanced()
{
	CComponentSelector l_dlgSlector(&m_Settings, this);
	if (l_dlgSlector.DoModal() == IDOK )
	{
		LoadComponentsList();
	}
}

// Matthew Sheets - 2008-01-14: Skip the current config section and go to the next valid one
void CdotNetInstallerDlg::OnBnClickedSkip()
{
	OnOK();
}

void CdotNetInstallerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	try
	{
		ApplicationLog.Write( TEXT("Releasing components ..."));

		for (size_t i = 0; i < m_Settings.components.size(); i++)
		{
			component * c = m_Settings.components[i];
			m_Settings.components[i] = NULL;

			FreeComponent(c);
		}
		m_Settings.components.clear();

		ApplicationLog.Write( TEXT("Components released"));

        // 2008-06-09 - Daniel Doubrovkine - delete temporary directory
        // even if a reboot is required, the temporary folder is gone; next run will re-extract components
        CString cabpath = (m_Settings.cab_path.GetLength() > 0) ? m_Settings.cab_path : DVLib::GetSessionTempPath(true);
        cabpath = m_Settings.ValidatePath(cabpath);
        if (m_Settings.cab_path_autodelete && cabpath.GetLength() && DVLib::FileExistsCustom(cabpath))
        {
		    ApplicationLog.Write(TEXT("Deleting temporary folder: ") + cabpath);
            DVLib::DeleteDirectoryDeep(cabpath);
        }
	}
    catch(TCHAR * error)
    {
		ApplicationLog.Write(error);
		DniSilentMessageBox(error, MB_OK | MB_ICONSTOP);
    }
	catch(...)
	{
		_ASSERT(false);
	}
}

void CdotNetInstallerDlg::OnBnClickedCancel()
{
	OnCancel();
}

void CdotNetInstallerDlg::ExtractCab()
{
    ExtractCABComponent e_component(m_Settings);
    installerSetting e_setting;
    e_setting.installing_component_wait = m_Settings.cab_dialog_message;
    e_component.description = m_Settings.cab_dialog_caption;
    InstallComponentDlg l_dg;
	l_dg.LoadComponent(& e_setting, & e_component);
    e_component.Init();
	l_dg.DoModal();
}
