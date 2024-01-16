// <copyright file="CommandLineParametersUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class CommandLineParametersTests : UnitTestsBase
    {
        [Test]
        public void TestHelp()
        {
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.args = "/qb /?";
            options.log = false;
            options.quiet = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
        }

        [Test]
        public void TestDisplayConfigSetupConfiguration()
        {
            // config file
            ConfigFile configFile = new ConfigFile();
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/qb /DisplayConfig";
            options.log = false;
            options.quiet = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));

            // cleanup
            File.Delete(configFilename);
        }

        [Test]
        public void TestDisplayConfigWebConfiguration()
        {
            // config file with a web configuration (that will not be downloaded)
            ConfigFile configFile = new ConfigFile();
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            WebConfiguration webConfiguration = new WebConfiguration();
            DownloadDialog downloadDialog = new DownloadDialog();
            downloadDialog.Children.Add(new Download());
            webConfiguration.Children.Add(downloadDialog);
            configFile.Children.Add(webConfiguration);
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.args = "/qb /DisplayConfig";
            options.log = false;
            options.quiet = false;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));

            // cleanup
            File.Delete(configFilename);
        }

        [Test]
        public void TestInvalidCommandLineParameter()
        {
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.args = "/qb /qn"; // qn is an invalid parameter
            options.log = false;
            options.quiet = false;
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(options));
        }

        [Test]
        public void TestInvalidCommandLineArgument()
        {
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions();
            options.args = "/qb name=value"; // name=value doesn't follow a parameter
            options.log = false;
            options.quiet = false;
            Assert.AreEqual(-1, dotNetInstallerExeUtils.Run(options));
        }
    }
}
