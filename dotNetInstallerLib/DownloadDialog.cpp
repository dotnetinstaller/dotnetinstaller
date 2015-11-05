#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "DownloadDialog.h"
#include "DownloadDialog.h"
#include "InstallerLog.h"

DownloadDialog::DownloadDialog(const std::wstring& id)
: auto_start(true)
, callback(NULL)
, component_id(id)
{

}

void DownloadDialog::Load(TiXmlElement * node)
{
    CHECK_BOOL(node != NULL,
        L"Expected 'downloaddialog' node");

    CHECK_BOOL(0 == strcmp(node->Value(), "downloaddialog"),
        L"Expected 'downloaddialog' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    caption = node->Attribute("dialog_caption");
    help_message = node->Attribute("dialog_message");
    downloading_message = node->Attribute("dialog_message_downloading");
    copying_message = node->Attribute("dialog_message_copying");
    connecting_message = node->Attribute("dialog_message_connecting");
    sendingrequest_message = node->Attribute("dialog_message_sendingrequest");
    start_caption = node->Attribute("buttonstart_caption");
    cancel_caption = node->Attribute("buttoncancel_caption");
    auto_start = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("autostartdownload")), false);

    TiXmlNode * child = NULL;
    while ( (child = node->IterateChildren(child)) != NULL)
    {
        TiXmlElement * node_element = child->ToElement();
        if (node_element == NULL)
            continue;

        auto_any<DownloadFile *, close_delete> downloadfile(new DownloadFile());
        downloadfile->Load(node_element);
        downloadfiles.push_back(downloadfile);
    }

    if (downloadfiles.empty())
    {
        THROW_EX("Invalid  Download dialog '" << caption << L"', requires at least one download file.");
    }

    LOG(L"Loaded 'download' configuration '" << caption << L"' with " << downloadfiles.size() << " file(s)");
}

int DownloadDialog::ExecOnThread()
{
    if (IsRequired())
    {
        try
        {
            for (size_t i = 0; i < downloadfiles.size(); i++)
            {
                if (callback && callback->IsDownloadCancelled())
                {
                    return -2;
                }

                downloadfiles[i]->Exec(callback);
            }

            if (callback)
            {
                callback->DownloadComplete();
            }
        }
        catch(std::exception& ex)
        {
            if (callback)
            {
                callback->DownloadError(DVLib::string2wstring(ex.what()).c_str());
            }

            throw ex;
        }
    }

    return 0;
}

bool DownloadDialog::IsCopyRequired() const
{
    for (size_t i = 0; i < downloadfiles.size(); i++)
    {
        bool required = downloadfiles[i]->IsCopyRequired();

        std::wstring destination = downloadfiles[i]->GetDestinationFileName();
        LOG(L"Destination '" << destination 
            << L"', exists=" << (DVLib::FileExists(destination) ? L"True" : L"False")
            << L", copy=" << (required ? L"True" : L"False"));

        if (required)
        {
            return true;
        }
    }

    return false;
}

bool DownloadDialog::IsDownloadRequired() const
{
    for (size_t i = 0; i < downloadfiles.size(); i++)
    {
        bool required = downloadfiles[i]->IsDownloadRequired();

        std::wstring destination = downloadfiles[i]->GetDestinationFileName();
        LOG(L"Destination '" << destination 
            << L"', exists=" << (DVLib::FileExists(destination) ? L"True" : L"False")
            << L", download=" << (required ? L"True" : L"False"));

        if (required)
        {
            return true;
        }
    }

    return false;
}

std::wstring DownloadDialog::GetString(int indent) const
{
    std::wstringstream ss;
    for (size_t i = 0; i < downloadfiles.size(); i++)
    {
        ss << downloadfiles[i]->GetString(indent + 1) << std::endl;
    }
    return ss.str();
}

bool DownloadDialog::IsRequired() const
{
    return IsCopyRequired() || IsDownloadRequired();
}
