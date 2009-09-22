#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "InstallConfiguration.h"
#include "ReferenceConfiguration.h"
#include "Configurations.h"
#include "InstallerLog.h"

Configurations::Configurations()
    : lcidtype(DVLib::LcidUserExe)
	, uilevel(InstallUILevelNotSet)
    , log_enabled(false)
{

}

Configurations::~Configurations()
{
}

void Configurations::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'configurations' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "configurations"),
		L"Expected 'configurations' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    uilevel = InstallUILevelSetting::ToUILevel(DVLib::UTF8string2wstring(node->Attribute("ui_level")));
	lcidtype = DVLib::wstring2lcidtype(DVLib::UTF8string2wstring(node->Attribute("lcid_type")));
	fileversion = DVLib::UTF8string2wstring(node->Attribute("fileversion"));
	productversion = DVLib::UTF8string2wstring(node->Attribute("productversion"));
    // auto-enabled log options
    log_enabled = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("log_enabled")), false);
    log_file = XML_ATTRIBUTE(node->Attribute("log_file"));
	// language selection
	show_language_selector = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("show_language_selector")), false);;
	language_selector_title = XML_ATTRIBUTE(node->Attribute("language_selector_title"));
	language_selector_ok = XML_ATTRIBUTE(node->Attribute("language_selector_ok"));
	language_selector_cancel = XML_ATTRIBUTE(node->Attribute("language_selector_cancel"));
	// no matching configuration message
	configuration_no_match_message = DVLib::UTF8string2wstring(node->Attribute("configuration_no_match_message"));

	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
			
		if (strcmp(child_element->Value(), "configuration") == 0)
		{
			std::wstring type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
			ConfigurationPtr configuration;
			if (type == L"reference") configuration = ConfigurationPtr(new ReferenceConfiguration());
			else if (type == L"install") configuration = ConfigurationPtr(new InstallConfiguration());
			else
			{
				THROW_EX(L"Invalid configuration type '" << type << L"'");
			}

			configuration->Load(child_element);
			push_back(configuration);
		}
		else if (strcmp(child_element->Value(), "schema") == 0)
		{
			schema.Load(child_element);
		}
		else if (strcmp(child_element->Value(), "fileattributes") == 0)
		{
			fileattributes.Load(child_element);
		}
		else
		{
			THROW_EX(L"Unexpected node '" << child_element->Value() << L"'");
		}
	}

	LOG(L"--- Read " << size() << L" configuration(s)");
}

std::vector<ConfigurationPtr> Configurations::GetSupportedConfigurations(DWORD oslcid) const
{
	if (oslcid == 0) 
	{
		oslcid = DVLib::GetOperatingSystemLCID(lcidtype);
	}

	std::vector<ConfigurationPtr> result;
	for each(const ConfigurationPtr& configuration in (* this))
	{
		if (configuration->IsSupported(oslcid))
		{
			result.push_back(configuration);
		}
	}
	return result;
}

std::vector<std::wstring> Configurations::GetLanguages() const
{
	std::vector<std::wstring> languages;
	languages.reserve(size());
	for each(const ConfigurationPtr& configuration in (* this))
	{
		// \todo: make the list unique
		languages.push_back(configuration->GetLanguageString());
	}
	return languages;
}

std::wstring Configurations::GetString() const
{
	std::wstringstream ss;
	for each(const ConfigurationPtr& configuration in (* this))
	{
		ss << configuration->GetString();
	}
	return ss.str();
}