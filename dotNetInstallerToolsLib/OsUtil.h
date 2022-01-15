#pragma once

namespace DVLib
{
    enum LcidType
    {
        LcidUserExe = 0, // System32\user.exe lcid
        LcidSystem, // GetSystemDefaultLCID
        LcidUser, // GetUserDefaultLCID
		LcidMuiSystem, // GetSystemDefaultUILanguage
		LcidMuiUser, // GetUserDefaultUILanguage		
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
		{ LcidMuiSystem, L"MuiSystem" },
		{ LcidMuiUser, L"MuiUser" },
	};

	LcidType wstring2lcidtype(const std::wstring& name, LcidType defaultvalue = LcidUser);
	std::wstring lcidtype2wstring(LcidType lcidtype);

	enum OperatingSystem
	{
		winNone = -1,

		winXP = 75,
		winXPsp1 = 80, 
		winXPsp2 = 82,
		winXPsp3 = 84,
		winXPMax = 89,

		winServer2003 = 90,
		winServer2003R2 = 91,
		winServer2003sp1 = 92,
		winServer2003R2sp1 = 93,
		winServer2003sp2 = 94,
		winServer2003R2sp2 = 95,
		winServer2003Max = 99,

		winVista = 100,
		winVistaSp1 = 102, 
		winVistaSp2 = 103, 
		winVistaMax = 109,

		winServer2008 = 110,
		winServer2008sp2 = 111,
		winServer2008R2 = 112,
		winServer2008R2sp1 = 113,
		winServer2008Max = 119,

		win7 = 120,
		win7sp1 = 121,
		win7Max = 129,

		win8 = 130,
		win8_1 = 131,
		win8Max = 139,
		
		win8Server = 140, // Windows Server 2012
		win8ServerR2 = 141, // Windows Server 2012 R2
		win8ServerMax = 149,

		win10 = 150, // build 1507
		win10_1511 = 151,
		win10_1607 = 152,
		win10_1703 = 153,
		win10_1709 = 154,
		win10_1803 = 155,
		win10_1809 = 156,
		win10_1903 = 157,
		win10_1909 = 158,
		win10_2004 = 159,
		win10_20H2 = 160,
		win10_21H1 = 161,
		win10_21H2 = 162,
		win10Max = 169,

		win10Server = 170, // Windows Server 2016
		win10ServerMax = 179,

		winServer2019 = 180,
		winServer2019Max = 189,

		winServer2022 = 190,
		winServer2022Max = 199,

		win11 = 200,
		win11Max = 209,

		winMax = 255, // This value should always be last
	};

	struct Os2StringMapEntry
	{
		OperatingSystem os;
		LPCWSTR oscode;
		LPCWSTR name;
	};

	static const Os2StringMapEntry Os2StringMap[] =
	{
		{ winXP, L"winXP", L"Windows XP" },
		{ winXPsp1, L"winXPsp1", L"Windows XP SP1" },
		{ winXPsp2, L"winXPsp2", L"Windows XP SP2" },
		{ winXPsp3, L"winXPsp3", L"Windows XP SP3" },
		{ winXPMax, L"winXPMax", L"Windows XP+" },
		{ winServer2003, L"winServer2003", L"Windows Server 2003" },
		{ winServer2003sp1, L"winServer2003sp1", L"Windows Server 2003 SP1" },
		{ winServer2003sp2, L"winServer2003sp2", L"Windows Server 2003 SP2" },
		{ winServer2003R2, L"winServer2003R2", L"Windows Server 2003 R2" },
		{ winServer2003R2sp1, L"winServer2003R2sp1", L"Windows Server 2003 R2 SP1" },
		{ winServer2003R2sp2, L"winServer2003R2sp2", L"Windows Server 2003 R2 SP2" },
		{ winServer2003Max, L"winServer2003Max", L"Windows Server 2003+" },
		{ winServer2008, L"winServer2008", L"Windows Server 2008" },
		{ winServer2008sp2, L"winServer2008sp2", L"Windows Server 2008 SP2" },
		{ winServer2008R2, L"winServer2008R2", L"Windows Server 2008 R2" },
		{ winServer2008R2sp1, L"winServer2008R2sp1", L"Windows Server 2008 R2 SP1" },
		{ winServer2008Max, L"winServer2008Max", L"Windows Server 2008+" },
		{ winVista, L"winVista", L"Windows Vista" },
		{ winVistaSp1, L"winVistaSp1", L"Windows Vista SP1" },
		{ winVistaSp2, L"winVistaSp2", L"Windows Vista SP2" },
		{ winVistaMax, L"winVistaMax", L"Windows Vista+" },
		{ win7, L"win7", L"Windows 7" },
		{ win7sp1, L"win7sp1", L"Windows 7 SP1" },
		{ win7Max, L"win7Max", L"Windows 7+" },
		{ win8, L"win8", L"Windows 8" },
		{ win8_1, L"win8_1", L"Windows 8.1" },
		{ win8Max, L"win8Max", L"Windows 8+" },
		{ win8Server, L"win8Server", L"Windows Server 2012" },
		{ win8ServerR2, L"win8ServerR2", L"Windows Server 2012 R2" },
		{ win8ServerMax, L"win8ServerMax", L"Windows Server 2012+" },
		{ win10, L"win10", L"Windows 10" },
		{ win10_1511, L"win10_1511", L"Windows 10 Version 1511" },
		{ win10_1607, L"win10_1607", L"Windows 10 Version 1607" },
		{ win10_1703, L"win10_1703", L"Windows 10 Version 1703" },
		{ win10_1709, L"win10_1709", L"Windows 10 Version 1709" },
		{ win10_1803, L"win10_1803", L"Windows 10 Version 1803" },
		{ win10_1809, L"win10_1809", L"Windows 10 Version 1809" },
		{ win10_1903, L"win10_1903", L"Windows 10 Version 1903" },
		{ win10_1909, L"win10_1909", L"Windows 10 Version 1909" },
		{ win10_2004, L"win10_2004", L"Windows 10 Version 2004" },
		{ win10_20H2, L"win10_20H2", L"Windows 10 Version 20H2" },
		{ win10_21H1, L"win10_21H1", L"Windows 10 Version 21H1" },
		{ win10_21H2, L"win10_21H2", L"Windows 10 Version 21H2" },
		{ win10Max, L"win10Max", L"Windows 10+" },
		{ win10Server, L"win10Server", L"Windows Server 2016" },
		{ win10ServerMax, L"win10ServerMax", L"Windows Server 2016+" },
		{ winServer2019, L"winServer2019", L"Windows Server 2019" },
		{ winServer2019Max, L"winServer2019Max", L"Windows Server 2019+" },
		{ winServer2022, L"winServer2022", L"Windows Server 2022" },
		{ winServer2022Max, L"winServer2022Max", L"Windows Server 2022+" },
		{ win11, L"win11", L"Windows 11" },
		{ win11Max, L"win11Max", L"Windows 11+" },
		{ winMax, L"winMax", L"Windows Latest" },
	};

	// operating system version
	OperatingSystem GetOperatingSystemVersion();
	// operating system version string
	std::wstring GetOperatingSystemVersionString();
	std::wstring os2wstring(OperatingSystem os);
	OperatingSystem oscode2os(const std::wstring& oscode);
	// true if operating system within bounds
	bool IsOperatingSystemID(OperatingSystem os, const std::wstring& os_filter);
	bool IsInOperatingSystemInRange(OperatingSystem os, const std::wstring& os_filter, 
		OperatingSystem l, OperatingSystem r);

	// operating system product type

	enum OperatingSystemProductType
	{
		osNone = -1,

		Workstation = 1,
		DomainController = 2,
		Server = 3
	};

	OperatingSystemProductType GetOperatingSystemProductType();
	bool IsOperatingSystemProductType(BYTE osProductType_in, const std::wstring& filter);
	WORD wstring2osType(const std::wstring& osProductType);

	struct OPERATING_SYSTEM_PRODUCT_TYPE
	{
		LPCWSTR name;
		BYTE productType;
	};

	static const OPERATING_SYSTEM_PRODUCT_TYPE operating_system_product_types[] =
	{
		{ L"workstation", VER_NT_WORKSTATION },
		{ L"server", VER_NT_SERVER },
		{ L"domainController", VER_NT_DOMAIN_CONTROLLER },
	};

	// get the operating system LCID
	LCID GetOperatingSystemLCID(LcidType lcidtype);
	std::wstring GetLocale(LCID lcid, int format = LOCALE_SISO639LANGNAME);
	std::wstring GetISOLocale(LCID lcid);
	// does the filter match a system LCID
	bool IsOperatingSystemLCID(LcidType lcidtype, const std::wstring& lcid);
	// does the filter match the operating system LCID
	bool IsOperatingSystemLCIDValue(LCID lcidtype, const std::wstring& lcid);
	bool IsOperatingSystemID(OperatingSystem os, const std::wstring& id);
	OperatingSystem OperatingSystemType(OperatingSystem os);

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

	// get current processor architecture
	WORD GetProcessorArchitecture();
	// returns the numerical representation of the processor architecture
	WORD wstring2pa(const std::wstring& pa);
	// returns the string representation of the numerical processor architecture
	std::wstring pa2wstring(WORD pa);
	// does the processor architecture match the current pa
	bool IsProcessorArchitecture(WORD pa, const std::wstring& pa_list);
	// is windows-on-windows 64
	bool IsWow64();
	// disables file system redirection for the calling thread on x64 systems
	bool Wow64DisableWow64FsRedirection(LPVOID * old_value);
	// restores file system redirection for the calling thread on x64 systems
	bool Wow64RevertWow64FsRedirection(LPVOID old_value);
	// reboot
	void ExitWindowsSystem(DWORD ulFlags /* = EWX_REBOOT */, DWORD ulReason = 0);
	// mui
	LCID MuiGetSystemDefaultUILCID();
	LCID MuiGetUserDefaultUILCID();
}
