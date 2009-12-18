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
using White.Core.UIItems.Custom;
using White.Core.UIItems.TableItems;
using White.Core.WindowsAPI;
using System.IO;
using InstallerLib;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UITemplateUnitTests
    {
        [Test]
        public void TestAddSetupConfigurationLang()
        {
            using (Application installerEditor = Application.Launch(InstallerEditorExeUtils.Executable))
            {
                Window mainWindow = installerEditor.GetWindow("Installer Editor", InitializeOption.NoCache);
                try
                {
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
                        TableHeader cancelCaptionItem = UIAutomation.Find<TableHeader>(propertyGrid, "cancel_caption");
                        ValuePattern cancelCaptionValuePattern = (ValuePattern) cancelCaptionItem.AutomationElement.GetCurrentPattern(ValuePattern.Pattern);
                        string currentCancelCaptionValue = cancelCaptionValuePattern.Current.Value;
                        Console.WriteLine(" {0}: {1}", language, currentCancelCaptionValue);
                        Assert.AreNotEqual(currentCancelCaptionValue, prevousCancelCaptionValue);
                        prevousCancelCaptionValue = currentCancelCaptionValue;
                    }
                }
                finally
                {
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("Tools", "Template For New Item", "English").Click();
                }
            }
        }
    }
}
