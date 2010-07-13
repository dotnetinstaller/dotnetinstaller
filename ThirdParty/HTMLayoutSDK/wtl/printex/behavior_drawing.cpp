#include "htmlayout.h"
#include "htmlayout_dom.h"
#include "htmlayout_behavior.h"
#include "htmlayout_behavior.hpp"

#include <windows.h>

namespace htmlayout 
{

struct figure: public behavior
{
    // ctor
    figure(): behavior(HANDLE_DRAW, "figure") {}

    virtual BOOL on_draw   (HELEMENT he, UINT draw_type, HDC hdc, const RECT& rc ) 
    { 
      if( draw_type != DRAW_CONTENT )
        return FALSE; /*do default draw*/ 

      HGDIOBJ br = ::CreateSolidBrush(0xFF);
      HGDIOBJ obr = ::SelectObject(hdc,br);
      Ellipse(hdc, rc.left,rc.top,rc.right,rc.bottom);
      ::SelectObject(hdc,obr);
      return TRUE; /*skip default draw as we did it already*/ 
    }

   
};

// instantiating and attaching it to the global list
figure figure_instance;

} // htmlayout namespace


