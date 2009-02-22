///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Luuk Weltevreden
// Date: 23-07-2004
//
// Completely rewritten by Elmü (http://kickme.to/elmue)
// Date: 12-12-2007
//
// Filename: ExtractExT.hpp
//
// Classes:
// - CExtractMemoryT<T>
//
// Purpose: This template extracts files from cabinet files by direct memory access.
//

#pragma once

#include "ExtractT.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{


template <class T> class CExtractMemoryT : public CExtractT<T>
{
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

	// This function overrides file access in ExtractT
	// For the CAB file it calls OpenMem(), for all other files it calls Open()
	static int Open(char* filename, int oflag, int pmode)
	{
		if (stricmp(filename, Store().s8_CabFile) == 0)
			return PtrToInt(T::OpenMem(filename, oflag, pmode));
		else
			return CExtractT<T>::Open(filename, oflag, pmode);
	}

	// This function overrides file access in ExtractT
	// For the CAB file it calls ReadMem(), for all other files it calls Read()
	static int Read(int fd, void* buffer, UINT count)
	{
		if (Store().IsCabFile(fd))
		{
			kMemory* pk_Mem = (kMemory*)IntToPtr(fd);
			int s32_Read = T::ReadMem(pk_Mem, buffer, count);
			if (s32_Read > 0) pk_Mem->s32_Pos += s32_Read;
			return s32_Read;
		}
		else
			return CExtractT<T>::Read(fd, buffer, count);
	}

	// This function overrides file access in ExtractT
	// For the CAB file it calls SeekMem(), for all other files it calls Seek()
	static long Seek(int fd, long offset, int origin)
	{
		if (Store().IsCabFile(fd))
			return T::SeekMem((kMemory*)IntToPtr(fd), offset, origin);
		else
			return CExtractT<T>::Seek(fd, offset, origin);
	}

	// This function overrides file access in ExtractT
	// For the CAB file it calls CloseMem(), for all other files it calls Close()
	static int Close(int fd)
	{
		if (Store().IsCabFile(fd))
			return T::CloseMem((kMemory*)IntToPtr(fd));
		else
			return CExtractT<T>::Close(fd);
	}

	// ################## OVERRIDABLES ####################

	// You can overwrite the following functions in a derived class
	// The parameters and return values must be identical to the file access functions.

	// Must always be overridden (opening the CAB memory)
	// Must always return new kMemory();
	static kMemory* OpenMem(char* filename, int oflag, int pmode)
	{ 
		errno = ENOSPC; 
		return (kMemory*) -1;
	}

	// Must always be overridden (reading CAB memory data)
	// Must return the count of bytes read
	static int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
	{  
		errno = ENOSPC; 
		return -1;
	}

	// Changes the file pointer used for walking the memory of the CAB file.
	// May be overridden (normally it is not required to override this)
	// Must return the current file pointer position
	static long SeekMem(kMemory* pk_Mem, long offset, int origin)
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

		case SEEK_END:
			s32_Pos = pk_Mem->s32_Size + offset;
			break;
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
	static int CloseMem(kMemory* pk_Mem)
	{
		delete pk_Mem;
		return 0;
	}

	// Declare this class as a friend so it can access the protected members.
	friend class CExtractT<T>;
};

} // Namespace Cabinet
