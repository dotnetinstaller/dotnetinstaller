using System;
using InstallerLib;

namespace InstallerEditor
{
    /// <summary>
    /// A menu item representing a template.
    /// </summary>
    public class MenuItemTemplate : System.Windows.Forms.MenuItem
    {
        protected AppSetting m_AppSetting;

        public MenuItemTemplate(AppSetting appsettings)
        {
            m_AppSetting = appsettings;
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

        public MenuItemTemplateInstance(AppSetting appsetting, Template template)
            : base(appsetting)
        {
            m_Template = template;
            Text = template.Name;
        }

        protected override void OnClick(EventArgs e)
        {
            m_AppSetting.TemplateConfigFile = m_Template.Name;
            Template.CurrentTemplate = m_Template;
            base.OnClick(e);
        }
    }
}
