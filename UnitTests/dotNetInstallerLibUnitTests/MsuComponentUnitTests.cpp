#include "StdAfx.h"
#include "MsuComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
        Assert::IsTrue(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
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
        Assert::IsTrue(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
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
    Assert::IsTrue(component.execution_method == DVLib::CemCreateProcess);
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
        Assert::IsTrue(ERROR_FILE_NOT_FOUND == component.GetProcessExitCode());
    }
}

void MsuComponentUnitTests::testMustReboot()
{
    MsuComponent component;
    Assert::IsTrue(! component.IsRebootRequired());
    component.mustreboot = true;
    Assert::IsTrue(component.IsRebootRequired());
}

void MsuComponentUnitTests::testLoad()
{
    tinyxml2::XMLDocument doc;
    doc.Parse("<component type=\"msu\" \
              package=\"test-dir\\test.msu\" \
              cmdparameters=\"/forcereboot\" \
              execution_method=\"ShellExecute\"/>");
    MsuComponent component;
    component.Load(doc.RootElement());
    Assert::IsTrue(component.package.GetValue() == L"test-dir\\test.msu");
    Assert::IsTrue(component.cmdparameters.GetValue() == L"/forcereboot");
    Assert::IsTrue(component.execution_method == DVLib::CemShellExecute);
}