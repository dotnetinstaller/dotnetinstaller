#pragma once

struct InstallStatus;
typedef auto_any<InstallStatus *, close_delete> InstallStatusPtr;

struct InstallStatus
{
	// status properties
	std::wstring status;
	// status constructors
	static InstallStatusPtr CreateStatus(const std::wstring&);
};
