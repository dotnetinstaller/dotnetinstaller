// <copyright file="ComponentArgsUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class ComponentArgsUnitTests : UnitTestsBase
    {
        [Test]
        public void TestComponentArgCmd()
        {
            Console.WriteLine("TestComponentArgCmd");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            component.required_install = true;
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
            Console.WriteLine("TestComponentNameArgCmd");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            component.required_install = true;
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
            Console.WriteLine("TestComponentNameArgQuotes");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            component.required_install = true;
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
            Console.WriteLine("TestAllArgCmd");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.id = "cmd1";
            component1.display_name = "command 1";
            component1.command = "cmd.exe /C exit /b ";
            component1.required_install = true;
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.id = "cmd2";
            component2.display_name = "command 2";
            component2.command = "cmd.exe /C exit /b ";
            component2.required_install = true;
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
            Console.WriteLine("TestComponentIdAndNameArgCmd");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            component.required_install = true;
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
            Console.WriteLine("TestComponentArgCmd2");

            ConfigFile configFile = new ConfigFile();

            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            component.id = "cmd1";
            component.display_name = "command 1";
            component.command = "cmd.exe /C dir";
            component.required_install = true;
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
            Console.WriteLine("TestComponentArgIgnored");

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