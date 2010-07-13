// WizardDlg.h : header file
//

#include "HTMPanel.h"

#pragma once


// CWizardDlg dialog
class CWizardDlg : public CDialog
{
// Construction
public:
  CWizardDlg(CWnd* pParent = NULL); // standard constructor

// Dialog Data
  enum { IDD = IDD_WIZARD_DIALOG };

  protected:
  virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV support


// Implementation
protected:
  HICON           m_hIcon;
  CHTMPanel       m_layout;

  // Generated message map functions
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnSize(UINT nType, int cx, int cy);

  void UpdateLayout() 
  {
    if(::IsWindow(m_hWnd) && ::IsWindow(m_layout.m_hWnd))
    {
      RECT rc;
      GetClientRect(&rc);
      m_layout.MoveWindow(&rc);
    }
  }


  DECLARE_MESSAGE_MAP()
};
