#include "StdAfx.h"
#include "RegistryUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(RegistryUtilUnitTests);

void RegistryUtilUnitTests::testHKEY2wstring()
{
    CPPUNIT_ASSERT(DVLib::HKEY2wstring(HKEY_CLASSES_ROOT) == L"HKEY_CLASSES_ROOT");
    CPPUNIT_ASSERT(DVLib::HKEY2wstring(HKEY_LOCAL_MACHINE) == L"HKEY_LOCAL_MACHINE");
}

void RegistryUtilUnitTests::testwstring2HKEY()
{
    CPPUNIT_ASSERT(DVLib::wstring2HKEY(L"HKEY_CLASSES_ROOT") == HKEY_CLASSES_ROOT);
    CPPUNIT_ASSERT(DVLib::wstring2HKEY(L"HKEY_LOCAL_MACHINE") == HKEY_LOCAL_MACHINE);
}

void RegistryUtilUnitTests::testGetStringValue()
{
    std::wstring version = DVLib::RegistryGetStringValue(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version");
    std::wcout << std::endl << ".NET 2.0 version: " << version;
    CPPUNIT_ASSERT(DVLib::startswith(version, L"2."));
}

void RegistryUtilUnitTests::testKeyExists()
{
    CPPUNIT_ASSERT(DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727"));
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.Doesnt.Exist"));
}

void RegistryUtilUnitTests::testValueExists()
{
    CPPUNIT_ASSERT(DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version"));
    CPPUNIT_ASSERT(! DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L""));
    CPPUNIT_ASSERT(! DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"VersionDoesntExist"));
}

void RegistryUtilUnitTests::testCreateDeleteKey()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();		
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));
}

void RegistryUtilUnitTests::testSetStringValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::wstring value = L"abc";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        std::wstring regvalue = DVLib::RegistryGetStringValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(regvalue == value);
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::wstring value = L"";	
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        std::wstring regvalue = DVLib::RegistryGetStringValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(regvalue == value);
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testDeleteValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::wstring value = L"abc";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        CPPUNIT_ASSERT(DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
        DVLib::RegistryDeleteValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(! DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::wstring value = L"";
        DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, path, name, value);
        CPPUNIT_ASSERT(DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
        DVLib::RegistryDeleteValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(! DVLib::RegistryValueExists(HKEY_CURRENT_USER, path, name));
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testSetDWORDValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    std::wstring name = L"Developer";
    DWORD value = 123;
    DVLib::RegistrySetDWORDValue(HKEY_CURRENT_USER, path, name, value);
    CPPUNIT_ASSERT(value == DVLib::RegistryGetDWORDValue(HKEY_CURRENT_USER, path, name));
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testGetDWORDValue()
{
    DWORD install = DVLib::RegistryGetDWORDValue(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Install");
    std::wcout << std::endl << ".NET 2.0 install flag: " << install;
    CPPUNIT_ASSERT(1 == install);
}


void RegistryUtilUnitTests::testGetSetMultiStringValue()
{
    std::wstring path = L"SOFTWARE\\DVLib\\" + DVLib::GenerateGUIDStringW();	
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, path);
    CPPUNIT_ASSERT( DVLib::RegistryKeyExists(HKEY_CURRENT_USER, path));	
    // test non-empty value
    {
        std::wstring name = L"Developer";
        std::vector<std::wstring> value;
        value.push_back(L"abc");
        value.push_back(L"");
        value.push_back(L"bcde");
        DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, path, name, value);
        std::vector<std::wstring> regvalue = DVLib::RegistryGetMultiStringValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(regvalue.size() == value.size());
        CPPUNIT_ASSERT(regvalue[0] == value[0]);
        CPPUNIT_ASSERT(regvalue[1] == value[1]);
        CPPUNIT_ASSERT(regvalue[2] == value[2]);
    }
    // test empty value
    {
        std::wstring name = L"Blank";
        std::vector<std::wstring> value;
        DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, path, name, value);
        std::vector<std::wstring> regvalue = DVLib::RegistryGetMultiStringValue(HKEY_CURRENT_USER, path, name);
        CPPUNIT_ASSERT(regvalue.size() == 0);
    }
    // cleanup
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    CPPUNIT_ASSERT(! DVLib::RegistryKeyExists(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib"));
}

void RegistryUtilUnitTests::testGetValueType()
{
    CPPUNIT_ASSERT(REG_DWORD == DVLib::RegistryGetValueType(HKEY_LOCAL_MACHINE, 
        L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Install"));
}