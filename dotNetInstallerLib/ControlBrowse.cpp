#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlBrowse.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlBrowse::ControlBrowse()
: ControlText(control_type_browse),
folders_only(false),
must_exist(false),
hide_readonly(false),
allow_edit(false)
{

}

void ControlBrowse::Load(TiXmlElement * node)
{
    id = node->Attribute("id");
    filter = node->Attribute("filter");
    button_text = node->Attribute("button_text");
    folders_only = XmlAttribute(node->Attribute("folders_only")).GetBoolValue(true);
    must_exist = XmlAttribute(node->Attribute("must_exist")).GetBoolValue(true);
    hide_readonly = XmlAttribute(node->Attribute("hide_readonly")).GetBoolValue(true);
    allow_edit = XmlAttribute(node->Attribute("allow_edit")).GetBoolValue(false);
    ControlText::Load(node);
}

std::wstring ControlBrowse::GetString() const
{
    std::wstringstream ss;
    ss << L"'browse' control, id=" << id << L", " << ControlText::GetString();
    return ss.str();
}
