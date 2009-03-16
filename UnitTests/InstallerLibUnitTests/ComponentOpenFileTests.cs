using System;
using System.Collections.Generic;
using System.Text;
using InstallerLib;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ComponentOpenFileTests
    {
        [Test]
        public void EmbedTest()
        {
            ComponentOpenFile component = new ComponentOpenFile();
            component.file = "Test.exe";
            Assert.AreEqual(1, component.GetFiles().Count);
            component.embed = false;
            Assert.AreEqual(0, component.GetFiles().Count);
        }
    }
}
