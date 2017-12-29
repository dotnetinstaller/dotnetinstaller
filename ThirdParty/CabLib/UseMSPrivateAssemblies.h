// Version 1.0 by Martin Richter [WWJD]

#pragma once

#ifndef RC_INVOKED
// Avoid problems with the resource compiler if included

// This defines bock the creation in the header files
#pragma message("Using private assemblies for the MS runtimes")

#ifndef __midl
#define _SXS_ASSEMBLY_VERSION "8.0.50727.6195"
#define _CRT_ASSEMBLY_VERSION _SXS_ASSEMBLY_VERSION
#define _MFC_ASSEMBLY_VERSION _SXS_ASSEMBLY_VERSION
#define _ATL_ASSEMBLY_VERSION _SXS_ASSEMBLY_VERSION
#endif

#define _STL_NOFORCE_MANIFEST
#define _CRT_NOFORCE_MANIFEST
// #define _AFX_NOFORCE_MANIFEST
//#define _ATL_NOFORCE_MANIFEST

// The next statements block the linker from including object files in the
// CRT and the MFC, that would create manifest pragmas too.
#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif

__declspec(selectany) int _forceCRTManifest;
__declspec(selectany) int _forceMFCManifest;
__declspec(selectany) int _forceAtlDllManifest;
__declspec(selectany) int _forceCRTManifestRTM;
__declspec(selectany) int _forceMFCManifestRTM;
__declspec(selectany) int _forceAtlDllManifestRTM;

#ifdef __cplusplus
}						/* __cplusplus */
#endif

// We don't have a seperate block for the Debug version. We just handle
// this with a extra define here.
#ifdef _DEBUG
#define __LIBRARIES_SUB_VERSION	"Debug"
#else
#define __LIBRARIES_SUB_VERSION	""
#endif

// Manifest for the CRT
#pragma comment(linker,"/manifestdependency:\"type='win32' "						\
	"name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX "." __LIBRARIES_SUB_VERSION "CRT' "   \
	"version='" _CRT_ASSEMBLY_VERSION "' "											\
	"processorArchitecture='x86' \"")

// Manifest for the MFC
//#pragma comment(linker,"/manifestdependency:\"type='win32' "						\
//	"name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX "." __LIBRARIES_SUB_VERSION "MFC' "   \
//	"version='" _CRT_ASSEMBLY_VERSION "' "											\
//	"processorArchitecture='x86'\"")

// #pragma comment(linker,"/manifestdependency:\"type='win32' "						\
// 	"name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".MFCLOC' "							\
// 	"version='" _CRT_ASSEMBLY_VERSION "' "											\
// 	"processorArchitecture='x86'\"")

// Manifest for the ATL
// #pragma comment(linker,"/manifestdependency:\"type='win32' "						\
//	"name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".ATL' "								\
//	"version='" _CRT_ASSEMBLY_VERSION "' "											\
//	"processorArchitecture='x86' \"")

#endif // RC_INVOKED
