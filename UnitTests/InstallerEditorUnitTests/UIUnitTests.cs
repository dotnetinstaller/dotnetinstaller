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
                Menus mainMenu = mainWindow.MenuBar.TopLevelMenu;
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
                StatusStrip statusStrip = mainWindow.Get<StatusStrip>("statusStrip");
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
                Menu fileMenu = mainWindow.MenuBar.TopLevelMenu.Find("File");
                fileMenu.Click();
                Menu fileNewConfigurationMenu = fileMenu.ChildMenus.Find("New");
                fileNewConfigurationMenu.Click();
                // status says "Ready"
                StatusStrip statusStrip = mainWindow.Get<StatusStrip>("statusStrip");
                WinFormTextBox statusLabel = (WinFormTextBox)statusStrip.Items[0];
                Assert.AreEqual("Ready", statusLabel.Text);
                // configuration tree has one node
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);
                Assert.AreEqual(0, configurationTree.SelectedNode.Nodes.Count);
                Assert.AreEqual("Config File", configurationTree.SelectedNode.Text);
            }
        }

        [Test]
        public void TestAddSetupConfiguration()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                Menu fileMenu = mainWindow.MenuBar.TopLevelMenu.Find("File");
                fileMenu.Click();
                Menu fileNewConfigurationMenu = fileMenu.ChildMenus.Find("New");
                fileNewConfigurationMenu.Click();

                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                Assert.AreEqual(1, configurationTree.Nodes.Count);

                string[] componentsMenuItems = { "Msi Component", "Command Component", "Msu Component", "OpenFile Component" };
                string[] checksMenuItems = { "Installed Check Registry", "Installed Check File", "Installed Check Directory", 
                    "Installed Check Operator", "Installed Check ProductCode" };

                UIAutomation.ClickThroughMenu(mainWindow.MenuBar.TopLevelMenu,
                    new string[] { "Edit", "Add", "Configurations", "Setup Configuration" });
                TreeNode configurationNode = configurationTree.SelectedNode;
                foreach (string componentMenuItem in componentsMenuItems)
                {
                    configurationNode.Select();
                    UIAutomation.ClickThroughMenu(mainWindow.MenuBar.TopLevelMenu,
                        new string[] { "Edit", "Add", "Components", componentMenuItem });

                    TreeNode componentNode = configurationTree.SelectedNode;
                    foreach (string checksMenuItem in checksMenuItems)
                    {
                        componentNode.Select();
                        UIAutomation.ClickThroughMenu(mainWindow.MenuBar.TopLevelMenu,
                            new string[] { "Edit", "Add", "Checks", checksMenuItem });
                    }

                    componentNode.Select();
                    UIAutomation.ClickThroughMenu(mainWindow.MenuBar.TopLevelMenu,
                        new string[] { "Edit", "Delete" });
                }
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
