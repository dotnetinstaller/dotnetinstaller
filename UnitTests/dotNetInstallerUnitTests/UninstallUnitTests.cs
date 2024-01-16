// <copyright file="UninstallUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class UninstallUnitTests : UnitTestsBase
    {
        [Test]
        public void TestSupportsNone()
        {
            Console.WriteLine("TestSupportsNone");

            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = false;
            setupConfiguration.supports_uninstall = false;

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestSupportsInstall()
        {
            Console.WriteLine("TestSupportsInstall");

            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = true;
            setupConfiguration.supports_uninstall = false;

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));

            // uninstall is not supported
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = true;
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestSupportsUninstall()
        {
            Console.WriteLine("TestSupportsUninstall");

            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = false;
            setupConfiguration.supports_uninstall = true;

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(configFilename));

            // uninstall is not supported
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUninstallSwitch()
        {
            Console.WriteLine("TestUninstallSwitch");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd.required_install = true;
            cmd.uninstall_command = "cmd.exe /C exit /b 0";
            cmd.supports_install = true;
            cmd.supports_uninstall = true;
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute uninstall
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = false;
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(options));
            options.uninstall = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUninstallAuto()
        {
            Console.WriteLine("TestUninstallAuto");

            // a component that's already installed
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.id = "cmd1";
            cmd.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd.uninstall_command = "cmd.exe /C exit /b 0";
            cmd.supports_install = true;
            cmd.supports_uninstall = true;
            InstalledCheckFile check = new InstalledCheckFile();
            cmd.Children.Add(check);
            check.comparison = installcheckfile_comparison.exists;
            check.filename = dotNetInstallerExeUtils.Executable;

            // a second component that doesn't support uninstall
            ComponentCmd cmd2 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd2);
            cmd2.id = "cmd2";
            cmd2.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.uninstall_command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.supports_install = true;
            cmd2.supports_uninstall = false;
            cmd2.Children.Add(check);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // will fallback to uninstall since all components are installed
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUninstallMsiSilentMode()
        {
            Console.WriteLine("TestUninstallMsiSilentMode");

            InstallUILevel[] testUILevels = { InstallUILevel.basic, InstallUILevel.silent };
            foreach (InstallUILevel uilevel in testUILevels)
            {
                // a configuration with no components
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                ComponentMsi msi = new ComponentMsi();
                msi.package = "msidoesntexist.msi";
                msi.uninstall_cmdparameters = string.Empty;
                msi.uninstall_cmdparameters_basic = "/qb-";
                msi.uninstall_cmdparameters_silent = "/qb-";
                InstalledCheckFile self = new InstalledCheckFile();
                self.filename = dotNetInstallerExeUtils.Executable;
                self.comparison = installcheckfile_comparison.exists;
                msi.Children.Add(self);
                setupConfiguration.Children.Add(msi);

                // silent install, no dialog messages
                configFile.ui_level = uilevel;

                // save config file
                string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", configFilename);
                configFile.SaveAs(configFilename);

                // execute dotNetInstaller
                dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
                options.uninstall = true;
                Assert.AreEqual(1619, dotNetInstallerExeUtils.Run(options));
                File.Delete(configFilename);
            }
        }

        [Test]
        public void TestUninstallMspSilentMode()
        {
            Console.WriteLine("TestUninstallMspSilentMode");

            InstallUILevel[] testUILevels = { InstallUILevel.basic, InstallUILevel.silent };
            foreach (InstallUILevel uilevel in testUILevels)
            {
                // a configuration with no components
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                ComponentMsp msp = new ComponentMsp();
                msp.package = "mspdoesntexist.msp";
                msp.uninstall_cmdparameters = string.Empty;
                msp.uninstall_cmdparameters_basic = "/qb-";
                msp.uninstall_cmdparameters_silent = "/qb-";
                InstalledCheckFile self = new InstalledCheckFile();
                self.filename = dotNetInstallerExeUtils.Executable;
                self.comparison = installcheckfile_comparison.exists;
                msp.Children.Add(self);
                setupConfiguration.Children.Add(msp);

                // silent install, no dialog messages
                configFile.ui_level = uilevel;

                // save config file
                string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", configFilename);
                configFile.SaveAs(configFilename);

                // execute dotNetInstaller
                dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
                options.uninstall = true;
                Assert.AreEqual(1619, dotNetInstallerExeUtils.Run(options));
                File.Delete(configFilename);
            }
        }

        [Test]
        public void TestUninstallAutoWithOptionalComponent()
        {
            Console.WriteLine("TestUninstallAutoWithOptionalComponent");

            // a component that's already installed
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.id = "cmd1";
            cmd.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd.uninstall_command = "cmd.exe /C exit /b 0";
            cmd.supports_install = true;
            cmd.supports_uninstall = true;
            InstalledCheckFile check = new InstalledCheckFile();
            cmd.Children.Add(check);
            check.comparison = installcheckfile_comparison.exists;
            check.filename = dotNetInstallerExeUtils.Executable;

            // a second component that is optional
            ComponentCmd cmd2 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd2);
            cmd2.id = "cmd2";
            cmd2.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.uninstall_command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.supports_install = true;
            cmd2.required_install = false;
            cmd2.supports_uninstall = false;
            cmd2.Children.Add(check);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // will fallback to uninstall since all required components are installed
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }
    }
}
