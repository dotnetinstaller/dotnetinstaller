#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "InstalledCheckOperator.h"
#include "InstallerLog.h"

InstalledCheckOperator::InstalledCheckOperator()
{

}

void InstalledCheckOperator::Load(TiXmlElement * node)
{
    type = DVLib::UTF8string2wstring(node->Attribute("type"));
    description = XML_ATTRIBUTE(node->Attribute("description"));
	// child install checks
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
		
		if (strcmp(child_element->Value(), "installedcheck") == 0)
		{
			std::wstring installedcheck_type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
			InstalledCheckPtr installedcheck(InstalledCheck::Create(installedcheck_type));
			installedcheck->Load(child_element);
			installedchecks.push_back(installedcheck);
		}
		else if (strcmp(child_element->Value(), "installedcheckoperator") == 0)
		{
			InstalledCheckPtr installedcheckoperator(new InstalledCheckOperator());
			installedcheckoperator->Load(child_element);
			installedchecks.push_back(installedcheckoperator);
		}
		else
		{
			THROW_EX(L"Unexpected node '" << child_element->Value() << L"'");
		}
	}

	LOG(L"Loaded '" << type << L"' installed check operator");
}

bool InstalledCheckOperator::IsInstalled() const
{
    if (type == L"And")
    {
        if (installedchecks.size() == 0)
            return false;

        for each(const InstalledCheckPtr& installedcheck in installedchecks)
        {
            if (! installedcheck->IsInstalled())
                return false;
        }

        return true;
    }
    else if (type == L"Or")
    {
        for each(const InstalledCheckPtr& installedcheck in installedchecks)
        {
            if (installedcheck->IsInstalled())
                return true;
        }
        
        return false;
    }
    else if (type == L"Not")
    {
        if (installedchecks.size() == 0)
            return true;

        for each(const InstalledCheckPtr& installedcheck in installedchecks)
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
