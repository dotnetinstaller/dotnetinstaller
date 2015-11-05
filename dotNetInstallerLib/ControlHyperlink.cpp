#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlHyperlink.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlHyperlink::ControlHyperlink()
: ControlText(control_type_hyperlink)
{

}

void ControlHyperlink::Load(TiXmlElement * node)
{
    uri = node->Attribute("uri");
    ControlText::Load(node);
}

std::wstring ControlHyperlink::GetString() const
{
    std::wstringstream ss;
    ss << L"'hyperlink' control, uri=" << uri << L", " << ControlText::GetString();
    return ss.str();
}
