#include "StdAfx.h"
#include "XmlAttribute.h"
#include "DownloadFile.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include <wininet.h>

#pragma comment(lib, "wininet.lib")

namespace
{
    struct close_internet_handle
    {
        static void close(HINTERNET handle)
        {
            ::InternetCloseHandle(handle);
        }
    };

    typedef auto_any<HINTERNET, close_internet_handle> auto_hinternet;
}

DownloadFile::DownloadFile()
: callback(NULL)
, alwaysdownload(false)
, clear_cache(false)
{

}

DownloadFile::~DownloadFile()
{

}

void DownloadFile::Load(tinyxml2::XMLElement * node)
{
    CHECK_BOOL(node != NULL,
        L"Expected 'download' node");

    CHECK_BOOL(0 == strcmp(node->Value(), "download"),
        L"Expected 'download' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    componentname = node->Attribute("componentname");
    sourceurl = node->Attribute("sourceurl");
    sourcepath = node->Attribute("sourcepath");
    destinationpath = node->Attribute("destinationpath");
    destinationfilename = node->Attribute("destinationfilename");
    alwaysdownload = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("alwaysdownload")), true);		
    clear_cache = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("clear_cache")), false);		

    LOG(L"Loaded 'download' dialog component '" << componentname 
        << L"', source=" << (sourceurl.empty() ? sourcepath : sourceurl));

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
    std::wstring tmp = DVLib::FormatMessage(L"%s (%s)", 
        componentname.GetValue().c_str(), DVLib::FormatBytesW(source_size).c_str());
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

    // download to a .tmp file, then rename to avoid partially downloaded installers
    std::wstring destination_full_filename_tmp = destination_full_filename + L".tmp";
    if (DVLib::FileExists(destination_full_filename_tmp))
    {
        LOG(L"Deleting '" << destination_full_filename_tmp << L"'.");
        DVLib::FileDelete(destination_full_filename_tmp);
    }

    ClearCache();

    if (IsHttpsUrl())
    {
        // URLDownloadToFile downloads into the Internet Explorer cache and copies the file from there, which
        // fails with INET_E_DOWNLOAD_FAILURE over https when "Do not save encrypted pages to disk" is enabled,
        // so https downloads write the response directly to the destination file without the cache
        DownloadWithWinINet(destination_full_filename_tmp);
    }
    else
    {
        CHECK_HR_DLL(URLDownloadToFile(NULL, sourceurl.GetValue().c_str(), destination_full_filename_tmp.c_str(), 0, this),
            L"Error downloading \"" << sourceurl << L"\" to \"" << destination_full_filename_tmp << L"\"", L"urlmon.dll");
    }

    DVLib::FileMove(destination_full_filename_tmp, destination_full_filename);

    LOG(L"Download '" << componentname << L"', size=" 
        << DVLib::FormatBytesW(DVLib::GetFileSize(destination_full_filename)) << L": OK");
}

bool DownloadFile::IsHttpsUrl() const
{
    return 0 == _wcsnicmp(sourceurl.GetValue().c_str(), L"https://", 8);
}

void DownloadFile::DownloadWithWinINet(const std::wstring& filename)
{
    std::wstring error_message = L"Error downloading \"" + sourceurl.GetValue() + L"\" to \"" + filename + L"\"";

    // INTERNET_OPEN_TYPE_PRECONFIG uses the same proxy settings as URLDownloadToFile
    auto_hinternet internet(::InternetOpenW(L"dotNetInstaller", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0));
    if (! internet)
    {
        THROW_EX(DVLib::GetErrorStringW(::GetLastError(), error_message.c_str(), L"wininet.dll"));
    }

    if (callback != NULL)
    {
        callback->Connecting(sourceurl);
    }

    DWORD flags = INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_UI;
    auto_hinternet request(::InternetOpenUrlW(get(internet), sourceurl.GetValue().c_str(), NULL, 0, flags, 0));
    if (! request)
    {
        THROW_EX(DVLib::GetErrorStringW(::GetLastError(), error_message.c_str(), L"wininet.dll"));
    }

    if (callback != NULL)
    {
        callback->SendingRequest(sourceurl);
    }

    DWORD status_code = 0;
    DWORD status_code_size = sizeof(status_code);
    if (::HttpQueryInfoW(get(request), HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER, & status_code, & status_code_size, NULL)
        && (status_code < 200 || status_code > 299))
    {
        THROW_EX(error_message << L": the server returned HTTP status code " << status_code);
    }

    // the content length is unknown when the server does not send it
    DWORD content_length = 0;
    DWORD content_length_size = sizeof(content_length);
    if (! ::HttpQueryInfoW(get(request), HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER, & content_length, & content_length_size, NULL))
    {
        content_length = 0;
    }

    auto_hfile file(::CreateFileW(filename.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
    if (! file)
    {
        THROW_EX(DVLib::GetLastErrorStringW((L"Error creating \"" + filename + L"\"").c_str()));
    }

    std::vector<char> buffer(64 * 1024);
    DWORD total_read = 0;
    while (true)
    {
        if (callback != NULL && callback->IsDownloadCancelled())
        {
            THROW_EX(DVLib::GetErrorStringW(E_ABORT, error_message.c_str()));
        }

        DWORD read = 0;
        if (! ::InternetReadFile(get(request), & buffer[0], static_cast<DWORD>(buffer.size()), & read))
        {
            THROW_EX(DVLib::GetErrorStringW(::GetLastError(), error_message.c_str(), L"wininet.dll"));
        }

        if (read == 0)
            break;

        DWORD written = 0;
        CHECK_WIN32_BOOL(::WriteFile(get(file), & buffer[0], read, & written, NULL),
            L"Error writing \"" << filename << L"\"");

        total_read += read;

        if (callback != NULL)
        {
            std::wstring tmp = DVLib::FormatMessage(L"%s (%s of %s)",
                componentname.GetValue().c_str(),
                DVLib::FormatBytesW(total_read).c_str(),
                DVLib::FormatBytesW(content_length).c_str());
            callback->Status(total_read, content_length, tmp);
        }
    }
}

bool DownloadFile::ClearCache()
{
    if (! clear_cache)
        return false;

    // DeleteUrlCacheEntryW supported on Windows 2000 and later
    typedef BOOL (WINAPI * pDeleteUrlCacheEntry) (LPCTSTR lpszUrlName);
    DllFunction<pDeleteUrlCacheEntry> deleteUrlCacheEntry(L"wininet.dll", "DeleteUrlCacheEntryW");
    if (NULL == deleteUrlCacheEntry)
    {
        LOG(L"Skipping deleting cache entry for '" << sourceurl << L"', function not available.");
        return false;
    }

    LOG(L"Deleting cache entry for '" << sourceurl << L"'.");
    if (! deleteUrlCacheEntry(sourceurl.GetValue().c_str()))
    {
        LOG(DVLib::GetLastErrorStringW(L"Ignoring error clearing cache"));
        return false;
    }

    return true;
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
        // \todo: extract host from sourceurl
        callback->Connecting(sourceurl);
        break;
    case BINDSTATUS_SENDINGREQUEST:
        callback->SendingRequest(sourceurl);
        break;
    case BINDSTATUS_DOWNLOADINGDATA:
        std::wstring tmp = DVLib::FormatMessage(L"%s (%s of %s)", 
            componentname.GetValue().c_str(), 
            DVLib::FormatBytesW(ulProgress).c_str(), 
            DVLib::FormatBytesW(ulProgressMax).c_str());
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
        if (cb != NULL)
        {
            // notify callback of file copy
            cb->CopyingFile(sourcepath);
        }

        CopyFromSourcePath();
    }
    else if (IsDownloadRequired())
    {
        if (cb != NULL)
        {
            // notify callback of download
            cb->DownloadingFile(sourceurl);
        }

        DownloadFromSourceUrl();
    }
}

std::wstring DownloadFile::GetString(int indent) const
{
    std::wstringstream ss;
    for (int i = 0; i < indent; i++) ss << L" ";
    ss << componentname;
    return ss.str();
}
