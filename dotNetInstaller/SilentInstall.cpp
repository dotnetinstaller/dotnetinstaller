#include "stdafx.h"
#include "SilentInstall.h"

// Matthew Sheets - 2007-09-20: Support silent installs

SilentInstall QuietInstall;

SilentInstall::SilentInstall(void):
				m_EnableSilentInstall(false)
{
}

SilentInstall::~SilentInstall(void)
{
}
