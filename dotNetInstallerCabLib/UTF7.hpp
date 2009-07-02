///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://kickme.to/elmue)
// Date: 2-12-2007
//
// Filename: UTF7.hpp
//
// Classes:
// - CUtf7
//
// Purpose: This tiny class encodes Unicode to UTF7 and decodes UTF7 to Unicode
// All characters above FIRST_UNI are represented by 16 Bit in a stream of ASCII characters 
// of which each represents 6 Bits (approx 3 ASCII characters per Unicode character)
// An UTF7 sequence starts with "<" and ends with ">"
// Example: 
// "test<sgS>test" represents the Unicode string "test?test" where "?" is a japanese Unicode character
//
// Noramally UTF7 uses '+' and '-' instead of '<' and '>' 
// But these characters are used here to avoid unnecessary encoding as they are not allowed in filenames.
// So a filename in a CAB file which contains a '<' character is surely a UTF filename
// With the '+' character it would not be possible to distinguish an ASCII filename from an UTF filename
//
// Normally UTF encodes character above 127.
// This encoder starts encoding above 255 to let pass characters like german umlauts which are 
// between 128 and 255 and must not be encoded as they are valid in filenames even on Windows 95.
//
// ---------------------------------------------------------------------
// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
//
// If you need to encode/decode multiple strings at the same time 
// you MUST create a new CUtf7 instance for EACH string 
// 
// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
// ---------------------------------------------------------------------

#pragma once

#define CHAR_OPEN  '<'
#define CHAR_CLOSE '>'

#define FIRST_UNI  256

namespace Cabinet
{

class CUtf7
{
private:
	char*   ms8_Base64Chr;
	char*   ms8_Base64Val;
	char*   ms8_EncBuf;
	WCHAR* mu16_DecBuf;

public:

	CUtf7()
	{
		static char     s8_Base64Val[FIRST_UNI] = "";
		ms8_Base64Val = s8_Base64Val;
		ms8_Base64Chr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		
		if (!s8_Base64Val[0]) // initialize static variable only once
		{
			for (int i=0; i<FIRST_UNI; i++)
			{
				s8_Base64Val[i] = -1;
			}

			for (int j=0; j<0x40; j++)
			{
				s8_Base64Val[(byte)ms8_Base64Chr[j]] = (char)j;
			}
		}

		 ms8_EncBuf = 0;
		mu16_DecBuf = 0;
	}

	~CUtf7()
	{
		if ( ms8_EncBuf) delete  ms8_EncBuf;
		if (mu16_DecBuf) delete mu16_DecBuf;
	}

	char* Encoded()
	{
		return ms8_EncBuf;
	}

	WCHAR* Decoded()
	{
		return mu16_DecBuf;
	}

	// **************** ENCODER ******************

	// Convert a Unicode string into a UTF7 string
	char* Encode(WCHAR* u16_In)
	{
		if (u16_In == 0)
			return 0;

		size_t Len = wcslen(u16_In);

		if (ms8_EncBuf) delete ms8_EncBuf;
		ms8_EncBuf = new char[Len*5+1]; // never zero!

		int Ptr      = 0;
		int bits     = 0;
		int bitCount = -1;

		for (UINT i=0; i<Len; i++)
		{
			WCHAR u16_Chr = u16_In[i];

			if (u16_Chr < FIRST_UNI)
			{
				if (bitCount >= 0)
				{
					if (bitCount > 0)
					{
						ms8_EncBuf[Ptr++] = ms8_Base64Chr[(bits << (6 - bitCount)) & 0x3f];
					}
					ms8_EncBuf[Ptr++] = CHAR_CLOSE;
					bitCount = -1;
				}
				ms8_EncBuf[Ptr++] = (byte) u16_Chr;
			}
			else if (bitCount < 0 && u16_Chr == CHAR_OPEN)
			{
				ms8_EncBuf[Ptr++] = CHAR_OPEN;
				ms8_EncBuf[Ptr++] = CHAR_CLOSE;
			}
			else
			{
				if (bitCount < 0)
				{
					ms8_EncBuf[Ptr++] = CHAR_OPEN;
					bitCount = 0;
				}
				bits = (bits << 16) | u16_Chr;
				bitCount += 16;
				while (bitCount >= 6)
				{
					bitCount -= 6;
					ms8_EncBuf[Ptr++] = ms8_Base64Chr[(bits >> bitCount) & 0x3f];
				}
			}
		}

		if (bitCount >= 0)
		{
			if (bitCount > 0)
			{
				ms8_EncBuf[Ptr++] = ms8_Base64Chr[(bits << (6 - bitCount)) & 0x3f];
			}
			ms8_EncBuf[Ptr++] = CHAR_CLOSE;
		}

		ms8_EncBuf[Ptr] = 0;
		return ms8_EncBuf;
	}

	// **************** DECODER ******************

	// Convert a UTF7 string into a Unicode string
	WCHAR* Decode(char* s8_In)
	{
		if (s8_In == 0)
			return 0;

		int  Ptr       = 0;
		int  bits      = 0;
		int  bitCount  = -1;
		BOOL firstByte = FALSE;
		size_t Len       = strlen(s8_In);

		if (mu16_DecBuf) delete mu16_DecBuf;
		mu16_DecBuf = new WCHAR[Len+10]; // never zero!

		for (UINT i=0; i<Len; i++)
		{
			byte Chr = (byte) s8_In[i];
			int NextChar = -1;
			if (bitCount >= 0)
			{
				if (Chr >= FIRST_UNI)
				{
					NextChar = Chr;
					bitCount = -1;
				}
				else
				{
					char Val = ms8_Base64Val[Chr];
					if  (Val >= 0)
					{
						firstByte = FALSE;
						bits = (bits << 6) | ((byte) Val);
						bitCount += 6;
						if (bitCount >= 16)
						{
							NextChar = (bits >> (bitCount - 16)) & 0xffff;
							bitCount -= 16;
						}
					}
					else
					{
						if (Chr == CHAR_CLOSE)
						{
							if (firstByte)
							{
								NextChar = CHAR_OPEN;
							}
						}
						else
						{
							NextChar = Chr;
						}
						bitCount = -1;
					}
				}
			}
			else if (Chr == CHAR_OPEN)
			{
				bitCount  = 0;
				firstByte = TRUE;
			}
			else
			{
				NextChar = Chr;
			}

			if (NextChar >= 0)
			{
				mu16_DecBuf[Ptr++] = (WCHAR) NextChar;
			}
		}

		mu16_DecBuf[Ptr] = 0;
		return mu16_DecBuf;
	}

	// return TRUE if the string is UTF encoded
	static BOOL IsUtf(char* s8_In)
	{
		if (s8_In == 0)
			return FALSE;

		return (strchr(s8_In, CHAR_OPEN) > 0);
	}

	// return FALSE on Windows 95,98,ME otherwise TRUE
	static BOOL IsNtPlatform()
	{
		static int s32_Platform = -1;
		if (s32_Platform == -1)
		{
			OSVERSIONINFO k_Ver;
			k_Ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

			GetVersionEx (&k_Ver);
			s32_Platform = k_Ver.dwPlatformId;
		}

		return (s32_Platform == VER_PLATFORM_WIN32_NT);
	}

}; // class

} // Namespace Cabinet
