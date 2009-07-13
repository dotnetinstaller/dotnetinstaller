#include "StdAfx.h"
#include "DownloadGroupConfiguration.h"
#include "InstallerLog.h"

DownloadGroupConfiguration::DownloadGroupConfiguration()
	: auto_start(true)
{

}

void DownloadGroupConfiguration::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'downloaddialog' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "downloaddialog"),
		L"Expected 'downloaddialog' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	caption = node->AttributeW("dialog_caption");
	help_message = node->AttributeW("dialog_message");
	downloading_message = node->AttributeW("dialog_message_downloading");
	start_caption = node->AttributeW("buttonstart_caption");
	cancel_caption = node->AttributeW("buttoncancel_caption");
	auto_start = DVLib::string2bool(node->Attribute("autostartdownload"), false);

	TiXmlNode * child = NULL;
	while ( (child = node->IterateChildren(child)) != NULL)
	{
		TiXmlElement * node_element = child->ToElement();
		if (node_element == NULL)
			continue;

		DownloadComponentInfoPtr downloadcomponentinfo(new DownloadComponentInfo());
		downloadcomponentinfo->Load(node_element);
		downloadcomponents.push_back(downloadcomponentinfo);
	}

	if (downloadcomponents.empty())
	{
		THROW_EX("Invalid  Download dialog '" << caption << L"', requires at least one download file.");
	}

	LOG(L"Loaded 'download' configuration '" << caption << L"' with " << downloadcomponents.size() << " file(s)");
}

DownloadGroupConfiguration::~DownloadGroupConfiguration()
{
}