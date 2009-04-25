#include "stdafx.h"
#include "InstallUILevel.h"

InstallUILevelSetting CurrentInstallUILevel;

InstallUILevelSetting::InstallUILevelSetting()
	: m_ConfigLevel(InstallUILevelNotSet)
	, m_RuntimeLevel(InstallUILevelNotSet)
{

}

void InstallUILevelSetting::SetConfigLevel(InstallUILevel value) 
{ 
	m_ConfigLevel = value; 
}

void InstallUILevelSetting::SetRuntimeLevel(InstallUILevel value) 
{ 
	m_RuntimeLevel = value; 
}

bool InstallUILevelSetting::IsSilent() const
{
	switch(m_RuntimeLevel)
	{
	case InstallUILevelBasic:
	case InstallUILevelSilent:
		return true;
	}

	switch(m_ConfigLevel)
	{
	case InstallUILevelBasic:
	case InstallUILevelSilent:
		return true;
	}

	return false;
}

bool InstallUILevelSetting::IsAnyUI() const
{
	switch(m_RuntimeLevel)
	{
	case InstallUILevelSilent:
		return false;
	}

	switch(m_ConfigLevel)
	{
	case InstallUILevelSilent:
		return false;
	}

	return true;
}

InstallUILevel InstallUILevelSetting::GetUILevel(InstallUILevel defaultValue) const
{
	if (m_RuntimeLevel != InstallUILevelNotSet)
		return m_RuntimeLevel;

	if (m_ConfigLevel != InstallUILevelNotSet)
		return m_ConfigLevel;

	// default to full UI mode
	return defaultValue;
}

InstallUILevel InstallUILevelSetting::ToUILevel(LPCSTR pszLevel, InstallUILevel defaultValue)
{
	if (! pszLevel || 0 == strlen(pszLevel))
		return defaultValue;

	if (0 == strcmpi(pszLevel, "full"))
		return InstallUILevelFull;
	else if (0 == strcmpi(pszLevel, "basic"))
		return InstallUILevelBasic;
	else if (0 == strcmpi(pszLevel, "silent"))
		return InstallUILevelSilent;
	else
		return defaultValue;
}