// <copyright file="UILevelUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class UILevelUnitTests : UnitTestsBase
    {
        [Test]
        public void TestSilentMode()
        {
            Console.WriteLine("TestSilentMode");

            InstallUILevel[] testUILevels = { InstallUILevel.basic, InstallUILevel.silent };
            foreach (InstallUILevel uilevel in testUILevels)
            {
                // a configuration with no components
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                setupConfiguration.installation_none = "this message should never appear in silent mode and disappear in basic";
                configFile.Children.Add(setupConfiguration);

                // silent install, no dialog messages
                configFile.ui_level = uilevel;

                // save config file
                string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", configFilename);
                configFile.SaveAs(configFilename);

                // execute dotNetInstaller
                dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
                Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
                File.Delete(configFilename);
            }
        }
    }
}
