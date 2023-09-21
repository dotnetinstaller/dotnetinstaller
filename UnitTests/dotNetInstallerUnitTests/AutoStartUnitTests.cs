// <copyright file="AutoStartUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>

namespace dotNetInstallerUnitTests
{
    using System;
    using System.Diagnostics;
    using System.IO;
    using dotNetUnitTestsRunner;
    using InstallerLib;
    using NUnit.Framework;

    [TestFixture]
    public class AutoStartUnitTests : UnitTestsBase
    {
        [Test]
        public void TestAutoStart()
        {
            Console.WriteLine("TestAutoStart");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = string.Empty;
            setupConfiguration.installation_none = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // marker that makes installed check succeeed after installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);
            InstalledCheckFile check = new InstalledCheckFile();
            check.filename = markerFilename;
            check.comparison = installcheckfile_comparison.exists;
            component.Children.Add(check);

            // configuration
            component.installcompletemessage = string.Empty;
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.reboot = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            Assert.IsTrue(File.Exists(markerFilename));
            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestAutoStartCmdLine()
        {
            Console.WriteLine("TestAutoStartCmdLine");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = false;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = string.Empty;
            setupConfiguration.installation_none = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // marker that makes installed check succeeed after installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);
            InstalledCheckFile check = new InstalledCheckFile();
            check.filename = markerFilename;
            check.comparison = installcheckfile_comparison.exists;
            component.Children.Add(check);

            // configuration
            component.installcompletemessage = string.Empty;
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.reboot = false;
            options.autostart = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            Assert.IsTrue(File.Exists(markerFilename));
            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestNoAutoStart()
        {
            Console.WriteLine("TestNoAutoStart");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = false;
            setupConfiguration.installation_completed = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = "cmd.exe /C exit /b 0";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            Process p = dotNetInstallerExeUtils.Detach(options);
            Assert.IsFalse(p.WaitForExit(2 * 1000));
            p.Kill();
            p.WaitForExit();
            Assert.AreEqual(-1, p.ExitCode);
            File.Delete(configFilename);
        }

        [Test]
        public void TestAutoContinueOnReboot()
        {
            Console.WriteLine("TestAutoContinueOnReboot");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = false;
            setupConfiguration.supports_uninstall = false;
            setupConfiguration.auto_continue_on_reboot = true;
            setupConfiguration.installation_completed = string.Empty;
            setupConfiguration.installation_none = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // marker that makes installed check succeeed after installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);
            InstalledCheckFile check = new InstalledCheckFile();
            check.filename = markerFilename;
            check.comparison = installcheckfile_comparison.exists;
            component.Children.Add(check);
            component.installcompletemessage = string.Empty;
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.reboot = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            Assert.IsTrue(File.Exists(markerFilename));
            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestNoAutoContinueOnReboot()
        {
            Console.WriteLine("TestNoAutoContinueOnReboot");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_continue_on_reboot = false;
            setupConfiguration.installation_completed = string.Empty;
            configFile.Children.Add(setupConfiguration);

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = "cmd.exe /C exit /b 0";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;
            options.reboot = true;
            Process p = dotNetInstallerExeUtils.Detach(options);
            Assert.IsFalse(p.WaitForExit(2 * 1000));
            p.Kill();
            p.WaitForExit();
            Assert.AreEqual(-1, p.ExitCode);
            File.Delete(configFilename);
        }
    }
}