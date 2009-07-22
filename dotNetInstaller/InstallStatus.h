#pragma once

struct InstallStatus
{
	// status properties
	std::wstring status;
	// status constructors
	static auto_any<InstallStatus *, close_delete> CreateStatus(const std::wstring&);
};

typedef auto_any<InstallStatus *, close_delete> InstallStatusPtr;
