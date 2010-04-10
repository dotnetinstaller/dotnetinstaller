using System;
using InstallerLib;

namespace InstallerEditor
{
    /// <summary>
    /// A menu item representing a template.
    /// </summary>
    public class MenuItemTemplate : System.Windows.Forms.MenuItem
    {
        public MenuItemTemplate()
        {
            RadioCheck = true;
        }

        protected override void OnClick(EventArgs e)
        {
            base.OnClick(e);
            Checked = true;
            foreach (System.Windows.Forms.MenuItem mn in Parent.MenuItems)
                if (mn != this)
                    mn.Checked = false;
        }

        public virtual bool AreEqual(string filename)
        {
            return (Text == filename);
        }
    }

    /// <summary>
    /// A menu item representing a template.
    /// </summary>
    public class MenuItemTemplateInstance : MenuItemTemplate
    {
        private Template m_Template;

        public MenuItemTemplateInstance(Template template)
        {
            m_Template = template;
            Text = template.Name;
        }

        protected override void OnClick(EventArgs e)
        {
            base.OnClick(e);
            Template.CurrentTemplate = m_Template;
        }
    }
}
