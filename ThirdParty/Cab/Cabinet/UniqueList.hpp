#pragma once

namespace Cabinet
{

template<class cDataType>
class CList
{
public:
	CList()
		: ms32_Size(4)
		, ms32_Count(0)
	{
		mp_Data = new cDataType[ms32_Size];
		if (!mp_Data) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
	}

	~CList()
	{
		delete[] mp_Data;
	}

	void Clear()
	{
		ms32_Count = 0;
	}

	int Count()
	{
		return ms32_Count;
	}

	cDataType GetAt(int Pos)
	{
		return mp_Data[Pos];
	}

	// Remove at an index
	cDataType RemoveAt(int Pos)
	{
		cDataType removedData = mp_Data[Pos];

		// overwrite the element which is deleted and shift
		ms32_Count--;
		while(Pos < ms32_Count)
		{
			mp_Data[Pos] = mp_Data[Pos + 1];
			Pos++;
		}

		return removedData;
	}

	bool Contains(cDataType i_Data)
	{
		for(int i = 0; i < ms32_Count; i++)
		{
			if (mp_Data[i] == i_Data)
				return true;
		}

		return false;
	}

	// Add
	bool Add(cDataType i_Data)
	{
		if (Contains(i_Data))
			return false;

		if (ms32_Count >= ms32_Size) // Allocate the double amount of list entries
		{
			ms32_Size *= 2;
			cDataType* p_DataNew = new cDataType[ms32_Size];
			if (!p_DataNew) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
			
			for (int i = 0; i < ms32_Count; i++)
				p_DataNew[i] = mp_Data[i];

			delete[] mp_Data;
			mp_Data = p_DataNew;
		}

		mp_Data[ms32_Count] = i_Data;
		ms32_Count++;
		return true;
	}

private:
	int        ms32_Size;
	int        ms32_Count;
	cDataType* mp_Data;
};

}
