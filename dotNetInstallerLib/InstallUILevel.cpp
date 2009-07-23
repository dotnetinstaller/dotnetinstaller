#include "stdafx.h"
#include "InstallUILevel.h"

shared_any<InstallUILevelSetting *, close_delete> InstallUILevelSetting::Instance;

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

InstallUILevel InstallUILevelSetting::ToUILevel(const std::wstring& level, InstallUILevel defaultValue)
{
	if (level == TEXT("full"))
		return InstallUILevelFull;
	if (level == TEXT("basic"))
		return InstallUILevelBasic;
	if (level == TEXT("silent"))
		return InstallUILevelSilent;
	else
		return defaultValue;
}
