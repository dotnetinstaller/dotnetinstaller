#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlLicense.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlLicense::ControlLicense()
: ControlText(control_type_license),
accepted(false)
{

}

void ControlLicense::Load(TiXmlElement * node)
{
    resource_id = node->Attribute("resource_id");
    license_file = node->Attribute("license_file");
    accept_message = node->Attribute("accept_message");
    accepted = XmlAttribute(node->Attribute("accepted")).GetBoolValue(false);
    ControlText::Load(node);
}

std::wstring ControlLicense::GetString() const
{
    std::wstringstream ss;
    ss << L"'license' control, " << ControlText::GetString();
    return ss.str();
}

ControlLicense::~ControlLicense()
{
    if (! license_file.empty() && DVLib::FileExists(license_file))
    {
        LOG("Deleting '" << license_file << L"'");
        DVLib::FileDelete(license_file);
    }
}
