/*
  Name:

    MemDC.h

  Author:

    Paul A. Howes
    Copyright (C) 2002 Fairware
    All Rights Reserved

  Description:

    This WTL-based class provides a memory-base device context.  This enables
    a developer to create all of a window's content in an invisible plane, and
    then update the entire window from this invisible plane in one pass.  The
    technique is commonly known as "double buffering", as the content of the
    invisible plane is held in a bitmap, which is copied to the visible
    window's device context in response to the WM_PAINT message.

  Note:

    Although Fairware claims a Copyright to this file and its contents,
    redistribution is welcome and encouraged, as long as this header remains.
*/


//  Guard against multiple inclusion.
#ifndef MEMDC_H
#define MEMDC_H


#ifndef __ATLGDI_H__
#error AtlGdi.h must be included before MemDC.h
#endif // __ATLGDI_H__


//  Allow the header precompiler to work more efficiently.
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


/*
  Name:

    CMemDC

  Description:

    A simple memory-based device context class for the WTL.  To use this in a
    window, create a member variable pointer of CMemDC.  Create the instance
    of the variable with "new" in the WM_PAINT handler for the window.  Delete
    the instance in the window class destructor.  Call the "Paint" function
    when the window is to be updated.  A sample implementation could be:

      class CSomeWindow : public CSomeWindowBase ...
      {
      public:

        CSomeWindow : CSomeWindowBase( ), m_memDC( 0 )
        {
        }

        ~CSomeWindow( )
        {
          if( m_memDC )
          {
            delete m_memDC;
          }
        }

        void OnPaint( HDC ) // parameter is unused.
        {
          //  Create the buffer if it does not already exist.
          if( ! m_memDC )
          {
            m_memDC = new CMemDC( *this );
          }

          //  Perform all window updates on the memory device context.

          //  Copy the memory DC to the window.
          m_memDC->Paint( );
        }

        private:

          //  The back-buffer.
          CMemDC m_memDC
      };
*/
class CMemDC : public CDC
{
public:


  /*
    Name:

      CMemDC

    Description:

      A constructor that creates the invisible device context and its
      associated bitmap buffer based on the provided window handle.

    Parameters:

      hWnd - A handle to the window that the buffer is based upon.
  */
  CMemDC( HWND hWnd )
  : CDC( )
  , m_bitmap( 0 )
  , m_hWnd( 0 )
  {
    ATLASSERT( hWnd );
    m_hWnd = hWnd;

    //  The size of the memory DC will fill the screen, if necessary.
    int width  = ::GetSystemMetrics( SM_CXSCREEN );
    int height = ::GetSystemMetrics( SM_CYSCREEN );

    //  Create the memory DC.
    CClientDC dc( hWnd );
    CreateCompatibleDC( dc );
    m_bitmap.CreateCompatibleBitmap( dc, width, height );
    SelectBitmap( m_bitmap );
  }


  /*
    Name:

      ~CMemDC

    Description:

      Object destructor.
  */
  virtual ~CMemDC( )
  {
  }


  /*
    Name:

      Paint

    Description:

      This function is called by the WM_PAINT message handle in the visible
      window to update it from this buffer.
  */
  void Paint( )
  {
    ATLASSERT( m_hWnd );
    CPaintDC dc( m_hWnd );
    RECT& rect = dc.m_ps.rcPaint;
    dc.BitBlt( rect.left, rect.top, rect.right, rect.bottom, *this, rect.left,
        rect.top, SRCCOPY );
  }


  /*
    Name:

      Repaint

    Description:

      If the visible window needs to update itself outside of the normal paint
      cycle, this function can be called.
  */
  void Repaint( )
  {
    ATLASSERT( m_hWnd );
    CClientDC dc( m_hWnd );
    RECT rect;
    ::GetClientRect( m_hWnd, &rect );
    dc.BitBlt( rect.left, rect.top, rect.right, rect.bottom, *this, rect.left,
        rect.top, SRCCOPY );
  }


private:

  CBitmap m_bitmap;
  HWND    m_hWnd;
};


#endif // MEMDC_H