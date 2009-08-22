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
    public class CabUnitTests
    {
        [Test]
        public void TestCabPathAutoDeleteFalse()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.cab_path = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            setupConfiguration.cab_path_autodelete = false;
            Console.WriteLine("Creating '{0}'", setupConfiguration.cab_path);
            Directory.CreateDirectory(setupConfiguration.cab_path);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsTrue(Directory.Exists(setupConfiguration.cab_path));
            Directory.Delete(setupConfiguration.cab_path);
        }

        [Test]
        public void TestCabPathAutoDeleteTrue()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.cab_path = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            setupConfiguration.cab_path_autodelete = true;
            Console.WriteLine("Creating '{0}'", setupConfiguration.cab_path);
            Directory.CreateDirectory(setupConfiguration.cab_path);
            File.WriteAllText(Path.Combine(setupConfiguration.cab_path, Guid.NewGuid().ToString()), Guid.NewGuid().ToString());
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsFalse(Directory.Exists(setupConfiguration.cab_path));
        }
    }
}
