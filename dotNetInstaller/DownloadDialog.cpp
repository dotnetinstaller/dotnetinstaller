#include "stdafx.h"
#include "DownloadDialog.h"
#include "DownloadStatus.h"

#define WM_USER_SETSTATUSDOWNLOAD (WM_USER+1)
#define WM_USER_CLOSE_DIALOG (WM_USER+2)

IMPLEMENT_DYNAMIC(CDownloadDialog, CDialog)

CDownloadDialog::CDownloadDialog(const DownloadDialogPtr& p_Configuration, CWnd* pParent /*=NULL*/)
: CDialog(CDownloadDialog::IDD, pParent)
, m_bDownloadCancelled(false)
, m_bDownloadError(false)
, m_bDownloadCompleted(false)
, m_bAutoStartDownload(p_Configuration->auto_start)
, m_Caption(p_Configuration->caption)
, m_Message(p_Configuration->help_message)
, m_hIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME))
, m_MessageDownloadingFile(p_Configuration->downloading_message)
, m_MessageCopyingFile(p_Configuration->copying_message)
, m_MessageConnecting(p_Configuration->connecting_message)
, m_MessageSendingRequest(p_Configuration->sendingrequest_message)
, m_ButtonStartCaption(p_Configuration->start_caption)
, m_ButtonCancelCaption(p_Configuration->cancel_caption)
, m_bDownloadStarted(false)
{
    LOG(L"Opening download dialog '" << m_Caption << L"'");
    m_DownloadDialog = p_Configuration;
}

void CDownloadDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_HELP_DOWNLOAD, m_LabelHelp);
    DDX_Control(pDX, IDC_STATUS, m_LabelStatus);
    DDX_Control(pDX, IDC_START, m_btStart);
    DDX_Control(pDX, IDC_CANCEL, m_btnCancel);
    DDX_Control(pDX, IDC_PROGRESSDOWNLOAD, m_ProgressControl);
}

BEGIN_MESSAGE_MAP(CDownloadDialog, CDialog)
    ON_BN_CLICKED(IDC_CANCEL, OnBnClickedCancel)
    ON_BN_CLICKED(IDC_START, OnBnClickedStart)
    ON_MESSAGE(WM_USER_SETSTATUSDOWNLOAD, OnSetStatusDownload)
    ON_MESSAGE(WM_USER_CLOSE_DIALOG, OnCloseDialog)
    ON_WM_CLOSE()
    ON_COMMAND(IDCANCEL, OnBnClickedCancel)
    ON_WM_SYSCOMMAND()
    ON_COMMAND(IDOK, OnOK)
END_MESSAGE_MAP()

// CDownloadDialog message handlers

void CDownloadDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
    switch(nID)
    {
    case SC_CLOSE:
        DownloadCancel();
        return;
    }

    CDialog::OnSysCommand(nID, lParam);
}

void CDownloadDialog::OnCancel()
{
    DownloadCancel();
}

BOOL CDownloadDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Impostare l'icona per questa finestra di dialogo. Il framework non esegue questa operazione automaticamente
    //  se la finestra principale dell'applicazione non è una finestra di dialogo.
    SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
    SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.

    m_LabelHelp.SetWindowText(m_Message.c_str());
    SetWindowText(m_Caption.c_str());
    m_btnCancel.SetWindowText(m_ButtonCancelCaption.c_str());
    m_btStart.SetWindowText(m_ButtonStartCaption.c_str());
    m_ProgressControl.SetRange(0,1000);
    m_LabelStatus.SetWindowText(TEXT(""));

    if (InstallUILevelSetting::Instance->IsSilent())
    {
        m_btStart.EnableWindow(FALSE);
        m_btnCancel.EnableWindow(FALSE);
        OnBnClickedStart();
    }
    else if (m_bAutoStartDownload || ! m_DownloadDialog->IsDownloadRequired())
    {
        OnBnClickedStart();
    }

    return TRUE;
}

void CDownloadDialog::OnOK()
{
    LOG(L"Closing download dialog '" << m_Caption << L"'");
    CDialog::OnOK();
}

void CDownloadDialog::OnBnClickedCancel() //Cancel Button
{
    DownloadCancel();
}

void CDownloadDialog::OnBnClickedStart()
{	
    m_DownloadDialog->callback = this;
    m_DownloadDialog->BeginExec();
    m_bDownloadStarted = true;
    m_btStart.EnableWindow(FALSE);
}

void CDownloadDialog::OnClose()
{
    m_DownloadDialog->EndExec();
}

//WM_USER_SETSTATUSDOWNLOAD
// Messaggio custom per gestire la sincronizzazione e lo scambio di informazioni tra i due thread 
afx_msg LRESULT CDownloadDialog::OnSetStatusDownload(WPARAM wParam, LPARAM /* lParam */)
{
    DownloadStatusPtr downloadstatus(reinterpret_cast<DownloadStatus *>(wParam));

    if (downloadstatus->type == StatusType_Progress)
    {
        if (downloadstatus->progress_max != 0)
        {
            m_ProgressControl.SetPos((int) ((double) downloadstatus->progress_current / (double) downloadstatus->progress_max * 1000.0));
        }
        else
        {
            m_ProgressControl.SetPos(0);
        }

        m_LabelStatus.SetWindowText(downloadstatus->status.c_str());
    }
    else if (downloadstatus->type == StatusType_Help)
    {
        m_LabelHelp.SetWindowText(downloadstatus->status.c_str());
    }
    else if (downloadstatus->type == StatusType_Error) //ERROR
    {
        // download fails with E_ABORT on cancel
        if (! IsDownloadCancelled())
        {
            LOG(L"*** Download ERROR: " << downloadstatus->error);
            DniMessageBox::Show(downloadstatus->error, MB_OK|MB_ICONSTOP);
            m_bDownloadError = true;
        }

        ::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
    }
    else if (downloadstatus->type == StatusType_Canceled) //CANCELED
    {
        LOG(L"*** Download CANCELED");
        m_bDownloadCancelled = true;
    }
    else if (downloadstatus->type == StatusType_Completed) //COMPLETED
    {
        LOG(L"--- Download OK");
        m_bDownloadCompleted = true; //Download OK
        ::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
    }

    return 0;
}

//ATTENZIONE questi metodo sono chiamati da un altro thread e quindi non devono accedere direttamente alla classe
// Uso la funzione PostMessage che non blocca il thread ma aggiunge una messaggio alla coda dei messaggi
//  dovendogli però passare dei puntatori devo fare la new qui e poi la delete quando leggo il puntatore
//  nella OnSetStatusDownload.
//IDownloadCallback
void CDownloadDialog::Status(ULONG p_progress_current, ULONG p_MaxProgress, const std::wstring& message)
{
    if (message != m_LastStatusMessage)
    {
        m_LastStatusMessage = message;
        DownloadStatusPtr status(DownloadStatus::CreateProgress(message, p_progress_current, p_MaxProgress));
        ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM) (release(status)), 0L );
    }
}

void CDownloadDialog::DownloadComplete()
{
    DownloadStatusPtr status(DownloadStatus::CreateComplete());
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}

void CDownloadDialog::DownloadError(const std::wstring& p_Message)
{
    DownloadStatusPtr status(DownloadStatus::CreateError(p_Message));
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}

void CDownloadDialog::Connecting(const std::wstring& host)
{
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_MessageConnecting.c_str()), host.c_str());
    DownloadStatusPtr status(DownloadStatus::CreateProgress(message, 0, 0));
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}

void CDownloadDialog::SendingRequest(const std::wstring& host)
{
    DownloadStatusPtr status(DownloadStatus::CreateProgress(m_MessageSendingRequest, 0, 0));
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}

bool CDownloadDialog::IsDownloadCancelled() const
{
    return m_bDownloadCancelled;
}

bool CDownloadDialog::IsDownloadError() const
{
    return m_bDownloadError;
}

void CDownloadDialog::DownloadCancel()
{
    DownloadStatusPtr cancel(DownloadStatus::CreateCanceled());
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(cancel)), 0L );

    if (! IsDownloadStarted())
    {
        ::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
    }
}

LRESULT CDownloadDialog::OnCloseDialog( WPARAM, LPARAM )
{
    if (IsDownloadStarted() 
        && ! IsDownloadCancelled() 
        && ! IsDownloadCompleted() 
        && ! IsDownloadError())
    {
        DownloadCancel();
        return 0;
    }

    OnOK();
    return 1;
}

bool CDownloadDialog::IsDownloadCompleted() const
{
    return m_bDownloadCompleted;
}

bool CDownloadDialog::IsDownloadStarted() const
{
    return m_bDownloadStarted;
}

void CDownloadDialog::DownloadingFile(const std::wstring& filename)
{
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_MessageDownloadingFile.c_str()), filename.c_str());
    DownloadStatusPtr status(DownloadStatus::CreateHelp(message));
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}

void CDownloadDialog::CopyingFile(const std::wstring& filename)
{
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_MessageCopyingFile.c_str()), filename.c_str());
    DownloadStatusPtr status(DownloadStatus::CreateHelp(message));
    ::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(status)), 0L );
}
