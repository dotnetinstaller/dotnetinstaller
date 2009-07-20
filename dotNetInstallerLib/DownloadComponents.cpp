#include "StdAfx.h"
#include "DownloadComponents.h"
#include "InstallerLog.h"

DownloadComponents::DownloadComponents(
	IDownloadCallback * callback_impl, 
	const std::vector<DownloadComponentInfoPtr>& component_info)
	: ThreadComponent(undefined)
	, callback(callback_impl)
{
	for (size_t i = 0; i < component_info.size(); i++)
	{
		push_back(DownloadComponentPtr(new DownloadComponent(
			callback, component_info[i], i + 1, component_info.size())));
	}
}

void DownloadComponents::ExecOnThread()
{
	try
	{
		for (size_t i = 0; i < size(); i++)
		{
			const DownloadComponentPtr& component = (* this)[i];

			if (callback && callback->IsDownloadCancelled())
				return;

			if (component->IsCopyRequired())
			{
				component->CopyFromSourcePath();
			}
			else if (component->IsDownloadRequired())
			{
				component->StartDownload();
			}
		}

		if (callback)
		{
			callback->DownloadComplete();
		}
	}
	catch(std::exception& ex)
	{
	    if (callback)
		{
			callback->DownloadError(DVLib::string2wstring(ex.what()).c_str());
		}
	}	
}

bool DownloadComponents::IsCopyRequired() const
{
	for (size_t i = 0; i < size(); i++)
	{
		bool required = (* this)[i]->IsCopyRequired();
				
		std::wstring destination = (* this)[i]->GetDestinationFileName();
		LOG(L"Destination '" << destination 
			<< L"', exists=" << (DVLib::FileExists(destination) ? L"True" : L"False")
			<< L", copy=" << (required ? L"True" : L"False"));

		if (required)
		{
			return true;
		}
	}

	return false;
}

bool DownloadComponents::IsDownloadRequired() const
{
	for (size_t i = 0; i < size(); i++)
	{
		bool required = (* this)[i]->IsDownloadRequired();
				
		std::wstring destination = (* this)[i]->GetDestinationFileName();
		LOG(L"Destination '" << destination 
			<< L"', exists=" << (DVLib::FileExists(destination) ? L"True" : L"False")
			<< L", download=" << (required ? L"True" : L"False"));

		if (required)
		{
			return true;
		}
	}

	return false;
}
