#include "StdAfx.h"
#include "DownloadComponent.h"
#include "InstallerLog.h"

DownloadComponent::DownloadComponent(
	IDownloadCallback * callback, 
	const DownloadComponentInfo& component, 
	int current, 
	int total)
{
	m_bCancel = false;
	m_Callback = callback;
	m_Component = component;
	m_CurrentComponent = current;
	m_TotalComponents = total;
}

bool DownloadComponent::IsCopyRequired() const
{
	// no source path, nothing to copy
	if (m_Component.source_path.empty())
		return false;

	// download every time
	if (m_Component.always_download)
		return false;

	// destination file has already been downloaded/copied
	if (DVLib::FileExists(GetDestinationFileName()))
		return false;

	// source path file exists, copy it
	if (DVLib::FileExists(m_Component.source_path))
		return true;

	// source path file doesn't exist
	return false;
}

bool DownloadComponent::IsDownloadRequired() const
{
	if (m_Component.source_url.empty())
		return false;

	if (! m_Component.always_download)
	{
		// destination file has already been donwloaded
		if (DVLib::FileExists(GetDestinationFileName()))
			return false;
		// file exists in a local path
		if (IsCopyRequired())
			return false;
	}

	return true;
}

std::wstring DownloadComponent::GetDestinationFileName() const
{
	return m_Component.destination_filename.empty()
		? DVLib::DirectoryCombine(m_Component.destination_path, DVLib::GetFileNameW(m_Component.source_url))
		: DVLib::DirectoryCombine(m_Component.destination_path, m_Component.destination_filename);
}

void DownloadComponent::CopyFromSourcePath()
{
	LOG(L"Source path: " << m_Component.source_path);
	LOG(L"Destination path: " << m_Component.destination_path);
	DVLib::DirectoryCreate(m_Component.destination_path);
	std::wstring destination_full_filename = GetDestinationFileName();
	LOG(L"Destination full path: " << destination_full_filename);
	LOG(L"Always download: " << m_Component.always_download ? L"True" : L"False");
	LOG(L"Destination exists: " << DVLib::FileExists(destination_full_filename) ? L"True" : L"False");

	if (! IsCopyRequired())
	{
		LOG(L"Skipping copy.");
		return;
	}

	DVLib::FileCopy(m_Component.source_path, destination_full_filename, true);
}

void DownloadComponent::StartDownload()
{
	std::wstring destination_full_filename = GetDestinationFileName();

	LOG(L"Source url: " << m_Component.source_url);
	LOG(L"Destination path: " << m_Component.destination_path);
	DVLib::DirectoryCreate(m_Component.destination_path);
	LOG(L"Destination full path: " << destination_full_filename);
	LOG(L"Always download: " << m_Component.always_download ? L"True" : L"False" );
	LOG(L"Destination exists: " << DVLib::FileExists(destination_full_filename) ? L"True" : L"False" );

	if (! IsDownloadRequired())
	{
		LOG(L"Skipping download.");
		return;
	}

	LOG(L"Downloading: " << m_Component.source_url);

	CHECK_HR_DLL(URLDownloadToFile(NULL, m_Component.source_url.c_str(), destination_full_filename.c_str(), 0, this),
		L"Error downloading \"" << m_Component.source_url << L"\" to \"" << destination_full_filename << L"\"", L"urlmon.dll");
}

HRESULT DownloadComponent::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText)
{
	// Did the user hit the Stop button?
	if ( m_Callback->IsDownloadCancelled() )
	{
		m_bCancel = true;
		return E_ABORT;
	}

	std::wstring tmp = DVLib::FormatMessage(L"%s (%s of %s) - %d/%d", 
		m_Component.component_name.c_str(), DVLib::FormatBytesW(ulProgress).c_str(), DVLib::FormatBytesW(ulProgressMax).c_str(), 
		m_CurrentComponent, m_TotalComponents);

	m_Callback->Status(ulProgress, ulProgressMax, tmp);
	return S_OK;
}

HRESULT DownloadComponent::OnStopBinding(HRESULT hresult, LPCWSTR szError)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::OnStartBinding(DWORD dwReserved, IBinding __RPC_FAR *pib)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::GetPriority(LONG __RPC_FAR *pnPriority)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::OnLowResource(DWORD reserved)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::GetBindInfo(DWORD __RPC_FAR *grfBINDF, BINDINFO __RPC_FAR *pbindinfo)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC __RPC_FAR *pformatetc, STGMEDIUM __RPC_FAR *pstgmed)
{
	return E_NOTIMPL;
}

HRESULT DownloadComponent::OnObjectAvailable(REFIID riid, IUnknown __RPC_FAR *punk)
{
	return E_NOTIMPL;
}


ULONG DownloadComponent::AddRef() 
{ 
	return 0; 
}

ULONG DownloadComponent::Release()
{
	return 0;
}

HRESULT DownloadComponent::QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject)
{ 
	return E_NOTIMPL; 
}
