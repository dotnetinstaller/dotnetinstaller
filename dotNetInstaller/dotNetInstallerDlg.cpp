// dotNetInstallerDlg.cpp : file di implementazione
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallComponentDlg.h"
#include "DniMessageBox.h"
#include "ExtractCabProcessor.h"
#include "DownloadDialog.h"
#include "InstallSystem.h"
#include "InstallerCommandLineInfo.h"

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
	RemoveRegistryRun();

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

	try
	{
		HBITMAP hBitmap;
		if ( (! p_configuration->dialog_bitmap.empty()) &&
			DVLib::FileExists(p_configuration->dialog_bitmap) )
		{
			hBitmap = DVLib::LoadBitmapFromFile(p_configuration->dialog_bitmap);
		}
		else
		{
			//l'immagine non è inserita come risorsa tipo BITMAP perchè avevo dei problemi poi a chiamare UpdateResource
			// è quindi inserita come risorsa di tipo CUSTOM e letta manualmente
			//hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BANNER));
			hBitmap = DVLib::LoadBitmapFromResource(AfxGetApp()->m_hInstance, L"RES_BANNER");
		}

		m_PictureBox.SetBitmap(hBitmap);
	}
	catch(std::exception&)
	{
		//errore nel caricamento dell'immagine
	}

	// just display CAB contents
	if (commandLineInfo.DisplayCab())
	{
		DisplayCab();
		OnOK();
		return FALSE;
	}

    // just extract the CABs
    if (commandLineInfo.ExtractCab())
    {
		p_configuration->cab_path = DVLib::GetCurrentDirectoryW();
        p_configuration->cab_path.append(L"\\SupportFiles");
        p_configuration->cab_path_autodelete = false;
        ExtractCab();
        OnOK();
        return FALSE;
    }
	
	bool all_components_installed = LoadComponentsList();
	if (all_components_installed)
	{
		if (p_configuration->auto_close_if_installed || CurrentInstallUILevel.IsSilent())
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
		
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		Components components = p_configuration->GetSupportedComponents(m_lcidtype);
		bool success = components.Exec(this);

		if (m_reboot)
		{
			DVLib::ExitWindowsSystem(EWX_REBOOT);
			PostQuitMessage(ERROR_SUCCESS_REBOOT_REQUIRED);
			return;
		}

		RemoveRegistryRun();

		// silent execution, 
		if (CurrentInstallUILevel.IsSilent()) 
		{
			OnOK();
			return;
		}

		// failure and auto-close-on-error
		if (! success && p_configuration->auto_close_on_error)
		{
			OnOK();
			return;
		}

		// success and possibly auto-close with a complete code if all components have been installed
		if (success)
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
		DniSilentMessageBox(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
		RecordError();
    }
	catch(...)
	{
		LOG(L"*** Failed to install one or more components");
		DniSilentMessageBox(TEXT("Failed to install one or more components"), MB_OK|MB_ICONSTOP);
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
        std::wstring cabpath = (! p_configuration->cab_path.empty()) ? p_configuration->cab_path : InstallerSession::GetSessionTempPath(true);
		cabpath = InstallerSession::MakePath(cabpath);
        if (p_configuration->cab_path_autodelete && ! cabpath.empty() && DVLib::FileExists(cabpath))
        {
		    LOG(L"Deleting temporary folder: " << cabpath);
			DVLib::DirectoryDelete(cabpath);
        }

		LOG(L"dotNetInstaller finished");
	}
    catch(std::exception& ex)
    {
		LOG("Error terminating dotNetInstaller: " << DVLib::string2wstring(ex.what()));
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

void CdotNetInstallerDlg::DisplayCab()
{
    InstallComponentDlg dlg;
	ComponentPtr extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, & dlg));
	ExtractCabProcessor * p = reinterpret_cast<ExtractCabProcessor *>(get(extractcab));
	DniMessageBox(DVLib::join(p->GetCabFiles(), L"\r\n"), MB_OK|MB_ICONINFORMATION);
}

void CdotNetInstallerDlg::ExtractCab()
{
    InstallComponentDlg dlg;
	ComponentPtr extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, & dlg));

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	
	ExtractCabProcessor * p = reinterpret_cast<ExtractCabProcessor *>(get(extractcab));
	p->cab_path = p_configuration->cab_path;
	p->cab_cancelled_message = p_configuration->cab_cancelled_message;
	p->description = p_configuration->cab_dialog_caption;
	if (p->GetCabCount() == 0)
		return;

	ConfigurationPtr installconfiguration(new InstallConfiguration());
	InstallConfiguration * c = reinterpret_cast<InstallConfiguration *>(get(installconfiguration));
	c->install_caption = p_configuration->cab_dialog_caption;
	c->installing_component_wait = p_configuration->cab_dialog_message;
	
	if (CurrentInstallUILevel.IsAnyUI())
		dlg.LoadComponent(installconfiguration, extractcab);

	p->Exec();

	if (CurrentInstallUILevel.IsAnyUI())
		dlg.DoModal();

	p->Wait();
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

bool CdotNetInstallerDlg::RunDownloadConfiguration(const DownloadGroupConfigurationPtr& p_Configuration)
{
	DownloadDialog downloaddlg(p_Configuration, this);
	downloaddlg.DoModal();
	return downloaddlg.IsDownloadCompleted();
}

bool CdotNetInstallerDlg::RunComponentDownload(const ComponentPtr& p_Component)
{
	if (get(p_Component->downloadconfiguration))
    {
		return RunDownloadConfiguration(p_Component->downloadconfiguration);
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
		DniMessageBox(message, MB_OK|MB_ICONINFORMATION);
    }

	std::wstring l_complete_command = p_configuration->complete_command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (! p_configuration->complete_command_silent.empty()) l_complete_command = p_configuration->complete_command_silent;
		else if (! p_configuration->complete_command_basic.empty()) l_complete_command = p_configuration->complete_command_basic;
		break;
	case InstallUILevelBasic:
		if (! p_configuration->complete_command_basic.empty()) l_complete_command = p_configuration->complete_command_basic;
		else if (! p_configuration->complete_command_silent.empty()) l_complete_command = p_configuration->complete_command_silent;
		break;
	}

    if (! commandLineInfo.GetCompleteCommandArgs().empty())
    {
        l_complete_command.append(L" ");
        l_complete_command.append(commandLineInfo.GetCompleteCommandArgs());
    }

	if (! l_complete_command.empty())
	{
		LOG(L"Executing complete command: " << l_complete_command);
        DWORD dwExitCode = 0;
        dwExitCode = DVLib::ExecCmd(l_complete_command);
	}
}


// IExecuteCallback
bool CdotNetInstallerDlg::OnComponentExecBegin(const ComponentPtr& component)
{
	if (get(component->downloadconfiguration))
	{
		if (! RunDownloadConfiguration(component->downloadconfiguration))
		{
			LOG(L"*** Component '" << component->description << L": ERROR ON DOWNLOAD");
			THROW_EX(L"Error downloading '" << component->description << L"'");
		}
	}

	l_component_dlg.LoadComponent(m_configuration, component);
	return true;
}

bool CdotNetInstallerDlg::OnComponentExecWait(const ComponentPtr& component)
{
	if (CurrentInstallUILevel.IsAnyUI())
	{
		l_component_dlg.DoModal();
	}

	LOG(L"--- Component '" << component->description << L": DIALOG CLOSED");
	return true;
}

bool CdotNetInstallerDlg::OnComponentExecSuccess(const ComponentPtr& component)
{
	// se è presente un messaggio di completamento installazione
	if (! component->installcompletemessage.empty())
	{
		DniSilentMessageBox(component->installcompletemessage, MB_OK | MB_ICONINFORMATION);
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
			DniSilentMessageBox(reboot_required, MB_OK | MB_ICONQUESTION);
			m_reboot = true;
		}
		else if (DniMessageBox(reboot_required, MB_YESNO|MB_ICONQUESTION, IDYES) == IDYES)
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
	    break_sequence = (DniSilentMessageBox(error_message, MB_YESNO, IDNO, MB_YESNO | MB_ICONEXCLAMATION) == IDNO);
    }
    else
    {
        DniSilentMessageBox(error_message, MB_OK, 0, MB_ICONEXCLAMATION);
        break_sequence = true;
    }

    if (break_sequence)
	{
		LOG(L"--- Component '" << component->description << L": FAILED, ABORTING");
		return false;
	}

	return true;
}
