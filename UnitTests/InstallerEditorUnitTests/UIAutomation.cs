using System;
using System.Windows.Automation;
using TestStack.White.Factory;
using TestStack.White.UIItems;

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
