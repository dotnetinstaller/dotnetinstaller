#ifndef __html_canvas_h__
#define __html_canvas_h__

#include "htmprint.h"

/* simple windowless html renderer */

class html_canvas: private PrintEx
{
  int  page_no;
  int  page_count;
  int  measured_width;
  int  measured_height;
  int  meauserd_nHTMLPx; // HTML/CSS pixel is a logical unit, there are 96px in 1in
                         // so for "letter" paper it is: 
                         // 8.5in * 96 = 816px in printer page width 
  bool valid;
public:

  html_canvas(): page_no(0), page_count(0), measured_width(0), measured_height(0),valid(false),meauserd_nHTMLPx(0) {}

  bool load_html(const char* url)
  {
    page_no = 0;
    page_count = 0;
    measured_width = 0;
    measured_height = 0;
    valid = PrintEx::load(url);

    if(valid)
    {
      htmlayout::dom::element el = getRootElement();
      htmlayout::dom::element title = el.find_first("title");
      if(title.is_valid())
        ATLTRACE(TEXT("title: %s\n"), CString(title.text()));
      
    }
    return valid;
  }

  bool load_html(LPCBYTE data, UINT length)
  {
    page_no = 0;
    page_count = 0;
    measured_width = 0;
    measured_height = 0;
    valid = PrintEx::load(data, length, "");

    if(valid)
    {
      htmlayout::dom::element el = getRootElement();
      htmlayout::dom::element title = el.find_first("title");
      if(title.is_valid())
        ATLTRACE(TEXT("title: %s\n"), CString(title.text()));
      
    }
    return valid;
  }


  bool inc_page_no(int i)
  {
    bool r = true;
    page_no += i;
    if(page_no >= page_count) { page_no = page_count - 1; r = false; }
    if(page_no < 0) { page_no = 0; r = false; }
    return r;
  }

  int get_page_count()
  {
    return page_count;
  }

  bool render(HDC hdc, RECT dst)
  {
    if(!valid)
      return false;

    int width = dst.right - dst.left;
    int height = dst.bottom - dst.top;

    if(measured_width != width ||
       measured_height != height)
    {
      // measure it
      page_count = 
        PrintEx::measure(hdc,
        816, 
        width,
        height);

       measured_width = width;
       measured_height = height;
    }

    //assert(page_count);
    //assert(page_no < page_count);

    if(page_no >= page_count)
      page_no = page_count - 1;
    if(page_no < 0)
      return false;
    // rendering first page on the metafile
    PrintEx::render(hdc,dst.left, dst.top, page_no);
    
    
    return true;

  }

  bool render(HDC hdc, RECT dst, int numOfHTMLPxInPrintingArea)
  {
    if(!valid)
      return false;

    int width = dst.right - dst.left;
    int height = dst.bottom - dst.top;

    if(measured_width != width ||
       measured_height != height ||
       meauserd_nHTMLPx != numOfHTMLPxInPrintingArea)
    {
      // measure it
      page_count = 
        PrintEx::measure(hdc,
        numOfHTMLPxInPrintingArea, 
        width,
        height);

       measured_width = width;
       measured_height = height;
    }

    //assert(page_count);
    //assert(page_no < page_count);

    if(page_no >= page_count)
      page_no = page_count - 1;
    if(page_no < 0)
      return false;
    // rendering first page on the metafile
    PrintEx::render(hdc,dst.left, dst.top, page_no);
    
    
    return true;

  }

  virtual void onNextPage(unsigned int pageNo, int pageViewportOffsetY, unsigned int& pageViewportHeight)
  {
     // for testing purposes: each odd page is twice shorter
     //if (pageNo & 1) 
     //  pageViewportHeight /= 2;
    htmlayout::dom::element root = getRootElement();
    htmlayout::dom::element body = root.find_first("body");
    RECT rcBody = body.get_location();
    if( unsigned(rcBody.bottom) < (pageViewportOffsetY + pageViewportHeight))
    {  
       // this is the last page.
       int lastPageContent = rcBody.bottom - pageViewportOffsetY;
    } 

  }

  virtual LRESULT on_load_data(LPNMHL_LOAD_DATA pnmld)
  {
    return 0;
  }

  

};


#endif