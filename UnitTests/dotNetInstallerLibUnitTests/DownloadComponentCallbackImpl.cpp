#include "StdAfx.h"
#include "DownloadComponentCallbackImpl.h"

using namespace DVLib::UnitTests;

DownloadComponentCallbackImpl::DownloadComponentCallbackImpl()
	: m_cancelled(false)
{
}

void DownloadComponentCallbackImpl::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
	std::wcout << std::endl << description << L" (" << progress_current << L"/" << progress_max << L")";
}

void DownloadComponentCallbackImpl::DownloadComplete()
{
	std::wcout << std::endl << "Download complete.";
}

void DownloadComponentCallbackImpl::DownloadError(const std::wstring& message)
{
	CPPUNIT_ASSERT_MESSAGE(DVLib::wstring2string(message).c_str(), false);
}
