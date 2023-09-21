// <copyright file="AutoCloseUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class AutoCloseUnitTests : UnitTestsBase
    {
        [Test]
        public void TestAutoClosesAfterInstallWhenComponentInstallSucceeds()
        {
            Console.WriteLine("TestAutoClosesAfterInstallWhenComponentInstallSucceeds");

            // configuration with a component that will run and succeed and so dni will auto close

            // marker that makes installed check succeed after installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = null;
            configFile.Children.Add(setupConfiguration);

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.required_install = true;
            component.supports_install = true;
            component.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);

            InstalledCheckFile check = new InstalledCheckFile();
            check.filename = markerFilename;
            check.comparison = installcheckfile_comparison.exists;
            component.Children.Add(check);

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;

            // will auto close since all components installed successfully
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options, TimeSpan.FromSeconds(3)));

            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestNotAutoClosesAfterInstallWhenComponentInstallFails()
        {
            Console.WriteLine("TestNotAutoClosesAfterInstallWhenComponentInstallFails");

            // configuration with a component that will run and fail and so dni will not auto close
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = null;
            setupConfiguration.failed_exec_command_continue = string.Empty;
            configFile.Children.Add(setupConfiguration);

            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b 1";
            cmd.required_install = true;
            cmd.supports_install = true;
            setupConfiguration.Children.Add(cmd);

            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExists";
            check.comparison = installcheckregistry_comparison.exists;
            cmd.Children.Add(check);

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // will not auto close since all required components failed to install
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(configFilename));

            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;

            Process p = dotNetInstallerExeUtils.Detach(options);
            Assert.IsFalse(p.WaitForExit(3 * 1000));
            p.Kill();
            p.WaitForExit();
            Assert.AreEqual(-1, p.ExitCode);

            File.Delete(configFilename);
        }

        [Test]
        public void TestAutoClosesBeforeInstallWhenComponentIsAlreadyInstalled()
        {
            Console.WriteLine("TestAutoClosesBeforeInstallWhenComponentIsAlreadyInstalled");

            // configuration with a component that is already installed and so dni will auto close

            // marker that makes installed check succeed before installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            File.Create(markerFilename).Close();

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = null;
            setupConfiguration.installation_none = null;
            setupConfiguration.supports_uninstall = false; // prevent switching to uninstall
            configFile.Children.Add(setupConfiguration);

            // dummy component
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.required_install = true;
            component.supports_install = true;
            component.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);

            InstalledCheckFile check = new InstalledCheckFile();
            check.filename = markerFilename;
            check.comparison = installcheckfile_comparison.exists;
            component.Children.Add(check);

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;

            // will auto close since all components are already installed
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options, TimeSpan.FromSeconds(3)));

            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestAutoClosesAfterInstallWhenCheckedComponentsInstallSucceeds()
        {
            Console.WriteLine("TestAutoClosesAfterInstallWhenCheckedComponentsInstallSucceeds");

            // configuration with two selected components and one unselected component
            // selected components will run and succeed, and so dni will auto close

            // marker that makes installed check succeed after installation
            string markerFilename1 = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            string markerFilename2 = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
            setupConfiguration.installation_completed = null;
            configFile.Children.Add(setupConfiguration);

            // required and selected component
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.required_install = true;
            component1.selected_install = true;
            component1.supports_install = true;
            component1.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename1);

            InstalledCheckFile check1 = new InstalledCheckFile();
            check1.filename = markerFilename1;
            check1.comparison = installcheckfile_comparison.exists;
            component1.Children.Add(check1);

            // optional and selected component
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.required_install = false;
            component2.selected_install = true;
            component2.supports_install = true;
            component2.command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename2);

            InstalledCheckFile check2 = new InstalledCheckFile();
            check2.filename = markerFilename2;
            check2.comparison = installcheckfile_comparison.exists;
            component2.Children.Add(check2);

            // optional and unselected component
            ComponentCmd component3 = new ComponentCmd();
            setupConfiguration.Children.Add(component3);
            component3.required_install = false;
            component3.selected_install = false;
            component3.supports_install = true;
            component3.command = "cmd.exe /C exit /b 1";

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.quiet = false;

            // will auto close since all checked components were installed
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options, TimeSpan.FromSeconds(6)));

            File.Delete(configFilename);
            File.Delete(markerFilename1);
            File.Delete(markerFilename2);
        }
    }
}
