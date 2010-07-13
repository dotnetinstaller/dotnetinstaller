// dibexView.h : interface of the CDibexView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBEXVIEW_H__AEFF779F_AB31_4D31_98B7_E59BE5A0BF7D__INCLUDED_)
#define AFX_DIBEXVIEW_H__AEFF779F_AB31_4D31_98B7_E59BE5A0BF7D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "htmlayout_x.h"

extern dibex img;

class CDibexView : public CWindowImpl<CDibexView>
{
public:
  DECLARE_WND_CLASS(NULL)

  CDibexView();

  BOOL PreTranslateMessage(MSG* pMsg);

  BEGIN_MSG_MAP(CDibexView)
    MESSAGE_HANDLER(WM_PAINT, OnPaint)
    MESSAGE_HANDLER(WM_ERASEBKGND, OnErase)
  END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//  LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//  LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//  LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

  LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
  LRESULT OnErase(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
  {
    return TRUE;
  }
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIBEXVIEW_H__AEFF779F_AB31_4D31_98B7_E59BE5A0BF7D__INCLUDED_)
