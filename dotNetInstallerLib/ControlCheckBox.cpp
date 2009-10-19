#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlCheckBox.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlCheckBox::ControlCheckBox()
	: ControlText(control_type_checkbox)
{

}

void ControlCheckBox::Load(TiXmlElement * node)
{
	checked = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("checked")));
	id = DVLib::UTF8string2wstring(node->Attribute("id"));
	checked_value = XML_ATTRIBUTE(node->Attribute("checked_value"));
	unchecked_value = XML_ATTRIBUTE(node->Attribute("unchecked_value"));
	ControlText::Load(node);
	LOG(L"Loaded " << GetString());
}

std::wstring ControlCheckBox::GetString() const
{
	std::wstringstream ss;
	ss << L"'checkbox' control, id=" << id << L", " << ControlText::GetString();
	return ss.str();
}
