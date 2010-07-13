// MFCMDIPrintPreviewView.h : interface of the CMFCMDIPrintPreviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCMDIPRINTPREVIEWVIEW_H__B3A26D24_FEE5_4A40_A75B_22289D2D6C8A__INCLUDED_)
#define AFX_MFCMDIPRINTPREVIEWVIEW_H__B3A26D24_FEE5_4A40_A75B_22289D2D6C8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
#include <assert.h>
// Done in Project Settings ->> #define PLAIN_API_ONLY //to exclude all kind of crap from being included into the build
#include "..\\..\\include\\htmlayout.h"
#include "..\\..\\include\\htmprint.h"


class CMFCMDIPrintPreviewView : public CView
{
protected: // create from serialization only
  CMFCMDIPrintPreviewView();
  DECLARE_DYNCREATE(CMFCMDIPrintPreviewView)

// Attributes
public:
  CMFCMDIPrintPreviewDoc* GetDocument();
protected:
  PrintEx* m_pPrinter; //HTMLLayout print manager
  CRect m_rcPrintArea; //print area in printer device units
  int m_scaled_width;  //scaled width of the print area for 1:1 scale

  double m_margin_left; //page margins in inches
  double m_margin_top;
  double m_margin_right;
  double m_margin_bottom;

  CSize  m_measured;

 

// Operations
public:
  bool LoadUrl(LPCTSTR url);

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMFCMDIPrintPreviewView)
  public:
  virtual void OnDraw(CDC* pDC);  // overridden to draw this view
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
  virtual void OnInitialUpdate();
  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  protected:
  virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
  virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
  //}}AFX_VIRTUAL

// Implementation
public:
  virtual ~CMFCMDIPrintPreviewView();
#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
  //{{AFX_MSG(CMFCMDIPrintPreviewView)
  afx_msg void OnSize(UINT nType, int cx, int cy);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCMDIPrintPreviewView.cpp
inline CMFCMDIPrintPreviewDoc* CMFCMDIPrintPreviewView::GetDocument()
   { return (CMFCMDIPrintPreviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMDIPRINTPREVIEWVIEW_H__B3A26D24_FEE5_4A40_A75B_22289D2D6C8A__INCLUDED_)
