using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using System.IO;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class CompleteCommandTests
    {
        [Test]
        public void TestNoComponents()
        {
            // a configuration with no components, complete command is executed
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            setupConfiguration.complete_command = string.Format("cmd.exe /C dir > \"{0}.ui\"", markerFilename);
            setupConfiguration.complete_command_basic = string.Format("cmd.exe /C dir > \"{0}.basic\"", markerFilename);
            setupConfiguration.complete_command_silent = string.Format("cmd.exe /C dir > \"{0}.silent\"", markerFilename);
            configFile.Children.Add(setupConfiguration);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(markerFilename + ".silent"));
            File.Delete(markerFilename);
        }

        [Test]
        public void TestFailingComponent()
        {
            // a configuration with a component that fails, complete command is not executed
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string markerFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".tmp");
            setupConfiguration.complete_command = string.Format("cmd.exe /C dir > \"{0}\"", markerFilename);
            setupConfiguration.complete_command_basic = setupConfiguration.complete_command;
            setupConfiguration.complete_command_silent = setupConfiguration.complete_command;
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.command = "cmd.exe /C exit /b 123";
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(markerFilename));
        }
    }
}
