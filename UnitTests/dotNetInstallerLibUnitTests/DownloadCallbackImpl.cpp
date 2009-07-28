#include "StdAfx.h"
#include "DownloadCallbackImpl.h"

using namespace DVLib::UnitTests;

DownloadCallbackImpl::DownloadCallbackImpl()
	: m_cancelled(false)
	, m_complete(0)
	, m_error(0)
{
}

void DownloadCallbackImpl::Connecting()
{
	std::wcout << std::endl << "Connecting ...";
}

void DownloadCallbackImpl::SendingRequest()
{
	std::wcout << std::endl << "Sending request ...";
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
