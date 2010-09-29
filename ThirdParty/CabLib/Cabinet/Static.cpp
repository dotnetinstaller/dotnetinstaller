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
// In the constructor of CCompress or CExtract this would not be 100% safe. 
// Although the probability that this causes a problem is !extremely! low, 
// this class completely eliminates this risk
// 
// If the static gi_Static would be defined in a HPP file rather than a CPP file you would get linker errors.

#include "Static.hpp"
#include "Trace.hpp"

// The following line executes before entering into Main() / DllMain()
static Cabinet::CStatic gi_Static;

// These are the implementations of the static variables which are defined in Static.hpp
LONG  Cabinet::CStatic::ms32_CompressClassID;
DWORD Cabinet::CStatic::mu32_ExtractTlsIndex;

// This constructor will ALWAYS be executed ONLY ONCE before entering into Main() / DllMain() 
// no matter how many threads you start later for extraction or compression of CAB files!
// This is absolutely thread safe while defining any static variables in CExtract or CCompress
// and initializing them !!THERE!! will only work in 99,9% of the cases.
Cabinet::CStatic::CStatic()
{
	#if _TraceExtract || _TraceCompress
		CTrace::TraceW(L"Constructor CStatic() initializing Critical Section structures");
	#endif

	ms32_CompressClassID = 0;
	mu32_ExtractTlsIndex = TlsAlloc();
}

// ###############################################################################
// ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION
// ------------------------------------------------------------------------------- 
//
//  If you manually add this file to another project you must right click it
//  in Solution Explorer and under Settings -> Precompiled Headers
//  you must select "Not using precompiled headers" otherwise you get 
//  C1010: unexpected end of file while looking for precompiled header directive
//
// -------------------------------------------------------------------------------
// ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION 
// ###############################################################################
