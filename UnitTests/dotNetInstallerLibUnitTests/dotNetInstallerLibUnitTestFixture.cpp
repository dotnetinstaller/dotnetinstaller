#include "StdAfx.h"
#include "dotNetInstallerLibUnitTestFixture.h"

void dotNetInstallerLibUnitTestFixture::setUp()
{
	InstallerLog::Instance = shared_any<InstallerLog *, close_delete>(new InstallerLog());
	InstallerSession::Instance = shared_any<InstallerSession *, close_delete>(new InstallerSession());
	InstallUILevelSetting::Instance = shared_any<InstallUILevelSetting *, close_delete>(new InstallUILevelSetting());
}

void dotNetInstallerLibUnitTestFixture::tearDown()
{
	reset(InstallerLog::Instance);
	reset(InstallerSession::Instance);
	reset(InstallUILevelSetting::Instance);
}
