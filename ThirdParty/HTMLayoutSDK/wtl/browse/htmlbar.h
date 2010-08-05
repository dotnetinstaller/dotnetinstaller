// HtmlBar.h: interface for the CHtmlBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTMLBAR_H__0B6EDB29_3DB6_4950_B20A_7B075C1C9E1F__INCLUDED_)
#define AFX_HTMLBAR_H__0B6EDB29_3DB6_4950_B20A_7B075C1C9E1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHTMLBar : 
    public CWindowImpl<CHTMLBar, CHTMLayoutCtrl>,
    public CHTMLayoutHost<CHTMLBar>,
    public htmlayout::event_handler // see constructor
    {
      htmlayout::dom::element m_url;
      htmlayout::dom::element m_search;

      BEGIN_MSG_MAP(CHTMLBar)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
      END_MSG_MAP()

      CHTMLBar():
        htmlayout::event_handler(
              HANDLE_BEHAVIOR_EVENT | // buttons
              HANDLE_KEY )            // we need to catch ENTER in edits
      {}

      LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
      {
        DefWindowProc();
        htmlayout::debug_output_console dc;
        // HTMLayout stuff
        SetCallback(); // reroute all notifications in this instance
        LoadHtmlResource("TOOLBAR");

        
        // attach this event_handler to the root node of the DOM
        // see on_key and on_event,
        htmlayout::attach_event_handler(GetRootElement(),this);
  
        // bind variables to DOM elements
        htmlayout::dom::element root = GetRootElement();
        m_url = root.get_element_by_id("url");
        m_search = root.get_element_by_id("google"); 

        assert(m_url.is_valid() && m_search.is_valid());
        
        return 0;
      }

      LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
      {
        m_url = 0;
        m_search = 0;
        bHandled = FALSE;
        return 0;
      }


      // htmlayout::event_handler::on_event 
      BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
      { 
        if(type == BUTTON_CLICK)
        {
          // 'he' here is a root - the element this event_handler was attached to
          htmlayout::dom::element ctl = target;
          aux::wchars id = aux::chars_of(ctl.get_attribute("id"));
          if( id == const_wchars("open-file") )
          {
            BOOL r = OnFileOpen();
            return r;
          }
          else if( id == const_wchars("new-win") )
          {
              ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_NEW_WINDOW),LPARAM(m_hWnd));
              return TRUE;
          }
          else if( id == const_wchars("refresh") )
          {
              ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_RELOAD),LPARAM(m_hWnd));
              return TRUE;
          }
          else if( id == const_wchars("view-source") )
          {
              ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_VIEW_SOURCE),LPARAM(m_hWnd));
              return TRUE;
          }
          else if( id == const_wchars("back") )
          {
              ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_GOBACK),LPARAM(m_hWnd));
              return TRUE;
          }
          else if( id == const_wchars("forward") )
          {
              ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_GOFORWARD),LPARAM(m_hWnd));
              return TRUE;
          }
        }
        else if(type == BUTTON_PRESS)
        {
          // 'he' here is a root - the element this event_handler was attached to
          target = target;
          ATLTRACE(_T("BUTTON_PRESS: type='%s' \n"), GetElementType(target) );
        }
        else if(type == HYPERLINK_CLICK)
        {
          htmlayout::dom::element ctl = target;
          ATLTRACE(_T("hyperlink click: %S\n"), ctl.get_attribute("href") );
        }
        else if(type == MENU_ITEM_CLICK)
        {
            htmlayout::dom::element ctl = target;
            if( aux::wcseq ( ctl.get_attribute("id"), L"recentfile" ))
            {
                const wchar_t* pwsFileName = ctl.get_attribute("mx_recent_file_name");
                if(pwsFileName && wcslen(pwsFileName))
                {
                    std::wstring wsFileName = pwsFileName;
                    ::SendMessage(GetParent(), WM_LoadFile, (WPARAM)wsFileName.c_str(), 0);

                    return TRUE;
                }
            }
        }
        else if(type == POPUP_REQUEST)
        {
            htmlayout::dom::element elPopup = target;
            if( aux::wcseq ( elPopup.get_attribute("id"), L"recent-file-list" ))
            {
                ::SendMessage(GetParent(), WM_UpdateRecentFileList, (WPARAM)target, 0);
                return TRUE;
            }
        }
        return FALSE; 
      }

      // htmlayout::event_handler::on_key 
      BOOL on_key    (HELEMENT he, HELEMENT target, UINT event_type, UINT code, UINT keyboardStates ) 
      { 
        // purpose of this function:
        // we want to catch VK_RETURN in <input name=url> and <input name=google>
        // *before* (means while sinking) processing of VK_RETURN in elements below the root

        if ( 
              event_type == (KEY_DOWN | SINKING ) &&
              code == VK_RETURN
           )
        {
          if(target == m_url) 
            return OnLoadUrl(); 
          if(target == m_search) 
            return OnSearch(); 
        }

        return FALSE;
      }

      LRESULT OnSize(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
      {
        if(wParam == 0 && lParam == 0) // special care about 
                        // CFrameWindowImplBase::UpdateBarsPosition
        {
          CWindow wp = GetParent();
          CRect rc;
          wp.GetClientRect(&rc);
          int h = GetDocumentMinHeight(rc.Width());
          SetWindowPos(NULL,0,0,rc.Width(),h,SWP_NOMOVE|SWP_NOZORDER);
          return 0;
        }
        bHandled = FALSE;
        return 0;
      }
        
      BOOL OnFileOpen()
      {
        // PostCommand
        ::PostMessage(GetParent(),WM_COMMAND,WPARAM(ID_FILE_OPEN),LPARAM(m_hWnd));
        return TRUE;
      }

      BOOL OnLoadUrl()
      {
        std::wstring url = m_url.text(); 
        ::SendMessage(GetParent(),WM_HTML_NAVIGATE, WPARAM(0),LPARAM(url.c_str()));
        return TRUE;
      }

      LRESULT OnSearch()
      {
        std::wstring search = m_search.text(); 
        ::SendMessage(GetParent(),WM_HTML_NAVIGATE, WPARAM(1),LPARAM(search.c_str()));
        return TRUE;
      }

      void UpdateUrl(LPCWSTR lpszUrl)
      {
          if(m_url.is_valid())
          {
              json::value filename = lpszUrl;
              m_url.set_value(filename);
          }
      }
    };

#endif // !defined(AFX_HTMLBAR_H__0B6EDB29_3DB6_4950_B20A_7B075C1C9E1F__INCLUDED_)
