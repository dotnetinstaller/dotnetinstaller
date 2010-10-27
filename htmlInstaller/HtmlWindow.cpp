#include "StdAfx.h"

#include "HtmlWindow.h"
#include "Resource.h"

HtmlWindow::HtmlWindow() 
	: htmlayout::event_handler(HANDLE_BEHAVIOR_EVENT)
	, hwnd(NULL)
	, m_modal(false)
{

}

void HtmlWindow::Self(HWND hWnd, HtmlWindow * inst) 
{ 
	::SetWindowLongPtr(hWnd, GWLP_USERDATA, LONG_PTR(inst));

	if (s_hwnd == NULL || hWnd == NULL)
	{
		s_hwnd = hWnd;
	}
}

HtmlWindow * HtmlWindow::Self(HWND hWnd)
{ 
	return (HtmlWindow *) ::GetWindowLongPtr(hWnd, GWLP_USERDATA); 
}

HINSTANCE HtmlWindow::s_hinstance = 0;
HWND HtmlWindow::s_hwnd = NULL;

const wchar_t CLASSNAME[] = L"htmlInstaller::HtmlWindow";

ATOM  HtmlWindow::RegisterClass(HINSTANCE hInstance)
{
	s_hinstance = hInstance;

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc    = (WNDPROC) WinProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, (LPCTSTR) IDI_HTMLINSTALLER);
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = 0;
	wcex.lpszClassName  = CLASSNAME;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, (LPCTSTR) IDI_HTMLINSTALLER);

	return RegisterClassExW(&wcex);
}

void HtmlWindow::Create(const wchar_t * filename, int x, int y, int width, int height, const wchar_t * title) 
{
	m_title = title;

	CHECK_BOOL(hwnd == NULL,
		L"Static instance already created");

	UINT style = WS_POPUP | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_SIZEBOX;
	hwnd = CreateWindowExW(WS_EX_LAYERED, CLASSNAME, NULL, style , x, y, width, height, NULL, NULL, s_hinstance, NULL);
	CHECK_WIN32_BOOL(hwnd != NULL, 
		L"CreateWindowExW");
	
	Self(hwnd, this);
	HTMLayoutSetCallback(hwnd, & callback, this);
	
	std::wstring indexhtml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), filename);
	if (DVLib::FileExists(indexhtml))
	{
		CHECK_BOOL(HTMLayoutLoadFile(hwnd, indexhtml.c_str()),
			L"Error loading " << indexhtml);
	}
	else
	{
		PBYTE pb = NULL; 
		DWORD cb = 0;
		CHECK_BOOL(LoadResourceData(filename, pb, cb),
			L"Error loading index.html.");
		CHECK_BOOL(HTMLayoutLoadHtml(hwnd, pb, cb),
			L"Error loading index.html from " << DVLib::FormatBytesW(cb) << " of resource data.");
	}

	attach_event_handler(hwnd, this);
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

LRESULT HtmlWindow::on_document_complete()
{
	htmlayout::dom::element r = GetRoot();
	body = r.find_first("body");
	caption = r.get_element_by_id("caption");
	button_min = r.get_element_by_id("minimize");
	button_max = r.get_element_by_id("maximize");
	button_icon = r.get_element_by_id("icon");
	button_close = r.get_element_by_id("close");
	corner = r.get_element_by_id("corner");
	
	::SetWindowTextW(hwnd, m_title.c_str());
	if( caption.is_valid()) caption.set_text(m_title.c_str());

	OnDocumentComplete();
	return 0;
}

BOOL HtmlWindow::on_event(HELEMENT /* he */, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR /* reason */)
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

int HtmlWindow::OnMessage(UINT message, WPARAM /* wParam */, LPARAM /* lParam */)
{
	switch(message)
	{
	case WM_SHOWWINDOW:
		OnShow();
		break;
	case WM_CLOSE:
		m_modal = false;
		break;
	}

	return 0;
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

	if (me != NULL)
	{
		int mc = me->OnMessage(message, wParam, lParam);
		if (mc != 0)
		{
			return mc;
		}
	}

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
		Self(hwnd, 0);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT HtmlWindow::on_load_data(LPNMHL_LOAD_DATA pnmld)
{
	PBYTE pb; DWORD cb;
	if (LoadResourceData(pnmld->uri, pb, cb))
	{
		::HTMLayoutDataReady(pnmld->hdr.hwndFrom, pnmld->uri, pb,  cb);
	}
	return LOAD_OK;
}

bool HtmlWindow::LoadResourceData(LPCWSTR uri, PBYTE& pb, DWORD& cb)
{
    if (!uri || !uri[0]) 
	{
		return LOAD_DISCARD;
	}

	std::wstring name = uri;
	for(unsigned int i = 0; i < name.length(); i++)
	{
		switch(name[i])
		{
		case '.':
		case '/':
		case '\\':
			name[i] = '_';
			break;
		}
	}

    HRSRC hrsrc = ::FindResourceW(0, name.c_str(), L"HTM");
	if (! hrsrc)
	{
		hrsrc = ::FindResourceW(0, name.c_str(), L"CUSTOM");
	}

    if (! hrsrc) 
	{
		return false; // resource not found here - proceed with default loader
	}

    HGLOBAL hgres = ::LoadResource(0, hrsrc);
    if (!hgres) 
	{
		return false;
	}

    pb = (PBYTE)::LockResource(hgres); 
	if (!pb) 
	{
		return FALSE;
	}

    cb = ::SizeofResource(0, hrsrc); 
	if (! cb) 
	{
		return FALSE;
	}

    return true;
}

void HtmlWindow::ModalLoop()
{
	while(m_modal)
	{
		MSG msg;
		while (GetMessage(& msg, NULL, 0, 0) && m_modal)
		{
			htmlayout::queue::execute();
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

void HtmlWindow::DoModal()
{
	try
	{
		m_modal = true;

		ShowWindow(hwnd, 1);

		CHECK_WIN32_BOOL(UpdateWindow(hwnd),
			L"UpdateWindow");

		ModalLoop();
	}
	catch(std::exception& ex)
	{
		TRYLOG(L"Error: " << DVLib::string2wstring(ex.what()));
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		m_modal = false;
		::DestroyWindow(hwnd);
		throw ex;
	}
}
