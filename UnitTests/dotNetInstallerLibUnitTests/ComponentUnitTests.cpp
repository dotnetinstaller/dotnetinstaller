#include "StdAfx.h"
#include "ComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ComponentUnitTests::testGetDisplayName()
{
    CmdComponent component1;
    component1.display_name = L"display_name";
    Assert::IsTrue(component1.GetDisplayName() == component1.display_name.GetValue());
    InstallerSession::Instance->sequence = SequenceUninstall;
    Assert::IsTrue(component1.GetDisplayName() == component1.display_name.GetValue());
    component1.uninstall_display_name = L"uninstall_display_name";
    Assert::IsTrue(component1.GetDisplayName() == component1.uninstall_display_name.GetValue());
    component1.display_name = L"";
    Assert::IsTrue(component1.GetDisplayName() == component1.uninstall_display_name.GetValue());
}
