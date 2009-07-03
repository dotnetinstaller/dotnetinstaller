#include "StdAfx.h"
#include "InstalledCheckOperator.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"

InstalledCheckOperator::InstalledCheckOperator()
{

}

void InstalledCheckOperator::Load(TiXmlElement * p_Node, InstallerSetting & p_Setting)
{
    type = p_Node->AttributeW("type").data();
    description = p_Node->AttributeW("description").data();
    ApplicationLog.Write(TEXT("----Reading installed check operator: "), description + TEXT(" (") + type + TEXT(")"));

	// installed checks
	TiXmlNode * l_Child = NULL;
	while ( (l_Child = p_Node->IterateChildren(l_Child)) != NULL)
	{
		TiXmlElement * l_Node = l_Child->ToElement();
		if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheck") == 0)
		{
            InstalledCheck * l_new_installedcheck = InstalledCheck::LoadFromXml(l_Node, p_Setting);
            installedchecks.push_back(l_new_installedcheck);
		}
		else if (l_Node != NULL && strcmp(l_Node->Value(), "installedcheckoperator") == 0)
		{
            InstalledCheckOperator * l_new_installedcheckoperator = new InstalledCheckOperator();
            l_new_installedcheckoperator->Load(l_Node, p_Setting);			
            installedchecks.push_back(l_new_installedcheckoperator);
		}
    }
}

bool InstalledCheckOperator::IsInstalled()
{
    if (type == "And")
    {
        if (installedchecks.size() == 0)
            return false;

        for each(InstalledCheck * installedcheck in installedchecks)
        {
            if (! installedcheck->IsInstalled())
                return false;
        }

        return true;
    }
    else if (type == "Or")
    {
        for each(InstalledCheck * installedcheck in installedchecks)
        {
            if (installedcheck->IsInstalled())
                return true;
        }
        
        return false;
    }
    else if (type == "Not")
    {
        if (installedchecks.size() == 0)
            return true;

        for each(InstalledCheck * installedcheck in installedchecks)
        {
            if (installedcheck->IsInstalled())
                return false;
        }

        return true;
    }
    else
    {
        throw std::exception("Invalid check operator");
    }
}
