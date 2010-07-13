// SimplePageSetup.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMDIPrintPreview.h"
#include "SimplePageSetup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimplePageSetup dialog


CSimplePageSetup::CSimplePageSetup(CWnd* pParent /*=NULL*/)
  : CDialog(CSimplePageSetup::IDD, pParent)
{
  //{{AFX_DATA_INIT(CSimplePageSetup)
  m_margin_bottom = 0.0;
  m_margin_left = 0.0;
  m_margin_right = 0.0;
  m_margin_top = 0.0;
  m_width = 0.0;
  m_height = 0.0;
  //}}AFX_DATA_INIT
}


void CSimplePageSetup::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CSimplePageSetup)
  DDX_Text(pDX, IDC_EDIT_BOTTOM, m_margin_bottom);
  DDX_Text(pDX, IDC_EDIT_LEFT, m_margin_left);
  DDX_Text(pDX, IDC_EDIT_RIGHT, m_margin_right);
  DDX_Text(pDX, IDC_EDIT_TOP, m_margin_top);
  DDX_Text(pDX, IDC_EDIT_WIDTH, m_width);
  DDX_Text(pDX, IDC_EDIT_HEIGHT, m_height);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSimplePageSetup, CDialog)
  //{{AFX_MSG_MAP(CSimplePageSetup)
    // NOTE: the ClassWizard will add message map macros here
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimplePageSetup message handlers
