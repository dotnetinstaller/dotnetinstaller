// maindlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINDLG_H__1896D540_0D52_4978_83FB_4934B1A79653__INCLUDED_)
#define AFX_MAINDLG_H__1896D540_0D52_4978_83FB_4934B1A79653__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "atlprint.h"

#include "html_canvas.h"

class CMainDlg : public CDialogImpl<CMainDlg>, public CUpdateUI<CMainDlg>,
    public CMessageFilter, public CIdleHandler
{
public:
  enum { IDD = IDD_MAINDLG };
  CString m_fileName;
  html_canvas hcanvas;

  virtual BOOL PreTranslateMessage(MSG* pMsg)
  {
    return IsDialogMessage(pMsg);
  }

  virtual BOOL OnIdle()
  {
    return FALSE;
  }

  BEGIN_UPDATE_UI_MAP(CMainDlg)
  END_UPDATE_UI_MAP()

  BEGIN_MSG_MAP(CMainDlg)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
    COMMAND_ID_HANDLER(IDC_OPEN, OnOpen)
    COMMAND_ID_HANDLER(IDC_MINUS, OnMinus)
    COMMAND_ID_HANDLER(IDC_PLUS, OnPlus)
    COMMAND_ID_HANDLER(IDC_PRINT, OnPrint)
    COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    MESSAGE_HANDLER(WM_PAINT, OnPaint)
    MESSAGE_HANDLER(WM_SIZE, OnSize)
    COMMAND_HANDLER(IDC_LOAD_URL, BN_CLICKED, OnClickedLoadUrl)
    COMMAND_HANDLER(IDC_EMF, BN_CLICKED, OnClickedEmf)
  END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//  LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//  LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//  LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

  LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
  {
    // center the dialog on the screen
    CenterWindow();

    // set icons
    HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
      IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
    SetIcon(hIcon, TRUE);
    HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
      IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
    SetIcon(hIconSmall, FALSE);

    // register object for message filtering and idle updates
    CMessageLoop* pLoop = _Module.GetMessageLoop();
    ATLASSERT(pLoop != NULL);
    pLoop->AddMessageFilter(this);
    pLoop->AddIdleHandler(this);

    UIAddChildWindowContainer(m_hWnd);

    DWORD exstyle = GetWindowLong(GWL_EXSTYLE);
    SetWindowLong(GWL_EXSTYLE,exstyle | WS_EX_COMPOSITED);

    const char* welcome = "<html><body style='text-align:center;vertical-align:middle'>Welcome to the PrintEx</body></html>";

    hcanvas.load_html((LPCBYTE)welcome, strlen(welcome));

    return TRUE;
  }

  LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CAboutDlg dlg;
    dlg.DoModal();
    return 0;
  }

  LRESULT OnOpen(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CFileDialog dlg(TRUE, "htm", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
      "HTML Files (*.htm,*.html)\0*.HTM;*.HTML\0"
      "All Files (*.*)\0*.*\0", m_hWnd);
    if(dlg.DoModal() == IDOK)
    {
      if(!hcanvas.load_html(dlg.m_szFileName))
      {
        AtlMessageBox(m_hWnd,TEXT("Unable to load your file"));
        return false;
      }
      m_fileName = dlg.m_szFileName;
      InvalidateRect(NULL);
    }
    return 0;
  }

  /*

  LRESULT OnPrint(WORD , WORD wID, HWND , BOOL& )
  {
    CPrintDialog dlg;
    if(dlg.GetDefaults())
    {
      html_canvas hpcanvas;
      if(!hpcanvas.load_html(m_fileName))
      {
        AtlMessageBox(m_hWnd,TEXT("Unable to load your file"));
        return 0;
      }
      CPrinterDC dc;
      RECT contentRc;
      contentRc.left = 0;
      contentRc.top = 0;
      contentRc.right = dc.GetDeviceCaps(PHYSICALWIDTH);
      contentRc.bottom = dc.GetDeviceCaps(PHYSICALHEIGHT);

      SIZE margins; margins.cx = 1000; // 1 cm
                    margins.cy = 1000; // 1 cm

      dc.HIMETRICtoDP(&margins);

      contentRc.left += margins.cx;
      contentRc.top += margins.cy;
      contentRc.right -= margins.cx;
      contentRc.bottom -= margins.cy;

      dc.StartDoc(TEXT("PrintEx HTML"));
      
      do {
        dc.StartPage();
        hpcanvas.render(dc,contentRc);
        dc.EndPage();
      } while ( hpcanvas.inc_page_no(1) );

      dc.EndDoc();
    }
    return 0;
  }
*/

  LRESULT OnPrint(WORD , WORD wID, HWND , BOOL& )
  {
    CPrintDialog dlg;
    if(dlg.GetDefaults())
    {
      html_canvas hpcanvas;
      if(!hpcanvas.load_html(m_fileName))
      {
        AtlMessageBox(m_hWnd,TEXT("Unable to load your file"));
        return 0;
      }
      CPrinterDC dc;

      SIZE pagePhysicalSize;
      pagePhysicalSize.cx = dc.GetDeviceCaps(PHYSICALWIDTH);
      pagePhysicalSize.cy = dc.GetDeviceCaps(PHYSICALHEIGHT);

      RECT contentRc;
      contentRc.left = 0;
      contentRc.top = 0;
      contentRc.right = pagePhysicalSize.cx;
      contentRc.bottom = pagePhysicalSize.cy;

      SIZE pageLogicalSize = pagePhysicalSize; // himetric
      dc.DPtoHIMETRIC(&pageLogicalSize);

      // margins
      SIZE margins; margins.cx = 1000; // 1 cm, himetric
                    margins.cy = 1000; // 1 cm, himetric

      dc.HIMETRICtoDP(&margins);

      contentRc.left += margins.cx;
      contentRc.top += margins.cy;
      contentRc.right -= margins.cx;
      contentRc.bottom -= margins.cy;

      // scale factor calculation
      // 1 inch = 2.54 centimeters
      // 1 html-px = 1/96 inch
      // 1 html-px = 
      int printingAreaWidthHM = pageLogicalSize.cx - 2000; // 2 cm margin, see above
      int printingAreaWidthHTMLPx = int((double(printingAreaWidthHM) / 2540.0) * 96.0);

      dc.StartDoc(TEXT("PrintEx HTML"));
      
      do {
        dc.StartPage();
        hpcanvas.render(dc,contentRc, printingAreaWidthHTMLPx);
        dc.EndPage();
      } while ( hpcanvas.inc_page_no(1) ); 

      dc.EndDoc();
    }
    return 0;
  }

  LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CloseDialog(wID);
    return 0;
  }

  void CloseDialog(int nVal)
  {
    DestroyWindow();
    ::PostQuitMessage(nVal);
  }

  LRESULT OnMinus(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    hcanvas.inc_page_no(-1); 
    InvalidateRect(NULL);
    return 0;
  }

  LRESULT OnPlus(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    hcanvas.inc_page_no(+1); 
    InvalidateRect(NULL);
    return 0;
  }
  LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {

    LRESULT lr = DefWindowProc();

    CRect rc;
    GetClientRect(&rc);
    rc.left += 100;
    rc.top += 54;
    rc.bottom -= 10;
    rc.right -= 10;

    if(rc.left > rc.right || rc.top > rc.bottom) 
      return lr;

    CPen pen;
    pen.CreatePen(PS_SOLID, 0, ::GetSysColor(COLOR_WINDOWFRAME));
    CBrush brush;
    brush.CreateSolidBrush(::GetSysColor(COLOR_3DFACE));

    {
      CPaintDC dc(m_hWnd);
      // drawing background
      HPEN hpenOld = dc.SelectPen(pen);
      HBRUSH hbrushOld = dc.SelectBrush(brush);
      dc.Rectangle(rc);
      dc.SelectPen(hpenOld);
      dc.SelectBrush(hbrushOld);

      rc.DeflateRect(1,1); // borders!

      hcanvas.render(dc,rc);

    }
    return lr;
  }
  LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    InvalidateRect(NULL);
    return 0;
  }
  LRESULT OnClickedLoadUrl(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    // TODO : Add Code for control notification handler.
    TCHAR buffer[MAX_PATH];
    GetDlgItemText(IDC_URL,buffer,MAX_PATH);
    hcanvas.load_html(buffer);
    return 0;
  }
  LRESULT OnClickedEmf(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    CPrintDialog dlg;
    if(dlg.GetDefaults())
    {
      html_canvas hpcanvas;
      if(!hpcanvas.load_html(m_fileName))
      {
        AtlMessageBox(m_hWnd,TEXT("Unable to load your file"));
        return 0;
      }
      // we will use PrinterDC as a prototype of EMF dc 
      CPrinterDC dc;

      // page rect (viewport rect) in device coordinates
      RECT contentRc;
      contentRc.left = 0;
      contentRc.top = 0;
      contentRc.right = dc.GetDeviceCaps(PHYSICALWIDTH);
      contentRc.bottom = dc.GetDeviceCaps(PHYSICALHEIGHT);

      SIZE margins; margins.cx = 1000; // 1 cm
                    margins.cy = 1000; // 1 cm
      dc.HIMETRICtoDP(&margins); 

      // EnhMetaFile accepts Rect in HiMetric units only
      // so we need to translate our content rect into HIMETRICs
      SIZE szHimetric;
      szHimetric.cx = contentRc.right;
      szHimetric.cy = contentRc.bottom;
      dc.DPtoHIMETRIC(&szHimetric);

      RECT contentRcHiMetric;
      contentRcHiMetric.left = 0;
      contentRcHiMetric.top = 0;
      contentRcHiMetric.right = szHimetric.cx;
      contentRcHiMetric.bottom = szHimetric.cy;

      // done: contentRcHiMetric is in Himetrics 
      // contentRc is in Device units 

      CEnhMetaFileDC emfdc(dc, TEXT("c:/test.emf"), &contentRcHiMetric, TEXT("HTMLayout"));

      // deflate contentRc by margins
      contentRc.left += margins.cx;
      contentRc.top += margins.cy;
      contentRc.right -= margins.cx;
      contentRc.bottom -= margins.cy;

      // and finally print first page      
      hpcanvas.render(emfdc,contentRc);
    }
    AtlMessageBox(m_hWnd,TEXT("c:/test.emf has been created"));
    return 0;
  }
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__1896D540_0D52_4978_83FB_4934B1A79653__INCLUDED_)
