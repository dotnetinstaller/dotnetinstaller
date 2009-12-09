///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 19-04-2008
//
// Filename: Error.hpp
//
// Classes:
// - CError
//
// Purpose: CError simplifies FDI error handling
//

#pragma once

#include "FDI.h"
#include "FCI.h"

#include "Internet.hpp"

namespace Cabinet
{

// Extension for enum FDIERROR defined in Microsoft file FDI.H
#define FDIERROR_LOAD_CABINET_DLL 1000
#define FDIERROR_LOAD_WININET_DLL 1001
#define FDIERROR_INVAL_PARAM      1002
#define FDIERROR_READ_CABFILE     1003
#define FDIERROR_INVAL_RESOURCE   1004
#define FDIERROR_PATH_TOO_LONG    1005
#define FDIERROR_INTERNET         1006
#define FDIERROR_NOT_ENCRYPTED    1007
#define FDIERROR_IS_ENCRYPTED     1008
#define FDIERROR_INVAL_FILE_LEN   1009
#define FDIERROR_MSIE_OFFLINE     1010
#define FDIERROR_INVAL_THREAD     1011
#define FDIERROR_INST_PER_THREAD  1012

// Extension for enum FCIERROR defined in Microsoft file FCI.H
#define FCIERR_LOAD_DLL           1000
#define FCIERR_INVAL_PARAM        1001
#define FCIERR_CREATE_DIR         1002
#define FCIERR_PATH_TOO_LONG      1003
#define FCIERR_UNICODE_NEEDS_UTF8 1004
#define FCIERR_INVAL_THREAD       1005
#define FCIERR_FILE_TOO_BIG       1006

class CError
{
public:

	CError(BOOL b_FDI)
	{
		mb_FDI = b_FDI;
		Reset();
	}

	void Reset()
	{
		mu32_LastCabError  = 0;
		mu32_LastApiError  = 0;
		mu32_LastHttpError = 0;
		memset(&k_ERF, 0, sizeof(ERF));
	}

	// stores the last error 
	void Set(UINT u32_CAB_Error, UINT u32_API_Error, UINT u32_HTTP_Error)
	{
		mu32_LastCabError  = u32_CAB_Error;
		mu32_LastApiError  = u32_API_Error;
		mu32_LastHttpError = u32_HTTP_Error;
	}

	// returns TRUE if an error occurred
	BOOL HasError()
	{
		return k_ERF.fError || mu32_LastApiError || mu32_LastCabError;
	}

	// Returns an Unicode message for the last error that has occured.
	WCHAR* LastErrorW()
	{
		if (!HasError())
			return L"Success";

		// avoid error "User Aborted" if output file could not be written
		if (mu32_LastCabError) k_ERF.erfOper = mu32_LastCabError;
		if (mu32_LastApiError) k_ERF.erfType = mu32_LastApiError;

		WCHAR* u16_CabErr = GetCabinetErrorW(k_ERF.erfOper);

		if (!k_ERF.erfType)
			return u16_CabErr;

		DWORD u32_BufLen = 2000;
		CStrW  sw_WinErr;
		sw_WinErr.Allocate(u32_BufLen);

		if (!CInternet::ExplainInetErrorW(k_ERF.erfType, &sw_WinErr, mu32_LastHttpError))
		{
			if (!FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, 0, k_ERF.erfType, 0, sw_WinErr, u32_BufLen, 0))
			{
				sw_WinErr = L"Microsoft has no explanation for this error code.";
			}
		}
		ms_Error.Format(L"%s\nError %d: %s", u16_CabErr, k_ERF.erfType, (WCHAR*)sw_WinErr);
		return ms_Error;
	}

	WCHAR* GetCabinetErrorW(UINT u32_Error)
	{
		if (mb_FDI)
		{
			switch (u32_Error)
			{
			case FDIERROR_NONE:                    return L"Success";
			case FDIERROR_CABINET_NOT_FOUND:       return L"Cabinet file (or part of splitted CAB) not found";
			case FDIERROR_NOT_A_CABINET:           return L"The file is not a cabinet";
			case FDIERROR_UNKNOWN_CABINET_VERSION: return L"Unknown cabinet version";
			case FDIERROR_CORRUPT_CABINET:         return L"Corrupt cabinet";
			case FDIERROR_READ_CABFILE:            return L"Could not read CAB file";
			case FDIERROR_ALLOC_FAIL:              return L"Memory allocation failed";
			case FDIERROR_BAD_COMPR_TYPE:          return L"Unknown compression type";
			case FDIERROR_MDI_FAIL:                return L"Failure decompressing data";
			case FDIERROR_TARGET_FILE:             return L"Failure writing to target file";
			case FDIERROR_RESERVE_MISMATCH:        return L"Cabinets in set have different RESERVE sizes";
			case FDIERROR_WRONG_CABINET:           return L"Cabinet returned on fdintNEXT_CABINET is incorrect";
			case FDIERROR_USER_ABORT:              return L"User aborted";
			case FDIERROR_LOAD_CABINET_DLL:        return L"Could not load Cabinet.dll";
			case FDIERROR_LOAD_WININET_DLL:        return L"Could not load Wininet.dll";
			case FDIERROR_INVAL_PARAM:             return L"Invalid parameters passed to extraction function. Read the documentation!";
			case FDIERROR_INVAL_RESOURCE:          return L"The specified resource could not be opened.";
			case FDIERROR_PATH_TOO_LONG:           return L"The path is too long. (Max 250 Ansii characters or approx 100 Unicode characters).";
			case FDIERROR_INTERNET:                return L"An internet error occurred.";
			case FDIERROR_MSIE_OFFLINE:            return L"Internet Explorer is switched to Offline mode.";
			case FDIERROR_NOT_ENCRYPTED:           return L"The CAB archive is not encrypted but a decryption key was set.";
			case FDIERROR_IS_ENCRYPTED:            return L"The CAB archive is encrypted but no decryption key was set.";
			case FDIERROR_INVAL_FILE_LEN:          return L"Invalid CAB file: Extracted file is longer than declared in fdintCOPY_FILE";
			case FDIERROR_INVAL_THREAD:            return L"Cabinet.dll does not support calling the same CAB context from two different threads.";
			case FDIERROR_INST_PER_THREAD:         return L"There must be only one CExtract instance per thread at the same time! Call CleanUp() before you use another instance in the same thread!";
			default:                               return L"Unknown error";
			}
		}
		else
		{
			switch (u32_Error)
			{
			case FCIERR_NONE:               return L"Success";
			case FCIERR_OPEN_SRC:           return L"Failure opening file to be stored in cabinet";
			case FCIERR_READ_SRC:           return L"Failure reading file to be stored in cabinet";
			case FCIERR_ALLOC_FAIL:         return L"Insufficient memory in FCI";
			case FCIERR_TEMP_FILE:          return L"Could not create a temporary file";
			case FCIERR_BAD_COMPR_TYPE:     return L"Unknown compression type";
			case FCIERR_CAB_FILE:           return L"Could not create cabinet file";
			case FCIERR_USER_ABORT:         return L"Client requested abort";
			case FCIERR_MCI_FAIL:           return L"Failure compressing data";
			case FCIERR_LOAD_DLL:           return L"Could not load Cabinet.dll";
			case FCIERR_INVAL_PARAM:        return L"Invalid parameters passed to compression function. Read the documentation!";
			case FCIERR_CREATE_DIR:         return L"Could not create the directory where to save the CAB file.";
			case FCIERR_PATH_TOO_LONG:      return L"The path is too long. (Max 250 Ansii characters or approx 100 Unicode characters).";
			case FCIERR_UNICODE_NEEDS_UTF8: return L"To store files with names containing Unicode characters into the CAB file you must enable UTF8 encoding!";
			case FCIERR_INVAL_THREAD:       return L"Cabinet.dll does not support calling the same CAB context from two different threads.";
			case FCIERR_FILE_TOO_BIG:       return L"Cabinet.dll does not support compressing files bigger than 2 GB.";
			default:                        return L"Unknown error";
			}
		}
	}

	// This public struct is passed to Cabinet.Dll
	ERF k_ERF;

private:
	BOOL mb_FDI;

	// Used for LastError()
	CStrW ms_Error;

	// The origional error which caused an abortion of the extraction process
	UINT mu32_LastCabError;
	UINT mu32_LastApiError;
	UINT mu32_LastHttpError;
};

} // Namespace Cabinet
