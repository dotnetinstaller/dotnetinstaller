//-----------------------------------------------------------------------------
//           Name: HTMLayout_DirectX.cpp
//         Author: David Suede (David.Suede@PicClique.com)
//  Last Modified: 2007/03/05
//
//    Description: This sample demonstrates how to use HTMLayout and its 
//          HTMLite API with Direct3D.  There is little error
//                  checking in this code.
//                
//          
//          Notes: Drag and drop HTML files into the window to see them.
//                 Basic mouse and keyboard events are sent to HTMLayout.   
//
//
//-----------------------------------------------------------------------------

#pragma comment(lib, "d3d8.lib")
#pragma comment(lib, "d3dx8.lib")

#pragma comment(lib, "winmm.lib")   //for multimedia timer

// this is a .NET 2003 problem, it wants libci, so set to ignore this demand
#pragma comment(linker,"/NODEFAULTLIB:libci.lib")

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <d3d8.h>
#include <d3dx8.h>
#include <mmsystem.h>

#include <wchar.h>

#pragma comment(lib, "../HTMLayout_3.1.2.7/lib/HTMLayout.lib")

#include "../HTMLayout_3.1.2.7/include/htmlite.h"

//#include "../HTMLayout/include/behaviors/behavior_css-popup.cpp"
//#include "../HTMLayout/include/behaviors/behavior_popup.cpp"
//#include "../HTMLayout/include/behaviors/behavior_expandable_list.cpp"

#pragma warning(disable: 4311)  // converting LPSTR to DWORD

//-----------------------------------------------------------------------------
// DEFINES
//-----------------------------------------------------------------------------

#define         HTML_WIDTH    512     // dimensions of our HTML canvas
#define         HTML_HEIGHT   512

#define         WIN_WIDTH   640     //size of window
#define         WIN_HEIGHT    640


#define         WMU_HTML_TIMER_IDLE   WM_APP + 1

//-----------------------------------------------------------------------------
// GLOBALS
//-----------------------------------------------------------------------------
HWND                    g_hWnd          = NULL;   //main window
LPDIRECT3D8             g_pD3D          = NULL;   
LPDIRECT3DDEVICE8       g_pd3dDevice    = NULL;
LPDIRECT3DVERTEXBUFFER8 g_pVertexBuffer = NULL;
LPDIRECT3DTEXTURE8      g_pTexture      = NULL;


int           g_nDXWidth;     // size of DX area. Will be slightly smaller than window dimesions.
int           g_nDXHeight;

HBITMAP         g_hBmp;       // bitmap that will hold the current temporary html image
void*         g_pFrameBuffer;   // pointer to the data in the bitmap
RECT          g_rInvalid;     // rect of area on HTML canvas that need updating

//-----------------------------------------------------------------------------
// PROTOTYPES
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
           LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void CALLBACK HTMLiteTimerProc(HWND hWnd, UINT msg, UINT idEvent, DWORD dwTime);
void CALLBACK MMTimeProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);

bool CreateTexture(void);
void InitDirectX(void);
void ShutDown(void);
void Render(void);
bool RenderHtmlToDXTexture(RECT* pRect);


// This is to handle mouse cursor change requests from HTMLayout
static DWORD cursor_ids[] = 
{
    (DWORD) IDC_ARROW,
    (DWORD) IDC_IBEAM,
    (DWORD) IDC_WAIT,
    (DWORD) IDC_CROSS,
    (DWORD) IDC_UPARROW,
    (DWORD) IDC_SIZENWSE,
    (DWORD) IDC_SIZENESW,
    (DWORD) IDC_SIZEWE,
    (DWORD) IDC_SIZENS,
    (DWORD) IDC_SIZEALL,
    (DWORD) IDC_NO,
    (DWORD) IDC_APPSTARTING,
    (DWORD) IDC_HELP,
    (DWORD) IDC_HAND,   
};


class CHTML :   public HTMLite        
{
public:
  
protected:

  void handleRefreshArea( LPNMHL_REFRESH_AREA pn )
  {
    //expand our invalid rectangle to accomidate this new request.

    //if the rectangle didn't previously have any area
    if (g_rInvalid.top == -1 && g_rInvalid.bottom == -1 && g_rInvalid.left ==-1 && g_rInvalid.right == -1){
      g_rInvalid = pn->area;
    }else{  
      //add the new area to the old area
      if (pn->area.top  < g_rInvalid.top)   g_rInvalid.top    = pn->area.top;
      if (pn->area.bottom > g_rInvalid.bottom)  g_rInvalid.bottom = pn->area.bottom;
      if (pn->area.left < g_rInvalid.left)  g_rInvalid.left   = pn->area.left;
      if (pn->area.right  > g_rInvalid.right) g_rInvalid.right  = pn->area.right;     
    }
  } 

  void handleSetTimer( LPNMHL_SET_TIMER pn )
   {
    //send an idle message.
    if ((pn->timerId == 0) && (pn->elapseTime == 1)){
      
      PostMessage(g_hWnd, WMU_HTML_TIMER_IDLE, 0,0);
      return;
    }

    if( pn->elapseTime){

      UINT_PTR nRes = SetTimer(g_hWnd, pn->timerId, pn->elapseTime, &HTMLiteTimerProc);
      if (!nRes) OutputDebugString("ERROR: SetTimer failed");
        
    }else{
      KillTimer(g_hWnd,pn->timerId);
    }
    
  }
  
  void handleSetCursor( LPNMHL_SET_CURSOR pn )
  { 
    SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(cursor_ids[pn->cursorId])));    
  }

  void handleUpdate()
  {
    //used with animations.  HTMLite will call this during traverseTimerEvent 
    // to signal it's ready to be drawn to screen.

    RenderHtmlToDXTexture(&g_rInvalid);

  }

 


};

CHTML*    g_pHtml;  //global of this class


// stucture to hold our 3d points for our 3d quad
struct Vertex
{
    float x, y, z;
    float tu, tv;
};

Vertex g_quadVertices[] =
{
  { - HTML_WIDTH / 2,   HTML_HEIGHT / 2, 0.0f,  0.0f,  0.0f },
  {   HTML_WIDTH / 2,   HTML_HEIGHT / 2, 0.0f,  1.0f,  0.0f },
  { - HTML_WIDTH / 2, - HTML_HEIGHT / 2, 0.0f,  0.0f,  1.0f },
  {   HTML_WIDTH / 2, - HTML_HEIGHT / 2, 0.0f,  1.0f,  1.0f }
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_TEX1)


//handle timer messages that we created in handleSetTimer
/*void CALLBACK HTMLiteTimerProc(HWND hWnd, UINT msg, UINT idEvent, DWORD dwTime)
{
  

  if (idEvent <= 1){
    KillTimer(hWnd, idEvent);
  }

  //if returned false, kill the timer.
  if (!g_pHtml->traverseTimerEvent(idEvent) && idEvent != 1){ 
    // only kill timer on traverseTimerEvent return false if it's not a pulse event
    //  (pulse events are always timerId == 1)
    KillTimer(hWnd,idEvent);
  }

  // this only seems to be needed for repeat timer events, like caret blinking.
  RenderHtmlToDXTexture(&g_rInvalid);

}*/

void CALLBACK HTMLiteTimerProc(HWND hWnd, UINT msg, UINT idEvent, DWORD dwTime)
{
  switch( nIDEvent )
  {
    case  TIMER_IDLE_ID: 
    case  TIMER_ANIMATION_ID:
      KillTimer(idEvent); // These are one shot timers so we need to kill them anyway.
                          // We must do it before traverseTimerEvent() call as it may want 
                          // to create timers with the same id.
      g_pHtml->traverseTimerEvent(idEvent);
      break;
    default: // these are normal timers
      BOOL cont = g_pHtml->traverseTimerEvent(idEvent)
      if (!cont) 
        KillTimer(idEvent);
      break;
  }
  // this only seems to be needed for repeat timer events, like caret blinking.
  RenderHtmlToDXTexture(&g_rInvalid);

}


//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
int WINAPI WinMain( HINSTANCE hInstance,
          HINSTANCE hPrevInstance,
          LPSTR     lpCmdLine,
          int       nCmdShow )
{
  WNDCLASSEX winClass;
  MSG        uMsg;

    memset(&uMsg,0,sizeof(uMsg));
    
  winClass.lpszClassName = "MY_WINDOWS_CLASS";
  winClass.cbSize        = sizeof(WNDCLASSEX);
  winClass.style         = CS_HREDRAW | CS_VREDRAW;
  winClass.lpfnWndProc   = WindowProc;
  winClass.hInstance     = hInstance;
  winClass.hIcon         = NULL;
    winClass.hIconSm     = NULL; 
  winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
  winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  winClass.lpszMenuName  = NULL;
  winClass.cbClsExtra    = 0;
  winClass.cbWndExtra    = 0;

  if( !RegisterClassEx(&winClass) )
    return E_FAIL;

  g_hWnd = CreateWindowEx( WS_EX_ACCEPTFILES
              , "MY_WINDOWS_CLASS", 
                             "HTMLayout using Direct3D (DX8)",
                 WS_OVERLAPPED   | WS_VISIBLE | WS_SYSMENU,
                   0, 0, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL );

  if( g_hWnd == NULL )
    return E_FAIL;


  
  InitDirectX();

  //clear our invalid rect.
  g_rInvalid.top = -1; g_rInvalid.bottom = -1; g_rInvalid.left =-1; g_rInvalid.right = -1;

  //create out BITMAP that will temporarily hold our html rendered image
  //set the bitmap header info
  BITMAPINFO binfo;
  memset(&binfo,0,sizeof(binfo));
  binfo.bmiHeader.biSize=sizeof(binfo);
  binfo.bmiHeader.biPlanes=1;
  binfo.bmiHeader.biBitCount=32;
  binfo.bmiHeader.biCompression=BI_RGB;
  binfo.bmiHeader.biHeight= HTML_HEIGHT;
  binfo.bmiHeader.biWidth= HTML_WIDTH;
  
  //create our bitmap buffer that HTMLite will render to
  g_hBmp = CreateDIBSection(NULL, (BITMAPINFO*)&binfo, DIB_RGB_COLORS,&g_pFrameBuffer, NULL, 0);
  if (!g_hBmp){
    return E_FAIL;
  }
  
  char* welcome = "<html><body style='text-align:center;vertical-align:middle'>"
          "<b>Drag and drop HTML files onto this window to load them.</b>"
          "</body></html>"; 

  int nWidth, nHeight;
  
  g_pHtml = new CHTML();

  if (!g_pHtml->load((LPCBYTE)welcome, (DWORD)strlen(welcome))){
    return E_FAIL;
  }
  
  //tell HTMLite how big our target render area should be.
  //  this needs to be called before the getDocumentMinHeight funcs
  g_pHtml->measure(HTML_WIDTH,HTML_HEIGHT);

  // Find out the minimum dimensions of the HTML canvas before scrollbars appear
  nHeight = g_pHtml->getDocumentMinHeight();
  nWidth = g_pHtml->getDocumentMinWidth();

  // At this point you could call g_pHtml->measure again to change dimensions so
  //  the html fits on the canvas without scrollbars


  //draw the HTML to our DX texture.  From this point on, only mouse,keyboard and timer events will call this.
  RenderHtmlToDXTexture(&g_rInvalid);


    ShowWindow( g_hWnd, nCmdShow );
    UpdateWindow( g_hWnd );

  while( uMsg.message != WM_QUIT )
  {
    if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
    { 
      TranslateMessage( &uMsg );
      DispatchMessage( &uMsg );
    }
    else
    {
      Render();
    }
  }

  ShutDown();

    UnregisterClass( "MY_WINDOWS_CLASS", winClass.hInstance );

  return (int)uMsg.wParam;
}

//-----------------------------------------------------------------------------
// Name: WindowProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT CALLBACK WindowProc( HWND   hWnd, 
               UINT   msg, 
               WPARAM wParam, 
               LPARAM lParam )
{
  POINT p;

  UINT nKeyEvent;

    switch( msg )
  { 

    ///////// HTMLAYOUT IDLE TIMER MSGS
    case WMU_HTML_TIMER_IDLE:
      g_pHtml->traverseTimerEvent(0);
    break;
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MOUSEMOVE:

      p.x = (short)LOWORD(lParam);
      p.y = (short)HIWORD(lParam);

      //check if mouse is over the canvas area
      if ((p.x > (g_nDXWidth / 2 - HTML_WIDTH / 2)) && (p.x < (g_nDXWidth / 2 + HTML_WIDTH / 2)) &&
        (p.y > (g_nDXHeight / 2 - HTML_HEIGHT / 2)) && (p.y < (g_nDXHeight / 2 + HTML_HEIGHT / 2))){

        //HTMLite wants co-ords zero based from the top left of canvas.
        //  Since our texture isn't moving in 3D space, we can simply translate the mouse co-ords.
        //  If our texture was moving around, you could use find where the mouse intersect the texture
        //  by using picking techniques, eg: http://toymaker.info/Games/html/picking.html
        p.x -= (g_nDXWidth / 2 - HTML_WIDTH / 2);
        p.y -= (g_nDXHeight / 2 - HTML_HEIGHT / 2);
        
        UINT nMouseButton = 0;
        

        //get the actual mouse event to send
        UINT nMouseEvent = 0;
        if  (msg == WM_MOUSEMOVE){
        
          nMouseEvent = MOUSE_MOVE;
          //get the button state.  This only work with WM_MOUSEMOVE
          if    (wParam & MK_LBUTTON)   nMouseButton = MAIN_MOUSE_BUTTON;
          else if (wParam & MK_MBUTTON)   nMouseButton = PROP_MOUSE_BUTTON;
          else if (wParam & MK_RBUTTON)   nMouseButton = MIDDLE_MOUSE_BUTTON;

        }else if  (msg == WM_LBUTTONDOWN){
          nMouseEvent = MOUSE_DOWN;
          nMouseButton = MAIN_MOUSE_BUTTON;
        }
        else if   (msg == WM_LBUTTONUP){
          nMouseEvent = MOUSE_UP;
          nMouseButton = MAIN_MOUSE_BUTTON;
        }

        // Send mouse and keyboard events to HTMLayout.
        g_pHtml->traverseMouseEvent(nMouseEvent, p, nMouseButton, 0);     

        //draw HTML canvas, if needed
        if (g_rInvalid.right != -1 || g_rInvalid.left != -1){
          RenderHtmlToDXTexture(&g_rInvalid);
          //reset our rect
          g_rInvalid.top = -1; g_rInvalid.bottom = -1; g_rInvalid.left =-1; g_rInvalid.right = -1;
        }

      }
    break;

    case WM_CHAR: 
    case WM_KEYUP:
    case WM_KEYDOWN:

      if    (msg == WM_CHAR)  nKeyEvent = KEY_CHAR;
      else if (msg == WM_KEYUP) nKeyEvent = KEY_UP;
      else            nKeyEvent = KEY_DOWN;
      
      if ( wParam == VK_ESCAPE){
        PostQuitMessage(0);
      }

      if (!g_pHtml->traverseKeyboardEvent(nKeyEvent,(UINT)wParam,0)){
        OutputDebugString("traverseKeyboardEvent returned false\n");
      }else{
        OutputDebugString("traverseKeyboardEvent returned true\n");
      }

      //draw HTML canvas, if needed
      RenderHtmlToDXTexture(&g_rInvalid);
      
    break;

    case WM_DROPFILES:
    {
      /////drag and drop business.
      HDROP hDrop = (HDROP)wParam;
      char szFilename[MAX_PATH];
      // Get the filename from the HDROP info.
      if ( DragQueryFile ( hDrop, 0, szFilename, MAX_PATH ) > 0 )
      {           
        WCHAR wsz [MAX_PATH];
        MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szFilename, -1, wsz, MAX_PATH);
        if (!g_pHtml->load(wsz)){
          // failed?  
        }       
        //tell HTMLite how big our target render area should be.
        g_pHtml->measure(HTML_WIDTH,HTML_HEIGHT);

        //Draw the HTML canvas
        RenderHtmlToDXTexture(&g_rInvalid);
      }
      // Free up memory.
      DragFinish ( hDrop );
    }

    break;

    case WM_CLOSE:
        case WM_DESTROY: PostQuitMessage(0); break;

    default:
    {
      return DefWindowProc( hWnd, msg, wParam, lParam );
    }
    break;
  }

  return 0;
}

//-----------------------------------------------------------------------------
// Name: CreateTexture()
// Desc: Creates a d3d texture for g_pTexture
//-----------------------------------------------------------------------------
bool CreateTexture(void)
{
  HRESULT hr = D3DXCreateTexture(
      g_pd3dDevice,
      HTML_WIDTH,
      HTML_HEIGHT,
      1,
      
      //D3DUSAGE_DYNAMIC,
      0,

      D3DFMT_A8R8G8B8,
      //D3DPOOL_DEFAULT,
      D3DPOOL_MANAGED,  //D3DPOOL_DEFAULT wont allow us to LockRect with D3DLOCK_DISCARD 
      &g_pTexture);


  if (!g_pTexture) return false;
  
  //since we only copy parts of the html canvas at a time, clear the texture to begin with.
  // NOTE: is this needed?  I think HTMLite draws entire canvas on load anyway.

  //lock our texture so we can write directly to it
  D3DSURFACE_DESC d3dsd;
  g_pTexture->GetLevelDesc(0, &d3dsd);
  D3DLOCKED_RECT rcLockedRect = { 0 };
  hr = g_pTexture->LockRect(0, &rcLockedRect,
    NULL,
    0);

  //blank our memory
  ZeroMemory(rcLockedRect.pBits, rcLockedRect.Pitch * (HTML_HEIGHT -1));

  g_pTexture->UnlockRect(0);

  return true;
}

//-----------------------------------------------------------------------------
// Name: InitDirectX()
// Desc: sets up D3D 
//-----------------------------------------------------------------------------
void InitDirectX( void )
{
    g_pD3D = Direct3DCreate8( D3D_SDK_VERSION );

    D3DDISPLAYMODE d3ddm;

    g_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm );

    D3DPRESENT_PARAMETERS d3dpp;

    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed               = TRUE;
    d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat       = d3ddm.Format;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
                          D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                          &d3dpp, &g_pd3dDevice );


  

  //get the dimensions of the directx window
  IDirect3DSurface8* pBackBuffer = NULL;
  g_pd3dDevice->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
  D3DSURFACE_DESC Desc;
  pBackBuffer->GetDesc(&Desc);
  g_nDXWidth = Desc.Width;
  g_nDXHeight = Desc.Height;

  pBackBuffer->Release();

  //Create our texture that we'll be displaying
  if (!CreateTexture()){
    MessageBox(NULL,"Error creating Texture", "", MB_OK);
  }

  // Create vertex buffer for our quad
  g_pd3dDevice->CreateVertexBuffer( 4*sizeof(Vertex), D3DUSAGE_WRITEONLY, 
                                      D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, 
                                      &g_pVertexBuffer );

    Vertex* pVertices = NULL;
    g_pVertexBuffer->Lock( 0, sizeof(g_quadVertices), (BYTE**)&pVertices, 0 );
    memcpy( pVertices, g_quadVertices, sizeof(g_quadVertices) );
    g_pVertexBuffer->Unlock();
  



    D3DXMATRIX matProj;
  D3DXMatrixPerspectiveFovLH( &matProj, 45.0f, 1.0f, 0.1f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );

  g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
  g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

  //set this for wireframe
  //g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_WIREFRAME );
}

//-----------------------------------------------------------------------------
// Name: shutDown()
// Desc: 
//-----------------------------------------------------------------------------
void ShutDown( void )
{
  if (g_pHtml != NULL){
    g_pHtml->destroy();
    delete g_pHtml;
    g_pHtml = NULL;
  }

  if (g_hBmp != NULL)
    DeleteObject(g_hBmp);

    if( g_pTexture != NULL ) 
        g_pTexture->Release();

    if( g_pVertexBuffer != NULL ) 
        g_pVertexBuffer->Release(); 

    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();
}

//-----------------------------------------------------------------------------
// Name: render()
// Desc: 
//-----------------------------------------------------------------------------
void Render( void )
{
  //the background blue component cycles, to illustrate the alpha channel of the texture above it
  float fBlue = (sin((float)timeGetTime()/ 1200.0f) / 2.0f) + 0.5f;
    
  g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                         D3DCOLOR_COLORVALUE(0.0f,0.0f,fBlue,1.0f), 1.0f, 0 );
  
  //setup the camera
  D3DXMATRIX matOrtho;  
  D3DXMATRIX matIdentity;
  
  D3DXMatrixOrthoLH(&matOrtho, (FLOAT)g_nDXWidth,(FLOAT)g_nDXHeight, 0.0f, 1.0f);
  D3DXMatrixIdentity(&matIdentity);

  g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matOrtho);
  g_pd3dDevice->SetTransform(D3DTS_WORLD, &matIdentity);
  g_pd3dDevice->SetTransform(D3DTS_VIEW, &matIdentity);

  //Make sure that the z-buffer and lighting are disabled
  g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
  g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);


  g_pd3dDevice->BeginScene();

  
  ///// Use the alpha channel
  g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
  g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
  g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,TRUE); 
  /////////

  //draw our quad
  g_pd3dDevice->SetTexture( 0, g_pTexture );
    g_pd3dDevice->SetStreamSource( 0, g_pVertexBuffer, sizeof(Vertex) );
    g_pd3dDevice->SetVertexShader( D3DFVF_CUSTOMVERTEX );
  g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP,  0, 2 );

    g_pd3dDevice->EndScene();
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

//-----------------------------------------------------------------------------
// Name: RenderHtmlToDXTexture()
// Desc: Renders the loaded html document to the global bitmap,
//       then copies the data to the global directx texture.
//       rcArea is the area to render/copy.
//-----------------------------------------------------------------------------
bool RenderHtmlToDXTexture(RECT* rcArea)
{
  //this is called after mouse and keyboard events.
  //  Since these events dont always cause redraws, only redraw
  //  if our invalid rectangle has an area.
  if (rcArea->top == -1 && rcArea->bottom == -1 && rcArea->left ==-1 && rcArea->right == -1){
    return false;
  }

  ///////////// BOUND CHECKS ///////////////////////////
  //check if either top or bottom are less than zero.
  //  if so, ignore.  
  if ((rcArea->top < 0) || (rcArea->bottom < 0)){
    // ?? no idea why this is happening.
    //return true;
  }
  if (rcArea->top < 0) rcArea->top = 0;
  if (rcArea->left < 0) rcArea->left = 0;
  if (rcArea->bottom > HTML_HEIGHT) rcArea->bottom = HTML_HEIGHT;
  if (rcArea->right > HTML_WIDTH) rcArea->right = HTML_WIDTH;

  int nHeight = rcArea->bottom - rcArea->top;
  int nWidth  = rcArea->right - rcArea->left;

  if ((nHeight < 1) || (nWidth < 1)) return true;
  ///////// END CHECKS ///////////////

  //Render the HTML to our bitmap.
  g_pHtml->render(g_hBmp,rcArea->left,rcArea->top,nWidth,nHeight);
  
  //lock our texture so we can write directly to it
  D3DSURFACE_DESC d3dsd;
  g_pTexture->GetLevelDesc(0, &d3dsd);
  D3DLOCKED_RECT rcLockedRect = { 0 };
  HRESULT hr = g_pTexture->LockRect(0, &rcLockedRect,
    rcArea,
    D3DLOCK_NOSYSLOCK
    //D3DLOCK_DISCARD
    );

  if (hr != D3D_OK){
    if (hr == D3DERR_INVALIDCALL){
      //  lg4 << "Error: LockRect failed. D3DERR_INVALIDCALL, one or more of the arguments are invalid";
    }else{
      //  lg4 << "Error: LockRect failed (unkown)";
    }
    return false;
  }

  //start our bitmap pointer where the refresh area begins.
  DWORD* pBitmapBits = (DWORD*)g_pFrameBuffer + (HTML_HEIGHT - rcArea->bottom) * HTML_WIDTH + rcArea->left;
  
  BYTE*  pTextureBits = (BYTE*)rcLockedRect.pBits;
  
  // we now have access to the bits in our DX texture.
  //  start copying from the bottom and work our way up.
  //  we need to flip the image, because DIBs are formatted upside down
  
  BYTE* pLineTextureBits = pTextureBits + rcLockedRect.Pitch * (nHeight - 1);
  
  for (int j = rcArea->bottom - 1; j >= rcArea->top; j--)
  {
    DWORD* pPixels = (DWORD*)pLineTextureBits;

    for (int i = 0; i < nWidth; i++)
    {
      *pPixels = *pBitmapBits;

      pPixels++;
      pBitmapBits++;
    }

    //go back one line in our texture
    pLineTextureBits -= rcLockedRect.Pitch;

    //go to the next line in our bmp
    pBitmapBits += (HTML_WIDTH - nWidth);
  }
  
  g_pTexture->UnlockRect(0);

  //reset our rectangle, signalling we've updated the invalid area.
  rcArea->top = -1; rcArea->bottom = -1; rcArea->left =-1; rcArea->right = -1;

  return true;
}
