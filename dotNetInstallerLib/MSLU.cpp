#include "StdAfx.h"

static HMODULE SaveAndLoadMSLU()
{
	char tf[MAX_PATH] = { 0 };
	if (! GetTempPathA(MAX_PATH, tf)) 
		return NULL;

	if (0 != strcat_s<>(tf, "unicows.dll"))
		return NULL;

	if (GetFileAttributesA(tf) == INVALID_FILE_ATTRIBUTES)
	{
		HRSRC res_unicows = ::FindResourceA(NULL, "RES_UNICOWS", "CUSTOM");
		if (res_unicows == NULL) 
			return NULL;

		HGLOBAL hgl = ::LoadResource(NULL, res_unicows);
		if (hgl == NULL) 
			return NULL;

		DWORD size = SizeofResource(NULL, res_unicows);
		if (size == 0) 
			return NULL;

		LPVOID buffer = LockResource(hgl);
		
		auto_hfile h(CreateFileA(tf, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, 
			OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

		if (get(h) == INVALID_HANDLE_VALUE)
			return NULL;

		DWORD written = 0;
		if (! WriteFile(get(h), buffer, size, & written, NULL))
			return NULL;
	}

	return ::LoadLibraryA(tf);
}

static HMODULE __stdcall LoadMSLU()
{
    HMODULE hUnicows = ::LoadLibraryA("unicows.dll");
	if (hUnicows == 0) hUnicows = SaveAndLoadMSLU();
    if (hUnicows == 0)
    {
		MessageBoxA(0, "Error loading unicows.dll (Microsoft Layer for Unicode, MSLU)", 
			"dotNetInstaller", MB_ICONSTOP | MB_OK);
		_exit(-1);
    }
    return hUnicows;
}

// load Microsoft Layer for Unicode (MSLU)
// http://msdn.microsoft.com/en-us/magazine/cc301794.aspx
extern "C" HMODULE (__stdcall *_PfnLoadUnicows) (void) = & LoadMSLU;
