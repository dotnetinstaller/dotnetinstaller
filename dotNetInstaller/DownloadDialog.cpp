#include "stdafx.h"
#include "DownloadDialog.h"
#include "DniMessageBox.h"
#include "DownloadStatus.h"

#define WM_USER_SETSTATUSDOWNLOAD (WM_USER+1)
#define WM_USER_CLOSE_DIALOG (WM_USER+2)

IMPLEMENT_DYNAMIC(DownloadDialog, CDialog)

DownloadDialog::DownloadDialog(const DownloadGroupConfigurationPtr& p_Configuration, CWnd* pParent /*=NULL*/)
	: CDialog(DownloadDialog::IDD, pParent)
	, m_DownloadComponents(this, p_Configuration->downloadcomponents)
	, m_bDownloadCancelled(false)
	, m_bDownloadError(false)
	, m_bDownloadCompleted(false)
	, m_bAutoStartDownload(p_Configuration->auto_start)
	, m_Caption(p_Configuration->caption)
	, m_HelpMessage(p_Configuration->help_message)
	, m_hIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME))
	, m_HelpMessageDownloading(p_Configuration->downloading_message)
	, m_ButtonStartCaption(p_Configuration->start_caption)
	, m_ButtonCancelCaption(p_Configuration->cancel_caption)
	, m_bDownloadStarted(false)
{
	LOG(L"Opening download dialog: " << m_Caption);
}

void DownloadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HELP_DOWNLOAD, m_LabelHelpDownload);
	DDX_Control(pDX, IDC_STATUS, m_LabelStatus);
	DDX_Control(pDX, IDC_START, m_btStart);
	DDX_Control(pDX, IDC_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_PROGRESSDOWNLOAD, m_ProgressControl);
}

BEGIN_MESSAGE_MAP(DownloadDialog, CDialog)
	ON_BN_CLICKED(IDC_CANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_START, OnBnClickedStart)
	ON_MESSAGE(WM_USER_SETSTATUSDOWNLOAD, OnSetStatusDownload)
	ON_MESSAGE(WM_USER_CLOSE_DIALOG, OnCloseDialog)
	ON_WM_CLOSE()
	ON_COMMAND(IDCANCEL, OnBnClickedCancel)
	ON_COMMAND(IDOK, OnOK)
END_MESSAGE_MAP()

// DownloadDialog message handlers

BOOL DownloadDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Impostare l'icona per questa finestra di dialogo. Il framework non esegue questa operazione automaticamente
	//  se la finestra principale dell'applicazione non è una finestra di dialogo.
	SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
	SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.

	m_LabelHelpDownload.SetWindowText(m_HelpMessage.c_str());
	SetWindowText(m_Caption.c_str());
	m_btnCancel.SetWindowText(m_ButtonCancelCaption.c_str());
	m_btStart.SetWindowText(m_ButtonStartCaption.c_str());
	m_ProgressControl.SetRange(0,1000);
	m_LabelStatus.SetWindowText(TEXT(""));

	if (CurrentInstallUILevel.IsSilent())
	{
		m_btStart.EnableWindow(FALSE);
		m_btnCancel.EnableWindow(FALSE);
		OnBnClickedStart();
	}
	else if (m_bAutoStartDownload || ! m_DownloadComponents.IsDownloadRequired())
	{
		OnBnClickedStart();
	}

	return TRUE;
}

void DownloadDialog::OnOK()
{
	CDialog::OnOK();
}

void DownloadDialog::OnBnClickedCancel() //Cancel Button
{
	DownloadCancel();
}

void DownloadDialog::OnBnClickedStart()
{
	m_LabelHelpDownload.SetWindowText(m_HelpMessageDownloading.c_str());
	m_DownloadComponents.BeginExec();
	m_bDownloadStarted = true;
	m_btStart.EnableWindow(FALSE);
}

void DownloadDialog::OnClose( ) //Chiusura della finestra tramite X 
{
	OnCancel();	
	m_DownloadComponents.EndExec();
}

//WM_USER_SETSTATUSDOWNLOAD
// Messaggio custom per gestire la sincronizzazione e lo scambio di informazioni tra i due thread 
afx_msg LRESULT DownloadDialog::OnSetStatusDownload(WPARAM wParam, LPARAM lParam)
{
	DownloadStatusPtr l_Param(reinterpret_cast<DownloadStatus *>(wParam));

	if (l_Param->type == StatusType_Downloading)
	{
		if (l_Param->progress_max != 0)
		{
			m_ProgressControl.SetPos((int) ((double) l_Param->progress_current / (double) l_Param->progress_max * 1000.0));
		}
		else
		{
			m_ProgressControl.SetPos(0);
		}

		m_LabelStatus.SetWindowText(l_Param->status.c_str());
	}
	else if (l_Param->type == StatusType_Error) //ERROR
	{
		// download fails with E_ABORT on cancel
		if (! IsDownloadCancelled())
		{
			LOG(L"*** Download ERROR: " << l_Param->error);
			DniMessageBox::Show(l_Param->error, MB_OK|MB_ICONSTOP);
			m_bDownloadError = true;
		}

		::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
	}
	else if (l_Param->type == StatusType_Canceled) //CANCELED
	{
		LOG(L"*** Download CANCELED");
		m_bDownloadCancelled = true;
	}
	else if (l_Param->type == StatusType_Completed) //COMPLETED
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
void DownloadDialog::Status(ULONG p_progress_current, ULONG p_MaxProgress, const std::wstring& p_Description)
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM) (release(DownloadStatus::CreateProgress(p_Description, p_progress_current, p_MaxProgress))), 0L );
}

void DownloadDialog::DownloadComplete()
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(DownloadStatus::CreateComplete())), 0L );
}

void DownloadDialog::DownloadError(const std::wstring& p_Message)
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(DownloadStatus::CreateError(p_Message))), 0L );
}

bool DownloadDialog::IsDownloadCancelled() const
{
	return m_bDownloadCancelled;
}

bool DownloadDialog::IsDownloadError() const
{
	return m_bDownloadError;
}

void DownloadDialog::DownloadCancel()
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(release(DownloadStatus::CreateCanceled())), 0L );

	if (! IsDownloadStarted())
	{
		::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
	}
}

LRESULT DownloadDialog::OnCloseDialog( WPARAM, LPARAM )
{
	OnOK();
	return 1;
}

bool DownloadDialog::IsDownloadCompleted() const
{
	return m_bDownloadCompleted;
}

bool DownloadDialog::IsDownloadStarted() const
{
	return m_bDownloadStarted;
}
