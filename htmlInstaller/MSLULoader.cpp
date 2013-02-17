#include "StdAfx.h"

// load Microsoft Layer for Unicode (MSLU)
// http://msdn.microsoft.com/en-us/magazine/cc301794.aspx
extern "C" HMODULE (__stdcall *_PfnLoadUnicows) (void) = & LoadMSLU;
