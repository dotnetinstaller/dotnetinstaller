#pragma once

#include "ThreadComponent.h"

struct ExtractComponent : public ThreadComponent, Cabinet::CExtractT<ExtractComponent> 
{
public:
	std::wstring cab_path;
	std::wstring cab_cancelled_message;
    ExtractComponent(HMODULE h);
	int GetCabCount() const;
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param);
	void OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param);
protected:
	UINT ExecOnThread();
	virtual void OnStatus(const std::wstring&) = 0;
private:
	HMODULE m_h;
	ComponentPtr m_pComponent;
    void ExtractCab();
};
