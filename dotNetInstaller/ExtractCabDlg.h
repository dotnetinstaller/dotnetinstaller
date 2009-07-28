#pragma once
#include "afxwin.h"
#include "KCBusyProgressCtrl.h"
#include "resource.h"
#include "ExtractCabProcessor.h"

#define WM_USER_SETSTATUSINSTALL (WM_USER+1)

class ExtractCabDlg : public CDialog
{
	DECLARE_DYNAMIC(ExtractCabDlg)

public:
	ExtractCabDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ExtractCabDlg();

// Dialog Data
	enum { IDD = IDD_DIALOGINSTALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
	CStatic m_InstallMessage;
	void LoadComponent(const ConfigurationPtr& setting, const ExtractCabProcessorPtr& p_Component);

private:
	
	UINT_PTR m_iTimer; //0 se il timer non è attivo

private:
	ConfigurationPtr m_Configuration;
	ExtractCabProcessorPtr m_Component;
public:
	afx_msg void OnBnClickedSkip();
	afx_msg void OnTimer(UINT nIDEvent);
    void OnCancel();
	CKCBusyProgressCtrl m_BusyControl;
	afx_msg LRESULT OnSetStatusInstall(WPARAM wParam, LPARAM lParam);
};
