#include "StdAfx.h"
#include "ConfigFileUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ConfigFileUnitTests);

using namespace DVLib::UnitTests;

void ConfigFileUnitTests::testLoadPackagedSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.1");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_msi);
}

void ConfigFileUnitTests::testLoadInstallCheckProductSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\InstallCheckProduct\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"InstallCheckProduct setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 2);
	// \todo: verify that product checks are correct
}

void ConfigFileUnitTests::testLoadInstallCheckOperators()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\InstallCheckOperators\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"InstallCheckOperators setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 4);
	CPPUNIT_ASSERT(configuration->components[0]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[1]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[2]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[3]->type == component_type_cmd);
	// \todo: verify that operators tree is correct
}

void ConfigFileUnitTests::testLoadStandaloneSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 2);
	// \todo: verify that lcid's are different
}

void ConfigFileUnitTests::testLoadDownloadSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\DownloadSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_cmd);
	// the component has a download dialog with one file
	CPPUNIT_ASSERT(get(component->downloaddialog) != NULL);
	CPPUNIT_ASSERT(component->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadReferenceSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\ReferenceSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const ReferenceConfiguration * configuration = reinterpret_cast<ReferenceConfiguration *>(get(config[0]));
	// the reference has a download dialog
	CPPUNIT_ASSERT(get(configuration->downloaddialog) != NULL);
	CPPUNIT_ASSERT(configuration->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadResource()
{
	ConfigFile config;
	config.LoadResource(NULL, L"RES_CONFIGURATION");
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.1");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_msi);
}

void ConfigFileUnitTests::testGetSupportedConfigurations()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're two configurations in this sample, opposite of each other
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0).size() == 1);
}

void ConfigFileUnitTests::testLoadOsFiltersSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\OsFilters\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're three components in this sample, but only 1 will show because the os filters don't overlap
	CPPUNIT_ASSERT(config.size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0).size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 3);	
}

void ConfigFileUnitTests::testLoadMultilingualSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're two configurations this sample, but only 1 will show because the lcids don't overlap
	CPPUNIT_ASSERT(config.size() == 2);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0).size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(1040).size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(1040)[0]->lcid_filter == L"1040");
}