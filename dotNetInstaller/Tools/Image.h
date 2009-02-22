#pragma once

#include "Path.h"

namespace DVLib
{
	inline HBITMAP LoadBitmapFromFile(LPCTSTR p_File)
	{
		HBITMAP l_hBitmap = (HBITMAP)(::LoadImage(NULL,  p_File,
											IMAGE_BITMAP,
											0, 0,
											LR_LOADFROMFILE |
											LR_CREATEDIBSECTION |
											LR_DEFAULTSIZE |
											LR_VGACOLOR));

		if (l_hBitmap == NULL)
			throw -1;

		return l_hBitmap;
	}

	//Load a bitmap from a stream.
	// I can't use CImage or GDI+ functions because are not supported on operating system prior to WinXp
	inline HBITMAP LoadBitmapFromBuffer(void * p_Buffer, DWORD p_BufferLength)
	{
		//creao un file temporaneo
		CString l_TempFile = GetTempFullFileName();
		HANDLE l_hFile = CreateFile(l_TempFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (l_hFile == INVALID_HANDLE_VALUE)
			throw -1;

		DWORD l_BytesWritten = 0;
		if (WriteFile(l_hFile, p_Buffer, p_BufferLength, &l_BytesWritten, NULL) == FALSE)
			throw -1;

		if (l_BytesWritten != p_BufferLength)
			throw -1;

		CloseHandle(l_hFile);

		HBITMAP l_hBitmap = LoadBitmapFromFile(l_TempFile);

		DeleteFile(l_TempFile);

		return l_hBitmap;
	}
}