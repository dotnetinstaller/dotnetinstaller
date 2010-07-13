// mfcliteDlg.h : header file
//

#include "htmlite.h"

#if !defined(AFX_MFCLITEDLG_H__08A2A577_FF62_4C6D_AC89_BCEE5005120E__INCLUDED_)
#define AFX_MFCLITEDLG_H__08A2A577_FF62_4C6D_AC89_BCEE5005120E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMfcliteDlg dialog

class CMfcliteDlg : public CDialog, 
  HTMLite, // - uses htmlayout in windowless form
  htmlayout::event_handler // - handles DOM event
{

// Construction
public:
  CMfcliteDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
  //{{AFX_DATA(CMfcliteDlg)
  enum { IDD = IDD_MFCLITE_DIALOG };
    // NOTE: the ClassWizard will add data members here
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMfcliteDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV support
  //}}AFX_VIRTUAL

  // HTMLite overridables
  virtual void handleRefreshArea( LPNMHL_REFRESH_AREA pn )
  {
    InvalidateRect(&pn->area,FALSE);
  }
  virtual void handleSetTimer( LPNMHL_SET_TIMER pn )
  {
    if( pn->elapseTime )
      SetTimer(pn->timerId,pn->elapseTime,0);
    else
      KillTimer(pn->timerId);
  }
  virtual void handleSetCursor( LPNMHL_SET_CURSOR pn );

  // htmlayout::event_handler overridables

  virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
  { 
    if( type == BUTTON_CLICK )
    {
      CString txt = htmlayout::dom::element(target).text();
      ::MessageBox(GetSafeHwnd(), txt ,TEXT("button click"), MB_OK);
    }
    return FALSE; 
  }


// Implementation
protected:
  HICON m_hIcon;

  virtual BOOL PreTranslateMessage( MSG* pMsg );
  void OnKeyDown( UINT code );
  void OnKeyUp( UINT code );
  void OnChar( UINT code );

  void TestBitmapRendering();

  // Generated message map functions
  //{{AFX_MSG(CMfcliteDlg)
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnDestroy();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg BOOL OnEraseBkgnd(CDC* pDC);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
  afx_msg void OnTimer(UINT nIDEvent);

  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};






//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLITEDLG_H__08A2A577_FF62_4C6D_AC89_BCEE5005120E__INCLUDED_)
