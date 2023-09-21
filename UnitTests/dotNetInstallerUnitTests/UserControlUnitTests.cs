// <copyright file="UserControlUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class UserControlUnitTests : UnitTestsBase
    {
        [Test]
        public void TestUserControlCheckbox()
        {
            Console.WriteLine("TestUserControlCheckbox");

            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // a checkbox that changes the return value
            ControlCheckBox checkbox = new ControlCheckBox();
            checkbox.UncheckedValue = "3";
            checkbox.CheckedValue = "4";
            checkbox.Checked = true;
            checkbox.Id = "checkbox1";
            setupConfiguration.Children.Add(checkbox);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [checkbox1]";
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlCheckboxInstallCheck");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEdit");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEditInstalledCheckBoth");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEditInstalledCheckHasValueDisabled");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEditInstalledCheckHasNoValueDisabled");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEditInstalledCheckDisplay");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlHyperlink");

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
            Console.WriteLine("TestUserControlBrowse");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlBrowse browse = new ControlBrowse();
            browse.Text = "4";
            browse.Id = "browse1";
            setupConfiguration.Children.Add(browse);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [browse1]";
            cmd.required_install = true;
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
        public void TestUserControlBrowseBackslashStripped()
        {
            Console.WriteLine("TestUserControlBrowseBackslashStripped");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlBrowse browse = new ControlBrowse();
            browse.Text = @"42\";
            browse.Id = "browse1";
            setupConfiguration.Children.Add(browse);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C if \"[browse1]\"==\"42\" ( exit /b 0 ) else ( exit /b 1 )";
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
        public void TestUserControlBrowseDrive()
        {
            Console.WriteLine("TestUserControlBrowseDrive");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlBrowse browse = new ControlBrowse();
            browse.Text = @"C:\";
            browse.Id = "browse1";
            setupConfiguration.Children.Add(browse);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C if \"[browse1]\"==\"C:\\\" ( exit /b 0 ) else ( exit /b 1 )";
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
        public void TestUserControlImage()
        {
            Console.WriteLine("TestUserControlImage");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ControlImage image = new ControlImage();
            image.ResourceId = "RES_BANNER_DOESNTEXIST";
            setupConfiguration.Children.Add(image);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b 0";
            setupConfiguration.Children.Add(cmd);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(configFilename));
            image.ResourceId = "RES_BANNER";
            configFile.SaveAs(configFilename);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUserControlLicense()
        {
            Console.WriteLine("TestUserControlLicense");

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
            cmd.required_install = true;
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
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            Assert.AreEqual(1, dotNetInstallerExeUtils.Run(args.output, "/q"));
            File.Delete(args.config);
            File.Delete(args.output);
        }

        [Test]
        public void TestNoUserControl()
        {
            Console.WriteLine("TestNoUserControl");

            // a configuration wthout a user control, value is blank
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [doesntexist]5[doesntexist]";
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlCheckboxControlArgs");

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
            cmd.required_install = true;
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
            Console.WriteLine("TestUserControlEditControlArgs");

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
            cmd.required_install = true;
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
        public void TestUserControlEditHtmlValues()
        {
            Console.WriteLine("TestUserControlEditHtmlValues");

            bool usingHtmlInstaller = dotNetInstallerExeUtils.Executable.EndsWith("htmlInstaller.exe");
            if (!usingHtmlInstaller)
            {
                return;
            }

            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.failed_exec_command_continue = string.Empty;
            setupConfiguration.auto_close_on_error = true;
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "3";
            edit.Id = "edit1";
            setupConfiguration.Children.Add(edit);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]1";
            cmd.required_install = true;
            setupConfiguration.Children.Add(cmd);

            // save config file
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            configFile.SaveAs(args.config);

            // create HTML directory
            string htmlPath = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            Directory.CreateDirectory(htmlPath);
            string htmlIndexFilename = Path.Combine(htmlPath, "index.html");
            File.WriteAllText(
                htmlIndexFilename,
                              @"<html><head><title></title></head><body>
                                <input type=""text"" id=""edit1"" value=""4"" />
                                <input id=""button_install"" type=""button"" value=""Install"" />
                                </body></html>");

            // link the install executable
            args.htmlFiles = new string[] { htmlPath };
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.embedFiles = new string[] { Path.GetFileName(args.config) };
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions runOptions = new dotNetInstallerExeUtils.RunOptions();
            runOptions.autostart = true;
            runOptions.quiet = false;
            Assert.AreEqual(41, dotNetInstallerExeUtils.Run(args.output, runOptions.CommandLineArgs));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(args.htmlFiles[0], true);
        }

        [Test]
        public void TestUserControlRadioButtonHtmlValues()
        {
            Console.WriteLine("TestUserControlRadioButtonHtmlValues");

            bool usingHtmlInstaller = dotNetInstallerExeUtils.Executable.EndsWith("htmlInstaller.exe");
            if (!usingHtmlInstaller)
            {
                return;
            }

            // a configuration with a checkbox control
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.auto_start = true;
            setupConfiguration.failed_exec_command_continue = string.Empty;
            setupConfiguration.auto_close_on_error = true;
            configFile.Children.Add(setupConfiguration);
            ControlEdit edit = new ControlEdit();
            edit.Text = "3";
            edit.Id = "edit1";
            setupConfiguration.Children.Add(edit);
            ComponentCmd cmd = new ComponentCmd();
            cmd.command = "cmd.exe /C exit /b [edit1]1";
            cmd.required_install = true;
            setupConfiguration.Children.Add(cmd);

            // save config file
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            configFile.SaveAs(args.config);

            // create HTML directory
            string htmlPath = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            Directory.CreateDirectory(htmlPath);
            string htmlIndexFilename = Path.Combine(htmlPath, "index.html");
            File.WriteAllText(
                htmlIndexFilename,
                              @"<html><head><title></title></head><body>
                                <input type=""radio"" id=""edit1"" name=""edit1"" value=""4"" checked=""checked"" />
                                <input type=""radio"" id=""edit1"" name=""edit1"" value=""2"" />
                                <input id=""button_install"" type=""button"" value=""Install"" />
                                </body></html>");

            // link the install executable
            args.htmlFiles = new string[] { htmlPath };
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.embedFiles = new string[] { Path.GetFileName(args.config) };
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions runOptions = new dotNetInstallerExeUtils.RunOptions();
            runOptions.autostart = true;
            runOptions.quiet = false;
            Assert.AreEqual(41, dotNetInstallerExeUtils.Run(args.output, runOptions.CommandLineArgs));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(args.htmlFiles[0], true);
        }

        [Test]
        public void TestUserControlBrowseControlArgs()
        {
            Console.WriteLine("TestUserControlBrowseControlArgs");

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
            cmd.required_install = true;
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
