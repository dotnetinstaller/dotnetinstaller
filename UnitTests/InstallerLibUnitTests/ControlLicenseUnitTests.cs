using System;
using InstallerLib;
using System.IO;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ControlLicenseTests
    {
        [Test]
        public void TestGetResourcesNoFile()
        {
            string supportdir = @"C:\SupportFiles\SupportFile";
            ConfigFile configFile = new ConfigFile();
            ResourceFileCollection resources = configFile.GetResources(supportdir);
            Assert.AreEqual(0, resources.Count);
        }

        [Test]
        public void TestGetFilesSourceAppPath()
        {
            ControlLicense license = new ControlLicense();
            license.LicenseFile = @"#APPPATH\license.txt";
            string supportdir = Environment.CurrentDirectory;
            ResourceFileCollection resources = license.GetResources(supportdir);
            Assert.AreEqual(1, resources.Count);
            Assert.AreEqual(Path.Combine(Environment.CurrentDirectory, "license.txt"), resources[0].path);
            Assert.AreEqual("RES_LICENSE", resources[0].id);
        }
    }
}
