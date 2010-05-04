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
        public void TestUserControlCheckboxInstallCheck()
        {
            // a configuration with a checkbox control which has an installed check that disables it
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
            // an installed check that is always false
            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExist";
            check.comparison = installcheckregistry_comparison.exists;
            checkbox.Children.Add(check);
            // command that depends on the value of checkbox1
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [checkbox1]5";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller, this checkbox is disabled, so all runs ignore checkbox1 value
            Assert.AreEqual(5, dotNetInstallerExeUtils.Run(configFilename));
            checkbox.Checked = false;
            configFile.SaveAs(configFilename);
            Assert.AreEqual(5, dotNetInstallerExeUtils.Run(configFilename));
            checkbox.Checked = true;
            checkbox.CheckedValue = "0";
            configFile.SaveAs(configFilename);
            Assert.AreEqual(5, dotNetInstallerExeUtils.Run(configFilename));
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
        public void TestUserControlEditInstalledCheckBoth()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            edit.Check = ControlCheckType.both;
            setupConfiguration.Children.Add(edit);
            // an installed check that is always false
            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExist";
            check.comparison = installcheckregistry_comparison.exists;
            edit.Children.Add(check);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]5";
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
        public void TestUserControlEditInstalledCheckHasValueDisabled()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            edit.Check = ControlCheckType.enabled; // control will be disabled, but has a value when disabled
            edit.HasValueDisabled = true;
            setupConfiguration.Children.Add(edit);
            // an installed check that is always false
            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExist";
            check.comparison = installcheckregistry_comparison.exists;
            edit.Children.Add(check);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]5";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(45, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlEditInstalledCheckHasNoValueDisabled()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            edit.Check = ControlCheckType.enabled; // control will be disabled, but has a value when disabled
            edit.HasValueDisabled = false;
            setupConfiguration.Children.Add(edit);
            // an installed check that is always false
            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExist";
            check.comparison = installcheckregistry_comparison.exists;
            edit.Children.Add(check);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]5";
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
        public void TestUserControlEditInstalledCheckDisplay()
        {
            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "4";
            edit.Id = "edit1";
            edit.Check = ControlCheckType.display;
            setupConfiguration.Children.Add(edit);
            // an installed check that is always false
            InstalledCheckRegistry check = new InstalledCheckRegistry();
            check.path = @"SOFTWARE\KeyDoesntExist";
            check.comparison = installcheckregistry_comparison.exists;
            edit.Children.Add(check);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]5";
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
        public void TestUserControlHyperlink()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlHyperlink hyperlink = new ControlHyperlink();
            hyperlink.Text = "url";
            hyperlink.Uri = "http://dotnetinstaller.codeplex.com";
            setupConfiguration.Children.Add(hyperlink);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b 0";
            setupConfiguration.Children.Add(cmd);
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlBrowse()
        {
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
        public void TestUserControlImage()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlImage image = new ControlImage();
            setupConfiguration.Children.Add(image);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b 0";
            setupConfiguration.Children.Add(cmd);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlLicense()
        {
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            // a configuration with a license agreement control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlLicense license = new ControlLicense();
            license.Accepted = true;
            license.ResourceId = "MY_RES_LICENSE";
            license.LicenseFile = configFilename;
            setupConfiguration.Children.Add(license);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [MY_RES_LICENSE]";
            setupConfiguration.Children.Add(cmd);
            // save config file
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // create a setup with the license file
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = configFilename;
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;
            Console.WriteLine("Linking '{0}'", args.output);
            InstallerLinker.CreateInstaller(args);
            Assert.IsTrue(File.Exists(args.output));
            // execute dotNetInstaller
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(args.output, "/q"));
            File.Delete(args.config);
            File.Delete(args.output);
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
