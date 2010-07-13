// win64.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "win64.h"

#include "htmlayout.h"
#include "aux-cvt.h"

#include "commdlg.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                // current instance
TCHAR szTitle[MAX_LOADSTRING];                // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];                // The title bar text

// Foward declarations of functions included in this code module:
ATOM        MyRegisterClass(HINSTANCE hInstance);
BOOL        InitInstance(HINSTANCE, int);
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK  About(HWND, UINT, WPARAM, LPARAM);
BOOL        GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb);
LRESULT     HandleHyperlink( HWND hWnd, NMHL_HYPERLINK *pHL);
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
  // TODO: Place code here.
  MSG msg;
  HACCEL hAccelTable;

  // Initialize global strings
  LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
  LoadString(hInstance, IDC_WIN64, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass(hInstance);

  // Perform application initialization:
  if (!InitInstance (hInstance, nCmdShow)) 
  {
    return FALSE;
  }

  hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_WIN64);

  // Main message loop:
  while (GetMessage(&msg, NULL, 0, 0)) 
  {
    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX); 

  wcex.style      = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc  = (WNDPROC)WndProc;
  wcex.cbClsExtra   = 0;
  wcex.cbWndExtra   = 0;
  wcex.hInstance    = hInstance;
  wcex.hIcon      = LoadIcon(hInstance, (LPCTSTR)IDI_WIN64);
  wcex.hCursor    = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
  wcex.lpszMenuName = (LPCTSTR)IDC_WIN64;
  wcex.lpszClassName  = szWindowClass;
  wcex.hIconSm    = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

  return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void HandleOpenFile(HWND hwnd)
{
  OPENFILENAMEW ofn;       // common dialog box structure
  WCHAR szFile[260];      // buffer for file name

  // Initialize OPENFILENAME
  ZeroMemory(&ofn, sizeof(ofn));
  ofn.lStructSize = sizeof(ofn);
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = szFile;
  //
  // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
  // use the contents of szFile to initialize itself.
  //
  ofn.lpstrFile[0] = '\0';
  ofn.nMaxFile = sizeof(szFile) / sizeof(WCHAR);
  ofn.lpstrFilter = L"html\0*.htm\0";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = NULL;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = NULL;
  ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

  // Display the Open dialog box. 

  if (GetOpenFileNameW(&ofn)==TRUE) 
  {
    HTMLayoutLoadFile(hwnd,szFile);
  }
}


//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT  - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;

  LRESULT lResult;
  BOOL    bHandled;

// HTMLayout +
  // HTMLayout could be created as separate window 
  // using CreateWindow API.
  // But in this case we are attaching HTMLayout functionality
  // to the existing window delegating windows message handling to 
  // HTMLayoutProcND function.
  lResult = HTMLayoutProcND(hWnd,message,wParam,lParam, &bHandled);
  if(bHandled)
    return lResult;
// HTMLayout -

  switch (message) 
  {
    case WM_COMMAND:

      wmId    = LOWORD(wParam); 
      wmEvent = HIWORD(wParam); 
      // Parse the menu selections:
      switch (wmId)
      {
        case IDM_ABOUT:
           DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
           break;
        case ID_FILE_OPEN:
           HandleOpenFile(hWnd);
           break;
        case IDM_EXIT:
           DestroyWindow(hWnd);
           break;
      }
      break;

    case WM_ERASEBKGND:
      return TRUE; // as HTMLayout will draw client area in full

// HTMLayout +
    case WM_CREATE:
      {
        // Normally HTMLayout sends its notifications
        // to its parent. 
        // In this particular case we are using callback function to receive and
        // and handle notification. Don't bother the desktop window (parent of this window)
        // by our notfications.
        HTMLayoutSetCallback(hWnd,&HTMLayoutNotifyHandler,0);

        PBYTE pb; DWORD cb;
        if(GetHtmlResource("DEFAULT",pb,cb))
          HTMLayoutLoadHtml(hWnd,pb,cb);
      }
      break;

    case WM_BEHAVIOR_NOTIFY: //see behaviors/notifications.h
      if(  HLN_HYPERLINK == ((LPNMHDR)lParam)->code  ) 
      {
         return HandleHyperlink(hWnd, (NMHL_HYPERLINK*)lParam);
      }
      break;    

// HTMLayout -

    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
      {
        EndDialog(hDlg, LOWORD(wParam));
        return TRUE;
      }
      break;
  }
    return FALSE;
}


BOOL GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb)
{
  // Find specified resource and check if ok

  HRSRC hrsrc = ::FindResource(hInst, a2t(pszName), MAKEINTRESOURCE(RT_HTML));

  if(!hrsrc) 
    return false;

  // Load specified resource and check if ok
  
  HGLOBAL hgres = ::LoadResource(hInst, hrsrc);
  if(!hgres) return FALSE;

  // Retrieve resource data and check if ok

  pb = (PBYTE)::LockResource(hgres); if (!pb) return FALSE;
  cb = ::SizeofResource(hInst, hrsrc); if (!cb) return FALSE;

  return TRUE;
}

LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpAB );


// HTMLayout specific notification handler.
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)
{
  // all HTMLayout notification are comming here.
  NMHDR*  phdr = (NMHDR*)lParam;

  switch(phdr->code)
  {
      case HLN_CREATE_CONTROL:    break; //return OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_CONTROL_CREATED:   break; //return OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_DESTROY_CONTROL:   break; //return OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
      case HLN_LOAD_DATA:         break; //return OnLoadData((LPNMHL_LOAD_DATA) lParam);
      case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: break; //return OnDocumentComplete();
      case HLN_ATTACH_BEHAVIOR:   return OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}

LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
{
    // attach custom behaviors
    htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);
    if(pb) 
    {
      lpab->elementTag  = pb;
      lpab->elementProc = htmlayout::behavior::element_proc;
      lpab->elementEvents = pb->subscribed_to;
    }
    
    // this project includes two behavior implementationsL
    // behavior_hyperlink.cpp
    // behavior_command.cpp
    // to connect them into the chain of available 
    // behaviors - just include them into the project.
    return 0;
}

LRESULT     HandleHyperlink( HWND hWnd, NMHL_HYPERLINK *pHL)
{
    switch (pHL->action) 
    {
      case NMHL_HYPERLINK::ENTER: 
        break;
      case NMHL_HYPERLINK::LEAVE: 
        break;
      case NMHL_HYPERLINK::CLICK: 
        HTMLayoutLoadFile(hWnd,pHL->szHREF);
        break;
    }
    return 0;
}
