using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using dotNetUnitTestsRunner;
using System.IO;
using System.Diagnostics;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class AutoStartUnitTests
    {
        [Test]
        public void TestAutoStart()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
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
            options.reboot = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestNoAutoStart()
        {
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
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = false;
            setupConfiguration.auto_continue_on_reboot = true;
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
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestNoAutoContinueOnReboot()
        {
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