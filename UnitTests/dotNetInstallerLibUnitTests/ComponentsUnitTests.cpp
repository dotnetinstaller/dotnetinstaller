#include "StdAfx.h"
#include "ComponentsUnitTests.h"
#include "ExecuteComponentCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ComponentsUnitTests);

using namespace DVLib::UnitTests;

void ComponentsUnitTests::testAdd()
{
    Components components;
    ComponentPtr component1(new CmdComponent());
    component1->id = DVLib::GenerateGUIDStringW();
    ComponentPtr component2(new CmdComponent());
    component2->id = DVLib::GenerateGUIDStringW();
    components.add(component1);
    components.add(component2);
    CPPUNIT_ASSERT(components.size() == 2);
    CPPUNIT_ASSERT(components.contains(component1->id));
    CPPUNIT_ASSERT(components.contains(component2->id));
    CPPUNIT_ASSERT(! components.contains(DVLib::GenerateGUIDStringW()));
}

void ComponentsUnitTests::testOsFilters()
{
    Components components;
    ComponentPtr component1(new MsiComponent());
    component1->os_filter = L"!win95";
    ComponentPtr component2(new MsiComponent());
    component2->os_filter = L"win95osr2";
    ComponentPtr component3(new MsiComponent());
    component3->os_filter = L"win95";
    ComponentPtr component4(new MsiComponent());
    components.add(component1);
    components.add(component2);
    components.add(component3);
    components.add(component4);
    CPPUNIT_ASSERT(components.size() == 4);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 2);
}

void ComponentsUnitTests::testOsFiltersGreaterSmaller()
{
    Components components;
    ComponentPtr component1(new MsiComponent());
    component1->os_filter_min = winNone;
    component1->os_filter_max = win95Max;
    ComponentPtr component2(new MsiComponent());
    component2->os_filter_min = win98;
    component2->os_filter_max = win2000Max;
    ComponentPtr component3(new MsiComponent());
    component3->os_filter_min = winXP;
    component3->os_filter_max = winNone;
    components.add(component1);
    components.add(component2);
    components.add(component3);
    CPPUNIT_ASSERT(components.size() == 3);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
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
    CPPUNIT_ASSERT(components.size() == 2);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
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
    CPPUNIT_ASSERT(components.size() == 2);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 1);
    CPPUNIT_ASSERT(get(components.GetSupportedComponents(LcidUser, SequenceInstall)[0]) == get(component_anotherpa));
}

void ComponentsUnitTests::testExecNoCallback()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    std::wstring check_file = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), component1->id);
    CPPUNIT_ASSERT(! DVLib::FileExists(check_file));
    component1->command = L"cmd.exe /C dir > \"" + check_file + L"\"";
    components.add(ComponentPtr(component1));
    components.Exec(NULL);
    CPPUNIT_ASSERT(DVLib::FileExists(check_file));
    DVLib::FileDelete(check_file);
}

void ComponentsUnitTests::testExecWithCallback()
{
    Components components;
    CmdComponent * component1 = new CmdComponent();
    component1->id = DVLib::GenerateGUIDStringW();
    std::wstring check_file = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), component1->id);
    CPPUNIT_ASSERT(! DVLib::FileExists(check_file));
    component1->command = L"cmd.exe /C dir > \"" + check_file + L"\"";
    components.add(ComponentPtr(component1));
    ExecuteComponentCallbackImpl callback;
    components.Exec(& callback);
    CPPUNIT_ASSERT(DVLib::FileExists(check_file));
    DVLib::FileDelete(check_file);
    CPPUNIT_ASSERT(1 == callback.starts);
    CPPUNIT_ASSERT(1 == callback.begins);
    CPPUNIT_ASSERT(1 == callback.waits);
    CPPUNIT_ASSERT(1 == callback.successes);
    CPPUNIT_ASSERT(0 == callback.errors);
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
    CPPUNIT_ASSERT(1 == callback.starts);
    CPPUNIT_ASSERT(1 == callback.begins);
    CPPUNIT_ASSERT(0 == callback.waits);
    CPPUNIT_ASSERT(0 == callback.successes);
    CPPUNIT_ASSERT(1 == callback.errors);
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
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall).size() == 2);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall)[0]->id == component1->id);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceInstall)[1]->id == component2->id);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceUninstall).size() == 2);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceUninstall)[0]->id == component2->id);
    CPPUNIT_ASSERT(components.GetSupportedComponents(LcidUser, SequenceUninstall)[1]->id == component1->id);
}

void ComponentsUnitTests::testSequenceInstalled()
{
    // a component with no install checks follows sequence
    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceInstall;
    CmdComponent cmd;
    CPPUNIT_ASSERT(! cmd.IsInstalled());
    InstallerSession::Instance->sequence = SequenceUninstall;
    CPPUNIT_ASSERT(cmd.IsInstalled());
}