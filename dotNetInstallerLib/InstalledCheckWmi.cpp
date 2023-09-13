#include "stdafx.h"
#include "InstalledCheckWmi.h"
#include "InstallerLog.h"

void InstalledCheckWmi::Load(tinyxml2::XMLElement* node)
{
    query = node->Attribute("query");
    LOG(L"Loaded 'wmi' installed check '" << query << L"'");
}

bool InstalledCheckWmi::IsInstalled() const
{
    LOG(L"Checking whether WMI query '" << query << L"' returns any results");
    bool any = DVLib::WmiUtil::Any(query);
    LOG(L"WMI query '" << query << L"' " << (any ? L"returned one or more results" : L"did not return any results"));
    return any;
}