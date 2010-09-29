///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 19-04-2008
//
// Filename: ExtractEx.hpp
//
// Classes:
// - CExtractMemory
//
// Purpose: This class extracts files from cabinet files by direct memory access.
//

#pragma once

#include "Extract.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

class CExtractMemory : public CExtract
{
public:
	CExtractMemory()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Constructor CExtractMemory()");
		#endif
	}
	~CExtractMemory()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Destructor ~CExtractMemory()");
		#endif
	}

protected:
	// Stores information about the resource, stream etc.. we are examining.
	typedef struct kMemory
	{
		void*  p_Addr;
		long   s32_Pos;
		long   s32_Size;

		// Constructor 1
		kMemory()
		{
			p_Addr   = 0;
			s32_Pos  = 0;
			s32_Size = 0;
		}

		// Constructor 2
		kMemory(void* Address, long Pos, long Size)
		{
			p_Addr   = Address;
			s32_Pos  = Pos;
			s32_Size = Size;
		}
	};

	// This function overrides file access in CExtract
	// For the CAB file it calls OpenMem(), for all other files it calls Open()
	INT_PTR Open(const WCHAR* u16_File, int oflag, int pmode)
	{
		// This function opens the CAB   file for reading
		// This function opens any other file for writing
		if (pmode & _S_IWRITE)
			return CExtract::Open(u16_File, oflag, pmode); // extracted file
		else
			return (INT_PTR)OpenMem(u16_File, oflag, pmode); // CAB file
	}

	// This function overrides file access in CExtract
	// For the CAB file it calls ReadMem(), for all other files it calls Read()
	int Read(INT_PTR fd, void* buffer, UINT count)
	{
		if (mi_Files.IsCabFile(fd))
		{
			kMemory* pk_Mem = (kMemory*)fd;
			int s32_Read = ReadMem(pk_Mem, buffer, count);
			if (s32_Read > 0) pk_Mem->s32_Pos += s32_Read;
			return s32_Read;
		}
		else
			return CExtract::Read(fd, buffer, count);
	}

	// This function overrides file access in CExtract
	// For the CAB file it calls SeekMem(), for all other files it calls Seek()
	long Seek(INT_PTR fd, long offset, int origin)
	{
		if (mi_Files.IsCabFile(fd))
			return SeekMem((kMemory*)fd, offset, origin);
		else
			return CExtract::Seek(fd, offset, origin);
	}

	// This function overrides file access in CExtract
	// For the CAB file it calls CloseMem(), for all other files it calls Close()
	int Close(INT_PTR fd)
	{
		if (mi_Files.IsCabFile(fd))
			return CloseMem((kMemory*)fd);
		else
			return CExtract::Close(fd);
	}

	// ################## OVERRIDABLES ####################

	// You can overwrite the following functions in a derived class
	// The parameters and return values must be identical to the file access functions.

	// Must always be overridden (opening the CAB memory)
	// Must always return new kMemory();
	virtual kMemory* OpenMem(const WCHAR* u16_File, int oflag, int pmode)
	{ 
		errno = ENOSPC; 
		return (kMemory*) -1;
	}

	// Must always be overridden (reading CAB memory data)
	// Must return the count of bytes read
	virtual int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
	{  
		errno = ENOSPC; 
		return -1;
	}

	// Changes the file pointer used for walking the memory of the CAB file.
	// May be overridden (normally it is not required to override this)
	// Must return the current file pointer position
	virtual long SeekMem(kMemory* pk_Mem, long offset, int origin)
	{
		// Calculate the new pointer
		long s32_Pos = -1;
		switch (origin)
		{
		case SEEK_SET:
			s32_Pos = offset;
			break;

		case SEEK_CUR:
			s32_Pos = pk_Mem->s32_Pos + offset;
			break;

		default: // SEEK_END is never used!
			errno = EBADF;
			return -1;
		}

		// Can't pass before the start of the file
		if (s32_Pos < 0 || s32_Pos >= pk_Mem->s32_Size)
		{
			errno = EBADF;
			return -1;
		}

		// Store the new pointer
		pk_Mem->s32_Pos = s32_Pos;
		return  s32_Pos;
	}

	// Deletes the memory we allocated in OpenMem().
	// May be overridden
	virtual int CloseMem(kMemory* pk_Mem)
	{
		delete pk_Mem;
		return 0;
	}

	// Declare this class as a friend so it can access the protected members.
	friend class CExtract;
};

} // Namespace Cabinet

