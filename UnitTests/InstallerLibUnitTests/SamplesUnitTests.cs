using System;
using NUnit.Framework;
using System.Reflection;
using InstallerLib;
using System.IO;
using System.Xml;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class SamplesUnitTests
    {
        [Test]
        public void TestLoadSaveSamples()
        {
            // \todo: don't use an embedded stream, this is a chicken/egg problem with rewriting sample xmls when configuration changes
            // make sure that every sample configuration loads and saves
            string[] manifestResourceNames = Assembly.GetExecutingAssembly().GetManifestResourceNames();
            foreach (string manifestResourceName in manifestResourceNames)
            {
                if (!manifestResourceName.EndsWith(".Configuration.xml"))
                    continue;

                // fetch the configuration from the resource
                Console.WriteLine(manifestResourceName);
                Stream s = Assembly.GetExecutingAssembly().GetManifestResourceStream(manifestResourceName);
                StreamReader r = new StreamReader(s);
                XmlDocument configXml = new XmlDocument();
                configXml.LoadXml(r.ReadToEnd());
                // load as a configuration
                ConfigFile configFile = new ConfigFile();
                configFile.LoadXml(configXml);
                // compare trivial properties
                Assert.AreEqual("1.0.0.0", configFile.productversion, configFile.productversion);
                Assert.AreEqual(InstallUILevel.full, configFile.ui_level);
                // compare contents
                Assert.AreEqual(configFile.GetXml(null).OuterXml, configXml.OuterXml);
            }
        }
    }
}
