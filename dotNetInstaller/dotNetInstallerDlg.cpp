// dotNetInstallerDlg.cpp : file di implementazione
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include ".\dotnetinstallerdlg.h"

#include "InstallComponentDlg.h"
#include "ComponentSelector.h"

//user defined include
#include <tchar.h>
#include "OsIdentifier.h"
#include "ConfigFile.h"
#include "InstallerLog.h"

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
	ON_BN_CLICKED(IDC_INSTALL, OnBnClickedInstall)
	ON_BN_CLICKED(IDC_ADVANCED, OnBnClickedAdvanced)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// gestori di messaggi di CdotNetInstallerDlg

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
	m_lblOperatingSystem.SetWindowText(DVLib::GetOsVersionString());

	//load xml file
	if (LoadXmlSettings() == false)
	{
		AfxMessageBox(TEXT("Failed to read configuration file."), MB_OK|MB_ICONSTOP);
		PostQuitMessage(-1);
	}
	else
	{
		// Matthias Jentsch - 2006-03-06: Checking operating system version ...
		if (DVLib::IsInRangedOs(DVLib::GetOsVersion(), m_Settings.os_filter_greater, m_Settings.os_filter_smaller) == false)
		{
			// Matthias Jentsch - 2006-03-06: This setup can't run on the current operating system
			AfxMessageBox(m_Settings.os_filter_not_match_message, MB_OK|MB_ICONSTOP);
			PostQuitMessage(-1);
		}
		else	// Matthias Jentsch - 2006-03-06: Checking of operating system version passed!
		{
			this->SetWindowText(m_Settings.dialog_caption);
			m_btCancel.SetWindowText(m_Settings.cancel_caption);
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
				if (m_Settings.auto_close_if_installed)
				{
					m_Settings.ExecuteCompleteCode();
					PostQuitMessage(0);
				}
			}
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

//returns true if the functions sucessfully load the setting m_Setting
bool CdotNetInstallerDlg::LoadXmlSettings(void)
{
	try
	{
		//riferimento standard
		CString l_SettingFile = DVLib::PathCombineCustom(DVLib::GetAppPath(), TEXT("configuration.xml"));

		if (DVLib::FileExistsCustom(l_SettingFile))
		{
			ApplicationLog.Write(TEXT("Loading configuration from file: "), l_SettingFile);

			LoadConfigFile(l_SettingFile, m_Settings, this); //riferimento
		}
		else
		{
			ApplicationLog.Write(TEXT("Loading configuration from resource."));

			LoadConfigFromResource(AfxGetApp()->m_hInstance, m_Settings, this);
		}

		return true;
	}
	catch(TCHAR * p_Message)
	{
		AfxMessageBox(p_Message, MB_OK|MB_ICONSTOP);
		return false;
	}
	catch(...)
	{
		AfxMessageBox(TEXT("Error loading configuration file"), MB_OK|MB_ICONSTOP);
		return false;
	}
}

void CdotNetInstallerDlg::OnBnClickedInstall()
{
	try
	{
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
									AfxMessageBox(l_completeMsg, MB_OK|MB_ICONINFORMATION);

								if (m_Settings.components[i]->mustreboot ||
									l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED) //se l'installazione ha chiesto di riavviare non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
								{
									ApplicationLog.Write( TEXT("---Component NEED REBOOT") );

									l_bRemoveRunOnce = false;
									

									//chiedo di riavviare
									if (AfxMessageBox(m_Settings.reboot_required, MB_YESNO|MB_ICONQUESTION) == IDYES )
									{
										InitiateReboot();
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

				if (AfxMessageBox(l_msg,MB_YESNO, MB_YESNO|MB_ICONEXCLAMATION) == IDNO )
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
	}
	catch(...)
	{
		AfxMessageBox(TEXT("Failed to install one or more components"), MB_OK|MB_ICONSTOP);
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
