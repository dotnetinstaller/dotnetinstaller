#include "StdAfx.h"
#include "ConfigFileUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ConfigFileUnitTests::testLoadPackagedSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.1");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 4);
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    ComponentPtr component = configuration->components[0];
    Assert::IsTrue(component->type == component_type_msi);
}

void ConfigFileUnitTests::testLoadInstallCheckProductSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\InstallCheckProduct\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.0");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 1);
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->value == L"InstallCheckProduct setup sample");
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 2);
    // \todo: verify that product checks are correct
}

void ConfigFileUnitTests::testLoadInstallCheckOperators()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\InstallCheckOperators\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.0");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 1);
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->value == L"InstallCheckOperators setup sample");
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 4);
    Assert::IsTrue(configuration->components[0]->type == component_type_cmd);
    Assert::IsTrue(configuration->components[1]->type == component_type_cmd);
    Assert::IsTrue(configuration->components[2]->type == component_type_cmd);
    Assert::IsTrue(configuration->components[3]->type == component_type_cmd);
    // \todo: verify that operators tree is correct
}

void ConfigFileUnitTests::testLoadStandaloneSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.0");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 0);
    // configurations with components
    Assert::IsTrue(config.size() == 2);
    // \todo: verify that lcid's are different
}

void ConfigFileUnitTests::testLoadDownloadSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\DownloadSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.0");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 0);
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    ComponentPtr component = configuration->components[0];
    Assert::IsTrue(component->type == component_type_cmd);
    // the component has a download dialog with one file
    Assert::IsTrue(get(component->downloaddialog) != NULL);
    Assert::IsTrue(component->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadReferenceSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\ReferenceSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.0");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 0);
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const ReferenceConfiguration * configuration = reinterpret_cast<ReferenceConfiguration *>(get(config[0]));
    // the reference has a download dialog
    Assert::IsTrue(get(configuration->downloaddialog) != NULL);
    Assert::IsTrue(configuration->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadResource()
{
    ConfigFile config;
    config.LoadResource(GetCurrentModuleHandle(), L"RES_CONFIGURATION");
    // configurations properties
    Assert::IsTrue(! config.schema.generator.empty());
    Assert::IsTrue(! config.schema.version.empty());
    Assert::IsTrue(config.lcidtype == DVLib::LcidUserExe);
    Assert::IsTrue(config.uilevel == InstallUILevelFull);
    Assert::IsTrue(config.fileversion == L"1.0.0.1");
    Assert::IsTrue(config.productversion == L"1.0.0.0");
    // file attributes
    Assert::IsTrue(config.fileattributes.size() == 4);
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
    Assert::IsTrue(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    ComponentPtr component = configuration->components[0];
    Assert::IsTrue(component->type == component_type_msi);
}

void ConfigFileUnitTests::testGetSupportedConfigurations()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // there're two configurations in this sample, opposite of each other
    Assert::IsTrue(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
}

void ConfigFileUnitTests::testLoadOsFiltersSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\OsFilters\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // there're three components in this sample, but only 1 will show because the os filters don't overlap
    Assert::IsTrue(config.size() == 1);
    Assert::IsTrue(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 3);	
}


void ConfigFileUnitTests::testLoadMultipleSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultipleConfig\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations properties
    Assert::IsTrue(config.size() == 2);	
    // install sequence
    std::vector<ConfigurationPtr> install_configurations = config.GetSupportedConfigurations(LcidUser, SequenceInstall);
    Assert::IsTrue(configuration_reference == install_configurations[0]->type);
    Assert::IsTrue(configuration_install == install_configurations[1]->type);
    InstallConfiguration * p_configuration_install = reinterpret_cast<InstallConfiguration *>(get(install_configurations[1]));
    Components install_components = p_configuration_install->GetSupportedComponents(LcidUser, SequenceInstall);
    Assert::IsTrue(install_components.size() == 2);
    Assert::IsTrue(install_components[0]->id == L"setup1");
    Assert::IsTrue(install_components[1]->id == L"setup2");
    Components uninstall_components = p_configuration_install->GetSupportedComponents(LcidUser, SequenceUninstall);
    Assert::IsTrue(uninstall_components.size() == 2);
    Assert::IsTrue(uninstall_components[0]->id == L"setup2");
    Assert::IsTrue(uninstall_components[1]->id == L"setup1");
    std::vector<ConfigurationPtr> uninstall_configurations = config.GetSupportedConfigurations(LcidUser, SequenceUninstall);
    Assert::IsTrue(configuration_install == uninstall_configurations[0]->type);
    Assert::IsTrue(configuration_reference == uninstall_configurations[1]->type);	
}

void ConfigFileUnitTests::testLoadMultilingualSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // there're two configurations in this sample, but only 1 will show because the lcids don't overlap
    Assert::IsTrue(config.size() == 2);
    Assert::IsTrue(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
    Assert::IsTrue(config.GetSupportedConfigurations(1040, SequenceInstall).size() == 1);
    Assert::IsTrue(config.GetSupportedConfigurations(1040, SequenceInstall)[0]->lcid_filter == L"1040");
}

void ConfigFileUnitTests::testLoadLicenseAgreement()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(),
        L"..\\..\\..\\Samples\\LicenseAgreement\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // there's one configuration in this sample
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    Assert::IsTrue(configuration->controls.size() == 2);
    Assert::IsTrue(configuration->controls[0]->type == control_type_license);
    Assert::IsTrue(configuration->controls[1]->type == control_type_image);
}

void ConfigFileUnitTests::testLoadCustomInputSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\CustomInputSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // there's one configuration in this sample
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    Assert::IsTrue(configuration->controls.size() == 6);
    Assert::IsTrue(configuration->controls[0]->type == control_type_label);
    Assert::IsTrue(configuration->controls[1]->type == control_type_label);
    Assert::IsTrue(configuration->controls[2]->type == control_type_checkbox);
    Assert::IsTrue(configuration->controls[3]->type == control_type_browse);
    Assert::IsTrue(configuration->controls[4]->type == control_type_browse);
    Assert::IsTrue(configuration->controls[5]->type == control_type_hyperlink);
}

void ConfigFileUnitTests::testLoadPatchSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\PatchSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 2);
    ComponentPtr component_msi = configuration->components[0];
    Assert::IsTrue(component_msi->type == component_type_msi);
    ComponentPtr component_msp = configuration->components[1];
    Assert::IsTrue(component_msp->type == component_type_msp);
}

void ConfigFileUnitTests::testLoadExeSetup()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\ExeSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFile config;
    config.LoadFile(configxml);
    // configurations with components
    Assert::IsTrue(config.size() == 1);
    const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
    Assert::IsTrue(configuration->components.size() == 1);
    ComponentPtr component_exe = configuration->components[0];
    Assert::IsTrue(component_exe->type == component_type_exe);	
}
