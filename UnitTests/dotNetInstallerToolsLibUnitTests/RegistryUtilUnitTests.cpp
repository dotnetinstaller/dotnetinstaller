#include "StdAfx.h"
#include "RegistryUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void RegistryUtilUnitTests::testHKEY2wstring()
{
    Assert::IsTrue(DVLib::HKEY2wstring(HKEY_CLASSES_ROOT) == L"HKEY_CLASSES_ROOT");
    Assert::IsTrue(DVLib::HKEY2wstring(HKEY_LOCAL_MACHINE) == L"HKEY_LOCAL_MACHINE");
}

void RegistryUtilUnitTests::testwstring2HKEY()
{
    Assert::IsTrue(DVLib::wstring2HKEY(L"HKEY_CLASSES_ROOT") == HKEY_CLASSES_ROOT);
    Assert::IsTrue(DVLib::wstring2HKEY(L"HKEY_LOCAL_MACHINE") == HKEY_LOCAL_MACHINE);
}

void RegistryUtilUnitTests::testGetStringValue()
{
    std::wstring version = DVLib::RegistryGetStringValue(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version");
    std::wcout << std::endl << ".NET 2.0 version: " << version;
    Assert::IsTrue(DVLib::startswith(version, L"2."));
}

void RegistryUtilUnitTests::testKeyExists()
{
    Assert::IsTrue(DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727"));
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.Doesnt.Exist"));
}

void RegistryUtilUnitTests::testValueExists()
{
    Assert::IsTrue(DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version"));
    Assert::IsTrue(! DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L""));
    Assert::IsTrue(! DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"VersionDoesntExist"));
}

void RegistryUtilUnitTests::testCreateDeleteKey()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();		
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));
}

void RegistryUtilUnitTests::testSetStringValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::wstring value = L"abc";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        std::wstring regvalue = DVLib::RegistryGetStringValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(regvalue == value);
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::wstring value = L"";	
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        std::wstring regvalue = DVLib::RegistryGetStringValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(regvalue == value);
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testDeleteValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::wstring value = L"abc";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        Assert::IsTrue(DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
        DVLib::RegistryDeleteValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(! DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::wstring value = L"";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        Assert::IsTrue(DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
        DVLib::RegistryDeleteValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(! DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testSetDWORDValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    std::wstring name = L"Developer";
    DWORD value = 123;
    DVLib::RegistrySetDWORDValue(HKEY_CURRENT_USER, path, name, value);
    Assert::IsTrue(value == DVLib::RegistryGetDWORDValue(HKEY_CURRENT_USER, path, name));
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testGetDWORDValue()
{
    DWORD install = DVLib::RegistryGetDWORDValue(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Install");
    std::wcout << std::endl << ".NET 2.0 install flag: " << install;
    Assert::IsTrue(1 == install);
}


void RegistryUtilUnitTests::testGetSetMultiStringValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    Assert::IsTrue( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::vector<std::wstring> value;
        value.push_back(L"abc");
        value.push_back(L"");
        value.push_back(L"bcde");
        DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, path, name, value);
        std::vector<std::wstring> regvalue = DVLib::RegistryGetMultiStringValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(regvalue.size() == value.size());
        Assert::IsTrue(regvalue[0] == value[0]);
        Assert::IsTrue(regvalue[1] == value[1]);
        Assert::IsTrue(regvalue[2] == value[2]);
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::vector<std::wstring> value;
        DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, path, name, value);
        std::vector<std::wstring> regvalue = DVLib::RegistryGetMultiStringValue(HKEY_CURRENT_USER, path, name);
        Assert::IsTrue(regvalue.size() == 0);
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    Assert::IsTrue(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testGetValueType()
{
    Assert::IsTrue(REG_DWORD == DVLib::RegistryGetValueType(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Install"));
}