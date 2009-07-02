///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://kickme.to/elmue)
// Date: 23-11-2006
//
// Filename: Map.hpp
//
// Classes:
// - CMap
//
// Purpose: This tiny class is a simple (and ultra fast) replacement for std::map
// It is strongly recommended to use this class intead, because using #include <map>
// will create a dependency to MSVCP70.DLL or MSVCP71.DLL or MSVCP80.DLL
// If you use std::map you have to deliver one of these DLLs with you application 
// because these DLLs are not available on every computer.
// Using CMap instead removes this problem!
//

#pragma once

namespace Cabinet
{

// Dynamic memory management is not necessary for this simple class
// we will never need more than 2 entries! (the handles of the CAB file)
// If the maximum is exceeded an exception will be thrown, 
// but this will never happen as long as CMap is used only in the cabinet library
#define __MaxEntries 100

class CMap
{
private:
	struct kData
	{
		int Key;
		int Value;
	};

	int    ms32_Count;
	kData  mk_Data[__MaxEntries];

public:
	CMap()
	{
		Clear();
	}

	void Clear()
	{
		ms32_Count = 0;
	}

	int Count()
	{
		return ms32_Count;
	}

	// Returns the zero based index of the Key or -1 if not found
	int Find(int Key)
	{
		for (int i=0; i<ms32_Count; i++)
		{
			if (mk_Data[i].Key == Key)
				return i;
		}
		return -1;
	}

	// Delete the given Key if it exists
	void Erase(int Key)
	{
		int Pos = Find(Key);
		if (Pos < 0)
			return;

		ms32_Count --;
		memmove(&mk_Data[Pos], &mk_Data[Pos+1], sizeof(kData) * (ms32_Count -Pos));
	}

	// Sets a value for the given key
	// If the key already exists, its value is overwritten
	// If the key does not yet exist, it is created
	void Set(int Key, int Value)
	{
		int Pos = Find(Key);
		if (Pos < 0)
		{
			if (ms32_Count >= __MaxEntries)
				throw "Overflow in CMap::Set()";

			Pos = ms32_Count; // create new entry
			ms32_Count ++;
		}

		mk_Data[Pos].Key   = Key;
		mk_Data[Pos].Value = Value;
	}

	// Returns the value of the Key at the given position
	// Before you must retrieve the position with Find(Key)
	// Do not call GetAt() if Find() returned -1 !!
	int GetAt(int Pos)
	{
		if (Pos < 0 || Pos >= ms32_Count)
			throw "Invalid position in CMap::Get()";

		return mk_Data[Pos].Value;
	}
};

// Used to decrypt the CAB file and store handles of CAB files
struct kStore
{
	// This map holds the file handles of the CAB file, which is opened TWICE by Cabinet.dll !!
	// It stores the handle of both opened CAB files and their current read / write positions
	CMap i_Map;

	char   s8_Key[5000];     // Holds the Encryption string if it has been set by SetEncryptionKey()
	int   s32_KeyLen;        // The length of the key
	char   s8_CabFile[2000]; // The path to the CAB file file which is currently written

	// Constructor
	kStore()
	{
		 s8_Key[0]     = 0;
		s32_KeyLen     = 0;
		 s8_CabFile[0] = 0;
	}

	// clear all stored file handles
	void Clear() 
	{ 
		i_Map.Clear(); 
	}
	// returns TRUE if the given file handle is the CAB file
	BOOL IsCabFile(int s32_FileHandle)
	{
		return (i_Map.Find(s32_FileHandle) > -1);
	}
	// remove the given file handle from the map
	void Erase(int s32_FileHandle)
	{
		i_Map.Erase(s32_FileHandle);
	}
	// set a pair of file handle and file pointer
	void SetPtr(int s32_FileHandle, int s32_FilePointer)
	{
		// ATTENTION: FileHandle may be a negative value!!!
		if (s32_FileHandle == 0 || s32_FileHandle == -1) return;
		i_Map.Set(s32_FileHandle, s32_FilePointer);
	}
	// return the file pointer for the given file handle or -1 if not found
	int GetPtr(int s32_FileHandle)
	{
		int Pos = i_Map.Find(s32_FileHandle);
		if (Pos < 0) return -1;
		return i_Map.GetAt(Pos);
	}
};


} // Namespace Cabinet
