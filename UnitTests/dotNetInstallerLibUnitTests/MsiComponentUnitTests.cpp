#include "StdAfx.h"
#include "MsiComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void MsiComponentUnitTests::testExecInstall()
{
    MsiComponent component;
    component.package = L"msidoesntexist.msi"; 
    component.cmdparameters = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception& /* ex */)
    {
        // msi file cannot be opened
        Assert::IsTrue(1619 == component.GetProcessExitCode());
    }
}

void MsiComponentUnitTests::testExecInstallSilent()
{
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MsiComponent component;
    component.package = L"msidoesntexist.msi"; 
    component.cmdparameters_silent = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception& /* ex */)
    {
        // msi file cannot be opened
        Assert::IsTrue(1619 == component.GetProcessExitCode());
    }
}

void MsiComponentUnitTests::testGetCommandLine()
{
    struct TestData
    {
        InstallSequence sequence;
        std::wstring package;
        std::wstring cmdparameters;
        std::wstring uninstall_cmdparameters;
        std::wstring uninstall_package;
        std::wstring command;
    };

    TestData testdata[] =
    {
        { SequenceInstall, L"test.msi", L"", L"", L"", L"msiexec /i \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"test.msi") + L"\"" },
        { SequenceInstall, L"{3DE50841-856E-4640-ABF4-0FF31560AA81}", L"", L"", L"", L"msiexec /i \"{3DE50841-856E-4640-ABF4-0FF31560AA81}\"" },
        { SequenceInstall, L"3DE50841-856E-4640-ABF4-0FF31560AA81", L"", L"", L"", L"msiexec /i \"3DE50841-856E-4640-ABF4-0FF31560AA81\"" },
        { SequenceInstall, L"C:\\test.msi", L"X=Y", L"", L"", L"msiexec /i \"C:\\test.msi\" X=Y" },
        { SequenceUninstall, L"test.msi", L"", L"", L"", L"msiexec /x \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"test.msi") + L"\"" },
        { SequenceUninstall, L"{3DE50841-856E-4640-ABF4-0FF31560AA81}", L"", L"", L"", L"msiexec /x \"{3DE50841-856E-4640-ABF4-0FF31560AA81}\"" },
        { SequenceUninstall, L"3DE50841-856E-4640-ABF4-0FF31560AA81", L"", L"", L"", L"msiexec /x \"3DE50841-856E-4640-ABF4-0FF31560AA81\"" },
        { SequenceUninstall, L"C:\\test.msi", L"X=Y", L"", L"", L"msiexec /x \"C:\\test.msi\"" },
        { SequenceUninstall, L"C:\\test.msi", L"", L"X=Y", L"", L"msiexec /x \"C:\\test.msi\" X=Y" },
        { SequenceUninstall, L"C:\\install.msi", L"", L"X=Y", L"C:\\uninstall.msi", L"msiexec /x \"C:\\uninstall.msi\" X=Y" },
        { SequenceUninstall, L"", L"", L"X=Y", L"C:\\uninstall.msi", L"msiexec /x \"C:\\uninstall.msi\" X=Y" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstallSequenceState state;
        InstallerSession::Instance->sequence = testdata[i].sequence;
        MsiComponent component;
        component.package = testdata[i].package;
        component.cmdparameters = testdata[i].cmdparameters;
        component.uninstall_cmdparameters = testdata[i].uninstall_cmdparameters;
        component.uninstall_package = testdata[i].uninstall_package;
        std::wstring command = component.GetCommandLine();
        std::wcout << std::endl << L" " << command;
        Assert::IsTrue(testdata[i].command == command);
    }
}

void MsiComponentUnitTests::testExecUninstall()
{
    InstallerSession::Instance->sequence = SequenceUninstall;
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MsiComponent component;
    component.package = L"msidoesntexist.msi"; 
    component.uninstall_cmdparameters = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception& /* ex */)
    {
        // msi file cannot be opened
        Assert::IsTrue(1619 == component.GetProcessExitCode());
    }
}

void MsiComponentUnitTests::testExecUninstallSilent()
{
    InstallerSession::Instance->sequence = SequenceUninstall;
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MsiComponent component;
    component.package = L"msidoesntexist.msi"; 
    component.uninstall_cmdparameters_silent = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception& /* ex */)
    {
        // msi file cannot be opened
        Assert::IsTrue(1619 == component.GetProcessExitCode());
    }
}

void MsiComponentUnitTests::testMustReboot()
{
    MsiComponent component;
    Assert::IsTrue(! component.IsRebootRequired());
    component.mustreboot = true;
    Assert::IsTrue(component.IsRebootRequired());
}
