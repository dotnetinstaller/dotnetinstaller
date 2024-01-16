// <copyright file="ContinueOnErrorUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class ContinueOnErrorTests : UnitTestsBase
    {
        [Test]
        public void TestContinueOnError()
        {
            Console.WriteLine("TestContinueOnError");

            ConfigFile configFile = new ConfigFile();
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            string markerFilename1 = string.Format("{0}.1", markerFilename);
            string markerFilename2 = string.Format("{0}.2", markerFilename);
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd1 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd1);
            cmd1.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 1", markerFilename1);
            cmd1.required_install = true;
            ComponentCmd cmd2 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd2);
            cmd2.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 2", markerFilename2);
            cmd2.required_install = true;

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(configFilename));
            Assert.IsTrue(File.Exists(markerFilename1));
            Assert.IsFalse(File.Exists(markerFilename2));
            File.Delete(markerFilename1);

            // allow continue on error (user prompted) -> no effect, this is a prompt that defaults to false in silent mode
            cmd1.allow_continue_on_error = true;
            cmd2.allow_continue_on_error = true;
            configFile.SaveAs(configFilename);
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(configFilename));
            Assert.IsTrue(File.Exists(markerFilename1));
            Assert.IsFalse(File.Exists(markerFilename2));
            File.Delete(markerFilename1);

            // continue on error by default -> continues on the first and the second component, returns the last error code
            cmd1.default_continue_on_error = true;
            cmd2.default_continue_on_error = true;
            configFile.SaveAs(configFilename);

            // the return code of the first failure is saved
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(configFilename));
            Assert.IsTrue(File.Exists(markerFilename1));
            Assert.IsTrue(File.Exists(markerFilename2));
            File.Delete(markerFilename1);
            File.Delete(markerFilename2);
            File.Delete(configFilename);
        }

        [Test]
        public void TestContinueOnErrorNoMessage()
        {
            Console.WriteLine("TestContinueOnErrorNoMessage");

            // test that with all failed_exec_command_continue blanked,
            // user is never asked a question in full UI mode (not blocked)
            ConfigFile configFile = new ConfigFile();
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            string markerFilename1 = string.Format("{0}.1", markerFilename);
            string markerFilename2 = string.Format("{0}.2", markerFilename);
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // running in full UI mode, auto-start
            setupConfiguration.auto_start = true;

            // running in full UI mode, installation is expected to fail, auto-close
            setupConfiguration.auto_close_on_error = true;
            setupConfiguration.installation_none = string.Empty;
            setupConfiguration.installation_completed = string.Empty;
            ComponentCmd cmd1 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd1);
            cmd1.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 1", markerFilename1);
            cmd1.required_install = true;
            ComponentCmd cmd2 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd2);
            cmd2.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 2", markerFilename2);
            cmd2.required_install = true;

            // continue on error by default -> continues on the first and the second component, returns the last error code
            cmd1.default_continue_on_error = true;
            cmd2.default_continue_on_error = true;

            // remove all continue or stop error messages
            setupConfiguration.failed_exec_command_continue = string.Empty;
            cmd1.failed_exec_command_continue = string.Empty;
            cmd1.failed_exec_command_continue = string.Empty;
            cmd2.failed_exec_command_continue = string.Empty;

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // the return code of the first failure is saved
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);

            // all continue error messages are blank, nothing should popup to block the test
            options.quiet = false;
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(options));
            Assert.IsTrue(File.Exists(markerFilename1));
            Assert.IsTrue(File.Exists(markerFilename2));
            File.Delete(markerFilename1);
            File.Delete(markerFilename2);
            File.Delete(configFilename);
        }
    }
}
