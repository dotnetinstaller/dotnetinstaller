///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 19-04-2008
//
// Filename: ExtractResource.hpp
//
// Classes:
// - CExtractResource
//
// Purpose: This class extracts files from cabinet files stored as a Win32 Resource.
//

#pragma once

#include "ExtractMemory.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

class CExtractResource : public CExtractMemory
{
public:
	CExtractResource()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Constructor CExtractResource()");
		#endif
	}
	~CExtractResource()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Destructor ~CExtractResource()");
		#endif
	}

	// Copy the content of the cabinet in the resources to disk
	// You can set sw_Module = "" if the cabinet is in the EXE file which created the process
	// Otherwise sw_Module must be the filename (without path) of the DLL which contains the CAB resource
	// To test this function with the file Test.cab included in this project
	// set sw_Module = "" and u32_ResID = ID_CAB_TEST and sw_ResType = "CABFILE"
	// because the file Cabinet.rc contains:
	// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
	BOOL ExtractResourceW(CStrW sw_Module, UINT u32_ResID, UINT u32_ResType, CStrW sw_TargetDir, void * pParam = NULL)
	{ 
		if (!GetMemoryW(sw_Module, ms_Name.FormatResource(u32_ResID), ms_Type.FormatResource(u32_ResType)))
			return FALSE;

		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(CStrW sw_Module, UINT u32_ResID, CStrW sw_ResType, CStrW sw_TargetDir, void * pParam = NULL)
	{
		if (!GetMemoryW(sw_Module, ms_Name.FormatResource(u32_ResID), sw_ResType))
			return FALSE;

		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(CStrW sw_Module, CStrW sw_ResName, UINT u32_ResType, CStrW sw_TargetDir, void * pParam = NULL)
	{ 
		if (!GetMemoryW(sw_Module, sw_ResName, ms_Type.FormatResource(u32_ResType)))
			return FALSE;

		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(CStrW sw_Module, CStrW sw_ResName, CStrW sw_ResType, CStrW sw_TargetDir, void * pParam = NULL)
	{
		if (!GetMemoryW(sw_Module, sw_ResName, sw_ResType))
			return FALSE;

		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}



	// Check if the cabinet in the resources is valid
	// You can set sw_Module = "" if the cabinet is in the EXE file which created the process
	// Otherwise sw_Module must be the filename (without path) of the DLL which contains the CAB resource
	// To test this function with the file Test.cab included in this project
	// set sw_Module = "" and u32_ResID = ID_CAB_TEST and sw_ResType = "CABFILE"
	// because the file Cabinet.rc contains:
	// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
	BOOL IsResourceCabinetW(CStrW sw_Module, UINT u32_ResID, UINT u32_ResType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryW(sw_Module, ms_Name.FormatResource(u32_ResID), ms_Type.FormatResource(u32_ResType)))
			return FALSE;

		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(CStrW sw_Module, UINT u32_ResID, CStrW sw_ResType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryW(sw_Module, ms_Name.FormatResource(u32_ResID), sw_ResType))
			return FALSE;

		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(CStrW sw_Module, CStrW sw_ResName, UINT u32_ResType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryW(sw_Module, sw_ResName, ms_Type.FormatResource(u32_ResType)))
			return FALSE;

		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(CStrW sw_Module, CStrW sw_ResName, CStrW sw_ResType, PFDICABINETINFO pfdici = NULL)
	{
		if (!GetMemoryW(sw_Module, sw_ResName, sw_ResType))
			return FALSE;
		
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}


protected:

	kMemory mk_Memory;
	CStrW   ms_Name;
	CStrW   ms_Type;

	// Fills the structure in mk_Memory with a pointer to the resource in memory
	// u16_Module may be = "" if the cabinet is in the file which created the process!!
	BOOL GetMemoryW(WCHAR* u16_Module, WCHAR* u16_ResName, WCHAR* u16_ResType)
	{
		if (wcslen(u16_Module) == 0)
			u16_Module = 0; // GetModuleHandle returns a handle of the file used to create the calling process.

		// Load the resource
		HMODULE h_DLL      = GetModuleHandleW(u16_Module);
		HRSRC   h_Resource = FindResourceW(h_DLL, u16_ResName, u16_ResType);
		HGLOBAL h_Global   = LoadResource (h_DLL, h_Resource);

		mk_Memory.p_Addr   = LockResource  (h_Global);
		mk_Memory.s32_Size = SizeofResource(h_DLL, h_Resource);
		mk_Memory.s32_Pos  = 0;

		if (mk_Memory.p_Addr == 0 || mk_Memory.s32_Size == 0)
		{
			mi_Error.Set(FDIERROR_INVAL_RESOURCE,0,0);
			return FALSE;
		}
		return TRUE;
	}

	// This function returns a new structure with the pointer to the resource data in memory
	kMemory* OpenMem(WCHAR* u16_File, int oflag, int pmode)
	{
		// IMPORTANT: The structure MUST be COPIED into a new instance !!!!
		// Cabinet.DLL will call OpenMem() TWO times and each time it requires 
		// an individual structure which has its own read position in kMemory.s32_Pos!
		// Later this kMemory instance will be deleted in ExtractMemory::CloseMem()
		return new kMemory(mk_Memory);
	}


	// Copies a part of the CAB file's memory from the resource to the given buffer
	int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
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
	friend class CExtractMemory;
};

} // Namespace Cabinet

