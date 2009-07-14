#pragma once
#include "afxwin.h"
#include "KCBusyProgressCtrl.h"
#include "resource.h"

class Configuration;
class Component;

#define WM_USER_SETSTATUSINSTALL (WM_USER+1)

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
	void LoadComponent(const ConfigurationPtr& setting, const ComponentPtr& p_Component);

private:
	
	UINT_PTR m_iTimer; //0 se il timer non è attivo

private:
	ConfigurationPtr m_Configuration;
	ComponentPtr m_Component;
public:
	afx_msg void OnBnClickedSkip();
	afx_msg void OnTimer(UINT nIDEvent);
    void OnCancel();
	CKCBusyProgressCtrl m_BusyControl;
	afx_msg LRESULT OnSetStatusInstall(WPARAM wParam, LPARAM lParam);
};

struct InstallStatusParam
{
	std::wstring Status;

	static InstallStatusParam * CreateStatus(const std::wstring& status)
	{
		InstallStatusParam * param = new InstallStatusParam();
		param->Status = status;
		return param;
	}

	static void Free(InstallStatusParam * param)
	{
		delete param;
	}
};
