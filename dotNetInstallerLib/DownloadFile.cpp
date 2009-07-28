#include "StdAfx.h"
#include "XmlAttribute.h"
#include "DownloadFile.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

DownloadFile::DownloadFile()
	: callback(NULL)
{

}

DownloadFile::~DownloadFile()
{

}

void DownloadFile::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'download' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "download"),
		L"Expected 'download' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	componentname = XML_ATTRIBUTE(node->Attribute("componentname"));
	sourceurl = XML_ATTRIBUTE(node->Attribute("sourceurl"));
	sourcepath = XML_ATTRIBUTE(node->Attribute("sourcepath"));
	destinationpath = XML_ATTRIBUTE(node->Attribute("destinationpath"));
	destinationfilename = XML_ATTRIBUTE(node->Attribute("destinationfilename"));
	alwaysdownload = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("alwaysdownload")), true);		

	LOG(L"Loaded 'download' dialog component '" << componentname 
		<< L"', source=" << (sourceurl.length() ? sourceurl : sourcepath));

	if (sourceurl.empty() && sourcepath.empty())
	{
		THROW_EX(L"Error in 'download' dialog component '" << componentname << L"', missing source url or path");
	}
}

bool DownloadFile::IsDownloadRequired() const
{
	if (sourceurl.empty())
		return false;

	if (! alwaysdownload)
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

bool DownloadFile::IsCopyRequired() const
{
	// no source path, nothing to copy
	if (sourcepath.empty())
		return false;

	// download every time
	if (alwaysdownload)
		return false;

	// destination file has already been downloaded/copied
	if (DVLib::FileExists(GetDestinationFileName()))
		return false;

	// source path file exists, copy it
	if (DVLib::FileExists(sourcepath))
		return true;

	// source path file doesn't exist
	return false;
}

std::wstring DownloadFile::GetDestinationFileName() const
{
	return destinationfilename.empty()
		? DVLib::DirectoryCombine(destinationpath, DVLib::GetFileNameW(sourceurl))
		: DVLib::DirectoryCombine(destinationpath, destinationfilename);
}

void DownloadFile::CopyFromSourcePath()
{
	std::wstring destination_full_filename = GetDestinationFileName();
	LOG(L"Copying '" << componentname 
		<< L"', source='" << sourcepath 
		<< L"', destination='" << destinationpath 
		<< L"', full='" << destination_full_filename
		<< L"', always download=" << (alwaysdownload ? L"True" : L"False")
		<< L"', destination exists=" << (DVLib::FileExists(destination_full_filename) ? L"True" : L"False"));

	DVLib::DirectoryCreate(destinationpath);

	if (! IsCopyRequired())
	{
		LOG(L"Copy '" << componentname << L"': SKIPPED");
		return;
	}

	long source_size = DVLib::GetFileSize(sourcepath);
	std::wstring tmp = DVLib::FormatMessage(L"%s (%s)", componentname.c_str(), DVLib::FormatBytesW(source_size).c_str());
	if (callback != NULL)
	{
		callback->Status(0, source_size, tmp);
	}

	DVLib::FileCopy(sourcepath, destination_full_filename, true);

	if (callback != NULL)
	{
		long dest_size = DVLib::GetFileSize(destination_full_filename);
		LOG(L"Copy '" << componentname << L"', size=" << DVLib::FormatBytesW(dest_size) << L": OK");
		callback->Status(dest_size, source_size, tmp);
	}
}

void DownloadFile::DownloadFromSourceUrl()
{
	std::wstring destination_full_filename = GetDestinationFileName();

	LOG(L"Downloading '" << componentname 
		<< L"', source='" << sourceurl 
		<< L"', destination='" << destinationpath 
		<< L"', full='" << destination_full_filename
		<< L"', always download=" << (alwaysdownload ? L"True" : L"False"));

	if (! DVLib::DirectoryExists(destinationpath))
	{
		LOG(L"Creating directory '" << destinationpath << L"'");
		DVLib::DirectoryCreate(destinationpath);
	}

	if (! IsDownloadRequired())
	{
		LOG(L"Download '" << componentname << L"': SKIPPED");
		return;
	}

	// download to a .tmp file, then rename to avoid partially donwloaded installers
	std::wstring destination_full_filename_tmp = destination_full_filename + L".tmp";
	CHECK_HR_DLL(URLDownloadToFile(NULL, sourceurl.c_str(), destination_full_filename_tmp.c_str(), 0, this),
		L"Error downloading \"" << sourceurl << L"\" to \"" << destination_full_filename_tmp << L"\"", L"urlmon.dll");

	DVLib::FileMove(destination_full_filename_tmp, destination_full_filename);

	LOG(L"Download '" << componentname << L"', size=" 
		<< DVLib::FormatBytesW(DVLib::GetFileSize(destination_full_filename)) << L": OK");
}

HRESULT DownloadFile::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR /* wszStatusText */)
{
	if (! callback)
		return S_OK;

	// did the user hit the Stop button?
	if (callback->IsDownloadCancelled() )
		return E_ABORT;

	switch(ulStatusCode)
	{
	case BINDSTATUS_CONNECTING:
		callback->Connecting();
		break;
	case BINDSTATUS_SENDINGREQUEST:
		callback->SendingRequest();
		break;
	case BINDSTATUS_DOWNLOADINGDATA:
		std::wstring tmp = DVLib::FormatMessage(L"%s (%s of %s)", 
			componentname.c_str(), DVLib::FormatBytesW(ulProgress).c_str(), DVLib::FormatBytesW(ulProgressMax).c_str());
		callback->Status(ulProgress, ulProgressMax, tmp);
		break;
	}

	return S_OK;
}

HRESULT DownloadFile::OnStopBinding(HRESULT /* hresult */, LPCWSTR /* szError */)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::OnStartBinding(DWORD /* dwReserved */, IBinding __RPC_FAR *)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::GetPriority(LONG __RPC_FAR *)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::OnLowResource(DWORD /* reserved */)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::GetBindInfo(DWORD __RPC_FAR * /* grfBINDF */, BINDINFO __RPC_FAR * /* pbindinfo */)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::OnDataAvailable(DWORD /* grfBSCF */, DWORD /* dwSize */, FORMATETC __RPC_FAR * /* pformatetc */, STGMEDIUM __RPC_FAR * /* pstgmed */)
{
	return E_NOTIMPL;
}

HRESULT DownloadFile::OnObjectAvailable(REFIID /* riid */, IUnknown __RPC_FAR * /* punk */)
{
	return E_NOTIMPL;
}


ULONG DownloadFile::AddRef() 
{ 
	return 0; 
}

ULONG DownloadFile::Release()
{
	return 0;
}

HRESULT DownloadFile::QueryInterface(REFIID /* riid */, void __RPC_FAR *__RPC_FAR * /* ppvObject */)
{ 
	return E_NOTIMPL; 
}

void DownloadFile::Exec(IDownloadCallback * cb)
{
	callback = cb;

	if (IsCopyRequired())
	{
		CopyFromSourcePath();
	}
	else if (IsDownloadRequired())
	{
		DownloadFromSourceUrl();
	}
}
