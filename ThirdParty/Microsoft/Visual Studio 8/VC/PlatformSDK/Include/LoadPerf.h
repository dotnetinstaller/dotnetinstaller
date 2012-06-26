/*++
Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:
    loadperf.h

Abstract:
    Header file for the Performance Monitor counter string installation
    and removal functions.

Revision History
    16-Nov-95   Created (a-robw)
--*/

#ifndef _LOADPERF_H_
#define _LOADPERF_H_

#if _MSC_VER > 1000
#pragma once
#endif

// function prototypes for perf counter name string load & unload functions
// provided in LOADPERF.DLL

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __LOADPERF__
#define LOADPERF_FUNCTION   DWORD __stdcall
#else
#define LOADPERF_FUNCTION   __declspec(dllimport) DWORD __stdcall
#endif

// flags for dwFlags Argument
#define LOADPERF_FLAGS_DELETE_MOF_ON_EXIT   ((ULONG_PTR) 1)
#define LOADPERF_FLAGS_LOAD_REGISTRY_ONLY   ((ULONG_PTR) 2)
#define LOADPERF_FLAGS_CREATE_MOF_ONLY      ((ULONG_PTR) 4)
#define LOADPERF_FLAGS_DISPLAY_USER_MSGS    ((ULONG_PTR) 8)

LOADPERF_FUNCTION
InstallPerfDllW(
    IN  LPCWSTR   szComputerName,
    IN  LPCWSTR   lpIniFile,
    IN  ULONG_PTR dwFlags         
);

LOADPERF_FUNCTION
InstallPerfDllA(
    IN  LPCSTR    szComputerName,
    IN  LPCSTR    lpIniFile,
    IN  ULONG_PTR dwFlags         
);

LOADPERF_FUNCTION
LoadPerfCounterTextStringsA(
    __in LPSTR lpCommandLine,
    __in BOOL bQuietModeArg
);

LOADPERF_FUNCTION
LoadPerfCounterTextStringsW(
    __in LPWSTR lpCommandLine,
    __in BOOL bQuietModeArg
);

LOADPERF_FUNCTION
UnloadPerfCounterTextStringsW(
    __in LPWSTR lpCommandLine,
    __in BOOL bQuietModeArg
);

LOADPERF_FUNCTION
UnloadPerfCounterTextStringsA(
    __in LPSTR lpCommandLine,
    __in BOOL bQuietModeArg
);

LOADPERF_FUNCTION
UpdatePerfNameFilesA(
    __in LPCSTR szNewCtrFilePath,
    __in LPCSTR szNewHlpFilePath,
    __in LPSTR szLanguageID,
    __in ULONG_PTR dwFlags
);

LOADPERF_FUNCTION
UpdatePerfNameFilesW(
    __in LPCWSTR szNewCtrFilePath,
    __in LPCWSTR szNewHlpFilePath,
    __in LPWSTR szLanguageID,
    __in ULONG_PTR dwFlags
);

LOADPERF_FUNCTION
SetServiceAsTrustedA(
    IN  LPCSTR    szReserved,
    IN  LPCSTR    szServiceName
);

LOADPERF_FUNCTION
SetServiceAsTrustedW(
    IN  LPCWSTR   szReserved,
    IN  LPCWSTR   szServiceName
);

DWORD
BackupPerfRegistryToFileW(
    IN  LPCWSTR   szFileName,
    IN  LPCWSTR   szCommentString
);

DWORD
RestorePerfRegistryFromFileW(
    IN  LPCWSTR   szFileName,
    IN  LPCWSTR   szLangId
);

#ifdef UNICODE
#define InstallPerfDll                  InstallPerfDllW
#define LoadPerfCounterTextStrings      LoadPerfCounterTextStringsW
#define UnloadPerfCounterTextStrings    UnloadPerfCounterTextStringsW
#define UpdatePerfNameFiles             UpdatePerfNameFilesW 
#define SetServiceAsTrusted             SetServiceAsTrustedW
#else
#define InstallPerfDll                  InstallPerfDllA
#define LoadPerfCounterTextStrings      LoadPerfCounterTextStringsA
#define UnloadPerfCounterTextStrings    UnloadPerfCounterTextStringsA
#define UpdatePerfNameFiles             UpdatePerfNameFilesA
#define SetServiceAsTrusted             SetServiceAsTrustedA
#endif

#ifdef __cplusplus
}
#endif


#endif // _LOADPERF_H_
