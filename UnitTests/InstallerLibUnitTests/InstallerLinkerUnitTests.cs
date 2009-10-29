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
                    List<Resource> custom = ri.Resources[new ResourceId("CUSTOM")];
                    Assert.IsNotNull(custom);
                    Assert.AreEqual(3, custom.Count);
                    // default banner
                    Assert.AreEqual(custom[0].Name, new ResourceId("RES_BANNER"));
                    // embedded configuration
                    Assert.AreEqual(custom[1].Name, new ResourceId("RES_CONFIGURATION"));
                    Assert.AreEqual(custom[1].Size, new FileInfo(args.config).Length);
                    // unicows
                    Assert.AreEqual(custom[2].Name, new ResourceId("RES_UNICOWS"));
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
                    List<Resource> manifests = ri.Resources[new ResourceId(Kernel32.ResourceTypes.RT_MANIFEST)]; // RT_MANIFEST
                    Assert.IsNotNull(manifests);
                    Assert.AreEqual(1, manifests.Count);
                    ManifestResource manifest = (ManifestResource) manifests[0]; // RT_MANIFEST
                    Console.WriteLine(manifest.Manifest.OuterXml);
                    XmlNamespaceManager manifestNamespaceManager = new XmlNamespaceManager(manifest.Manifest.NameTable);
                    manifestNamespaceManager.AddNamespace("v1", "urn:schemas-microsoft-com:asm.v1");
                    manifestNamespaceManager.AddNamespace("v3", "urn:schemas-microsoft-com:asm.v3");
                    string level = manifest.Manifest.SelectSingleNode("//v3:requestedExecutionLevel",
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
                    List<Resource> manifests = ri.Resources[new ResourceId(Kernel32.ResourceTypes.RT_MANIFEST)]; // RT_MANIFEST
                    Assert.IsNotNull(manifests);
                    Assert.AreEqual(1, manifests.Count);
                    ManifestResource manifest = (ManifestResource) manifests[0]; // RT_MANIFEST
                    Console.WriteLine(manifest.Manifest.OuterXml);
                    XmlNamespaceManager manifestNamespaceManager = new XmlNamespaceManager(manifest.Manifest.NameTable);
                    manifestNamespaceManager.AddNamespace("v1", "urn:schemas-microsoft-com:asm.v1");
                    manifestNamespaceManager.AddNamespace("v3", "urn:schemas-microsoft-com:asm.v3");
                    string level = manifest.Manifest.SelectSingleNode("//v3:requestedExecutionLevel",
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

        [Test]
        public void TestLinkEmbedFilesAndFolders()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                string binPath = Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath));
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                args.embedFolders = new string[] { binPath };
                args.embed = true;
                args.embedResourceSize = 0;
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    List<Resource> custom = ri.Resources[new ResourceId("RES_CAB")];
                    Assert.IsNotNull(custom);
                    Assert.AreEqual(1, custom.Count);
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
        public void TestLinkNoEmbedFilesAndFolders()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                string binPath = Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath));
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                args.embedFolders = new string[] { binPath };
                args.embed = false;
                args.embedResourceSize = 0;
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);                    
                    Assert.IsFalse(ri.Resources.ContainsKey(new ResourceId("RES_CAB")));
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
        public void TestLinkEmbedFilesAndFoldersSegments()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                string binPath = Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath));
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                args.embedFolders = new string[] { binPath };
                args.embed = true;
                args.embedResourceSize = 64 * 1024;
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    List<Resource> custom = ri.Resources[new ResourceId("RES_CAB")];
                    Assert.IsNotNull(custom);
                    Console.WriteLine("Segments: {0}", custom.Count);
                    Assert.IsTrue(custom.Count > 1);
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
        public void TestEmbedSplashScreen()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            try
            {
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                string binPath = Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath));
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                ComponentCmd cmd = new ComponentCmd();
                cmd.command = "cmd.exe /C exit /b 0";
                setupConfiguration.Children.Add(cmd);
                args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
                Console.WriteLine("Writing '{0}'", args.config);
                configFile.SaveAs(args.config);
                args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
                Console.WriteLine("Linking '{0}'", args.output);
                args.template = dotNetInstallerExeUtils.Executable;
                args.splash = Path.Combine(dotNetInstallerExeUtils.Location, @"..\res\banner.bmp");
                InstallerLib.InstallerLinker.CreateInstaller(args);
                // check that the linker generated output
                Assert.IsTrue(File.Exists(args.output));
                Assert.IsTrue(new FileInfo(args.output).Length > 0);
                using (ResourceInfo ri = new ResourceInfo())
                {
                    ri.Load(args.output);
                    Assert.IsTrue(ri.Resources.ContainsKey(new ResourceId("CUSTOM")));
                    List<Resource> custom = ri.Resources[new ResourceId("CUSTOM")];
                    Assert.AreEqual("RES_BANNER", custom[0].Name.Name);
                    Assert.AreEqual("RES_CONFIGURATION", custom[1].Name.ToString());
                    Assert.AreEqual("RES_SPLASH", custom[2].Name.ToString());
                }
                // execute with and without splash
                dotNetInstallerExeUtils.Run(args.output, "/qb");
                dotNetInstallerExeUtils.Run(args.output, "/qb /nosplash");
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
