///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 04-08-2009
//
// Filename: Static.hpp + Static.cpp
//
// Class:
// - CStatic
//
// Purpose: For a 100% fail safe multithreading support it is indispensible 
// to initialize all static variables before starting to compress/extract!
// In the constructor of CCompress or CExtract this would not be 100% sure if 2 threads 
// are starting at exactly the same moment. Although the probability that this causes a
// problem is !extremely! low, this class completely eliminates this risk

#pragma once

#include <windows.h>

namespace Cabinet
{

class CStatic
{
public:
	// Constructor
	CStatic();

	static LONG  ms32_CompressClassID;
	static DWORD mu32_ExtractTlsIndex;
};

} // Namespace Cabinet


