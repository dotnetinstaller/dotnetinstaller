#include "StdAfx.h"
#include "ExtractCabProcessor.h"
#include "Resource.h"

ExtractCabProcessor::ExtractCabProcessor(HMODULE h, const std::wstring& id, htmlayout::dom::element status)
    : ExtractComponent(h, id)
	, m_status(status)
{

}

void ExtractCabProcessor::OnStatus(const std::wstring& status)
{
	if (m_status.is_valid())
	{
		m_status.set_text(status.c_str());
	}
}
