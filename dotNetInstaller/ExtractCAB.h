#pragma once

struct ExtractCABComponent;

class ExtractCABProcessor : public Cabinet::CExtractT<ExtractCABProcessor> 
{
private:
    ExtractCABComponent * m_pComponent;
public:
    ExtractCABProcessor(ExtractCABComponent * pComponent);
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param);
	void OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param);
};

struct ExtractCABComponent : public ThreadComponent
{
    friend class ExtractCABProcessor;
public:
    ExtractCABComponent(InstallConfiguration * configuration);
	static int GetCabCount(HMODULE p_Module);
	void SetDialog(CDialog * pDialog) { m_pDialog = pDialog; }
protected:
	UINT ExecOnThread();
private:
	CDialog * m_pDialog;
    InstallConfiguration * m_pConfiguration;
    void ExtractCab(HMODULE p_Module, Component * pComponent);
};


