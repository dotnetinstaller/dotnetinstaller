#include "StdAfx.h"
#include "XmlAttribute.h"
#include "Control.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

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
	check = wstring2controlcheck(DVLib::UTF8string2wstring(node->Attribute("check")));
	// install checks, embed files, etc.
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;

		std::wstring type = DVLib::UTF8string2wstring(child_element->Value());
		
		if (type == L"installedcheck")
		{
			std::wstring installedcheck_type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
			InstalledCheckPtr installedcheck(InstalledCheck::Create(installedcheck_type));
			installedcheck->Load(child_element);
			installedchecks.push_back(installedcheck);
		}
		else if (type == L"installedcheckoperator")
		{
			InstalledCheckPtr installedcheckoperator(new InstalledCheckOperator());
			installedcheckoperator->Load(child_element);
			installedchecks.push_back(installedcheckoperator);
		}
		else
		{
			THROW_EX(L"Unexpected node '" << type << L"'");
		}
	}
	LOG(L"Loaded " << GetString());
}

std::wstring Control::GetString() const
{
	std::wstringstream ss;
	ss << position.ToString();
	return ss.str();
}

bool Control::IsEnabled() const
{
	if (check == control_check_enabled || check == control_check_both)
	{
		for (size_t j = 0; j < installedchecks.size(); j++)
		{
			if (! installedchecks[j]->IsInstalled())
				return false;
		}
	}

	return enabled;
}

bool Control::IsVisible() const
{
	if (InstallerSession::Instance->sequence == SequenceInstall && ! display_install)
		return false;

	if (InstallerSession::Instance->sequence == SequenceUninstall && ! display_uninstall)
		return false;

	if (check == control_check_display || check == control_check_both)
	{
		for (size_t j = 0; j < installedchecks.size(); j++)
		{
			if (! installedchecks[j]->IsInstalled())
				return false;
		}
	}

	return true;
}

control_check Control::wstring2controlcheck(const std::wstring& value)
{
	if (value == L"enabled") return control_check_enabled;
	else if (value == L"display") return control_check_display;
	else if (value == L"both") return control_check_both;
	else
	{
		THROW_EX(L"Invalid control check value '" << value << L"'");
	}
}