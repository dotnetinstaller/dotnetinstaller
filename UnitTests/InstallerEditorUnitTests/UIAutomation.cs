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
    }
}
