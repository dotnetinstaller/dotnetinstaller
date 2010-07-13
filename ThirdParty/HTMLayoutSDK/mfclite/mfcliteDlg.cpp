// mfcliteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfclite.h"
#include "mfcliteDlg.h"

#include "memdc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
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
    // No message handlers
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcliteDlg dialog

CMfcliteDlg::CMfcliteDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CMfcliteDlg::IDD, pParent), htmlayout::event_handler(HANDLE_ALL)
{
  //{{AFX_DATA_INIT(CMfcliteDlg)
    // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
  // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcliteDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CMfcliteDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMfcliteDlg, CDialog)
  //{{AFX_MSG_MAP(CMfcliteDlg)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_WM_DESTROY()
  ON_WM_SIZE()
  ON_WM_ERASEBKGND()
  ON_WM_LBUTTONDOWN()
  ON_WM_LBUTTONUP()
  ON_WM_MOUSEMOVE()
  ON_WM_LBUTTONDBLCLK()
  ON_WM_TIMER()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcliteDlg message handlers

BOOL CMfcliteDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    CString strAboutMenu;
    strAboutMenu.LoadString(IDS_ABOUTBOX);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);     // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon
  
  LPBYTE pb; DWORD cb;

  //const char* pdoc = "<html><frame src='http://terrainformatica.com/' /></html>";
  // if(HTMLite::load(LPCBYTE(pdoc),strlen(pdoc)))
  if(htmlayout::load_resource_data(L"main.html", pb, cb ))
  {
    HTMLite::load(pb,cb, L"http://www.terrainformatica.com/");
    // Attach event handler to the root element,
    // Use this if you want to handle DOM events.
    htmlayout::attach_event_handler(getRootElement(),this);  
    
    CRect rect;
    GetClientRect(&rect);
    HTMLite::measure(rect.Width(),rect.Height());
  }
  else
    HTMLite::load(L"http://terrainformatica.com/");
    //ASSERT(false);

  //HTMLiteSetDataReady(0,0,0,0);
  
  return TRUE;  // return TRUE  unless you set the focus to a control
}



void CMfcliteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    CDialog::OnSysCommand(nID, lParam);
  }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcliteDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    //CDialog::OnPaint();
    CRect rect;
    GetClientRect(&rect);
    CPaintDC dc(this); // device context for painting
    {
      CMemDC mdc(&dc);
      mdc.SelectObject(GetStockObject(LTGRAY_BRUSH));
      mdc.SelectObject(GetStockObject(WHITE_PEN));
      mdc.Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

      render(mdc, 0, 0, rect.Width(), rect.Height());
    }
  }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMfcliteDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

void CMfcliteDlg::OnDestroy() 
{
  // TODO: Add your message handler code here
  HTMLite::destroy();

  CDialog::OnDestroy();
}

void CMfcliteDlg::OnSize(UINT nType, int cx, int cy) 
{
  // CDialog::OnSize(nType, cx, cy);
  
  HTMLite::measure(cx,cy);
  Invalidate(FALSE);
}

BOOL CMfcliteDlg::OnEraseBkgnd(CDC* pDC) 
{
  return TRUE; // we paint everything.
}

void CMfcliteDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
    //CBitmap bmp;
    //CClientDC dc(this);
    //bmp.CreateCompatibleBitmap(&dc, 100, 100);
    //render(bmp, 0, 0, 100, 100);

    htmlayout::dom::element elRoot = getRootElement();
    htmlayout::dom::element elTarget = elRoot.find_first("div#test");

    elTarget.set_style_attribute("width", L"100px");

    //HTMLayoutUpdateElementEx(elTarget, REDRAW_NOW);


    /*htmlayout::dom::element elRoot = getRootElement();
    htmlayout::dom::element elTarget = elRoot.find_first("img");

    elTarget.set_attribute("border", L"1px solid red");

    HTMLayoutUpdateElementEx(elTarget, REDRAW_NOW);*/

    traverseMouseEvent(MOUSE_DOWN, point, MAIN_MOUSE_BUTTON, 0);      
    CDialog::OnLButtonDown(nFlags, point);
}

void CMfcliteDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
  traverseMouseEvent(MOUSE_UP, point, MAIN_MOUSE_BUTTON, 0);      
  CDialog::OnLButtonUp(nFlags, point);
}

void CMfcliteDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
  traverseMouseEvent(MOUSE_DCLICK, point, MAIN_MOUSE_BUTTON, 0);      
  CDialog::OnLButtonDblClk(nFlags, point);
}

void CMfcliteDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
  int nMouseButton = 0;
  //get the button state.  This only work with WM_MOUSEMOVE
  if    (nFlags & MK_LBUTTON)   nMouseButton = MAIN_MOUSE_BUTTON;
  else if (nFlags & MK_MBUTTON)   nMouseButton = PROP_MOUSE_BUTTON;
  else if (nFlags & MK_RBUTTON)   nMouseButton = MIDDLE_MOUSE_BUTTON;
  traverseMouseEvent(MOUSE_MOVE, point, nMouseButton, 0);       
  //CDialog::OnMouseMove(nFlags, point);
}

BOOL CMfcliteDlg::PreTranslateMessage( MSG* pMsg )
{
  if (pMsg->message == WM_KEYDOWN )
  {
    OnKeyDown( pMsg->wParam );
    return FALSE;
  }
  if (pMsg->message == WM_KEYUP )
  {
    OnKeyUp( pMsg->wParam );
    return FALSE;
  }
  if (pMsg->message == WM_CHAR )
  {
    OnChar( pMsg->wParam );
    return TRUE;
  }
  return CDialog::PreTranslateMessage( pMsg );
}

int GetAlts() 
{
  int alts = 0;
  if (GetAsyncKeyState(VK_SHIFT) < 0) alts |= SHIFT_KEY_PRESSED;
  if (GetAsyncKeyState(VK_CONTROL) < 0) alts |= CONTROL_KEY_PRESSED;
  if (GetAsyncKeyState(VK_MENU) < 0) alts |= ALT_KEY_PRESSED;
  return alts;
}

void CMfcliteDlg::OnKeyDown( UINT nChar )
{
  int alts = GetAlts();
  if( nChar == 'O' && (alts & CONTROL_KEY_PRESSED))
  {
    static char BASED_CODE szFilter[] = "HTML Files (*.htm, *.html)|*.htm;*.html|All Files (*.*)|*.*||";
    CFileDialog fod( TRUE, "htm", NULL, 0, szFilter);
    if(IDOK == fod.DoModal())
    {
      load(aux::a2w(fod.GetPathName()));
      return;
    }
  }
  if( nChar == 'T' && (alts & CONTROL_KEY_PRESSED))
  {
    TestBitmapRendering();
    return;
  }

  traverseKeyboardEvent(KEY_DOWN, nChar, alts);
}
void CMfcliteDlg::OnKeyUp( UINT nChar )
{
  traverseKeyboardEvent(KEY_UP, nChar, GetAlts());
}
void CMfcliteDlg::OnChar( UINT nChar )
{
  traverseKeyboardEvent(KEY_CHAR, nChar, GetAlts());
}

void CMfcliteDlg::handleSetCursor( LPNMHL_SET_CURSOR pn )
{
  static DWORD cursor_ids[] = 
  {
      (DWORD) IDC_ARROW,
      (DWORD) IDC_IBEAM,
      (DWORD) IDC_WAIT,
      (DWORD) IDC_CROSS,
      (DWORD) IDC_UPARROW,
      (DWORD) IDC_SIZENWSE,
      (DWORD) IDC_SIZENESW,
      (DWORD) IDC_SIZEWE,
      (DWORD) IDC_SIZENS,
      (DWORD) IDC_SIZEALL,
      (DWORD) IDC_NO,
      (DWORD) IDC_APPSTARTING,
      (DWORD) IDC_HELP,
      (DWORD) IDC_HAND,   
  };
  SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(cursor_ids[pn->cursorId])));
}

void CMfcliteDlg::OnTimer(UINT nIDEvent) 
{
  switch( nIDEvent )
  {
    case  TIMER_IDLE_ID: 
    case  TIMER_ANIMATION_ID:
      KillTimer(nIDEvent); // These are one shot timers so we need to kill them anyway.
                           // We must do it before traverseTimerEvent() call is it may want 
                           // to create timers with the same id.
      HTMLite::traverseTimerEvent(nIDEvent);
      break;
    default: // these are normal timers
      BOOL cont = HTMLite::traverseTimerEvent(nIDEvent);
      if (!cont) 
        KillTimer(nIDEvent);
      break;
  }
  //CDialog::OnTimer(nIDEvent);
}

void CMfcliteDlg::TestBitmapRendering(  )
{
      RECT rt;
      ::GetClientRect( GetSafeHwnd(), &rt);

      int width = rt.right - rt.left;
      int height = rt.bottom - rt.top;

      //============================================================ 
      //Creating compatible DC and a bitmap to render the image 
      BITMAPINFO bmp_info; 
      bmp_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
      bmp_info.bmiHeader.biWidth = width; 
      bmp_info.bmiHeader.biHeight = height; 
      bmp_info.bmiHeader.biPlanes = 1; 
      bmp_info.bmiHeader.biBitCount = 32; 
      bmp_info.bmiHeader.biCompression = BI_RGB; 
      bmp_info.bmiHeader.biSizeImage = 0; 
      bmp_info.bmiHeader.biXPelsPerMeter = 0; 
      bmp_info.bmiHeader.biYPelsPerMeter = 0; 
      bmp_info.bmiHeader.biClrUsed = 0; 
      bmp_info.bmiHeader.biClrImportant = 0; 

      HDC mem_dc = ::CreateCompatibleDC(NULL); 

      void* buf = 0; 

      HBITMAP bmp = ::CreateDIBSection( 
          mem_dc, 
          &bmp_info, 
          DIB_RGB_COLORS, 
          &buf, 
          0, 
          0 
      ); 

      // init the bitmap:
      unsigned int * pixel = (unsigned int *)buf; 
      for( int n = 0; n < width*height; ++n)
        *pixel++ = 0xffffffff; 

      // render current document to the bitmap
      render(bmp, 0, 0, width, height);
      
      HBITMAP temp = (HBITMAP)::SelectObject(mem_dc, bmp);

      HDC screenDC = ::GetDC(NULL);

      BLENDFUNCTION blend;
      blend.BlendOp = AC_SRC_OVER;
      blend.BlendFlags = 0;
      blend.AlphaFormat = AC_SRC_ALPHA;
      blend.SourceConstantAlpha = 255;

        ::AlphaBlend(
          screenDC,      
          0,      
          0,      
          width,  
          height, 
          mem_dc,
          0,
          0,     
          width, 
          height,
          blend
        );

        ::SelectObject(mem_dc, temp);
        ::DeleteObject(bmp);
        ::DeleteDC(mem_dc);
        ::ReleaseDC(NULL,screenDC);
               
}
