#include "StdAfx.h"
#include "ExtractComponent.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ExtractComponent::ExtractComponent(HMODULE h)
	: m_h(h)
	, cancelled(false)
{

}


int ExtractComponent::ExecOnThread()
{
	ResolvePaths();
	WriteCab();
    ExtractCab();
	LOG(L"ExtractComponent: extracted Setup.cab");
	return 0;
}

int ExtractComponent::GetCabCount() const
{
	int currentIndex = 1;	
	std::wstring resname = TEXT("SETUP_");
	resname.append(DVLib::towstring(currentIndex));
	
	HRSRC l_res = FindResource(m_h, resname.c_str(), TEXT("RES_CAB"));
	if (l_res == NULL)
		return 0;

	do
	{
		currentIndex++;
		resname = TEXT("SETUP_");
		resname.append(DVLib::towstring(currentIndex));
		l_res = FindResource(m_h, resname.c_str(), TEXT("RES_CAB"));
	} while(l_res);

	return currentIndex - 1;
}

void ExtractComponent::ResolvePaths()
{
    LOG(L"Extracting CABs");

	resolved_cab_path = cab_path.empty() ? InstallerSession::Instance->GetSessionTempPath() : cab_path; 
	resolved_cab_path = InstallerSession::Instance->ExpandVariables(resolved_cab_path);
	LOG(L"Cabpath: " << resolved_cab_path);
	DVLib::DirectoryCreate(resolved_cab_path);
}

void ExtractComponent::WriteCab()
{
	int cabCount = GetCabCount();
	DWORD dwWrittenTotal = 0;

	for (int i = 1; i <= cabCount; i++)
	{
		std::wstring resname = TEXT("SETUP_");
		resname.append(DVLib::towstring(i));

        if (cancelled)
        {
			LOG(L"Cancelled: " << resname);
            std::wstring resolved_cancelled_message = cab_cancelled_message;
            if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
			THROW_EX(resolved_cancelled_message);
        }

		std::wstring resolved_cab_file = DVLib::DirectoryCombine(resolved_cab_path, resname + L".CAB");
		LOG(L"Extracting: " << resolved_cab_file);

		auto_hfile hfile(CreateFile(resolved_cab_file.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, 
			OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

		CHECK_WIN32_BOOL(get(hfile) != INVALID_HANDLE_VALUE,
			L"Error creating '" << resolved_cab_file << L"'");

		OnStatus(L"Setup.cab - " + DVLib::FormatMessage(L"%d%%", (i * 100) / cabCount));

		std::vector<char> data = DVLib::LoadResourceData<char>(m_h, resname, L"RES_CAB");

		DWORD dwWritten = 0;
        CHECK_WIN32_BOOL(WriteFile(get(hfile), (LPCVOID) & * data.begin(), data.size(), & dwWritten, NULL),
			L"Error writing '" << resname << L".CAB'");

		dwWrittenTotal += dwWritten;
		LOG(L"Extracted: " << resname);
    }

	LOG(L"Extracted " << DVLib::FormatBytesW(dwWrittenTotal) << L" from " << cabCount << L" resource segment(s)");
}

void ExtractComponent::ExtractCab()
{
	Cabinet::CExtract extract;
	Cabinet::CExtract::kCallbacks callbacks;
	callbacks.f_OnBeforeCopyFile = & ExtractComponent::OnBeforeCopyFile; 
	callbacks.f_OnAfterCopyFile = & ExtractComponent::OnAfterCopyFile;
	extract.SetCallbacks(& callbacks);

	std::wstring resolved_cab_file = DVLib::DirectoryCombine(resolved_cab_path, TEXT("SETUP_1.CAB"));
	LOG(L"Cabfile: " << resolved_cab_file);

	CHECK_BOOL(extract.CreateFDIContext(),
		L"Error initializing cabinet.dll: " << extract.LastErrorW());

	CHECK_BOOL(extract.ExtractFileW(Cabinet::CStrW(resolved_cab_file.c_str()), Cabinet::CStrW(resolved_cab_path.c_str()), this), 
		L"Error extracting '" << resolved_cab_file << L"': " << extract.LastErrorW());

	LOG(L"Extracted CAB: " << resolved_cab_file);
}

void ExtractComponent::OnAfterCopyFile(wchar_t * s8_File, Cabinet::CMemory *, void* /*p_Param*/)
{
	LOG(L"Done: " << s8_File);
}

BOOL ExtractComponent::OnBeforeCopyFile(Cabinet::CExtract::kCabinetFileInfo * k_FI, void* p_Param)
{
	LOG(L"Extracting: " << k_FI->u16_FullPath);

	ExtractComponent * extractComponent = (ExtractComponent *) p_Param;

	extractComponent->OnStatus(std::wstring(k_FI->u16_File) + L" - " + DVLib::FormatBytesW(k_FI->s32_Size));

	std::wstring cancelled_message;
	if (extractComponent->cancelled)
    {
        std::wstring resolved_cancelled_message = extractComponent->cab_cancelled_message;
        if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
        THROW_EX(resolved_cancelled_message);
    }

	return TRUE;
}

std::vector<std::wstring> ExtractComponent::GetCabFiles() const
{
	std::vector<wchar_t> v_buffer = DVLib::LoadResourceData<wchar_t>(m_h, L"RES_CAB_LIST", L"CUSTOM");
	std::wstring s_buffer(& * v_buffer.begin(), v_buffer.size());
	return DVLib::split(s_buffer, L"\r\n");
}
