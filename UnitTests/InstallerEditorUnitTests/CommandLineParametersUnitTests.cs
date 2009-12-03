using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Diagnostics;
using System.Threading;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class CommandLineParametersUnitTests
    {
        [Test]
        public void TestRunNoArguments()
        {
            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            InstallerEditorExeUtils.RunResult r = InstallerEditorExeUtils.Run(options);
            Assert.AreEqual("Installer Editor", r.WindowTitle);
            Assert.AreEqual(0, r.ExitCode);
        }

        [Test]
        public void TestRunHelp()
        {
            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            options.args = "/?";
            InstallerEditorExeUtils.RunResult r = InstallerEditorExeUtils.Run(options);
            Assert.AreEqual("Installer Editor Help", r.WindowTitle);
            Assert.AreEqual(2, r.ExitCode);
        }

        [Test]
        public void TestRunFileDoesntExist()
        {
            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            options.args = Guid.NewGuid().ToString();
            InstallerEditorExeUtils.RunResult r = InstallerEditorExeUtils.Run(options);
            Assert.AreEqual("Error", r.WindowTitle);
            Assert.AreEqual(-2, r.ExitCode);
        }

        [Test]
        public void TestRunFileIsADirectory()
        {
            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            options.args = Environment.SystemDirectory;
            InstallerEditorExeUtils.RunResult r = InstallerEditorExeUtils.Run(options);
            Assert.AreEqual("Error", r.WindowTitle);
            Assert.AreEqual(-3, r.ExitCode);
        }

    }
}
