using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using System.IO;
using dotNetUnitTestsRunner;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class LoggingUnitTests
    {
        [Test]
        public void TestNoLogging()
        {
            if (File.Exists(dotNetInstallerExeUtils.DefaultLogFile))
                File.Delete(dotNetInstallerExeUtils.DefaultLogFile);
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename, false, string.Empty));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.DefaultLogFile));
        }

        [Test]
        public void TestLogConfigSpecified()
        {
            if (File.Exists(dotNetInstallerExeUtils.DefaultLogFile))
                File.Delete(dotNetInstallerExeUtils.DefaultLogFile);
            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = Path.Combine(Path.GetTempPath(), "TestLogConfigSpecified.log");
            if (File.Exists(configFile.log_file)) 
                File.Delete(configFile.log_file);
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename, false, string.Empty));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.DefaultLogFile));
            Assert.IsTrue(File.Exists(configFile.log_file));
        }

        [Test]
        public void TestLogCommandLineOverwritesConfigFile()
        {
            if (File.Exists(dotNetInstallerExeUtils.DefaultLogFile))
                File.Delete(dotNetInstallerExeUtils.DefaultLogFile);
            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = Path.Combine(Path.GetTempPath(), "TestLogConfigSpecified.log");
            if (File.Exists(configFile.log_file))
                File.Delete(configFile.log_file);
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename, true, dotNetInstallerExeUtils.DefaultLogFile));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(dotNetInstallerExeUtils.DefaultLogFile));
            Assert.IsFalse(File.Exists(configFile.log_file));
        }

        [Test]
        public void TestLogAcceptsPathVariables()
        {
            string resolved_logfile = Path.Combine(Path.GetTempPath(), "TestLogAcceptsPathVariables.log");
            if (File.Exists(dotNetInstallerExeUtils.DefaultLogFile))
                File.Delete(dotNetInstallerExeUtils.DefaultLogFile);
            if (File.Exists(resolved_logfile)) 
                File.Delete(resolved_logfile);
            ConfigFile configFile = new ConfigFile();
            configFile.log_enabled = true;
            configFile.log_file = @"#TEMPPATH\TestLogAcceptsPathVariables.log"; 
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename, false, string.Empty));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(resolved_logfile), string.Format("Missing {0}", resolved_logfile));
            Assert.IsFalse(File.Exists(dotNetInstallerExeUtils.DefaultLogFile));
        }
    }
}
