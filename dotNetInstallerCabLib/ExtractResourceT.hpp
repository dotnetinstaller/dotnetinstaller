///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Luuk Weltevreden
// Date: 23-07-2004
//
// Completely rewritten by Elmü (http://kickme.to/elmue)
// Date: 12-12-2007
//
// Filename: ExtractResourceT.hpp
//
// - CExtractResourceT<T>
// - CExtractResource
//
// Purpose: This template extracts files from cabinet files stored as a Win32 Resource.
//

#pragma once

#include "ExtractMemoryT.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

template <class T> class CExtractResourceT : public CExtractMemoryT<T>
{
public:
	// The same as ExtractResourceA() for Unicode
	BOOL ExtractResourceW(WCHAR* u16_Module, UINT u32_ResourceID, UINT u32_ResourceType, WCHAR* u16_TargetDir, void * pParam = NULL)
		{ return ExtractResourceW(u16_Module, MAKEINTRESOURCEW(u32_ResourceID), MAKEINTRESOURCEW(u32_ResourceType), u16_TargetDir, pParam); }

	BOOL ExtractResourceW(WCHAR* u16_Module, UINT u32_ResourceID, WCHAR* u16_ResourceType, WCHAR* u16_TargetDir, void * pParam = NULL)
		{ return ExtractResourceW(u16_Module, MAKEINTRESOURCEW(u32_ResourceID), u16_ResourceType, u16_TargetDir, pParam); }

	BOOL ExtractResourceW(WCHAR* u16_Module, WCHAR* u16_ResourceName, UINT u32_ResourceType, WCHAR* u16_TargetDir, void * pParam = NULL)
		{ return ExtractResourceW(u16_Module, u16_ResourceName, MAKEINTRESOURCEW(u32_ResourceType), u16_TargetDir, pParam); }

	BOOL ExtractResourceW(WCHAR* u16_Module, WCHAR* u16_ResourceName, WCHAR* u16_ResourceType, WCHAR* u16_TargetDir, void * pParam = NULL)
	{
		if (!GetMemoryW(u16_Module, u16_ResourceName, u16_ResourceType))
			return FALSE;

		// Pass it on to the base class
		return ExtractFileW(L"*CABINET\\*RESOURCE", u16_TargetDir, pParam);
	}


	// Copy the content of the cabinet in the resources onto disk
	// You can set s8_Module = 0 if the cabinet is in the file which created the process
	// Otherwise s8_Module must be the filename (without path) of the DLL which contains the CAB resource
	// To test this function with the file Test.cab included in this project
	// set s8_Module = 0 and u32_ResourceID = ID_CAB_TEST and s8_ResourceType = "CABFILE"
	// because the file Cabinet.rc contains:
	// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
	BOOL ExtractResourceA(char* s8_Module, UINT u32_ResourceID, UINT u32_ResourceType, char* s8_TargetDir, void * pParam = NULL)
		{ return ExtractResourceA(s8_Module, MAKEINTRESOURCEA(u32_ResourceID), MAKEINTRESOURCEA(u32_ResourceType), s8_TargetDir, pParam); }

	BOOL ExtractResourceA(char* s8_Module, UINT u32_ResourceID, char* s8_ResourceType, char* s8_TargetDir, void * pParam = NULL)
		{ return ExtractResourceA(s8_Module, MAKEINTRESOURCEA(u32_ResourceID), s8_ResourceType, s8_TargetDir, pParam); }

	BOOL ExtractResourceA(char* s8_Module, char* s8_ResourceName, UINT u32_ResourceType, char* s8_TargetDir, void * pParam = NULL)
		{ return ExtractResourceA(s8_Module, s8_ResourceName, MAKEINTRESOURCEA(u32_ResourceType), s8_TargetDir, pParam); }

	BOOL ExtractResourceA(char* s8_Module, char* s8_ResourceName, char* s8_ResourceType, char* s8_TargetDir, void * pParam = NULL)
	{
		if (!GetMemoryA(s8_Module, s8_ResourceName, s8_ResourceType))
			return FALSE;

		// Pass it on to the base class
		return ExtractFileA("*CABINET\\*RESOURCE", s8_TargetDir, pParam);
	}


	// The same as IsResourceCabinetA() for Unicode
	BOOL IsResourceCabinetW(WCHAR* u16_Module, UINT u32_ResourceID, UINT u32_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetW(u16_Module, MAKEINTRESOURCEW(u32_ResourceID), MAKEINTRESOURCEW(u32_ResourceType), pfdici); }

	BOOL IsResourceCabinetW(WCHAR* u16_Module, UINT u32_ResourceID, WCHAR* u16_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetW(u16_Module, MAKEINTRESOURCEW(u32_ResourceID), u16_ResourceType, pfdici); }

	BOOL IsResourceCabinetW(WCHAR* u16_Module, WCHAR* u16_ResourceName, UINT u32_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetW(u16_Module, u16_ResourceName, MAKEINTRESOURCEW(u32_ResourceType), pfdici); }

	BOOL IsResourceCabinetW(WCHAR* u16_Module, WCHAR* u16_ResourceName, WCHAR* u16_ResourceType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryW(u16_Module, u16_ResourceName, u16_ResourceType))
			return FALSE;

		// Pass it on to the base class
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}

	// Check if the cabinet in the resources is valid
	// You can set s8_Module = 0 if the cabinet is in the file which created the process
	// Otherwise s8_Module must be the filename (without path) of the DLL which contains the CAB resource
	// To test this function with the file Test.cab included in this project
	// set s8_Module = 0 and u32_ResourceID = ID_CAB_TEST and s8_ResourceType = "CABFILE"
	// because the file Cabinet.rc contains:
	// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
	BOOL IsResourceCabinetA(char* s8_Module, UINT u32_ResourceID, UINT u32_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetA(s8_Module, MAKEINTRESOURCEA(u32_ResourceID), MAKEINTRESOURCEA(u32_ResourceType), pfdici); }

	BOOL IsResourceCabinetA(char* s8_Module, UINT u32_ResourceID, char* s8_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetA(s8_Module, MAKEINTRESOURCEA(u32_ResourceID), s8_ResourceType, pfdici); }

	BOOL IsResourceCabinetA(char* s8_Module, char* s8_ResourceName, UINT u32_ResourceType, PFDICABINETINFO pfdici = NULL)
		{ return IsResourceCabinetA(s8_Module, s8_ResourceName, MAKEINTRESOURCEA(u32_ResourceType), pfdici); }

	BOOL IsResourceCabinetA(char* s8_Module, char* s8_ResourceName, char* s8_ResourceType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryA(s8_Module, s8_ResourceName, s8_ResourceType))
			return FALSE;

		// Pass it on to the base class
		return IsCabinetA("*CABINET\\*RESOURCE", pfdici);
	}


protected:

	static kMemory& Mem()
	{
		static kMemory k_Memory;
		return k_Memory;
	}

	// The same as GetMemoryA() for Unicode
	// u16_Module may be = 0 if the cabinet is in the file which created the process!!
	BOOL GetMemoryW(WCHAR* u16_Module, WCHAR* u16_ResourceName, WCHAR* u16_ResourceType)
	{
		if (!CUtf7::IsNtPlatform())
		{
			CUtf7 i_Mod, i_Name, i_Type;
			return GetMemoryA(i_Mod.Encode(u16_Module), i_Name.Encode(u16_ResourceName), i_Type.Encode(u16_ResourceType));
		}

		WCHAR u16_RscName[2000];
		WCHAR u16_RscType[2000];

		if (IS_INTRESOURCE(u16_ResourceName))
			swprintf(u16_RscName, L"#%d", PtrToInt(u16_ResourceName));
		else 
			wcscpy(u16_RscName, u16_ResourceName);

		if (IS_INTRESOURCE(u16_ResourceType))
			swprintf(u16_RscType, L"#%d", PtrToInt(u16_ResourceType));
		else 
			wcscpy(u16_RscType, u16_ResourceType);

		// Load the resource
		HMODULE h_DLL      = GetModuleHandleW(u16_Module);
		HRSRC   h_Resource = FindResourceW(h_DLL, u16_RscName, u16_RscType);
		HGLOBAL h_Global   = LoadResource (h_DLL, h_Resource);

		Mem().p_Addr   = LockResource  (h_Global);
		Mem().s32_Size = SizeofResource(h_DLL, h_Resource);
		Mem().s32_Pos  = 0;

		if (Mem().p_Addr == 0 || Mem().s32_Size == 0)
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_INVAL_RESOURCE;
			return FALSE;
		}
		return TRUE;
	}

	// Fills the static structure in Mem() with a pointer to the resource in memory
	// s8_Module may be = 0 if the cabinet is in the file which created the process!!
	BOOL GetMemoryA(char* s8_Module, char* s8_ResourceName, char* s8_ResourceType)
	{
		if (!CUtf7::IsNtPlatform() && (CUtf7::IsUtf(s8_Module) || CUtf7::IsUtf(s8_ResourceName) || CUtf7::IsUtf(s8_ResourceType)))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_NT_PLATFORM;
			return FALSE;
		}

		char s8_RscName[2000];
		char s8_RscType[2000];

		if (IS_INTRESOURCE(s8_ResourceName))
			sprintf(s8_RscName, "#%d", PtrToInt(s8_ResourceName));
		else 
			strcpy (s8_RscName, s8_ResourceName);

		if (IS_INTRESOURCE(s8_ResourceType))
			sprintf(s8_RscType, "#%d", PtrToInt(s8_ResourceType));
		else 
			strcpy (s8_RscType, s8_ResourceType);

		// Load the resource
		HMODULE h_DLL      = GetModuleHandleA(s8_Module);
		HRSRC   h_Resource = FindResourceA(h_DLL, s8_RscName, s8_RscType);
		HGLOBAL h_Global   = LoadResource (h_DLL, h_Resource);

		Mem().p_Addr   = LockResource  (h_Global);
		Mem().s32_Size = SizeofResource(h_DLL, h_Resource);
		Mem().s32_Pos  = 0;

		if (Mem().p_Addr == 0 || Mem().s32_Size == 0)
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_INVAL_RESOURCE;
			return FALSE;
		}
		return TRUE;
	}

	// This function returns a new structure with the pointer to the resource data in memory
	static kMemory* OpenMem(const char* s8_File, int, int)
	{
		// IMPORTANT: The structure MUST be COPIED into a new instance !!!!
		// Cabinet.DLL will call OpenMem() TWO times and each time it requires 
		// an individual structure which has its own read position in kMemory.s32_Pos!
		// Later this kMemory instance will be deleted in ExtractMemoryT::CloseMem()
		return new kMemory(Mem());
	}


	// Copies a part of the CAB file's memory from the resource to the given buffer
	static int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
	{
		// Reached the end of the resource
		if (pk_Mem->s32_Pos >= pk_Mem->s32_Size)
			return 0;

		// Do not try to read behind the end of the resource
		count = min((long)count, pk_Mem->s32_Size - pk_Mem->s32_Pos);

		// Copy the memory in the buffer
		memcpy(buffer, (char*)(pk_Mem->p_Addr) + pk_Mem->s32_Pos, count);

		// Return the amount of bytes copied
		return count;
	}

	// Declare this class as a friend so it can access the protected members.
	friend class CExtractMemoryT<T>;
};

class CExtractResource : public CExtractResourceT<CExtractResource> { };

} // Namespace Cabinet