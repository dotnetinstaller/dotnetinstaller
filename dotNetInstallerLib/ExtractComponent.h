#pragma once

#include "Component.h"
#include "ThreadComponent.h"

struct ExtractComponent : public ThreadComponent
{
public:
	int status_interval;
	bool cancelled;
	std::wstring component_id;
	std::wstring cab_path;
	std::wstring cab_cancelled_message;
	// resolved location of the extracted CAB
	std::wstring resolved_cab_path;
	ExtractComponent(HMODULE h, const std::wstring& id);
	int GetCabCount() const;
	std::vector<std::wstring> GetCabFiles() const;
	static BOOL OnBeforeCopyFile(Cabinet::CExtract::kCabinetFileInfo * k_FI, void* p_Param);
	static void OnAfterCopyFile(wchar_t * s8_File, Cabinet::CMemory *, void* p_Param);
	static void OnProgressInfo(Cabinet::CExtract::kProgressInfo* pk_Progress, void* p_Param);
	// return a normalized component id
	static std::wstring GetNormalizedId(const std::wstring& id);
protected:
	int ExecOnThread();
	virtual void OnStatus(const std::wstring&) = 0;
private:
	HMODULE m_h;
	ComponentPtr m_pComponent;
    void ResolvePaths();
	void ExtractFromResource();
	// returns a setup resource name at a given index
	std::wstring GetResName(int currentIndex) const;
};
