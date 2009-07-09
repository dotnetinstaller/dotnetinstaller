#include "StdAfx.h"
#include "InstalledCheckOperator.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"

InstalledCheckOperator::InstalledCheckOperator()
{

}

void InstalledCheckOperator::Load(TiXmlElement * node, Configuration & setting)
{
    type = node->AttributeW("type");
    description = node->AttributeW("description");
	LOG(L"----Reading installed check operator: " << description << L" (" << type << L")");

	// installed checks
	TiXmlNode * l_Child = NULL;
	while ( (l_Child = node->IterateChildren(l_Child)) != NULL)
	{
		TiXmlElement * node = l_Child->ToElement();
		if (node != NULL && strcmp(node->Value(), "installedcheck") == 0)
		{
            InstalledCheck * l_new_installedcheck = InstalledCheck::LoadFromXml(node, setting);
            installed_checks.push_back(l_new_installedcheck);
		}
		else if (node != NULL && strcmp(node->Value(), "installedcheckoperator") == 0)
		{
            InstalledCheckOperator * l_new_installedcheckoperator = new InstalledCheckOperator();
            l_new_installedcheckoperator->Load(node, setting);			
            installed_checks.push_back(l_new_installedcheckoperator);
		}
    }
}

bool InstalledCheckOperator::IsInstalled() const
{
    if (type == L"And")
    {
        if (installed_checks.size() == 0)
            return false;

        for each(InstalledCheck * installedcheck in installed_checks)
        {
            if (! installedcheck->IsInstalled())
                return false;
        }

        return true;
    }
    else if (type == L"Or")
    {
        for each(InstalledCheck * installedcheck in installed_checks)
        {
            if (installedcheck->IsInstalled())
                return true;
        }
        
        return false;
    }
    else if (type == L"Not")
    {
        if (installed_checks.size() == 0)
            return true;

        for each(InstalledCheck * installedcheck in installed_checks)
        {
            if (installedcheck->IsInstalled())
                return false;
        }

        return true;
    }
    else
    {
		THROW_EX("Invalid check operator \"" << type << L"\"");
    }
}
