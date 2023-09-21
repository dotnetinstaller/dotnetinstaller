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
                    Assert.AreEqual(2, custom.Count);
                    // default banner
                    Assert.AreEqual(custom[0].Name, new ResourceId("RES_BANNER"));
                    // embedded configuration
                    Assert.AreEqual(custom[1].Name, new ResourceId("RES_CONFIGURATION"));
                    Assert.AreEqual(custom[1].Size, new FileInfo(args.config).Length);
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
                    ManifestResource manifest = (ManifestResource)manifests[0]; // RT_MANIFEST
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

                    int expectedManifestFiles = 1;
                    bool usingHtmlInstaller = dotNetInstallerExeUtils.Executable.EndsWith("htmlInstaller.exe");
                    if (usingHtmlInstaller)
                    {
                        // the stub file already has an embedded manifest
                        expectedManifestFiles++;
                    }

                    Assert.AreEqual(expectedManifestFiles, manifests.Count);
                    ManifestResource manifest = (ManifestResource)manifests[0]; // RT_MANIFEST
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

                string relativePathName = "res";
                bool usingHtmlInstaller = dotNetInstallerExeUtils.Executable.EndsWith("htmlInstaller.exe");
                if (usingHtmlInstaller)
                {
                    relativePathName = "Html";
                }

                args.splash = Path.Combine(dotNetInstallerExeUtils.Location, string.Format(@"..\{0}\banner.bmp", relativePathName));
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

        [Test]
        public void TestControlLicenseResources()
        {
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            string licenseFile = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".txt");
            try
            {
                Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                string binPath = Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath));
                ConfigFile configFile = new ConfigFile();
                SetupConfiguration setupConfiguration = new SetupConfiguration();
                configFile.Children.Add(setupConfiguration);
                ControlLicense license = new ControlLicense();
                license.LicenseFile = licenseFile;
                Console.WriteLine("Writing '{0}'", license.LicenseFile);
                File.WriteAllText(license.LicenseFile, "Lorem ipsum");
                setupConfiguration.Children.Add(license);
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
                    Assert.IsTrue(ri.Resources.ContainsKey(new ResourceId("CUSTOM")));
                    List<Resource> custom = ri.Resources[new ResourceId("CUSTOM")];
                    Assert.AreEqual("RES_BANNER", custom[0].Name.Name);
                    Assert.AreEqual("RES_CONFIGURATION", custom[1].Name.ToString());
                    Assert.AreEqual("RES_LICENSE", custom[2].Name.ToString());
                }
            }
            finally
            {
                if (File.Exists(licenseFile))
                    File.Delete(licenseFile);
                if (File.Exists(args.config))
                    File.Delete(args.config);
                if (File.Exists(args.output))
                    File.Delete(args.output);
            }
        }

        [Test]
        public void TestLinkProcessorArchitectureFilter()
        {
            // configurations
            SetupConfiguration nofilterConfiguration = new SetupConfiguration();
            SetupConfiguration x86Configuration = new SetupConfiguration();
            x86Configuration.processor_architecture_filter = "x86";
            SetupConfiguration x64Configuration = new SetupConfiguration();
            x64Configuration.processor_architecture_filter = "x64";
            SetupConfiguration mipsConfiguration = new SetupConfiguration();
            mipsConfiguration.processor_architecture_filter = "mips";
            // components
            ComponentCmd nofilterComponent = new ComponentCmd();
            ComponentCmd x86Component = new ComponentCmd();
            x86Component.processor_architecture_filter = "x86";
            ComponentCmd x64Component = new ComponentCmd();
            x64Component.processor_architecture_filter = "x64";
            ComponentCmd mipsComponent = new ComponentCmd();
            mipsComponent.processor_architecture_filter = "mips";
            // make a tree
            nofilterConfiguration.Children.Add(nofilterComponent);
            nofilterConfiguration.Children.Add(x86Component);
            nofilterConfiguration.Children.Add(x64Component);
            nofilterConfiguration.Children.Add(mipsComponent);
            x86Configuration.Children.Add(nofilterComponent);
            x86Configuration.Children.Add(x86Component);
            x86Configuration.Children.Add(x64Component);
            x86Configuration.Children.Add(mipsComponent);
            x64Configuration.Children.Add(nofilterComponent);
            x64Configuration.Children.Add(x86Component);
            x64Configuration.Children.Add(x64Component);
            x64Configuration.Children.Add(mipsComponent);
            mipsConfiguration.Children.Add(nofilterComponent);
            mipsConfiguration.Children.Add(x86Component);
            mipsConfiguration.Children.Add(x64Component);
            mipsConfiguration.Children.Add(mipsComponent);
            // configfile
            ConfigFile configFile = new ConfigFile();
            configFile.Children.Add(nofilterConfiguration);
            configFile.Children.Add(x86Configuration);
            configFile.Children.Add(x64Configuration);
            configFile.Children.Add(mipsConfiguration);
            // write a configuration
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.processorArchitecture = "x86,alpha";
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            Console.WriteLine("Writing '{0}'", args.config);
            try
            {
                configFile.SaveAs(args.config);
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
                    Assert.AreEqual(custom[1].Name, new ResourceId("RES_CONFIGURATION"));
                    byte[] data = custom[1].WriteAndGetBytes();
                    // skip BOM
                    String config = Encoding.UTF8.GetString(data, 3, data.Length - 3);
                    XmlDocument xmldoc = new XmlDocument();
                    xmldoc.LoadXml(config);
                    ConfigFile filteredConfig = new ConfigFile();
                    filteredConfig.LoadXml(xmldoc);
                    Assert.AreEqual(2, filteredConfig.ConfigurationCount);
                    Assert.AreEqual(4, filteredConfig.ComponentCount);
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
