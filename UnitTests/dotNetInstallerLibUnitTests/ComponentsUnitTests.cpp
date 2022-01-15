#include "StdAfx.h"
#include "ComponentsUnitTests.h"
#include "ExecuteComponentCallbackImpl.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ComponentsUnitTests::testAdd()
{
    Components components;
    ComponentPtr component1(new CmdComponent());
    component1->id = DVLib::GenerateGUIDStringW();
    ComponentPtr component2(new CmdComponent());
    component2->id = DVLib::GenerateGUIDStringW();
    components.add(component1);
    components.add(component2);
    Assert::IsTrue(components.size() == 2);
    Assert::IsTrue(components.contains(component1->id));
    Assert::IsTrue(components.contains(component2->id));
    Assert::IsTrue(! components.contains(DVLib::GenerateGUIDStringW()));
}

void ComponentsUnitTests::testOsFilters()
{
    Components components;
    ComponentPtr component1(new MsiComponent());
    component1->os_filter = L"!winXP";
    ComponentPtr component2(new MsiComponent());
    component2->os_filter = L"winXPsp1";
    ComponentPtr component3(new MsiComponent());
    component3->os_filter = L"winXP";
    ComponentPtr component4(new MsiComponent());
    components.add(component1);
    components.add(component2);
    components.add(component3);
    components.add(component4);
    Assert::IsTrue(components.size() == 4);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 2);
}

void ComponentsUnitTests::testOsFiltersGreaterSmaller()
{
    Components components;
    ComponentPtr component1(new MsiComponent());
    component1->os_filter_min = winNone;
    component1->os_filter_max = winXPMax;
    ComponentPtr component2(new MsiComponent());
    component2->os_filter_min = winXP;
    component2->os_filter_max = winServer2003Max;
    ComponentPtr component3(new MsiComponent());
    component3->os_filter_min = winXP;
    component3->os_filter_max = winNone;
    components.add(component1);
    components.add(component2);
    components.add(component3);
    Assert::IsTrue(components.size() == 3);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
}

void ComponentsUnitTests::testLcidFilters()
{
    Components components;
    ComponentPtr component_currentlcid(new MsiComponent());
    component_currentlcid->os_filter_lcid = L"1040";
    ComponentPtr component_anotherlcid(new MsiComponent());
    component_anotherlcid->os_filter_lcid = L"!1040";
    components.add(component_currentlcid);
    components.add(component_anotherlcid);
    Assert::IsTrue(components.size() == 2);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
}

void ComponentsUnitTests::testPAFilters()
{
    Components components;
    ComponentPtr component_currentpa(new MsiComponent());
    component_currentpa->processor_architecture_filter = L"mips";
    ComponentPtr component_anotherpa(new MsiComponent());
    component_anotherpa->processor_architecture_filter = L"x86,x64";
    components.add(component_currentpa);
    components.add(component_anotherpa);
    Assert::IsTrue(components.size() == 2);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
    Assert::IsTrue(get(components.GetSupportedComponents(LcidUser, SequenceInstall)[0]) == get(component_anotherpa));
}

void ComponentsUnitTests::testOsTypeFilters()
{
    Components components;
    ComponentPtr component1(new MsiComponent());
    component1->os_type_filter = L"domainController";
    ComponentPtr component2(new MsiComponent());
    component2->os_type_filter = L"workstation";
    ComponentPtr component3(new MsiComponent());
    component3->os_type_filter = L"server";
    ComponentPtr component4(new MsiComponent());
    components.add(component1);
    components.add(component2);
    components.add(component3);
    components.add(component4);
    Assert::IsTrue(components.size() == 4);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 2);
}

void ComponentsUnitTests::testExecNoCallback()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    std::wstring check_file = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), component1->id);
    Assert::IsTrue(! DVLib::FileExists(check_file));
    component1->command = L"cmd.exe /C dir > \"" + check_file + L"\"";
    components.add(ComponentPtr(component1));
    components.Exec(NULL);
    Assert::IsTrue(DVLib::FileExists(check_file));
    DVLib::FileDelete(check_file);
}

void ComponentsUnitTests::testExecWithCallback()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    std::wstring check_file = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), component1->id);
    Assert::IsTrue(! DVLib::FileExists(check_file));
    component1->command = L"cmd.exe /C dir > \"" + check_file + L"\"";
    components.add(ComponentPtr(component1));
    ExecuteComponentCallbackImpl callback;
    components.Exec(& callback);
    Assert::IsTrue(DVLib::FileExists(check_file));
    DVLib::FileDelete(check_file);
    Assert::IsTrue(1 == callback.starts);
    Assert::IsTrue(1 == callback.begins);
    Assert::IsTrue(1 == callback.waits);
    Assert::IsTrue(1 == callback.successes);
    Assert::IsTrue(0 == callback.errors);
}

void ComponentsUnitTests::testExecWithError()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    component1->command = L"foobar.exe";
    components.add(ComponentPtr(component1));
    ExecuteComponentCallbackImpl callback;
    components.Exec(& callback);
    Assert::IsTrue(1 == callback.starts);
    Assert::IsTrue(1 == callback.begins);
    Assert::IsTrue(0 == callback.waits);
    Assert::IsTrue(0 == callback.successes);
    Assert::IsTrue(1 == callback.errors);
}

void ComponentsUnitTests::testLoadUninstallSequence()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    components.add(ComponentPtr(component1));
    CmdComponent * component2 = new CmdComponent();
    component2->id = DVLib::GenerateGUIDStringW();
    components.add(ComponentPtr(component2));
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 2);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall)[0]->id == component1->id);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceInstall)[1]->id == component2->id);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceUninstall).size() == 2);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceUninstall)[0]->id == component2->id);
    Assert::IsTrue(components.GetSupportedComponents(LcidUser, SequenceUninstall)[1]->id == component1->id);
}

void ComponentsUnitTests::testSequenceInstalled()
{
    // a component with no install checks follows sequence
    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceInstall;
    CmdComponent cmd;
    Assert::IsTrue(! cmd.IsInstalled());
    InstallerSession::Instance->sequence = SequenceUninstall;
    Assert::IsTrue(cmd.IsInstalled());
}