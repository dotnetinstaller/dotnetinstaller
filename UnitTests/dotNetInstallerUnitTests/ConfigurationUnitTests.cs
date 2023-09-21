// <copyright file="ConfigurationUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>

namespace dotNetInstallerUnitTests
{
    using System;
    using System.IO;
    using System.Xml;
    using dotNetUnitTestsRunner;
    using InstallerLib;
    using NUnit.Framework;

    [TestFixture]
    public class ConfigurationUnitTests : UnitTestsBase
    {
        [Test]
        public void TestInvalidVersionContinues()
        {
            Console.WriteLine("TestInvalidVersionContinues");

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
