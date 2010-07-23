using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using dotNetUnitTestsRunner;
using System.IO;
using System.Diagnostics;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class ComponentArgsUnitTests
    {
        [Test]
        public void TestComponentArgCmd()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs cmd1:\"& exit /b 123\"";
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestComponentNameArgCmd()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs \"command 1\":\"& exit /b 123\"";
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestComponentNameArgQuotes()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs \"command 1\":\"INSTALLLOCATION=\"\"C:\\Program Files\\FooBar\"\" & exit /b 123\"";
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestAllArgCmd()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.id = "cmd1";
            component1.display_name = "command 1";
            component1.command = "cmd.exe /C exit /b ";
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.id = "cmd2";
            component2.display_name = "command 2";
            component2.command = "cmd.exe /C exit /b ";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs *:\"23\"";
            Assert.AreEqual(23, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestComponentIdAndNameArgCmd()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs \"cmd1\":\"& exit /b 123\" /ComponentArgs \"command 1\":\"& exit /b 456\"";
            Assert.AreEqual(123, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestComponentArgCmd2()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs cmd1:\"& exit /b 123\" /ComponentArgs cmd1:\"& exit /b 456\"";
            Assert.AreEqual(456, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestComponentArgIgnored()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C exit /b 0";
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/ComponentArgs cmddoesntexist:\"& exit /b 123\"";
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }
   }
}