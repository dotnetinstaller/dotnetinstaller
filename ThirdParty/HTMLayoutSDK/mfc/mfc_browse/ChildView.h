// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__02672198_6D9B_441D_9F0C_E59127C99F4F__INCLUDED_)
#define AFX_CHILDVIEW_H__02672198_6D9B_441D_9F0C_E59127C99F4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "htmlayout.h"

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CLayoutView : public CWnd, 
                    public htmlayout::event_handler // handler of DOM events
{
// Construction
public:
  CLayoutView();

// Attributes
public:

// Operations
public:

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CLayoutView)
  protected:
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
  virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
  //}}AFX_VIRTUAL

// Implementation
public:
  virtual ~CLayoutView();

  // Load html from memory buffer
  bool LoadHtml(LPCBYTE pb, DWORD nBytes)
  {
    ASSERT(::IsWindow(m_hWnd));
    return ::HTMLayoutLoadHtml(m_hWnd, pb, nBytes) != 0;
  }

  bool LoadUrl(LPCWSTR url)
  {
    ASSERT(::IsWindow(m_hWnd));
    return ::HTMLayoutLoadFile(m_hWnd, url) != 0;
  }

  bool LoadHtmlResource(LPCTSTR name);


  // implement what is needed in your application

  LRESULT OnCreateControl( LPNMHL_CREATE_CONTROL nm) { return 0; }
  LRESULT OnControlCreated( LPNMHL_CREATE_CONTROL nm) { return 0; }
  LRESULT OnDestroyControl( LPNMHL_DESTROY_CONTROL nm) { return 0; }
  LRESULT OnLoadData( LPNMHL_LOAD_DATA nm) { return 0; }
  LRESULT OnDataLoaded( LPNMHL_DATA_LOADED nm) { return 0; }
  LRESULT OnDocumentComplete() { return 0; }
  LRESULT OnAttachBehavior( LPNMHL_ATTACH_BEHAVIOR nm );

  //htmlayout::event_handler overridables - handlers of "DOM events":

  // notification events from builtin behaviors - synthesized events: BUTTON_CLICK, VALUE_CHANGED
  // see enum BEHAVIOR_EVENTS
  virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
  { 
    if( type == BUTTON_CLICK ) 
    {
      htmlayout::dom::element button = target;
      CString button_id = button.get_attribute("id");
      if( button_id.IsEmpty() )
        button_id = button.text();
      MessageBox(button_id,TEXT("BUTTON_CLICK"));
      return TRUE;
    }
    return FALSE; 
  }



  // Generated message map functions
protected:
  //{{AFX_MSG(CLayoutView)
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__02672198_6D9B_441D_9F0C_E59127C99F4F__INCLUDED_)
