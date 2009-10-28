#pragma once
#include "ProcessComponent.h"

class CmdComponent : public ProcessComponent
{
public:
    CmdComponent();
public:
	std::wstring command;
    std::wstring command_silent;
	std::wstring command_basic;
	std::wstring uninstall_command;
    std::wstring uninstall_command_silent;
	std::wstring uninstall_command_basic;
	// return codes
	std::wstring returncodes_reboot;
	std::wstring returncodes_failure;
	void Exec();
	void Load(TiXmlElement * node);
	void Wait(DWORD tt = 1000);
	bool IsRebootRequired() const;
private:
	// functions that indicate whether a return code falls into a certain category
	virtual bool IsReturnCodeFailure(DWORD exitcode) const;
	virtual bool IsReturnCodeReboot(DWORD exitcode) const;
	static bool IsReturnCode(DWORD return_code, const std::wstring& possible_values);
};

typedef shared_any<CmdComponent *, close_delete> CmdComponentPtr;
