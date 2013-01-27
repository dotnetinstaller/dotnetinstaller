//-----------------------------------------------------------------------------
// OpenMP runtime support library for Visual C++
// Copyright (C) Microsoft Corporation.  All rights reserved.
//-----------------------------------------------------------------------------

// OpenMP C/C++ Version 2.0 March 2002

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#define _OMPAPI     __cdecl

#if !defined(_OMP_LOCK_T)
#define _OMP_LOCK_T
typedef void * omp_lock_t;
#endif

#if !defined(_OMP_NEST_LOCK_T)
#define _OMP_NEST_LOCK_T
typedef void * omp_nest_lock_t;
#endif

#if !defined(_OPENMP)

#if defined(_DEBUG)
    #pragma comment(lib, "vcompd")
#else   // _DEBUG
    #pragma comment(lib, "vcomp")
#endif  // _DEBUG

#endif // _OPENMP

#if !defined(_OPENMP_NOFORCE_MANIFEST)

    #include <crtassem.h>

    #if defined(_DEBUG)

        #if defined(_M_IX86)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".DebugOpenMP' "         \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='x86' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #elif defined(_M_AMD64)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".DebugOpenMP' "         \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='amd64' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #elif defined(_M_IA64)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".DebugOpenMP' "         \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='ia64' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #endif

    #else   // _DEBUG

        #if defined(_M_IX86)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".OpenMP' "              \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='x86' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #elif defined(_M_AMD64)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".OpenMP' "              \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='amd64' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #elif defined(_M_IA64)
            #pragma comment(linker,"/manifestdependency:\"type='win32' "            \
                "name='" __LIBRARIES_ASSEMBLY_NAME_PREFIX ".OpenMP' "              \
                "version='" _CRT_ASSEMBLY_VERSION "' "                          \
                "processorArchitecture='ia64' "                                  \
                "publicKeyToken='" _VC_ASSEMBLY_PUBLICKEYTOKEN "'\"")
        #endif

    #endif  // _DEBUG

#endif  // _OPENMP_NOFORCE_MANIFEST

#if !defined(_OMPIMP)
#define _OMPIMP     __declspec(dllimport)
#endif

_OMPIMP void _OMPAPI
omp_set_num_threads(
    int _Num_threads
    );

_OMPIMP int _OMPAPI
omp_get_num_threads(
    void
    );

_OMPIMP int _OMPAPI
omp_get_max_threads(
    void
    );

_OMPIMP int _OMPAPI
omp_get_thread_num(
    void
    );

_OMPIMP int _OMPAPI
omp_get_num_procs(
    void
    );

_OMPIMP void _OMPAPI
omp_set_dynamic(
    int _Dynamic_threads
    );

_OMPIMP int _OMPAPI
omp_get_dynamic(
    void
    );

_OMPIMP int _OMPAPI
omp_in_parallel(
    void
    );

_OMPIMP void _OMPAPI
omp_set_nested(
    int _Nested
    );

_OMPIMP int _OMPAPI
omp_get_nested(
    void
    );

_OMPIMP void _OMPAPI
omp_init_lock(
    omp_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_destroy_lock(
    omp_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_set_lock(
    omp_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_unset_lock(
    omp_lock_t * _Lock
    );

_OMPIMP int _OMPAPI
omp_test_lock(
    omp_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_init_nest_lock(
    omp_nest_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_destroy_nest_lock(
    omp_nest_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_set_nest_lock(
    omp_nest_lock_t * _Lock
    );

_OMPIMP void _OMPAPI
omp_unset_nest_lock(
    omp_nest_lock_t * _Lock
    );

_OMPIMP int _OMPAPI
omp_test_nest_lock(
    omp_nest_lock_t * _Lock
    );

_OMPIMP double _OMPAPI
omp_get_wtime(
    void
    );

_OMPIMP double _OMPAPI
omp_get_wtick(
    void
    );

#if defined(__cplusplus)
}
#endif
