using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using InstallerLib;
using NUnit.Framework;
using dotNetUnitTestsRunner;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class UILevelUnitTests
    {
        [Test]
        public void TestSilentMode()
        {
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
                Assert.AreEqual(0, dotNetInstallerExeUtils.Run(dotNetInstallerExeUtils.Executable,
                    string.Format("/ConfigFile \"{0}\"", configFilename)));
                File.Delete(configFilename);
            }
        }
    }
}
