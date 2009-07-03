#include "StdAfx.h"
#include "DownloadComponent.h"
#include "InstallerLog.h"

DownloadComponent::DownloadComponent(
	IDownloadCallback * p_Callback, 
	DownloadComponentInfo * p_Component, 
	int p_CurrentComponent, 
	int p_TotalComponents)
{
	m_bCanceledByTheUser = false;
	m_Callback = p_Callback;
	m_Component = p_Component;
	m_CurrentComponent = p_CurrentComponent;
	m_TotalComponents = p_TotalComponents;
}

bool DownloadComponent::IsCopyRequired() const
{
	// no source path, nothing to copy
	if (m_Component->SourcePath.IsEmpty())
		return false;

	// download every time
	if (m_Component->AlwaysDownload)
		return false;

	// destination file has already been downloaded/copied
	if (DVLib::FileExists(GetDestinationFileName()))
		return false;

	// source path file exists, copy it
	if (DVLib::FileExists(m_Component->SourcePath))
		return true;

	// source path file doesn't exist
	return false;
}

bool DownloadComponent::IsDownloadRequired() const
{
	if (m_Component->SourceURL.IsEmpty())
		return false;

	if (! m_Component->AlwaysDownload)
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

CString DownloadComponent::GetDestinationFileName() const
{
	if (m_Component->DestinationFileName.GetLength() <= 0)
	{
		return DVLib::PathCombineT(
			m_Component->DestinationPath, 
			DVLib::GetFileNameFromFullFilePath(m_Component->SourceURL));
	}
	else
	{
		return DVLib::PathCombineT(
			m_Component->DestinationPath, 
			m_Component->DestinationFileName);
	}
}

void DownloadComponent::CopyFromSourcePath()
{
	ApplicationLog.Write( TEXT("SourcePath: "), m_Component->SourcePath);
	ApplicationLog.Write( TEXT("DestinationPath: "), m_Component->DestinationPath);
	DVLib::CreateDirectoryPath(m_Component->DestinationPath);
	CString l_destinationFullFileName = GetDestinationFileName();
	ApplicationLog.Write( TEXT("DestinationFullFileName: "), l_destinationFullFileName);
	ApplicationLog.Write( TEXT("AlwaysDownload: "), m_Component->AlwaysDownload ? TEXT("True") : TEXT("False") );
	ApplicationLog.Write( TEXT("FileExists: "), DVLib::FileExists(l_destinationFullFileName) ? TEXT("True") : TEXT("False") );

	if (! IsCopyRequired())
	{
		ApplicationLog.Write( TEXT("Skipping copy.") );
		return;
	}

	if (! CopyFile(m_Component->SourcePath, l_destinationFullFileName, false))
	{
		std::string error = "Error copying \"";
		error.append(DVLib::wstring2string((LPCWSTR) m_Component->SourcePath));
		error.append("\" to \"");
		error.append(DVLib::wstring2string((LPCWSTR) l_destinationFullFileName));
		error.append("\r\n");
		error.append(DVLib::GetLastErrorString());
		throw std::exception(error.c_str());
	}
}

void DownloadComponent::StartDownload()
{
	CString l_destinationFullFileName = GetDestinationFileName();

	ApplicationLog.Write( TEXT("SourceURL: "), m_Component->SourceURL);
	ApplicationLog.Write( TEXT("DestinationPath: "), m_Component->DestinationPath);
	DVLib::CreateDirectoryPath(m_Component->DestinationPath);
	ApplicationLog.Write( TEXT("DestinationFullFileName: "), l_destinationFullFileName);
	ApplicationLog.Write( TEXT("AlwaysDownload: "), m_Component->AlwaysDownload ? TEXT("True") : TEXT("False") );
	ApplicationLog.Write( TEXT("FileExists: "), DVLib::FileExists(l_destinationFullFileName) ? TEXT("True") : TEXT("False") );

	if (! IsDownloadRequired())
	{
		ApplicationLog.Write( TEXT("Skipping download.") );
		return;
	}

	ApplicationLog.Write( TEXT("Downloading: "), m_Component->SourceURL);
	HRESULT l_hrRet = URLDownloadToFile(NULL, m_Component->SourceURL, l_destinationFullFileName, 0, this);
	if (FAILED(l_hrRet))
	{
		std::string error = "Error downloading \"";
		error.append(DVLib::wstring2string((LPCTSTR) m_Component->SourceURL));
		error.append("\" to \"");
		error.append(DVLib::wstring2string((LPCTSTR) l_destinationFullFileName));
		error.append(": ");
		error.append(DVLib::wstring2string((LPCTSTR) DVLib::TranslateErrorMsg(l_hrRet, "urlmon.dll")));
		throw std::exception(error.c_str());
	}
}

HRESULT DownloadComponent::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText)
{
	// Did the user hit the Stop button?
	if ( m_Callback->WantToStop() )
	{
		m_bCanceledByTheUser = true;
		return E_ABORT;
	}

	CString tmp;
	tmp.Format(TEXT("%s (%s of %s) - %d/%d"), m_Component->ComponentName, 
		DVLib::FormatNumberToBytes(ulProgress), DVLib::FormatNumberToBytes(ulProgressMax), 
		m_CurrentComponent, m_TotalComponents );

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
