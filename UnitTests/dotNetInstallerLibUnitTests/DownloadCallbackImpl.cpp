#include "StdAfx.h"
#include "DownloadCallbackImpl.h"

using namespace DVLib::UnitTests;

DownloadCallbackImpl::DownloadCallbackImpl()
: m_cancelled(false)
, m_complete(0)
, m_error(0)
, m_downloading(false)
, m_copying(false)
{
}

void DownloadCallbackImpl::Connecting(const std::wstring& host)
{
    std::wcout << std::endl << "Connecting to " << host << L"...";
}

void DownloadCallbackImpl::SendingRequest(const std::wstring& host)
{
    std::wcout << std::endl << "Sending request to " << host << L"...";
}

void DownloadCallbackImpl::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
    std::wcout << std::endl << description << L" (" << progress_current << L"/" << progress_max << L")";
}

void DownloadCallbackImpl::DownloadComplete()
{
    InterlockedIncrement(& m_complete);
    std::wcout << std::endl << "Download complete.";
}

void DownloadCallbackImpl::DownloadError(const std::wstring& message)
{
    InterlockedIncrement(& m_error);
    std::wcout << std::endl << message;	
}

void DownloadCallbackImpl::CopyingFile(const std::wstring& filename)
{
    std::wcout << std::endl << "Copying " << filename << L"...";
    m_copying = true;
}

void DownloadCallbackImpl::DownloadingFile(const std::wstring& url)
{
    std::wcout << std::endl << "Downloading " << url << L"...";
    m_downloading = true;
}
