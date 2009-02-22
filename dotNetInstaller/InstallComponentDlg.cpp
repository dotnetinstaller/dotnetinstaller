// InstallComponentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "InstallComponentDlg.h"
#include ".\installcomponentdlg.h"


// InstallComponentDlg dialog

IMPLEMENT_DYNAMIC(InstallComponentDlg, CDialog)
InstallComponentDlg::InstallComponentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InstallComponentDlg::IDD, pParent),
	m_Component(NULL),
	m_Setting(NULL),
	m_iTimer(0)
{
}

InstallComponentDlg::~InstallComponentDlg()
{
}

void InstallComponentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HELP_INSTALL, m_InstallMessage);
	DDX_Control(pDX, IDC_BUSYCONTROL, m_BusyControl);
}


BEGIN_MESSAGE_MAP(InstallComponentDlg, CDialog)
	ON_MESSAGE(WM_USER_SETSTATUSINSTALL, OnSetStatusInstall)
    ON_WM_TIMER()
END_MESSAGE_MAP()

// InstallComponentDlg message handlers

void InstallComponentDlg::LoadComponent(installerSetting * p_Setting, component * p_Component)
{
	m_Setting = p_Setting;
	m_Component = p_Component;
}

//void InstallComponentDlg::OnBnClickedNext()
//{
//	bool l_retVal;
//
//	CString l_tmp;
//	l_tmp.Format(m_Setting->installing_component_wait, m_Component->description);
//	m_InstallMessage.SetWindowText(l_tmp);
//
//	l_retVal = m_Component->Exec();
//	
//	if (l_retVal == false)
//	{
//		OnCancel();
//	}
//	else
//	{
//		m_bSkipped = false;
//		m_iTimer = this->SetTimer(1,1000,NULL);
//		m_Install_Next.EnableWindow(FALSE);
//		m_Install_Skip.EnableWindow(FALSE);
//	}
//}

void InstallComponentDlg::OnBnClickedSkip()
{
	OnCancel();
}

void InstallComponentDlg::OnCancel()
{
    if (m_Component != NULL)
    {
        m_Component->cancelled = true;
    }
}

void InstallComponentDlg::OnTimer(UINT nIDEvent)
{
	try
	{
		if (m_Component != NULL)
		{
			if (m_Component->IsExecuting() == false && m_iTimer != 0)
			{
				m_BusyControl.End();

				//Kill Timer
				KillTimer(m_iTimer);
				m_iTimer = 0;

				DWORD l_ExitCode = m_Component->GetExitCode();
				if (l_ExitCode == ERROR_SUCCESS || l_ExitCode == ERROR_SUCCESS_REBOOT_REQUIRED)
				{
					OnOK();
				}
				else //error
				{
					OnOK();
				}
			}
		}
	}
	catch(...)
	{
		_ASSERT(false);
	}
	CDialog::OnTimer(nIDEvent);
}

BOOL InstallComponentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_BusyControl.SetNumSteps(16);
	m_BusyControl.SetSpeed(100);
	m_BusyControl.SetMode(BPC_MODE_BUSY);
	m_BusyControl.SetColBlockFace( RGB(255, 255, 255) );
	m_BusyControl.SetColBlockFaceHi( GetSysColor(COLOR_HIGHLIGHT) );
	m_BusyControl.SetBusyType( BPC_BUSY_PINGPONG );
	m_BusyControl.SetColBlockEdge( RGB(0, 0, 0) );
	m_BusyControl.SetColBlockEdgeHi( RGB(0, 0, 0) );

	m_BusyControl.Recalc();
	m_BusyControl.Start();

	SetWindowText(m_Component->description);

	CString l_tmp;
	l_tmp.Format(m_Setting->installing_component_wait, m_Component->description);
    m_InstallMessage.SetWindowText(l_tmp);
    m_iTimer = this->SetTimer(1,1000,NULL);
	return TRUE;
}

// WM_USER_SETSTATUSINSTALL
afx_msg LRESULT InstallComponentDlg::OnSetStatusInstall(WPARAM wParam, LPARAM lParam)
{
    if (wParam != NULL)
    {
        InstallStatusParam * status = (InstallStatusParam *) wParam;
		CString l_tmp;
		l_tmp.Format(m_Setting->installing_component_wait, (LPCWSTR) status->Status);
		m_InstallMessage.SetWindowText(l_tmp);
        InstallStatusParam::Free(status);
    }

	return 0;
}
