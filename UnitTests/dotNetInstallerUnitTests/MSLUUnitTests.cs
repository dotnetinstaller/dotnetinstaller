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
    public class MSLUUnitTests
    {
        [Test]
        public void TestLoadMSLU()
        {
            Console.WriteLine("TestLoadUnicows");

            if (File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile))
                File.Delete(dotNetInstallerExeUtils.RunOptions.DefaultLogFile);
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.loadMSLU = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
            string[] logLines = File.ReadAllLines(dotNetInstallerExeUtils.RunOptions.DefaultLogFile);
            Console.WriteLine(logLines[0]);
            Assert.IsTrue(logLines[0].Contains("Loaded MSLU:"));
            string[] msluLine = logLines[0].Split(":".ToCharArray());
            string msluAddress = msluLine[msluLine.Length - 1].Trim();
            Console.WriteLine("MSLU loaded at: " + msluAddress);
            Assert.IsTrue(Int32.Parse(msluAddress, System.Globalization.NumberStyles.HexNumber) > 0);
            File.Delete(dotNetInstallerExeUtils.RunOptions.DefaultLogFile);
        }
    }
}
