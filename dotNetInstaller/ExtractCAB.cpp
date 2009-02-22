#include "StdAfx.h"
#include "ExtractCAB.h"

#include "ConfigFile.h"
#include "Tools/Cab/ExtractResourceT.hpp"
#include "Tools/Cab/CompressT.hpp"
#include "Tools/Guid.h"
#include "Tools/Cab/ExtractT.hpp"
#include "InstallComponentDlg.h"

ExtractCABProcessor::ExtractCABProcessor(ExtractCABComponent * pComponent)
    : m_pComponent(pComponent)
{

}

BOOL ExtractCABProcessor::OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param)
{
    if (m_pComponent != NULL)
    {
        if (m_pComponent->m_pDialog != NULL)
        {
            m_pComponent->m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
                (WPARAM) InstallStatusParam::CreateStatus(k_FI.u16_File, 
                    DVLib::FormatNumberToBytes(k_FI.s32_Size)));
        }

        if (m_pComponent->cancelled)
        {
            CString cancelled_message = m_pComponent->m_Settings.cab_cancelled_message;
            if (cancelled_message.Trim().GetLength() == 0) cancelled_message = L"Cancelled by user";
            throw std::exception(DVLib::Tstring2string((LPCWSTR) cancelled_message).c_str());
        }
    }

    return Cabinet::CExtractT<ExtractCABProcessor>::OnBeforeCopyFile(k_FI, p_Param);
}

UINT ExtractCABComponent::ExecOnThread()
{
    ExtractCab(AfxGetApp()->m_hInstance, this);
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
	resname.append(DVLib::FormatNumber(currentIndex));
	
	HRSRC l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
	if (l_res == NULL)
		return 0;

	do
	{
		currentIndex++;
		resname = TEXT("RES_CAB");
		resname.append(DVLib::FormatNumber(currentIndex));
		l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
	} while(l_res);

	return currentIndex - 1;
}

void ExtractCABComponent::ExtractCab(HMODULE p_Module, Component * pComponent)
{
	ULONG currentIndex = 1;

	std::wstring resname = TEXT("RES_CAB");
	resname.append(DVLib::FormatNumber(currentIndex));
    ApplicationLog.Write( TEXT("Extracting Setup.cab") );

    CString cabpath = (m_Settings.cab_path.GetLength() > 0) ? m_Settings.cab_path : DVLib::GetSessionTempPath();
    cabpath = m_Settings.ValidatePath(cabpath);
	ApplicationLog.Write( TEXT("Cabpath is: "), cabpath );

    if (! DVLib::FileExistsCustom(cabpath))
    {
	    if (! ::CreateDirectory(cabpath, NULL))
        {
            throw std::exception("Failed to create CABPATH directory");
        }
    }

    CString tempFile = DVLib::PathCombineCustom(cabpath, TEXT("setup.cab") );
	ApplicationLog.Write( TEXT("TempFile is: "), tempFile );
    HANDLE l_hFile = CreateFile(tempFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (l_hFile == INVALID_HANDLE_VALUE)
    {
	    throw std::exception("Failed to create temp file");
    }

	int cabCount = GetCabCount(p_Module);

	for(int i = 1; i <= cabCount; i++)
	{
        if (m_pDialog != NULL)
        {
            CString percent;
            percent.Format(L"%d%%", (i * 100) / cabCount);
            m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
                (WPARAM) InstallStatusParam::CreateStatus(L"Setup.cab", percent));
        }

		std::wstring resname = TEXT("RES_CAB");
		resname.append(DVLib::FormatNumber(i));
		ApplicationLog.Write( TEXT("Extracting: "), resname.c_str() );

		HRSRC l_res = FindResource(p_Module, resname.c_str(), TEXT("BINARY"));
		if (l_res == NULL)
		{
			throw std::exception("Missing RES_CAB resource");
		}

        if (cancelled)
        {
            CString cancelled_message = m_Settings.cab_cancelled_message;
            if (cancelled_message.Trim().GetLength() == 0) cancelled_message = L"Cancelled by user";
            throw std::exception(DVLib::Tstring2string((LPCWSTR) cancelled_message).c_str());
        }

		HGLOBAL l_hRes = LoadResource(p_Module, l_res);
		if (l_hRes == NULL)
		{
			throw std::exception("Failed to load resource RES_CAB");
		}

		LPVOID l_buffer = LockResource(l_hRes);
		if (l_buffer == NULL)
		{
			throw std::exception("Failed to lock resource RES_CAB");
		}

		DWORD l_size = SizeofResource(p_Module, l_res);
		DWORD dwWritten = 0;

        if (! WriteFile(l_hFile, (char *) l_buffer, l_size, & dwWritten, NULL))
        {
            CloseHandle(l_hFile);
            UnlockResource(l_buffer);
            throw std::exception("Failed to write setup.cab");
        }

		UnlockResource(l_buffer);
    }

    CloseHandle(l_hFile);

    ExtractCABProcessor i_Extract(this);
    if (!i_Extract.CreateFDIContext()) 
    {
        throw std::exception("Failed to initialize CAB context");
    }

    if (!i_Extract.ExtractFileW(tempFile.GetBuffer(), cabpath.GetBuffer()))
    {
        throw std::exception("Error extracting files from setup.cab");
    }
}
