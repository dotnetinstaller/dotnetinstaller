using System;
using System.Collections.Generic;
using System.Text;
using InstallerLib;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.IO;
using System.Xml;
using Vestris.ResourceLib;
using System.Reflection;
using System.Web;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class InstallerLinkerTests
    {
        [Test]
        public void TestLinkBasics()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    List<Resource> custom = ri.Resources["CUSTOM"];
                    Assert.IsNotNull(custom);
                    Assert.AreEqual(3, custom.Count);
                    // default banner
                    Assert.AreEqual(custom[0].Name, "RES_BANNER");
                    // embedded configuration
                    Assert.AreEqual(custom[1].Name, "RES_CONFIGURATION");
                    Assert.AreEqual(custom[1].Size, new FileInfo(args.config).Length);
                    // unicows
                    Assert.AreEqual(custom[2].Name, "RES_UNICOWS");
                }
            }
            finally
            {
                if (File.Exists(args.config))
                    File.Delete(args.config);
                if (File.Exists(args.output))
                    File.Delete(args.output);
            }
        }

        [Test]
        public void TestLinkDefaultManifest()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    List<Resource> manifests = ri.Resources["24"]; // RT_MANIFEST
                    Assert.IsNotNull(manifests);
                    Assert.AreEqual(1, manifests.Count);
                    UnknownResource manifest = (UnknownResource)manifests[0]; // RT_MANIFEST
                    XmlDocument manifestXml = new XmlDocument();
                    manifestXml.LoadXml(Encoding.UTF8.GetString(manifest.Data));
                    Console.WriteLine(manifestXml.OuterXml);
                    XmlNamespaceManager manifestNamespaceManager = new XmlNamespaceManager(manifestXml.NameTable);
                    manifestNamespaceManager.AddNamespace("v1", "urn:schemas-microsoft-com:asm.v1");
                    manifestNamespaceManager.AddNamespace("v3", "urn:schemas-microsoft-com:asm.v3");
                    string level = manifestXml.SelectSingleNode("//v3:requestedExecutionLevel",
                        manifestNamespaceManager).Attributes["level"].Value;
                    Assert.AreEqual(level, "requireAdministrator");
                }
            }
            finally
            {
                if (File.Exists(args.config))
                    File.Delete(args.config);
                if (File.Exists(args.output))
                    File.Delete(args.output);
            }
        }

        [Test]
        public void TestLinkEmbedManifest()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                // manifest
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                args.manifest = Path.Combine(Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath)), "Manifests\\asInvoker.manifest");
                // link
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    List<Resource> manifests = ri.Resources["24"]; // RT_MANIFEST
                    Assert.IsNotNull(manifests);
                    Assert.AreEqual(1, manifests.Count);
                    UnknownResource manifest = (UnknownResource)manifests[0]; // RT_MANIFEST
                    XmlDocument manifestXml = new XmlDocument();
                    manifestXml.LoadXml(Encoding.UTF8.GetString(manifest.Data));
                    Console.WriteLine(manifestXml.OuterXml);
                    XmlNamespaceManager manifestNamespaceManager = new XmlNamespaceManager(manifestXml.NameTable);
                    manifestNamespaceManager.AddNamespace("v1", "urn:schemas-microsoft-com:asm.v1");
                    manifestNamespaceManager.AddNamespace("v3", "urn:schemas-microsoft-com:asm.v3");
                    string level = manifestXml.SelectSingleNode("//v3:requestedExecutionLevel",
                        manifestNamespaceManager).Attributes["level"].Value;
                    Assert.AreEqual(level, "asInvoker");
                }
            }
            finally
            {
                if (File.Exists(args.config))
                    File.Delete(args.config);
                if (File.Exists(args.output))
                    File.Delete(args.output);
            }
        }
    }
}
