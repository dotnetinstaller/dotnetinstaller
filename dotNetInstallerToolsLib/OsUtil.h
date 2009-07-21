#pragma once

namespace DVLib
{
    enum LcidType
    {
        LcidUserExe = 0, // System32\user.exe lcid
        LcidSystem, // GetSystemDefaultLCID
        LcidUser // GetUserDefaultLCID
    };

	struct LcidType2wstringMapEntry
	{
		LcidType lcidtype;
		LPCWSTR name;
	};

	static const LcidType2wstringMapEntry LcidType2wstringMap[] = 
	{
		{ LcidUserExe, L"UserExe" },
		{ LcidSystem, L"System" },
		{ LcidUser, L"User" },
	};

	LcidType wstring2lcidtype(const std::wstring& name, LcidType defaultvalue = LcidUser);
	std::wstring lcidtype2wstring(LcidType lcidtype);

	enum OperatingSystem
	{
		winMin = -1,
		winNotSupported = 0,

		win95 = 5,
		win95osr2 = 10,

		win98 = 15,
		win98se = 20,

		winME = 25,

		winNT4 = 30,
		winNT4sp6 = 35,
		winNT4sp6a = 40,

		win2000 = 45,
		win2000sp1 = 50,
		win2000sp2 = 55,
		win2000sp3 = 60,
		win2000sp4 = 65, // or later

		winXP = 75,
		winXPsp1 = 80, 
		winXPsp2 = 82,
		winXPsp3 = 84, // or later

		winServer2003 = 90,
		winServer2003sp1 = 92,
		winServer2003sp2 = 94, // or later

		winVista = 100,
		winVistaSp1 = 102, 
		winVistaSp2 = 103, 

		winServer2008 = 110, // or later

		//
		// winMax must be +1 the highest configuration 
		// since IsInOperatingSystemInRange is not inclusive
		// 

		winMax = 111 
	};

	// operating system version
	OperatingSystem GetOperatingSystemVersion();
	// operating system version string
	std::wstring GetOperatingSystemVersionString();
	// true if operating system within bounds
	bool IsInOperatingSystemInRange(OperatingSystem os, const std::wstring& l, const std::wstring& r);
	// get the operating system LCID
	LCID GetOperatingSystemLCID(LcidType lcidtype);
	// does the filter match the operating system LCID
	bool IsOperatingSystemLCID(LcidType lcidtype, const std::wstring& lcid);

	struct PROCESSOR_ARCHITECTURE
	{
		LPCWSTR name;
		WORD pa;
	};

	static const PROCESSOR_ARCHITECTURE processor_architectures[] = 
	{
		{ L"x86", PROCESSOR_ARCHITECTURE_INTEL },
		{ L"mips", PROCESSOR_ARCHITECTURE_MIPS },
		{ L"alpha", PROCESSOR_ARCHITECTURE_ALPHA },
		{ L"ppc", PROCESSOR_ARCHITECTURE_PPC },
		{ L"shx", PROCESSOR_ARCHITECTURE_SHX },
		{ L"arm", PROCESSOR_ARCHITECTURE_ARM },
		{ L"ia64", PROCESSOR_ARCHITECTURE_IA64 },
		{ L"alpha64", PROCESSOR_ARCHITECTURE_ALPHA64 },
		{ L"msil", PROCESSOR_ARCHITECTURE_MSIL },
		{ L"x64", PROCESSOR_ARCHITECTURE_AMD64 },
		{ L"ia32onwin64", PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 }
	};

	// get current processor architecutre
	WORD GetProcessorArchitecture();
	// returns the numerical representation of the processor architecture
	WORD wstring2pa(const std::wstring& pa);
	// returns the string representation of the numerical processor architecture
	std::wstring pa2wstring(WORD pa);
	// does the processor architecture match the current pa
	bool IsProcessorArchitecture(WORD pa, const std::wstring& pa_list);
	// is windows-on-windows 64
	bool IsWow64();

	// reboot
	void ExitWindowsSystem(DWORD ulFlags /* = EWX_REBOOT */, DWORD ulReason = 0);
}
