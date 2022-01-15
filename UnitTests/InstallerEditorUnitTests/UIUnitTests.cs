using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Windows.Automation;
using System.Diagnostics;
using System.Threading;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.WindowStripControls;
using TestStack.White.UIItems.MenuItems;
using TestStack.White.UIItems.TreeItems;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UIUnitTests : EnUsUnitTests
    {
        [Test]
        public void TestMainMenu()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                Menus mainMenu = UIAutomation.Find<MenuBar>(mainWindow, "Application").TopLevelMenu;
                Assert.AreEqual(5, mainMenu.Count);
                Assert.AreEqual("File", mainMenu[0].Name);
                Assert.AreEqual("Edit", mainMenu[1].Name);
                Assert.AreEqual("View", mainMenu[2].Name);
                Assert.AreEqual("Tools", mainMenu[3].Name);
                Assert.AreEqual("Help", mainMenu[4].Name);
            }
        }

        [Test]
        public void TestMainMenuFile()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar menuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                Menu menu = menuBar.MenuItem("File");
                Assert.IsTrue(menu.SubMenu("New").Enabled);
                Assert.IsTrue(menu.SubMenu("Open...").Enabled);
                Assert.IsFalse(menu.SubMenu("Close").Enabled);
                Assert.IsFalse(menu.SubMenu("Save").Enabled);
                Assert.IsFalse(menu.SubMenu("Save As...").Enabled);
                Assert.IsFalse(menu.SubMenu("Close").Enabled);
                Assert.IsFalse(menu.SubMenu("Edit With Notepad").Enabled);
                Assert.IsFalse(menu.SubMenu("Create Exe...").Enabled);
                Assert.IsTrue(menu.SubMenu("Exit").Enabled);
            }
        }

        [Test]
        public void TestMainMenuEdit()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar menuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                Menu menu = menuBar.MenuItem("Edit");
                Assert.IsFalse(menu.SubMenu("Add").Enabled);
                Assert.IsFalse(menu.SubMenu("Move").Enabled);
                Assert.IsFalse(menu.SubMenu("Expand All").Enabled);
                Assert.IsFalse(menu.SubMenu("Collapse All").Enabled);
                Assert.IsFalse(menu.SubMenu("Delete").Enabled);
            }
        }

        [Test]
        public void TestMainMenuView()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar menuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                Menu menu = menuBar.MenuItem("View");
                Assert.IsTrue(menu.SubMenu("Refresh").Enabled);
            }
        }

        [Test]
        public void TestMainMenuHelp()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar menuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                Menu menu = menuBar.MenuItem("Help");
                Assert.IsTrue(menu.SubMenu("Users Guide").Enabled);
                Assert.IsTrue(menu.SubMenu("Home Page").Enabled);
                Assert.IsTrue(menu.SubMenu("About").Enabled);
            }
        }

        [Test]
        public void TestMainMenuTools()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                MenuBar menuBar = UIAutomation.Find<MenuBar>(mainWindow, "Application");
                Menu menu = menuBar.MenuItem("Tools");
                Assert.IsTrue(menu.SubMenu("Template For New Item").Enabled);
                Assert.IsTrue(menu.SubMenu("Customize Templates").Enabled);
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

        [Test]
        public void TestExpandCollapseRoot()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                TreeNode configFileNode = configurationTree.SelectedNode;
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                configFileNode.Select();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Web Configuration").Click();
                configFileNode.Select();
                Assert.IsTrue(configFileNode.IsExpanded());
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Collapse All").Click();
                Assert.IsFalse(configFileNode.IsExpanded());
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Expand All").Click();
                Assert.IsTrue(configFileNode.IsExpanded());
            }
        }

        [Test]
        public void TestExit()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Exit").Click();
                Assert.IsTrue(mainWindow.IsClosed);
            }
        }

        [Test]
        public void TestRefresh()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                TreeNode configFileNode = configurationTree.SelectedNode;
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                configFileNode.Select();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Web Configuration").Click();
                configFileNode.Select();
                configFileNode.Collapse();
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("View", "Refresh").Click();
                configFileNode = configurationTree.SelectedNode;
                Assert.IsTrue(configFileNode.IsExpanded());
            }
        }

        [Test]
        public void TestHelpAbout()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Help", "About").Click();
                Window aboutWindow = mainWindow.ModalWindow("About");
                aboutWindow.Close();
            }
        }
    }
}
