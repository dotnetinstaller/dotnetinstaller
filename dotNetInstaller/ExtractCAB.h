#pragma once

class ExtractCABProcessor : public ExtractComponent
{
private:
	CDialog * m_pDialog;
public:
    ExtractCABProcessor(HMODULE h, CDialog * pDialog);
	void OnStatus(const std::wstring& status);
};

