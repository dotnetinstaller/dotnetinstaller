using System;
using System.IO;
using System.Windows.Automation;
using NUnit.Framework;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.Finders;
using TestStack.White.UIItems.WindowItems;

namespace InstallerEditorUnitTests
{
    public abstract class UIAutomation
    {
        public static void DumpControl(UIItem el)
        {
            DumpControl(el.AutomationElement, true);
        }

        public static void DumpControl(AutomationElement el)
        {
            DumpControl(el, true);
        }

        public static void DumpControl(AutomationElement el, bool recurse)
        {
            DumpControl(el, recurse, 0);
        }

        public static void FailWithErrorMessageFromErrorDialog(Window window)
        {
            try
            {
                Window errorDialog = window.ModalWindow(SearchCriteria.ByAutomationId("ErrorDialog"));
                Label errorMessageLabel = errorDialog.Get<Label>("lblErrorMessage");
                string errorMessage = errorMessageLabel.Text;

                // TODO: get and include exception details
                Assert.Fail(errorMessage);
            }
            finally
            {
                string pngFilePath = Path.Combine(TestContext.CurrentContext.WorkDirectory, $"{TestContext.CurrentContext.Test.FullName}-{TestContext.CurrentContext.Test.ID}.png");
                Desktop.TakeScreenshot(pngFilePath, System.Drawing.Imaging.ImageFormat.Png);
                Console.WriteLine($"Saved screenshot to \"{pngFilePath}\".");
            }
        }

        private static void DumpControl(AutomationElement el, bool recurse, int level)
        {
            Console.WriteLine("{0}{1}: {2}", new String(' ', level),
                el.Current.ControlType.LocalizedControlType, el.Current.Name);

            if (recurse)
            {
                foreach (AutomationElement child in el.FindAll(TreeScope.Children, Condition.TrueCondition))
                {
                    DumpControl(child, true, level + 1);
                }
            }
        }

        private static DictionaryMappedItemFactory _factory = new DictionaryMappedItemFactory();

        private static AutomationElement Find(AutomationElement element, string name, int maxDepth)
        {
            if (maxDepth == 0)
            {
                return null;
            }
            TreeWalker walker = TreeWalker.RawViewWalker;
            AutomationElement current = walker.GetFirstChild(element);
            while (current != null)
            {
                if ((string)current.GetCurrentPropertyValue(AutomationElement.NameProperty) == name)
                {
                    return current;
                }
                current = walker.GetNextSibling(current);
            }
            current = walker.GetFirstChild(element);
            while (current != null)
            {
                AutomationElement found = Find(current, name, maxDepth - 1);
                if (found != null)
                {
                    return found;
                }
                current = walker.GetNextSibling(current);
            }
            return null;
        }

        private static UIItem Find(UIItem item, string name, int maxDepth)
        {
            AutomationElement element = Find(item.AutomationElement, name, maxDepth);
            if (element == null) return null;
            return (UIItem)_factory.Create(element, item.ActionListener);
        }

        public static T Find<T>(UIItem item, string name) where T : UIItem
        {
            return (T)Find(item, name, 4);
        }
    }
}
