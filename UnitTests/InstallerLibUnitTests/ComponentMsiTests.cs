using System;
using System.Collections.Generic;
using System.Text;
using InstallerLib;
using NUnit.Framework;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ComponentMsiTests
    {
        [Test]
        public void EmbedTest()
        {
            ComponentMsi component = new ComponentMsi();
            component.package = "Setup.msi";
            Assert.AreEqual(1, component.GetFiles().Count);
            component.embed = false;
            Assert.AreEqual(0, component.GetFiles().Count);
        }
    }
}
