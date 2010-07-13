// htmlview.h: interface for the CHTMLView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTMLVIEW_H__8CEA139E_1C20_4B40_836F_71864F34F919__INCLUDED_)
#define AFX_HTMLVIEW_H__8CEA139E_1C20_4B40_836F_71864F34F919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "htmlayout_aux.h"

class CHTMLView : 
    public CWindowImpl<CHTMLView, CHTMLayoutCtrl>,
    public CHTMLayoutHost<CHTMLView>,
    public htmlayout::event_handler
    {

      bool          m_probeMode;
      std::wstring  m_currentUrl;
      HELEMENT      m_mouseOver;
public:
      CHTMLView() : event_handler( unsigned(-1) /*handle all event groups*/ ) 
      {
          m_nCurIndex = -1;
      }

      BOOL PreTranslateMessage(MSG* pMsg)
      {
        // engine needs tabs for TAB navigation

        if((pMsg->message == WM_KEYDOWN || pMsg->message == WM_KEYUP) && ::GetFocus() == m_hWnd)
        {
          if(pMsg->wParam == VK_TAB) // always need this
          {
            ::SendMessage(m_hWnd,pMsg->message,pMsg->wParam,pMsg->lParam);
            return TRUE;
          }
          /*if() // others - only when we are in focus
          {
            ::SendMessage(m_hWnd,pMsg->message,pMsg->wParam,pMsg->lParam);
            return TRUE;
          }*/
        }
        return FALSE;
        //return ::IsDialogMessage(m_hWnd,pMsg);
      }

      BEGIN_MSG_MAP(CHTMLView)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
        MESSAGE_HANDLER(WM_RBUTTONUP, OnMouseUp)
        MESSAGE_HANDLER(WM_DROPFILES, OnDropFiles)
        
    
        HTML_HYPERLINK_HANDLER(OnHyperlink)
      END_MSG_MAP()

      LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
      {
        m_probeMode = false;
        DefWindowProc();
        // HTMLayout stuff
        SetCallback(); // reroute all notifications here
        SetEventHandler(this); // set this as a "zero level" event handler, all not handled HTML DOM events will go here
        
        ::DragAcceptFiles(m_hWnd,TRUE);

        LoadHtmlResource("EMPTY");
        
        //aux::chars empty = const_chars("<html></html>");
        //LoadHtml((const byte*)empty.start, empty.length);
        //OpenFile("http://ya.ru/");
       
        LoadRecentFileList();

        return 0;
      }

      LRESULT OnHyperlink(NMHL_HYPERLINK* pnmhl, BOOL& bHandled)
      {
        ATLTRACE(_T("CHTMLayoutHost::OnHyperLink: href='%.256s' target='%s' action=%u\n"), 
          CString(pnmhl->szHREF), CString(pnmhl->szTarget), pnmhl->action);

        switch (pnmhl->action) {
          case NMHL_HYPERLINK::ENTER: 
            break;
          case NMHL_HYPERLINK::LEAVE: 
            break;
          case NMHL_HYPERLINK::CLICK: 
            {
              CString url(pnmhl->szHREF);
            //AtlMessageBox(m_hWnd, (LPCTSTR)CString(pnmhl->szHREF), TEXT("href"));
              ::SendMessage( GetParent(),WM_HTML_NAVIGATE,0, LPARAM((LPCTSTR)url));
#ifdef _DEBUG
              /*
              htmlayout::dom::element root = htmlayout::dom::element::root_element(m_hWnd);
              htmlayout::dom::element el = root.find_first("#test-of-insertion");
              if(el.is_valid())
              {
                const char *t = "<p><a href=\"\">some text</a></p>";
                el.element::set_html((LPBYTE)t,strlen(t),SIH_REPLACE_CONTENT);
                root.update(true);
                Invalidate();
                UpdateWindow();
              }*/
#endif
            }
            break;

        }
        return 0;
      }

      HELEMENT in_focus()
      {
        return htmlayout::dom::element::focus_element(m_hWnd);
      }

      virtual BOOL handle_focus (HELEMENT he, FOCUS_PARAMS& params ) 
      {
        /*htmlayout::debug_output_console dc;
        switch( params.cmd )
        {
          case FOCUS_GOT: dc.printf("GOT_FOCUS: %S\n", id_or_name_or_tag(in_focus()).c_str() ); break;
          case FOCUS_GOT | HANDLED: dc.printf("GOT_FOCUS*: %S\n", id_or_name_or_tag(in_focus()).c_str() ); break;
          case FOCUS_LOST:  if(params.target) dc.printf("LOST_FOCUS: %S\n", id_or_name_or_tag(in_focus()).c_str() ); break;
          case FOCUS_LOST | HANDLED: if(params.target) dc.printf("LOST_FOCUS*: %S\n", id_or_name_or_tag(in_focus()).c_str() ); break;
        }*/
        return FALSE;
      }

      virtual BOOL handle_mouse (HELEMENT he, MOUSE_PARAMS& params ) 
      {
        htmlayout::debug_output_console dc;
        switch( params.cmd )
        {
          case MOUSE_DOWN: dc.printf("MOUSE_DOWN: %S\n", id_or_name_or_tag( params.target ).c_str() ); break;
          case MOUSE_DOWN | HANDLED: dc.printf("MOUSE_DOWN*: %S\n", id_or_name_or_tag( params.target ).c_str() ); break;
          case MOUSE_UP: dc.printf("MOUSE_UP: %S\n", id_or_name_or_tag( params.target ).c_str() ); break;
          case MOUSE_UP | HANDLED: dc.printf("MOUSE_UP*: %S\n", id_or_name_or_tag( params.target ).c_str() ); break;
        }
        return FALSE;
      }

      virtual BOOL handle_event (HELEMENT he, BEHAVIOR_EVENT_PARAMS& params ) 
      { 
        switch( params.cmd )
        {
        case BUTTON_CLICK:              // click on button
             OnButtonClick( params.heTarget );   break;
        case BUTTON_PRESS:              break;// mouse down or key down in button
        case BUTTON_STATE_CHANGED:      
             OnButtonState( params.heTarget );   break;// checkbox/radio/slider changed its state/value 
        case EDIT_VALUE_CHANGING:       break;// before text change
        
        case EDIT_VALUE_CHANGED:        //after text change
             OnEditChanged( params.heTarget, false );   break;
        case EDIT_VALUE_CHANGED | HANDLED:
             OnEditChanged( params.heTarget, true );   break;

        case SELECT_SELECTION_CHANGED:  
             OnSelectChanged( params.heTarget, false );   
             break;// selection in <select> changed
        //case SELECT_SELECTION_CHANGED | HANDLED:  
        //     OnSelectChanged( params.heTarget, false );   
        //     break;// selection in <select> changed

        case SELECT_STATE_CHANGED:      
             OnSelectChanged( params.heTarget, true );   
             break;// node in select expanded/collapsed, heTarget is the node

        case POPUP_REQUEST: 
             OnPopupRequest( params.he, params.heTarget );
                                        break;// request to show popup just received, 
                                              //     here DOM of popup element can be modifed.
        case POPUP_READY:               break;// popup element has been measured and ready to be shown on screen,
                                              //     here you can use functions like ScrollToView.
        case POPUP_DISMISSED:           break;// popup element is closed,
                                              //     here DOM of popup element can be modifed again - e.g. some items can be removed
                                              //     to free memory.

        //case MENU_ITEM_ACTIVE:                // menu item activated by mouse hover or by keyboard
        //     OnMenuActive( params.he, params.heTarget );     break;
        //     break;
        case MENU_ITEM_CLICK:                 // menu item click 
             OnMenuClick( params.he, params.heTarget );     break;


            // "grey" event codes  - notfications from behaviors from this SDK 
        case HYPERLINK_CLICK | SINKING:           
          /*::MessageBoxW(m_hWnd, 
            htmlayout::dom::element(params.heTarget).get_attribute("href"), 
            L"hyperlink",
            MB_OK);
            return TRUE;*/
            break;
          break;// hyperlink click

        case TABLE_HEADER_CLICK:        break;// click on some cell in table header, 
                                              //     target = the cell, 
                                              //     reason = index of the cell (column number, 0..n)
        case TABLE_ROW_CLICK:           break;// click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)
        case TABLE_ROW_DBL_CLICK:       break;// mouse dbl click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)

        case ELEMENT_COLLAPSED:         OnElementExpanded(params.heTarget,FALSE); break;// element was collapsed, so far only behavior:tabs and expandable-list are sending these two to the panels
        case ELEMENT_EXPANDED:          OnElementExpanded(params.heTarget,TRUE); break;// element was expanded,

        case FORM_SUBMIT | SINKING:
          {
            htmlayout::debug_output_console dc;
            json::value map = params.data;
            dc.printf("Form submit with data:%S\n", map.to_string(CVT_JSON_MAP).c_str()); 
          } break;



        }
        return FALSE; 
      }

      // handler of custom global functions for CSSS! engine
      virtual BOOL on_script_call(HELEMENT he, LPCSTR name, UINT argc, json::value* argv, json::value& retval) 
      { 
        if( aux::streq(name, "application-name") )
        {
          retval = json::value(L"browse.exe");
          return TRUE;
        }
        if( aux::streq(name, "debug") )
        {
          htmlayout::debug_output_console dc;
          for(int n = 0; n < int(argc); ++n) 
          {
            if( argv[n].is_dom_element() )
            {
              htmlayout::dom::element el = htmlayout::dom::element::from_value(argv[n]);
              dc.printf("%S ", id_or_name_or_tag(el).c_str());
            }
            else
              dc.printf("%S ", argv[n].to_string().c_str() );
          }
          dc.printf("\n");
          return TRUE;
        }
        if( aux::streq(name, "shell-exec") && argc >= 1)
        {
          ShellExecuteW(0, L"open", argv[0].to_string().c_str(), NULL, NULL, SW_SHOWNORMAL);
          return TRUE;
        }

        return FALSE; 
      }      


      bool set_string( std::wstring& stupid_std_string, const wchar_t* str )
      {
         if(!str) return false;
         stupid_std_string = str;
         return true;
      }

      std::wstring id_or_name_or_text( HELEMENT he )
      {
        htmlayout::dom::element el = he;

        std::wstring name;
        if(set_string( name, el.get_attribute("id")) ) return name;
        if(set_string( name, el.get_attribute("name")) ) return name;

        name = L"{";
		std::wstring str = el.text().c_str();
        if( str.length() )
          name += str;
        name += L"}";
        return name;
      }
      std::wstring id_or_name_or_tag( HELEMENT he )
      {
        if(!he)
          return L"(no element)";
        htmlayout::dom::element el = he;
        std::wstring name;
        if(set_string( name, el.get_attribute("id")) ) return name;
        if(set_string( name, el.get_attribute("name")) ) return name;
        name = aux::a2w(el.get_element_type());
        return name;
      }


      void OnButtonClick(HELEMENT button)
      {
        htmlayout::debug_output_console dc;
        dc.printf("BUTTON_CLICK: %S\n", id_or_name_or_text(button).c_str() );
      }

      void OnButtonState(HELEMENT button)
      {
        htmlayout::debug_output_console dc;
        dc.printf("BUTTON_STATE_CHANGED: %S\n", id_or_name_or_text(button).c_str() );
      }

      void OnEditChanged(HELEMENT edit, bool processed)
      {
        htmlayout::debug_output_console dc;
        dc.printf("EDIT_VALUE_CHANGED%c:%S\n", processed?'*':' ', id_or_name_or_tag(edit).c_str() );
      }

      void OnSelectChanged(HELEMENT edit, bool stateChanged)
      {
        htmlayout::debug_output_console dc;
        if(stateChanged)
          dc.printf("SELECT_STATE_CHANGED:%S\n", id_or_name_or_tag(edit).c_str() );
        else
          dc.printf("SELECT_SELECTION_CHANGED:%S\n", id_or_name_or_tag(edit).c_str() );
      }
      
      LRESULT OnMenuClick(HELEMENT anchor, HELEMENT menuItem)
      {
        htmlayout::debug_output_console dc;
        dc.printf("MENU_ITEM_CLICK: %S for %S\n", id_or_name_or_text(menuItem).c_str(), id_or_name_or_text(anchor).c_str() );
        return 0;
      }
      LRESULT OnMenuActive(HELEMENT anchor, HELEMENT menuItem)
      {
        htmlayout::debug_output_console dc;
        dc.printf("MENU_ITEM_ACTIVE: %S for %S\n", id_or_name_or_text(menuItem).c_str(), id_or_name_or_text(anchor).c_str() );
        return 0;
      }

      LRESULT OnElementExpanded(HELEMENT item, BOOL expanded)
      {
        htmlayout::debug_output_console dc;
        if(expanded)
          dc.printf("ELEMENT_EXPANDED:%S\n", id_or_name_or_tag(item).c_str() );
        else
          dc.printf("ELEMENT_COLLAPSED:%S\n", id_or_name_or_tag(item).c_str() );
        return 0;
      }


      LRESULT OnPopupRequest(HELEMENT heAnchor, HELEMENT hePopup)
      {
        //htmlayout::debug_output_console dc;

        //htmlayout::dom::element popup = hePopup;
        //htmlayout::dom::element anchor = heAnchor;

        //dc.printf("POPUP_REQUEST: popup=%s, anchor=%s\n", popup.get_element_type(), anchor.get_element_type() );
        return 0;
      }

      void Open(LPCWSTR url = 0, bool bByBackForwardCmd = false)
      {
        if( url )
          m_currentUrl = url;
        else
          url = m_currentUrl.c_str();


        ::SendMessage(GetParent(), WM_UrlChanged, (WPARAM)url, 0);
        OpenFile( w2t(url) );

        if(!bByBackForwardCmd)
        {
            //for go back/forward
            if(m_historyList.empty())
            {
                m_historyList.push_back(url);
            }
            else
            {
                std::vector<std::wstring>::iterator itLast = m_historyList.end();
                --itLast;
                const std::wstring& strLast = *itLast;
                if(strLast != url)
                {
                    m_historyList.push_back(url);
                }
            }
            m_nCurIndex = m_historyList.size() - 1;

            //update recent file list
            std::wstring strFileName = GetFileName();
            if(strFileName.length())
            {
                std::list<std::wstring>::iterator it = std::find(m_recentList.begin(), m_recentList.end(), strFileName);
                if(it != m_recentList.end())
                {
                    m_recentList.erase(it);
                }
                m_recentList.push_front(strFileName);
                SaveRecentFileList();
            }
        }
      }


      // switch probe mode on - will show tag stack in status bar
      void ProbeMode()
      {
        m_probeMode = true;
      }


      // printTagName - fill buf with tag stack.
      char* printTag( char* buf, HELEMENT he )
      {
        htmlayout::dom::element el = he;
        if(el.is_valid())
        {
          char* p = printTag( buf, el.parent() );
          
          const wchar_t* id = el.get_attribute("id");
          aux::w2a acls(el.get_attribute("class"));
          aux::chars cls = aux::chars_of(acls);
          p += sprintf(p,"<%s", el.get_element_type());
          if(id) p += sprintf(p,"#%S", id);
          if(cls.length) 
          {
            aux::atokens wt(cls, " ");
            aux::chars c1;
            while(wt.next(c1))
            {
              strcat(p,"."); p += 1;
              strncat(p,c1.start,c1.length); p += c1.length;
            }
          }
          p += sprintf(p,"> ");
          return p;
        }
        return buf;
      }

      LRESULT OnMouseMove(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
      {
        if(m_probeMode)
        {
          POINT pt;
            pt.x = GET_X_LPARAM(lParam); 
            pt.y = GET_Y_LPARAM(lParam); 
          
          HELEMENT he = htmlayout::dom::element::find_element(m_hWnd,pt);
          if(m_mouseOver != he)
          {
            m_mouseOver = he;
            char buf[2048]; // may overflow, not for use in production code
            printTag(buf,he);
            ::SendMessage( GetParent(),WM_SHOW_STATUS,0, LPARAM(buf));
          }
        }
        bHandled = FALSE;
        return 0;
      }

      static void CALLBACK styleCallback( HTMLayoutCSSRuleDef* pdef, LPVOID callback_prm )
      {
        htmlayout::debug_output_console* dcon = (htmlayout::debug_output_console*) callback_prm;
        switch( pdef->rule_type )
        {
          case 0: 
            dcon->printf("\tselector %S in %s(%d)\n", pdef->selector, pdef->file_url, pdef->file_line_no);
            break;
          case 1: 
            dcon->printf("\tstyle attribute: %S \n", pdef->selector );
            break;
          case 2: 
            dcon->printf("\talso has runtime styles set.\n" );
            break;
        }
      }

      LRESULT OnMouseUp(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
      {
        if(m_probeMode)
        {
          POINT pt;
            pt.x = GET_X_LPARAM(lParam); 
            pt.y = GET_Y_LPARAM(lParam); 
          
          htmlayout::dom::element root = htmlayout::dom::element::root_element(m_hWnd);
          htmlayout::dom::element tr = root.find_first("tr");
          if( tr )
          {
            htmlayout::debug_output_console dcon;
            LPCSTR tag;
            HTMLayoutGetElementType(tr,&tag);
            dcon.printf("styles of <%s>:\n", tag); 
            HTMLayoutEnumElementStyles(tr,&styleCallback,&dcon);
          }
         
          /*HELEMENT he = htmlayout::dom::element::find_element(m_hWnd,pt);
          if( he )
          {
            htmlayout::debug_output_console dcon;
            LPCSTR tag;
            HTMLayoutGetElementType(he,&tag);
            dcon.printf("styles of <%s>:\n", tag); 
            HTMLayoutEnumElementStyles(he,&styleCallback,&dcon);
          }*/
        }
        bHandled = FALSE;
        return 0;
      }

      LRESULT OnDropFiles(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
      {
        HDROP hdrop = (HDROP) wParam; 
        

        WCHAR file_name[MAX_PATH] = L"file://";
        if ( DragQueryFileW ( hdrop, 0, file_name + 7, MAX_PATH - 7) > 0 )
          Open( file_name );
        DragFinish ( hdrop );
        return 0;
      }

      /*virtual LRESULT OnLoadData(LPNMHL_LOAD_DATA pnmld)
      {
        // <include> in <table> testing.
        if( aux::wcseq(pnmld->uri,L"rowdata:1") )
        {
           char data[] = {
               "<tr style=\"background-color:yellow\"><td>Test</td></tr>"
           };
    
           HTMLayoutDataReady(pnmld->uri, (LPBYTE)data, strlen(data));
           return LOAD_OK;
          
        }
        return CHTMLayoutHost<CHTMLView>::OnLoadData(pnmld);
      }*/

      std::wstring GetFileName()
      {
          aux::wchars filename = aux::wchars(m_currentUrl.c_str(), m_currentUrl.length());
          if(filename.like(L"file://*"))
          {
            filename.prune(7);
            return std::wstring(filename.start, filename.length); 
          }
          return m_currentUrl;
      }

      void LoadRecentFileList()
      {
          m_recentList.clear();

          LPCWSTR lpszSection = L"RecentFile";
          LPCWSTR lpszFileName = L"HL_RecentFile.ini";

          int nCount = GetPrivateProfileIntW(lpszSection,
              L"Count",
              0,
              lpszFileName);

          const int nMaxCount = 20;

          if(nCount > nMaxCount)
          {
              nCount = nMaxCount;
          }

          for(int i = 0; i < nCount; ++i)
          {
              WCHAR szKey[260] = {0};
              _snwprintf(szKey,sizeof(szKey), L"Item%02d", i);
              WCHAR szFileName[MAX_PATH] = {0};
              GetPrivateProfileStringW(lpszSection, 
                  szKey, 
                  NULL, 
                  szFileName, 
                  sizeof(szFileName)/sizeof(szFileName[0]), 
                  lpszFileName);

              if(szFileName[0])
              {
                  m_recentList.push_back(szFileName);
              }
          }
      }
          
      void SaveRecentFileList()
      {
          const int nMaxCount = 20;

          LPCWSTR lpszSection = L"RecentFile";
          LPCWSTR lpszFileName = L"HL_RecentFile.ini";

          //char szTemp[32] = {0};
          //itoa(min(m_recentList.size(), nMaxCount), szTemp, 10);
          
          WritePrivateProfileStringW(lpszSection,
              L"Count",
              aux::itow(min(m_recentList.size(), nMaxCount)),
              lpszFileName);

          int i = 0;
          std::list<std::wstring>::const_iterator it = m_recentList.begin();
          while(it != m_recentList.end())
          {
              const std::wstring& refFileName = *it++;

              WCHAR szKey[260] = {0};
              _snwprintf(szKey,sizeof(szKey), L"Item%02d", i++);
              WritePrivateProfileStringW(lpszSection,
                  szKey,
                  refFileName.c_str(),
                  lpszFileName);

              if(i >= nMaxCount)
              {
                  break;
              }
          }
      }

      void GoBack()
      {
          if(m_nCurIndex > 0)
          {
              --m_nCurIndex;

              if(m_nCurIndex < int(m_historyList.size()))
              {
                  std::wstring strUrl = m_historyList.at(m_nCurIndex);
                  Open(strUrl.c_str(), true);
              }
          }
      }

      void GoForward()
      {
          if(!m_historyList.empty() && m_nCurIndex < int(m_historyList.size()) - 1)
          {
              ++m_nCurIndex;

              std::wstring strUrl = m_historyList.at(m_nCurIndex);
              Open(strUrl.c_str(), true);
          }
      }

      //used for recent file list
      std::list<std::wstring> m_recentList;

      //used for go back/forward
      std::vector<std::wstring> m_historyList;
      int m_nCurIndex;          

    };

#endif // !defined(AFX_HTMLVIEW_H__8CEA139E_1C20_4B40_836F_71864F34F919__INCLUDED_)
