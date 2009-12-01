#pragma once

class ExtractCabProcessor : public ExtractComponent
{
private:
	CDialog * m_pDialog;
public:
	ExtractCabProcessor(HMODULE h, const std::wstring& id, CDialog * pDialog);
	void OnStatus(const std::wstring& status);
};

typedef shared_any<ExtractCabProcessor *, close_delete> ExtractCabProcessorPtr;
