#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER
#define WINVER _WIN32_WINNT_WINXP
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#endif						

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINNT_WINXP
#endif

#ifndef _WIN32_IE
#define _WIN32_IE _WIN32_IE_XP
#endif

#ifndef _WIN32_MSI
#define _WIN32_MSI 110
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

#define _AFX_ALL_WARNINGS

#include <afxwin.h> // standard MFC components
#include <afxext.h> // MFC exceptions
#include <afxdisp.h> // MFC automation

#include <afxdtctl.h> // Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h> // common Windows components
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <time.h>
#include <tchar.h>

#pragma warning(push)
#pragma warning(disable:4995) // name was marked as #pragma deprecated
#include <shlwapi.h>
#pragma warning(pop)

#include <winnls.h>

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <list>

#include <strsafe.h>
#include <msi.h>
#include <msiquery.h>
