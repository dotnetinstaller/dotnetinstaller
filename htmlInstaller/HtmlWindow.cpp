#include "StdAfx.h"

#include "HtmlWindow.h"
#include "Resource.h"

HtmlWindow::HtmlWindow() 
	: htmlayout::event_handler(HANDLE_BEHAVIOR_EVENT)
	, hwnd(NULL)
{

}

void HtmlWindow::Self(HWND hWnd, HtmlWindow * inst) 
{ 
	::SetWindowLongPtr(hWnd,GWLP_USERDATA, LONG_PTR(inst)); 
}

HtmlWindow * HtmlWindow::Self(HWND hWnd)
{ 
	return (HtmlWindow *) ::GetWindowLongPtr(hWnd,GWLP_USERDATA); 
}

HINSTANCE HtmlWindow::hinstance = 0;

const wchar_t CLASSNAME[] = L"htmlInstaller::HtmlWindow";

ATOM  HtmlWindow::RegisterClass(HINSTANCE hInstance)
{
	hinstance = hInstance;

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = (WNDPROC) WinProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, (LPCTSTR) IDI_HTMLINSTALLER);
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = 0;
	wcex.lpszClassName  = CLASSNAME;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, (LPCTSTR) IDI_HTMLINSTALLER_SMALL);

	return RegisterClassExW(&wcex);
}

void HtmlWindow::Create(int x, int y, int width, int height, const wchar_t * title) 
{
	CHECK_BOOL(hwnd == NULL,
		L"Static instance already created");

	UINT style = WS_POPUP | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_SIZEBOX;
	hwnd = CreateWindowExW(WS_EX_LAYERED, CLASSNAME, NULL, style , x, y, width, height, NULL, NULL, hinstance, NULL);
	CHECK_WIN32_BOOL(hwnd != NULL, 
		L"CreateWindowExW");
	
	Self(hwnd, this);
	HTMLayoutSetCallback(hwnd, & callback, this);
	
	std::wstring indexhtml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), TEXT("index.html"));
	if (DVLib::FileExists(indexhtml))
	{
		CHECK_BOOL(HTMLayoutLoadFile(hwnd, indexhtml.c_str()),
			L"Error loading " << indexhtml);
	}
	else
	{
		PBYTE pb = NULL; 
		DWORD cb = 0;
		CHECK_BOOL(htmlayout::load_resource_data(L"index.html", pb, cb),
			L"Error loading index.html.");
		CHECK_BOOL(HTMLayoutLoadHtml(hwnd, pb, cb),
			L"Error loading index.html from " << DVLib::FormatBytesW(cb) << " of resource data.");
	}

	htmlayout::dom::element r = GetRoot();
	body = r.find_first("body");
	caption = r.get_element_by_id("caption");
	button_min = r.get_element_by_id("minimize");
	button_max = r.get_element_by_id("maximize");
	button_icon = r.get_element_by_id("icon");
	button_close = r.get_element_by_id("close");
	corner = r.get_element_by_id("corner");
	attach_event_handler(hwnd, this);
	SetCaption(title);
}

void HtmlWindow::SetCaption(const wchar_t * text)
{
	if(text)
	{
		::SetWindowTextW(hwnd, text);
		if( caption.is_valid())
		{
			caption.set_text(text);
		}
	}
}

HELEMENT HtmlWindow::GetRoot()
{
	return htmlayout::dom::element::root_element(hwnd);
}

int HtmlWindow::HitTest(int x, int y)
{
	POINT pt; 
	pt.x = x; 
	pt.y = y;

	::MapWindowPoints(HWND_DESKTOP, hwnd, & pt, 1);

	if(caption.is_valid() && caption.is_inside(pt))
		return HTCAPTION;

	if(button_icon.is_valid() && button_icon.is_inside(pt))
		return HTSYSMENU;

	if(corner.is_valid() && corner.is_inside(pt))
		return HTBOTTOMRIGHT;

	RECT body_rc = body.get_location(ROOT_RELATIVE | CONTENT_BOX);

	if(PtInRect(&body_rc, pt))
		return HTCLIENT;

	if( pt.y < body_rc.top + 10 ) 
	{
		if( pt.x < body_rc.left + 10 ) 
			return HTTOPLEFT;
		if( pt.x > body_rc.right - 10 ) 
			return HTTOPRIGHT;
	}
	else if( pt.y > body_rc.bottom - 10 ) 
	{
		if( pt.x < body_rc.left + 10 )
			return HTBOTTOMLEFT;
		if( pt.x > body_rc.right - 10 ) 
			return HTBOTTOMRIGHT;
	}

	if( pt.y < body_rc.top ) 
		return HTTOP;
	if( pt.y > body_rc.bottom ) 
		return HTBOTTOM;
	if( pt.x < body_rc.left ) 
		return HTLEFT;
	if( pt.x > body_rc.right ) 
		return HTRIGHT;

	return HTCLIENT;
}

BOOL HtmlWindow::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
	
	if( type != BUTTON_CLICK)
		return FALSE; // handling only button clicks here. 

	if( target == button_min)
	{
		::ShowWindow(hwnd, SW_MINIMIZE); 
		return TRUE;
	}

	if( target == button_max)
	{
		if( IsWindowMaximized())
		{
			::ShowWindow(hwnd, SW_RESTORE); 
		}
		else
		{
			::ShowWindow(hwnd, SW_MAXIMIZE); 
		}

		return TRUE;
	}

	if(target == button_close)
	{
		::PostMessage(hwnd, WM_CLOSE, 0,0); 
		return TRUE;
	}

	// click on some other button
	htmlayout::dom::element button = target;
	//::MessageBoxW(button.get_element_hwnd(true) ,button.get_attribute("id"), L"Click on the button with id:", MB_OK);
	::MessageBox(button.get_element_hwnd(true), L"test", L"Click on the button with id:", MB_OK);

	return TRUE;
}

bool HtmlWindow::IsWindowMinimized() const
{
	WINDOWPLACEMENT wp;
	GetWindowPlacement(hwnd,&wp);
	return wp.showCmd == SW_SHOWMINIMIZED;
}

bool HtmlWindow::IsWindowMaximized() const
{
	WINDOWPLACEMENT wp;
	GetWindowPlacement(hwnd,&wp);
	return wp.showCmd == SW_SHOWMAXIMIZED;
}

LRESULT CALLBACK HtmlWindow::WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT lResult;
	BOOL    bHandled;

	// HTMLayout +
	// HTMLayout could be created as separate window 
	// using CreateWindow API.
	// But in this case we are attaching HTMLayout functionality
	// to the existing window delegating windows message handling to 
	// HTMLayoutProcND function.
	lResult = HTMLayoutProcND(hwnd,message,wParam,lParam, &bHandled);
	
	if(bHandled)
	{
		return lResult;
	}

	// HTMLayout -

	HtmlWindow * me = Self(hwnd);

	switch (message) 
	{

	case WM_NCHITTEST:
		if(me)
		{
		  return me->HitTest(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		}
		break;

	case WM_NCCALCSIZE:  
		return 0; // we have no non-client areas.
	case WM_NCPAINT:     
		return 0; // we have no non-client areas.
	case WM_NCACTIVATE:  
		return (wParam == 0)? TRUE : FALSE; // we have no non-client areas.
	case WM_GETMINMAXINFO:
	{
		LRESULT lr = DefWindowProc(hwnd, message, wParam, lParam);
		MINMAXINFO* pmmi = (MINMAXINFO*)lParam;
		pmmi->ptMinTrackSize.x = ::HTMLayoutGetMinWidth(hwnd);
		RECT rc; GetWindowRect(hwnd,&rc);
		pmmi->ptMinTrackSize.y = ::HTMLayoutGetMinHeight(hwnd, rc.right - rc.left);
		return lr;
	}
	case WM_CLOSE:
		::DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		delete me;
		Self(hwnd, 0);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
