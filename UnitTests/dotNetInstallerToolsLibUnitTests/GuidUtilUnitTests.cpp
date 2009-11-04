#include "StdAfx.h"
#include "GuidUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(GuidUtilUnitTests);

void GuidUtilUnitTests::testguid2wstring()
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
		L"13709620-C279-11CE-A49E-444553540000", { 0x13709620, 0xC279, 0x11CE, { 0xA4, 0x9E, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } }, // "Shell.Application.1"
		L"EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B", { 0xEAB22AC3, 0x30C1, 0x11CF, { 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B } }, // "Shell.Explorer.1"
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << data[i].pszGuid;
		
		std::wstring wstring_fromguid2 = DVLib::guid2wstring(data[i].clsid);
		std::string string_fromguid2 = DVLib::guid2string(data[i].clsid);
		CPPUNIT_ASSERT(wstring_fromguid2 == DVLib::makeguid(data[i].pszGuid));
		CPPUNIT_ASSERT(wstring_fromguid2 == DVLib::string2wstring(string_fromguid2));
		CPPUNIT_ASSERT(DVLib::string2guid(data[i].pszGuid) == data[i].clsid);
	}
}

void GuidUtilUnitTests::testisguid()
{
	typedef struct
	{
		LPCWSTR pszGuid;
		bool guid;
	} TestData;

	TestData data[] = 
	{
		{ L"", false },
		{ L"00000000", false },
		{ L"abracadabra", false },
		{ L"EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B", true },
		{ L"{13709620-C279-11CE-A49E-444553540000}", true },		
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << L"Guid?: " << data[i].pszGuid;
		CPPUNIT_ASSERT(DVLib::isguid(data[i].pszGuid) == data[i].guid);
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
	for (unsigned int i = 0; i < wstring_guid.length(); i++)
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

void GuidUtilUnitTests::testmakeguid()
{
	typedef struct
	{
		LPCWSTR input;
		LPCWSTR expected_output;
	} TestData;

	TestData data[] = 
	{
		{ L"", L"" },
		{ L"a", L"{a}" },
		{ L"{a", L"{a}" },
		{ L"a}", L"{a}" },
		{ L"{a}", L"{a}" },
		{ L"{{a}}", L"{{a}}" },
		{ L"abracadabra", L"{abracadabra}" },
		{ L"EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B", L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}" },
		{ L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B", L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}" },
		{ L"EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}", L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}" },
		{ L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}", L"{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}" },
	};

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::wcout << std::endl << L"MakeGuid: " << data[i].input;
		CPPUNIT_ASSERT(DVLib::makeguid(data[i].input) == data[i].expected_output);
	}
}