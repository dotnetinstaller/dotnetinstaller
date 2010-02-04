#include "StdAfx.h"
#include "XmlAttribute.h"
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
			filename = child_element->Attribute("filename");
		}
		else if (strcmp(child_element->Value(), "downloaddialog") == 0)
		{
			auto_any<DownloadDialog *, close_delete> newdownloaddialog(
				new DownloadDialog(filename));
			newdownloaddialog->Load(child_element);
			downloaddialog = newdownloaddialog;
		}
		else
		{
			THROW_EX(L"Unexpected node '" << child_element->Value() << L"'");
		}
	}

	Configuration::Load(node);
	LOG(L"Loaded 'reference' configuration '" << filename << L"'");
}

void ReferenceConfiguration::Exec()
{
	if (get(downloaddialog))
	{
		downloaddialog->Exec();
	}
}

std::wstring ReferenceConfiguration::GetString(int indent) const
{
	std::wstringstream ss;
	for(int i = 0; i < indent; i++) ss << L" ";
	ss << L"Reference " << Configuration::GetString();
	
	if (get(downloaddialog))
	{
		ss << std::endl << downloaddialog->GetString(indent + 1);
	}

	return ss.str();
}
