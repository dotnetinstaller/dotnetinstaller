// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__8250352F_8843_4D8E_932B_A4E743C6C7E4__INCLUDED_)
#define AFX_STDAFX_H__8250352F_8843_4D8E_932B_A4E743C6C7E4__INCLUDED_

// Change these values to use different versions
//#define WINVER    0x0501
#define _WIN32_WINNT  0x0501
#define _WIN32_IE 0x501
#define _RICHEDIT_VER 0x0100

#if (_ATL_VER >= 0x0700)
#define _SECURE_ATL 1
#endif

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;


#include <atlwin.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlw.h>
#include <atlctrlx.h>

#include "wtl_htmlayout.h"
#include "wtl_htmlayouthost.h"
#include "wtl_htmlpopup.h"
#include "aux-cvt.h"
#include "aux-slice.h"
#include "value.h"

#define WM_HTML_NAVIGATE (WM_APP + 1)
#define WM_SHOW_STATUS (WM_APP + 2)
#define WM_UpdateRecentFileList     (WM_APP + 3)
#define WM_LoadFile                 (WM_APP + 4)
#define WM_UrlChanged               (WM_APP + 5)


#include <list>
#include <string>
#include <vector>
#include <algorithm>


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__8250352F_8843_4D8E_932B_A4E743C6C7E4__INCLUDED_)
