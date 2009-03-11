using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Reflection;
using InstallerLib;
using System.IO;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class SamplesUnitTests
    {
        [Test]
        public void LoadSaveSamplesTest()
        {
            // make sure that every sample configuration loads and saves
            string[] manifestResourceNames = Assembly.GetExecutingAssembly().GetManifestResourceNames();
            foreach (string manifestResourceName in manifestResourceNames)
            {
                if (! manifestResourceName.EndsWith(".Configuration.xml"))
                    continue;
                
                // fetch the configuration from the resource
                Console.WriteLine(manifestResourceName);
                Stream s = Assembly.GetExecutingAssembly().GetManifestResourceStream(manifestResourceName);
                StreamReader r = new StreamReader(s);
                string configXml = r.ReadToEnd();
                ConfigFile configFile = new ConfigFile();
                configFile.LoadXml(configXml);
                // compare trivial properties
                Assert.AreEqual("1.0.0.0", configFile.productversion, configFile.productversion);
                Assert.AreEqual(false, configFile.silent_install);
                // save file
                string tempFilename = Path.GetTempFileName();
                configFile.SaveAs(tempFilename);
                // delete temporary file
                File.Delete(tempFilename);
            }
        }
    }
}
