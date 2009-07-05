// dotNetInstallerDlg.cpp : file di implementazione
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallComponentDlg.h"
#include "DniMessageBox.h"
#include "ExtractCAB.h"
#include "DownloadDialog.h"
#include "InstallSystem.h"
#include "InstallerCommandLineInfo.h"

// finestra di dialogo CdotNetInstallerDlg

CdotNetInstallerDlg::CdotNetInstallerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CdotNetInstallerDlg::IDD, pParent)
	, m_additional_config(false)
	, m_recorded_error(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdotNetInstallerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SKIP, m_btnSkip);
	DDX_Control(pDX, IDC_INSTALL, m_btnInstall);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_MESSAGE, m_lblMessage);
	DDX_Control(pDX, IDC_COMPONENTS_LIST, m_ListBoxComponents);
	DDX_Control(pDX, IDC_PICTUREBOX, m_PictureBox);
	DDX_Control(pDX, IDC_OPERATING_SYSTEM, m_lblOperatingSystem);
	DDX_Control(pDX, IDC_INFO_LINK, m_InfoLink);
}

BEGIN_MESSAGE_MAP(CdotNetInstallerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SKIP, OnBnClickedSkip)
	ON_BN_CLICKED(IDC_INSTALL, OnBnClickedInstall)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// gestori di messaggi di CdotNetInstallerDlg

INT_PTR CdotNetInstallerDlg::RunDni(InstallerSetting & p_Settings, bool p_additional_config)
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

	// remove the Run key if exist
	RemoveRegistryRun();

	// determinating operating system
    m_lblOperatingSystem.SetWindowText(DVLib::GetOsVersionString() + L" (" + DVLib::GetProcessorArchitectureString() + L")");

	// hide the "Skip" button if there are no additional configurations
	if (!m_additional_config)
	{
		m_btnSkip.ShowWindow(SW_HIDE);
	}

	// load xml file
	this->SetWindowText(m_Settings.dialog_caption);
    AfxGetApp()->m_pszAppName = _tcsdup(m_Settings.dialog_caption);

	m_btnCancel.SetWindowText(m_Settings.cancel_caption);
	m_btnSkip.SetWindowText(m_Settings.skip_caption);
	m_btnInstall.SetWindowText(m_Settings.install_caption);
	m_lblMessage.SetWindowText(m_Settings.dialog_message);

    MoveWindow(* this, m_Settings.dialog_position);
    MoveWindow(m_ListBoxComponents, m_Settings.dialog_components_list_position);
    MoveWindow(m_lblMessage, m_Settings.dialog_message_position);
    MoveWindow(m_PictureBox, m_Settings.dialog_bitmap_position);
    MoveWindow(m_InfoLink, m_Settings.dialog_otherinfo_link_position);
    MoveWindow(m_lblOperatingSystem, m_Settings.dialog_osinfo_position);
    MoveWindow(m_btnInstall, m_Settings.dialog_install_button_position);
    MoveWindow(m_btnCancel, m_Settings.dialog_cancel_button_position);
    MoveWindow(m_btnSkip, m_Settings.dialog_skip_button_position);
    
	m_InfoLink.SetCaption(m_Settings.dialog_otherinfo_caption);
	m_InfoLink.SetHyperlink(m_Settings.dialog_otherinfo_link);
	if (m_Settings.dialog_otherinfo_caption.GetLength() <= 0)
		m_InfoLink.ShowWindow(SW_HIDE);

	try
	{
		HBITMAP hBitmap;
		if ( m_Settings.dialog_bitmap.GetLength() > 0 &&
			DVLib::FileExists(m_Settings.dialog_bitmap) )
		{
			hBitmap = DVLib::LoadBitmapFromFile(m_Settings.dialog_bitmap);
		}
		else
		{
			//l'immagine non è inserita come risorsa tipo BITMAP perchè avevo dei problemi poi a chiamare UpdateResource
			// è quindi inserita come risorsa di tipo CUSTOM e letta manualmente
			//hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BANNER));
            hBitmap = DVLib::LoadBannerFromResource(AfxGetApp()->m_hInstance);
		}

		m_PictureBox.SetBitmap(hBitmap);
	}
	catch(std::exception&)
	{
		//errore nel caricamento dell'immagine
	}

    // just extract the CABs
    if (commandLineInfo.ExtractCab())
    {
        wchar_t currentDirectory[MAX_PATH];
        ::GetCurrentDirectoryW(MAX_PATH, currentDirectory);
        m_Settings.cab_path = currentDirectory;
        m_Settings.cab_path.Append(L"\\SupportFiles");
        m_Settings.cab_path_autodelete = false;
        ExtractCab();
        OnOK();
        return FALSE;
    }

	if (LoadComponentsList())
	{
		if (m_Settings.auto_close_if_installed || CurrentInstallUILevel.IsSilent())
		{
            if (m_Settings.complete_command.Trim().GetLength() 
				|| m_Settings.complete_command_silent.Trim().GetLength()
				|| m_Settings.complete_command_basic.Trim().GetLength())
            {
                ExtractCab(); // the command may need to execute a file
            }

			ExecuteCompleteCode(false);
			OnOK();
		}
	}
	else
	{
		// initiate component install(s) silently, without end-user input
		if(CurrentInstallUILevel.IsSilent())
		{
			m_btnInstall.EnableWindow(FALSE);
			m_btnCancel.EnableWindow(FALSE);
            m_InfoLink.EnableWindow(FALSE);
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

// Select components based on the list box selections.
void CdotNetInstallerDlg::SelectComponents()
{
	for(int i = 0; i < m_ListBoxComponents.GetCount(); i++)
	{
		Component * pComponent = (Component *) m_ListBoxComponents.GetItemDataPtr(i);
		pComponent->selected = (m_ListBoxComponents.GetCheck(i) == 1);
	}
}

void CdotNetInstallerDlg::OnBnClickedInstall()
{
	try
	{
		ClearError();
        SelectComponents();
        ExtractCab();
		InsertRegistryRun();
		bool l_bRemoveRunOnce = true;
		bool l_bShutdownOrCancel = false;

	    for each(Component * component in m_Settings.GetComponents())
		{
			bool l_retVal = false;
			try
			{
				if (component->selected)
				{
					ApplicationLog.Write( TEXT("--Executing component: "), component->description);

					InstallComponentDlg l_dg;
					if (CurrentInstallUILevel.IsAnyUI())
					{
						l_dg.LoadComponent(& m_Settings, component);
						component->Init(& l_dg);
					}
					else
					{
						component->Init(NULL);
					}

					if (DownloadComponents(* component) &&  //download component
						component->Exec()) //execute component
					{
						if (CurrentInstallUILevel.IsAnyUI())
						{
							l_dg.DoModal();
						}
						else
						{
							while(component->IsExecuting())
							{
								Sleep(1000);
							}
						}

						ApplicationLog.Write( TEXT("---Component DIALOG CLOSED") );
						
						if (component->IsExecuting()) // se l'installazione è ancora attiva non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
						{
							ApplicationLog.Write( TEXT("---Component STILL ACTIVE") );

							l_bRemoveRunOnce = false;
							break; //esco dal for
						}
						else //setup finished
						{
							DWORD l_ExitCode = component->GetExitCode();
							if (l_ExitCode == ERROR_SUCCESS || l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED)
							{
								ApplicationLog.Write( TEXT("---Component SUCCEEDED") );

								//se è presente un messaggio di completamento installazione
								CString l_completeMsg = component->installcompletemessage;
								if (l_completeMsg.Trim().GetLength() > 0)
									DniMessageBox(l_completeMsg, MB_OK|MB_ICONINFORMATION);

								if (component->mustreboot ||
									l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED) //se l'installazione ha chiesto di riavviare non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
								{
									ApplicationLog.Write( TEXT("---Component NEED REBOOT") );

									l_bRemoveRunOnce = false;

                                    bool l_bReboot = false;
                                    CString reboot_required = component->reboot_required;
                                    if (reboot_required.IsEmpty()) reboot_required = m_Settings.reboot_required;
                                    if (m_Settings.must_reboot_required || component->must_reboot_required)
                                    {
										ApplicationLog.Write( TEXT("---Required REBOOT") );
                                        DniMessageBox(reboot_required, MB_OK|MB_ICONQUESTION);
                                        l_bReboot = true;
                                    }
                                    else 
                                    {
										ApplicationLog.Write( TEXT("---Prompt for REBOOT") );
                                        l_bReboot = (DniMessageBox(reboot_required, MB_YESNO|MB_ICONQUESTION, IDYES) == IDYES);
                                    }

									if (l_bReboot)
									{
										InitiateReboot();
										l_bShutdownOrCancel = true;
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
                                ApplicationLog.Write( TEXT("***Component ERROR ON EXIT CODE: "), DVLib::towstring(l_ExitCode).c_str());
								RecordError(l_ExitCode);
								l_retVal = false;
							}
						}
					}
					else //download non riuscito o eseguzione del setup non riuscita
					{
						ApplicationLog.Write( TEXT("***Component ERROR ON DOWNLOAD OR EXECUTING") );
						RecordError();
						l_retVal = false;
					}
				}
				else //già installato
				{
					l_retVal = true;
				}
			}
			catch(std::exception& ex)
			{
                ApplicationLog.Write( TEXT("***ERROR on component: "), DVLib::string2wstring(ex.what()).c_str());
				RecordError();
				l_retVal = false;
			}

			if (l_retVal == false)
			{
                // the component failed to install, display an error message and let the user choose to continue or not
                // unless global or component setting decides otherwise

                CString failed_exec_command_continue = component->failed_exec_command_continue;
                if (failed_exec_command_continue.IsEmpty()) failed_exec_command_continue = m_Settings.failed_exec_command_continue;
				CString l_msg;
				l_msg.Format( failed_exec_command_continue, component->description );

                bool l_breakSequence = false;
                if (m_Settings.allow_continue_on_error && component->allow_continue_on_error)
                {
				    l_breakSequence = (DniMessageBox(l_msg, MB_YESNO, IDNO, MB_YESNO|MB_ICONEXCLAMATION) == IDNO);
                }
                else
                {
                    DniMessageBox(l_msg, MB_OK, 0, MB_ICONEXCLAMATION);
                    l_breakSequence = true;
                }

                if (l_breakSequence)
                {
                    if (m_Settings.auto_close_on_error)
                    {
                        l_bShutdownOrCancel = true;
                    }
                    
                    break;
                }
			}
		}

		if (l_bRemoveRunOnce)
		{
			RemoveRegistryRun();
		}
		else
		{
			ApplicationLog.Write( TEXT("--dotNetInstaller is configured to auto execute on the next boot"));
		}

		if (l_bShutdownOrCancel)
		{
			OnOK();
		}
		else
		{
			if (LoadComponentsList())
			{
				ExecuteCompleteCode(true);
				OnOK();
			}
			else if (CurrentInstallUILevel.IsSilent())
			{
				OnOK();
			}
		}

    }
    catch(std::exception& ex)
    {
		ApplicationLog.Write(TEXT("***"), DVLib::string2wstring(ex.what()).c_str());
		DniSilentMessageBox(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
		RecordError();
    }
	catch(...)
	{
		ApplicationLog.Write( TEXT("***Failed to install one or more components"));
		DniSilentMessageBox(TEXT("Failed to install one or more components"), MB_OK|MB_ICONSTOP);
		RecordError();
	}
}

// returns true if all required components have been properly installed
bool CdotNetInstallerDlg::LoadComponentsList(void)
{
	m_ListBoxComponents.ResetContent();

	int hScrollWidth = 0;
	CDC *pDC = m_ListBoxComponents.GetDC();
	ASSERT(pDC);

	bool l_AllInstalled = true;
    for each(Component * component in m_Settings.GetComponents())
	{
        bool component_installed = component->IsInstalled();
        
        ApplicationLog.Write( TEXT("-- ") + component->description + TEXT(": "), 
            component_installed ? TEXT("INSTALLED") : TEXT("NOT INSTALLED"));

		if (component_installed)
		{
			component->selected = false;
		}

        if (component->required)
        {
            l_AllInstalled &= component_installed;
        }

		CString l_descr = component->description;
	    l_descr += " ";
        l_descr += component_installed
			? (component->status_installed.IsEmpty() ? m_Settings.status_installed : component->status_installed)
			: (component->status_notinstalled.IsEmpty() ? m_Settings.status_notinstalled : component->status_notinstalled);

        if (! m_Settings.dialog_show_installed && component_installed)
            continue;

        if (! m_Settings.dialog_show_required && component->required)
            continue;

		int id = m_ListBoxComponents.AddString(l_descr);
		m_ListBoxComponents.SetItemDataPtr(id, component);

        if (component->selected)
        {
			m_ListBoxComponents.SetCheck(id, 1);
        }

        // a component is considered installed when it has an install check which results
        // in a clear positive; if a component doesn't have any install checks, it cannot
        // be required (there's no way to check whether the component was installed)
        if (component->required || component_installed)
        {
            m_ListBoxComponents.Enable(id, 0);
        }

		CSize size = pDC->GetTextExtent(component->description);
		if ((size.cx > 0) && (hScrollWidth < size.cx))
			hScrollWidth = size.cx;
    }

	if (hScrollWidth > 0 )
		m_ListBoxComponents.SetHorizontalExtent(hScrollWidth);

	m_ListBoxComponents.ReleaseDC(pDC); 

	return l_AllInstalled;
}

// skip the current config section and go to the next valid one
void CdotNetInstallerDlg::OnBnClickedSkip()
{
	OnOK();
}

void CdotNetInstallerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	try
	{
		ApplicationLog.Write( TEXT("Releasing components"));

        m_Settings.ClearComponents();

		ApplicationLog.Write( TEXT("Components released"));

        // delete temporary directory
        // even if a reboot is required, the temporary folder is gone; next run will re-extract components
        CString cabpath = (m_Settings.cab_path.GetLength() > 0) ? m_Settings.cab_path : DVLib::GetSessionTempPath(true);
        cabpath = m_Settings.ValidatePath(cabpath);
        if (m_Settings.cab_path_autodelete && cabpath.GetLength() && DVLib::FileExists(cabpath))
        {
		    ApplicationLog.Write(TEXT("Deleting temporary folder: ") + cabpath);
            DVLib::DeleteDirectoryDeep(cabpath);
        }

		ApplicationLog.Write( TEXT("dotNetInstaller finished"));
	}
    catch(std::exception& ex)
    {
		ApplicationLog.Write(DVLib::string2wstring(ex.what()).c_str());
		DniSilentMessageBox(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
    }
	catch(...)
	{
		_ASSERT(false);
	}
}

void CdotNetInstallerDlg::OnBnClickedCancel()
{
	RecordError(-2);
	OnCancel();
}

void CdotNetInstallerDlg::ExtractCab()
{
	if (ExtractCABComponent::GetCabCount(AfxGetApp()->m_hInstance) == 0)
		return;

    ExtractCABComponent e_component(m_Settings);
    InstallerSetting e_setting;
    e_setting.installing_component_wait = m_Settings.cab_dialog_message;
    e_component.description = m_Settings.cab_dialog_caption;
    InstallComponentDlg l_dg;
	if (CurrentInstallUILevel.IsAnyUI())
	{
		l_dg.LoadComponent(& e_setting, & e_component);
		e_component.Init(& l_dg);
		l_dg.DoModal();
	}
	else
	{
		e_component.Init(NULL);
	}
    e_component.Exec();
}

// the pos rectangle is the top left point, width and height, not l/r/t/b
bool CdotNetInstallerDlg::MoveWindow(CWnd& dlg, const WidgetPosition& pos)
{   
    // an empty rectangle is ignored
	if (! pos.IsSet()) 
		return false;

    WINDOWPLACEMENT wpc;
    dlg.GetWindowPlacement(& wpc);

    if (pos.Left() != 0) wpc.rcNormalPosition.left = pos.Left();
    if (pos.Width() != 0) wpc.rcNormalPosition.right = wpc.rcNormalPosition.left + pos.Width();
    if (pos.Top() != 0) wpc.rcNormalPosition.top = pos.Top();
    if (pos.Height() != 0) wpc.rcNormalPosition.bottom = wpc.rcNormalPosition.top + pos.Height();

    // move the window to a combination of old and new coordinates
    dlg.SetWindowPlacement(& wpc);
    return true;
}

void CdotNetInstallerDlg::RecordError(int error) 
{ 
	if (m_recorded_error == 0) 
	{
		m_recorded_error = error; 
	}
}

void CdotNetInstallerDlg::ClearError() 
{ 
	m_recorded_error = 0; 
}

bool CdotNetInstallerDlg::RunDownloadConfiguration(DownloadGroupConfiguration & p_Configuration)
{
	DownloadDialog l_dgDownload(p_Configuration, this);
	
	if (l_dgDownload.IsCopyRequired())
	{
		l_dgDownload.CopyFromSourcePath();
		return true;
	}

	if (l_dgDownload.IsDownloadRequired())
	{
		l_dgDownload.DoModal();
		return l_dgDownload.IsDownloadCompleted();
	}

	return true;
}

bool CdotNetInstallerDlg::DownloadComponents(Component& p_Component)
{
	try
	{
		if (p_Component.download)
        {
			return RunDownloadConfiguration(p_Component.DownloadDialogConfiguration);
        }
		else
        {
			return true;
        }
	}
	catch(std::exception&)
	{
		return false;
	}
}

void CdotNetInstallerDlg::ExecuteCompleteCode(bool componentsInstalled)
{
	ApplicationLog.Write(TEXT("--Complete Command"));

    CString message = m_Settings.installation_completed;
	// installation completed, but no components have been installed
	if (! componentsInstalled && m_Settings.installation_none.GetLength())
	{
		message = m_Settings.installation_none;
	}

	if (message.Trim().GetLength() > 0)
    {
		DniMessageBox(message, MB_OK|MB_ICONINFORMATION);
    }

	CString l_complete_command = m_Settings.complete_command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (m_Settings.complete_command_silent.GetLength()) l_complete_command = m_Settings.complete_command_silent;
		else if (m_Settings.complete_command_basic.GetLength()) l_complete_command = m_Settings.complete_command_basic;
		break;
	case InstallUILevelBasic:
		if (m_Settings.complete_command_basic.GetLength()) l_complete_command = m_Settings.complete_command_basic;
		else if (m_Settings.complete_command_silent.GetLength()) l_complete_command = m_Settings.complete_command_silent;
		break;
	}

    if (commandLineInfo.GetCompleteCommandArgs().GetLength())
    {
        l_complete_command.Append(L" ");
        l_complete_command.Append(commandLineInfo.GetCompleteCommandArgs());
    }

	if (l_complete_command.Trim().GetLength())
	{
		ApplicationLog.Write( TEXT("Executing complete command: "), l_complete_command);
        DWORD dwExitCode = 0;
        dwExitCode = DVLib::ExecCmd((LPCWSTR) l_complete_command);
	}
}
