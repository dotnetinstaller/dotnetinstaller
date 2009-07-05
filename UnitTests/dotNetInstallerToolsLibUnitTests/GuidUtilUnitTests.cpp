#include "StdAfx.h"
#include "GuidUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(GuidUtilUnitTests);

void GuidUtilUnitTests::testStringFromGUID2()
{
	typedef struct
	{
		LPCWSTR pszGuid;
		GUID clsid;
	} TestData;

	TestData data[] = 
	{
		L"{13709620-C279-11CE-A49E-444553540000}", { 0x13709620, 0xC279, 0x11CE, { 0xA4, 0x9E, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } }, // "Shell.Application.1"
		L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}", { 0xEAB22AC3, 0x30C1, 0x11CF, { 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B } }, // "Shell.Explorer.1"
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << data[i].pszGuid;
		
		std::wstring wstring_fromguid2 = DVLib::StringFromGUID2W(data[i].clsid);
		std::string string_fromguid2 = DVLib::StringFromGUID2A(data[i].clsid);
		CPPUNIT_ASSERT(wstring_fromguid2 == data[i].pszGuid);
		CPPUNIT_ASSERT(wstring_fromguid2 == DVLib::string2wstring(string_fromguid2));
	}
}

void GuidUtilUnitTests::testGenerateGUIDString()
{
	std::wstring wstring_guid = DVLib::GenerateGUIDStringW();
	std::wcout << std::endl << wstring_guid;
	std::string string_guid = DVLib::GenerateGUIDStringA();
	std::cout << std::endl << string_guid;
	CPPUNIT_ASSERT(wstring_guid != DVLib::string2wstring(string_guid));
	CPPUNIT_ASSERT(wstring_guid.length() == string_guid.length());
	CPPUNIT_ASSERT(wstring_guid.length() == 38);
	for (int i = 0; i < wstring_guid.length(); i++)
	{
		switch(i)
		{
		case 0:
			CPPUNIT_ASSERT(wstring_guid[i] == L'{');
			break;
		case 37:
			CPPUNIT_ASSERT(wstring_guid[i] == L'}');
			break;
		case 9:
		case 14:
		case 19:
		case 24:
			CPPUNIT_ASSERT(wstring_guid[i] == L'-');
			break;
		default:
			CPPUNIT_ASSERT(::isalnum(wstring_guid[i]));
			break;
		}
	}
}
