#pragma once
#include "afxwin.h"

#include "installerTypes.h"

#include "KCBusyProgressCtrl.h"

// InstallComponentDlg dialog

class InstallComponentDlg : public CDialog
{
	DECLARE_DYNAMIC(InstallComponentDlg)

public:
	InstallComponentDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~InstallComponentDlg();

// Dialog Data
	enum { IDD = IDD_DIALOGINSTALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_InstallMessage;
	void LoadComponent(installerSetting * p_Setting, component * p_Component);

private:
	
	UINT_PTR m_iTimer; //0 se il timer non è attivo

private:
	installerSetting * m_Setting;
	component * m_Component;
public:
	afx_msg void OnBnClickedSkip();
	afx_msg void OnTimer(UINT nIDEvent);
	CKCBusyProgressCtrl m_BusyControl;
};
