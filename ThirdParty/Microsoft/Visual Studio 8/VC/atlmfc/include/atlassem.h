/***
*atlassem.h - Libraries Assembly information
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file has information about Libraries Assembly version.
*
*
****/

#pragma once

#ifndef _VC_ASSEMBLY_PUBLICKEYTOKEN
#define _VC_ASSEMBLY_PUBLICKEYTOKEN "1fc8b3b9a1e18e3b"
#endif

#ifndef _ATL_ASSEMBLY_VERSION
#if defined _USE_RTM_VERSION
#define _ATL_ASSEMBLY_VERSION "8.0.50608.0"
#else
#define _ATL_ASSEMBLY_VERSION "8.0.50727.6195"
#endif
#endif

#ifndef __LIBRARIES_ASSEMBLY_NAME_PREFIX
#define __LIBRARIES_ASSEMBLY_NAME_PREFIX "Microsoft.VC80"
#endif

#if _MSC_FULL_VER >= 140040130

#ifdef _M_IX86
    #pragma comment(linker,"/manifestdependency:\"type='win32' "        \
        "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".ATL' "              \
        "version='" _ATL_ASSEMBLY_VERSION "' "                          \
        "processorArchitecture='x86' "                                  \
        "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
#endif

#ifdef _M_AMD64
    #pragma comment(linker,"/manifestdependency:\"type='win32' "        \
        "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".ATL' "              \
        "version='" _ATL_ASSEMBLY_VERSION "' "                          \
        "processorArchitecture='amd64' "                                \
        "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
#endif

#ifdef _M_IA64
    #pragma comment(linker,"/manifestdependency:\"type='win32' "        \
        "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".ATL' "              \
        "version='" _ATL_ASSEMBLY_VERSION "' "                          \
        "processorArchitecture='ia64' "                                 \
        "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
#endif

#endif

