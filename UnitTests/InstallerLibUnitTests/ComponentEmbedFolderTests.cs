using System;
using System.Collections.Generic;
using InstallerLib;
using System.IO;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ComponentEmbedFolderTests
    {
        [Test]
        public void TestGetFilesNoTargetPath()
        {
            EmbedFolder embedFolder = new EmbedFolder();
            embedFolder.sourcefolderpath = Path.Combine(Environment.GetFolderPath(
                Environment.SpecialFolder.System), @"spool\tools");
            string supportdir = @"C:\SupportFiles\SupportFolder";
            Dictionary<string, EmbedFileCollection> embedFileCollection = embedFolder.GetFiles(string.Empty, supportdir);
            foreach (EmbedFilePair pair in embedFileCollection[string.Empty])
            {
                Console.WriteLine("{0} -> {1}", pair.fullpath, pair.relativepath);
                Assert.IsFalse(pair.relativepath.StartsWith(@"\"));
                Assert.IsTrue(File.Exists(pair.fullpath));
            }
        }

        [Test]
        public void TestGetFilesTargetWithoutBackslashPath()
        {
            EmbedFolder embedFolder = new EmbedFolder();
            embedFolder.sourcefolderpath = Path.Combine(Environment.GetFolderPath(
                Environment.SpecialFolder.System), @"spool\tools");
            embedFolder.targetfolderpath = @"parent\child";
            string supportdir = @"C:\SupportFiles\SupportFolder";
            Dictionary<string, EmbedFileCollection> embedFileCollection = embedFolder.GetFiles(string.Empty, supportdir);
            foreach (EmbedFilePair pair in embedFileCollection[string.Empty])
            {
                Console.WriteLine("{0} -> {1}", pair.fullpath, pair.relativepath);
                Assert.IsFalse(pair.relativepath.StartsWith(@"\"));
                Assert.IsTrue(File.Exists(pair.fullpath));
                Assert.IsTrue(pair.relativepath.StartsWith(embedFolder.targetfolderpath));
            }
        }

        [Test]
        public void TestGetFilesTargetWithBackslashPath()
        {
            EmbedFolder embedFolder = new EmbedFolder();
            embedFolder.sourcefolderpath = Path.Combine(Environment.GetFolderPath(
                Environment.SpecialFolder.System), @"spool\tools");
            embedFolder.targetfolderpath = @"parent\child\";
            string supportdir = @"C:\SupportFiles\SupportFolder";
            Dictionary<string, EmbedFileCollection> embedFileCollection = embedFolder.GetFiles(string.Empty, supportdir);
            foreach (EmbedFilePair pair in embedFileCollection[string.Empty])
            {
                Console.WriteLine("{0} -> {1}", pair.fullpath, pair.relativepath);
                Assert.IsFalse(pair.relativepath.StartsWith(@"\"));
                Assert.IsTrue(File.Exists(pair.fullpath));
                Assert.IsTrue(pair.relativepath.StartsWith(embedFolder.targetfolderpath));
                Assert.IsFalse(pair.relativepath.Contains(@"\\"));
            }
        }

        [Test]
        public void TestGetFilesTargetWithBackslashPath2()
        {
            EmbedFolder embedFolder = new EmbedFolder();
            embedFolder.sourcefolderpath = Path.Combine(Environment.GetFolderPath(
                Environment.SpecialFolder.System), @"spool\tools");
            embedFolder.targetfolderpath = @"\parent\child\";
            string supportdir = @"C:\SupportFiles\SupportFolder";
            Dictionary<string, EmbedFileCollection> embedFileCollection = embedFolder.GetFiles(string.Empty, supportdir);
            foreach (EmbedFilePair pair in embedFileCollection[string.Empty])
            {
                Console.WriteLine("{0} -> {1}", pair.fullpath, pair.relativepath);
                Assert.IsFalse(pair.relativepath.StartsWith(@"\"));
                Assert.IsTrue(File.Exists(pair.fullpath));
                Assert.IsTrue(pair.relativepath.StartsWith(embedFolder.targetfolderpath.TrimStart(Path.DirectorySeparatorChar)));
                Assert.IsFalse(pair.relativepath.Contains(@"\\"));
            }
        }
    }
}
