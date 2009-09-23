// dotNetInstallerDlg.cpp : file di implementazione
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallComponentDlg.h"
#include "ExtractCabDlg.h"
#include "DniMessageBox.h"
#include "ExtractCabProcessor.h"
#include "DownloadDialog.h"
#include "InstallerCommandLineInfo.h"
#include <Version/Version.h>

// finestra di dialogo CdotNetInstallerDlg

CdotNetInstallerDlg::CdotNetInstallerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CdotNetInstallerDlg::IDD, pParent)
	, m_additional_config(false)
	, m_recorded_error(0)
	, m_reboot(false)
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

bool CdotNetInstallerDlg::RunInstallConfiguration(
	DVLib::LcidType lcidtype, 
	const ConfigurationPtr& configuration, 
	bool p_additional_config)
{
	m_configuration = configuration;
	m_lcidtype = lcidtype;
	m_additional_config = p_additional_config;
	return(IDOK == this->DoModal());
}

BOOL CdotNetInstallerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Impostare l'icona per questa finestra di dialogo. Il framework non esegue questa operazione automaticamente
	//  se la finestra principale dell'applicazione non è una finestra di dialogo.
	SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
	SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.

	// remove the Run key if exist
	InstallerSession::Instance->DisableRunOnReboot();

	// determinating operating system
    m_lblOperatingSystem.SetWindowText(
		(DVLib::GetOperatingSystemVersionString() + L" (" + 
		DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L")").c_str());

	// hide the "Skip" button if there are no additional configurations
	if (!m_additional_config)
	{
		m_btnSkip.ShowWindow(SW_HIDE);
	}

	// load xml file
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
	this->SetWindowText(p_configuration->dialog_caption.c_str());
    AfxGetApp()->m_pszAppName = _tcsdup(p_configuration->dialog_caption.c_str());

	m_btnCancel.SetWindowText(p_configuration->cancel_caption.c_str());
	m_btnSkip.SetWindowText(p_configuration->skip_caption.c_str());
	m_btnInstall.SetWindowText(p_configuration->install_caption.c_str());
	m_lblMessage.SetWindowText(p_configuration->dialog_message.c_str());

    MoveWindow(* this, p_configuration->dialog_position);
    MoveWindow(m_ListBoxComponents, p_configuration->dialog_components_list_position);
    MoveWindow(m_lblMessage, p_configuration->dialog_message_position);
    MoveWindow(m_PictureBox, p_configuration->dialog_bitmap_position);
    MoveWindow(m_InfoLink, p_configuration->dialog_otherinfo_link_position);
    MoveWindow(m_lblOperatingSystem, p_configuration->dialog_osinfo_position);
    MoveWindow(m_btnInstall, p_configuration->dialog_install_button_position);
    MoveWindow(m_btnCancel, p_configuration->dialog_cancel_button_position);
    MoveWindow(m_btnSkip, p_configuration->dialog_skip_button_position);
    
	m_InfoLink.SetCaption(p_configuration->dialog_otherinfo_caption);
	m_InfoLink.SetHyperlink(p_configuration->dialog_otherinfo_link);
	if (p_configuration->dialog_otherinfo_caption.empty())
		m_InfoLink.ShowWindow(SW_HIDE);

	if (! p_configuration->dialog_bitmap.empty() && DVLib::FileExists(p_configuration->dialog_bitmap))
	{
		m_PictureBox.SetBitmap(DVLib::LoadBitmapFromFile(p_configuration->dialog_bitmap));
	}
	else if (DVLib::ResourceExists(AfxGetApp()->m_hInstance, L"RES_BANNER", L"CUSTOM"))
	{
		m_PictureBox.SetBitmap(DVLib::LoadBitmapFromResource(AfxGetApp()->m_hInstance, L"RES_BANNER", L"CUSTOM"));
	}

	bool all_components_installed = LoadComponentsList();
	if (all_components_installed)
	{
		if (p_configuration->auto_close_if_installed || InstallUILevelSetting::Instance->IsSilent())
		{
            if (! p_configuration->complete_command.empty()
				|| ! p_configuration->complete_command_silent.empty()
				|| ! p_configuration->complete_command_basic.empty())
            {
                ExtractCab(); // the command may need to execute a file
            }

			ExecuteCompleteCode(false);
			OnOK();
		}
	}
	else
	{
		if (AutoStart(p_configuration))
		{
			m_btnInstall.EnableWindow(FALSE);
			m_btnCancel.EnableWindow(FALSE);
            m_InfoLink.EnableWindow(FALSE);
			OnBnClickedInstall();
		}
	}

	return TRUE;  // restituisce TRUE a meno che non venga impostato lo stato attivo su un controllo.
}

// initiate component install(s) without end-user input
bool CdotNetInstallerDlg::AutoStart(InstallConfiguration * p_configuration)
{
	bool autostart = false;

	if (InstallUILevelSetting::Instance->IsSilent())
	{
		autostart = true;
		LOG(L"Silent mode: automatically starting install");
	}

	if (InstallerCommandLineInfo::Instance->Reboot())
	{
		if (p_configuration->auto_continue_on_reboot)
		{
			autostart = true;
			LOG(L"Reboot defines auto-start: automatically starting install");
		}
	}
	else if (p_configuration->auto_start)
	{
		autostart = true;
		LOG(L"Configuration defines auto-start: automatically starting install");
	}

	return autostart;
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
		
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		Components components = p_configuration->GetSupportedComponents(m_lcidtype);
		int rc = components.Exec(this);

		if (rc != 0)
		{
			RecordError(rc);
		}

		if (m_reboot)
		{
			InstallerSession::Instance->EnableRunOnReboot(p_configuration->reboot_cmd);
			DVLib::ExitWindowsSystem(EWX_REBOOT);
			PostQuitMessage(ERROR_SUCCESS_REBOOT_REQUIRED);
			return;
		}

		// silent execution, 
		if (InstallUILevelSetting::Instance->IsSilent()) 
		{
			OnOK();
			return;
		}

		// failure and auto-close-on-error
		if (rc != 0 && p_configuration->auto_close_on_error)
		{
			OnOK();
			return;
		}

		// success and possibly auto-close with a complete code if all components have been installed
		if (rc == 0)
		{
			bool all_components_installed = LoadComponentsList();
			if (all_components_installed || p_configuration->auto_close_if_installed) 
			{
				ExecuteCompleteCode(true);
				OnOK();
			}
		}
    }
    catch(std::exception& ex)
    {
		LOG(L"*** Failed to install one or more components: " << DVLib::string2wstring(ex.what()));
		DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
		RecordError();
    }
	catch(...)
	{
		LOG(L"*** Failed to install one or more components");
		DniMessageBox::Show(TEXT("Failed to install one or more components"), MB_OK|MB_ICONSTOP);
		RecordError();
	}
}

// returns true if all components have been installed
bool CdotNetInstallerDlg::LoadComponentsList()
{
	return m_ListBoxComponents.Load(m_lcidtype, m_configuration);
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
        // delete temporary directory
        // even if a reboot is required, the temporary folder is gone; next run will re-extract components
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
        std::wstring cabpath = (! p_configuration->cab_path.empty()) ? p_configuration->cab_path : InstallerSession::Instance->GetSessionTempPath(true);
		cabpath = InstallerSession::Instance->ExpandVariables(cabpath);
		if (p_configuration->cab_path_autodelete && ! cabpath.empty() && DVLib::DirectoryExists(cabpath))
        {
		    LOG(L"Deleting temporary folder: " << cabpath);
			DVLib::DirectoryDelete(cabpath);
        }

		LOG(L"dotNetInstaller finished");
	}
    catch(std::exception& ex)
    {
		LOG("Error terminating dotNetInstaller: " << DVLib::string2wstring(ex.what()));
		DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
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
    ExtractCabDlg dlg;

	ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, & dlg));	
	if (p_extractcab->GetCabCount() == 0)
		return;

	if (InstallUILevelSetting::Instance->IsAnyUI())
		dlg.LoadComponent(m_configuration, p_extractcab);

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	p_extractcab->cab_path = p_configuration->cab_path;
	p_extractcab->cab_cancelled_message = p_configuration->cab_cancelled_message;
	p_extractcab->BeginExec();

	if (InstallUILevelSetting::Instance->IsAnyUI())
		dlg.DoModal();

	p_extractcab->EndExec();
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

bool CdotNetInstallerDlg::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
	CDownloadDialog downloaddlg(p_Configuration, this);
	downloaddlg.DoModal();
	return downloaddlg.IsDownloadCompleted();
}

bool CdotNetInstallerDlg::RunComponentDownload(const ComponentPtr& p_Component)
{
	if (get(p_Component->downloaddialog))
    {
		return RunDownloadConfiguration(p_Component->downloaddialog);
    }

	return true;
}

void CdotNetInstallerDlg::ExecuteCompleteCode(bool componentsInstalled)
{
	LOG(L"--- Complete Command");

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
    std::wstring message = p_configuration->installation_completed;
	// installation completed, but no components have been installed
	if (! componentsInstalled && ! p_configuration->installation_none.empty())
	{
		message = p_configuration->installation_none;
	}

	if (! message.empty())
    {
		DniMessageBox::Show(message, MB_OK|MB_ICONINFORMATION);
    }

	std::wstring l_complete_command = InstallUILevelSetting::Instance->GetCommand(
		p_configuration->complete_command,
		p_configuration->complete_command_basic,
		p_configuration->complete_command_silent);

    if (! InstallerCommandLineInfo::Instance->GetCompleteCommandArgs().empty())
    {
        l_complete_command.append(L" ");
        l_complete_command.append(InstallerCommandLineInfo::Instance->GetCompleteCommandArgs());
    }

	if (! l_complete_command.empty())
	{
		DWORD dwExitCode = 0;
		if (p_configuration->wait_for_complete_command)
		{
			LOG(L"Executing complete command: " << l_complete_command);
			dwExitCode = DVLib::ExecCmd(l_complete_command);
		}
		else
		{
			LOG(L"Detaching complete command: " << l_complete_command);
			DVLib::DetachCmd(l_complete_command);
		}
	}
}


// IExecuteCallback
bool CdotNetInstallerDlg::OnComponentExecBegin(const ComponentPtr& component)
{
	if (get(component->downloaddialog))
	{
		if (! RunDownloadConfiguration(component->downloaddialog))
		{
			LOG(L"*** Component '" << component->description << L": ERROR ON DOWNLOAD");
			THROW_EX(L"Error downloading '" << component->description << L"'");
		}
	}

	m_component_dlg.LoadComponent(m_configuration, component);
	return true;
}

bool CdotNetInstallerDlg::OnComponentExecWait(const ComponentPtr& component)
{
	if (InstallUILevelSetting::Instance->IsAnyUI())
	{
		m_component_dlg.DoModal();
	}

	LOG(L"--- Component '" << component->description << L": DIALOG CLOSED");
	return true;
}

bool CdotNetInstallerDlg::OnComponentExecSuccess(const ComponentPtr& component)
{
	// se è presente un messaggio di completamento installazione
	if (! component->installcompletemessage.empty())
	{
		DniMessageBox::Show(component->installcompletemessage, MB_OK | MB_ICONINFORMATION);
	}

	// se l'installazione ha chiesto di riavviare non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
	if (component->IsRebootRequired())
	{
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		LOG(L"--- Component '" << component->description << L": REQUESTS REBOOT");

		std::wstring reboot_required = component->reboot_required;
		if (reboot_required.empty()) reboot_required = p_configuration->reboot_required;
		
		if (p_configuration->must_reboot_required || component->must_reboot_required)
		{
			LOG(L"--- Component '" << component->description << L": REQUIRES REBOOT");
			DniMessageBox::Show(reboot_required, MB_OK | MB_ICONQUESTION);
			m_reboot = true;
		}
		else if (DniMessageBox::Show(reboot_required, MB_YESNO|MB_ICONQUESTION, IDYES) == IDYES)
		{
			m_reboot = true;
		}

		if (m_reboot)
		{
			LOG(L"--- Component '" << component->description << L": CAUSED A REBOOT");
			return false;
		}
	}

	return true;
}

bool CdotNetInstallerDlg::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
	LOG(L"--- Component '" << component->description << L"' FAILED: " << DVLib::string2wstring(ex.what()));
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
    // the component failed to install, display an error message and let the user choose to continue or not
    // unless global or component setting decides otherwise
	std::wstring failed_exec_command_continue = component->failed_exec_command_continue;
	if (failed_exec_command_continue.empty()) failed_exec_command_continue = p_configuration->failed_exec_command_continue;
	std::wstring error_message = DVLib::FormatMessage(const_cast<wchar_t *>(failed_exec_command_continue.c_str()), component->description.c_str());

    bool break_sequence = false;
    if (p_configuration->allow_continue_on_error && component->allow_continue_on_error)
    {
	    break_sequence = (DniMessageBox::Show(error_message, MB_YESNO, IDNO, MB_YESNO | MB_ICONEXCLAMATION) == IDNO);
    }
    else
    {
        DniMessageBox::Show(error_message, MB_OK, 0, MB_ICONEXCLAMATION);
        break_sequence = true;
    }

    if (break_sequence)
	{
		LOG(L"--- Component '" << component->description << L"': FAILED, ABORTING");
		return false;
	}

	return true;
}

