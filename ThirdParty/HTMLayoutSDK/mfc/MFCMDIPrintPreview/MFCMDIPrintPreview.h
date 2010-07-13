// MFCMDIPrintPreview.h : main header file for the MFCMDIPRINTPREVIEW application
//

#if !defined(AFX_MFCMDIPRINTPREVIEW_H__ACAB93A7_C222_4F7E_A715_80A7D3A70572__INCLUDED_)
#define AFX_MFCMDIPRINTPREVIEW_H__ACAB93A7_C222_4F7E_A715_80A7D3A70572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewApp:
// See MFCMDIPrintPreview.cpp for the implementation of this class
//

class CMFCMDIPrintPreviewApp : public CWinApp
{
public:
  CMFCMDIPrintPreviewApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMFCMDIPrintPreviewApp)
  public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

// Implementation
  //{{AFX_MSG(CMFCMDIPrintPreviewApp)
  afx_msg void OnAppAbout();
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMDIPRINTPREVIEW_H__ACAB93A7_C222_4F7E_A715_80A7D3A70572__INCLUDED_)
