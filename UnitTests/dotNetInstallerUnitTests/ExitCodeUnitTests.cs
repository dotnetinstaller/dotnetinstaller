// <copyright file="ExitCodeUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class ExitCodeUnitTests : UnitTestsBase
    {
        [Test]
        public void TestNoComponentsSuccess()
        {
            Console.WriteLine("TestNoComponentsSuccess");

            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestMissingConfigFile()
        {
            Console.WriteLine("TestMissingConfigFile");

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(configFilename));
        }

        [Test]
        public void TestBadConfigFile()
        {
            Console.WriteLine("TestBadConfigFile");

            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            File.WriteAllText(configFilename, "bogus xml");
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }
    }
}
