// dibexView.cpp : implementation of the CDibexView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "dibexView.h"

#include "memdc.h"

dibex img;

CDibexView::CDibexView()
{
  //img.load();
}

BOOL CDibexView::PreTranslateMessage(MSG* pMsg)
{
  pMsg;
  return FALSE;
}

LRESULT CDibexView::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
  CMemDC dc(m_hWnd);
  CRect rc; GetClientRect(&rc);

  dc.FillRect(&rc, HBRUSH(COLOR_WINDOW+1) );

  if(!img.is_valid())
  {
    dc.DrawText( "no image", 8, &rc, DT_VCENTER | DT_CENTER | DT_SINGLELINE );
  }
  else
  {
    CPoint dst( (rc.Width() - img.width()) / 2, (rc.Height() - img.height()) / 2 );
    img.render(dc,dst);
  }
  dc.Paint();
  return 0;
}
