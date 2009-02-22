using System;
using InstallerLib;

namespace InstallerEditor
{
	/// <summary>
	/// Summary description for MenuItemTemplateFile.
	/// </summary>
	public class MenuItemTemplateFile : System.Windows.Forms.MenuItem
	{
		private AppSetting m_AppSetting;
		private string m_FileName;
		public MenuItemTemplateFile(AppSetting p_AppSetting,
									string p_FileName)
		{
			m_FileName = p_FileName;
			m_AppSetting = p_AppSetting;

			System.IO.FileInfo fl = new System.IO.FileInfo(p_FileName);
			base.Text = fl.Name;
			RadioCheck = true;
		}

		protected override void OnClick(EventArgs e)
		{
			base.OnClick (e);

			try
			{
				using (System.IO.FileStream st = new System.IO.FileStream(m_FileName, System.IO.FileMode.Open, System.IO.FileAccess.Read))
				{
					Template.CurrentTemplate = new Template(st, base.Text);
					st.Close();
				}

				m_AppSetting.TemplateConfigFile = m_FileName;
				Checked = true;

				foreach (System.Windows.Forms.MenuItem mn in Parent.MenuItems)
					if (mn != this)
						mn.Checked = false;
			}
			catch(Exception err)
			{
				SourceLibrary.Windows.Forms.ErrorDialog.Show(err, "Error");
			}
		}
	}
}
