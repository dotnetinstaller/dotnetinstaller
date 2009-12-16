using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Windows.Automation;
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

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UIUnitTests
    {
        [Test]
        public void TestMainMenu()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                Menus mainMenu = mainWindowMenuBar.TopLevelMenu;
                Assert.AreEqual(5, mainMenu.Count);
                Assert.AreEqual("File", mainMenu[0].Name);
                Assert.AreEqual("Edit", mainMenu[1].Name);
                Assert.AreEqual("View", mainMenu[2].Name);
                Assert.AreEqual("Tools", mainMenu[3].Name);
                Assert.AreEqual("Help", mainMenu[4].Name);
            }
        }

        [Test]
        public void TestStatusReady()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                StatusStrip statusStrip = UIAutomation.Find<StatusStrip>(mainWindow, "statusStrip");
                WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                Assert.AreEqual("Ready", statusLabel.Text);
            }
        }

        [Test]
        public void TestNewConfiguration()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                Menu fileMenu = mainWindowMenuBar.TopLevelMenu.Find("File");
                fileMenu.Click();
                Menu fileNewConfigurationMenu = fileMenu.ChildMenus.Find("New");
                fileNewConfigurationMenu.Click();
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
                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("File", "New").Click();

                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);

                string[] controlMenuItems = { "Label", "Edit", "Checkbox", "Browse", "Hyperlink" };

                mainWindowMenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;

                foreach (string controlMenuItem in controlMenuItems)
                {
                    configurationNode.Select();
                    mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                    mainWindowMenuBar.MenuItem("Edit", "Add", "Controls", controlMenuItem).Click();
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

                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("File", "New").Click();

                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);

                mainWindowMenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;

                mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("Edit", "Add", "Controls", "License Agreement").Click();
                Assert.AreEqual("I have read and ...", configurationTree.SelectedNode.Name);
            }
        }

        [Test]
        public void TestAddSetupConfigurationComponents()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                mainWindowMenuBar.MenuItem("File", "New").Click();

                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);

                string[] componentsMenuItems = { "Msi Component", "Command Component", "Msu Component", "OpenFile Component" };
                string[] checksMenuItems = { "Installed Check Registry", "Installed Check File", "Installed Check Directory", 
                    "Installed Check Operator", "Installed Check ProductCode" };

                mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                mainWindowMenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;

                foreach (string componentMenuItem in componentsMenuItems)
                {
                    configurationNode.Select();
                    mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                    mainWindowMenuBar.MenuItem("Edit", "Add", "Components", componentMenuItem).Click();

                    TreeNode componentNode = configurationTree.SelectedNode;
                    foreach (string checksMenuItem in checksMenuItems)
                    {
                        componentNode.Select();
                        mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                        mainWindowMenuBar.MenuItem("Edit", "Add", "Checks", checksMenuItem).Click();
                    }

                    componentNode.Select();
                    mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                    mainWindowMenuBar.MenuItem("Edit", "Delete").Click();
                }
            }
        }

        [Test]
        public void TestAddDownloadDialog()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application"); 
                mainWindowMenuBar.MenuItem("File", "New").Click();
                mainWindowMenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("Edit", "Add", "Components", "Msi Component").Click();
                mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("Edit", "Add", "Download", "Download Dialog").Click();
                mainWindowMenuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                mainWindowMenuBar.MenuItem("Edit", "Add", "Download", "Download File").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                Assert.AreEqual("Download File", configurationTree.SelectedNode.Name);
            }
        }

        [Test]
        public void DumpControls()
        {
            InstallerEditorExeUtils.RunOptions options = new InstallerEditorExeUtils.RunOptions();
            using (Process p = InstallerEditorExeUtils.Detach(options))
            {
                Thread.Sleep(2000);
                p.WaitForInputIdle();
                UIAutomation.DumpControl(AutomationElement.FromHandle(p.MainWindowHandle));
                p.CloseMainWindow();
                p.WaitForExit();
            }
        }
    }
}
