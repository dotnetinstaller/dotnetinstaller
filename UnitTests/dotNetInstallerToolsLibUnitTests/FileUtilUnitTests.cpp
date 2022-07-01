#include "StdAfx.h"
#include "FileUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FileUtilUnitTests::testFileExists()
{
    std::string path = DVLib::GetTemporaryFileNameA();
    std::cout << std::endl << "Temporary filename: " << path;

    std::string directory = DVLib::GetFileDirectoryA(path);
    std::cout << std::endl << "Directory: " << directory;

    Assert::IsTrue(! DVLib::FileExists(directory));
    Assert::IsTrue(DVLib::FileExists(path));
    DVLib::FileDelete(path);

    Assert::IsTrue(! DVLib::FileExists("C:\\"));	
    Assert::IsTrue(! DVLib::FileExists(""));

    std::string filename = DVLib::GenerateGUIDStringA();
    std::string guidpath = "C:\\" + filename;
    std::cout << std::endl << "Guid path: " << guidpath;
    Assert::IsTrue(! DVLib::FileExists(guidpath));
}

void FileUtilUnitTests::testGetTemporaryFileName()
{
    std::string path = DVLib::GetTemporaryFileNameA();
    std::cout << std::endl << "Temporary filename: " << path;
    std::string directory = DVLib::GetFileDirectoryA(path);
    std::cout << std::endl << "Directory: " << directory;
    Assert::IsTrue(directory.length() > 0);
    std::string filename = DVLib::GetFileNameA(path);
    std::cout << std::endl << "File: " << filename;
    Assert::IsTrue(filename.length() > 0);
    std::stringstream s_path;
    s_path << directory << filename;
    std::cout << std::endl << "Joined directory: " << s_path.str();
    Assert::IsTrue(path == s_path.str());
    Assert::IsTrue(DVLib::FileExists(path));
    DVLib::FileDelete(path);
    Assert::IsTrue(! DVLib::FileExists(path));
}

void FileUtilUnitTests::testFileDelete()
{
    std::string path = DVLib::GetTemporaryFileNameA();
    std::cout << std::endl << "Temporary filename: " << path;
    Assert::IsTrue(DVLib::FileExists(path));
    Assert::IsTrue(::PathFileExistsA(path.c_str()));
    DVLib::FileDelete(path);
    Assert::IsTrue(! DVLib::FileExists(path));
    Assert::IsTrue(FALSE == ::PathFileExistsA(path.c_str()));
}

void FileUtilUnitTests::testFileCopy()
{
    std::string path = DVLib::GetTemporaryFileNameA();
    std::cout << std::endl << "Temporary filename: " << path;
    Assert::IsTrue(DVLib::FileExists(path));
    std::string path_copy = path + ".copy";
    Assert::IsTrue(! DVLib::FileExists(path_copy));
    DVLib::FileCopy(path, path_copy, true);
    Assert::IsTrue(DVLib::FileExists(path_copy));
    DVLib::FileDelete(path);
    DVLib::FileDelete(path_copy);
}

void FileUtilUnitTests::testFileMove()
{
    std::string path = DVLib::GetTemporaryFileNameA();
    std::cout << std::endl << "Temporary filename: " << path;
    Assert::IsTrue(DVLib::FileExists(path));
    std::string path_copy = path + ".move";
    Assert::IsTrue(! DVLib::FileExists(path_copy));
    DVLib::FileMove(path, path_copy);
    Assert::IsTrue(! DVLib::FileExists(path));
    Assert::IsTrue(DVLib::FileExists(path_copy));
    DVLib::FileDelete(path_copy);
}

void FileUtilUnitTests::testGetFileSize()
{
    std::wstring moduledir = DVLib::GetModuleDirectoryW();
    std::list<std::wstring> files = DVLib::GetFiles(moduledir, L"*.xml", DVLib::GET_FILES_FILES | DVLib::GET_FILES_RECURSIVE);
    for each (const std::wstring& file in files)
    {
        long size = DVLib::GetFileSize(file);
        std::wcout << std::endl << L" " << file << L": " << DVLib::towstring(size) << L" byte(s)";
        Assert::IsTrue(size >= 0);
    }
}

void FileUtilUnitTests::testFileWrite()
{
    std::wstring tmpfile = DVLib::DirectoryCombine(
        DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    std::wcout << std::endl << L"Temporary filename: " << tmpfile;
    // empty data
    std::vector<char> write_data;
    DVLib::FileWrite(tmpfile, write_data);
    std::vector<char> read_data = DVLib::FileReadToEnd(tmpfile);
    Assert::IsTrue(read_data.size() == 0); // temporary files are created empty
    // some data
    std::string write_guid = DVLib::GenerateGUIDStringA();
    std::cout << std::endl << "Write GUID: " << write_guid;
    std::vector<char> write_guid_vector(write_guid.begin(), write_guid.end());
    DVLib::FileWrite(tmpfile, write_guid_vector);
    std::vector<char> read_guid = DVLib::FileReadToEnd(tmpfile);
    std::wcout << std::endl << L"Size: " << read_guid.size();    
    Assert::IsTrue(read_guid.size() > 0);
    Assert::IsTrue(static_cast<long>(read_guid.size()) == DVLib::GetFileSize(tmpfile));
    std::string read_guid_string(read_guid.begin(), read_guid.end());
    std::cout << std::endl << "Read GUID: " << read_guid_string;
    Assert::IsTrue(write_guid == read_guid_string);
    // delete temp file
    DVLib::FileDelete(tmpfile);
}

void FileUtilUnitTests::testFileCreate()
{
    std::wstring tmpfile = DVLib::DirectoryCombine(
        DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    std::wcout << std::endl << L"Temporary filename: " << tmpfile;
    Assert::IsTrue(! DVLib::FileExists(tmpfile));
    // create the file
    DVLib::FileCreate(tmpfile);
    Assert::IsTrue(DVLib::GetFileSize(tmpfile) == 0);
    // populate the temp file with data, then re-create, ensure that it is empty
    std::vector<char> data;
    data.push_back('x');
    DVLib::FileWrite(tmpfile, data);
    Assert::IsTrue(DVLib::GetFileSize(tmpfile) == 1);
    DVLib::FileCreate(tmpfile);
    Assert::IsTrue(DVLib::FileExists(tmpfile));
    Assert::IsTrue(DVLib::GetFileSize(tmpfile) == 0);
    DVLib::FileDelete(tmpfile);
}

void FileUtilUnitTests::testFileReadToEnd()
{
    std::wstring tmpfile = DVLib::GetTemporaryFileNameW();
    std::wcout << std::endl << L"Temporary filename: " << tmpfile;
    Assert::IsTrue(DVLib::FileExists(tmpfile));
    std::vector<char> data = DVLib::FileReadToEnd(tmpfile);
    Assert::IsTrue(data.size() == 0); // temporary files are created empty
    // ansi data
    std::string guid = DVLib::GenerateGUIDStringA();
    std::ofstream f(DVLib::wstring2string(tmpfile).c_str());
    f << guid.c_str();
    f.close();
    // read as byte data
    std::vector<char> guiddata = DVLib::FileReadToEnd(tmpfile);
    std::wcout << std::endl << L"Size: " << guiddata.size();    
    Assert::IsTrue(guiddata.size() > 0);
    Assert::IsTrue(static_cast<long>(guiddata.size()) == DVLib::GetFileSize(tmpfile));
    // delete temp file
    DVLib::FileDelete(tmpfile);
}

void FileUtilUnitTests::testGetFileVersionInfo()
{
    std::wstring userexepath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"user.exe");
    DVLib::FileVersionInfo versioninfo = DVLib::GetFileVersionInfo(userexepath);
    std::wcout << std::endl << L"user.exe version: " 
        << HIWORD(versioninfo.fixed_info.dwFileVersionMS) << L"."
        << LOWORD(versioninfo.fixed_info.dwFileVersionMS) << L"."
        << HIWORD(versioninfo.fixed_info.dwFileVersionLS) << L"."
        << LOWORD(versioninfo.fixed_info.dwFileVersionLS);
    Assert::IsTrue(versioninfo.fixed_info.dwFileVersionMS > 0);
    std::wcout << std::endl << L"user.exe cp/language: "
        << versioninfo.translation_info.wCodePage << L":" << versioninfo.translation_info.wLanguage;
    Assert::IsTrue(versioninfo.translation_info.wCodePage > 256);
    Assert::IsTrue(versioninfo.translation_info.wLanguage > 256);
}

void FileUtilUnitTests::testGetFileVersion()
{
    std::wstring userexepath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"user.exe");
    std::wstring version = DVLib::GetFileVersion(userexepath);
    Assert::IsTrue(version.length());
    Assert::IsTrue(DVLib::split(version, L".").size() == 4);	
}

void FileUtilUnitTests::testLoadResourceData()
{
    std::vector<char> data = DVLib::LoadResourceData<char>(GetCurrentModuleHandle(), L"RES_TEST", L"CUSTOM");
    Assert::IsTrue(data.size() == 3390);
}

void FileUtilUnitTests::testResourceExists()
{
    HMODULE hm = GetCurrentModuleHandle();
    Assert::IsTrue(DVLib::ResourceExists(hm, L"RES_TEST", L"CUSTOM"));
    Assert::IsTrue(! DVLib::ResourceExists(hm, L"RES_TEST", L"TypeDoesntExist"));
    Assert::IsTrue(! DVLib::ResourceExists(hm, L"ResourceDoesntExist", L"CUSTOM"));
}