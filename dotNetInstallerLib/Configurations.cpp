#include "StdAfx.h"
#include "InstallConfiguration.h"
#include "ReferenceConfiguration.h"
#include "Configurations.h"
#include "InstallerLog.h"

Configurations::Configurations()
    : lcidtype(DVLib::LcidUserExe)
	, uilevel(InstallUILevelNotSet)
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

    uilevel = InstallUILevelSetting::ToUILevel(node->AttributeW("ui_level"));
	lcidtype = DVLib::wstring2lcidtype(node->AttributeW("lcid_type"));
	fileversion = node->AttributeW("fileversion");
	productversion = node->AttributeW("productversion");

	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
			
		if (strcmp(child_element->Value(), "configuration") == 0)
		{
			std::wstring type = child_element->AttributeW("type");
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

std::vector<ConfigurationPtr> Configurations::GetSupportedConfigurations() const
{
	std::vector<ConfigurationPtr> result;
	for each(const ConfigurationPtr& configuration in (* this))
	{
		if (configuration->IsSupported(lcidtype))
			result.push_back(configuration);
	}
	return result;
}