using System;
using System.Collections.Generic;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Diagnostics;
using System.Threading;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.WindowStripControls;
using TestStack.White.UIItems.TreeItems;
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
            //TODO: High: ok button on error window is not automatically clicked on windows 7 ultimate x64

            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            options.args = Guid.NewGuid().ToString();
            ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, options.CommandLineArgs);
            using (Application installerEditor = Application.Launch(pi))
            {
                List<Window> windows = installerEditor.GetWindows();
                Assert.AreEqual(windows.Count, 2);
                Window errorWindow = windows[1];
                Assert.IsNotNull(errorWindow);
                Assert.AreEqual(errorWindow.Title, "Error");
                Button exitButton = UIAutomation.Find<Button>(errorWindow, "OK");
                exitButton.Click();
                while (!installerEditor.HasExited) Thread.Sleep(100);
                Assert.AreEqual(-2, installerEditor.Process.ExitCode);
            }
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
                ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, "\"" + configFileName + "\"");
                using (Application installerEditor = Application.Launch(pi))
                {
                    string title = string.Format("Installer Editor - {0}", configFileName);
                    Window mainWindow = installerEditor.GetWindow(title, InitializeOption.NoCache);
                    Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                    Assert.AreEqual("Config File", configurationTree.SelectedNode.Name);
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
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
            //TODO: High: ok button on error window is not automatically clicked on windows 7 ultimate x64

            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            options.args = Environment.SystemDirectory;
            ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, options.CommandLineArgs);
            using (Application installerEditor = Application.Launch(pi))
            {
                List<Window> windows = installerEditor.GetWindows();
                Assert.AreEqual(windows.Count, 2);
                Window errorWindow = windows[1];
                Assert.IsNotNull(errorWindow);
                Assert.AreEqual(errorWindow.Title, "Error");
                Button exitButton = UIAutomation.Find<Button>(errorWindow, "OK");
                exitButton.Click();
                while (!installerEditor.HasExited) Thread.Sleep(100);
                Assert.AreEqual(-3, installerEditor.Process.ExitCode);
            }
        }
    }
}
