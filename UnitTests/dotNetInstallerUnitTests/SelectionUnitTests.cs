// <copyright file="SelectionUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class SelectionUnitTests : UnitTestsBase
    {
        [Test]
        public void TestDefaultSelectionInstall()
        {
            Console.WriteLine("TestDefaultSelectionInstall");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // dummy component 1
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.command = "cmd.exe /C exit /b 57";
            component1.required_install = true;
            component1.selected_install = false;

            // dummy component 2
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.command = "cmd.exe /C exit /b 42";
            component2.required_install = true;
            component2.selected_install = true;

            // second component is selected and runs, not the first one
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            Assert.AreEqual(42, dotNetInstallerExeUtils.Run(options));

            // first component is selected and runs
            component1.selected_install = true;
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(57, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestDefaultSelectionUninstall()
        {
            Console.WriteLine("TestDefaultSelectionUninstall");

            InstalledCheckFile existsCheck = new InstalledCheckFile();
            existsCheck.filename = dotNetInstallerExeUtils.Executable;
            existsCheck.comparison = installcheckfile_comparison.exists;
            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // dummy component 1
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.uninstall_command = "cmd.exe /C exit /b 57";
            component1.selected_uninstall = true;
            component1.supports_uninstall = true;
            component1.Children.Add(existsCheck);

            // dummy component 2
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.uninstall_command = "cmd.exe /C exit /b 42";
            component2.selected_uninstall = false;
            component2.supports_uninstall = true;
            component2.Children.Add(existsCheck);

            // second component is selected and runs, not the first one
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = true;
            Assert.AreEqual(57, dotNetInstallerExeUtils.Run(options));

            // first component is selected and runs
            component2.selected_uninstall = true;
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(42, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }
    }
}
