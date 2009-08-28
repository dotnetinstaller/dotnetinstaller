///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 19-04-2008
//
// Filename: ExtractStreamT.hpp
//
// - CExtractStreamT<T>
// - CExtractStream
//
// Purpose: This template extracts files from a stream which represents a cabinet file
//

#pragma once

#include "ExtractMemory.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

class CExtractStream : public CExtractMemory
{
public:
	// Copy the files from the stream which contains a cabinet file
	BOOL ExtractStreamW(CStrW sw_TargetDir, void* pParam = NULL)
	{
		// Pass it on to the base class (the file name is a dummy which is not used)
		return ExtractFileW(L"*CABINET\\*STREAM", sw_TargetDir, pParam);
	}

	// Check if the stream contains a valid cabinet file
	BOOL IsStreamCabinet(PFDICABINETINFO pfdici = NULL)
	{
		// Pass it on to the base class (the file name is a dummy which is not used)
		return IsCabinetW(L"*CABINET\\*STREAM", pfdici);
	}

private:
	// Reset the stream pointer to the beginning of the stream
	kMemory* OpenMem(WCHAR* u16_File, int oflag, int pmode)
	{
		if (!mk_Callbacks.f_StreamGetLen)
			return 0;

		int Size = mk_Callbacks.f_StreamGetLen(mp_Param);
		return new kMemory(0, 0, Size);
	}

	// Copies a part of the memory from the stream to the buffer.
	int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
	{
		if (!mk_Callbacks.f_StreamRead)
			return 0;

		// Return the amount of bytes copied
		return mk_Callbacks.f_StreamRead(buffer, pk_Mem->s32_Pos, count, mp_Param);
	}

	// Declare this class as a friend so it can access the private members.
	friend class CExtractMemory;
};

} // Namespace Cabinet

