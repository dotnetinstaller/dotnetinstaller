#include "StdAfx.h"
#include "dotNetInstallerLibUnitTestFixture.h"

void dotNetInstallerLibUnitTestFixture::setUp()
{
	InstallerLog::Instance = shared_any<InstallerLog *, close_delete>(new InstallerLog());
	InstallerSession::Instance = shared_any<InstallerSession *, close_delete>(new InstallerSession());
	InstallUILevelSetting::Instance = shared_any<InstallUILevelSetting *, close_delete>(new InstallUILevelSetting());
	InstallerLauncher::Instance = shared_any<InstallerLauncher *, close_delete>(new InstallerLauncher());
}

void dotNetInstallerLibUnitTestFixture::tearDown()
{
	reset(InstallerLauncher::Instance);
	reset(InstallerLog::Instance);
	reset(InstallerSession::Instance);
	reset(InstallUILevelSetting::Instance);
}
