///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 23-11-2006
//
// Filename: Map.hpp
//
// Classes:
// - CMap
// - CFilePtr
//
// Purpose: This tiny class is a simple (and ultra fast) replacement for std::map
// It is strongly recommended to use this class instead, because using #include <map>
// will create a dependency to MSVCP70.DLL or MSVCP71.DLL or MSVCP80.DLL
// If you use std::map you have to deliver one of these DLLs with you application 
// because these DLLs are not available on every computer.
// Using CMap instead removes this problem!
//

#pragma once

#include "String.hpp"

namespace Cabinet
{

template<class cKeyType, class cDataType>
class CMap
{
public:
	CMap()
	{
		// For CFilePtr only two CAB handles have to be stored. So the 4 are more than needed.
		ms32_Size = 4;
		mp_Keys = new cKeyType [ms32_Size];
		mp_Data = new cDataType[ms32_Size];
		if (!mp_Keys || !mp_Data) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions

		Clear();
	}

	~CMap()
	{
		delete mp_Keys;
		delete mp_Data;
	}

	void Clear()
	{
		ms32_Count = 0;
	}

	int Count()
	{
		return ms32_Count;
	}

	int Find(cKeyType i_Key)
	{
		for (int i=0; i<ms32_Count; i++)
		{
			if (mp_Keys[i] == i_Key)
				return i;
		}
		return -1;
	}

	// Returns the data stored with the Key. returns FALSE if key not found.
	BOOL GetData(cKeyType i_Key, cDataType* p_Data)
	{
		int Pos = Find(i_Key);
		if (Pos < 0)
		{
			*p_Data = NULL;
			return FALSE;
		}

		*p_Data = mp_Data[Pos];
		return TRUE;
	}

	// Delete the given Key if it exists
	void Delete(cKeyType i_Key)
	{
		int Pos = Find(i_Key);
		if (Pos < 0)
			return;

		ms32_Count --;
		// overwrite the element which is deleted with the last element
		mp_Data[Pos] = mp_Data[ms32_Count];
		mp_Keys[Pos] = mp_Keys[ms32_Count];
	}

	// Sets the data for the given key
	// If the key already exists, its data is overwritten
	// If the key does not yet exist, it is created
	void Set(cKeyType i_Key, cDataType i_Data)
	{
		int Pos = Find(i_Key);
		if (Pos < 0)
		{
			if (ms32_Count >= ms32_Size) // Allocate the double amount of map entries
			{
				ms32_Size *= 2;
				cKeyType*  p_KeysNew = new cKeyType [ms32_Size];
				cDataType* p_DataNew = new cDataType[ms32_Size];
				if (!p_KeysNew || !p_DataNew) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
				
				memcpy(p_KeysNew, mp_Keys, ms32_Count * sizeof(cKeyType));
				memcpy(p_DataNew, mp_Data, ms32_Count * sizeof(cDataType));

				delete mp_Keys;
				delete mp_Data;

				mp_Keys = p_KeysNew;
				mp_Data = p_DataNew;
			}

			Pos = ms32_Count; // create new entry at index Pos
			ms32_Count ++;
		}

		mp_Data[Pos] = i_Data;
		mp_Keys[Pos] = i_Key;
	}

private:
	int        ms32_Size;
	int        ms32_Count;
	cKeyType*  mp_Keys;
	cDataType* mp_Data;
};

// Stores handles of all CAB files and their read pointer position
class CFilePtr
{
public:

	void Clear() 
	{ 
		mi_Map.Clear(); 
	}

	BOOL IsCabFile(INT_PTR s32_Handle)
	{
		return mi_Map.Find(s32_Handle) >= 0;
	}

	void Delete(INT_PTR s32_Handle)
	{
		mi_Map.Delete(s32_Handle);
	}
	
	void SetPtr(INT_PTR s32_Handle, int s32_Pointer)
	{
		if (s32_Handle == 0 || s32_Handle == -1) 
			return;
		
		mi_Map.Set(s32_Handle, s32_Pointer);
	}

	int GetPtr(INT_PTR s32_Handle)
	{
		int s32_Ptr;
		if (mi_Map.GetData(s32_Handle, &s32_Ptr))
			return s32_Ptr;
		else 
			return -1;
	}

private:

	CMap<INT_PTR, int> mi_Map;
};

} // Namespace Cabinet


