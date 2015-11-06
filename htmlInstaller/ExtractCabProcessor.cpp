#include "StdAfx.h"
#include "HtmlWidgets.h"
#include "ExtractCabProcessor.h"
#include "Resource.h"

ExtractCabProcessor::ExtractCabProcessor(HMODULE h, const std::wstring& id, htmlayout::dom::element * status)
: ExtractComponent(h, id)
, m_status(status)
{

}

void ExtractCabProcessor::OnStatus(const std::wstring& msg)
{
    htmlayout::queue::push(new html_set_text_task(m_status, msg), HtmlWindow::s_hwnd);
}
