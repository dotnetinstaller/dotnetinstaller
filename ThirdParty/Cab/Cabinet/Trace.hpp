///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (www.netcult.ch/elmue)
// Date: 18-03-2008
//
// Trace debug output
//
// User Debugview from www.sysinternals.com to see this output
// This application MUST be started with CTRL + F5 from VisualStudio otherwise you will see nothing
//

#pragma once
#pragma warning(disable: 4793)

#include <stdio.h>

namespace Cabinet
{

// change FALSE into TRUE to enable tracing
#define _TraceExtract  (_DEBUG && FALSE) // Extraction
#define _TraceCompress (_DEBUG && FALSE) // Compression
#define _TraceInternet (_DEBUG && FALSE) // Internet
#define _TraceCache    (_DEBUG && FALSE) // Internet Caches

class CTrace
{
public:
	
#if _DEBUG
	static void TraceW(const WCHAR* u16_Format, ...)
	{
		const DWORD BUFLEN = 5000;
		WCHAR u16_Buf[BUFLEN];
		
		swprintf(u16_Buf, L"{%04u} ", GetCurrentThreadId());
		DWORD u32_Len = wcslen(u16_Buf);
		
		va_list  args;
		va_start(args, u16_Format);
		_vsnwprintf(u16_Buf+u32_Len, BUFLEN-u32_Len, u16_Format, args);
		
		OutputDebugStringW(u16_Buf);
	}
#endif
}; // class
} // Namespace Cabinet

