#include "StdAfx.h"
#include "ExtractComponent.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ExtractComponent::ExtractComponent(HMODULE h)
    : ThreadComponent(undefined)
	, m_h(h)
{

}


UINT ExtractComponent::ExecOnThread()
{
    ExtractCab();
	LOG(L"ExtractComponent: extracted Setup.cab");
    return ERROR_SUCCESS;
};

int ExtractComponent::GetCabCount() const
{
	int currentIndex = 1;	
	std::wstring resname = TEXT("RES_CAB");
	resname.append(DVLib::towstring(currentIndex));
	
	HRSRC l_res = FindResource(m_h, resname.c_str(), TEXT("BINARY"));
	if (l_res == NULL)
		return 0;

	do
	{
		currentIndex++;
		resname = TEXT("RES_CAB");
		resname.append(DVLib::towstring(currentIndex));
		l_res = FindResource(m_h, resname.c_str(), TEXT("BINARY"));
	} while(l_res);

	return currentIndex - 1;
}

void ExtractComponent::ExtractCab()
{
	ULONG currentIndex = 1;

	std::wstring resname = TEXT("RES_CAB");
	resname.append(DVLib::towstring(currentIndex));
    LOG(L"Extracting Setup.cab");

	std::wstring resolved_cab_path = cab_path.empty() ? InstallerSession::GetSessionTempPath() : cab_path; 
	resolved_cab_path = InstallerSession::MakePath(resolved_cab_path);
	LOG(L"Cabpath: " << resolved_cab_path);
	DVLib::DirectoryCreate(resolved_cab_path);

    std::wstring tempFile = DVLib::DirectoryCombine(resolved_cab_path, TEXT("setup.cab") );
	LOG(L"TempFile: " << tempFile);

	auto_hfile hfile(CreateFile(tempFile.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	CHECK_WIN32_BOOL(get(hfile) != INVALID_HANDLE_VALUE,
		L"Error creating '" << tempFile << L"'");

	int cabCount = GetCabCount();

	for (int i = 1; i <= cabCount; i++)
	{
		OnStatus(L"Setup.cab - " + DVLib::FormatMessage(L"%d%%", (i * 100) / cabCount));

		std::wstring resname = TEXT("RES_CAB");
		resname.append(DVLib::towstring(i));
		LOG(L"Extracting: " << resname);

		HRSRC l_res = FindResource(m_h, resname.c_str(), TEXT("BINARY"));
		if (l_res == NULL)
		{
			LOG(L"Missing " << resname << L" resource");
			THROW_EX(L"Missing " << resname << L" resource");
		}

        if (cancelled)
        {
			LOG(L"Cancelled: " << resname);
            std::wstring resolved_cancelled_message = cab_cancelled_message;
            if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
			THROW_EX(resolved_cancelled_message);
        }

		HGLOBAL l_hRes = LoadResource(m_h, l_res);
		if (l_hRes == NULL)
		{
			LOG(L"Error loading resource: " << resname);
			THROW_EX("Error loading resource: " << resname);
		}

		LPVOID l_buffer = LockResource(l_hRes);
		if (l_buffer == NULL)
		{
			LOG(L"Failed to lock resource: " << resname);
			THROW_EX(L"Failed to lock resource: " << resname);
		}

		DWORD l_size = SizeofResource(m_h, l_res);
		DWORD dwWritten = 0;

        CHECK_WIN32_BOOL(WriteFile(get(hfile), (char *) l_buffer, l_size, & dwWritten, NULL),
			L"Error writing setup.cab at '" << resname << L"' resource");

		UnlockResource(l_buffer);
		LOG(L"Extracted: " << resname);
    }

	LOG(L"Extracted all resource segments");

	CHECK_BOOL(CreateFDIContext(),
		L"Error initializing CAB context");

	CHECK_BOOL(ExtractFileW(const_cast<wchar_t *>(tempFile.c_str()), const_cast<wchar_t *>(resolved_cab_path.c_str())),
		L"Error extracting '" << tempFile << L"'");

	LOG(L"Extracted CAB: " << tempFile);
}

void ExtractComponent::OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param)
{
	LOG(L"Done: " << u16_File);
    Cabinet::CExtractT<ExtractComponent>::OnAfterCopyFile(s8_File, u16_File, p_Param);
}

BOOL ExtractComponent::OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param)
{
	LOG(L"Extracting: " << k_FI.u16_FullPath);

	OnStatus(std::wstring(k_FI.u16_File) + L" - " + DVLib::FormatBytesW(k_FI.s32_Size));

	std::wstring cancelled_message;
	if (cancelled)
    {
        std::wstring resolved_cancelled_message = cab_cancelled_message;
        if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
        THROW_EX(resolved_cancelled_message);
    }

    return Cabinet::CExtractT<ExtractComponent>::OnBeforeCopyFile(k_FI, p_Param);
}
