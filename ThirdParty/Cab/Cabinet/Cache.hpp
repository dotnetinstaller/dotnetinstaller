///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 14-03-2008
//
// Filename: Cache.hpp
//
// Classes:
// - CMemBlock
// - CCache
//
// Purpose: CCache is a storage for any data which is read sequencially
// It is used to hold data from the HTTP server which is downloaded in larger chunks
// and then read by Cabinet.dll in smaller chunks.
// Cabinet.dll opens two file pointers to read the CAB file:
// One reads only the filenames and the other one reads the compressed data.
// The pointer which reads the filenames reads alternating 16 Byte, then 256 Byte.
// It would result in a very bad performance downloading such small peaces from the HTTP server!
//

#pragma once

#include <stdio.h>

#include "Trace.hpp"

namespace Cabinet
{

// ########################################################################

// a class to store one block of memory
class CMemBlock
{
public:

	// Callback function that requests more data
	// returns the count of bytes that have been read or -1 on error
	typedef int (*fReadData)(void* p_Buffer, DWORD u32_Offset, DWORD u32_Count);

private:
	WCHAR   mu16_Name[3];      // for debugging (Trace)
	BYTE*    mu8_Memory;       // pointer to memory
	int     ms32_BlockSize;    // size of memory
	int     ms32_StartPos;     // Absolute read position in the entire data 
	int     ms32_Content;      // Current content of the block
	fReadData mf_ReadCallback; // Callback function that is called to read more data

public:

	// Constructor
	CMemBlock()
	{
		mu16_Name[0]    = 0;
		mu8_Memory      = 0;
		ms32_BlockSize  = 0;
		ms32_StartPos   = 0;
		ms32_Content    = 0;
		mf_ReadCallback = 0;
	}

	~CMemBlock()
	{
		if (mu8_Memory) delete mu8_Memory;
	}

	// Allocate memory or change block size or change callback
	// s32_BlockSize is the size that will be read from the given callback function
	// Setting s32_BlockSize = 0 disables the cache and frees memory
	// when more data is required
	void Init(int s32_BlockSize, fReadData f_ReadCallback, WCHAR c_CacheName, WCHAR c_BlockName)
	{
		swprintf(mu16_Name, L"%c%c", c_CacheName, c_BlockName);
		mf_ReadCallback = f_ReadCallback;

		if (ms32_BlockSize != s32_BlockSize)
		{
			ms32_BlockSize = s32_BlockSize;

			if (mu8_Memory) delete mu8_Memory;

			mu8_Memory = 0;
			if (s32_BlockSize)
			{
				mu8_Memory = new BYTE[s32_BlockSize];
				if (!mu8_Memory) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
			}
		}
	}

	BOOL ContainsRange(int s32_Pos, int s32_Length)
	{
		return (s32_Pos >= ms32_StartPos && s32_Pos + s32_Length < ms32_StartPos + ms32_Content);
	}

	// Obtain data from the cache.
	// If the cache does not contain the requested amout of data: read more from the ReadCallback.
	// returns the count of bytes that have been read or -1 on error
	int ReadData(void* p_Buffer, int s32_Pos, int s32_Count)
	{
		#if _TraceCache
			CTrace::TraceW(L"  CMemBlock %s:  ReadData(Pos= %08d, Count= %05d)", mu16_Name, s32_Pos, s32_Count);
		#endif

		if (!ms32_BlockSize)            throw "The CMemBlock cache is not intialized!";
		if (s32_Count > ms32_BlockSize) throw "Cache blocksize too small!";

		// If the cache does not contain the requested data -> fill with new data
		if (!ContainsRange(s32_Pos, 0))
		{
			#if _TraceCache
				if (s32_Pos < ms32_StartPos) CTrace::TraceW(L"******* Warning Cache Callback reads a block twice! *******");
			#endif

			ms32_StartPos = s32_Pos;
			ms32_Content  = mf_ReadCallback(mu8_Memory, s32_Pos, ms32_BlockSize);

			#if _TraceCache
				CTrace::TraceW(L"  CMemBlock %s: *Callback(Pos= %08d, Count= %05d) --> %05d Bytes read", mu16_Name, s32_Pos, ms32_BlockSize, ms32_Content);
			#endif

			if (ms32_Content < 0)
				return -1; // Read Error
		}

		int s32_RelPos = s32_Pos - ms32_StartPos;
		s32_Count = min(s32_Count, ms32_Content - s32_RelPos);

		#if _TraceCache
			CTrace::TraceW(L"  CMemBlock %s:  Copy Buf RelPos= %05d, Count= %05d", mu16_Name, s32_RelPos, s32_Count);
		#endif

		memcpy(p_Buffer, mu8_Memory + s32_RelPos, s32_Count);
		return s32_Count;
	}
};

// ########################################################################

// A class which uses two memory blocks and reads alternatingly one or both of them.
// So data which overlaps from one datablock to the next data block can be read without 
// reloading the data
class CCache
{
private:
	CMemBlock mi_Block[2];

public:
	// Allocate memory and set callback
	void Init(int s32_BlockSize, CMemBlock::fReadData f_ReadCallback, WCHAR c_CacheName)
	{
		mi_Block[0].Init(s32_BlockSize, f_ReadCallback, c_CacheName, 'A');
		mi_Block[1].Init(s32_BlockSize, f_ReadCallback, c_CacheName, 'B');
	}

	BOOL ContainsRange(int s32_Start, int s32_Length)
	{
		return (mi_Block[0].ContainsRange(s32_Start, s32_Length) ||
		        mi_Block[1].ContainsRange(s32_Start, s32_Length));
	}

	// read data from one of the blocks or from both blocks if it overlaps
	// returns the count of bytes that have been read or -1 on error
	int ReadData(void* p_Buffer, int s32_Pos, int s32_Count)
	{
		#if _TraceCache
			CTrace::TraceW(L" CCache:         ReadData(Pos= %08d, Count= %05d)", s32_Pos, s32_Count);
		#endif

		CMemBlock* pi_CacheLo = &mi_Block[0];
		CMemBlock* pi_CacheHi = &mi_Block[1];

		if (mi_Block[1].ContainsRange(s32_Pos, 0)) // Swap caches
		{
			pi_CacheLo = &mi_Block[1];
			pi_CacheHi = &mi_Block[0];
		}

		// Read from the first memory block
		int s32_Read = pi_CacheLo->ReadData(p_Buffer, s32_Pos, s32_Count);
		if (s32_Read < 0)
			return -1; // Read Error

		if (s32_Read == s32_Count)
		{
			#if _TraceCache
				CTrace::TraceW(L" CCache --> %05d Bytes read", s32_Read);
			#endif
			return s32_Read;
		}

		// read the overlapping rest from the other block
		p_Buffer   = (BYTE*)p_Buffer + s32_Read;
		s32_Pos   += s32_Read;
		s32_Count -= s32_Read;

		int s32_Rest = pi_CacheHi->ReadData(p_Buffer, s32_Pos, s32_Count);
		if (s32_Rest < 0)
			return -1;

		#if _TraceCache
			CTrace::TraceW(L" CCache --> %05d + %05d = %05d Bytes read", s32_Read, s32_Rest, s32_Read+s32_Rest);
		#endif
		return s32_Read + s32_Rest;
	}
};

} // Namespace Cabinet
