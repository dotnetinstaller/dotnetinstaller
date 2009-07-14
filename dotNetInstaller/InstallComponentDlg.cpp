// InstallComponentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "InstallComponentDlg.h"

IMPLEMENT_DYNAMIC(InstallComponentDlg, CDialog)
InstallComponentDlg::InstallComponentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InstallComponentDlg::IDD, pParent),
	m_Component(NULL),
	m_Configuration(NULL),
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

// \todo: all these pointers need to become shared_any
void InstallComponentDlg::LoadComponent(const ConfigurationPtr& configuration, const ComponentPtr& component)
{
	m_Configuration = configuration;
	m_Component = component;
}

void InstallComponentDlg::OnBnClickedSkip()
{
	OnCancel();
}

void InstallComponentDlg::OnCancel()
{
    if (get(m_Component) != NULL)
    {
        m_Component->cancelled = true;
    }
}

void InstallComponentDlg::OnTimer(UINT nIDEvent)
{
	try
	{
		if (get(m_Component) != NULL)
		{
			if (m_Component->IsExecuting() == false && m_iTimer != 0)
			{
				m_BusyControl.End();
				KillTimer(m_iTimer);
				m_iTimer = 0;				
				OnOK();
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

	SetWindowText(m_Component->description.c_str());

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_Configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
	std::wstring l_tmp = DVLib::FormatMessage(const_cast<wchar_t *>(
		p_configuration->installing_component_wait.c_str()), 
		m_Component->description.c_str());
    m_InstallMessage.SetWindowText(l_tmp.c_str());
    m_iTimer = this->SetTimer(1,1000,NULL);
	return TRUE;
}

// WM_USER_SETSTATUSINSTALL
afx_msg LRESULT InstallComponentDlg::OnSetStatusInstall(WPARAM wParam, LPARAM lParam)
{
    if (wParam != NULL)
    {
        InstallStatusParam * status = (InstallStatusParam *) wParam;
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_Configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
		std::wstring l_tmp = DVLib::FormatMessage(const_cast<wchar_t *>(
			p_configuration->installing_component_wait.c_str()), 
			status->Status.c_str());
		m_InstallMessage.SetWindowText(l_tmp.c_str());
        InstallStatusParam::Free(status);
    }

	return 0;
}
