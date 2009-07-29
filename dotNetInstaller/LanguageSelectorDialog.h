#pragma once

#include "Resource.h"

class CLanguageSelectorDialog : public CDialog
{
	DECLARE_DYNAMIC(CLanguageSelectorDialog)
public:
	CLanguageSelectorDialog(const ConfigFile& config, CWnd* pParent = NULL);
	enum { IDD = IDD_LANGUAGE_SELECTOR_DIALOG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	std::vector<ConfigurationPtr> m_Configurations;
	std::wstring m_CancelText;
	std::wstring m_OKText;
	std::wstring m_Title;
public:
	CComboBox m_listLanguages;
	CButton m_btnOK;
	CButton m_btnCancel;
	afx_msg void OnOK();
};
