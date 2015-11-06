// ExtractCabDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "InstallStatus.h"
#include "ExtractCabDlg.h"

IMPLEMENT_DYNAMIC(ExtractCabDlg, CDialog)

ExtractCabDlg::ExtractCabDlg(CWnd * pParent)
: CDialog(ExtractCabDlg::IDD, pParent)
, m_iTimer(0)
{
}

ExtractCabDlg::~ExtractCabDlg()
{
}

void ExtractCabDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_HELP_INSTALL, m_InstallMessage);
    DDX_Control(pDX, IDC_BUSYCONTROL, m_BusyControl);
}

BEGIN_MESSAGE_MAP(ExtractCabDlg, CDialog)
    ON_MESSAGE(WM_USER_SETSTATUSINSTALL, OnSetStatusInstall)
    ON_WM_TIMER()
END_MESSAGE_MAP()

// ExtractCabDlg message handlers
void ExtractCabDlg::LoadComponent(const ConfigurationPtr& configuration, const ExtractCabProcessorPtr& component)
{
    m_Configuration = configuration;
    m_Component = component;
}

void ExtractCabDlg::OnBnClickedSkip()
{
    OnCancel();
}

void ExtractCabDlg::OnCancel()
{
    if (get(m_Component) != NULL)
    {
        m_Component->cancelled = true;
    }
}

void ExtractCabDlg::OnTimer(UINT nIDEvent)
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

BOOL ExtractCabDlg::OnInitDialog()
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

    InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_Configuration));
    CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    SetWindowText(p_configuration->cab_dialog_caption.GetValue().c_str());

    std::wstring l_tmp = DVLib::FormatMessage(const_cast<wchar_t *>(
        p_configuration->cab_dialog_message.GetValue().c_str()), 
        p_configuration->cab_dialog_caption.GetValue().c_str());
    m_InstallMessage.SetWindowText(l_tmp.c_str());
    m_iTimer = this->SetTimer(1,1000,NULL);
    return TRUE;
}

// WM_USER_SETSTATUSINSTALL
afx_msg LRESULT ExtractCabDlg::OnSetStatusInstall(WPARAM wParam, LPARAM /*lParam*/)
{
    if (wParam != NULL)
    {
        InstallStatusPtr status(reinterpret_cast<InstallStatus *>(wParam));
        InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_Configuration));
        CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
        std::wstring tmp = DVLib::FormatMessage(const_cast<wchar_t *>(
            p_configuration->cab_dialog_message.GetValue().c_str()), 
            status->status.c_str());
        m_InstallMessage.SetWindowText(tmp.c_str());
    }

    return 0;
}
