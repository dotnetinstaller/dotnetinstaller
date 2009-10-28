#include "StdAfx.h"
#include "XmlAttribute.h"
#include "Control.h"

Control::Control(control_type t)
	: type(t)
{

}

Control::~Control(void)
{
}

void Control::Load(TiXmlElement * node)
{
	position.FromString(DVLib::UTF8string2wstring(node->Attribute("position")));
	enabled = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("enabled")));
	display_install = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("display_install")));
	display_uninstall = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("display_uninstall")));
}

std::wstring Control::GetString() const
{
	std::wstringstream ss;
	ss << position.ToString();
	return ss.str();
}
