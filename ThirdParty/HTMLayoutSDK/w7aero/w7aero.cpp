// w7aero.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "w7aero.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

BOOL        GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb);
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_W7AERO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_W7AERO));

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
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEX wcex = {0};

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_W7AERO));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= NULL;//(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
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

HRESULT EnableBlurBehind(HWND hwnd)
{
   HRESULT hr = S_OK;

   //Create and populate the BlurBehind structre
   DWM_BLURBEHIND bb = {0};
   //Disable Blur Behind and Blur Region;
   bb.dwFlags = DWM_BB_ENABLE;
   bb.fEnable = true;
   bb.hRgnBlur = NULL;

   //Disable Blur Behind
   hr = DwmEnableBlurBehindWindow(hwnd, &bb);
   if (SUCCEEDED(hr))
   {
      //do more things
   }
   return hr;
}


HRESULT SetAeroTransparentBack(HWND hwnd)
{
   // Negative margins have special meaning to DwmExtendFrameIntoClientArea.
   // Negative margins create the "sheet of glass" effect, where the client area
   //  is rendered as a solid surface with no window border.
   MARGINS margins = {-1};
   HRESULT hr = S_OK;
   // Extend frame across entire window.
   hr = DwmExtendFrameIntoClientArea(hwnd,&margins);
   if (SUCCEEDED(hr))
   {
     // if succeeded configure htmlayout to draw on base with alpha. 
     HTMLayoutSetOption( hwnd, HTMLAYOUT_TRANSPARENT_WINDOW, TRUE);
   }
   return hr;
}

struct DOMEventsHandlerType: htmlayout::event_handler
{
      DOMEventsHandlerType(): event_handler(0xFFFFFFFF) {}
      virtual BOOL handle_event (HELEMENT he, BEHAVIOR_EVENT_PARAMS& params ) 
      { 
        switch( params.cmd )
        {
        //case BUTTON_CLICK:              OnButtonClick(params.heTarget); break;// click on button
        case BUTTON_PRESS:              break;// mouse down or key down in button
        case BUTTON_STATE_CHANGED:      break;
        case EDIT_VALUE_CHANGING:       break;// before text change
        case EDIT_VALUE_CHANGED:        break;//after text change
        case SELECT_SELECTION_CHANGED:  break;// selection in <select> changed
        case SELECT_STATE_CHANGED:      break;// node in select expanded/collapsed, heTarget is the node
        case POPUP_REQUEST: 
                                        break;// request to show popup just received, 
                                              //     here DOM of popup element can be modifed.
        case POPUP_READY:               break;// popup element has been measured and ready to be shown on screen,
                                              //     here you can use functions like ScrollToView.
        case POPUP_DISMISSED:           break;// popup element is closed,
                                              //     here DOM of popup element can be modifed again - e.g. some items can be removed
                                              //     to free memory.
        case MENU_ITEM_ACTIVE:                // menu item activated by mouse hover or by keyboard
             break;
        case MENU_ITEM_CLICK:                 // menu item click 
             break;


            // "grey" event codes  - notfications from behaviors from this SDK 
        case HYPERLINK_CLICK:           break;// hyperlink click
        case TABLE_HEADER_CLICK:        break;// click on some cell in table header, 
                                              //     target = the cell, 
                                              //     reason = index of the cell (column number, 0..n)
        case TABLE_ROW_CLICK:           break;// click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)
        case TABLE_ROW_DBL_CLICK:       break;// mouse dbl click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)

        case ELEMENT_COLLAPSED:         break;// element was collapsed, so far only behavior:tabs is sending these two to the panels
        case ELEMENT_EXPANDED:          break;// element was expanded,

        }
        return FALSE; 
      }
 
} DOMEventsHandler;

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

  LRESULT lResult;
  BOOL    bHandled = FALSE;

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
	/*case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
    {
      RECT r;
      GetClientRect(hWnd,&r);
      HBRUSH hb = CreateSolidBrush(0xffffffff);
      FillRect(hdc,&r,hb);
      DeleteObject(hb);
    }
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;*/
  case WM_CREATE:
    {
      //EnableBlurBehind ( hWnd );
      SetAeroTransparentBack ( hWnd );

      // Normally HTMLayout sends its notifications
      // to its parent. 
      // In this particular case we are using callback function to receive and
      // and handle notification. Don't bother the desktop window (parent of this window)
      // by our notfications.
      HTMLayoutSetCallback(hWnd,&HTMLayoutNotifyHandler,0);

      // attach DOM events handler so we will be able to receive DOM events like BUTTON_CLICK, HYPERLINK_CLICK, etc.
      //HTMLayoutWindowAttachEventHandler( hWnd, 
      //    DOMEventsHandler.element_proc, 
      //   &DOMEventsHandler, 
      //    DOMEventsHandler.subscribed_to);
      htmlayout::attach_event_handler(hWnd, &DOMEventsHandler);

      WCHAR path[2048] = L"file://"; 
      GetModuleFileNameW(NULL, &path[7], 2048 - 7);

      PBYTE pb; DWORD cb;
      if(GetHtmlResource("DEFAULT",pb,cb))
        HTMLayoutLoadHtmlEx(hWnd,pb,cb,path); // we use path here so all relative links in the document will resolved against it.

    } break;
  case WM_ERASEBKGND:
    return TRUE; // as HTMLayout will draw client area in full
  case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

BOOL GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb)
{
  // Find specified resource and check if ok

  HRSRC hrsrc = ::FindResourceA(hInst, pszName, MAKEINTRESOURCEA(RT_HTML));

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

LRESULT LoadResourceData(HWND hWnd, LPCWSTR uri )
{
    // Check for trivial case

    if (!uri || !uri[0]) return LOAD_DISCARD;

    if (wcsncmp( uri, L"res:", 4 ) == 0 )
      uri += 4;
    else
      return LOAD_OK; // it is not a "res:*" so proceed with the default loader

    // Retrieve url specification into a local storage since FindResource() expects
    // to find its parameters on stack rather then on the heap under Win9x/Me

    wchar_t achURL[MAX_PATH]; wcsncpy(achURL, uri, MAX_PATH);

    // Separate name and handle external resource module specification

    LPWSTR pszName = achURL;

    // Separate extension if any

    LPWSTR pszExt = wcsrchr(pszName, '.'); if (pszExt) *pszExt++ = '\0';

    // Find specified resource and leave if failed. Note that we use extension
    // as the custom resource type specification or assume standard HTML resource
    // if no extension is specified

    HRSRC hrsrc = 0;
    bool  isHtml = false;
    if( pszExt == 0 || wcsicmp(pszExt,L"HTML") == 0 )
    {
      hrsrc = ::FindResourceW(hInst, pszName, (LPCWSTR)RT_HTML);
      isHtml = true;
    }
    else
      hrsrc = ::FindResourceW(hInst, pszName, pszExt);

    if (!hrsrc) return LOAD_OK; // resource not found here - proceed with default loader

    // Load specified resource and check if ok

    HGLOBAL hgres = ::LoadResource(hInst, hrsrc);
    if (!hgres) return LOAD_DISCARD;

    // Retrieve resource data and check if ok

    PBYTE pb = (PBYTE)::LockResource(hgres); if (!pb) return LOAD_DISCARD;
    DWORD cb = ::SizeofResource(hInst, hrsrc); if (!cb) return LOAD_DISCARD;

    // Report data ready

    ::HTMLayoutDataReady(hWnd, uri, pb,  cb);

    return LOAD_OK;
  }

  LRESULT OnLoadData(LPNMHL_LOAD_DATA pnmld)
  {
    return LoadResourceData(pnmld->hdr.hwndFrom, pnmld->uri);
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
      case HLN_LOAD_DATA:         return OnLoadData((LPNMHL_LOAD_DATA) lParam);
      case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: break; //return OnDocumentComplete();
      case HLN_ATTACH_BEHAVIOR:   return OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}

LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
{
    // attach custom behaviors
    htmlayout::behavior::handle(lpab);
   
    // behavior implementations are located om /include/behaviors/ folder
    // to connect them into the chain of available 
    // behaviors - just include them into the project.
    return 0;
}



// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
