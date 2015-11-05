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
    checked = XmlAttribute(node->Attribute("checked")).GetBoolValue(false);
    id = node->Attribute("id");
    checked_value = node->Attribute("checked_value");
    unchecked_value = node->Attribute("unchecked_value");
    ControlText::Load(node);
}

std::wstring ControlCheckBox::GetString() const
{
    std::wstringstream ss;
    ss << L"'checkbox' control, id=" << id << L", " << ControlText::GetString();
    return ss.str();
}
