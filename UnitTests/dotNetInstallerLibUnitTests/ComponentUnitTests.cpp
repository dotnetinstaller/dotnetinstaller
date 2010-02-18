#include "StdAfx.h"
#include "ComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ComponentUnitTests);

using namespace DVLib::UnitTests;

void ComponentUnitTests::testGetDisplayName()
{
	CmdComponent component1;
	component1.display_name = L"display_name";
	CPPUNIT_ASSERT(component1.GetDisplayName() == component1.display_name.GetValue());
	InstallerSession::Instance->sequence = SequenceUninstall;
	CPPUNIT_ASSERT(component1.GetDisplayName() == component1.display_name.GetValue());
	component1.uninstall_display_name = L"uninstall_display_name";
	CPPUNIT_ASSERT(component1.GetDisplayName() == component1.uninstall_display_name.GetValue());
	component1.display_name = L"";
	CPPUNIT_ASSERT(component1.GetDisplayName() == component1.uninstall_display_name.GetValue());
}
