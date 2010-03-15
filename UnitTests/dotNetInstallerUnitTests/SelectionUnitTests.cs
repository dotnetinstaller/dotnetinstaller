using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using dotNetUnitTestsRunner;
using System.IO;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class SelectionUnitTests
    {
        [Test]
        public void TestDefaultSelection()
        {
            ConfigFile configFile = new ConfigFile();
            // setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            // dummy component 1
            ComponentCmd component1 = new ComponentCmd();
            setupConfiguration.Children.Add(component1);
            component1.command = "cmd.exe /C exit /b 57";
            component1.selected = false;
            // dummy component 2
            ComponentCmd component2 = new ComponentCmd();
            setupConfiguration.Children.Add(component2);
            component2.command = "cmd.exe /C exit /b 42";
            component2.selected = true;
            // second component is selected and runs, not the first one
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            Assert.AreEqual(42, dotNetInstallerExeUtils.Run(options));
            // first component is selected and runs
            component1.selected = true;
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            Assert.AreEqual(57, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }
    }
}
