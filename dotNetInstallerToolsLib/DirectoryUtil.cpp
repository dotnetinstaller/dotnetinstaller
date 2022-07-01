#include "StdAfx.h"
#include "DirectoryUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"
#include "PathUtil.h"

std::wstring DVLib::DirectoryNormalize(const std::wstring& path)
{
    return DVLib::replace(path, L"\\\\", L"\\");
}

bool DVLib::DirectoryExists(const std::string& path)
{
    return DirectoryExists(DVLib::string2wstring(path));
}

bool DVLib::DirectoryExists(const std::wstring& full_path)
{
    std::wstring path = DirectoryNormalize(full_path);

    if (path.empty()) 
        return false;

    DWORD dwAttr = GetFileAttributesW(path.c_str());

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
                L"GetFileAttributesW: " << path);
            break;
        }
    }
    else if (dwAttr & FILE_ATTRIBUTE_DIRECTORY)
    {
        return true;
    }

    return false;
}

std::string DVLib::DirectoryCreate(const std::string& path)
{
    return DVLib::wstring2string(
        DirectoryCreate(DVLib::string2wstring(path)));
}

std::wstring DVLib::DirectoryCreate(const std::wstring& full_path)
{
    std::wstring result;
    std::wstring path = DirectoryNormalize(full_path);
    std::vector<std::wstring> parts = DVLib::split(path, L"\\");

    std::wstring current;
    for each (std::wstring part in parts)
    {
        // avoid double-slashes, bug 4378
        if (part.empty())
            continue;

        if (current.length() > 0) current.append(L"\\");
        current.append(part);

        if (! DirectoryExists(current))
        {
            CHECK_WIN32_BOOL(::CreateDirectoryW(current.c_str(), NULL),
                L"Error in CreateDirectory: " << current);

            if (result.empty()) result = current;
        }
    }

    return result;
}

bool DVLib::DirectoryDelete(const std::string& path, int flags)
{
    return DirectoryDelete(DVLib::string2wstring(path), flags);
}

bool DVLib::DirectoryDelete(const std::wstring& full_path, int flags)
{
    std::wstring path = DirectoryNormalize(full_path);

    CHECK_BOOL(flags > 0,
        L"Missing flags");

    WIN32_FIND_DATAW data = { 0 };
    bool directory_empty = true;
    bool directory_exists = false;
    std::wstring wildcard = DVLib::trim(path, L"\\");
    wildcard.append(L"\\*");

    auto_hfind h(::FindFirstFileW(wildcard.c_str(), & data)); // find the first file

    if (get(h) != INVALID_HANDLE_VALUE)
    {
        directory_exists = true;

        do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            std::wstring sub = DVLib::trimright(path, L"\\");
            sub.append(L"\\");
            sub.append(filename);

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if ((flags & DELETE_DIRECTORY_SUBDIRECTORIES) > 0)
                {
                    directory_empty &= DirectoryDelete(sub, flags);
                }
            }
            else if ((flags & DELETE_DIRECTORY_FILES) > 0)
            {
                CHECK_WIN32_BOOL(::DeleteFileW(sub.c_str()),
                    L"Error deleting " << sub);
            }
            else
            {
                directory_empty = false;
            }

        } while (FindNextFileW(get(h), & data));
    }

    switch(DWORD rc = ::GetLastError())
    {
    case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // no more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }

    reset(h);

    if (directory_exists && directory_empty && ((flags & DELETE_DIRECTORY_FOLDERS) > 0))
    {
        CHECK_WIN32_BOOL(::RemoveDirectoryW(path.c_str()),
            L"Error deleting directory: " << path);
    }

    return directory_empty;
}

std::list<std::wstring> DVLib::GetFiles(const std::wstring& path_and_wildcard, int flags)
{
    std::wstring::size_type star_pos = path_and_wildcard.find(L"*");
    std::wstring::size_type question_pos = path_and_wildcard.find(L"?");
    std::wstring::size_type bs_pos = path_and_wildcard.rfind(L"\\");

    if (bs_pos == path_and_wildcard.npos)
    {
        // the entire path_and_wildcard is a name or a wildcard
        return GetFiles(DVLib::GetCurrentDirectoryW(), path_and_wildcard, flags);
    } 

    // the only supported wildcards are part of the file name
    // directory wildcards are not supported
    if ((star_pos != path_and_wildcard.npos && star_pos < bs_pos)
        || (question_pos != path_and_wildcard.npos && question_pos < bs_pos))
    {
        throw std::exception("wildcard in a directory name");
    }

    // split in 2, path and wildcard
    return GetFiles(
        path_and_wildcard.substr(0, bs_pos),
        path_and_wildcard.substr(bs_pos + 1),
        flags);	
}


std::list<std::wstring> DVLib::GetDirectoryFiles(const std::wstring& full_path, const std::wstring& wildcard)
{
    std::wstring path = DirectoryNormalize(full_path);
    std::list<std::wstring> result;

    WIN32_FIND_DATA data = { 0 };

    auto_hfind h(::FindFirstFileW((path + L"\\" + wildcard).c_str(), & data));

    if (get(h) != INVALID_HANDLE_VALUE)
    {
        do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            if (! (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                result.push_back(filename);
            }

        } while(::FindNextFile(get(h), & data));
    }

    switch(DWORD rc = ::GetLastError())
    {
    case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // no more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }

    return result;
}

std::list<std::wstring> DVLib::GetFiles(const std::wstring& full_path, const std::wstring& wildcard, int flags)
{
    std::wstring path = DirectoryNormalize(full_path);
    std::list<std::wstring> result;

    WIN32_FIND_DATA data = { 0 };

    auto_hfind h(::FindFirstFileW((path + L"\\*.*").c_str(), & data));

    DWORD rc = ERROR_SUCCESS;

    if (get(h) != INVALID_HANDLE_VALUE)
    {
        do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            filename = DirectoryCombine(path, filename);

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (flags & GET_FILES_DIRECTORIES)
                    result.push_back(filename);

                if (flags & GET_FILES_RECURSIVE)
                {
                    std::wstring fullsubpath = DirectoryCombine(path, data.cFileName);
                    std::list<std::wstring> files = GetFiles(fullsubpath, wildcard, flags);
                    result.splice(result.end(), files);
                }
            }

        } while(::FindNextFile(get(h), & data));
    }

    switch(rc = ::GetLastError())
    {
    case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // no more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }

    // get files matching wildcard in this directory
    if (flags & GET_FILES_FILES)
    {
        std::list<std::wstring> files = GetDirectoryFiles(path, wildcard);

        for each(const std::wstring& file in files)
        {
            result.push_back(DirectoryCombine(path, file));
        }
    }

    return result;
}

std::list<std::wstring> DVLib::GetDirectories(const std::wstring& full_path, const std::wstring& wildcard)
{
    std::wstring path = DirectoryNormalize(full_path);
    std::list<std::wstring> result;

    WIN32_FIND_DATA data = { 0 };

    auto_hfind h(::FindFirstFileW((path + L"\\" + wildcard).c_str(), &data));

    if (get(h) != INVALID_HANDLE_VALUE)
    {
        do
        {
            std::wstring filename = data.cFileName;

            if (filename == L"." || filename == L"..")
                continue;

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                result.push_back(filename);
            }

        } while (::FindNextFile(get(h), &data));
    }

    switch (DWORD rc = ::GetLastError())
    {
    case ERROR_PATH_NOT_FOUND: // directory not found in FindFirstFile
    case ERROR_FILE_NOT_FOUND: // file not found in FindFirstFile
    case ERROR_NO_MORE_FILES: // no more files in FindNextFile
        break;
    default:
        CHECK_WIN32_DWORD(rc, "Error in FindFirst/NextFile");
    }

    return result;
}