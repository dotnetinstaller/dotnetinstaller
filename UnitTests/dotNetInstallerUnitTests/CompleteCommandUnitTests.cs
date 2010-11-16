using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using System.IO;
using dotNetUnitTestsRunner;
using System.Threading;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class CompleteCommandTests
    {
        [Test]
        public void TestNoComponents()
        {
            Console.WriteLine("TestNoComponents");

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
            File.Delete(markerFilename + ".silent");
        }

        [Test]
        public void TestFailingComponent()
        {
            Console.WriteLine("TestFailingComponent");

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
            component.required_install = true;
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsFalse(File.Exists(markerFilename));
        }
        
        [Test]
        public void TestWaitForCompleteCommand()
        {
            Console.WriteLine("TestWaitForCompleteCommand");

            ConfigFile configFile = new ConfigFile();
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.complete_command = TestTimerExeUtils.Executable;
            setupConfiguration.wait_for_complete_command = true;
            configFile.Children.Add(setupConfiguration);
            // save config file
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            DateTime ts = DateTime.UtcNow;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            // test timer lives for 2 seconds before it closes
            Assert.IsTrue(DateTime.UtcNow.Subtract(ts).TotalSeconds >= 2);
            File.Delete(configFilename);
        }

        [Test]
        public void TestDontWaitForCompleteCommand()
        {
            Console.WriteLine("TestDontWaitForCompleteCommand");

            ConfigFile configFile = new ConfigFile();
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.complete_command = TestTimerExeUtils.Executable;
            setupConfiguration.wait_for_complete_command = false;
            configFile.Children.Add(setupConfiguration);
            // save config file
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            DateTime ts = DateTime.UtcNow;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            // test timer lives for 2 seconds before it closes
            Assert.IsTrue(DateTime.UtcNow.Subtract(ts).TotalSeconds < 2);
            File.Delete(configFilename);
        }
    }
}
