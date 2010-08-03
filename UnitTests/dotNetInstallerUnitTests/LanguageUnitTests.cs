using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using System.IO;
using dotNetUnitTestsRunner;
using System.Threading;
using System.Xml;
using System.Globalization;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class LanguageUnitTests
    {
        [Test]
        public void TestComponentLcid()
        {
            // a configuration with one component
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            // current lcid
            string currentLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdCurrentLcid = new ComponentCmd();
            cmdCurrentLcid.os_filter_lcid = CultureInfo.CurrentCulture.LCID.ToString();
            Console.WriteLine("Current lcid: {0}", cmdCurrentLcid.os_filter_lcid);
            cmdCurrentLcid.command = string.Format("cmd.exe /C dir > \"{0}\"", currentLcidFilename);
            setupConfiguration.Children.Add(cmdCurrentLcid);
            // empty lcid
            string emptyLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdEmptyLcid = new ComponentCmd();
            cmdEmptyLcid.command = string.Format("cmd.exe /C dir > \"{0}\"", emptyLcidFilename);
            setupConfiguration.Children.Add(cmdEmptyLcid);
            // another lcid
            string anotherLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdAnotherLcid = new ComponentCmd();
            cmdAnotherLcid.os_filter_lcid = (CultureInfo.CurrentCulture.LCID + 1).ToString();
            Console.WriteLine("Another lcid: {0}", cmdAnotherLcid.os_filter_lcid);
            cmdAnotherLcid.command = string.Format("cmd.exe /C dir > \"{0}\"", anotherLcidFilename);
            setupConfiguration.Children.Add(cmdAnotherLcid);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            Assert.IsTrue(File.Exists(currentLcidFilename));
            Assert.IsTrue(File.Exists(emptyLcidFilename));
            Assert.IsFalse(File.Exists(anotherLcidFilename));
            File.Delete(currentLcidFilename);
            File.Delete(emptyLcidFilename);
        }

        [Test]
        public void TestConfigurationLcid()
        {
            // a configuration with one component
            ConfigFile configFile = new ConfigFile();
            // current lcid setup configuration
            SetupConfiguration currentLcidConfiguration = new SetupConfiguration();
            currentLcidConfiguration.lcid_filter = CultureInfo.CurrentCulture.LCID.ToString(); 
            configFile.Children.Add(currentLcidConfiguration);
            string currentLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdCurrentLcid = new ComponentCmd();
            Console.WriteLine("Current lcid: {0}", currentLcidConfiguration.lcid_filter);
            cmdCurrentLcid.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 0", currentLcidFilename);
            currentLcidConfiguration.Children.Add(cmdCurrentLcid);
            // empty lcid setup configuration
            SetupConfiguration emptyLcidConfiguration = new SetupConfiguration();
            configFile.Children.Add(emptyLcidConfiguration);
            string emptyLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdEmptyLcid = new ComponentCmd();
            cmdEmptyLcid.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 0", emptyLcidFilename);
            emptyLcidConfiguration.Children.Add(cmdEmptyLcid);
            // another lcid setup configuration
            SetupConfiguration anotherLcidConfiguration = new SetupConfiguration();
            anotherLcidConfiguration.lcid_filter = (CultureInfo.CurrentCulture.LCID + 1).ToString();
            configFile.Children.Add(anotherLcidConfiguration);
            string anotherLcidFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            ComponentCmd cmdAnotherLcid = new ComponentCmd();
            Console.WriteLine("Another lcid: {0}", anotherLcidConfiguration.lcid_filter);
            cmdAnotherLcid.command = string.Format("cmd.exe /C dir > \"{0}\" & exit /b 0", anotherLcidFilename);
            anotherLcidConfiguration.Children.Add(cmdAnotherLcid);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            Assert.IsTrue(File.Exists(currentLcidFilename));
            Assert.IsTrue(File.Exists(emptyLcidFilename));
            Assert.IsFalse(File.Exists(anotherLcidFilename));
            File.Delete(currentLcidFilename);
            File.Delete(emptyLcidFilename);
        }
    }
}
