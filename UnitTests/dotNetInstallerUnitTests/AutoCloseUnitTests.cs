using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using dotNetUnitTestsRunner;
using System.IO;
using Microsoft.Win32;
using System.Diagnostics;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class AutoCloseUnitTests
    {
        [Test]
        public void TestAutoCloseIfInstalledWithComponentInstallSuccess()
        {
            Console.WriteLine("TestAutoCloseIfInstalledWithComponentInstallSuccess");

            //configuration with a component that will run and succeed and so dni will auto close

            // marker that makes installed check succeeed after installation
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
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

            // will auto close since all components installed successfully
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));

            File.Delete(configFilename);
            File.Delete(markerFilename);
        }

        [Test]
        public void TestAutoCloseIfInstalledWithComponentInstallFailure()
        {
            Console.WriteLine("TestAutoCloseIfInstalledWithComponentInstallFailure");

            //configuration with a component that will run and fail and so dni will not auto close

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.auto_close_if_installed = true;
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
    }
}
