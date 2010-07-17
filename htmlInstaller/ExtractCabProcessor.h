#pragma once

class ExtractCabProcessor : public ExtractComponent
{
private:
	htmlayout::dom::element m_status;
public:
	ExtractCabProcessor(HMODULE h, const std::wstring& id, htmlayout::dom::element status);
	void OnStatus(const std::wstring& status);
};

typedef shared_any<ExtractCabProcessor *, close_delete> ExtractCabProcessorPtr;
