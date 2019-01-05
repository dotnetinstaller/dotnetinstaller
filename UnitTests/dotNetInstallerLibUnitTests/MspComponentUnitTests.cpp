#include "StdAfx.h"
#include "MspComponentUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void MspComponentUnitTests::testExecInstall()
{
    MspComponent component;
    component.package = L"mspdoesntexist.msu"; 
    component.cmdparameters = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // msp file cannot be opened
        Assert::IsTrue(ERROR_INSTALL_PACKAGE_OPEN_FAILED == component.GetProcessExitCode());
    }
}

void MspComponentUnitTests::testExecInstallSilent()
{
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MspComponent component;
    component.package = L"mspdoesntexist.msu";
    component.cmdparameters_silent = L"/qn";
    component.Exec();
    try
    {
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // msu file cannot be opened
        Assert::IsTrue(ERROR_INSTALL_PACKAGE_OPEN_FAILED == component.GetProcessExitCode());
    }
}

void MspComponentUnitTests::testExecUninstall()
{
    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceUninstall;
    MspComponent component;
    component.uninstall_cmdparameters = L"/qn";
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

void MspComponentUnitTests::testExecUninstallSilent()
{
    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceUninstall;
    InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
    MspComponent component;
    component.package = L"mspdoesntexist.msu";
    component.uninstall_cmdparameters_silent = L"/qn";
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

void MspComponentUnitTests::testGetCommandLine()
{
    struct TestData
    {
        InstallSequence sequence;
        std::wstring patch;
        std::wstring package;
        std::wstring cmdparameters;
        std::wstring uninstall_cmdparameters;
        std::wstring uninstall_patch;
        std::wstring uninstall_package;
        std::wstring reinstall;
        std::wstring reinstallmode;
        std::wstring command;
    };

    TestData testdata[] =
    {
        { SequenceInstall, L"test.msp", L"", // patch, package
        L"", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"test.msp") + L"\"" },
        { SequenceInstall, L"{3DE50841-856E-4640-ABF4-0FF31560AA81}", L"", // patch, package
        L"", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"{3DE50841-856E-4640-ABF4-0FF31560AA81}\"" },
        { SequenceInstall, L"3DE50841-856E-4640-ABF4-0FF31560AA81", L"", // patch, package
        L"", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"3DE50841-856E-4640-ABF4-0FF31560AA81\"" },
        { SequenceInstall, L"c:\\test.msp", L"", // patch, package
        L"X=Y", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"c:\\test.msp\" X=Y" },
        { SequenceInstall, L"c:\\test.msp", L"", // patch, package
        L"X=Y", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"ALL", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"c:\\test.msp\" X=Y REINSTALL=ALL" },
        { SequenceInstall, L"c:\\test.msp", L"", // patch, package
        L"X=Y", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"vomus", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"c:\\test.msp\" X=Y REINSTALLMODE=vomus" },
        { SequenceInstall, L"c:\\test.msp", L"", // patch, package
        L"X=Y", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"ALL", L"vomus", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"c:\\test.msp\" X=Y REINSTALL=ALL REINSTALLMODE=vomus" },
        { SequenceInstall, L"c:\\test.msp", L"c:\\package.msi", // patch, package
        L"X=Y", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"ALL", L"vomus", // REINSTALL, REINSTALLMODE
        L"msiexec /p \"c:\\test.msp\" /a \"c:\\package.msi\" X=Y REINSTALL=ALL REINSTALLMODE=vomus" },
        { SequenceUninstall, L"test.msp", L"", // patch, package
        L"", L"", // cmdparameters, uninstall_cmdparameters
        L"", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /uninstall \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"test.msp") + L"\"" },
        { SequenceUninstall, L"test.msp", L"", // patch, package
        L"", L"", // cmdparameters, uninstall_cmdparameters
        L"uninstall_test.msp", L"", // uninstall_patch, uninstall_package
        L"", L"", // REINSTALL, REINSTALLMODE
        L"msiexec /uninstall \"" + DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), L"uninstall_test.msp") + L"\"" },
        { SequenceUninstall, L"c:\\test.msp", L"c:\\package.msi", // patch, package
        L"X=Y", L"T=U", // cmdparameters, uninstall_cmdparameters
        L"", L"c:\\package.msi", // uninstall_patch, uninstall_package
        L"ALL", L"vomus", // REINSTALL, REINSTALLMODE
        L"msiexec /uninstall \"c:\\test.msp\" /package \"c:\\package.msi\" T=U" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstallSequenceState state;
        InstallerSession::Instance->sequence = testdata[i].sequence;
        MspComponent component;
        component.patch = testdata[i].patch;
        component.package = testdata[i].package;
        component.cmdparameters = testdata[i].cmdparameters;
        component.uninstall_cmdparameters = testdata[i].uninstall_cmdparameters;
        component.uninstall_patch = testdata[i].uninstall_patch;
        component.uninstall_package = testdata[i].uninstall_package;
        component.reinstall = testdata[i].reinstall;
        component.reinstallmode = testdata[i].reinstallmode;
        std::wstring command = component.GetCommandLine();
        std::wcout << std::endl << L" " << command;
        Assert::IsTrue(testdata[i].command == command);
    }
}

void MspComponentUnitTests::testMustReboot()
{
    MspComponent component;
    Assert::IsTrue(! component.IsRebootRequired());
    component.mustreboot = true;
    Assert::IsTrue(component.IsRebootRequired());
}
