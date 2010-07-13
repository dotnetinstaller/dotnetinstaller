// browse.cpp : main source file for browse.exe
//

#include "stdafx.h"

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include "resource.h"

#include "aboutdlg.h"
#include "MainFrm.h"

#include "htmlite.h"

CAppModule _Module;

// enable debug output
//htmlayout::debug_output _debug_stream;

//htmlayout::debug_output_console _debug_stream;

//PrimordialDataLoader, used for loading res:name.ext resources refered by custom master CSS

BOOL CALLBACK PrimordialDataLoader(LPCWSTR uri, UINT dataType, HTMLAYOUT_DATA_WRITER* pDataWriter)
{
    USES_CONVERSION;

    if (wcsncmp( uri, L"res:", 4 ) == 0 )
      uri += 4;
    else 
      return FALSE; // it is not ours

    // Retrieve url specification into a local storage since FindResource() expects 
    // to find its parameters on stack rather then on the heap under Win9x/Me

    TCHAR achURL[MAX_PATH]; lstrcpyn(achURL, W2CT(uri), MAX_PATH);

    // Separate extension if any

    LPTSTR pszName = achURL;
    LPTSTR pszExt = _tcsrchr(achURL, '.'); if (pszExt) *pszExt++ = '\0';

    // Find specified resource and leave if failed. Note that we use extension
    // as the custom resource type specification or assume standard HTML resource 
    // if no extension is specified

    HRSRC hrsrc = 0;
    bool  isHtml = false;
#ifndef _WIN32_WCE
    if( pszExt == 0 || _tcsicmp(pszExt,TEXT("HTML")) == 0)
    {
      hrsrc = ::FindResource(_Module.GetResourceInstance(), pszName, RT_HTML);
      isHtml = true;
    }
    else
      hrsrc = ::FindResource(_Module.GetResourceInstance(), pszName, pszExt);
#else 
      hrsrc = ::FindResource(_Module.GetResourceInstance(), pszName, pszExt);
#endif

    if (!hrsrc) return FALSE; // resource not found here - proceed with default loader

    // Load specified resource and check if ok

    HGLOBAL hgres = ::LoadResource(_Module.GetResourceInstance(), hrsrc);
    if (!hgres) return FALSE;

    // Retrieve resource data and check if ok

    PBYTE pb = (PBYTE)::LockResource(hgres); if (!pb) return LOAD_DISCARD;
    DWORD cb = ::SizeofResource(_Module.GetResourceInstance(), hrsrc); if (!cb) return LOAD_DISCARD;

    pDataWriter(uri,dataType,pb,cb);
    
    return TRUE;
}

class CBrowseThreadManager
{
public:
  // thread init param
  struct _RunData
  {
    LPTSTR lpstrCmdLine;
    int nCmdShow;
  };

  // thread proc
  static DWORD WINAPI RunThread(LPVOID lpData)
  {
    CMessageLoop theLoop;
    _Module.AddMessageLoop(&theLoop);

    _RunData* pData = (_RunData*)lpData;
    CMainFrame wndFrame;

    //if(wndFrame.CreateEx(NULL, NULL, 0, WS_EX_LAYOUTRTL ) == NULL)
    if(wndFrame.CreateEx() == NULL)
    {
      ATLTRACE(_T("Frame window creation failed!\n"));
      return 0;
    }

    wndFrame.ShowWindow(pData->nCmdShow);
    ::SetForegroundWindow(wndFrame);  // Win95 needs this
    delete pData;

    int nRet = theLoop.Run();

    _Module.RemoveMessageLoop();
    return nRet;
  }

  DWORD m_dwCount;
  HANDLE m_arrThreadHandles[MAXIMUM_WAIT_OBJECTS - 1];

  CBrowseThreadManager() : m_dwCount(0)
  { }

// Operations
  DWORD AddThread(LPTSTR lpstrCmdLine, int nCmdShow)
  {
    if(m_dwCount == (MAXIMUM_WAIT_OBJECTS - 1))
    {
      ::MessageBox(NULL, _T("ERROR: Cannot create ANY MORE threads!!!"), _T("browse"), MB_OK);
      return 0;
    }

    _RunData* pData = new _RunData;
    pData->lpstrCmdLine = lpstrCmdLine;
    pData->nCmdShow = nCmdShow;
    DWORD dwThreadID;
    HANDLE hThread = ::CreateThread(NULL, 0, RunThread, pData, 0, &dwThreadID);
    if(hThread == NULL)
    {
      ::MessageBox(NULL, _T("ERROR: Cannot create thread!!!"), _T("browse"), MB_OK);
      return 0;
    }

    m_arrThreadHandles[m_dwCount] = hThread;
    m_dwCount++;
    return dwThreadID;
  }

  void RemoveThread(DWORD dwIndex)
  {
    ::CloseHandle(m_arrThreadHandles[dwIndex]);
    if(dwIndex != (m_dwCount - 1))
      m_arrThreadHandles[dwIndex] = m_arrThreadHandles[m_dwCount - 1];
    m_dwCount--;
  }

  int Run(LPTSTR lpstrCmdLine, int nCmdShow)
  {
    MSG msg;
    // force message queue to be created
    ::PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);

    AddThread(lpstrCmdLine, nCmdShow);

    int nRet = m_dwCount;
    DWORD dwRet;
    while(m_dwCount > 0)
    {
      dwRet = ::MsgWaitForMultipleObjects(m_dwCount, m_arrThreadHandles, FALSE, INFINITE, QS_ALLINPUT);

      if(dwRet == 0xFFFFFFFF)
        ::MessageBox(NULL, _T("ERROR: Wait for multiple objects failed!!!"), _T("browse"), MB_OK);
      else if(dwRet >= WAIT_OBJECT_0 && dwRet <= (WAIT_OBJECT_0 + m_dwCount - 1))
        RemoveThread(dwRet - WAIT_OBJECT_0);
      else if(dwRet == (WAIT_OBJECT_0 + m_dwCount))
      {
        ::GetMessage(&msg, NULL, 0, 0);
        if(msg.message == WM_USER)
          AddThread("", SW_SHOWNORMAL);
        else
          ::MessageBeep((UINT)-1);
      }
      else
        ::MessageBeep((UINT)-1);
    }

    return nRet;
  }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
  HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//  HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
  ATLASSERT(SUCCEEDED(hRes));

  // this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
  ::DefWindowProc(NULL, 0, 0, 0L);

  AtlInitCommonControls(ICC_BAR_CLASSES | ICC_DATE_CLASSES ); // add flags to support other controls

  hRes = _Module.Init(NULL, hInstance);
  ATLASSERT(SUCCEEDED(hRes));

  /*
    ATTENTION! ::HTMLayoutSetMasterCSS MUST be invoked only if there are no instances of 
    htmlayout created. Otherwise result is unpredictable.

    These lines are here for HTMLayoutSetMasterCSS testing purposes

    const char* mcss = // all gone except hyperlinks
        "a:link { text-decoration:underline; color:blue; cursor:pointer; behavior:hyperlink; }"
        "a:link:hover { color:red; }"
        "a:link:active { text-decoration:none; }";

    ::HTMLayoutSetMasterCSS((LPCBYTE)mcss,strlen(mcss));
  */


  /*
  // test of HTMLayoutDeclareElementType
  // see, html_samples/goodies/custom-tags.htm
  // <panel> is an analog of <div>
  ::HTMLayoutDeclareElementType("panel", BLOCK_BLOCK_ELEMENT);
  // <marked> is a sort of <span>
  ::HTMLayoutDeclareElementType("marked", INLINE_TEXT_ELEMENT);
  //<note> is a <p>
  ::HTMLayoutDeclareElementType("note", BLOCK_TEXT_ELEMENT);
  // <data> is an invisible data element
  ::HTMLayoutDeclareElementType("data", DATA_ELEMENT);
  */

  const char* mcss = // custom elements <checkbox>
      "marked {"
        "display-model: inline-inside;"
        "display: inline;"
        "background-color: lime;"
        "}"
      "checkbox {"
        "display-model: block-inside;"
        "display: inline-block;"
        "style-set: \"std-checkbox\"}"
      "panel {"
        "display-model: block-inside;"
        "display: block;"
        "}"
      "note {"
        "display-model: inline-inside;"
        "display: block;"
        "foreground-image: url(res:note-icon.png);" // this used for demonstrating HTMLayoutSetDataLoader below
        "foreground-repeat: no-repeat;"
        "foreground-position: 3px 50%;"
        "padding-left: 50px;"
        "min-height: 50px;"
        "vertical-align: middle;"
        "}";
      "data {"
        "display-model: inline-inside;"
        "display: block;"
        "visibility: collapsed;"
        "}";
  // set "Primordial" loader
  HTMLayoutSetDataLoader(&PrimordialDataLoader);
  HTMLayoutAppendMasterCSS((LPCBYTE)mcss,strlen(mcss));

  int nRet = 0;
  // BLOCK: Run application
  {
    CBrowseThreadManager mgr;
    nRet = mgr.Run(lpstrCmdLine, nCmdShow);
  }

  _Module.Term();
  ::CoUninitialize();

  return nRet;
}


/*struct toggler : htmlayout::behavior 
{ 
public: 
   toggler() : behavior( HANDLE_MOUSE, "toggler" ) { } 


   virtual BOOL handle_mouse( HELEMENT he, MOUSE_PARAMS &params ) 
  { 
     if (params.cmd != MOUSE_DOWN) return FALSE; 
     htmlayout::dom::element e( he ); 
     if (!e.is_valid()) return FALSE; 
     if (e.get_state( STATE_EXPANDED )) 
         e.set_state( STATE_COLLAPSED ); 
     else 
         e.set_state( STATE_EXPANDED ); 
     return TRUE; 
  } 
} togglerbehavior; */
