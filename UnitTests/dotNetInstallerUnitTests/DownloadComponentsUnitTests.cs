// <copyright file="DownloadComponentsUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>

namespace dotNetInstallerUnitTests
{
    using System;
    using System.IO;
    using System.Reflection;
    using dotNetUnitTestsRunner;
    using InstallerLib;
    using NUnit.Framework;

    [TestFixture]
    public class DownloadComponentsUnitTests : UnitTestsBase
    {
        [Test]
        public void TestDownloadConfiguration()
        {
            Console.WriteLine("TestDownloadConfiguration");

            // a configuration with a single component that contains two download components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.command = "cmd.exe /C exit /b 0";
            component1.required_install = true;
            DownloadDialog component1downloaddialog = new DownloadDialog(
                string.Format("{0} Download Dialog", component1.id));
            component1.Children.Add(component1downloaddialog);
            Download component1download1 = new Download();
            component1download1.componentname = "download 1";
            component1download1.sourceurl = Assembly.GetExecutingAssembly().Location;
            component1download1.destinationpath = Path.GetTempPath();
            component1download1.destinationfilename = Guid.NewGuid().ToString();
            component1downloaddialog.Children.Add(component1download1);
            Download component1download2 = new Download();
            component1download2.componentname = "download 2";
            component1download2.sourceurl = Assembly.GetExecutingAssembly().Location;
            component1download2.destinationpath = Path.GetTempPath();
            component1download2.destinationfilename = Guid.NewGuid().ToString();
            component1downloaddialog.Children.Add(component1download2);

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(Path.Combine(component1download1.destinationpath, component1download1.destinationfilename)));
            File.Delete(Path.Combine(component1download1.destinationpath, component1download1.destinationfilename));
            Assert.IsTrue(File.Exists(Path.Combine(component1download2.destinationpath, component1download2.destinationfilename)));
            File.Delete(Path.Combine(component1download2.destinationpath, component1download2.destinationfilename));
        }

        [Test]
        public void TestNoDownloadWhenSourceFileExsts()
        {
            Console.WriteLine("TestNoDownloadWhenSourceFileExsts");

            // a configuration where the source file exists, no download dialog should show
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.command = "cmd.exe /C exit /b 0";
            cmd.required_install = true;
            DownloadDialog cmddownloaddialog = new DownloadDialog(
                string.Format("{0} Download Dialog", cmd.id));
            cmd.Children.Add(cmddownloaddialog);
            cmddownloaddialog.autostartdownload = false;
            Download download = new Download();
            download.componentname = "download 1";
            download.sourceurl = string.Format("http://{0}/dummy.exe", Guid.NewGuid());
            download.sourcepath = Assembly.GetExecutingAssembly().Location;
            download.destinationpath = Path.GetTempPath();
            download.destinationfilename = Guid.NewGuid().ToString();
            download.alwaysdownload = false;
            cmddownloaddialog.Children.Add(download);

            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.configFile = configFilename;
            options.args = "/qb";
            options.quiet = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            Assert.IsTrue(File.Exists(Path.Combine(download.destinationpath, download.destinationfilename)));
            File.Delete(Path.Combine(download.destinationpath, download.destinationfilename));
        }
    }
}
