#include "StdAfx.h"
#include "DownloadComponentCallbackImpl.h"

using namespace DVLib::UnitTests;

DownloadComponentCallbackImpl::DownloadComponentCallbackImpl()
	: m_cancelled(false)
	, m_complete(0)
	, m_error(0)
{
}

void DownloadComponentCallbackImpl::Connecting()
{
	std::wcout << std::endl << "Connecting ...";
}

void DownloadComponentCallbackImpl::SendingRequest()
{
	std::wcout << std::endl << "Sending request ...";
}

void DownloadComponentCallbackImpl::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
	std::wcout << std::endl << description << L" (" << progress_current << L"/" << progress_max << L")";
}

void DownloadComponentCallbackImpl::DownloadComplete()
{
	InterlockedIncrement(& m_complete);
	std::wcout << std::endl << "Download complete.";
}

void DownloadComponentCallbackImpl::DownloadError(const std::wstring& message)
{
	InterlockedIncrement(& m_error);
	std::wcout << std::endl << message;	
}
