#include "StdAfx.h"
#include "ExeComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ExeComponentUnitTests);

using namespace DVLib::UnitTests;

void ExeComponentUnitTests::testExecInstall()
{
    ExeComponent component;
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 0";
    component.id = "execomponent";
    component.Exec();
    component.Wait();
    try
    {
        component.executable = L"cmd.exe";
        component.exeparameters = L"/C exit /b 1";
        component.Exec();
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << ex.what();
    }
}

void ExeComponentUnitTests::testExecInstallResponseFile()
{
    std::wstring responsefile_source = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), L"execomponentut.rsp");
    std::wstring responsefile_target = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), L"execomponentut.out");
    if (DVLib::FileExists(responsefile_target)) DVLib::FileDelete(responsefile_target);
    std::string data_s = "P=#APPPATH";
    std::vector<char> data(data_s.begin(), data_s.end());
    DVLib::FileWrite(responsefile_source, data);
    ExeComponent component;
    component.executable = L"cmd.exe";
    component.id = "rsptest";
    component.exeparameters = L"/C IF EXIST \"" + responsefile_target + L"\" ( exit /b 0 ) ELSE ( exit /b 1 )";
    component.responsefile_source = responsefile_source;
    component.responsefile_target = responsefile_target;
    component.responsefile_format = L"ini"; // ResponseFileFormatNone;
    component.Exec();
    component.Wait();
    CPPUNIT_ASSERT(DVLib::FileExists(responsefile_target));
    std::vector<char> data_s_target = DVLib::FileReadToEnd(responsefile_target);
    CPPUNIT_ASSERT(std::string(data_s_target.begin(), data_s_target.end()) == 
        DVLib::wstring2string(InstallerSession::Instance->ExpandVariables(DVLib::string2wstring(data_s))));
    DVLib::FileDelete(responsefile_source);
    DVLib::FileDelete(responsefile_target);
}

void ExeComponentUnitTests::testExecInstallDir()
{
    // install
    std::wstring install_dir = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    ExeComponent component;
    component.executable = L"cmd.exe";
    component.uninstall_executable = L"cmd.exe";
    component.install_directory = install_dir;
    component.exeparameters = L"/C exit /b 0";
    component.uninstall_exeparameters = L"/C exit /b 0";
    component.Exec();
    component.Wait();
    CPPUNIT_ASSERT(DVLib::DirectoryExists(install_dir));
    DVLib::DirectoryDelete(install_dir);
    // uninstall
    InstallSequenceState state;
    InstallerSession::Instance->sequence = SequenceUninstall;
    component.Exec();
    component.Wait();
    CPPUNIT_ASSERT(! DVLib::DirectoryExists(install_dir));
}

void ExeComponentUnitTests::testExecShell()
{
    std::wstring filename = DVLib::GetTemporaryFileNameW();
    DVLib::FileMove(filename, filename + L".txt");
    filename = filename + L".txt";

    ExeComponent component;
    component.executable = filename;
    // default execution method is CreateProcess
    CPPUNIT_ASSERT(component.execution_method == DVLib::CemCreateProcess);
    try
    {
        component.Exec();
        throw "expected std::exception";
    }
    catch (std::exception& ex)
    {
        // expected - CreateProcess cannot run text files
        CPPUNIT_ASSERT(strstr(ex.what(), "CreateProcess") != NULL);
        CPPUNIT_ASSERT(strstr(ex.what(), "0x800700c1") != NULL);
    }

    component.execution_method = DVLib::CemShellExecute;
    component.Exec();
    ::TerminateProcess(component.m_process_handle, 0);
    component.Wait();

    DVLib::FileDelete(filename);
}

void ExeComponentUnitTests::testMustReboot()
{
    ExeComponent component;
    CPPUNIT_ASSERT(! component.IsRebootRequired());
    component.mustreboot = L"True";
    CPPUNIT_ASSERT(component.IsRebootRequired());
}

void ExeComponentUnitTests::testReturnCodeRebootRequired()
{
    ExeComponent component;
    // a success value
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 0";
    component.id = "execomponent";
    component.Exec();
    component.Wait();
    CPPUNIT_ASSERT(! component.IsRebootRequired());
    component.returncodes_reboot = L"0";
    component.Exec();
    component.Wait();
    CPPUNIT_ASSERT(component.IsRebootRequired());
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 1053";
    component.id = "execomponent";
    component.returncodes_reboot = L"0,1053";
    component.Exec();
    component.Wait();
    // component will succeed, since this is a reboot return code
    CPPUNIT_ASSERT(component.IsRebootRequired());

    // component will fail since the return code is neither a default success (0) nor a reboot error code
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 1055";
    component.id = "execomponent";
    try
    {
        component.Exec();
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // expected
    }
    CPPUNIT_ASSERT(! component.IsRebootRequired());

    // Test legacy method handling 0x84BE0BC2
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b -2067919934"; // 0x84BE0BC2
    component.id = "execomponent";
    component.returncodes_reboot = L"2227047362";
    component.Exec();
    component.Wait();
    // component will succeed, since this is a reboot return code
    CPPUNIT_ASSERT(component.IsRebootRequired());

    // Test hex code
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 3010"; // 0xBC2
    component.id = "execomponent";
    component.returncodes_reboot = L"0x84BE0BC2,0xBC2";
    component.Exec();
    component.Wait();
    // component will succeed, since this is a reboot return code
    CPPUNIT_ASSERT(component.IsRebootRequired());

    // Test hex code
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b -2067919934"; // 0x84BE0BC2
    component.returncodes_reboot = L"0x84BE0BC2,0xBC2";
    component.Exec();
    component.Wait();
    // component will succeed, since this is a reboot return code
    CPPUNIT_ASSERT(component.IsRebootRequired());
}

void ExeComponentUnitTests::testReturnCodeSuccess()
{
    ExeComponent component;
    // a success value
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 1";
    component.id = "execomponent";
    component.returncodes_success = L"1,3010";
    component.Exec();
    // component will succeed, return code in success list
    component.Wait();

    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 3010";
    component.id = "execomponent";
    component.Exec();
    // component will succeed, return code in success list
    component.Wait();

    // component will fail since the return code is not in the success list
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 0";
    component.id = "execomponent";
    try
    {
        component.Exec();
        component.Wait();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {
        // expected
    }

    // Test hex code
    component.executable = L"cmd.exe";
    component.exeparameters = L"/C exit /b 3010"; // 0xBC2
    component.id = "execomponent";
    component.returncodes_success = L"0,0x0BC2";
    component.Exec();
    // component will succeed, return code in success list
    component.Wait();
}

void ExeComponentUnitTests::testLoad()
{
    TiXmlDocument doc;
    doc.Parse("<component type=\"exe\" \
              executable=\"test-dir\\test.exe\" \
              exeparameters=\"/i\" \
              uninstall_executable=\"test-dir\\testu.exe\" \
              uninstall_exeparameters=\"/u\" \
              execution_method=\"ShellExecute\"/>");
    ExeComponent component;
    component.Load(doc.RootElement());
    CPPUNIT_ASSERT(component.executable.GetValue() == L"test-dir\\test.exe");
    CPPUNIT_ASSERT(component.exeparameters.GetValue() == L"/i");
    CPPUNIT_ASSERT(component.uninstall_executable.GetValue() == L"test-dir\\testu.exe");
    CPPUNIT_ASSERT(component.uninstall_exeparameters.GetValue() == L"/u");
    CPPUNIT_ASSERT(component.execution_method == DVLib::CemShellExecute);
}