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
    public class UIMoveUpDownUnitTests
    {
        [Test]
        public void TestMoveUpMoveDownConfiguration()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                mainWindow.MenuBar.MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                TreeNode configFileNode = configurationTree.SelectedNode;
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                configFileNode.Select();
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Configurations", "Web Configuration").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Up").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Down").Click();
            }
        }

        [Test]
        public void TestMoveUpMoveDownComponent()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                mainWindow.MenuBar.MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Components", "Msi Component").Click();
                configurationNode.Select();
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Components", "Msu Component").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Up").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Down").Click();
            }
        }

        [Test]
        public void TestMoveUpMoveDownChecks()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                mainWindow.MenuBar.MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Components", "Msi Component").Click();
                TreeNode componentNode = configurationTree.SelectedNode;
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Checks", "Installed Check Registry").Click();
                componentNode.Select();
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Checks", "Installed Check File").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Up").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Down").Click();
            }
        }

        [Test]
        public void TestMoveUpMoveDownEmbedFileFolder()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                mainWindow.MenuBar.MenuItem("File", "New").Click();
                Tree configurationTree = mainWindow.Get<Tree>("configurationTree");
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                TreeNode configurationNode = configurationTree.SelectedNode;
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Embed", "Embed File").Click();
                configurationNode.Select();
                mainWindow.MenuBar.MenuItem("Edit", "Add", "Embed", "Embed Folder").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Up").Click();
                mainWindow.MenuBar.MenuItem("Edit", "Move", "Down").Click();
            }
        }
    }
}
