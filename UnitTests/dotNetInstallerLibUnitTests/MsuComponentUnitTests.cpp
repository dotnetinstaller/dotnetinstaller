#include "StdAfx.h"
#include "MsuComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::MsuComponentUnitTests);

using namespace DVLib::UnitTests;

void MsuComponentUnitTests::testExecInstall()
{
    if (DVLib::GetOperatingSystemVersion() < winVista)
    {
        std::wcout << std::endl << L"skipping: MsuComponentUnitTests::testExecInstall (os=" 
            << DVLib::GetOperatingSystemVersionString() << L")";
        return;
    }

    MsuComponent component;
    component.package = L"msidoesntexist.msu"; 
    component.cmdparameters = L"/quiet";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // msu file cannot be opened
        CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
    }
}

void MsuComponentUnitTests::testExecInstallSilent()
{
    if (DVLib::GetOperatingSystemVersion() < winVista)
    {
        std::wcout << std::endl << L"skipping: MsuComponentUnitTests::testExecInstallSilent (os=" 
            << DVLib::GetOperatingSystemVersionString() << L")";
        return;
    }

    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MsuComponent component;
    component.package = L"msidoesntexist.msu";
    component.cmdparameters_silent = L"/quiet";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // msu file cannot be opened
        CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
    }
}

void MsuComponentUnitTests::testExecUninstall()
{
    if (DVLib::GetOperatingSystemVersion() < winVista)
    {
        std::wcout << std::endl << L"skipping: MsuComponentUnitTests::testExecUninstall (os=" 
            << DVLib::GetOperatingSystemVersionString() << L")";
        return;
    }

    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceUninstall;
    MsuComponent component;
    try
    {
        component.Exec();
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // sequence is not supported
    }
}

void MsuComponentUnitTests::testExecUninstallSilent()
{
    if (DVLib::GetOperatingSystemVersion() < winVista)
    {
        std::wcout << std::endl << L"skipping: MsuComponentUnitTests::testExecUninstallSilent (os=" 
            << DVLib::GetOperatingSystemVersionString() << L")";
        return;
    }

    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceUninstall;
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MsuComponent component;
    component.package = L"msidoesntexist.msu";
    component.cmdparameters_silent = L"/quiet";
    try
    {
        component.Exec();
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // sequence is not supported
    }
}

void MsuComponentUnitTests::testExecShell()
{
    if (DVLib::GetOperatingSystemVersion() < winVista)
    {
        std::wcout << std::endl << L"skipping: MsuComponentUnitTests::testExecutionMethod (os=" 
            << DVLib::GetOperatingSystemVersionString() << L")";
        return;
    }

    // Cannot test whether ShellExecute is really used, because executable is fixed (wusa.exe)
    // Just check it can run when execution method is ShellExecute

    MsuComponent component;
    component.package = L"msidoesntexist.msu"; 
    component.cmdparameters = L"/quiet";
    // default execution method is CreateProcess
    CPPUNIT_ASSERT(component.execution_method == DVLib::CemCreateProcess);
    component.execution_method = DVLib::CemShellExecute;
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // msu file cannot be opened
        CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
    }
}

void MsuComponentUnitTests::testMustReboot()
{
    MsuComponent component;
    CPPUNIT_ASSERT(! component.IsRebootRequired());
    component.mustreboot = true;
    CPPUNIT_ASSERT(component.IsRebootRequired());
}

void MsuComponentUnitTests::testLoad()
{
    TiXmlDocument doc;
    doc.Parse("<component type=\"msu\" \
              package=\"test-dir\\test.msu\" \
              cmdparameters=\"/forcereboot\" \
              execution_method=\"ShellExecute\"/>");
    MsuComponent component;
    component.Load(doc.RootElement());
    CPPUNIT_ASSERT(component.package.GetValue() == L"test-dir\\test.msu");
    CPPUNIT_ASSERT(component.cmdparameters.GetValue() == L"/forcereboot");
    CPPUNIT_ASSERT(component.execution_method == DVLib::CemShellExecute);
}