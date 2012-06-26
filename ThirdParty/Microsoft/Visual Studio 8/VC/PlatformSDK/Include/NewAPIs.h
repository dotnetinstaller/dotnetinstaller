/*
 *  Copyright (c) 1997-2004, Microsoft Corporation
 *
 *  Wrapper module that "stubs" APIs that were not implemented
 *  on Windows 95 or Windows NT versions less than 4.0 SP 3.
 *
 *  By using this header, your code will run on older platforms.
 *
 *  To enable a particular wrapper, define the corresponding symbol.
 *
 *  Function                Symbol
 *
 *  GetDiskFreeSpaceEx      WANT_GETDISKFREESPACEEX_WRAPPER
 *  GetLongPathName         WANT_GETLONGPATHNAME_WRAPPER
 *  GetFileAttributesEx     WANT_GETFILEATTRIBUTESEX_WRAPPER
 *  IsDebuggerPresent       WANT_ISDEBUGGERPRESENT_WRAPPER
 *
 *  Exactly one source file must include the line
 *
 *  #define COMPILE_NEWAPIS_STUBS
 *
 *  before including this file.
 *
 */

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */

/*****************************************************************************
 *
 * GetDiskFreeSpaceEx
 *
 *****************************************************************************/

#ifdef WANT_GETDISKFREESPACEEX_WRAPPER

#undef GetDiskFreeSpaceEx
#define GetDiskFreeSpaceEx _GetDiskFreeSpaceEx

extern BOOL (CALLBACK *GetDiskFreeSpaceEx)
             (LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);

/*
 * Exactly one file should define this symbol.
 */
#ifdef COMPILE_NEWAPIS_STUBS

/*
 * The version to use if we are forced to emulate.
 */
static BOOL WINAPI
Emulate_GetDiskFreeSpaceEx(LPCTSTR ptszRoot, PULARGE_INTEGER pliQuota,
                         PULARGE_INTEGER pliTotal, PULARGE_INTEGER pliFree)
{
    DWORD dwSecPerClus, dwBytesPerSec, dwFreeClus, dwTotalClus;
    BOOL fRc;

    fRc = GetDiskFreeSpace(ptszRoot, &dwSecPerClus, &dwBytesPerSec,
                           &dwFreeClus, &dwTotalClus);
    if (fRc) {
        DWORD dwBytesPerClus = dwSecPerClus * dwBytesPerSec;

        /*
         *  Curiously, of all the output parameters, only pliFree is
         *  allowed to be NULL.
         */

        *(__int64 *)pliQuota = Int32x32To64(dwBytesPerClus, dwFreeClus);
        if (pliFree) {
            *pliFree = *pliQuota;
        }

        *(__int64 *)pliTotal = Int32x32To64(dwBytesPerClus, dwTotalClus);
    }

    return fRc;
}

/*
 * The stub that probes to decide which version to use.
 */
static BOOL WINAPI
Probe_GetDiskFreeSpaceEx(LPCTSTR ptszRoot, PULARGE_INTEGER pliQuota,
                         PULARGE_INTEGER pliTotal, PULARGE_INTEGER pliFree)
{
    HINSTANCE hinst;
    FARPROC fp;
    BOOL fRc;
    BOOL (CALLBACK *RealGetDiskFreeSpaceEx)
             (LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);

    hinst = GetModuleHandle(TEXT("KERNEL32"));
#ifdef UNICODE
    fp = GetProcAddress(hinst, "GetDiskFreeSpaceExW");
#else
    fp = GetProcAddress(hinst, "GetDiskFreeSpaceExA");
#endif

    if (fp) {
        *(FARPROC *)&RealGetDiskFreeSpaceEx = fp;
        fRc = RealGetDiskFreeSpaceEx(ptszRoot, pliQuota, pliTotal, pliFree);
        if (fRc || GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
            GetDiskFreeSpaceEx = RealGetDiskFreeSpaceEx;
        } else {
            GetDiskFreeSpaceEx = Emulate_GetDiskFreeSpaceEx;
            fRc = GetDiskFreeSpaceEx(ptszRoot, pliQuota, pliTotal, pliFree);
        }
    } else {
        GetDiskFreeSpaceEx = Emulate_GetDiskFreeSpaceEx;
        fRc = GetDiskFreeSpaceEx(ptszRoot, pliQuota, pliTotal, pliFree);
    }

    return fRc;

}

BOOL (CALLBACK *GetDiskFreeSpaceEx)
             (LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER) =
                Probe_GetDiskFreeSpaceEx;

#endif /* COMPILE_NEWAPIS_STUBS */
#endif /* WANT_GETDISKFREESPACEEX_WRAPPER */

/*****************************************************************************
 *
 * GetLongPathName
 *
 *****************************************************************************/

#ifdef WANT_GETLONGPATHNAME_WRAPPER

#include <shlobj.h>

#undef GetLongPathName
#define GetLongPathName _GetLongPathName

extern DWORD (CALLBACK *GetLongPathName)(LPCTSTR, LPTSTR, DWORD);

/*
 * Exactly one file should define this symbol.
 */
#ifdef COMPILE_NEWAPIS_STUBS

/*
 * The version to use if we are forced to emulate.
 */
static DWORD WINAPI
Emulate_GetLongPathName(LPCTSTR ptszShort, LPTSTR ptszLong, DWORD ctchBuf)
{
    LPSHELLFOLDER psfDesk;
    HRESULT hr;
    LPITEMIDLIST pidl;
    TCHAR tsz[MAX_PATH];            /* Scratch TCHAR buffer */
    DWORD dwRc;
    LPMALLOC pMalloc;

    /*
     *  The file had better exist.  GetFileAttributes() will
     *  not only tell us, but it'll even call SetLastError()
     *  for us.
     */
    if (GetFileAttributes(ptszShort) == 0xFFFFFFFF) {
        return 0;
    }

    /*
     *  First convert from relative path to absolute path.
     *  This uses the scratch TCHAR buffer.
     */
    dwRc = GetFullPathName(ptszShort, MAX_PATH, tsz, NULL);
    if (dwRc == 0) {
        /*
         *  Failed; GFPN already did SetLastError().
         */
    } else if (dwRc >= MAX_PATH) {
        /*
         *  Resulting path would be too long.
         */
        SetLastError(ERROR_BUFFER_OVERFLOW);
        dwRc = 0;
    } else {
        /*
         *  Just right.
         */
        hr = SHGetDesktopFolder(&psfDesk);
        if (SUCCEEDED(hr)) {
            ULONG cwchEaten;

#ifdef UNICODE
#ifdef __cplusplus
            hr = psfDesk->ParseDisplayName(NULL, NULL, tsz,
                                       &cwchEaten, &pidl, NULL);
#else
            hr = psfDesk->lpVtbl->ParseDisplayName(psfDesk, NULL, NULL, tsz,
                                       &cwchEaten, &pidl, NULL);
#endif
#else
            WCHAR wsz[MAX_PATH];        /* Scratch WCHAR buffer */

            /*
             *  ParseDisplayName requires UNICODE, so we use
             *  the scratch WCHAR buffer during the conversion.
             */
            dwRc = MultiByteToWideChar(
                        AreFileApisANSI() ? CP_ACP : CP_OEMCP,
                        0, tsz, -1, wsz, MAX_PATH);
            if (dwRc == 0) {
                /*
                 *  Couldn't convert to UNICODE.  MB2WC uses
                 *  ERROR_INSUFFICIENT_BUFFER, which we convert
                 *  to ERROR_BUFFER_OVERFLOW.  Any other error
                 *  we leave alone.
                 */
                if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
                    SetLastError(ERROR_BUFFER_OVERFLOW);
                }
                dwRc = 0;
            } else {
#ifdef __cplusplus
                hr = psfDesk->ParseDisplayName(NULL, NULL, wsz,
                                           &cwchEaten, &pidl, NULL);
#else
                hr = psfDesk->lpVtbl->ParseDisplayName(psfDesk, NULL, NULL,
                                           wsz, &cwchEaten, &pidl, NULL);
#endif
#endif

                if (FAILED(hr)) {
                    /*
                     *  Weird.  Convert the result back to a Win32
                     *  error code if we can.  Otherwise, use the
                     *  generic "duh" error code ERROR_INVALID_DATA.
                     */
                    if (HRESULT_FACILITY(hr) == FACILITY_WIN32) {
                        SetLastError(HRESULT_CODE(hr));
                    } else {
                        SetLastError(ERROR_INVALID_DATA);
                    }
                    dwRc = 0;
                } else {
                    /*
                     *  Convert the pidl back to a filename in the
                     *  TCHAR scratch buffer.
                     */
                    dwRc = SHGetPathFromIDList(pidl, tsz);
                    if (dwRc == 0 && tsz[0]) {
                        /*
                         *  Bizarre failure.
                         */
                        SetLastError(ERROR_INVALID_DATA);
                    } else {
                        /*
                         *  Copy the result back to the user's buffer.
                         */
                        dwRc = lstrlen(tsz);
                        if (dwRc + 1 > ctchBuf) {
                            /*
                             *  On buffer overflow, return necessary
                             *  size including terminating null (+1).
                             */
                            SetLastError(ERROR_INSUFFICIENT_BUFFER);
                            dwRc = dwRc + 1;
                        } else {
                            /*
                             *  On buffer okay, return actual size not
                             *  including terminating null.
                             */
                            lstrcpyn(ptszLong, tsz, ctchBuf);
                        }
                    }

                    /*
                     *  Free the pidl.
                     */
                    if (SUCCEEDED(SHGetMalloc(&pMalloc))) {
#ifdef __cplusplus
                        pMalloc->Free(pidl);
                        pMalloc->Release();
#else
                        pMalloc->lpVtbl->Free(pMalloc, pidl);
                        pMalloc->lpVtbl->Release(pMalloc);
#endif
                    }
                }
#ifndef UNICODE
            }
#endif
            /*
             *  Release the desktop folder now that we no longer
             *  need it.
             */
#ifdef __cplusplus
            psfDesk->Release();
#else
            psfDesk->lpVtbl->Release(psfDesk);
#endif
        }
    }
    return dwRc;
}

/*
 * The stub that probes to decide which version to use.
 */
static DWORD WINAPI
Probe_GetLongPathName(LPCTSTR ptszShort, LPTSTR ptszLong, DWORD ctchBuf)
{
    HINSTANCE hinst;
    FARPROC fp;
    DWORD dwRc;
    DWORD (CALLBACK *RealGetLongPathName)(LPCTSTR, LPTSTR, DWORD);

    hinst = GetModuleHandle(TEXT("KERNEL32"));
#ifdef UNICODE
    fp = GetProcAddress(hinst, "GetLongPathNameW");
#else
    fp = GetProcAddress(hinst, "GetLongPathNameA");
#endif

    if (fp) {
        *(FARPROC *)&RealGetLongPathName = fp;
        dwRc = RealGetLongPathName(ptszShort, ptszLong, ctchBuf);
        if (dwRc || GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
            GetLongPathName = RealGetLongPathName;
        } else {
            GetLongPathName = Emulate_GetLongPathName;
            dwRc = GetLongPathName(ptszShort, ptszLong, ctchBuf);
        }
    } else {
        GetLongPathName = Emulate_GetLongPathName;
        dwRc = GetLongPathName(ptszShort, ptszLong, ctchBuf);
    }

    return dwRc;

}

DWORD (CALLBACK *GetLongPathName)(LPCTSTR, LPTSTR, DWORD) =
                Probe_GetLongPathName;

#endif /* COMPILE_NEWAPIS_STUBS */
#endif /* WANT_GETLONGPATHNAME_WRAPPER */

/*****************************************************************************
 *
 * GetFileAttributesEx
 *
 *****************************************************************************/

#ifdef WANT_GETFILEATTRIBUTESEX_WRAPPER

#undef GetFileAttributesEx
#define GetFileAttributesEx _GetFileAttributesEx

/*
 *  Really old header files don't even have definitions for these constants
 *  and structures.
 */
#if WINVER < 0x040A

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

#endif

extern BOOL (CALLBACK *GetFileAttributesEx)
                (LPCTSTR, GET_FILEEX_INFO_LEVELS, LPVOID);

/*
 * Exactly one file should define this symbol.
 */
#ifdef COMPILE_NEWAPIS_STUBS

/*
 * The version to use if we are forced to emulate.
 */
static BOOL WINAPI
Emulate_GetFileAttributesEx(LPCTSTR ptszFile, GET_FILEEX_INFO_LEVELS level,
                            LPVOID pv)
{
    BOOL fRc;

    if (level == GetFileExInfoStandard) {

        /*
         *  Must call GetFileAttributes first to avoid returning random
         *  values if the so-called filename contains wildcards.
         */
        if (GetFileAttributes(ptszFile) != 0xFFFFFFFF) {
            HANDLE hfind;
            WIN32_FIND_DATA wfd;
            hfind = FindFirstFile(ptszFile, &wfd);
            if (hfind != INVALID_HANDLE_VALUE) {
                LPWIN32_FILE_ATTRIBUTE_DATA pfad = pv;
                FindClose(hfind);

                pfad->dwFileAttributes = wfd.dwFileAttributes;
                pfad->ftCreationTime   = wfd.ftCreationTime;
                pfad->ftLastAccessTime = wfd.ftLastAccessTime;
                pfad->ftLastWriteTime  = wfd.ftLastWriteTime;
                pfad->nFileSizeHigh    = wfd.nFileSizeHigh;
                pfad->nFileSizeLow     = wfd.nFileSizeLow;

                fRc = TRUE;

            } else {
                /*
                 *  FindFirstFile already called SetLastError() for us.
                 */
                fRc = FALSE;
            }
        } else {
            /*
             *  GetFileAttributes already called SetLastError() for us.
             */
            fRc = FALSE;
        }
    } else {
        /*
         *  Unknown info level.
         */
        SetLastError(ERROR_INVALID_PARAMETER);
        fRc = FALSE;
    }

    return fRc;
}

/*
 * The stub that probes to decide which version to use.
 */
static BOOL WINAPI
Probe_GetFileAttributesEx(LPCTSTR ptszFile, GET_FILEEX_INFO_LEVELS level,
                          LPVOID pv)
{
    HINSTANCE hinst;
    FARPROC fp;
    BOOL fRc;
    BOOL (CALLBACK *RealGetFileAttributesEx)
             (LPCTSTR, GET_FILEEX_INFO_LEVELS, LPVOID);

    hinst = GetModuleHandle(TEXT("KERNEL32"));
#ifdef UNICODE
    fp = GetProcAddress(hinst, "GetFileAttributesExW");
#else
    fp = GetProcAddress(hinst, "GetFileAttributesExA");
#endif

    if (fp) {
        *(FARPROC *)&RealGetFileAttributesEx = fp;
        fRc = RealGetFileAttributesEx(ptszFile, level, pv);
        if (fRc || GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
            GetFileAttributesEx = RealGetFileAttributesEx;
        } else {
            GetFileAttributesEx = Emulate_GetFileAttributesEx;
            fRc = GetFileAttributesEx(ptszFile, level, pv);
        }
    } else {
        GetFileAttributesEx = Emulate_GetFileAttributesEx;
        fRc = GetFileAttributesEx(ptszFile, level, pv);
    }

    return fRc;

}

BOOL (CALLBACK *GetFileAttributesEx)
                (LPCTSTR, GET_FILEEX_INFO_LEVELS, LPVOID) =
        Probe_GetFileAttributesEx;

#endif /* COMPILE_NEWAPIS_STUBS */
#endif /* WANT_GETFILEATTRIBUTESEX_WRAPPER */

/*****************************************************************************
 *
 * IsDebuggerPresent
 *
 *****************************************************************************/

#ifdef WANT_ISDEBUGGERPRESENT_WRAPPER

#define IsDebuggerPresent _IsDebuggerPresent

extern BOOL (CALLBACK *IsDebuggerPresent)(VOID);

/*
 * Exactly one file should define this symbol.
 */
#ifdef COMPILE_NEWAPIS_STUBS

/*
 * The version to use if we are forced to emulate.
 */
static BOOL WINAPI
Emulate_IsDebuggerPresent(VOID)
{
    /* No way to tell, so just say "no". */
    return FALSE;
}

/*
 * The stub that probes to decide which version to use.
 */
static BOOL WINAPI
Probe_IsDebuggerPresent(VOID)
{
    HINSTANCE hinst;
    FARPROC fp;
    BOOL (CALLBACK *RealIsDebuggerPresent)(VOID);

    hinst = GetModuleHandle(TEXT("KERNEL32"));
    fp = GetProcAddress(hinst, "IsDebuggerPresent");

    if (fp) {
        *(FARPROC *)&IsDebuggerPresent = fp;
    } else {
        IsDebuggerPresent = Emulate_IsDebuggerPresent;
    }

    return IsDebuggerPresent();
}

BOOL (CALLBACK *IsDebuggerPresent)(VOID) =
        Probe_IsDebuggerPresent;

#endif /* COMPILE_NEWAPIS_STUBS */
#endif /* WANT_ISDEBUGGERPRESENT_WRAPPER */

#ifdef __cplusplus
}
#endif    /* __cplusplus */
