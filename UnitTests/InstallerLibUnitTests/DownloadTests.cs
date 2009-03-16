using System;
using System.Collections.Generic;
using System.Text;
using InstallerLib;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class DownloadTests
    {
        [Test]
        public void EmbedTest()
        {
            Download download = new Download();
            download.sourceurl = "http://dotnetinstaller.codeplex.com/dummy.txt";
            download.destinationfilename = "dummy.txt";
            download.destinationpath = "dummy";
            Assert.AreEqual(1, download.GetFiles().Count);
            download.embed = false;
            Assert.AreEqual(0, download.GetFiles().Count);
        }
    }
}
