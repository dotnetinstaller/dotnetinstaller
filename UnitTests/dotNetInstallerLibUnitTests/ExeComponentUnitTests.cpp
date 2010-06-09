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