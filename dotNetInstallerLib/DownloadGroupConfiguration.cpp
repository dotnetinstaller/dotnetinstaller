#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "DownloadGroupConfiguration.h"
#include "DownloadComponents.h"
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

	caption = XML_ATTRIBUTE(node->Attribute("dialog_caption"));
	help_message = XML_ATTRIBUTE(node->Attribute("dialog_message"));
	downloading_message = XML_ATTRIBUTE(node->Attribute("dialog_message_downloading"));
	connecting_message = XML_ATTRIBUTE(node->Attribute("dialog_message_connecting"));
	sendingrequest_message = XML_ATTRIBUTE(node->Attribute("dialog_message_sendingrequest"));
	start_caption = XML_ATTRIBUTE(node->Attribute("buttonstart_caption"));
	cancel_caption = XML_ATTRIBUTE(node->Attribute("buttoncancel_caption"));
	auto_start = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("autostartdownload")), false);

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

void DownloadGroupConfiguration::Exec()
{
	DownloadComponents components;
	components.Load(NULL, downloadcomponents);
	components.Exec();
}