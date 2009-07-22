#include "StdAfx.h"
#include "DownloadComponent.h"
#include "InstallerLog.h"

DownloadComponent::DownloadComponent(
	IDownloadCallback * callback, 
	DownloadComponentInfoPtr componentinfo, 
	int current, 
	int total)
{
	m_Callback = callback;
	m_pComponent = componentinfo;
	m_CurrentComponent = current;
	m_TotalComponents = total;
}

bool DownloadComponent::IsCopyRequired() const
{
	// no source path, nothing to copy
	if (m_pComponent->sourcepath.empty())
		return false;

	// download every time
	if (m_pComponent->alwaysdownload)
		return false;

	// destination file has already been downloaded/copied
	if (DVLib::FileExists(GetDestinationFileName()))
		return false;

	// source path file exists, copy it
	if (DVLib::FileExists(m_pComponent->sourcepath))
		return true;

	// source path file doesn't exist
	return false;
}

bool DownloadComponent::IsDownloadRequired() const
{
	if (m_pComponent->sourceurl.empty())
		return false;

	if (! m_pComponent->alwaysdownload)
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
	return m_pComponent->destinationfilename.empty()
		? DVLib::DirectoryCombine(m_pComponent->destinationpath, DVLib::GetFileNameW(m_pComponent->sourceurl))
		: DVLib::DirectoryCombine(m_pComponent->destinationpath, m_pComponent->destinationfilename);
}

void DownloadComponent::CopyFromSourcePath()
{
	std::wstring destination_full_filename = GetDestinationFileName();
	LOG(L"Copying '" << m_pComponent->componentname 
		<< L"', source='" << m_pComponent->sourcepath 
		<< L"', destination='" << m_pComponent->destinationpath 
		<< L"', full='" << destination_full_filename
		<< L"', always download=" << (m_pComponent->alwaysdownload ? L"True" : L"False")
		<< L"', destination exists=" << (DVLib::FileExists(destination_full_filename) ? L"True" : L"False"));

	DVLib::DirectoryCreate(m_pComponent->destinationpath);

	if (! IsCopyRequired())
	{
		LOG(L"Copy '" << m_pComponent->componentname << L"': SKIPPED");
		return;
	}

	long source_size = DVLib::GetFileSize(m_pComponent->sourcepath);
	std::wstring tmp = DVLib::FormatMessage(L"%s (%s) - %d/%d", 
		m_pComponent->componentname.c_str(), DVLib::FormatBytesW(source_size).c_str(),
		m_CurrentComponent, m_TotalComponents);
	m_Callback->Status(0, source_size, tmp);

	DVLib::FileCopy(m_pComponent->sourcepath, destination_full_filename, true);

	long dest_size = DVLib::GetFileSize(destination_full_filename);
	LOG(L"Copy '" << m_pComponent->componentname << L"', size=" 
		<< DVLib::FormatBytesW(dest_size) << L": OK");
	m_Callback->Status(dest_size, source_size, tmp);
}

void DownloadComponent::StartDownload()
{
	std::wstring destination_full_filename = GetDestinationFileName();

	LOG(L"Downloading '" << m_pComponent->componentname 
		<< L"', source='" << m_pComponent->sourceurl 
		<< L"', destination='" << m_pComponent->destinationpath 
		<< L"', full='" << destination_full_filename
		<< L"', always download=" << (m_pComponent->alwaysdownload ? L"True" : L"False"));

	if (! DVLib::DirectoryExists(m_pComponent->destinationpath))
	{
		LOG(L"Creating directory '" << m_pComponent->destinationpath << L"'");
		DVLib::DirectoryCreate(m_pComponent->destinationpath);
	}

	if (! IsDownloadRequired())
	{
		LOG(L"Download '" << m_pComponent->componentname << L"': SKIPPED");
		return;
	}

	// download to a .tmp file, then rename to avoid partially donwloaded installers
	std::wstring destination_full_filename_tmp = destination_full_filename + L".tmp";
	CHECK_HR_DLL(URLDownloadToFile(NULL, m_pComponent->sourceurl.c_str(), destination_full_filename_tmp.c_str(), 0, this),
		L"Error downloading \"" << m_pComponent->sourceurl << L"\" to \"" << destination_full_filename_tmp << L"\"", L"urlmon.dll");

	DVLib::FileMove(destination_full_filename_tmp, destination_full_filename);

	LOG(L"Download '" << m_pComponent->componentname << L"', size=" 
		<< DVLib::FormatBytesW(DVLib::GetFileSize(destination_full_filename)) << L": OK");
}

HRESULT DownloadComponent::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText)
{
	// Did the user hit the Stop button?
	if ( m_Callback && m_Callback->IsDownloadCancelled() )
		return E_ABORT;

	switch(ulStatusCode)
	{
	case BINDSTATUS_CONNECTING:
		m_Callback->Connecting();
		break;
	case BINDSTATUS_SENDINGREQUEST:
		m_Callback->SendingRequest();
		break;
	case BINDSTATUS_DOWNLOADINGDATA:
		std::wstring tmp = DVLib::FormatMessage(L"%s (%s of %s) - %d/%d", 
			m_pComponent->componentname.c_str(), DVLib::FormatBytesW(ulProgress).c_str(), DVLib::FormatBytesW(ulProgressMax).c_str(), 
			m_CurrentComponent, m_TotalComponents);
		m_Callback->Status(ulProgress, ulProgressMax, tmp);
		break;
	}

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
