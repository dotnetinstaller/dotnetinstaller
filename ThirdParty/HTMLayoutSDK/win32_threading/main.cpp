#include <windows.h>
#include <htmlayout.h>
#include <htmlayout_notifications.hpp>

#define class_name  L"MyClass"

HWND hWnd;
HELEMENT RootElement;
HELEMENT HE = NULL;

    class AsyncSetText: public htmlayout::gui_task {

        private:
          htmlayout::dom::element el;
          std::wstring str;

        public:
            AsyncSetText( HELEMENT he, std::wstring Str )
            { 
              el = he; 
              str = Str; 
            }

            virtual void exec() 
            { 
              el.set_text(str.c_str(),str.length());
            }

        };

DWORD
WINAPI
ThreadProc (
    IN      PVOID param
    )
{
    int counter = 0;
    std::wstring str;
    WCHAR buffer [10];

    while (TRUE) {

        counter++;
        _itow_s( counter,
                 buffer,
                 10,
                 10 );

        str = L"Counter: ";
        str += buffer;

        htmlayout::queue::push( new AsyncSetText( HE, str ),
                                hWnd );

        Sleep( 100 );

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

LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)
{
  // all HTMLayout notification are comming here.
  NMHDR*  phdr = (NMHDR*)lParam;

  switch(phdr->code)
  {
      case HLN_CREATE_CONTROL:    break; //return OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_CONTROL_CREATED:   break; //return OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_DESTROY_CONTROL:   break; //return OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
      case HLN_LOAD_DATA:         break;
      case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: break; //return OnDocumentComplete();
      case HLN_ATTACH_BEHAVIOR:   return OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}

LRESULT
CALLBACK
wnd_proc (
    IN      HWND   hwnd,
    IN      UINT   message,
    IN      WPARAM wParam,
    IN      LPARAM lParam
    )
{
    LRESULT result;
    BOOL    Handled;


    result = HTMLayoutProcND( hwnd,
                              message,
                              wParam,
                              lParam,
                              &Handled );
    if (Handled == TRUE)
        return result;

    switch (message) {

    case WM_ERASEBKGND:
        return TRUE;

    case WM_CLOSE:
        ::DestroyWindow( hwnd );
        break;

    case WM_DESTROY:
        ::PostQuitMessage( 0 );
        break;

    default:
        return DefWindowProc( hwnd,
                              message,
                              wParam,
                              lParam );

    }

    return 0;
}

BOOL
handle_event (
    IN      HELEMENT              he,
    IN      BEHAVIOR_EVENT_PARAMS &params
    )
{
    return FALSE;
}

 BOOL CALLBACK find_callback(HELEMENT he, LPVOID param)
 {
     HE = he;
     return TRUE;
 }

int
APIENTRY
WinMain (
    IN      HINSTANCE hInstance,
    IN      HINSTANCE hPrevInstance,
    IN      LPSTR     lpCmdLine,
    IN      int       nCmdShow
    )
{
    BOOL result;
    WNDCLASSEX window_class;
    MSG msg;

    //DefWindowProc(0, 0, 0, 0);

    //
    // Register class
    //
    window_class.cbSize          = sizeof( WNDCLASSEX );
    window_class.style           = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc     = (WNDPROC)wnd_proc;
    window_class.cbClsExtra      = 0;
    window_class.cbWndExtra      = 0;
    window_class.hInstance       = hInstance;
    window_class.hIcon           = LoadIcon( hInstance, (LPCTSTR)IDI_APPLICATION );
    window_class.hCursor         = LoadCursor( NULL, IDC_ARROW );
    window_class.hbrBackground   = (HBRUSH)( COLOR_WINDOW + 1 );
    window_class.lpszMenuName    = NULL;
    window_class.lpszClassName   = class_name;
    window_class.hIconSm         = LoadIcon( hInstance, (LPCTSTR)IDI_APPLICATION );

    if (RegisterClassExW( &window_class ) == 0) {

        hWnd = NULL;
        return -1;

    }

    //
    // Create window
    //
    hWnd = CreateWindow( class_name,
                         L"Just4Test",
                         WS_MINIMIZEBOX | WS_SYSMENU,
                         CW_USEDEFAULT,
                         CW_USEDEFAULT,
                         100,
                         100,
                         NULL,
                         NULL,
                         hInstance,
                         NULL );

    if (hWnd == NULL)
        return -1;

    ShowWindow( hWnd,
                SW_SHOW );

    UpdateWindow( hWnd );

    //
    // Set callback
    //
    HTMLayoutSetCallback( hWnd,
                          &HTMLayoutNotifyHandler,
                          NULL );

    //
    // Attach event handler
    //
    htmlayout::attach_event_handler( hWnd,
                                     NULL );

    if (HTMLayoutLoadFile( hWnd, L"test.html" ) == FALSE)
        return -2;

    RootElement = htmlayout::dom::root_element( hWnd );

    HTMLayoutVisitElements( RootElement,
                            NULL,
                            "id",
                            L"test_me",
                            &find_callback,
                            NULL,
                            0 );

    CreateThread( NULL,
                  0,
                  ThreadProc,
                  NULL,
                  0,
                  NULL );

    while( (result = GetMessage( &msg, (HWND)NULL, 0, 0 )) != 0) {

        if (result == -1)
            return result;

        htmlayout::queue::execute();

        TranslateMessage( &msg );
        DispatchMessage( &msg );

    }

    return msg.wParam;
}