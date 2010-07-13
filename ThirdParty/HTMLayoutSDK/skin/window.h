#ifndef __window_h__
#define __window_h__

#include "htmlayout.h"
#include <windowsx.h>

namespace htmlayout
{

class window: public event_handler,
              public notification_handler<window>
{
public:  
  HWND          hwnd;

  dom::element  body;
  dom::element  caption;
  dom::element  button_min;
  dom::element  button_max;
  dom::element  button_icon;
  dom::element  button_close;
  dom::element  corner;

  static  window* create( int x, int y, int width, int height, const wchar_t* caption = 0 );
  static  window* self(HWND hWnd) { return (window*)::GetWindowLongPtr(hWnd,GWLP_USERDATA); }

  void            set_caption( const wchar_t* text );

  static  ATOM              register_class(HINSTANCE hInstance);
protected:
  window(): event_handler(HANDLE_BEHAVIOR_EVENT) {}

  int       hit_test( int x, int y );
  HELEMENT  root();
  bool      is_minimized() const;
  bool      is_maximized() const;

  virtual BOOL  on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason );

  static  void              self(HWND hWnd, window* inst) { ::SetWindowLongPtr(hWnd,GWLP_USERDATA, LONG_PTR(inst)); }
  static  LRESULT CALLBACK  win_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  static  HINSTANCE         hinstance;




};


}

#endif