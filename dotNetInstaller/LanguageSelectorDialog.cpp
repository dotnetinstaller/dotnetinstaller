#include "stdafx.h"
#include "LanguageSelectorDialog.h"
#include "DniMessageBox.h"
#include "DownloadStatus.h"

IMPLEMENT_DYNAMIC(CLanguageSelectorDialog, CDialog)

CLanguageSelectorDialog::CLanguageSelectorDialog(const ConfigFile& configfile, CWnd* pParent /*=NULL*/)
	: CDialog(CLanguageSelectorDialog::IDD, pParent)
{
	m_Configurations = configfile;
	m_CancelText = configfile.language_selector_cancel;
	m_OKText = configfile.language_selector_ok;
	m_Title = configfile.language_selector_title;
}

void CLanguageSelectorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LANGUAGES, m_listLanguages);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDOK, m_btnOK);
}

BEGIN_MESSAGE_MAP(CLanguageSelectorDialog, CDialog)
	ON_COMMAND(IDOK, OnOK)
END_MESSAGE_MAP()

BOOL CLanguageSelectorDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	LOG(L"Opening language selector dialog '" << m_Title << L"'");	
	m_btnCancel.SetWindowText(m_CancelText.c_str());
	m_btnOK.SetWindowText(m_OKText.c_str());
	SetWindowText(m_Title.c_str());

	for each(const ConfigurationPtr& configuration in m_Configurations)
	{
		m_listLanguages.AddString(configuration->GetLanguageString().c_str());
		m_listLanguages.SetItemDataPtr(m_listLanguages.GetCount() - 1, 
			static_cast<LPVOID>(get(configuration)));
	}

	if (m_listLanguages.GetCount() == 0)
	{
		THROW_EX(L"No languages are available for language selection");
	}

	m_listLanguages.SetCurSel(0);
	return TRUE;
}

void CLanguageSelectorDialog::OnOK()
{
	Configuration * p = static_cast<Configuration *>(m_listLanguages.GetItemDataPtr(m_listLanguages.GetCurSel()));
	CHECK_BOOL(p != NULL, L"Missing configuration");
	
	CHECK_BOOL(! p->language_id.empty(),
		L"Chosen configuration of type '" << p->type << L"' is missing a language_id");

	LOG(L"User-chosen language id: " << p->language_id);
	InstallerSession::Instance->languageid = DVLib::wstring2long(p->language_id);

	CDialog::OnOK();
}
