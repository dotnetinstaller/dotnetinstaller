#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlLicense.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlLicense::ControlLicense()
	: ControlText(control_type_license)
{

}

void ControlLicense::Load(TiXmlElement * node)
{
	resource_id = XML_ATTRIBUTE(node->Attribute("resource_id"));
	license_file = XML_ATTRIBUTE(node->Attribute("license_file"));
	accept_message = XML_ATTRIBUTE(node->Attribute("accept_message"));
	accepted = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("accepted")));
	ControlText::Load(node);
	LOG(L"Loaded " << GetString());
}

std::wstring ControlLicense::GetString() const
{
	std::wstringstream ss;
	ss << L"'license' control, " << ControlText::GetString();
	return ss.str();
}
