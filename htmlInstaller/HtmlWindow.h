#pragma once

class HtmlWindow 
	: public htmlayout::event_handler
	, public htmlayout::notification_handler<HtmlWindow>
{
public:  
	HWND hwnd;
	htmlayout::dom::element body;
	htmlayout::dom::element caption;
	htmlayout::dom::element button_min;
	htmlayout::dom::element button_max;
	htmlayout::dom::element button_icon;
	htmlayout::dom::element button_close;
	htmlayout::dom::element corner;
	virtual void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	static HtmlWindow * Self(HWND hWnd);
	void SetCaption(const wchar_t *);
	static ATOM RegisterClass(HINSTANCE hInstance);
protected:
	HtmlWindow();
	int HitTest(int x, int y);
	HELEMENT GetRoot();
	bool IsWindowMinimized() const;
	bool IsWindowMaximized() const;
	virtual BOOL on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
	static void Self(HWND hWnd, HtmlWindow * inst);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static HINSTANCE hinstance;
};
