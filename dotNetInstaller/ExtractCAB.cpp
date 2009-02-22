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
            throw _wcsdup((LPCWSTR) cancelled_message);
        }
    }

    return Cabinet::CExtractT<ExtractCABProcessor>::OnBeforeCopyFile(k_FI, p_Param);
}

UINT ExtractCABComponent::ExecOnThread()
{
    ExtractCab(AfxGetApp()->m_hInstance, this);
    return ERROR_SUCCESS;
};

ExtractCABComponent::ExtractCABComponent(installerSetting& settings)
    : m_Settings(settings)
{

}

void ExtractCABComponent::ExtractCab(HMODULE p_Module, component * pComponent)
{
    HRSRC l_res = FindResource(p_Module, TEXT("RES_CAB"), TEXT("CUSTOM"));
    if (l_res == NULL)
	    return;

    ApplicationLog.Write( TEXT("Extracting Setup.cab") );

    HGLOBAL l_hRes = LoadResource(p_Module, l_res);
    if (l_hRes == NULL)
    {
	    throw TEXT("Failed to load resource RES_CAB");
    }

    LPVOID l_buffer = LockResource(l_hRes);
    if (l_buffer == NULL)
    {
        CloseHandle(l_hRes);
	    throw TEXT("Failed to lock resource RES_CAB");
    }

    DWORD l_size = SizeofResource(p_Module, l_res);

    CString cabpath = (m_Settings.cab_path.GetLength() > 0) ? m_Settings.cab_path : DVLib::GetSessionTempPath();
    cabpath = m_Settings.ValidatePath(cabpath);
	ApplicationLog.Write( TEXT("Cabpath is: "), cabpath );

    if (! DVLib::FileExistsCustom(cabpath))
    {
	    if (! ::CreateDirectory(cabpath, NULL))
        {
            UnlockResource(l_buffer);
            CloseHandle(l_hRes);
            throw TEXT("Failed to create CABPATH directory");
        }
    }

    CString tempFile = DVLib::PathCombineCustom(cabpath, TEXT("setup.cab") );

	ApplicationLog.Write( TEXT("TempFile is: "), tempFile );
    HANDLE l_hFile = CreateFile(tempFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (l_hFile == INVALID_HANDLE_VALUE)
    {
	    throw TEXT("Failed to create temp file");
    }

    long l_current = 0;
    long l_chunk = l_size / 10;
    if (l_chunk == 0) l_chunk = l_size;
    while (l_current < l_size)
    {
        if (cancelled)
        {
            CString cancelled_message = m_Settings.cab_cancelled_message;
            if (cancelled_message.Trim().GetLength() == 0) cancelled_message = L"Cancelled by user";
            throw _wcsdup((LPCWSTR) cancelled_message);
        }

        DWORD dwWritten = 0;
        l_chunk = min(l_chunk, l_size - l_current);
        if (! WriteFile(l_hFile, (char *) l_buffer + l_current, l_chunk, & dwWritten, NULL))
        {
            CloseHandle(l_hFile);
            UnlockResource(l_buffer);
            CloseHandle(l_hRes);
            throw TEXT("Failed to write setup.cab");
        }

        l_current += l_chunk;

        if (m_pDialog != NULL)
        {
            CString percent;
            percent.Format(L"%d%%", l_current / (l_size / 100));
            m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
                (WPARAM) InstallStatusParam::CreateStatus(L"Setup.cab", percent));
        }
    }

    CloseHandle(l_hFile);
    UnlockResource(l_buffer);

    ExtractCABProcessor i_Extract(this);
    if (!i_Extract.CreateFDIContext()) 
    {
        throw TEXT("Failed to initialize CAB context");
    }

    if (!i_Extract.ExtractFileW(tempFile.GetBuffer(), cabpath.GetBuffer()))
    {
        throw TEXT("Error extracting files from setup.cab");
    }
}


