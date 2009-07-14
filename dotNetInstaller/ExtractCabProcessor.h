#pragma once

class ExtractCabProcessor : public ExtractComponent
{
private:
	CDialog * m_pDialog;
public:
    ExtractCabProcessor(HMODULE h, CDialog * pDialog);
	void OnStatus(const std::wstring& status);
};

