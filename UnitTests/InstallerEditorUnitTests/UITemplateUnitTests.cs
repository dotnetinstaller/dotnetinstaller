using System;
using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Windows.Automation;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.WindowStripControls;
using TestStack.White.UIItems.MenuItems;
using TestStack.White.UIItems.TreeItems;
using TestStack.White.UIItems.TableItems;
using TestStack.White.WindowsAPI;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UITemplateUnitTests : EnUsUnitTests
    {
        [Test]
        public void TestAddSetupConfigurationLang()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "New").Click();
                Tree configurationTree = UIAutomation.Find<Tree>(mainWindow, "configurationTree");
                TreeNode configurationNode = configurationTree.SelectedNode;
                string prevousCancelCaptionValue = string.Empty;
                string[] languages = { "English", "Deutsch", "Français", "Italiano" };
                foreach (string language in languages)
                {
                    configurationNode.Select();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Tools", "Template For New Item", language).Click();
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Edit", "Add", "Configurations", "Setup Configuration").Click();
                    Panel propertyGrid = UIAutomation.Find<Panel>(mainWindow, "propertyGrid");
                    TestStack.White.UIItems.Custom.CustomUIItem cancelCaptionItem = UIAutomation.Find<TestStack.White.UIItems.Custom.CustomUIItem>(propertyGrid, "cancel_caption");
                    ValuePattern cancelCaptionValuePattern = (ValuePattern)cancelCaptionItem.AutomationElement.GetCurrentPattern(ValuePattern.Pattern);
                    string currentCancelCaptionValue = cancelCaptionValuePattern.Current.Value;
                    Console.WriteLine(" {0}: {1}", language, currentCancelCaptionValue);
                    Assert.AreNotEqual(currentCancelCaptionValue, prevousCancelCaptionValue);
                    prevousCancelCaptionValue = currentCancelCaptionValue;
                }
                // note: the selection is not saved since the application is killed
            }
        }

        [Test]
        public void TestCustomizeTemplates()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                Menu templateForNewItem = UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Tools", "Template For New Item");
                templateForNewItem.Click();
                int countBefore = templateForNewItem.ChildMenus.Count;
                UIAutomation.Find<Menu>(templateForNewItem, "English").Click();
                // add an item
                UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Tools", "Customize Templates").Click();
                Window customizeTemplatesWindow = mainWindow.ModalWindow("Customize Templates");
                Panel gridList = UIAutomation.Find<Panel>(customizeTemplatesWindow, "gridList");
                gridList.DoubleClick();
                gridList.Keyboard.Enter(string.Format(@"{0}\english_template.xml", InstallerLibUtils.TemplatesLocation));
                gridList.KeyIn(KeyboardInput.SpecialKeys.RETURN);
                UIAutomation.Find<Button>(customizeTemplatesWindow, "OK").Click();
                // check whether the item was added
                templateForNewItem = UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Tools", "Template For New Item");
                templateForNewItem.Click();
                int countAfter = templateForNewItem.ChildMenus.Count;
                UIAutomation.Find<Menu>(templateForNewItem, "English").Click();
                Assert.AreEqual(countBefore + 1, countAfter);
                // note: the updated list is not saved since the application is killed
            }
        }
    }
}
