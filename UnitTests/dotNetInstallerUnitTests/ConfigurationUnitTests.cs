using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using System.IO;
using dotNetUnitTestsRunner;
using System.Threading;
using System.Xml;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class ConfigurationUnitTests
    {
        [Test]
        public void TestInvalidVersionContinues()
        {
            // a configuration with a mismatched version
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            XmlDocument configXml = new XmlDocument();
            configXml.Load(configFilename);
            configXml.SelectSingleNode("/configurations/schema").Attributes["version"].Value = "bogus";
            configXml.Save(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }
    }
}
