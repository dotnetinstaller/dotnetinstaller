using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Automation;
using System.Reflection;
using White.Core.UIItems.MenuItems;

namespace InstallerEditorUnitTests
{
    public abstract class UIAutomation
    {
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

        public static Menu ClickThroughMenu(Menus m, string[] items)
        {
            List<string> itemsArray = new List<string>(items);
            if (itemsArray.Count == 0) throw new ArgumentOutOfRangeException();
            Menu rootMenu = m.Find(itemsArray[0]);
            if (rootMenu == null) throw new Exception(string.Format("Missing menu: ", itemsArray[0]));
            itemsArray.RemoveAt(0);
            return ClickThroughMenu(rootMenu, itemsArray.ToArray());
        }

        public static Menu ClickThroughMenu(Menu m, string[] items)
        {
            m.Click();
            foreach (string item in items)
            {
                Menu itemMenu = m.ChildMenus.Find(item);
                if (itemMenu == null)
                {
                    throw new Exception(string.Format("Missing menu: {0}", item));
                }
                itemMenu.Click();
                m = itemMenu;
            }
            return m;
        }
    }
}
