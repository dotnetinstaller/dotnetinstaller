// mfclite.h : main header file for the MFCLITE application
//

#if !defined(AFX_MFCLITE_H__E42A0120_30D1_49EA_96BC_0067A0B9DC8C__INCLUDED_)
#define AFX_MFCLITE_H__E42A0120_30D1_49EA_96BC_0067A0B9DC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"   // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfcliteApp:
// See mfclite.cpp for the implementation of this class
//

class CMfcliteApp : public CWinApp
{
public:
  CMfcliteApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMfcliteApp)
  public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

// Implementation

  //{{AFX_MSG(CMfcliteApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLITE_H__E42A0120_30D1_49EA_96BC_0067A0B9DC8C__INCLUDED_)
