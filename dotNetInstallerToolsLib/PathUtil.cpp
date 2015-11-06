#include "StdAfx.h"
#include "PathUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"

std::string DVLib::GetFileDirectoryA(const std::string& path)
{
    if (DVLib::startswith(path, "file://"))
        return "file://" + GetFileDirectoryA(path.substr(ARRAYSIZE("file://") - 1));

    int backslashPos = path.rfind('\\', path.length());
    if (backslashPos == path.npos) backslashPos = path.rfind('/', path.length());
    if (backslashPos == path.npos)
        return "";

    return path.substr(0, backslashPos + 1);
}

std::wstring DVLib::GetFileDirectoryW(const std::wstring& path)
{
    if (DVLib::startswith(path, L"file://"))
        return L"file://" + GetFileDirectoryW(path.substr(ARRAYSIZE(L"file://") - 1));

    std::wstring::size_type backslashPos = path.rfind(L'\\', path.length());
    if (backslashPos == path.npos) backslashPos = path.rfind(L'/', path.length());
    if (backslashPos == path.npos)
        return L"";

    return path.substr(0, backslashPos + 1);
}

std::string DVLib::GetFileNameA(const std::string& path)
{
    int backslashPos = path.rfind('\\', path.length());
    if (backslashPos == path.npos) backslashPos = path.rfind('/', path.length());
    if (backslashPos == path.npos)
        return path;

    return path.substr(backslashPos + 1, path.length() - backslashPos - 1);
}

std::wstring DVLib::GetFileNameW(const std::wstring& path)
{
    std::wstring::size_type backslashPos = path.rfind(L'\\', path.length());
    if (backslashPos == path.npos) backslashPos = path.rfind(L'/', path.length());
    if (backslashPos == path.npos)
        return path;

    return path.substr(backslashPos + 1, path.length() - backslashPos - 1);
}

std::string DVLib::GetModuleDirectoryA()
{
    return GetFileDirectoryA(GetModuleFileNameA());
}

std::wstring DVLib::GetModuleDirectoryW()
{
    return GetFileDirectoryW(GetModuleFileNameW());
}

std::string DVLib::GetModuleFileNameA(HINSTANCE h)
{
    char moduleFileName[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetModuleFileNameA(h, moduleFileName, MAX_PATH),
        L"GetModuleFileNameA");
    return moduleFileName;
}

std::wstring DVLib::GetModuleFileNameW(HINSTANCE h)
{
    wchar_t moduleFileName[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetModuleFileNameW(h, moduleFileName, MAX_PATH),
        L"GetModuleFileNameW");
    return moduleFileName;
}

std::wstring DVLib::DirectoryCombine(const std::wstring& dir, const std::wstring& file)
{
    wchar_t buffer[MAX_PATH] = { 0 };
    CHECK_BOOL(NULL != ::PathCombineW(buffer, dir.length() ? dir.c_str() : NULL, file.length() ? file.c_str() : NULL),
        L"Error combining \"" << dir << "\" and \"" << file << "\"");
    return buffer;
}

std::string DVLib::GetTemporaryDirectoryA()
{
    char td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(GetTempPathA(MAX_PATH, td),
        L"GetTempPathA");

    return td;
}

std::wstring DVLib::GetTemporaryDirectoryW()
{
    wchar_t td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetTempPathW(MAX_PATH, td),
        "GetTempPathW");

    return td;
}

std::string DVLib::GetCurrentDirectoryA()
{
    char result[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(0 < ::GetCurrentDirectoryA(MAX_PATH, result),
        L"Error in GetCurrentDirectoryA");
    return result;
}

std::wstring DVLib::GetCurrentDirectoryW()
{
    wchar_t result[MAX_PATH];
    CHECK_WIN32_BOOL(0 < ::GetCurrentDirectoryW(MAX_PATH, result),
        L"Error in GetCurrentDirectoryW");
    return result;
}

std::string DVLib::GetSystemDirectoryA()
{
    char td[MAX_PATH];	
    CHECK_WIN32_BOOL(::GetSystemDirectoryA(td, MAX_PATH),
        L"GetSystemDirectoryA");
    return td;
}

std::wstring DVLib::GetSystemDirectoryW()
{
    wchar_t td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetSystemDirectoryW(td, MAX_PATH),
        L"GetSystemDirectoryW");
    return td;
}

std::string DVLib::GetWindowsDirectoryA()
{
    char td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetWindowsDirectoryA(td, MAX_PATH),
        L"GetWindowsDirectoryA");
    return td;
}

std::wstring DVLib::GetWindowsDirectoryW()
{
    wchar_t td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetWindowsDirectoryW(td, MAX_PATH),
        L"GetWindowsDirectoryW");
    return td;
}

std::string DVLib::GetSystemWindowsDirectoryA()
{
    return DVLib::wstring2string(GetSystemWindowsDirectoryW());
}

std::wstring DVLib::GetSystemWindowsDirectoryW()
{
    wchar_t td[MAX_PATH] = { 0 };
    CHECK_WIN32_BOOL(::GetSystemWindowsDirectoryW(td, MAX_PATH),
        L"GetSystemWindowsDirectoryW");
    return td;
}

std::wstring DVLib::StripPathTerminator(const std::wstring& path)
{
    std::wstring result = DVLib::trimright(path, L" \t\n\r\\/");
    if (result.length() == 2 && result[1] == L':') result += L"\\";
    return result;
}
