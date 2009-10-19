#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlText.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlText::ControlText(control_type type)
	: Control(type)
{

}

void ControlText::Load(TiXmlElement * node)
{
	text = XML_ATTRIBUTE(node->Attribute("text"));
	font_name = XML_ATTRIBUTE(node->Attribute("font_name"));
	font_size = DVLib::wstring2long(XML_ATTRIBUTE(node->Attribute("font_size")));
	Control::Load(node);
}

std::wstring ControlText::GetString() const
{
	std::wstringstream ss;
	ss << L"text='" << text << L"', font=" << font_name << L" (" << font_size << L" pt.), " << Control::GetString(); 
	return ss.str();
}
