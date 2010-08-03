#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallComponentDlg.h"
#include "ExtractCabDlg.h"
#include "ExtractCabProcessor.h"
#include "DownloadDialog.h"
#include "BrowseCtrl.h"
#include "ControlValue.h"
#include <Version/Version.h>

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

bool CdotNetInstallerDlg::Run()
{
	return(IDOK == this->DoModal());
}

BOOL CdotNetInstallerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// set components list callback for double-click execution
	m_ListBoxComponents.SetExecuteCallback(this);

	// Impostare l'icona per questa finestra di dialogo. Il framework non esegue questa operazione automaticamente
	//  se la finestra principale dell'applicazione non è una finestra di dialogo.
	SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
	SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.

	// determinating operating system
    m_lblOperatingSystem.SetWindowText(
		(DVLib::GetOperatingSystemVersionString() + L" (" + 
		DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L")").c_str());

	// hide the "Skip" button if there are no additional configurations
	if (!m_additional_config)
	{
		m_btnSkip.ShowWindow(SW_HIDE);
	}

	// load components
	LoadComponents();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	SetWindowText(p_configuration->dialog_caption.GetValue().c_str());
    AfxGetApp()->m_pszAppName = _tcsdup(p_configuration->dialog_caption.GetValue().c_str());

	m_btnCancel.SetWindowText(p_configuration->cancel_caption.GetValue().c_str());
	m_btnSkip.SetWindowText(p_configuration->skip_caption.GetValue().c_str());

	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		m_btnInstall.SetWindowText(p_configuration->install_caption.GetValue().c_str());
		m_lblMessage.SetWindowText(p_configuration->dialog_message.GetValue().c_str());
		break;
	case SequenceUninstall:
		m_btnInstall.SetWindowText(p_configuration->uninstall_caption.GetValue().c_str());
		m_lblMessage.SetWindowText(p_configuration->dialog_message_uninstall.GetValue().c_str());
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

	switch(DialogButton::wstring2button(p_configuration->dialog_default_button.GetValue()))
	{
	case DialogButton::dialog_default_button_cancel:
		SetDefaultButton(IDCANCEL);
		break;
	case DialogButton::dialog_default_button_install:
		SetDefaultButton(IDC_INSTALL);
		break;
	case DialogButton::dialog_default_button_skip:
		SetDefaultButton(IDC_SKIP);
		break;
	default:
		THROW_EX("Unsupported dialog_default_button: " << p_configuration->dialog_default_button.GetValue());
	}

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

	AddUserControls();

	Start();

	return FALSE; // don't set focus on the first control
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
		pComponent->checked = (m_ListBoxComponents.GetCheck(i) == 1);
	}
}

void CdotNetInstallerDlg::OnExecBegin()
{
	SetControlValues();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    ExtractCab(L"", p_configuration->show_cab_dialog);		
}

void CdotNetInstallerDlg::OnBnClickedInstall()
{
	try
	{
		auto_any<CWnd *, close_enable> btn_install(& m_btnInstall);
		m_btnInstall.EnableWindow(FALSE);
		auto_any<CWnd *, close_enable> btn_cancel(& m_btnCancel);
		m_btnCancel.EnableWindow(FALSE);
		auto_any<CWnd *, close_enable> btn_skip(& m_btnSkip);
		m_btnSkip.EnableWindow(FALSE);
		
		ClearError();
        SelectComponents();

		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		Components components = p_configuration->GetSupportedComponents(
			m_lcidtype, InstallerSession::Instance->sequence);

		int rc = components.Exec(this);
		InstallerUI::AfterInstall(rc);
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
	bool rc = InstallerUI::LoadComponentsList();
	InstallConfiguration * pConfiguration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(pConfiguration != NULL, L"Invalid configuration");
	m_ListBoxComponents.Load(m_lcidtype, pConfiguration);
	return rc;
}

void CdotNetInstallerDlg::AddComponent(const ComponentPtr& component)
{
	m_ListBoxComponents.AddComponent(component);
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
	for each(CWnd * control in m_custom_controls)
	{
		control->DestroyWindow();
		delete control;
	}

	for each(CFont * font in m_custom_fonts)
	{
		delete font;
	}

	m_custom_controls.clear();

	InstallerUI::Terminate();
}

void CdotNetInstallerDlg::OnBnClickedCancel()
{
	RecordError(-2);
	OnCancel();
}

void CdotNetInstallerDlg::ExtractCab(const std::wstring& id, bool display_progress)
{
    ExtractCabDlg dlg;
	ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, id, & dlg));	
	int cab_count = p_extractcab->GetCabCount();
	if (cab_count == 0)
	{
		LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': NO FILES EMBEDDED");
		return;
	}

	LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': " << cab_count << L" CAB(s)");

	if (display_progress && InstallUILevelSetting::Instance->IsAnyUI())
		dlg.LoadComponent(m_configuration, p_extractcab);

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	p_extractcab->cab_path = p_configuration->cab_path;
	p_extractcab->cab_cancelled_message = p_configuration->cab_cancelled_message;
	p_extractcab->BeginExec();

	if (display_progress && InstallUILevelSetting::Instance->IsAnyUI())
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

	WidgetPosition current;
	current.FromRect(wpc.rcNormalPosition);
    if (pos.Left() != 0) current.Left(pos.Left());
    if (pos.Width() != 0) current.Width(pos.Width());
    if (pos.Top() != 0) current.Top(pos.Top());
    if (pos.Height() != 0) current.Height(pos.Height());

	// move the window to a combination of old and new coordinates
 	wpc.rcNormalPosition = current.ToRect();
    dlg.SetWindowPlacement(& wpc);
    return true;
}

bool CdotNetInstallerDlg::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
	if (! p_Configuration->IsRequired())
	{
		LOG(L"*** Component '" << p_Configuration->component_id << L"': SKIPPING DOWNLOAD/COPY");
		return true;
	}

	CDownloadDialog downloaddlg(p_Configuration, this);
	downloaddlg.DoModal();
	return downloaddlg.IsDownloadCompleted();
}

// IExecuteCallback
bool CdotNetInstallerDlg::OnComponentExecBegin(const ComponentPtr& component)
{
	bool rc = InstallerUI::ComponentExecBegin(component);
	m_component_dlg.LoadComponent(m_configuration, component);
	return rc;
}

bool CdotNetInstallerDlg::OnComponentExecWait(const ComponentPtr& component)
{
	if (InstallUILevelSetting::Instance->IsAnyUI())
	{
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		if (p_configuration->show_progress_dialog && component->show_progress_dialog)
		{
			m_component_dlg.DoModal();
			LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): DIALOG CLOSED");
		}
	}

	return true;
}

bool CdotNetInstallerDlg::OnComponentExecSuccess(const ComponentPtr& component)
{
	return InstallerUI::ComponentExecSuccess(component);
}

bool CdotNetInstallerDlg::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
	return InstallerUI::ComponentExecError(component, ex);
}

void CdotNetInstallerDlg::AddControl(const ControlLabel& label)
{
	CStatic * p_static = new CStatic();
	p_static->Create(label.text.GetValue().c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_NOPREFIX, label.position.ToRect(), this);
	p_static->EnableWindow(label.IsEnabled());
	p_static->SetFont(CreateFont(label));
	m_custom_controls.push_back(p_static);
}

CFont * CdotNetInstallerDlg::CreateFont(const ControlText& text)
{
	CFont * p_font = new CFont;	
	int nFontHeight = MulDiv(text.font_size, GetDeviceCaps(GetDC()->GetSafeHdc(), LOGPIXELSY), 72);
	p_font->CreateFont(nFontHeight, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, text.font_name.GetValue().c_str());
	m_custom_fonts.push_back(p_font);
	return p_font;
}

void CdotNetInstallerDlg::AddControl(const ControlCheckBox& checkbox)
{
	ControlValueCheckBox * p_checkbox = new ControlValueCheckBox(checkbox);
	p_checkbox->Create(checkbox.text.GetValue().c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX, checkbox.position.ToRect(), this, 0);
	p_checkbox->EnableWindow(checkbox.IsEnabled());
	p_checkbox->SetFont(CreateFont(checkbox));
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(checkbox.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		if (checkbox.checked_value == value->second) p_checkbox->SetCheck(1);
		else if (checkbox.unchecked_value == value->second) p_checkbox->SetCheck(0);
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
	ControlValueEdit * p_edit = new ControlValueEdit(edit);
	p_edit->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, edit.position.ToRect(), this, 0);
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(edit.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		p_edit->SetWindowText(value->second.c_str());
	}
	else
	{
		p_edit->SetWindowText(edit.text.GetValue().c_str());
	}
	p_edit->EnableWindow(edit.IsEnabled());
	p_edit->SetFont(CreateFont(edit));
	m_custom_control_values.insert(std::pair<std::wstring, ControlValue *>(edit.id, p_edit));
	m_custom_controls.push_back(p_edit);
}

void CdotNetInstallerDlg::AddControl(const ControlBrowse& browse)
{
	ControlValueBrowse * p_browse = new ControlValueBrowse(browse);
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
		p_browse->SetButtonText(browse.button_text.GetValue().c_str());
	}
	if (browse.allow_edit) dwStyle |= BC_CTL_ALLOWEDIT;
	if (browse.folders_only) dwStyle |= BC_CTL_FOLDERSONLY; 
	p_browse->SetButtonStyle(dwStyle);
	// filter
	if (! browse.filter.empty()) p_browse->SetFilter(browse.filter.GetValue().c_str());
	// file flags
	DWORD dwFileFlags = 0;
	if (browse.must_exist) dwFileFlags |= OFN_FILEMUSTEXIST;
	if (browse.hide_readonly) dwFileFlags |= OFN_HIDEREADONLY;
	p_browse->SetFileFlags(dwFileFlags);
	// default extension
	p_browse->SetDefExt(NULL);
	// default path
	p_browse->SetWindowTextW(browse.text.GetValue().c_str());
	std::map<std::wstring, std::wstring>::iterator value;
	if ((value = InstallerSession::Instance->AdditionalControlArgs.find(browse.id)) != 
		InstallerSession::Instance->AdditionalControlArgs.end())
	{
		p_browse->SetPathName(value->second.c_str());
	}
	else
	{
		p_browse->SetPathName(browse.text.GetValue().c_str());
	}
	// font
	p_browse->SetFont(CreateFont(browse));
	// open, not save as
	p_browse->SetOpenSave(TRUE); 
	p_browse->EnableWindow(browse.IsEnabled());
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
	ControlValueLicense * p_checkbox = new ControlValueLicense(license);
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
	p_link->Create(license.text.GetValue().c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_NOPREFIX, link_rect, this, 0);
	p_link->SetHyperlink(license_file);
	p_link->SetFont(CreateFont(license));
	m_custom_controls.push_back(p_link);
}

void CdotNetInstallerDlg::AddControl(const ControlHyperlink& hyperlink)
{
	CHyperlinkStatic * p_link = new CHyperlinkStatic();
	p_link->Create(hyperlink.text.GetValue().c_str(), WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_NOPREFIX, hyperlink.position.ToRect(), this, 0);
	p_link->SetHyperlink(hyperlink.uri);
	p_link->SetFont(CreateFont(hyperlink));
	m_custom_controls.push_back(p_link);
}

void CdotNetInstallerDlg::AddControl(const ControlImage& image)
{
	CStatic * p_image = new CStatic();
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP;
	if (image.center) dwStyle |= SS_CENTERIMAGE;
	p_image->Create(NULL, dwStyle, image.position.ToRect(), this);
	p_image->SetBitmap(DVLib::LoadBitmapFromResource(AfxGetApp()->m_hInstance, image.resource_id.GetValue(), L"CUSTOM"));
	p_image->EnableWindow(image.IsEnabled());
	m_custom_controls.push_back(p_image);
}

void CdotNetInstallerDlg::SetControlValues()
{
	std::map<std::wstring, ControlValue *>::const_iterator iter;
	for(iter = m_custom_control_values.begin(); iter != m_custom_control_values.end(); ++iter)
	{
		if (iter->second->IsVisible())
		{
			if (iter->second->IsEnabled())
			{
				LOG(L"--- Setting user-defined value '" << iter->first << L"'=" << iter->second->GetValue());
				InstallerSession::Instance->AdditionalControlArgs[iter->first] = iter->second->GetValue();
			}
			else
			{
				LOG(L"--- Skipping user-defined value '" << iter->first << L"', control disabled");
			}
		}
		else
		{
			LOG(L"--- Skipping user-defined value '" << iter->first << L"', control hidden");
		}
	}
}

DWORD CdotNetInstallerDlg::SetDefaultButton(const DWORD id) 
{
	DWORD prev_id = GetDefID();
	SendDlgItemMessage(prev_id, WM_KILLFOCUS);
	SendDlgItemMessage(prev_id, BM_SETSTYLE, BS_PUSHBUTTON, (LPARAM) TRUE);
	SetDefID(id);
	SendDlgItemMessage(id, WM_SETFOCUS);
	SendDlgItemMessage(id, BM_SETSTYLE, BS_DEFPUSHBUTTON, (LPARAM) TRUE);
	return prev_id;
}

void CdotNetInstallerDlg::ResetContent()
{
	m_ListBoxComponents.ResetContent();
}

HINSTANCE CdotNetInstallerDlg::GetInstance() const
{
	return AfxGetApp()->m_hInstance;
}

HWND CdotNetInstallerDlg::GetHwnd() const
{
	return GetSafeHwnd();
}

void CdotNetInstallerDlg::Stop()
{
	OnOK();
}

void CdotNetInstallerDlg::StartInstall()
{
	m_btnInstall.EnableWindow(FALSE);
	m_btnCancel.EnableWindow(FALSE);
    m_InfoLink.EnableWindow(FALSE);
	OnBnClickedInstall();
}