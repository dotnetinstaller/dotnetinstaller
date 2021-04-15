#include "StdAfx.h"
#include "FileUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"
#include "PathUtil.h"
#include "FormatUtil.h"

bool DVLib::FileExists(const std::string& filename)
{
    return FileExists(string2wstring(filename));
}

bool DVLib::FileExists(const std::wstring& filename)
{
    DWORD dwAttr = GetFileAttributesW(filename.c_str());

    if (dwAttr == INVALID_FILE_ATTRIBUTES)
    {
        DWORD dwErr = GetLastError();

        switch(dwErr)
        {
        case ERROR_FILE_NOT_FOUND:
        case ERROR_PATH_NOT_FOUND:
            return false;
        default:
            CHECK_WIN32_DWORD(dwErr,
                L"GetFileAttributesW: " << filename);
        }
    }
    else if (dwAttr & FILE_ATTRIBUTE_DIRECTORY)
    {
        return false;
    }

    return true;
}

std::string DVLib::GetTemporaryFileNameA()
{
    char tf[MAX_PATH];
    CHECK_WIN32_BOOL(GetTempFileNameA(GetTemporaryDirectoryA().c_str(), "DV", 0, tf),
        L"GetTempFileNameA");
    return tf;
}

std::wstring DVLib::GetTemporaryFileNameW()
{	
    wchar_t tf[MAX_PATH];
    CHECK_WIN32_BOOL(GetTempFileNameW(GetTemporaryDirectoryW().c_str(), L"DV", 0, tf),
        L"GetTempFileNameW");
    return tf;
}

void DVLib::FileDelete(const std::string& filename)
{
    CHECK_WIN32_BOOL(::DeleteFileA(filename.c_str()),
        L"Error deleting \"" << DVLib::string2wstring(filename) << L"\"");
}

void DVLib::FileDelete(const std::wstring& filename)
{
    CHECK_WIN32_BOOL(::DeleteFileW(filename.c_str()),
        L"Error deleting \"" << filename << L"\"");
}

void DVLib::FileCopy(const std::string& from, const std::string& to, bool overwrite)
{
    CHECK_WIN32_BOOL(::CopyFileA(from.c_str(), to.c_str(), overwrite),
        L"Error copying \"" << DVLib::string2wstring(from) << L"\" to \"" << DVLib::string2wstring(to) << L"\"");
}

void DVLib::FileCopy(const std::wstring& from, const std::wstring& to, bool overwrite)
{
    CHECK_WIN32_BOOL(::CopyFileW(from.c_str(), to.c_str(), overwrite),
        L"Error copying \"" << from << L"\" to \"" << to << L"\"");
}

void DVLib::FileMove(const std::string& from, const std::string& to)
{
    if (FileExists(to)) 
        FileDelete(to);

    CHECK_WIN32_BOOL(::MoveFileA(from.c_str(), to.c_str()),
        L"Error moving \"" << DVLib::string2wstring(from) << L"\" to \"" << DVLib::string2wstring(to) << L"\"");
}

void DVLib::FileMove(const std::wstring& from, const std::wstring& to)
{
    if (FileExists(to)) 
        FileDelete(to);

    CHECK_WIN32_BOOL(::MoveFileW(from.c_str(), to.c_str()),
        L"Error moving \"" << from << L"\" to \"" << to << L"\"");
}

long DVLib::GetFileSize(const std::wstring& filename)
{
    WIN32_FILE_ATTRIBUTE_DATA attr = { 0 };
    CHECK_WIN32_BOOL(GetFileAttributesExW(filename.c_str(), GetFileExInfoStandard, & attr),
        L"Error getting file attributes of " << filename);
    CHECK_BOOL(0 == attr.nFileSizeHigh,
        L"File " << filename << L" is > 2GB (" << attr.nFileSizeHigh << ")");
    return (long) attr.nFileSizeLow; 
}

long DVLib::GetFileSize(const std::string& filename)
{
    return GetFileSize(DVLib::string2wstring(filename));
}

std::vector<char> DVLib::FileReadToEnd(const std::wstring& filename)
{
    std::vector<char> data;
    long size = GetFileSize(filename);
    if (size > 0)
    {
        auto_hfile hFile(::CreateFile(filename.c_str(), GENERIC_READ, 0,  
            NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL));

        CHECK_WIN32_BOOL(get(hFile) != NULL,
            L"Error opening \"" << filename << L"\"");

        data.resize(size);

        DWORD dwRead = 0;
        CHECK_WIN32_BOOL(::ReadFile(get(hFile), & * data.begin(), size, & dwRead, NULL),
            L"Error reading \"" << filename << L"\"");

        CHECK_BOOL(static_cast<long>(dwRead) == size,
            L"Invalid number of bytes read from \"" << filename << L"\"");
    }
    return data;
}

void DVLib::FileWrite(
                      const std::wstring& filename, 
                      const std::vector<char>& data,
                      DWORD dwShareMode, // GENERIC_READ | GENERIC_WRITE
                      DWORD dwCreationDisposition, // CREATE_ALWAYS
                      DWORD dwFlagsAndAttributes) // FILE_ATTRIBUTE_NORMAL)
{
    auto_hfile hFile(::CreateFile(filename.c_str(), dwShareMode, 0, 
        NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL));

    CHECK_WIN32_BOOL(get(hFile) != NULL,
        L"Error opening " << filename);

    if (data.size() > 0) // empty files are ok
    {
        DWORD dwWritten = 0;
        CHECK_WIN32_BOOL(::WriteFile(get(hFile), & * data.begin(), data.size(), & dwWritten, NULL),
            L"Error writing " << data.size() << " byte(s) to \"" << filename << L"\"");

        CHECK_BOOL(dwWritten == data.size(), 
            L"Invalid number of bytes written.");
    }
}

void DVLib::FileCreate(
                       const std::wstring& filename, 
                       DWORD dwDesiredAccess, // GENERIC_READ | GENERIC_WRITE
                       DWORD dwShareMode, // 0
                       DWORD dwCreationDisposition, // CREATE_ALWAYS
                       DWORD dwFlagsAndAttributes) // FILE_ATTRIBUTE_NORMAL)
{
    auto_hfile hFile(::CreateFile(filename.c_str(), dwDesiredAccess, dwShareMode, 
        NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL));

    CHECK_WIN32_BOOL(get(hFile) != NULL,
        L"Error opening \"" << filename << L"\"");
}

DVLib::FileVersionInfo DVLib::GetFileVersionInfo(const std::wstring& filename)
{
    DVLib::FileVersionInfo result = { 0 };
    DWORD dwVerHnd = 0;
    DWORD dwVerInfoSize = ::GetFileVersionInfoSize(filename.c_str(), & dwVerHnd);
    CHECK_WIN32_BOOL(dwVerInfoSize != 0,
        L"GetFileVersionInfoSize(" << filename << L")");
    std::vector<byte> versioninfo_data;
    versioninfo_data.resize(dwVerInfoSize);
    dwVerInfoSize = versioninfo_data.size();
    CHECK_WIN32_BOOL(::GetFileVersionInfo(filename.c_str(), dwVerHnd, dwVerInfoSize, & * versioninfo_data.begin()),
        L"GetFileVersionInfo(" << filename << L")");
    // VS_FIXEDFILEINFO
    UINT fixed_len = 0;
    VS_FIXEDFILEINFO * lpvi = NULL;
    CHECK_WIN32_BOOL(0 != ::VerQueryValueW(& * versioninfo_data.begin(), L"\\", reinterpret_cast<LPVOID *>(& lpvi), & fixed_len),
        L"VerQueryValue(" << filename << L")");
    result.fixed_info = * lpvi;
    // translation info
    UINT translation_len = 0;
    TranslationInfo * lpti = NULL;
    CHECK_WIN32_BOOL(0 != ::VerQueryValueW(& * versioninfo_data.begin(), L"\\VarFileInfo\\Translation", reinterpret_cast<LPVOID *>(& lpti), & translation_len),
        L"VerQueryValue(" << filename << L", \"\\VarFileInfo\\Translation\")");
    CHECK_BOOL(translation_len <= sizeof(TranslationInfo),
        L"VerQueryValue(" << filename << L", \"\\VarFileInfo\\Translation\"): invalid size");
    result.translation_info = * lpti;
    return result;
}

std::wstring DVLib::GetFileVersion(const std::wstring& filename)
{
    DVLib::FileVersionInfo versioninfo = DVLib::GetFileVersionInfo(filename);
    std::wstringstream version;
    version << HIWORD(versioninfo.fixed_info.dwFileVersionMS) << L"."
        << LOWORD(versioninfo.fixed_info.dwFileVersionMS) << L"."
        << HIWORD(versioninfo.fixed_info.dwFileVersionLS) << L"."
        << LOWORD(versioninfo.fixed_info.dwFileVersionLS);
    return version.str();
}

bool DVLib::ResourceExists(HMODULE h, const std::wstring& resource, const std::wstring& type)
{
    return (NULL != ::FindResource(h, resource.c_str(), type.c_str()));
}

DVLib::FileVersion DVLib::wstring2fileversion(std::wstring version)
{
    FileVersion result = { 0, 0, 0, 0 };

    if (!version.empty() && (version[0] == 'v' || version[0] == 'V'))
       version.erase(0, 1);

    for (size_t i = 0; i < version.length(); i++)
    {
        CHECK_BOOL(version[i] == '.' || isdigit(version[i]),
            L"Invalid version format: '" << version << L"'");
    }

    if (! version.empty())
    {
        std::vector<std::wstring> parts_l = DVLib::split(version, L".", 4);
        result.major = ((parts_l.size() >= 1) ? DVLib::wstring2long(parts_l[0]) : 0);
        result.minor = ((parts_l.size() >= 2) ? DVLib::wstring2long(parts_l[1]) : 0);
        result.build = ((parts_l.size() >= 3) ? DVLib::wstring2long(parts_l[2]) : 0);
        result.rev = ((parts_l.size() == 4) ? DVLib::wstring2long(parts_l[3]) : 0);
    }
    return result;
}

std::wstring DVLib::fileversion2wstring(const FileVersion& version)
{
    return DVLib::FormatMessageW(L"%d.%d.%d.%d", 
        version.major, version.minor, version.build, version.rev);
}

int DVLib::CompareVersion(const std::wstring& l, const std::wstring& r)
{
    FileVersion l_v = wstring2fileversion(l);
    FileVersion r_v = wstring2fileversion(r);

    if (l_v.major < r_v.major)
        return -1;
    else if (l_v.major > r_v.major)
        return 1;

    if (l_v.minor < r_v.minor)
        return -1;
    else if (l_v.minor > r_v.minor)
        return 1;

    if (l_v.build < r_v.build)
        return -1;
    else if (l_v.build > r_v.build)
        return 1;

    if (l_v.rev < r_v.rev)
        return -1;
    else if (l_v.rev > r_v.rev)
        return 1;

    return 0;
}
