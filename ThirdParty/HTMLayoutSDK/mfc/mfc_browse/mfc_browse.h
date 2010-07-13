// mfc_browse.h : main header file for the MFC_BROWSE application
//

#if !defined(AFX_MFC_BROWSE_H__C3B02B37_E096_46EC_B1BC_D9F13DDC8584__INCLUDED_)
#define AFX_MFC_BROWSE_H__C3B02B37_E096_46EC_B1BC_D9F13DDC8584__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc_browseApp:
// See mfc_browse.cpp for the implementation of this class
//

class CMfc_browseApp : public CWinApp
{
public:
  CMfc_browseApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMfc_browseApp)
  public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

// Implementation

public:
  //{{AFX_MSG(CMfc_browseApp)
  afx_msg void OnAppAbout();
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


extern CMfc_browseApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_BROWSE_H__C3B02B37_E096_46EC_B1BC_D9F13DDC8584__INCLUDED_)
