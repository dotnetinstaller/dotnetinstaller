using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Diagnostics;
using System.Threading;
using White.Core;
using White.Core.Factory;
using White.Core.UIItems;
using White.Core.UIItems.WindowItems;
using White.Core.UIItems.WindowStripControls;
using White.Core.UIItems.MenuItems;
using White.Core.UIItems.TreeItems;
using White.Core.UIItems.Finders;
using White.Core.WindowsAPI;
using InstallerLib;
using System.IO;

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
        public void TestRunFileConfiguration()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFileName);
            configFile.SaveAs(configFileName);
            try
            {
                ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, configFileName);
                using (Application installerEditor = Application.Launch(pi))
                {
                    string title = string.Format("Installer Editor - {0}", configFileName);
                    Window mainWindow = installerEditor.GetWindow(title, InitializeOption.NoCache);
                    Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                    Assert.AreEqual("Config File", configurationTree.SelectedNode.Name);
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox) statusStrip.Items[0];
                    Assert.AreEqual(string.Format("Loaded {0}", configFileName), statusLabel.Text);
                }
            }
            finally
            {
                File.Delete(configFileName);
            }
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
