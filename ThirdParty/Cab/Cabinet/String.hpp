///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 23-08-2008
//
// Filename: String.hpp
//
// Classes:
// - CStrA
// - CStrW
//
// Purpose: This tiny class represents ultra fast Ansi and Unicode strings.
// It does not require any external DLLs like for MFC CString or std::string
//
// Additionally it encodes Unicode to UTF8 and decodes UTF8 to Unicode
//
// ---------------------------------------------------------------------
// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
//
// If you need to encode/decode multiple strings at the same time 
// you MUST create a new CUtf8 instance for EACH string 
// 
// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
// ---------------------------------------------------------------------

#pragma once


#pragma warning(disable: 4996)
#pragma warning(disable: 4793)


// this is enough for all paths which occupy 260 characters (MAX_PATH)
#define DEFAULT_BUFSIZE   300

namespace Cabinet
{

class CStrA
{
private:
	char* ms8_Buf;
	UINT mu32_Size;

public:

	CStrA()
	{
		ms8_Buf   = 0;
		mu32_Size = 0;
		Allocate(DEFAULT_BUFSIZE);
		ms8_Buf[0] = 0;
	}
	CStrA(const char* s8_String)
	{
		ms8_Buf   = 0;
		mu32_Size = 0;
		Allocate(max(DEFAULT_BUFSIZE, (UINT)strlen(s8_String))); // throws
		strcpy(ms8_Buf, s8_String);
	}
	CStrA(const CStrA& s_String)
	{
		ms8_Buf   = 0;
		mu32_Size = 0;
		Allocate(max(DEFAULT_BUFSIZE, s_String.Len())); // throws
		strcpy(ms8_Buf, s_String);
	}
	~CStrA()
	{
		delete[] ms8_Buf;
	}

	// return the buffer
	operator char*() const
	{
		return ms8_Buf;
	}

	void Clean()
	{
		ms8_Buf[0] = 0;
	}

	// !ALWAYS! recalculate the length!!! The buffer may have been modified exernally
	UINT Len() const
	{
		UINT u32_Len = (UINT)strlen(ms8_Buf);
		if (u32_Len >= mu32_Size) throw "The string has no terminating null character!";
		return u32_Len;
	}

	// if the buffer is too small -> copy the old content to the new buffer
	void Allocate(UINT u32_Size)
	{
		if (u32_Size < mu32_Size) // NOT "<=" here!!
			return;

		u32_Size *= 2; // always allocate more than required to store the string

		char* s8_New = new char[u32_Size];
		if  (!s8_New) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions

		if (ms8_Buf)
		{
			strncpy(s8_New, ms8_Buf, Len()+1);
			delete[] ms8_Buf;
		}
		else s8_New[0] = 0;

		ms8_Buf   = s8_New;
		mu32_Size = u32_Size;
	}

	void Assign(const char* s8_String, UINT u32_Len)
	{
		Allocate(u32_Len); // throws
		strncpy(ms8_Buf, s8_String, u32_Len);
		ms8_Buf[u32_Len] = 0;
	}
	void operator=(const char* s8_String)
	{
		Assign(s8_String, (UINT)strlen(s8_String));
	}
	void operator=(const CStrA& s_String)
	{
		Assign(s_String, s_String.Len());
	}
	// copies an Unicode string into an Ansi string without any encoding
	// Throws exception if invalid characters > 0xFF are found
	void operator=(const WCHAR* u16_Unicode)
	{
		int s32_Len = (int)wcslen(u16_Unicode);
		ms8_Buf[0] = 0;
		Allocate(s32_Len);

		for (int i=0; i<=s32_Len; i++)
		{
			if (u16_Unicode[i] > 0xFF) throw "Unicode string cannot be converted to Ansi!";
			ms8_Buf[i] = (char)u16_Unicode[i];
		}
	}

	// Append external string to the current content
	void operator+=(const char* s8_String)
	{
		Allocate(Len() + (UINT)strlen(s8_String));
		strcat(ms8_Buf, s8_String);
	}
	void operator+=(const CStrA& s_String)
	{
		Allocate(Len() + s_String.Len());
		strcat(ms8_Buf, s_String);
	}

	BOOL operator==(const char* s8_String)
	{
		return (stricmp(ms8_Buf, s8_String) == 0);
	}
	BOOL operator==(const CStrA& s_String)
	{
		return (stricmp(ms8_Buf, s_String) == 0);
	}

	BOOL operator!=(const char* s8_String)
	{
		return (stricmp(ms8_Buf, s8_String) != 0);
	}
	BOOL operator!=(const CStrA& s_String)
	{
		return (stricmp(ms8_Buf, s_String) != 0);
	}

	void Format(const char* s8_Format, ...)
	{
		va_list  args;
		va_start(args, s8_Format);
		while (true)
		{
			int s32_Len = _vsnprintf(ms8_Buf, mu32_Size, s8_Format, args);
			if (s32_Len >= 0)
				break;
		
			ms8_Buf[0] = 0;
			Allocate(mu32_Size * 2); // s32_Len = -1 -> Buffer too small, try again
		}
	}

	// Copy string content to external buffer
	BOOL SafeExport(char* s8_Buffer, UINT u32_BufSize)
	{
		if (u32_BufSize < Len()+1)
			return FALSE;
			
		strcpy(s8_Buffer, ms8_Buf);
		return TRUE;
	}

	// ************* UTF8 ENCODER ****************

	// Convert an Unicode string into an UTF8 string and stores it in "this"
	char* EncodeUtf8(const WCHAR* u16_Unicode)
	{
		// UTF8: One Unicode character is converted into 1,2,3 or 4 ASCII characters
		ms8_Buf[0] = 0;		
		Allocate((UINT)wcslen(u16_Unicode)*4);

		int s32_Len = WideCharToMultiByte(CP_UTF8, 0, u16_Unicode, -1, ms8_Buf, mu32_Size, 0, 0);
		
		ms8_Buf[s32_Len] = 0;
		return  ms8_Buf;
	}

}; // class

// ############################################################################

class CStrW
{
private:
	WCHAR* mu16_Buf;
	UINT  mu32_Size;

public:

	CStrW()
	{
		mu16_Buf  = 0;
		mu32_Size = 0;
		Allocate(DEFAULT_BUFSIZE);
		mu16_Buf[0] = 0;
	}
	CStrW(const WCHAR* u16_String)
	{
		mu16_Buf  = 0;
		mu32_Size = 0;
		Allocate(max(DEFAULT_BUFSIZE, (UINT)wcslen(u16_String))); // throws
		wcscpy(mu16_Buf, u16_String);
	}
	CStrW(const CStrW& s_String)
	{
		mu16_Buf  = 0;
		mu32_Size = 0;
		Allocate(max(DEFAULT_BUFSIZE, s_String.Len())); // throws
		wcscpy(mu16_Buf, s_String);
	}
	~CStrW()
	{
		delete[] mu16_Buf;
	}

	// return the buffer
	operator WCHAR*() const
	{
		return mu16_Buf;
	}

	void Clean()
	{
		mu16_Buf[0] = 0;
	}

	// !ALWAYS! recalculate the length!!! The buffer may have been modified exernally
	UINT Len() const
	{
		UINT u32_Len = (UINT)wcslen(mu16_Buf);
		if (u32_Len >= mu32_Size) throw "The string has no terminating null character!";
		return u32_Len;
	}

	// if the buffer is too small -> copy the old content to the new buffer
	void Allocate(UINT u32_Size)
	{
		if (u32_Size < mu32_Size) // NOT "<=" here!!
			return;

		u32_Size *= 2; // always allocate more than required to store the string

		WCHAR* u16_New = new WCHAR[u32_Size];
		if   (!u16_New) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions

		if (mu16_Buf)
		{
			wcsncpy(u16_New, mu16_Buf, Len()+1);
			delete[] mu16_Buf;
		}
		else u16_New[0] = 0;

		mu16_Buf  = u16_New;
		mu32_Size = u32_Size;
	}

	void Assign(const WCHAR* u16_String, UINT u32_Len)
	{
		Allocate(u32_Len); // throws
		wcsncpy(mu16_Buf, u16_String, u32_Len);
		mu16_Buf[u32_Len] = 0;
	}
	void operator=(const WCHAR* u16_String)
	{
		Assign(u16_String, (UINT)wcslen(u16_String));
	}
	void operator=(const CStrW& s_String)
	{
		Assign(s_String, s_String.Len());
	}
	// copies an ASCII or ANSI string into a Unicode string without any encoding
	void operator=(const char* s8_Ansi)
	{
		int s32_Len = (int)strlen(s8_Ansi);
		mu16_Buf[0] = 0;
		Allocate(s32_Len);

		for (int i=0; i<=s32_Len; i++)
		{
			mu16_Buf[i] = (BYTE)s8_Ansi[i];
		}
	}

	// Append external string to the current content
	void operator+=(const WCHAR* u16_String)
	{
		Allocate(Len() + (UINT)wcslen(u16_String));
		wcscat(mu16_Buf, u16_String);
	}
	void operator+=(const CStrW& s_String)
	{
		Allocate(Len() + s_String.Len());
		wcscat(mu16_Buf, s_String);
	}

	BOOL operator==(const WCHAR* u16_String)
	{
		return (wcsicmp(mu16_Buf, u16_String) == 0);
	}
	BOOL operator==(const CStrW& s_String)
	{
		return (wcsicmp(mu16_Buf, s_String) == 0);
	}

	BOOL operator!=(const WCHAR* u16_String)
	{
		return (wcsicmp(mu16_Buf, u16_String) != 0);
	}
	BOOL operator!=(const CStrW& s_String)
	{
		return (wcsicmp(mu16_Buf, s_String) != 0);
	}

// Visual Studio 6.0 will not compile this because VARIANT does not define llVal and ullVal
// But for C++ projects this function is not required. It is only used in the .NET project.
// So simply omit it from compiling on Visual Studio 6!
#if _MSC_VER > 1200 

	// pk_Args is a pointer to an array of VARIANT's with s32_ArgCount entries
	void Format(const WCHAR* u16_Format, int s32_ArgCount, VARIANT* pk_Args)
	{
		char* s8_Stack = new char[s32_ArgCount * sizeof(VARIANT)]; // always big enough
		if  (!s8_Stack) throw "Fatal error: Out of memory!";       // Required for older Visual Studio versions

		va_list args = s8_Stack;

		for (int i=0; i<s32_ArgCount; i++, pk_Args++)
		{
			switch (pk_Args->vt)
			{
			case VT_I1:   *((CHAR*)        args) = pk_Args->cVal;    va_arg(args, CHAR);         break;
			case VT_I2:   *((SHORT*)       args) = pk_Args->iVal;    va_arg(args, SHORT);        break;
			case VT_I4:   *((LONG*)        args) = pk_Args->lVal;    va_arg(args, LONG);         break;
			case VT_I8:   *((LONGLONG*)    args) = pk_Args->llVal;   va_arg(args, LONGLONG);     break;
			case VT_UI1:  *((BYTE*)        args) = pk_Args->bVal;    va_arg(args, BYTE);         break;
			case VT_UI2:  *((USHORT*)      args) = pk_Args->uiVal;   va_arg(args, USHORT);       break;
			case VT_UI4:  *((ULONG*)       args) = pk_Args->ulVal;   va_arg(args, ULONG);        break;
			case VT_UI8:  *((ULONGLONG*)   args) = pk_Args->ullVal;  va_arg(args, ULONGLONG);    break;
			case VT_R4:   *((FLOAT*)       args) = pk_Args->fltVal;  va_arg(args, FLOAT);        break;
			case VT_R8:   *((DOUBLE*)      args) = pk_Args->dblVal;  va_arg(args, DOUBLE);       break;
			case VT_BOOL: *((VARIANT_BOOL*)args) = pk_Args->boolVal; va_arg(args, VARIANT_BOOL); break;
			case VT_BSTR: *((BSTR*)        args) = pk_Args->bstrVal; va_arg(args, BSTR);         break;
			case VT_INT:  *((INT*)         args) = pk_Args->intVal;  va_arg(args, INT);          break;
			case VT_UINT: *((UINT*)        args) = pk_Args->uintVal; va_arg(args, UINT);         break;
			default: throw "Invalid parameter!";
			}
		}

		while (true)
		{
			int s32_Len = _vsnwprintf(mu16_Buf, mu32_Size, u16_Format, s8_Stack);
			if (s32_Len >= 0)
				break;

			mu16_Buf[0] = 0;
			Allocate(mu32_Size * 2); // s32_Len = -1 -> Buffer too small, try again
		}
		delete s8_Stack;
	}

#endif

	void Format(const WCHAR* u16_Format, ...)
	{
		va_list  args;
		va_start(args, u16_Format);
		while (true)
		{
			int s32_Len = _vsnwprintf(mu16_Buf, mu32_Size, u16_Format, args);
			if (s32_Len >= 0)
				break;

			mu16_Buf[0] = 0;
			Allocate(mu32_Size * 2); // s32_Len = -1 -> Buffer too small, try again
		}
	}
	
	// Copy string content to external buffer 
	// s32_BufSize in BYTES !!!
	BOOL SafeExport(WCHAR* u16_Buffer, UINT u32_BufSize)
	{
		if (u32_BufSize < Len()*2+2)
			return FALSE;
			
		wcscpy(u16_Buffer, mu16_Buf);
		return TRUE;
	}


	// ************** UTF8 DECODER ***************

	// Convert an UTF8 string into an Unicode string and stores it in "this"
	WCHAR* DecodeUtf8(const char* s8_Utf)
	{
		// UTF8: One Unicode character is converted into 1,2,3 or 4 ASCII characters
		mu16_Buf[0] = 0;		
		Allocate((UINT)strlen(s8_Utf));

		int s32_Len = MultiByteToWideChar(CP_UTF8, 0, s8_Utf, -1, mu16_Buf, mu32_Size);

		mu16_Buf[s32_Len] = 0;
		return mu16_Buf;
	}

	// ************** Resource ***************

	// used for FindResourceW()
	WCHAR* FormatResource(UINT u32_Resource)
	{
		Format(L"#%d", u32_Resource);
		return mu16_Buf;
	}

	// **************** STATIC ******************

	// Characters 0000 until 007F --> pure ASCII (no conversion required)
	// Characters 0080 until 00FF --> ANSI characters (e.g. áéíóúñßöäü)
	// Characters 0100 until FFFF --> Unicode

	// return TRUE if the string has NO characters above 0x7F
	BOOL IsAscii() const
	{
		for (int P=0; mu16_Buf[P]; P++)
		{
			if (mu16_Buf[P] > 0x7F)
				return FALSE;
		};
		return TRUE;
	}

	// return TRUE if the string has characters above 0xFF
	BOOL IsUnicode() const
	{
		for (int P=0; mu16_Buf[P]; P++)
		{
			if (mu16_Buf[P] > 0xFF)
				return TRUE;
		};
		return FALSE;
	}

}; // class


// A simple class to store any data of any length
class CMemory
{
private:
	BYTE* mu8_Mem;
	int  ms32_Size; // the allocated memory
	int  ms32_Len;  // the length of the data

public:
	CMemory()
	{
		 mu8_Mem  = 0;
		ms32_Size = 0;
		ms32_Len  = 0;
	}

	~CMemory()
	{
		Free();
	}

	void Free()
	{
		if (mu8_Mem) delete[] mu8_Mem;
		mu8_Mem = 0;
	}

	void Allocate(int s32_Size)
	{
		if (s32_Size > ms32_Size)
		{
			if (mu8_Mem) delete[] mu8_Mem;

			// This line will throw an exception if Windows is out of memory
			mu8_Mem = new BYTE[s32_Size + 2];
			if (!mu8_Mem) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions

			ms32_Size = s32_Size;
		}
		ms32_Len = 0;
	}

	// return the data
	BYTE* GetData(int* ps32_Len)
	{
		// If the file contains an Ascii or Unicode text file it can directly be copied into a string
		mu8_Mem[ms32_Len]   = 0;
		mu8_Mem[ms32_Len+1] = 0;

		*ps32_Len = ms32_Len;
		return mu8_Mem;
	}

	// return FALSE if the buffer is too small
	BOOL Append(BYTE* u8_Data, int s32_Len)
	{
		if (ms32_Len + s32_Len > ms32_Size)
			return FALSE;

		memcpy(mu8_Mem + ms32_Len, u8_Data, s32_Len);
		ms32_Len += s32_Len;
		return TRUE;
	}

}; // class

} // Namespace Cabinet

