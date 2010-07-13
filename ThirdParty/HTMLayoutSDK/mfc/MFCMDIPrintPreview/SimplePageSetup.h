#if !defined(AFX_SIMPLEPAGESETUP_H__89780FA7_C5FA_4D82_87B3_153FEA472AD2__INCLUDED_)
#define AFX_SIMPLEPAGESETUP_H__89780FA7_C5FA_4D82_87B3_153FEA472AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SimplePageSetup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimplePageSetup dialog

class CSimplePageSetup : public CDialog
{
// Construction
public:
  CSimplePageSetup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
  //{{AFX_DATA(CSimplePageSetup)
  enum { IDD = IDD_SIMPLE_PAGE_SETUP };
  double  m_margin_bottom;
  double  m_margin_left;
  double  m_margin_right;
  double  m_margin_top;
  double  m_width;
  double  m_height;
  //}}AFX_DATA


// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CSimplePageSetup)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:

  // Generated message map functions
  //{{AFX_MSG(CSimplePageSetup)
    // NOTE: the ClassWizard will add member functions here
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLEPAGESETUP_H__89780FA7_C5FA_4D82_87B3_153FEA472AD2__INCLUDED_)
