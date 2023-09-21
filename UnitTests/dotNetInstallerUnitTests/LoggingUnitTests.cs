// <copyright file="LoggingUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class LoggingUnitTests : UnitTestsBase
    {
        [Test]
        public void TestNoLogging()
        {
            Console.WriteLine("TestNoLogging");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.log = false;
            options.logfile = string.Empty;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile));
        }

        [Test]
        public void TestLogConfigSpecified()
        {
            Console.WriteLine("TestLogConfigSpecified");

            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = Path.Combine(Path.GetTempPath(), "TestLogConfigSpecified.log");
            if (File.Exists(configFile.log_file))
            {
                File.Delete(configFile.log_file);
            }

            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.log = false;
            options.logfile = string.Empty;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile));
            Assert.IsTrue(File.Exists(configFile.log_file));
            File.Delete(configFile.log_file);
        }

        [Test]
        public void TestLogCommandLineOverwritesConfigFile()
        {
            Console.WriteLine("TestLogCommandLineOverwritesConfigFile");

            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = Path.Combine(Path.GetTempPath(), "TestLogConfigSpecified.log");
            if (File.Exists(configFile.log_file))
            {
                File.Delete(configFile.log_file);
            }

            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.log = true;
            options.logfile = dotNetInstallerExeUtils.RunOptions.DefaultLogFile;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile));
            Assert.IsFalse(File.Exists(configFile.log_file));
            File.Delete(configFile.log_file);
        }

        [Test]
        public void TestLogAcceptsPathVariables()
        {
            Console.WriteLine("TestLogAcceptsPathVariables");

            string resolved_logfile = Path.Combine(Path.GetTempPath(), "TestLogAcceptsPathVariables.log");
            if (File.Exists(resolved_logfile))
            {
                File.Delete(resolved_logfile);
            }

            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = @"#TEMPPATH\TestLogAcceptsPathVariables.log";
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.log = false;
            options.logfile = string.Empty;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(resolved_logfile), string.Format("Missing {0}", resolved_logfile));
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile));
            File.Delete(resolved_logfile);
        }
    }
}
