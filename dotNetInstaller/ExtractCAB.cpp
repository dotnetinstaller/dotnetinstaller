#include "StdAfx.h"
#include "ExtractCAB.h"
#include "ConfigFile.h"
#include "InstallComponentDlg.h"
#include "Resource.h"

ExtractCABProcessor::ExtractCABProcessor(ExtractCABComponent * pComponent)
    : m_pComponent(pComponent)
{

}

void ExtractCABProcessor::OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param)
{
	ApplicationLog.Write( TEXT("Done: "), u16_File );
    Cabinet::CExtractT<ExtractCABProcessor>::OnAfterCopyFile(s8_File, u16_File, p_Param);
}

BOOL ExtractCABProcessor::OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param)
{
	ApplicationLog.Write( TEXT("Extracting: "), k_FI.u16_FullPath );

    if (m_pComponent != NULL)
    {
        if (m_pComponent->m_pDialog != NULL)
        {
            m_pComponent->m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
                (WPARAM) InstallStatusParam::CreateStatus(k_FI.u16_File, 
                    DVLib::FormatBytesW(k_FI.s32_Size).c_str()));
        }

        if (m_pComponent->cancelled)
        {
            std::wstring cancelled_message = m_pComponent->m_Settings.cab_cancelled_message;
            if (cancelled_message.empty()) cancelled_message = L"Cancelled by user";
            THROW_EX(cancelled_message);
        }
    }

    return Cabinet::CExtractT<ExtractCABProcessor>::OnBeforeCopyFile(k_FI, p_Param);
}

UINT ExtractCABComponent::ExecOnThread()
{
    ExtractCab(AfxGetApp()->m_hInstance, this);
	ApplicationLog.Write( TEXT("ExtractCABComponent: extracted CAB") );
    return ERROR_SUCCESS;
};

ExtractCABComponent::ExtractCABComponent(InstallerSetting& settings)
    : m_Settings(settings)
{

}

int ExtractCABComponent::GetCabCount(HMODULE p_Module)
{
	int currentIndex = 1;	
	std::wstring resname = TEXT("RES_CAB");
	resname.append(DVLib::towstring(currentIndex));
	
	HRSRC l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
	if (l_res == NULL)
		return 0;

	do
	{
		currentIndex++;
		resname = TEXT("RES_CAB");
		resname.append(DVLib::towstring(currentIndex));
		l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
	} while(l_res);

	return currentIndex - 1;
}

void ExtractCABComponent::ExtractCab(HMODULE p_Module, Component * pComponent)
{
	ULONG currentIndex = 1;

	std::wstring resname = TEXT("RES_CAB");
	resname.append(DVLib::towstring(currentIndex));
    ApplicationLog.Write( TEXT("Extracting Setup.cab") );

	std::wstring cabpath = (! m_Settings.cab_path.empty()) ? m_Settings.cab_path : InstallerSetting::GetSessionTempPath();
    cabpath = m_Settings.ValidatePath(cabpath);
	ApplicationLog.Write( TEXT("Cabpath: "), cabpath );
	DVLib::DirectoryCreate(cabpath);

    std::wstring tempFile = DVLib::DirectoryCombine(cabpath, TEXT("setup.cab") );
	ApplicationLog.Write( TEXT("TempFile: "), tempFile );
    HANDLE l_hFile = CreateFile(tempFile.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (l_hFile == INVALID_HANDLE_VALUE)
    {
	    throw std::exception("Failed to create temp file");
    }

	int cabCount = GetCabCount(p_Module);

	for(int i = 1; i <= cabCount; i++)
	{
        if (m_pDialog != NULL)
        {
			std::wstring percent = DVLib::FormatMessage(L"%d%%", (i * 100) / cabCount);
            m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
                (WPARAM) InstallStatusParam::CreateStatus(L"Setup.cab", percent));
        }

		std::wstring resname = TEXT("RES_CAB");
		resname.append(DVLib::towstring(i));
		ApplicationLog.Write( TEXT("Extracting: "), resname.c_str() );

		HRSRC l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
		if (l_res == NULL)
		{
			ApplicationLog.Write( TEXT("Missing: "), resname.c_str() );
			throw std::exception("Missing RES_CAB resource");
		}

        if (cancelled)
        {
			ApplicationLog.Write( TEXT("Cancelled: "), resname.c_str() );
            std::wstring cancelled_message = m_Settings.cab_cancelled_message;
            if (cancelled_message.empty()) cancelled_message = L"Cancelled by user";
			THROW_EX(cancelled_message);
        }

		HGLOBAL l_hRes = LoadResource(p_Module, l_res);
		if (l_hRes == NULL)
		{
			ApplicationLog.Write( TEXT("Error loading resource: "), resname.c_str() );
			throw std::exception("Failed to load resource RES_CAB");
		}

		LPVOID l_buffer = LockResource(l_hRes);
		if (l_buffer == NULL)
		{
			ApplicationLog.Write( TEXT("Failed to lock resource: "), resname.c_str() );
			throw std::exception("Failed to lock resource RES_CAB");
		}

		DWORD l_size = SizeofResource(p_Module, l_res);
		DWORD dwWritten = 0;

        if (! WriteFile(l_hFile, (char *) l_buffer, l_size, & dwWritten, NULL))
        {
			ApplicationLog.Write( TEXT("Error writing file: "), resname.c_str() );
            CloseHandle(l_hFile);
            UnlockResource(l_buffer);
            throw std::exception("Failed to write setup.cab");
        }

		UnlockResource(l_buffer);
		ApplicationLog.Write( TEXT("Extracted: "), resname.c_str() );
    }

	ApplicationLog.Write( TEXT("Extracted all segments") );
    CloseHandle(l_hFile);

    ExtractCABProcessor i_Extract(this);
    if (!i_Extract.CreateFDIContext()) 
    {
		ApplicationLog.Write( TEXT("Failed to initialize CAB context") );
        throw std::exception("Failed to initialize CAB context");
    }

    if (!i_Extract.ExtractFileW(const_cast<wchar_t *>(tempFile.c_str()), const_cast<wchar_t *>(cabpath.c_str())))
    {
		ApplicationLog.Write( TEXT("Failed to extract file:"), tempFile );
        throw std::exception("Error extracting files from setup.cab");
    }

	ApplicationLog.Write( TEXT("Extracted CAB: "), tempFile );
}
