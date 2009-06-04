#include "stdafx.h"
#include "DownloadDialog.h"
#include "Tools/Format.h"

#define WM_USER_SETSTATUSDOWNLOAD (WM_USER+1)
#define WM_USER_CLOSE_DIALOG (WM_USER+2)

IMPLEMENT_DYNAMIC(DownloadDialog, CDialog)
	DownloadDialog::DownloadDialog(const DownloadGroupConfiguration & p_Configuration, CWnd* pParent /*=NULL*/)
	: CDialog(DownloadDialog::IDD, pParent)
	, m_bCancelOrErrorDownload(false)
	, m_bDownloadCompleted(false)
	, m_pDownloadThread(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_Caption = p_Configuration.Caption;
	m_HelpMessage = p_Configuration.HelpMessage;
	m_HelpMessageDownloading = p_Configuration.HelpMessageDownloading;
	m_ButtonStartCaption = p_Configuration.ButtonStartCaption;
	m_ButtonCancelCaption = p_Configuration.ButtonCancelCaption;
	m_Components.Copy(p_Configuration.Components);
	m_bAutoStartDownload = p_Configuration.AutoStartDownload;

	ApplicationLog.Write( TEXT("Opening Download Dialog: "), m_Caption);
}

DownloadDialog::~DownloadDialog()
{
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

	m_LabelHelpDownload.SetWindowText(m_HelpMessage);
	SetWindowText(m_Caption);
	m_btnCancel.SetWindowText(m_ButtonCancelCaption);
	m_btStart.SetWindowText(m_ButtonStartCaption);
	m_ProgressControl.SetRange(0,1000);
	m_LabelStatus.SetWindowText(TEXT(""));

	if (CurrentInstallUILevel.IsSilent())
	{
		m_btStart.EnableWindow(FALSE);
		m_btnCancel.EnableWindow(FALSE);
		OnBnClickedStart();
	}
	else if (m_bAutoStartDownload)
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
	CanceledByTheUser();
}

void DownloadDialog::OnBnClickedStart()
{
	ApplicationLog.Write( TEXT("Starting download thread"));

	m_LabelHelpDownload.SetWindowText(m_HelpMessageDownloading);
	m_pDownloadThread = AfxBeginThread(ThreadProc, this);
	m_btStart.EnableWindow(FALSE);
}

void DownloadDialog::OnClose( ) //Chiusura della finestra tramite X 
{
	OnCancel();
}

//WM_USER_SETSTATUSDOWNLOAD
// Messaggio custom per gestire la sincronizzazione e lo scambio di informazioni tra i due thread 
afx_msg LRESULT DownloadDialog::OnSetStatusDownload(WPARAM wParam, LPARAM lParam)
{
	try
	{
		m_bDownloadCompleted = false; //flag per indicare al chiamante di questa finestra che il donload ha avuto successo

		DownloadStatusParam * l_Param = (DownloadStatusParam*)wParam;

		if (l_Param->Type == StatusType_Downloading)
		{
			if (l_Param->ProgressMax!=0)
				m_ProgressControl.SetPos( (int)((double)l_Param->CurrentProgress/(double)l_Param->ProgressMax*1000.0));
			else
				m_ProgressControl.SetPos( 0 );
			m_LabelStatus.SetWindowText(l_Param->Status);
			DownloadStatusParam::Free(l_Param);
		}
		else if (l_Param->Type == StatusType_Error) //ERROR
		{
			ApplicationLog.Write( TEXT("***Download ERROR: "), l_Param->Error);
			DniSilentMessageBox(l_Param->Error, MB_OK|MB_ICONSTOP);
			m_bCancelOrErrorDownload = true;
			DownloadStatusParam::Free(l_Param);
		}
		else if (l_Param->Type == StatusType_Canceled) //CANCELED
		{
			ApplicationLog.Write( TEXT("***Download CANCELED"));
			m_bCancelOrErrorDownload = true;
			DownloadStatusParam::Free(l_Param);
		}
		else if (l_Param->Type == StatusType_Completed) //COMPLETED
		{
			ApplicationLog.Write( TEXT("---Download OK"));
			m_bDownloadCompleted = true; //Download OK
			DownloadStatusParam::Free(l_Param);
		}
	}
	catch(...)
	{
		m_bCancelOrErrorDownload = true;
		DniSilentMessageBox(TEXT("Failed to read OnSetStatusDownload parameters"), MB_OK|MB_ICONSTOP);			
	}
	return 0;
}

//ATTENZIONE questi metodo sono chiamati da un altro thread e quindi non devono accedere direttamente alla classe
// Uso la funzione PostMessage che non blocca il thread ma aggiunge una messaggio alla coda dei messaggi
//  dovendogli però passare dei puntatori devo fare la new qui e poi la delete quando leggo il puntatore
//  nella OnSetStatusDownload.
//IDownloadCallback
void DownloadDialog::Status(ULONG p_CurrentProgress, ULONG p_MaxProgress, LPCTSTR p_Description)
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(DownloadStatusParam::CreateProgress(p_Description, p_CurrentProgress, p_MaxProgress)), 0L );
}

void DownloadDialog::DownloadComplete()
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(DownloadStatusParam::CreateComplete() ), 0L );
}

void DownloadDialog::DownloadError(LPCTSTR p_Message)
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(DownloadStatusParam::CreateError(p_Message)), 0L );
}

bool DownloadDialog::WantToStop()
{
	return m_bCancelOrErrorDownload;
}

void DownloadDialog::CanceledByTheUser()
{
	::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(DownloadStatusParam::CreateCanceled()), 0L );

	if (! IsDownloadStarted())
	{
		::PostMessage(GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
	}
}

DownloadComponentInfoVector * DownloadDialog::GetComponents()
{
	return &m_Components;
}

LRESULT DownloadDialog::OnCloseDialog( WPARAM, LPARAM )
{
	OnOK();
	return 1;
}

UINT DownloadDialog::ThreadProc(LPVOID pParam)
{
	DownloadDialog * dlg = (DownloadDialog *) pParam;
	DownloadComponents(dlg);
	::PostMessage(dlg->GetSafeHwnd(), WM_USER_CLOSE_DIALOG, 0, 0);
	return 0;
}

void DownloadDialog::CopyFromSourcePath()
{
	for (int i = 0; i < m_Components.GetCount(); i++)
	{
		DownloadComponent l_Component(this, &(m_Components.GetAt(i)), i + 1, (int) m_Components.GetCount());
		if (l_Component.IsCopyRequired())
		{
			l_Component.CopyFromSourcePath();
		}
	}
}

bool DownloadDialog::IsCopyRequired()
{
	for (int i = 0; i < m_Components.GetCount(); i++)
	{
		DownloadComponent l_Component(this, &(m_Components.GetAt(i)), i + 1, (int) m_Components.GetCount());
		bool l_CopyRequired = l_Component.IsCopyRequired();
				
		CString l_destinationFullFileName = l_Component.GetDestinationFileName();
		ApplicationLog.Write( TEXT("DestinationFullFileName: "), l_destinationFullFileName);
		ApplicationLog.Write( TEXT("FileExists: "), FileExists(l_destinationFullFileName) ? TEXT("True") : TEXT("False") );
		ApplicationLog.Write( TEXT("Copy: "), l_CopyRequired ? TEXT("True") : TEXT("False") );

		if (l_CopyRequired)
		{
			return true;
		}
	}

	return false;
}

bool DownloadDialog::IsDownloadRequired()
{
	for (int i = 0; i < m_Components.GetCount(); i++)
	{
		DownloadComponent l_Component(this, &(m_Components.GetAt(i)), i + 1, (int) m_Components.GetCount());
		bool l_DownloadRequired = l_Component.IsDownloadRequired();
				
		CString l_destinationFullFileName = l_Component.GetDestinationFileName();
		ApplicationLog.Write( TEXT("DestinationFullFileName: "), l_destinationFullFileName);
		ApplicationLog.Write( TEXT("FileExists: "), FileExists(l_destinationFullFileName) ? TEXT("True") : TEXT("False") );
		ApplicationLog.Write( TEXT("Download: "), l_DownloadRequired ? TEXT("True") : TEXT("False") );

		if (l_DownloadRequired)
		{
			return true;
		}
	}

	return false;
}

void DownloadDialog::DownloadComponents(IDownloadCallback * p_Callback)
{
	CString l_tmpLastComponent = TEXT("-");
	try
	{
		DownloadComponentInfoVector * l_List = p_Callback->GetComponents();
		for (int i = 0; i < l_List->GetCount(); i++)
		{
			//verifico se l'utente ha premuto cancel
			if (p_Callback->WantToStop())
			{
				p_Callback->CanceledByTheUser();
				return;
			}

			l_tmpLastComponent = l_List->GetAt(i).ComponentName;

			//Download del componente
			DownloadComponent l_Component(p_Callback, &(l_List->GetAt(i)), i+1, (int)l_List->GetCount() );
			l_Component.StartDownload();

			//verifico se l'utente ha premuto cancel
			if (l_Component.IsCanceledByTheUser())
			{
				p_Callback->CanceledByTheUser();
				return;
			}
		}

		p_Callback->DownloadComplete();
	}
	catch(std::exception& ex)
	{
	    p_Callback->DownloadError(DVLib::string2Tstring(ex.what()).c_str());
	}
}
