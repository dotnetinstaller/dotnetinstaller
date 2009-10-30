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
#include "BrowseCtrl.h"
#include "ControlValue.h"
#include "SplashWnd.h"
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

void CdotNetInstallerDlg::DisplaySplash()
{
	// splash screen
	if (! InstallerCommandLineInfo::Instance->DisplaySplash())
		return;
	
	if (! InstallUILevelSetting::Instance->IsAnyUI())
		return;

	HRSRC hsplash = ::FindResourceA(NULL, "RES_SPLASH", "CUSTOM");
	if (NULL == hsplash)
		return;

	HBITMAP hsplash_bitmap = DVLib::LoadBitmapFromResource(AfxGetApp()->m_hInstance, L"RES_SPLASH", L"CUSTOM");
	CHECK_BOOL(CSplashWnd::ShowSplashScreen(3000, hsplash_bitmap, this),
		L"Error loading splash screen.");
}

BOOL CdotNetInstallerDlg::OnInitDialog()
{
	DisplaySplash();

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

	// load components

	bool all = LoadComponentsList();

	if (InstallerSession::Instance->sequence == SequenceInstall && all && p_configuration->supports_uninstall)
	{
		LOG("All components installed, switching to uninstall.");
		InstallerSession::Instance->sequence = SequenceUninstall;
		all = LoadComponentsList();
		if (all)
		{
			LOG("All components uninstalled, nothing to do.");
			InstallerSession::Instance->sequence = SequenceInstall;
		}
	}

	SetWindowText(p_configuration->dialog_caption.c_str());
    AfxGetApp()->m_pszAppName = _tcsdup(p_configuration->dialog_caption.c_str());

	m_btnCancel.SetWindowText(p_configuration->cancel_caption.c_str());
	m_btnSkip.SetWindowText(p_configuration->skip_caption.c_str());

	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		m_btnInstall.SetWindowText(p_configuration->install_caption.c_str());
		m_lblMessage.SetWindowText(p_configuration->dialog_message.c_str());
		break;
	case SequenceUninstall:
		m_btnInstall.SetWindowText(p_configuration->uninstall_caption.c_str());
		m_lblMessage.SetWindowText(p_configuration->dialog_message_uninstall.c_str());
		break;
	}

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

	// controls

	for each(const ControlPtr& control in p_configuration->controls)
	{
		if (InstallerSession::Instance->sequence == SequenceInstall && ! control->display_install)
		{
			LOG(L"-- Skipping " << control->GetString() << L" on install");
			continue;
		}

		if (InstallerSession::Instance->sequence == SequenceUninstall && ! control->display_uninstall)
		{
			LOG(L"-- Skipping " << control->GetString() << L" on uninstall");
			continue;
		}

		LOG(L"-- Adding " << control->GetString());
		switch(control->type)
		{
		case control_type_label:
			AddControl(* (ControlLabel *) get(control));
			break;
		case control_type_checkbox:
			AddControl(* (ControlCheckBox *) get(control));
			break;
		case control_type_edit:
			AddControl(* (ControlEdit *) get(control));
			break;
		case control_type_browse:
			AddControl(* (ControlBrowse *) get(control));
			break;
		case control_type_license:
			AddControl(* (ControlLicense *) get(control));
			break;
		default:
			THROW_EX(L"Invalid control type: " << control->type);
		}
	}
	
	// check sequences

	if (! p_configuration->supports_uninstall && ! p_configuration->supports_install)
	{
		THROW_EX("Configuration supports neither install nor uninstall.");
	}
	else if (InstallerSession::Instance->sequence == SequenceUninstall && ! p_configuration->supports_uninstall)
	{
		THROW_EX("Configuration doesn't support uninstall.");
	}
	else if (InstallerSession::Instance->sequence == SequenceInstall && ! p_configuration->supports_install)
	{
		THROW_EX("Configuration doesn't support install.");
	}

	if (InstallerSession::Instance->sequence == SequenceInstall && all && p_configuration->supports_install)
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
	else if (InstallerSession::Instance->sequence == SequenceUninstall && all && p_configuration->supports_uninstall)
	{
		OnOK();
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
		LOG(L"Silent mode: automatically starting " 
			<< InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
	}

	if (InstallerCommandLineInfo::Instance->Reboot())
	{
		if (p_configuration->auto_continue_on_reboot)
		{
			autostart = true;
			LOG(L"Reboot defines auto-start: automatically starting "
				 << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
		}
	}
	else if (p_configuration->auto_start)
	{
		autostart = true;
		LOG(L"Configuration defines auto-start: automatically starting "
			 << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
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
		SetControlValues();
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
			bool all = LoadComponentsList();
			if (all || p_configuration->auto_close_if_installed) 
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

	// destroy custom dialog controls
	for each(CObject * control in m_custom_controls)
	{
		delete control;
	}

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

void CdotNetInstallerDlg::AddControl(const ControlLabel& label)
{
	CStatic * p_static = new CStatic();
	p_static->Create(label.text.c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP, label.position.ToRect(), this);
	p_static->EnableWindow(label.enabled);
	p_static->SetFont(CreateFont(label));
	m_custom_controls.push_back(p_static);
}

CFont * CdotNetInstallerDlg::CreateFont(const ControlText& text)
{
	CFont * p_font = new CFont;	
	int nFontHeight = MulDiv(text.font_size, GetDeviceCaps(GetDC()->GetSafeHdc(), LOGPIXELSY), 72);
	p_font->CreateFont(nFontHeight, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, text.font_name.c_str());
	m_custom_controls.push_back(p_font);
	return p_font;
}

void CdotNetInstallerDlg::AddControl(const ControlCheckBox& checkbox)
{
	ControlValueCheckBox * p_checkbox = new ControlValueCheckBox(checkbox.checked_value, checkbox.unchecked_value);
	p_checkbox->Create(checkbox.text.c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX, checkbox.position.ToRect(), this, 0);
	p_checkbox->EnableWindow(checkbox.enabled);
	p_checkbox->SetFont(CreateFont(checkbox));
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(checkbox.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		if (value->second == checkbox.checked_value) p_checkbox->SetCheck(1);
		else if (value->second == checkbox.unchecked_value) p_checkbox->SetCheck(0);
		else 
		{
			THROW_EX(L"Invalid " << checkbox.id << L" value '" << value->second << L"', should be one of '"
				<< checkbox.checked_value << L"' or '" << checkbox.unchecked_value << L"'");
		}
	}
	else
	{
		p_checkbox->SetCheck(checkbox.checked);
	}
	m_custom_control_values.insert(std::pair<std::wstring, ControlValue *>(checkbox.id, p_checkbox));
	m_custom_controls.push_back(p_checkbox);
}

void CdotNetInstallerDlg::AddControl(const ControlEdit& edit)
{
	ControlValueEdit * p_edit = new ControlValueEdit();
	p_edit->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, edit.position.ToRect(), this, 0);
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(edit.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		p_edit->SetWindowText(value->second.c_str());
	}
	else
	{
		p_edit->SetWindowText(edit.text.c_str());
	}
	p_edit->EnableWindow(edit.enabled);
	p_edit->SetFont(CreateFont(edit));
	m_custom_control_values.insert(std::pair<std::wstring, ControlValue *>(edit.id, p_edit));
	m_custom_controls.push_back(p_edit);
}

void CdotNetInstallerDlg::AddControl(const ControlBrowse& browse)
{
	ControlValueBrowse * p_browse = new ControlValueBrowse();
	p_browse->Create(browse.position.ToRect(), this, 0);
	// style and options
	DWORD dwStyle = p_browse->GetButtonStyle();
	if (browse.button_text.empty()) 
	{
		dwStyle |= BC_BTN_ICON; 
		// if (browse.flat) dwStyle |= BC_BTN_FLAT; 
		dwStyle &= ~BC_ICO_ARROWFOLDER;
		dwStyle &= ~BC_ICO_FOLDER;
		dwStyle |= BC_ICO_EXPLORER;
	}
	else
	{
		dwStyle &= ~BC_BTN_ICON;
		p_browse->SetButtonText(browse.button_text.c_str());
	}
	if (browse.allow_edit) dwStyle |= BC_CTL_ALLOWEDIT;
	if (browse.folders_only) dwStyle |= BC_CTL_FOLDERSONLY; 
	p_browse->SetButtonStyle(dwStyle);
	// filter
	if (! browse.filter.empty()) p_browse->SetFilter(browse.filter.c_str());
	// file flags
	DWORD dwFileFlags = 0;
	if (browse.must_exist) dwFileFlags |= OFN_FILEMUSTEXIST;
	if (browse.hide_readonly) dwFileFlags |= OFN_HIDEREADONLY;
	p_browse->SetFileFlags(dwFileFlags);
	// default extension
	p_browse->SetDefExt(NULL);
	// default path
	p_browse->SetWindowTextW(browse.text.c_str());
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(browse.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		p_browse->SetPathName(value->second.c_str());
	}
	else
	{
		p_browse->SetPathName(browse.text.c_str());
	}
	// font
	p_browse->SetFont(CreateFont(browse));
	// open, not save as
	p_browse->SetOpenSave(TRUE); 
	m_custom_control_values.insert(std::pair<std::wstring, ControlValue *>(browse.id, p_browse));
	m_custom_controls.push_back(p_browse);
}

void CdotNetInstallerDlg::AddControl(const ControlLicense& license)
{
	// extract license to temporary location
	std::vector<char> license_buffer = DVLib::LoadResourceData<char>(NULL, license.resource_id, L"CUSTOM");
	std::wstring license_file = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionTempPath(), DVLib::GetFileNameW(license.license_file));
	LOG(L"Extracting license '" << license.resource_id << L"' to " << license_file);
	DVLib::FileWrite(license_file, license_buffer);
	// checkbox
	ControlValueLicense * p_checkbox = new ControlValueLicense(license.accept_message);
	CRect checkbox_rect = license.position.ToRect();
	checkbox_rect.right = checkbox_rect.left + 20;
	p_checkbox->Create(L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX, checkbox_rect, this, 0);
	p_checkbox->SetFont(CreateFont(license));
	p_checkbox->SetCheck(license.accepted);
	m_custom_control_values.insert(std::pair<std::wstring, ControlValue *>(license.resource_id, p_checkbox));
	m_custom_controls.push_back(p_checkbox);
	// hyperlink
	CHyperlinkStatic * p_link = new CHyperlinkStatic();
	CRect link_rect = license.position.ToRect();
	link_rect.left += 20;
	p_link->Create(license.text.c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP, link_rect, this, 0);
	p_link->SetCaption(license.text.c_str());
	p_link->SetHyperlink(license_file);
	p_link->SetFont(CreateFont(license));
	m_custom_controls.push_back(p_link);
}

void CdotNetInstallerDlg::SetControlValues()
{
	std::map<std::wstring, ControlValue *>::const_iterator iter;
	for(iter = m_custom_control_values.begin(); iter != m_custom_control_values.end(); ++iter)
	{
		LOG(L"--- Setting user-defined value " << iter->first << L"=" << iter->second->GetValue());
		InstallerSession::Instance->AdditionalControlArgs[iter->first] = iter->second->GetValue();
	}
}
