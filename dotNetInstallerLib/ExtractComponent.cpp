#include "StdAfx.h"
#include "ExtractComponent.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ExtractComponent::ExtractComponent(HMODULE h, const std::wstring& id)
: m_h(h)
, cancelled(false)
, component_id(GetNormalizedId(id))
, status_interval(1000)
{

}


int ExtractComponent::ExecOnThread()
{
    ResolvePaths();
    switch(GetCabCount())
    {
    case 0:
        break;
    default:
        ExtractFromResource();
        break;
    }
    return 0;
}

int ExtractComponent::GetCabCount() const
{
    int currentIndex = 1;
    std::wstring resname = GetResName(currentIndex);

    HRSRC l_res = FindResource(m_h, resname.c_str(), TEXT("RES_CAB"));
    if (l_res == NULL)
        return 0;

    do
    {
        currentIndex++;
        resname = GetResName(currentIndex);
        l_res = FindResource(m_h, resname.c_str(), TEXT("RES_CAB"));
    } while(l_res);

    return currentIndex - 1;
}

void ExtractComponent::ResolvePaths()
{
    resolved_cab_path = cab_path.empty() ? InstallerSession::Instance->GetSessionCabPath() : cab_path; 
    resolved_cab_path = InstallerSession::Instance->ExpandVariables(resolved_cab_path);	
    LOG(L"Resolved CAB path '" << resolved_cab_path << L"' for component '" << (component_id.empty() ? L"*" : component_id) << L"'");
    DVLib::DirectoryCreate(resolved_cab_path);
}

void ExtractComponent::ExtractFromResource()
{
    std::wstring resname = GetResName(1);
    LOG(L"Extracting '" << resname << L"' for component '" << (component_id.empty() ? L"*" : component_id) << L"'");

    Cabinet::CExtractResource extract;
    Cabinet::CExtract::kCallbacks callbacks;
    callbacks.f_OnBeforeCopyFile = & ExtractComponent::OnBeforeCopyFile; 
    callbacks.f_OnAfterCopyFile = & ExtractComponent::OnAfterCopyFile;
    callbacks.f_OnProgressInfo = & ExtractComponent::OnProgressInfo;
    callbacks.s32_ProgressInterval = status_interval;
    extract.SetCallbacks(& callbacks);

    CHECK_BOOL(extract.CreateFDIContext(),
        L"Error initializing cabinet.dll: " << extract.LastErrorW());

    CHECK_BOOL(extract.ExtractResourceW(L"", Cabinet::CStrW(resname.c_str()), L"RES_CAB", Cabinet::CStrW(resolved_cab_path.c_str()), this), 
        L"Error extracting '" << resname << L"': " << extract.LastErrorW());
}

void ExtractComponent::OnAfterCopyFile(wchar_t * s8_File, Cabinet::CMemory *, void* /*p_Param*/)
{
    LOG(L"Done: " << s8_File);
}

BOOL ExtractComponent::OnBeforeCopyFile(Cabinet::CExtract::kCabinetFileInfo * k_FI, void* p_Param)
{
    LOG(L"Extracting: " << k_FI->u16_FullPath);

    ExtractComponent * extractComponent = static_cast<ExtractComponent*>(p_Param);

    extractComponent->OnStatus(std::wstring(k_FI->u16_File) + L" - " + DVLib::FormatBytesW(k_FI->s32_Size));

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

std::wstring ExtractComponent::GetNormalizedId(const std::wstring& id)
{
    std::wstring result(id);
    for (unsigned int i = 0; i < result.length(); i++)
    {
        result[i] = iswalnum(result[i]) 
            ? towupper(result[i])
            : L'_';
    }
    return result;
}

std::wstring ExtractComponent::GetResName(int currentIndex) const
{
    std::wstring resname = TEXT("SETUP_");
    if (! component_id.empty())
    {
        resname += component_id;
        resname += L'_';
    }
    resname.append(DVLib::towstring(currentIndex));
    resname.append(L".CAB");
    return resname;
}

void ExtractComponent::OnProgressInfo(Cabinet::CExtract::kProgressInfo* pk_Progress, void* p_Param)
{
    ExtractComponent * extractComponent = static_cast<ExtractComponent*>(p_Param);

    extractComponent->OnStatus(std::wstring(pk_Progress->u16_RelPath) + L" - " + 
        DVLib::FormatMessage(L"%.f%%", pk_Progress->fl_Percent));

    if (extractComponent->cancelled)
    {
        std::wstring resolved_cancelled_message = extractComponent->cab_cancelled_message;
        if (resolved_cancelled_message.empty()) resolved_cancelled_message = L"Cancelled by user";
        THROW_EX(resolved_cancelled_message);
    }
}