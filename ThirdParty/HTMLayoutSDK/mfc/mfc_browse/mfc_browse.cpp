// mfc_browse.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "mfc_browse.h"
#include "childview.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp

BEGIN_MESSAGE_MAP(CMfc_browseApp, CWinApp)
  //{{AFX_MSG_MAP(CMfc_browseApp)
  ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp construction

CMfc_browseApp::CMfc_browseApp()
{
  // TODO: add construction code here,
  // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMfc_browseApp object

CMfc_browseApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp initialization

BOOL CMfc_browseApp::InitInstance()
{
  AfxEnableControlContainer();

  // Standard initialization
  // If you are not using these features and wish to reduce the size
  //  of your final executable, you should remove from the following
  //  the specific initialization routines you do not need.

#ifdef _AFXDLL
  Enable3dControls();     // Call this when using MFC in a shared DLL
#else
  Enable3dControlsStatic(); // Call this when linking to MFC statically
#endif

  // Change the registry key under which our settings are stored.
  // TODO: You should modify this string to be something appropriate
  // such as the name of your company or organization.
  SetRegistryKey(_T("Local AppWizard-Generated Applications"));


  // To create the main window, this code creates a new frame window
  // object and then sets it as the application's main window object.

  CMainFrame* pFrame = new CMainFrame;
  m_pMainWnd = pFrame;

  // create and load the frame with its resources

  pFrame->LoadFrame(IDR_MAINFRAME,
    WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
    NULL);




  // The one and only window has been initialized, so show and update it.
  pFrame->ShowWindow(SW_SHOW);
  pFrame->UpdateWindow();

  return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp message handlers





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{

  CLayoutView m_html;

public:
  CAboutDlg();

// Dialog Data
  //{{AFX_DATA(CAboutDlg)
  enum { IDD = IDD_ABOUTBOX };
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CAboutDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  //{{AFX_MSG(CAboutDlg)
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
  //{{AFX_DATA_INIT(CAboutDlg)
  //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CAboutDlg)
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
  //{{AFX_MSG_MAP(CAboutDlg)
  ON_WM_CREATE()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMfc_browseApp::OnAppAbout()
{
  CAboutDlg aboutDlg;
  aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp message handlers


int CAboutDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  if (CDialog::OnCreate(lpCreateStruct) == -1)
    return -1;

  CRect cr;
  GetClientRect(&cr);
  cr.bottom -= 40;
  
  m_html.Create(NULL, NULL, WS_CHILD | WS_VISIBLE, cr, this, 0, NULL);
  m_html.LoadHtmlResource(TEXT("ABOUT"));
    
  return 0;
}
