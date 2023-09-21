// <copyright file="CabUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
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
    public class CabUnitTests : UnitTestsBase
    {
        [Test]
        public void TestCabPathAutoDeleteFalse()
        {
            Console.WriteLine("TestCabPathAutoDeleteFalse");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.cab_path = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            setupConfiguration.cab_path_autodelete = false;
            Console.WriteLine("Creating '{0}'", setupConfiguration.cab_path);
            Directory.CreateDirectory(setupConfiguration.cab_path);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsTrue(Directory.Exists(setupConfiguration.cab_path));
            Directory.Delete(setupConfiguration.cab_path);
        }

        [Test]
        public void TestCabPathAutoDeleteTrue()
        {
            Console.WriteLine("TestCabPathAutoDeleteTrue");

            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.cab_path = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            setupConfiguration.cab_path_autodelete = true;
            Console.WriteLine("Creating '{0}'", setupConfiguration.cab_path);
            Directory.CreateDirectory(setupConfiguration.cab_path);
            File.WriteAllText(Path.Combine(setupConfiguration.cab_path, Guid.NewGuid().ToString()), Guid.NewGuid().ToString());
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
            Assert.IsFalse(Directory.Exists(setupConfiguration.cab_path));
        }

        [Test]
        public void TestExtractCab()
        {
            Console.WriteLine("TestExtractCab");

            // create a self-extracting bootstrapper
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            configFile.SaveAs(args.config);
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.embedFiles = new string[] { Path.GetFileName(args.config) };
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(args.output, "/ExtractCab"));

            // this should have created a directory called SupportFiles in the current directory
            string supportFilesPath = Path.Combine(Path.GetDirectoryName(args.output), "SupportFiles");
            Console.WriteLine("Checking {0}", supportFilesPath);
            Assert.IsTrue(Directory.Exists(supportFilesPath), string.Format("Missing {0}", supportFilesPath));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(supportFilesPath, true);
        }

        [Test]
        public void TestExtractCabPerComponent()
        {
            Console.WriteLine("TestExtractCabPerComponent");

            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;

            // create a self-extracting bootstrapper
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            setupConfiguration.Children.Add(component);
            EmbedFile embedfile = new EmbedFile();
            embedfile.sourcefilepath = args.config;
            embedfile.targetfilepath = Path.GetFileName(args.config);
            component.Children.Add(embedfile);
            configFile.SaveAs(args.config);
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(args.output, "/ExtractCab"));

            // this should have created a directory called SupportFiles in the current directory
            string supportFilesPath = Path.Combine(Path.GetDirectoryName(args.output), "SupportFiles");
            Console.WriteLine("Checking {0}", supportFilesPath);
            Assert.IsTrue(Directory.Exists(supportFilesPath), string.Format("Missing {0}", supportFilesPath));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(supportFilesPath, true);
        }

        [Test]
        public void TestExtractAndRunCabPerComponent()
        {
            Console.WriteLine("TestExtractAndRunCabPerComponent");

            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;

            // create a self-extracting bootstrapper
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            setupConfiguration.cab_path = Path.Combine(Path.GetTempPath(), "testExtractAndRunCabPerComponent");
            setupConfiguration.cab_path_autodelete = false;
            configFile.Children.Add(setupConfiguration);
            ComponentCmd component = new ComponentCmd();
            component.command = "cmd.exe /C copy \"#CABPATH\\component\\before.xml\" \"#CABPATH\\component\\after.xml\"";
            component.required_install = true;
            setupConfiguration.Children.Add(component);
            EmbedFile embedfile = new EmbedFile();
            embedfile.sourcefilepath = args.config;
            embedfile.targetfilepath = @"component\before.xml";
            component.Children.Add(embedfile);
            configFile.SaveAs(args.config);
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            string logfile = Path.Combine(Path.GetTempPath(), "testExtractAndRunCabPerComponent.log");
            Console.WriteLine("Log: {0}", logfile);
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(args.output, string.Format("/qb /log /logfile \"{0}\"", logfile)));
            string extractedComponentPath = Path.Combine(setupConfiguration.cab_path, "component");
            Console.WriteLine("Checking {0}", extractedComponentPath);
            Assert.IsTrue(Directory.Exists(extractedComponentPath), string.Format("Missing {0}", extractedComponentPath));
            Assert.IsTrue(File.Exists(Path.Combine(Path.GetTempPath(), @"testExtractAndRunCabPerComponent\component\before.xml")));
            Assert.IsTrue(File.Exists(Path.Combine(Path.GetTempPath(), @"testExtractAndRunCabPerComponent\component\after.xml")));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(setupConfiguration.cab_path, true);
            File.Delete(logfile);
        }

        [Test]
        public void TestDisplayCab()
        {
            Console.WriteLine("TestDisplayCab");

            // create a self-extracting bootstrapper
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            configFile.SaveAs(args.config);
            args.embed = true;
            args.apppath = Path.GetTempPath();

            // args.embedFiles = new string[] { Path.GetFileName(args.config) };
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(args.output, "/DisplayCab /qb"));
            File.Delete(args.config);
            File.Delete(args.output);
        }

        [Test]
        public void TestExtractCabTwoComponentsSameName()
        {
            Console.WriteLine("TestExtractCabTwoComponentsSameName");

            InstallerLinkerArguments args = new InstallerLinkerArguments();
            args.config = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", args.config);
            args.embed = true;
            args.apppath = Path.GetTempPath();
            args.output = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".exe");
            args.template = dotNetInstallerExeUtils.Executable;

            // create a self-extracting bootstrapper
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            for (int i = 0; i < 2; i++)
            {
                ComponentCmd component = new ComponentCmd();
                component.id = "component";
                setupConfiguration.Children.Add(component);
                EmbedFile embedfile = new EmbedFile();
                embedfile.sourcefilepath = args.config;
                embedfile.targetfilepath = string.Format("component{0}\\file.xml", i);
                component.Children.Add(embedfile);
            }

            configFile.SaveAs(args.config);
            Console.WriteLine("Linking '{0}'", args.output);
            Assert.AreEqual(0, InstallerLinkerExeUtils.CreateInstaller(args));
            Assert.IsTrue(File.Exists(args.output));

            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(args.output, "/ExtractCab"));

            // this should have created a directory called SupportFiles in the current directory
            string supportFilesPath = Path.Combine(Path.GetDirectoryName(args.output), "SupportFiles");
            Console.WriteLine("Checking {0}", supportFilesPath);
            Assert.IsTrue(Directory.Exists(supportFilesPath), string.Format("Missing {0}", supportFilesPath));
            Assert.IsTrue(Directory.Exists(supportFilesPath + @"\component0"));
            Assert.IsTrue(File.Exists(supportFilesPath + @"\component0\file.xml"));
            Assert.IsTrue(Directory.Exists(supportFilesPath + @"\component1"));
            Assert.IsTrue(File.Exists(supportFilesPath + @"\component1\file.xml"));
            File.Delete(args.config);
            File.Delete(args.output);
            Directory.Delete(supportFilesPath, true);
        }
    }
}
