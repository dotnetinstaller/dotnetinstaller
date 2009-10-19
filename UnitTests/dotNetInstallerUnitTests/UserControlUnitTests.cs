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
    public class UserControlUnitTests
    {
        [Test]
        public void TestUserControlCheckbox()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            // a checkbox that changes are return value
            ControlCheckBox checkbox = new ControlCheckBox();
            checkbox.UncheckedValue = "3";
            checkbox.CheckedValue = "4";
            checkbox.Checked = true;
            checkbox.Id = "checkbox1";
            setupConfiguration.Children.Add(checkbox);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [checkbox1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(configFilename));
            checkbox.Checked = false;
            configFile.SaveAs(configFilename);
            Assert.AreEqual(3, dotNetInstallerExeUtils.Run(configFilename));
            checkbox.Checked = true;
            checkbox.CheckedValue = "0";
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlEdit()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            setupConfiguration.Children.Add(edit);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlBrowse()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlBrowse browse = new ControlBrowse();
            browse.Text = "4";
            browse.Id = "browse1";
            setupConfiguration.Children.Add(browse);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [browse1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestNoUserControl()
        {
            // a configuration wthout a user control, value is blank
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [doesntexist]5[doesntexist]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(5, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlCheckboxControlArgs()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            // a checkbox that changes are return value
            ControlCheckBox checkbox = new ControlCheckBox();
            checkbox.UncheckedValue = "3";
            checkbox.CheckedValue = "4";
            checkbox.Checked = true;
            checkbox.Id = "checkbox1";
            setupConfiguration.Children.Add(checkbox);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [checkbox1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.configFile = configFilename;
            // unchecked value
            options.args = "/controlArgs checkbox1:3";
            Assert.AreEqual(3, dotNetInstallerExeUtils.Run(options));
            // checked value
            options.args = "/controlArgs checkbox1:4";
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(options));
            // invalid value
            options.args = "/controlArgs checkbox1:5";
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlEditControlArgs()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            setupConfiguration.Children.Add(edit);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.configFile = configFilename;
            // edit value
            options.args = "/controlArgs edit1:4";
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlBrowseControlArgs()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlBrowse browse = new ControlBrowse();
            browse.Text = "4";
            browse.Id = "browse1";
            setupConfiguration.Children.Add(browse);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [browse1]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.configFile = configFilename;
            options.args = "/controlArgs browse1:4";
            Assert.AreEqual(4, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }
    }
}
