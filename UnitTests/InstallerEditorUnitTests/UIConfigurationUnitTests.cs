using System;
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
using White.Core.WindowsAPI;
using System.IO;
using InstallerLib;
using System.Runtime.InteropServices;
using Microsoft.Win32;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UIConfigurationUnitTests : EnUsUnitTests
    {
        [Test]
        public void TestNewConfiguration()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").TopLevelMenu.Find("File").Click();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").TopLevelMenu.Find("File").ChildMenus.Find("New").Click();
                // status says "Ready"
                StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                Assert.AreEqual("Ready", statusLabel.Text);
                // configuration tree has one node
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);
                Assert.AreEqual(0, configurationTree.SelectedNode.Nodes.Count);
                Assert.AreEqual("Config File", configurationTree.SelectedNode.Text);
            }
        }

        [Test]
        public void TestAddSetupConfigurationControls()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);
                string[] controlMenuItems = { "Label", "Edit", "Checkbox", "Browse", "Hyperlink" };
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;
                foreach (string controlMenuItem in controlMenuItems)
                {
                    configurationNode.Select();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Controls", controlMenuItem).Click();
                    Assert.AreEqual("Lorem ipsum", configurationTree.SelectedNode.Name);
                }
            }
        }

        [Test]
        public void TestAddSetupConfigurationLicenseAgreement()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Controls", "License Agreement").Click();
                Assert.AreEqual("I have read and ...", configurationTree.SelectedNode.Name);
            }
        }

        [Test]
        public void TestAddSetupConfigurationComponents()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);
                string[] componentsMenuItems = { "Msi Component", "Command Component", "Msu Component", "Msp Component", "OpenFile Component" };
                string[] checksMenuItems = { "Installed Check Registry", "Installed Check File", "Installed Check Directory", 
                    "Installed Check Operator", "Installed Check ProductCode" };
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;
                foreach (string componentMenuItem in componentsMenuItems)
                {
                    configurationNode.Select();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Components", componentMenuItem).Click();
                    TreeNode componentNode = configurationTree.SelectedNode;
                    foreach (string checksMenuItem in checksMenuItems)
                    {
                        componentNode.Select();
                        UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Checks", checksMenuItem).Click();
                    }

                    componentNode.Select();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Delete").Click();
                }
            }
        }

        [Test]
        public void TestAddDownloadDialog()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Components", "Msi Component").Click();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Download", "Download Dialog").Click();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Download", "Download File").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual("Download File", configurationTree.SelectedNode.Name);
            }
        }

        [Test]
        public void TestOpenCloseConfiguration()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFileName);
            configFile.SaveAs(configFileName);
            try
            {
                using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
                {
                    Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Open...").Click();
                    Window openWindow = mainWindow.ModalWindow("Open");
                    TextBox filenameTextBox = openWindow.Get<TextBox>("File name:");
                    filenameTextBox.Text = configFileName;
                    openWindow.KeyIn(KeyboardInput.SpecialKeys.RETURN);
                    mainWindow.WaitWhileBusy();
                    Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                    Assert.AreEqual("Config File", configurationTree.SelectedNode.Name);
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                    Assert.AreEqual(string.Format("Loaded {0}", configFileName), statusLabel.Text);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Close").Click();
                    Assert.AreEqual(0, configurationTree.Nodes.Count);
                    Assert.AreEqual("Ready", statusLabel.Text);
                }
            }
            finally
            {
                File.Delete(configFileName);
            }
        }

        [Test]
        public void TestSaveConfiguration()
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
                    Window mainWindow = installerEditor.GetWindow(
                        string.Format("Installer Editor - {0}", configFileName), InitializeOption.NoCache);
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                    Assert.AreEqual(string.Format("Loaded {0}", configFileName), statusLabel.Text);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Save").Click();
                    Assert.AreEqual(string.Format("Written {0}", configFileName), statusLabel.Text);
                    ConfigFile savedConfigFile = new ConfigFile();
                    savedConfigFile.Load(configFileName);
                    Assert.AreEqual(2, savedConfigFile.Children.Count);
                }
            }
            finally
            {
                File.Delete(configFileName);
            }
        }

        [Test]
        public void TestSaveAsConfiguration()
        {
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            try
            {
                using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
                {
                    Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                    Menu mainMenuFile = UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File");
                    mainMenuFile.Click();
                    Assert.IsFalse(mainMenuFile.ChildMenus.Find("Save").Enabled);
                    mainMenuFile.ChildMenus.Find("Save As...").Click();
                    Window openWindow = mainWindow.ModalWindow("Save As");
                    TextBox filenameTextBox = openWindow.Get<TextBox>("File name:");
                    filenameTextBox.Text = configFileName;
                    openWindow.KeyIn(KeyboardInput.SpecialKeys.RETURN);
                    openWindow.WaitWhileBusy();
                    mainWindow.WaitWhileBusy();
                    Assert.IsTrue(File.Exists(configFileName));
                    Assert.IsTrue(UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Save").Enabled);
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                    Assert.AreEqual(string.Format("Written {0}", configFileName), statusLabel.Text);
                    ConfigFile savedConfigFile = new ConfigFile();
                    savedConfigFile.Load(configFileName);
                    Assert.AreEqual(1, savedConfigFile.Children.Count);
                }
            }
            finally
            {
                if (File.Exists(configFileName))
                    File.Delete(configFileName);
            }
        }

        #region Short Display Name

        [DllImport("shlwapi.dll", CharSet = CharSet.Auto)]
        private static extern bool PathCompactPathEx(
            StringBuilder pszOut,
            string pszPath,
            int cchMax,
            int reserved);

        private string GetShortDisplayName(string longName, int maxLen)
        {
            StringBuilder pszOut = new StringBuilder(maxLen + maxLen + 2);  // for safety

            if (PathCompactPathEx(pszOut, longName, maxLen, 0))
            {
                return pszOut.ToString();
            }
            else
            {
                return longName;
            }
        }

        #endregion

        [Test]
        public void TestOpenRecent()
        {
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            try
            {
                using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
                {
                    Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                    Menu mainMenuFile = UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File");
                    mainMenuFile.Click();
                    mainMenuFile.ChildMenus.Find("Save As...").Click();
                    Window openWindow = mainWindow.ModalWindow("Save As");
                    TextBox filenameTextBox = openWindow.Get<TextBox>("File name:");
                    filenameTextBox.Text = configFileName;
                    openWindow.KeyIn(KeyboardInput.SpecialKeys.RETURN);
                    openWindow.WaitWhileBusy();
                    mainWindow.WaitWhileBusy();
                    Assert.IsTrue(File.Exists(configFileName));
                    string shortDisplayFileName = GetShortDisplayName(configFileName, 40);
                    Console.WriteLine(shortDisplayFileName);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Recent Files", shortDisplayFileName).Click();
                    StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                    WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                    Assert.AreEqual(string.Format("Loaded {0}", configFileName), statusLabel.Text);
                }
            }
            finally
            {
                if (File.Exists(configFileName))
                    File.Delete(configFileName);
            }
        }

        [Test]
        public void TestEditWithNotepad()
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
                    Window mainWindow = installerEditor.GetWindow(
                        string.Format("Installer Editor - {0}", configFileName), InitializeOption.NoCache);
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Edit With Notepad").Click();
                    Thread.Sleep(1000);
                    string windowText = string.Format("{0} -", Path.GetFileName(configFileName));

                    using (RegistryKey currentUserKey = RegistryKey.OpenBaseKey(RegistryHive.CurrentUser, RegistryView.Registry64))
                    {
                        using (RegistryKey key = currentUserKey.OpenSubKey(@"Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"))
                        {
                            object hideFileExt = key.GetValue("HideFileExt");
                            if ((int)hideFileExt == 1)
                            {
                                // file extensions are hidden
                                windowText = string.Format("{0} -", Path.GetFileNameWithoutExtension(configFileName));
                            }
                        }
                    }

                    Console.WriteLine(windowText);
                    bool foundNotepad = false;
                    foreach (Process p in Process.GetProcessesByName("notepad"))
                    {
                        Console.WriteLine($"Found process with id {p.Id} with main window title '{p.MainWindowTitle}'.");

                        if (p.MainWindowTitle.StartsWith(windowText))
                        {
                            p.CloseMainWindow();
                            foundNotepad = true;
                            break;
                        }
                    }
                    Assert.IsTrue(foundNotepad);
                }
            }
            finally
            {
                File.Delete(configFileName);
            }
        }
    }
}
