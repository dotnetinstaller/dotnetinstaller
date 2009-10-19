#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlBrowse.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlBrowse::ControlBrowse()
	: ControlText(control_type_browse)
{

}

void ControlBrowse::Load(TiXmlElement * node)
{
	id = DVLib::UTF8string2wstring(node->Attribute("id"));
	filter = XML_ATTRIBUTE(node->Attribute("filter"));
	button_text = XML_ATTRIBUTE(node->Attribute("button_text"));
	folders_only = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("folders_only")));
	must_exist = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("must_exist")));
	hide_readonly = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("hide_readonly")));
	allow_edit = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("allow_edit")));
	ControlText::Load(node);
	LOG(L"Loaded " << GetString());
}

std::wstring ControlBrowse::GetString() const
{
	std::wstringstream ss;
	ss << L"'browse' control, id=" << id << L", " << ControlText::GetString();
	return ss.str();
}
