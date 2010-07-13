// aboutdlg.h : interface of the CAboutDlg class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABOUTDLG_H__BF6A9FCC_701B_4FC9_A3A4_02B9636B9C34__INCLUDED_)
#define AFX_ABOUTDLG_H__BF6A9FCC_701B_4FC9_A3A4_02B9636B9C34__INCLUDED_

class CAboutDlg : public CDialogImpl<CAboutDlg>
{
public:
  enum { IDD = IDD_ABOUTBOX };

  BEGIN_MSG_MAP(CAboutDlg)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
    COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
  END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//  LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//  LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//  LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

  LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
  {
    CenterWindow(GetParent());
    return TRUE;
  }

  LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    EndDialog(wID);
    return 0;
  }
};

#endif // !defined(AFX_ABOUTDLG_H__BF6A9FCC_701B_4FC9_A3A4_02B9636B9C34__INCLUDED_)
