///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 23-01-2009
//
// Filename: Defines.h
//
// This file contains general settings

#pragma once

// -----------------------------------------------------------------------------------------------

// If this is FALSE Cabinet.dll will be loaded dynamically each time it is used.
// If this is TRUE  the code of Cabinet.dll will be compiled into the C++ Application or .NET CabLib.dll
// The filesize of the compiled EXE / DLL increases approx 45 kB when linking statically.
// If you set TRUE here, FCI.LIB and FDI.LIB must be listed under "External Dependencies" in the Linker settings!
#define STATIC_LINK_CABINET_DLL  FALSE

// Big enough because Cabinet.dll internally uses a 32 kB buffer
#define CRYPT_BUFFER_SIZE 64*1024

// The following value is used for Encryption and Decryption
// It defines the position of the first byte in the CAB file that is encrypted
// The bytes before this position are NOT encrypted (file header)
// ATTENTION: This value must be a multiple of 8 !!!!
// ATTENTION: This value must not be zero !!!!
#define ENCRYPTION_START  0x38

// -----------------------------------------------------------------------------------------------

// Stores in the file attributes that the file was compressed using UTC time
#define FILE_ATTR_UTC_TIME     0x100

// convert FILETIME to 64 bit integer
#define _FileTimeTo64(FileTime) *(__int64*)&FileTime

// The interval in milliseconds in which the Extraction Progress callback is called
#define DEFAULT_PROGRESS_CALLBACK_INTERVAL  200

// for Visual Studio 6:
#if _MSC_VER <= 1200 
	#define SLR_NOSEARCH     0x10
	#define SLR_NOTRACK      0x20
	#define SLR_NOLINKINFO   0x40

	#define HTTP_STATUS_RETRY_WITH       449
	#define INTERNET_CONNECTION_OFFLINE  0x20
#endif

#if _WIN32_WINNT <= 0x0400
	#define COINIT_MULTITHREADED 0
	WINOLEAPI CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
#endif
