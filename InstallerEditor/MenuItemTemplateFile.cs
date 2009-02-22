using System;
using InstallerLib;
using System.IO;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for MenuItemTemplateFile.
    /// </summary>
    public class MenuItemTemplateFile : MenuItemTemplate
    {
        private string m_FileName;

        public MenuItemTemplateFile(AppSetting p_AppSetting, string p_FileName)
            : base(p_AppSetting)
        {
            m_FileName = p_FileName;
            FileInfo fl = new FileInfo(p_FileName);
            Text = fl.Name;
        }

        protected override void OnClick(EventArgs e)
        {
            try
            {
                using (System.IO.FileStream st = new System.IO.FileStream(m_FileName, System.IO.FileMode.Open, System.IO.FileAccess.Read))
                {
                    Template.CurrentTemplate = new Template(st, base.Text);
                    st.Close();
                }

                m_AppSetting.TemplateConfigFile = m_FileName;
                base.OnClick(e);
            }
            catch (Exception err)
            {
                SourceLibrary.Windows.Forms.ErrorDialog.Show(err, "Error");
            }
        }

        public override bool AreEqual(string filename)
        {
            return (m_FileName == filename);
        }
    }
}
