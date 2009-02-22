#pragma once
#include "afxwin.h"
#include "installerTypes.h"


// CComponentSelector dialog

class CComponentSelector : public CDialog
{
	DECLARE_DYNAMIC(CComponentSelector)

public:
	CComponentSelector(installerSetting * p_Setting, CWnd* pParent = NULL);   // standard constructor
	virtual ~CComponentSelector();

// Dialog Data
	enum { IDD = IDD_COMPONENTSELECTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CCheckListBox m_List;

private:
	installerSetting * m_Settings;
public:
	CButton m_btnOK;
	CButton m_btnCancel;
	CStatic m_lblMessage;

protected:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
};
