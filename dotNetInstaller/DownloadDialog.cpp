// DownloadDialog.cpp : implementation file
//

#include "stdafx.h"

#include "dotNetInstaller.h"

#include "DownloadDialog.h"
#include "downloaddialog.h"
#include "InstallerLog.h"
#include "DniMessageBox.h"
#include "SilentInstall.h"

#define WM_USER_SETSTATUSDOWNLOAD (WM_USER+1)


namespace DVLib
{
	// DownloadDialog dialog

	IMPLEMENT_DYNAMIC(DownloadDialog, CDialog)
	DownloadDialog::DownloadDialog(const DownloadGroupConfiguration & p_Configuration,
							CWnd* pParent /*=NULL*/)
		: CDialog(DownloadDialog::IDD, pParent),
		m_bCancelDownload(false),
		m_hDownloadThread(INVALID_HANDLE_VALUE),
		m_bDownloadCompleted(false)
	{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

		m_Caption = p_Configuration.Caption;
		m_HelpMessage = p_Configuration.HelpMessage;
		m_HelpMessageDownloading = p_Configuration.HelpMessageDownloading;
		m_ButtonStartCaption = p_Configuration.ButtonStartCaption;
		m_ButtonCancelCaption = p_Configuration.ButtonCancelCaption;
		m_Components.Copy(p_Configuration.Components);
		m_bAutoStartDownload = p_Configuration.AutoStartDownload;

		ApplicationLog.Write( TEXT("Opening download dialog for: "), m_Caption);
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
		DDX_Control(pDX, IDC_CANCEL, m_btCancel);
		DDX_Control(pDX, IDC_PROGRESSDOWNLOAD, m_ProgressControl);
	}


	BEGIN_MESSAGE_MAP(DownloadDialog, CDialog)
		ON_BN_CLICKED(IDC_CANCEL, OnBnClickedCancel)
		ON_BN_CLICKED(IDC_START, OnBnClickedStart)
		ON_MESSAGE(WM_USER_SETSTATUSDOWNLOAD, OnSetStatusDownload)
		ON_WM_CLOSE()
		ON_COMMAND(IDCANCEL, OnCancel)
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
		m_btCancel.SetWindowText(m_ButtonCancelCaption);
		m_btStart.SetWindowText(m_ButtonStartCaption);
		m_ProgressControl.SetRange(0,1000);
		m_LabelStatus.SetWindowText(TEXT(""));
		//m_ProgressControl.SetStep

		if (QuietInstall.IsSilent())
		{
			m_btStart.EnableWindow(FALSE);
			m_btCancel.EnableWindow(FALSE);
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
		WaitDownloadThread();

		CDialog::OnOK();
	}

	void DownloadDialog::OnCancel() //ESC Key
	{
		//n.b. Sulla pressione del tasto cancel non viene chiamato OnClose e quindi devo anche in questo caso verificare il thread
		m_bCancelDownload = true;

		WaitDownloadThread();

		CDialog::OnCancel();
	}

	void DownloadDialog::OnBnClickedCancel() //Cancel Button
	{
		OnCancel();
	}

	void DownloadDialog::OnBnClickedStart()
	{
		ApplicationLog.Write( TEXT("Starting download thread ..."));

		m_LabelHelpDownload.SetWindowText(m_HelpMessageDownloading);

		CWinThread * l_Thread = AfxBeginThread(DownloadComponentsThread, (IDownloadCallback*)this);
		m_hDownloadThread = l_Thread->m_hThread;

		m_btStart.EnableWindow(FALSE);
	}

	void DownloadDialog::WaitDownloadThread()
	{
		if (m_hDownloadThread!=INVALID_HANDLE_VALUE)
		{
			WaitForSingleObject(m_hDownloadThread, 20000); //wait for 20 seconds
			m_hDownloadThread = INVALID_HANDLE_VALUE;
		}
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
				ApplicationLog.Write( TEXT("--Download ERROR"));

				DniSilentMessageBox(l_Param->Error, MB_OK|MB_ICONSTOP);

				DownloadStatusParam::Free(l_Param);
				OnCancel();
			}
			else if (l_Param->Type == StatusType_Canceled) //CANCELED
			{
				ApplicationLog.Write( TEXT("--Download CANCELED"));

				DownloadStatusParam::Free(l_Param);
				OnCancel();
			}
			else if (l_Param->Type == StatusType_Completed) //COMPLETED
			{
				ApplicationLog.Write( TEXT("--Download OK"));

				m_bDownloadCompleted = true; //Download OK

				DownloadStatusParam::Free(l_Param);
				OnOK();
			}
		}
		catch(...)
		{
			DniSilentMessageBox(TEXT("Failed to read OnSetStatusDownload parameters"), MB_OK|MB_ICONSTOP);
			OnCancel();
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
		return m_bCancelDownload;
	}
	void DownloadDialog::CanceledByTheUser()
	{
		::PostMessage(m_hWnd, WM_USER_SETSTATUSDOWNLOAD, (WPARAM)(DownloadStatusParam::CreateCanceled()), 0L );
	}
	DownloadComponentInfoVector * DownloadDialog::GetComponents()
	{
		return &m_Components;
	}
}