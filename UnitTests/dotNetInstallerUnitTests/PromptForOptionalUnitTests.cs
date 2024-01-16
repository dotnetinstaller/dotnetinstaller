// <copyright file="PromptForOptionalUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>

namespace dotNetInstallerUnitTests
{
    using System;
    using System.IO;
    using dotNetUnitTestsRunner;
    using InstallerLib;
    using NUnit.Framework;

    [TestFixture]
    public class PromptForOptionalUnitTests : UnitTestsBase
    {
        [Test]
        public void TestPromptForOptionalNotSet()
        {
            Console.WriteLine("TestPromptForOptionalNotSet");

            // configuration with a required and optional component that will auto-start
            // and won't prompt or execute the optional component
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            ConfigFile configFile = new ConfigFile();

            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.prompt_for_optional_components = false;
            setupConfiguration.installation_completed = string.Empty;
            setupConfiguration.installation_none = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // dummy required component
            ComponentCmd component_required = new ComponentCmd();
            setupConfiguration.Children.Add(component_required);
            component_required.required_install = true;
            component_required.supports_install = true;
            component_required.command = "dummy";

            InstalledCheckRegistry check_required = new InstalledCheckRegistry();
            check_required.fieldname = string.Empty;
            check_required.path = "SOFTWARE";
            check_required.comparison = installcheckregistry_comparison.exists;
            component_required.Children.Add(check_required);

            // dummy optional component
            ComponentCmd component_optional = new ComponentCmd();
            setupConfiguration.Children.Add(component_optional);
            component_optional.required_install = false;
            component_optional.supports_install = true;
            component_optional.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);

            InstalledCheckFile check_optional = new InstalledCheckFile();
            check_optional.filename = markerFilename;
            check_optional.comparison = installcheckfile_comparison.exists;
            component_optional.Children.Add(check_optional);

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // will not auto close since all components installed successfully
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.autostart = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));

            Assert.IsFalse(File.Exists(markerFilename));

            File.Delete(configFilename);
        }

        [Test]
        public void TestPromptForOptionalSet()
        {
            Console.WriteLine("TestPromptForOptionalSet");

            // configuration with a required and optional component
            // will prompt for the optional component, auto-start and install it
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            ConfigFile configFile = new ConfigFile();

            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.prompt_for_optional_components = true;
            setupConfiguration.installation_completed = string.Empty;
            setupConfiguration.installation_none = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // dummy required component
            ComponentCmd component_required = new ComponentCmd();
            setupConfiguration.Children.Add(component_required);
            component_required.required_install = true;
            component_required.supports_install = true;
            component_required.command = "dummy";

            InstalledCheckRegistry check_required = new InstalledCheckRegistry();
            check_required.fieldname = string.Empty;
            check_required.path = "SOFTWARE";
            check_required.comparison = installcheckregistry_comparison.exists;
            component_required.Children.Add(check_required);

            // dummy optional component
            ComponentCmd component_optional = new ComponentCmd();
            setupConfiguration.Children.Add(component_optional);
            component_optional.required_install = false;
            component_optional.supports_install = true;
            component_optional.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);

            InstalledCheckFile check_optional = new InstalledCheckFile();
            check_optional.filename = markerFilename;
            check_optional.comparison = installcheckfile_comparison.exists;
            component_optional.Children.Add(check_optional);

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // will not auto close since all components installed successfully
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.autostart = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));

            Assert.IsTrue(File.Exists(markerFilename));

            File.Delete(configFilename);
            File.Delete(markerFilename);
        }
    }
}
