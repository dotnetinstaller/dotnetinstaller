#pragma once

#include "ConfigFile.h"
#include "Tools/Cab/ExtractResourceT.hpp"
#include "Tools/Cab/CompressT.hpp"
#include "Tools/Guid.h"

struct ExtractCABComponent : public thread_component
{
public:

	virtual bool Exec()
	{
        ExtractCab(AfxGetApp()->m_hInstance);
        return true;
	};

    ExtractCABComponent(installerSetting& settings)
        : m_Settings(settings)
    {

    }

private:

    installerSetting& m_Settings;

    void ExtractCab(HMODULE p_Module)
    {
	    HRSRC l_res = FindResource(p_Module, TEXT("RES_CAB"), TEXT("CUSTOM"));
	    if (l_res == NULL)
		    return;

	    ApplicationLog.Write( TEXT("Extracting setup.cab ...") );

	    HGLOBAL l_hRes = LoadResource(p_Module, l_res);
	    if (l_hRes == NULL)
		    throw TEXT("Failed to load resource RES_CAB.");
	    LPVOID l_buffer = LockResource(l_hRes);
	    if (l_buffer == NULL)
		    throw TEXT("Failed to lock resource RES_CAB.");
	    DWORD l_size = SizeofResource(p_Module, l_res);

        CString cabpath = (m_Settings.cab_path.GetLength() > 0) ? m_Settings.cab_path : DVLib::GetSessionTempPath();
        cabpath = m_Settings.ValidatePath(cabpath);
		ApplicationLog.Write( TEXT("cabpath is: "), cabpath );

        CString tempFile = DVLib::PathCombineCustom(cabpath, TEXT("setup.cab") );

		ApplicationLog.Write( TEXT("tempFile is: "), tempFile );
	    HANDLE l_hFile = CreateFile(tempFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	    if (l_hFile == INVALID_HANDLE_VALUE)
		    throw TEXT("Failed to create temp file");

        DWORD dwWritten = 0;
        if (! WriteFile(l_hFile, l_buffer, l_size, & dwWritten, NULL))
            throw TEXT("Failed to write setup.cab");

        UnlockResource(l_buffer);
        CloseHandle(l_hRes);
        CloseHandle(l_hFile);

        Cabinet::CExtract i_Extract;
        if (!i_Extract.CreateFDIContext()) 
            throw TEXT("Failed to initialize CAB context");

        if (!i_Extract.ExtractFileW(tempFile.GetBuffer(), cabpath.GetBuffer()))
            throw TEXT("Error extracting files from setup.cab");
    }
};


