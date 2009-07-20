#include "StdAfx.h"
#include "ExtractComponent.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ExtractComponent::ExtractComponent(HMODULE h)
    : ThreadComponent(undefined)
	, m_h(h)
{

}


void ExtractComponent::ExecOnThread()
{
    ExtractCab();
	LOG(L"ExtractComponent: extracted Setup.cab");
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

        if (cancelled)
        {
			LOG(L"Cancelled: " << resname);
            std::wstring resolved_cancelled_message = cab_cancelled_message;
            if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
			THROW_EX(resolved_cancelled_message);
        }

		std::vector<char> data = DVLib::LoadResourceData<char>(m_h, resname, L"BINARY");

		DWORD dwWritten = 0;
        CHECK_WIN32_BOOL(WriteFile(get(hfile), (LPCVOID) & * data.begin(), data.size(), & dwWritten, NULL),
			L"Error writing setup.cab at '" << resname << L"' resource");

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

std::vector<std::wstring> ExtractComponent::GetCabFiles() const
{
	std::vector<wchar_t> v_buffer = DVLib::LoadResourceData<wchar_t>(m_h, L"RES_CAB_LIST", L"CUSTOM");
	std::wstring s_buffer(& * v_buffer.begin(), v_buffer.size());
	return DVLib::split(s_buffer, L"\r\n");
}
