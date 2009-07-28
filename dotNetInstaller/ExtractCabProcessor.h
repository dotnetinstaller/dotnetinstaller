#pragma once

class ExtractCabProcessor : public ExtractComponent
{
private:
	CDialog * m_pDialog;
public:
    std::wstring cab_cancelled_message;
    std::wstring cab_path;
	std::wstring description;
public:
    ExtractCabProcessor(HMODULE h, CDialog * pDialog);
	void OnStatus(const std::wstring& status);
};

typedef shared_any<ExtractCabProcessor *, close_delete> ExtractCabProcessorPtr;
