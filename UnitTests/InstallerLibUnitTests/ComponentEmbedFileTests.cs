using System;
using System.Collections.Generic;
using System.Text;
using InstallerLib;
using System.IO;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ComponentEmbedFileTests
    {
        [Test]
        public void TestGetFilesNoTargetPath()
        {
            EmbedFile embedFile = new EmbedFile();
            embedFile.sourcefilepath = Path.Combine(Environment.CurrentDirectory, @"InstallerLibUnitTests.dll");
            string supportdir = @"C:\SupportFiles\SupportFile";
            EmbedFileCollection embedFileCollection = embedFile.GetFiles(supportdir);
            Assert.AreEqual(1, embedFileCollection.Count);
            Assert.AreEqual(embedFile.sourcefilepath, embedFileCollection[0].fullpath);
            Assert.AreEqual(@"InstallerLibUnitTests.dll", embedFileCollection[0].relativepath);
        }

        [Test]
        public void TestGetFilesTargetPath()
        {
            EmbedFile embedFile = new EmbedFile();
            embedFile.sourcefilepath = Path.Combine(Environment.CurrentDirectory, @"InstallerLibUnitTests.dll");
            embedFile.targetfilepath = @"parent\child\InstallerLibUnitTests.dll";
            string supportdir = @"C:\SupportFiles\SupportFile";
            EmbedFileCollection embedFileCollection = embedFile.GetFiles(supportdir);
            Assert.AreEqual(1, embedFileCollection.Count);
            Assert.AreEqual(embedFile.sourcefilepath, embedFileCollection[0].fullpath);
            Assert.AreEqual(@"parent\child\InstallerLibUnitTests.dll", embedFileCollection[0].relativepath);
        }

        [Test]
        public void TestGetFilesAppPath()
        {
            EmbedFile embedFile = new EmbedFile();
            embedFile.sourcefilepath = Path.Combine(Environment.CurrentDirectory, @"InstallerLibUnitTests.dll");
            embedFile.targetfilepath = @"#APPPATH\InstallerLibUnitTests.dll";
            string supportdir = @"C:\SupportFiles\SupportFile";
            EmbedFileCollection embedFileCollection = embedFile.GetFiles(supportdir);
            Assert.AreEqual(1, embedFileCollection.Count);
            Assert.AreEqual(embedFile.sourcefilepath, embedFileCollection[0].fullpath);
            Assert.AreEqual("InstallerLibUnitTests.dll", embedFileCollection[0].relativepath);
        }

        [Test]
        public void TestGetFilesSourceAppPath()
        {
            EmbedFile embedFile = new EmbedFile();
            embedFile.sourcefilepath = @"#APPPATH\InstallerLibUnitTests.dll";
            embedFile.targetfilepath = @"#APPPATH\InstallerLibUnitTests.dll";
            string supportdir = Environment.CurrentDirectory;
            EmbedFileCollection embedFileCollection = embedFile.GetFiles(supportdir);
            Assert.AreEqual(1, embedFileCollection.Count);
            Assert.AreEqual(Path.Combine(Environment.CurrentDirectory, "InstallerLibUnitTests.dll"), embedFileCollection[0].fullpath);
            Assert.AreEqual("InstallerLibUnitTests.dll", embedFileCollection[0].relativepath);
        }
    }
}
