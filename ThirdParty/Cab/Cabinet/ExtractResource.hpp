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
	BOOL ExtractResourceW(const CStrW& sw_Module, UINT u32_ResID, UINT u32_ResType, const CStrW& sw_TargetDir, void * pParam = NULL)
	{ 
		mk_Resource.Set(sw_Module, L"", u32_ResID, L"", u32_ResType);
		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(const CStrW& sw_Module, UINT u32_ResID, const CStrW& sw_ResType, const CStrW& sw_TargetDir, void * pParam = NULL)
	{
		mk_Resource.Set(sw_Module, L"", u32_ResID, sw_ResType, 0);
		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(const CStrW& sw_Module, const CStrW& sw_ResName, UINT u32_ResType, const CStrW& sw_TargetDir, void * pParam = NULL)
	{ 
		mk_Resource.Set(sw_Module, sw_ResName, 0, L"", u32_ResType);
		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}
	BOOL ExtractResourceW(const CStrW& sw_Module, const CStrW& sw_ResName, const CStrW& sw_ResType, const CStrW& sw_TargetDir, void * pParam = NULL)
	{
		mk_Resource.Set(sw_Module, sw_ResName, 0, sw_ResType, 0);
		return ExtractFileW(L"*CABINET\\*RESOURCE", sw_TargetDir, pParam);
	}


	// Check if the cabinet in the resources is valid
	// You can set sw_Module = "" if the cabinet is in the EXE file which created the process
	// Otherwise sw_Module must be the filename (without path) of the DLL which contains the CAB resource
	// To test this function with the file Test.cab included in this project
	// set sw_Module = "" and u32_ResID = ID_CAB_TEST and sw_ResType = "CABFILE"
	// because the file Cabinet.rc contains:
	// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
	BOOL IsResourceCabinetW(const CStrW& sw_Module, UINT u32_ResID, UINT u32_ResType, PFDICABINETINFO pfdici = NULL)
	{
		mk_Resource.Set(sw_Module, L"", u32_ResID, L"", u32_ResType);
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(const CStrW& sw_Module, UINT u32_ResID, const CStrW& sw_ResType, PFDICABINETINFO pfdici = NULL)
	{
		mk_Resource.Set(sw_Module, L"", u32_ResID, sw_ResType, 0);
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(const CStrW& sw_Module, const CStrW& sw_ResName, UINT u32_ResType, PFDICABINETINFO pfdici = NULL)
	{
		mk_Resource.Set(sw_Module, sw_ResName, 0, L"", u32_ResType);
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}
	BOOL IsResourceCabinetW(const CStrW& sw_Module, const CStrW& sw_ResName, const CStrW& sw_ResType, PFDICABINETINFO pfdici = NULL)
	{
		mk_Resource.Set(sw_Module, sw_ResName, 0, sw_ResType, 0);
		return IsCabinetW(L"*CABINET\\*RESOURCE", pfdici);
	}


protected:

	struct kResource
	{
		CStrW sw_CurFile;
		CStrW sw_Module;
		UINT u32_ID;   // Usage of either ID or Name
		CStrW sw_Name; // Usage of either ID or Name
		CStrW sw_Type;

		void Set(const CStrW& swModule, const CStrW& swName, UINT u32ID, const CStrW& swType, UINT u32Type)
		{
			sw_CurFile.Clean();
			sw_Module = swModule;
			u32_ID    = u32ID;
			sw_Name   = swName;
			sw_Type   = swType;
			if (u32Type) sw_Type.FormatResource(u32Type);
		}
	};

	kResource mk_Resource;
	kMemory   mk_Memory;

	// Fills the structure in mk_Memory with a pointer to the resource in memory
	// mk_Resource.sw_Module may be = "" if the cabinet is in the EXE which created the process.
	BOOL GetMemory()
	{
		CStrW sw_ResName = mk_Resource.sw_Name;
		if (mk_Resource.u32_ID) sw_ResName.FormatResource(mk_Resource.u32_ID);

		WCHAR* u16_Module = 0; // Resource is in the calling process
		if (mk_Resource.sw_Module.Len())
			u16_Module = mk_Resource.sw_Module;

		// Load the resource (via Filemapping, there is no memory consumption here)
		HMODULE h_DLL      = GetModuleHandleW(u16_Module);
		HRSRC   h_Resource = FindResourceW(h_DLL, sw_ResName, mk_Resource.sw_Type);
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
	// This function is called TWICE for each CAB file!!
	kMemory* OpenMem(const WCHAR* u16_File, int oflag, int pmode)
	{
		// the first or the next CAB file is to be opened
		if (mk_Resource.sw_CurFile != u16_File)
		{
			// The second, third,.. part of a splitted Cabinet is to be opened
			if (mk_Resource.sw_CurFile.Len())
			{
				// If the resource was specified as integer ID -> increment to the next value
				if (mk_Resource.u32_ID) 
					mk_Resource.u32_ID++;
				else // If the resource was specified by name -> use the name stored in the previous CAB part
					CFile::SplitPathW(u16_File, 0, &mk_Resource.sw_Name);
			}

			mk_Resource.sw_CurFile = u16_File;
			if (!GetMemory())
				return (kMemory*)-1;
		}

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

