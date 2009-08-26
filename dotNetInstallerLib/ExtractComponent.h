#pragma once

#include "Component.h"
#include "ThreadComponent.h"

struct ExtractComponent : public ThreadComponent, Cabinet::CExtractT<ExtractComponent> 
{
public:
	bool cancelled;
	std::wstring cab_path;
	std::wstring cab_cancelled_message;
	// resolved location of the extracted CAB
	std::wstring resolved_cab_path;
	// full path to the CAB file
	std::wstring resolved_cab_file;
    ExtractComponent(HMODULE h);
	int GetCabCount() const;
	std::vector<std::wstring> GetCabFiles() const;
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param);
	void OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param);
protected:
	int ExecOnThread();
	virtual void OnStatus(const std::wstring&) = 0;
private:
	HMODULE m_h;
	ComponentPtr m_pComponent;
    void ResolvePaths();
	void ExtractCab();
	void WriteCab();
};
