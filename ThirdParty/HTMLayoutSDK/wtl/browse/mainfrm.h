// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__6AFDAC6D_A631_4236_8344_8EEB36750A1D__INCLUDED_)
#define AFX_MAINFRM_H__6AFDAC6D_A631_4236_8344_8EEB36750A1D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "HTMLBar.h"
#include "HTMLView.h"
#include <string>

#include "htmlayout_graphin.h"

static LPCWSTR GetIeEditorName();

class CMainFrame : public CFrameWindowImpl<CMainFrame>, public CUpdateUI<CMainFrame>,
    public CMessageFilter, public CIdleHandler
{
  CHTMLBar  m_toolbar;
  CHTMLView m_view;

  typedef CFrameWindowImpl<CMainFrame> super;

public:
  DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)

  virtual BOOL PreTranslateMessage(MSG* pMsg)
  {
    if( CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
      return TRUE;
    return m_view.PreTranslateMessage(pMsg);
  }

  virtual BOOL OnIdle()
  {
    UIUpdateToolBar();
    return FALSE;
  }

  BEGIN_UPDATE_UI_MAP(CMainFrame)
    UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
    UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
  END_UPDATE_UI_MAP()

  BEGIN_MSG_MAP(CMainFrame)
    MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_MOVE, OnMove)
    COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
    COMMAND_ID_HANDLER(ID_FILE_OPEN, OnFileOpen)
    COMMAND_ID_HANDLER(ID_FILE_RELOAD, OnFileReload)
        COMMAND_ID_HANDLER(ID_FILE_GOBACK, OnFileGoBack)
        COMMAND_ID_HANDLER(ID_FILE_GOFORWARD, OnFileGoForward)
        COMMAND_ID_HANDLER(ID_FILE_VIEW_SOURCE, OnFileViewSource)
    COMMAND_ID_HANDLER(ID_FILE_NEW_WINDOW, OnFileNewWindow)
    COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
    COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
    COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
    COMMAND_ID_HANDLER(ID_INPUT_DIALOG, OnInputDialog)

    COMMAND_ID_HANDLER(ID_TEST_FETCH_CONTROLS, OnFetchControlValues)
    COMMAND_ID_HANDLER(ID_TEST_RESET_CONTROLS, OnResetControlValues)
    COMMAND_ID_HANDLER(ID_TEST_INSERT_OPTION, OnTestInsertOption)
    COMMAND_ID_HANDLER(ID_TEST_REMOVE_OPTION, OnTestRemeoveOption)

    COMMAND_ID_HANDLER(ID_TEST_UPDATE_WINDOW, OnTestUpdateWindow)

    COMMAND_ID_HANDLER(ID_TEST_TRACK_POPUP, OnTestTrackPopup)
    COMMAND_ID_HANDLER(ID_TEST_SHOW_POPUP, OnTestShowPopup)
    
    COMMAND_ID_HANDLER(ID_GET_HTML, OnGetHTML)
    COMMAND_ID_HANDLER(IDC_GET_DOC_TEXT, OnGetText)
    COMMAND_ID_HANDLER(ID_SELECTION_MODE, OnSelectionMode)
    COMMAND_ID_HANDLER(ID_EDIT_COPY, OnCopy)
    COMMAND_ID_HANDLER(ID_UPDATE_TEST, OnTestUpdate)
    COMMAND_ID_HANDLER(ID_TEST_SCROLL_TO_BOTTOM, OnTestScrollBottom)
    COMMAND_ID_HANDLER(ID_TEST_PROBE, OnTestProbe)

    COMMAND_ID_HANDLER(ID_TEST_CSS, OnTestCSS)
    COMMAND_ID_HANDLER(ID_TEST_SET_HTML, OnTestSetHtml)
    COMMAND_ID_HANDLER(ID_TEST_SET_TEXT, OnTestSetText)

    COMMAND_ID_HANDLER(ID_TEST_SELECT_TEXT, OnTestSelection)
    COMMAND_ID_HANDLER(ID_TEST_GET_SELECTED_TEXT, OnTestSelection)
    COMMAND_ID_HANDLER(ID_TEST_REPLACE_SELECTED_TEXT, OnTestSelection)
    COMMAND_ID_HANDLER(ID_TEST_SET_CARET, OnTestSelection)
    COMMAND_ID_HANDLER(ID_TEST_GET_CARET_POSITION, OnTestSelection)
    COMMAND_ID_HANDLER(ID_TEST_SET_TEXT, OnTestSelection)

    COMMAND_ID_HANDLER(ID_TEST_TABLES, OnTestTables)
    COMMAND_ID_HANDLER(ID_TEST_CLONE, OnTestClone)



    COMMAND_ID_HANDLER(ID_TEST_SET_HTTP_HEADER, OnTestHttpHeaders)

    COMMAND_ID_HANDLER(ID_TEST_ENUMERATE, OnEnumerate)
    COMMAND_ID_HANDLER(ID_TEST_SCROLL_TO_ELEMENT, OnScrollToLastBodyElement)

    COMMAND_ID_HANDLER(ID_TEST_RICHTEXT_LOAD_FILE, OnRichtextLoadFile)

    COMMAND_ID_HANDLER(ID_TEST_SCROLL_RICHTEXT, OnScrollRichtext)

    COMMAND_ID_HANDLER(ID_TEST_SET_ATTR, OnTestSetAttr)
    COMMAND_ID_HANDLER(ID_TEST_CLEAR_ATTR, OnTestClearAttr)
    COMMAND_ID_HANDLER(ID_TEST_CLEAR, OnTestClear)

    COMMAND_ID_HANDLER(ID_SAVE_AS_JPEG, OnSaveAsJpeg)
    COMMAND_ID_HANDLER(ID_SAVE_AS_PNG, OnSaveAsPng)
           
    // these two messages defined in stdafx.h 
    MESSAGE_HANDLER(WM_HTML_NAVIGATE, OnNavigate)
    MESSAGE_HANDLER(WM_SHOW_STATUS, OnShowStatus)
    MESSAGE_HANDLER(WM_PRINTCLIENT, OnPrintClient)
    
    MESSAGE_HANDLER(WM_UpdateRecentFileList, OnUpdateRecentFileList)
    MESSAGE_HANDLER(WM_LoadFile, OnLoadFile)
    MESSAGE_HANDLER(WM_UrlChanged, OnUrlChanged)    
    
    CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
    CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
  END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//  LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//  LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//  LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

  LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
  {
    CreateHtmlBar();  
    CreateSimpleStatusBar();

    UIAddToolBar(m_hWndToolBar);
    UISetCheck(ID_VIEW_TOOLBAR, 1);
    UISetCheck(ID_VIEW_STATUS_BAR, 1);
    
    // register object for message filtering and idle updates
    CMessageLoop* pLoop = _Module.GetMessageLoop();
    ATLASSERT(pLoop != NULL);
    pLoop->AddMessageFilter(this);
    pLoop->AddIdleHandler(this);

    m_hWndClient = m_view.Create(m_hWnd, rcDefault);

    //LPCTSTR lpszSection = TEXT("RecentFile");
    //LPCTSTR lpszFileName = TEXT("HL_RecentFile.ini");
    
    RECT rc = {100, 100, 900, 700};
    LoadWindowPos(rc);
    MoveWindow(&rc);

    return 0;
  }

    LRESULT OnMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
    {
        bHandled = FALSE;

        WINDOWPLACEMENT wp;
        ::GetWindowPlacement(m_hWnd, &wp);
        
        if(wp.showCmd != SW_SHOWNORMAL)
        {
            SaveWindowPos();
        }

        return 0;
    }

    LRESULT OnSize(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& bHandled)
    {
        bHandled = FALSE;

        if(wParam == SIZE_RESTORED)
        {
            SaveWindowPos();
        }

    return 0;
  }

  void UpdateLayout(BOOL bResizeBars = TRUE)
  {
    super::UpdateLayout(bResizeBars);
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_hWndClient);

    POINT scrollPos;
    RECT viewRect;
    SIZE contentSize;

    HTMLayoutGetScrollInfo(root, &scrollPos, &viewRect, &contentSize);

    ATLTRACE(TEXT("content size: %d %d, view size:%d %d\n"), 
      contentSize.cx, contentSize.cy,
      viewRect.right - viewRect.left,
      viewRect.bottom - viewRect.top);    
  }

  LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    PostMessage(WM_CLOSE);
    return 0;
  }

  LRESULT OnFileOpen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CFileDialog dlg(TRUE, TEXT("htm"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
      TEXT("HTML Files (*.htm,*.html)\0*.HTM;*.HTML\0"
           "All Files (*.*)\0*.*\0"), m_hWnd);
    if(dlg.DoModal() == IDOK)
    {
      //static htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
      m_view.Open(t2w(dlg.m_szFileName));
    }
    return 0;
  }

  LRESULT OnFileReload(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    m_view.Open();
    return 0;
  }
    LRESULT OnFileGoBack(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        m_view.GoBack();
        return 0;
    }
    LRESULT OnFileGoForward(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        m_view.GoForward();
        return 0;
    }
    LRESULT OnFileViewSource(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        std::wstring strFileName = m_view.GetFileName();
        if(strFileName.length() == 0)
        {
            return 0;
        }

        LPCWSTR lpszEditorName = GetIeEditorName();
        if(lpszEditorName && wcslen(lpszEditorName))
        {
            SHELLEXECUTEINFOW ShExecInfo = {0};
            
            ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
            ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
            ShExecInfo.hwnd = NULL;
            ShExecInfo.lpVerb = L"OPEN";
            ShExecInfo.lpFile = lpszEditorName;
            ShExecInfo.lpParameters = strFileName.c_str(); 
            ShExecInfo.lpDirectory = NULL;
            ShExecInfo.nShow = SW_SHOW;
            ShExecInfo.hInstApp = NULL;
            
            ShellExecuteExW(&ShExecInfo);
        }
        
        return 0;
    }

  LRESULT OnFileNewWindow(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    ::PostThreadMessage(_Module.m_dwMainThreadID, WM_USER, 0, 0L);
    return 0;
  }

  LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    BOOL bVisible = !::IsWindowVisible(m_hWndToolBar);
    ::ShowWindow(m_hWndToolBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
    UISetCheck(ID_VIEW_TOOLBAR, bVisible);
    UpdateLayout();
    return 0;
  }

  LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    BOOL bVisible = !::IsWindowVisible(m_hWndStatusBar);
    ::ShowWindow(m_hWndStatusBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
    UISetCheck(ID_VIEW_STATUS_BAR, bVisible);
    UpdateLayout();
    return 0;
  }

  LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dialog dlg(m_hWnd);
    
    dlg.show(IDR_ABOUT);
    
    return 0;
  }

  struct my_dialog: public htmlayout::dialog
  {
    my_dialog(HWND parent): htmlayout::dialog(parent, WS_DLGFRAME) {}

    virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
    { 
      htmlayout::dom::element t(target);
      if( type == BUTTON_CLICK && aux::wcseq(t.get_attribute("id"),L"child-dlg"))
      {
        htmlayout::dom::element root = t.root();
        htmlayout::dom::element r = root.find_first("div.content");
        r.set_attribute("state",L"on");
        my_dialog dlg(t.get_element_hwnd(true));
        dlg.alignment = -5; // center of the dialog in the center of m_hWnd rectangle.
        dlg.show(IDR_INPUT_DIALOG);
        r.set_attribute("state",0);
        root.update(RESET_STYLE_DEEP|REDRAW_NOW);
        return TRUE;
      }
      return FALSE; 
    }
  };

  LRESULT OnInputDialog(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    my_dialog dlg(m_hWnd);

    htmlayout::named_values values;
    values[L"YourName"] = L"Andrew"; // some initial value
    
    if(dlg.input(IDR_INPUT_DIALOG,values) == IDOK)
    {
      std::wstring s;
      for ( htmlayout::named_values::const_iterator it = values.begin(); it != values.end() ; ++it )
      {
        s += (*it).first;
        s += L"=";
        s += (*it).second.to_string();
        s += L"\n";
      }
      ::MessageBoxW(m_hWnd,s.c_str(),L"values are:", MB_OK);
    }
    return 0;
  }


  BOOL CreateHtmlBar()
  {
    ATLASSERT(!::IsWindow(m_hWndToolBar));
    m_hWndToolBar = m_toolbar.Create(m_hWnd,rcDefault);
    return (m_hWndToolBar != NULL);
  }

  LRESULT OnNavigate(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
  {
    if(wParam == 0) // url
    {

      LPCWSTR lpszURL = LPCWSTR(lParam);
      if(lpszURL == 0 || lpszURL[0] == 0)
      {
        m_view.LoadHtmlResource(TEXT("EMPTY"));
      }
      else
      {
        m_view.OpenFile(w2t(lpszURL));
        
      }
    }
    else if(wParam == 1) // google search
    {
      LPCWSTR search = LPCWSTR(lParam);
      if(search != 0 && search[0] != 0)
      {
        WCHAR buff[2048]; buff[0] = 0;
        _snwprintf(buff ,2048, L"http://www.google.com/search?q=%s",search);
        
        //URL escape. ATTN: in real life it should be URLescaped properly!
        WCHAR* p = buff;
        for(int i = 0; i < 2048 && *p; ++i, ++p )
          if(*p == ' ') *p = '+';

        m_view.OpenFile(w2t(buff));

      }
    }
    return 0;
  }

  LRESULT OnFetchControlValues(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    // test of json::value::from_string
    aux::wchars text = const_wchars("{one:1 2:'two'}");
    json::value v = json::value::from_string(text,CVT_JSON_LITERAL);
    assert(v.is_map() && v.length() == 2 && v.get_item(json::value("one")) == json::value(1));


    htmlayout::named_values values;
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    
    if(htmlayout::get_values(root, values ))
    {
      std::wstring s;
      for ( htmlayout::named_values::const_iterator it = values.begin(); it != values.end() ; ++it )
      {
        s += (*it).first;
        s += L"=";
        s += (*it).second.to_string();
        s += L"\n";
      }
      ::MessageBoxW(m_hWnd,s.c_str(),L"values are:", MB_OK);
    }
    else
      ::MessageBox(m_hWnd,TEXT("Please load page with <input>s"),TEXT("no input elements on the page"), MB_OK);

    return 0;
  }

  LRESULT OnResetControlValues(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::named_values values;
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);

    values[L"Age"] = 10;
    values[L"YourName"] = L"Unknown!"; // '!' should not appear as of @filter
    values[L"Alignment"] = L"right";
    values[L"Textarea"] = L"one\r\n two\r\n  three";
    values[L"DateOfBirth"] = L"2006-05-12";
    values[L"color"] = 2; // second option in option group
    //values[L"first"] = L"";
    //values[L"Textarea"] = L"";

    if(htmlayout::set_values(root, values ))
    {
      //htmlayout::dom::element textarea = root.find_first("[name='Textarea']");
      //textarea.set_text(L"one_two_three");
      //textarea.update();
      //textarea.set_state( STATE_FOCUS );
    }
    else
      ::MessageBox(m_hWnd,TEXT("Please load page /forms/form.htm"),TEXT("no input elements on the page"), MB_OK);

    return 0;
  }

  // for testing purposes, some data associated with option
  class x_data: public htmlayout::dom::expando
  {
    int data;
  public:
    x_data(int v): data(v) {}
    ~x_data()
    {
      ATLTRACE(TEXT("destroying expando (x_data): %x\n"), data); 
    }
  };

  LRESULT OnTestInsertOption(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    
    htmlayout::dom::element select = root.find_first("widget[type='select']");

    if(!select.is_valid())
    {
      ::MessageBox(m_hWnd,TEXT("Please load /html_samples/forms/selects.htm"),TEXT("widget name=country not found"), MB_OK);
      return 0;
    }
    
    htmlayout::dom::element option = htmlayout::dom::element::create("option", L"Republic of Alpha Centaurus");
    option.set_attribute("class", L"item");
    option.set_attribute("value", L"1");
    // test of set_text in disconnected element
    option.set_text(L"Empire of Beta Centaurus");
    // tresting expando stuff, the x_data instance will de deleted when DOM element will be destroyed
    //option.set_expando( new x_data( 0xDA ) );

    select.insert(option,1); // insert this option at position 1
    //const char *ht = "<p><span>Vini Vidi Vici</span></p>";
    //option.set_html(LPCBYTE(ht), strlen(ht), SIH_REPLACE_CONTENT);

/*
    //htmlayout::dom::element select = root.get_element_by_id( "mylist" ); 
    htmlayout::dom::element opts = htmlayout::dom::element::create( "options"); 
    select.append( opts ); 
    // adding its caption: 
    htmlayout::dom::element opts_caption = htmlayout::dom::element::create( "caption", L"some opt" ); 
    opts.append( opts_caption );  
    for (int i = 0; i < 10; i++) 
    { 
       htmlayout::dom::element opt = htmlayout::dom::element::create( "option", L"some text" ); 
       opts.append( opt ); 
    } 
    select.update( true ); 
*/
    return 0;
  }

  LRESULT OnTestRemeoveOption(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element select = root.find_first("widget[type='select'][name='country']");

    if(!select.is_valid())
    {
      ::MessageBox(m_hWnd,TEXT("Please load /html_samples/forms/selects.htm"),TEXT("widget name=country not found"), MB_OK);
      return 0;
    }
    
    htmlayout::dom::element option = select.child(1);
    if( option.is_valid() && stricmp(option.get_element_type(),"option") == 0 )
    {
      option.detach(); // remove it from parent
      select.update();
    }
    else
    {
      ::MessageBox(m_hWnd,TEXT("There are no <option> at index 1"),TEXT("Ooops!"), MB_OK);
    }
    return 0;
  }

  LRESULT   OnTestTrackPopup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element popup = root.find_first("menu.popup");
    POINT pt; pt.x = 100; pt.y = 100;
    htmlayout::dom::element item = popup.track_popup(8,pt);
    if(item.is_valid())
    {
      std::wstring text = item.text();
      ::MessageBoxW(m_hWnd,text.c_str(),L"Menu Track", MB_OK);
    }
    else
      ::MessageBoxW(m_hWnd,L"no item selected",L"Menu Track" , MB_OK);
    return 0;
  }
  LRESULT   OnTestShowPopup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element popup = root.find_first("menu.popup");
    POINT pt; pt.x = 100; pt.y = 100;
    popup.show_popup(9,pt);
    return 0;
  }


  LRESULT   DoTestTrackPopup(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element popup = root.find_first("menu.popup");
    POINT pt; pt.x = 100; pt.y = 100;
    htmlayout::dom::element item = popup.track_popup(pt);
    if(item.is_valid())
    {
      std::wstring text = item.text();
      ::MessageBoxW(m_hWnd,text.c_str(),L"Menu Track", MB_OK);
    }
    else
      ::MessageBoxW(m_hWnd,L"no item selected",L"Menu Track" , MB_OK);
    return 0;
  }
  

  LRESULT   OnTestUpdateWindow(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element progress = root.find_first("div#progress");

    if(!progress.is_valid())
    {
      ::MessageBox(m_hWnd,TEXT("Test"),TEXT("Please load document with div#progress"), MB_OK);
      return 0;
    }

    progress.set_style_attribute("display",L"block");
    ::HTMLayoutUpdateWindow(progress.get_element_hwnd(true));
    ::Sleep(2000);
    progress.set_style_attribute("display",L"none");
    
    return 0;
  }


  LRESULT OnTestCSS(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    /*

    ATTENTION! ::HTMLayoutSetMasterCSS MUST be invoked only if there no instances of 
    htmlayout created. Otherwise result is unpredictable.

    const char* mcss = // all gone except hyperlinks
        "a:link { text-decoration:underline; color:blue; cursor:pointer; behavior:hyperlink; }"
        "a:link:hover { color:red; }"
        "a:link:active { text-decoration:none; }";

    if(IDYES == ::MessageBox(m_hWnd, "Now master style sheet will be reset,\n all inputs will loose their styles and behaviors.\nDo you really want this?", "Attention!", MB_YESNO))
      ::HTMLayoutSetMasterCSS((LPCBYTE)mcss,strlen(mcss));
    */

    //htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view.m_hWnd);
    //htmlayout::dom::element test = root.find_first("#test");
    //const wchar_t* b = test.get_style_attribute("opacity");


    const char* mcss = // all gone except hyperlinks
        "a:link { text-decoration:underline; color:blue; cursor:pointer; behavior:hyperlink; }"
        "a:link:hover { color:red; }"
        "a:link:active { text-decoration:none; }"
        "h1 { color:red; }"
        "h2 { color:red; }"
        "h3 { color:red; }"
        ;

    HTMLayoutSetCSS(m_view.m_hWnd,(LPCBYTE)mcss,strlen(mcss),0,0);

    return 0;
  }

//#pragma setlocale("russian")

  LRESULT OnTestSetHtml(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);

    /* Sample #0 test of SIH_INSERT_AT_START/SIH_APPEND_AFTER_LAST */
    htmlayout::dom::element body = root.find_first("body");

    /*int n = 3678;
    int fn = 3678.12;

    utf8::ostream os; 
    os << L"<p><b>Hello</b> world!</p>";
    os << L"<p>Some value:" << aux::itoa(n) << "</p>";
    os << L"<p>Some float value 1: " << aux::ftoa(n) << "</p>";
    os << L"<p>Some float value 2: " << aux::ftoa(fn) << "</p>";
    os << L"<p>Some float value 3: " << aux::ftoa(fn,"em") << "</p>";
    //body.set_html( (LPCBYTE) "bb", 2);
    //body.set_html( os.data(), os.length(), SIH_INSERT_AT_START);
    body.set_html( os.data(), os.length(), SIH_APPEND_AFTER_LAST);
    //body.update(true);
    return 0; */
    
    /*           
    // Sample #1: how to fill UL by LIs with hyperlinks

    htmlayout::dom::element el = root.find_first("ul");
    el.clear();

    for(int i = 0; i < 30; ++i)
    {
      htmlayout::dom::element li = htmlayout::dom::element::create("li");
      htmlayout::dom::element a = htmlayout::dom::element::create("a", L"test hyperlink caption");
      el.insert(li, i);
      li.insert(a, 0);
    }
    el.update();
    */

    // Sample #2:  test of the case when target is a paragraph 
    //use sdk/html_samples/index.htm for an example
    /* {
      htmlayout::dom::element p = root.find_first("p");
      assert(p.is_valid());
      
      utf8::ostream os; os << L"<b>Hello</b> world!";

      p.set_html( (LPCBYTE) "bb", 2);
      p.set_html( os.data(), os.length(), SIH_INSERT_AT_START);
      p.set_html( os.data(), os.length(), SIH_APPEND_AFTER_LAST);
      p.update(true);
    } */

    //Sample #3:  test of the case when target is a table 
    //use sdk/html_samples/index.htm for an example
     /*{
      htmlayout::dom::element t = root.find_first("table");
      assert(t.is_valid());
      
      utf8::ostream os; os << L"<tr><td>1</td><td>2</td><td>3</td><td>4</td></tr>";

      //t.set_html( os.data(), os.length());
      t.set_html( os.data(), os.length(), SIH_INSERT_AT_START);
      t.set_html( os.data(), os.length(), SIH_APPEND_AFTER_LAST);
      t.update(true);
    } */

    //Sample #3a:  test of the case when target is a row in the table 
    //use sdk/html_samples/index.htm for an example
    /*{
      htmlayout::dom::element t = root.find_first("table tr:last-child");
      assert(t.is_valid());
      
      utf8::ostream os; os << L"<td>1</td><td>2</td><td>3</td><td>4</td>";

      t.set_html( os.data(), os.length());
      //t.set_html( os.data(), os.length(), SIH_APPEND_AFTER_LAST);
      t.update(true);
    }*/


    // Sample #4:  test of the case when target is a span 
    //use sdk/html_samples/index.htm for an example
    {
      // replace content of first hyperlink
      htmlayout::dom::element p = root.find_first("#empty-select");
      assert(p.is_valid());
      
      utf8::ostream os; os << L"<option>1</option><option>2</option><option>3</option><option>4</option><option>5</option>";

      p.set_html( os.data(), os.length(), SIH_REPLACE_CONTENT);
      //p.update(true);
    }

    // Sample #5:  
    //use sdk/html_samples/forms/form.htm for the example
    /*{
      // replace content of first hyperlink
      htmlayout::dom::element p = root.find_first("span");
      assert(p.is_valid());
      
      utf8::ostream os; 
      os << L"<b>Hello</b> <i>wonderful</i> world!<br/><small>(Way better than that stupid jumping fox, eh?)</small>";
      os << L".";
      p.set_html( os.data(), os.length(), SIH_REPLACE_CONTENT);
      //p.set_text(L"");

      p.update(true);
    }*/

    // Sample #6: 
    /*{
      htmlayout::dom::element div = root.find_first("div");
      if(div.is_valid())
      {
        utf8::ostream os; 
        os << L"<div id=\"content\">text</div>";
        os << L"<div id=\"footer\">footer text</div>";
        div.set_html( os.data(), os.length());
        div.update();
      }
    }*/


    //test of dynamic colspan/rowspan updates
    /*{
      htmlayout::dom::element t = root.find_first("table");
      //htmlayout::dom::element c = t.find_first("td");
      htmlayout::dom::element c = htmlayout::dom::element::create("td");
      
      c.set_attribute("colspan",L"2");
      c.set_attribute("rowspan",L"2");
      htmlayout::dom::element r = htmlayout::dom::element::create("tr");
      r.append(c);
      t.append(r);
      t.update();
    }*/

    /*{
      htmlayout::dom::element p = root.find_first("p");
      if(p.is_valid())
      {
        utf8::ostream os;

        os << "Brief <a href=\"#\"  id=\"2\" >Description</a> that is multiline(m).";

        //os << L"some <a href=\"#\">hyperlink</a> here,"
        //   << L" <b>bold</b> and <i>italic</i>";
        p.set_html( os.data(), os.length());
        p.update(); //- it has to be here but I've removed it for the test.
      }
    }*/


    // Sample #6:

    return 0;
  }
  

  LRESULT OnGetHTML(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element el = htmlayout::dom::element::root_element(m_view);

    json::astring html = el.get_html(true);
       
    FILE * f = fopen("c:\\browse.exe.OnGetHTML.html","wb+");
    if(f)
    {
      unsigned char UTF8_BOM[3] = { 0xEF, 0xBB, 0xBF };
      fwrite(UTF8_BOM,1,3,f);
      fwrite(html.c_str(),1,html.length(),f);
      fclose(f);
      system( "notepad.exe c:\\browse.exe.OnGetHTML.html");
    }
    return 0;
  }


  LRESULT OnGetText(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element el = htmlayout::dom::element::root_element(m_view);
    el = el.find_first("#test");
    if(el.is_valid())
      ::MessageBoxW(m_hWnd, el.text(), L"Text of #test", MB_OK);
    else
      ::MessageBoxA(m_hWnd, "#test element is not found", "Problem:", MB_OK);
    return 0;
  }



  LRESULT OnSelectionMode(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    m_view.SetSelectionMode();
    return 0;
  }

  LRESULT OnCopy(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    m_view.CopySelection();
    LPCBYTE phtml = m_view.GetSelectedHTML(NULL);
    ::MessageBox(m_hWnd,(LPCSTR)phtml, "Selected HTML", MB_OK);
    return 0;
  }

  LRESULT OnEnumerate(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element body = root.find_first("body");

    struct rambler: public htmlayout::dom::enumerator
    {
      htmlayout::debug_output_console dc;
      
      virtual bool on_element_head( HELEMENT he )
      { 
        htmlayout::dom::element el = he;
        dc.printf("head of %s\n", el.get_element_type());
        return false; 
      }
      virtual bool on_element_tail( HELEMENT he )                    
      { 
        htmlayout::dom::element el = he;
        dc.printf("tail of %s\n", el.get_element_type());
        return false; 
      }
      virtual bool on_char( HELEMENT he, int pos,  WCHAR code ) 
      { 
        htmlayout::dom::element el = he;
        RECT rc;
        HTMLayoutGetCharacterRect( he, pos, &rc );
        dc.printf("char %C at %d (%d,%d,%d,%d)\n", code, pos, rc.left, rc.top, rc.right, rc.bottom );
        return false; 
      }
    };

    rambler r;
    r.ramble(body);

    return 0;
  }

  LRESULT OnScrollToLastBodyElement(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element body_last = root.find_first("body>:last-child");
    body_last.scroll_to_view(true);
    //Try to find <CODE class="sample"> in html_samples/index.htm
    //htmlayout::dom::element code_sample = root.find_first("code.sample");
    //code_sample.set_style_attribute("background-color",L"yellow");
    //code_sample.update();
    //code_sample.scroll_to_view(true);
    return 0;
  }

  LRESULT OnScrollRichtext(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element rt = root.find_first("richtext");
    POINT scroll_pos;
    RECT  view_rect;
    SIZE  content_size;
    rt.get_scroll_info(scroll_pos,view_rect,content_size);
    scroll_pos.y = content_size.cy - (view_rect.bottom - view_rect.top);
    rt.set_scroll_pos(scroll_pos);
    return 0;
  }



  LRESULT OnRichtextLoadFile(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element rt = root.find_first("richtext");
    if(!rt.is_valid())
    {
      ::MessageBox(m_hWnd,TEXT("Please load page with <richtext>"),TEXT("no richtext element on the page"), MB_OK);
      return 0;
    }

    CFileDialog dlg(TRUE, "htm", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
      "HTML Files (*.htm,*.html)\0*.HTM;*.HTML\0"
      "All Files (*.*)\0*.*\0", m_hWnd);
    if(dlg.DoModal() != IDOK)
      return 0;

    json::value filename = t2w(dlg.m_szFileName);
    json::value r = rt.xcall("loadFile", filename); 

    return 0;
  }

  LRESULT OnTestTables(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element table = root.find_first("table");

    {
    //htmlayout::dom::element table = htmlayout::dom::element::create("table"); 
    htmlayout::dom::element tr = htmlayout::dom::element::create("tr"); 
    htmlayout::dom::element td = htmlayout::dom::element::create("td",L"first"); tr.append(td); 
                            td = htmlayout::dom::element::create("td",L"second"); tr.append(td); 
                            td = htmlayout::dom::element::create("td",L"third"); tr.append(td); 
    table.append(tr); 
    root.update(true);

    //htmlayout::dom::element table2 = table.clone(); 
    //htmlayout::dom::element td2 = table2.find_first("td"); 
    //td2.detach(); 
    //htmlayout::dom::element td3 = td2.clone(); //BANG!!!!
    return 0;
    }

    
    //const char* html="<html><body><table border=1></table></body></html>"; 
    //::HTMLayoutLoadHtml( m_view, (LPCBYTE)html, strlen(html) ); 


    const char* thtml="<tr><td>test1</td><td>test2</td><td>test3</td></tr>"; 
    table.set_html((LPCBYTE)thtml,strlen(thtml), SIH_APPEND_AFTER_LAST);
    return 0;


    /*{
      htmlayout::dom::element td1 = htmlayout::dom::element::create("td",L"Hello world!"); 
      htmlayout::dom::element td2 = htmlayout::dom::element::create("td",L"Hello world!"); 
      htmlayout::dom::element tr = htmlayout::dom::element::create("tr", L""); 
      tr.append(td1);
      tr.append(td2);
      table.append(tr); 
      table.update(true);
    }
    return 0; */

    /*
    const char* html="<html><body><table border=1><tr><td>test1</td></tr></table></body></html>"; 
    ::HTMLayoutLoadHtml( m_view, (LPCBYTE)html, strlen(html) ); 

    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);
    htmlayout::dom::element table = root.find_first("table");
    htmlayout::dom::element tr = table.find_first("tr");

    {
      htmlayout::dom::element td1 = htmlayout::dom::element::create("td",L"Hello world!"); 
      tr.append(td1);
      td1.update(true);
    }

    return 0;
    */

    if(false)
    {
      htmlayout::dom::element tr = htmlayout::dom::element::create("tr"); 
      htmlayout::dom::element td = htmlayout::dom::element::create("td",L"New Cell"); 
      tr.append(td);
      table.append(tr);
      /* 
      htmlayout::dom::element tr = htmlayout::dom::element::create("tr"); 
      table.insert(tr,0); DON'T DO THIS! EMPTY ROW!
      table.update();
      htmlayout::dom::element td = htmlayout::dom::element::create("td",L"New Cell"); 
      tr.append(td);
      */
      table.update(true);
    }
    else
    {
      htmlayout::dom::element tr = root.find_first("tr"); 
      tr.detach();  //used to crash here 
      htmlayout::dom::element td = tr.child(0);
      td.detach();  //detaching cell
      table.update();

      const char* thtml="<tr><td>test1</td><td>test2</td></tr>"; 

      table.set_html((LPCBYTE)thtml,strlen(thtml), SIH_APPEND_AFTER_LAST);
      table.update();
    }
    return 0;
  }

  
  LRESULT OnTestUpdate(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {

    htmlayout::dom::element root = htmlayout::dom::element::root_element(m_view);

    // test example - enumerate all H3 and add attribute 'updated' to them
    struct enumerator: htmlayout::dom::callback
    {
      virtual bool on_element(HELEMENT he)
      {
        htmlayout::dom::element el = he;
        el.set_attribute("updated", L"true"); // uses html32.htm for testing.
        //el.set_attribute("hide", L"1");
        return false; // continue enumeration
      }
    };

    enumerator cb;
    root.select(&cb,"H1,H2,H3,H4,H5,H6"); // enumerate all headers

    return 0;
  }



  LRESULT OnTestScrollBottom(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    m_view.SendMessage(WM_VSCROLL, SB_BOTTOM, 0);
    return 0;
  }

  LRESULT OnTestProbe(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    m_view.ProbeMode();
    return 0;
  }

  // test of selection methods in edit box
  LRESULT OnTestSelection(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = m_view.GetRootElement();
    htmlayout::dom::editbox ed = root.find_first("textarea, widget[type='htmlarea'],plaintext, input[type='text']");
    if(!ed.is_valid())
    {
      ::MessageBoxW(m_hWnd,L"No input text elements on the page", L"Problem", MB_OK);
      return 0;
    }

    switch(wID)
    {
    case ID_TEST_SELECT_TEXT:
      {
        ed.set_state(STATE_FOCUS);
        ed.select();
      } break;
    case ID_TEST_GET_SELECTED_TEXT:
      {
        pod::buffer<wchar_t> wos;
        ed.get_selected_text(wos);
        ::MessageBoxW(m_hWnd,wos.data(), L"Selected text is:", MB_OK);

        pod::buffer<byte> bos;
        ed.get_selected_html(bos);
        ::MessageBoxA(m_hWnd,(const char*)bos.data(), "Selected html is:", MB_OK);


        std::wstring s = ed.text_value();
        /*
        int start, end;
        if(ed.selection(start,end))
        {
          if( start < end ) // end is a caret position. start is an anchor in selection.
            s = s.substr(start,end - start);
          else
            s = s.substr(end,start - end);
          ::MessageBoxW(m_hWnd,s.c_str(), L"Selected text is:", MB_OK);
        }*/
      } break;
    case ID_TEST_REPLACE_SELECTED_TEXT:
      {
        ed.replace(L"hello!", 6);
      } break;
    case ID_TEST_SET_CARET:
      {
        //ed.text_value(L"some text text");
        //ed.select( 0xFFFFFFF, 0xFFFFFFF ); - to the end of text
        //ed.select( 0, 0 ); - to the start of text
        ed.select( 0, 0xFFFF );
      } break;
    case ID_TEST_GET_CARET_POSITION:
      {
        int x,y,w,h;
        ed.caret_position( x,y,w,h );
        char buf[256];

        sprintf(buf,"x=%d y=%d w=%d h=%d", x,y,w,h);
        
        ::MessageBox(m_hWnd,buf, "caret is at:", MB_OK);
      } break;
    case ID_TEST_SET_TEXT:
      ed.text_value(L"some\ntext");
      break;

    }

    return 0;
  }

  LRESULT OnTestSetAttr(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = m_view.GetRootElement();
    struct set: htmlayout::dom::callback  
      {
        inline bool on_element(HELEMENT he) 
        { 
          htmlayout::dom::element(he).set_attribute("hide", L"1");
          return false; /*continue enumeration*/ 
        }
      };
    set _set;
    root.find_all(&_set, "div.test");
    return 0;
  }
  LRESULT OnTestClearAttr(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = m_view.GetRootElement();
    struct clear: htmlayout::dom::callback 
      {
        inline bool on_element(HELEMENT he) 
        { 
          htmlayout::dom::element(he).remove_attribute("hide");
          return false; /*continue enumeration*/ 
        }
      };
    clear _clear;
    root.find_all(&_clear, "div.test");
    return 0;
  }

  LRESULT OnTestClear(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = m_view.GetRootElement();
    htmlayout::dom::element el = root.find_first("table");
    el.clear();
    return 0;
  }

  struct file_writer: public htmlayout::writer
  {
    FILE* f;
    file_writer(const char* filename):f(0) { f = fopen(filename,"wb");  }
    ~file_writer() { if(f) fclose(f);  }
    virtual bool write( aux::bytes data ) { return fwrite(data.start,data.length,1,f) != 0; }
  };

  LRESULT OnSaveAsJpeg(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CRect r;
    m_view.GetClientRect(&r);
    htmlayout::image *pimg = htmlayout::image::create(r.Width(),r.Height());
    if(pimg)
    {
      HTMLayoutRender(m_view.m_hWnd, pimg->handle(), r );
      file_writer fw("c:\\saved.jpg");
      pimg->save(fw,85);
      ::MessageBox(m_hWnd,TEXT("Saved in c:\\saved.jpg"),TEXT("Save"), MB_OK);
    }
    return 0;
  }

  LRESULT OnSaveAsPng(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    CRect r;
    m_view.GetClientRect(&r);
    htmlayout::image *pimg = htmlayout::image::create(r.Width(),r.Height());
    if(pimg)
    {
      HTMLayoutRender(m_view.m_hWnd, pimg->handle(), r );
      file_writer fw("c:\\saved.png");
      pimg->save(fw,0);
      ::MessageBox(m_hWnd,TEXT("Saved in c:\\saved.png"),TEXT("Save"), MB_OK);
    }
    return 0;
  }

  // test of selection methods in edit box
  LRESULT OnTestHttpHeaders(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    const char* hdr = "HTMLayout-Header-1: test 1\r\nHTMLayout-Header-2: test 2\r\n";
    HTMLayoutSetHttpHeaders(m_view, hdr, strlen(hdr));
    m_view.OpenFile("http://www.terrainformatica.com/tools/http-headers.php");
    return 0;
  }

  LRESULT OnShowStatus(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
  {
    const char* msg = (const char*)lParam;
    CStatusBarCtrl status(m_hWndStatusBar);
    status.SetText(0, msg);
    return 0;
  }

  LRESULT OnPrintClient(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    if( lParam & (PRF_ERASEBKGND | PRF_CLIENT) )
    {
      bHandled = TRUE;
      CDC dc; dc.Attach(HDC(wParam));
      RECT rc;
      ::GetClipBox(dc,&rc);
      dc.FillRect(&rc,COLOR_SCROLLBAR);
      dc.Detach();
    }
    return 0;
  }
  
  LRESULT OnUpdateRecentFileList(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
      m_view.LoadRecentFileList();
      const std::list<std::wstring>& recentList = m_view.m_recentList;

      htmlayout::dom::element elRecentFileList = (HELEMENT)wParam;

      if(!elRecentFileList.is_valid())
      {
          return 0;
      }
      
      utf8::oxstream html;
     
      std::list<std::wstring>::const_iterator it = recentList.begin();
      while(it != recentList.end())
      {
          const std::wstring& fileName = *it++;
          html << "<li id='recentfile' mx_recent_file_name='" << fileName.c_str() << "'>";
          html <<   fileName.c_str();
          html << "</li>";
      }
      if(html.length() == 0)
          html << "<li>no history</li>";
      elRecentFileList.set_html(html.data(), html.length());

      return 0;
  }

  LRESULT OnLoadFile(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
      LPCWSTR lpszFileName = (LPCWSTR)wParam;
      if(lpszFileName && wcslen(lpszFileName))
      {
          m_view.Open(lpszFileName);
      }
      return 0;
  }
  
  LRESULT OnUrlChanged(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
      LPCWSTR lpszUrl = (LPCWSTR)wParam;
      if(lpszUrl && wcslen(lpszUrl))
      {
          m_toolbar.UpdateUrl(lpszUrl);
          LPCWSTR lps = wcsrchr(lpszUrl, '\\');
          if(lps)
          {
              ++lps;
          }
          if(!lps || *lps == 0)
          {
              lps = lpszUrl;
          }
          SetWindowText(w2t(lps));
      }
      return 0;
  }
  

  /*
  void UpdateLayout(BOOL bResizeBars = TRUE)
  {
    CFrameWindowImpl<CMainFrame>::UpdateLayout(bResizeBars);
    ::UpdateWindow(m_hWnd);
  } */
  

  LRESULT OnTestClone(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    htmlayout::dom::element root = m_view.GetRootElement();

    htmlayout::dom::element div = root.find_first("div"); 
    if( div.is_valid() )
    {
      htmlayout::dom::element div_cpy = div.clone(); 
      std::string s1 = (const char*)div.get_html(); 
      std::string s2 = (const char*)div_cpy.get_html(); 
      div.append(div_cpy); 
      div.update(true); 
    }
    return 0;
  }

  LRESULT OnTestSetText(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
  {
    /*htmlayout::dom::element root = m_view.GetRootElement();
    htmlayout::dom::element span = root.find_first("#three"); 
    if(!span) return 0;

    const char* s = "Hello world";
    span.set_html(LPCBYTE(s),strlen(s));
    span.update(true);
    */

    htmlayout::dom::element root = m_view.GetRootElement();
    htmlayout::dom::element el = root.get_element_by_id("TEST_INPUT");
    if(el.is_valid())
    {
        unsigned char szTestTitle[] = {0xFD, 0xFF, 0x76, 0x06, 0xFD, 0xFF, 0xBB, 0x04, 0xFD, 0xFF, 0xA3, 0x00, 0xFD, 0xFF, 0xFD, 0xFF, 0xFD, 0xFF, 0xFD, 0xFF, 0xFD, 0xFF, 0xAA, 0x05, 0xFD, 0xFF, 0xFD, 0xFF, 0, 0};
        el.set_text((const wchar_t*)szTestTitle);
    }
    return 0;

  }
 
  void LoadWindowPos(RECT& refRect)
  {
      LPCTSTR lpszSection = TEXT("RecentFile");
      LPCTSTR lpszFileName = TEXT("HL_RecentFile.ini");
      
      RECT rc = {0};
      
      if(GetPrivateProfileStruct(lpszSection,
          TEXT("position"),
          &rc,
          sizeof(rc),
          lpszFileName))
      {
        if((rc.right - rc.left) > 10 && (rc.bottom - rc.top) > 10 && rc.top > 0)
          refRect = rc;
      }
  }

  void SaveWindowPos()
  {
      RECT rc = {100, 100, 900, 700};
      GetWindowRect(&rc);
      
      LPCTSTR lpszSection = TEXT("RecentFile");
      LPCTSTR lpszFileName = TEXT("HL_RecentFile.ini");
      
      WritePrivateProfileStruct(lpszSection,
          TEXT("position"),
          (void*)&rc,
          sizeof(rc),
          lpszFileName);
  }

};

static LPCWSTR GetIeEditorName()
{
    HKEY hKey;   
    LONG result = RegOpenKeyExW(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\Internet Explorer\\View Source Editor\\Editor Name\\",
        0,
        KEY_READ,
        &hKey);
    
    if(result != ERROR_SUCCESS)
    {
        return L"notepad.exe";
    }
    
    static WCHAR szEditorName[MAX_PATH] = {0};

    DWORD dwType = REG_SZ;
    DWORD dwSize = sizeof(szEditorName);

    result = RegQueryValueExW(
        hKey,
        NULL,
        NULL,
        &dwType,
        (LPBYTE)szEditorName,
        &dwSize);
    
    if(result != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        return NULL;
    }
    
    RegCloseKey(hKey);

    return szEditorName;
}

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__6AFDAC6D_A631_4236_8344_8EEB36750A1D__INCLUDED_)
