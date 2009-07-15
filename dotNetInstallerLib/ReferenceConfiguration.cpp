#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerLog.h"
#include "ReferenceConfiguration.h"
#include "InstallerSession.h"

ReferenceConfiguration::ReferenceConfiguration()
	: Configuration(configuration_reference)
{

}

ReferenceConfiguration::~ReferenceConfiguration()
{

}

void ReferenceConfiguration::Load(TiXmlElement * node)
{
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
		
		if (strcmp(child_element->Value(), "configfile") == 0)
		{
			filename = InstallerSession::MakePath(child_element->AttributeW("filename"));
		}
		else if (strcmp(child_element->Value(), "downloaddialog") == 0)
		{
			auto_any<DownloadGroupConfiguration *, close_delete> d(new DownloadGroupConfiguration());
			d->Load(child_element);
			downloadconfiguration = d;
		}
		else
		{
			THROW_EX(L"Unexpected node '" << child_element->Value() << L"'");
		}
	}

	Configuration::Load(node);
	LOG(L"Loaded 'reference' configuration '" << filename << L"'");
}
