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

        public MenuItemTemplateFile(string p_FileName)
        {
            m_FileName = p_FileName;
            FileInfo fl = new FileInfo(p_FileName);
            Text = fl.Name;
        }

        protected override void OnClick(EventArgs e)
        {
            try
            {
                using (FileStream st = new FileStream(m_FileName, FileMode.Open, FileAccess.Read))
                {
                    Template.CurrentTemplate = new Template(st, base.Text);
                    st.Close();
                }

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
