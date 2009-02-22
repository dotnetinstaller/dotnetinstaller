using System;

namespace InstallerEditor
{
	/// <summary>
	/// Summary description for AppSetting.
	/// </summary>
	public class AppSetting : SourceLibrary.IO.IsolatedStorage.IsolatedStorageSettingVersionBase
	{
		public AppSetting() : base(3)
		{
			base.StorageFileName = "InstallerEditorAppSetting.bin";
		}

		private string m_BannerBitmapFile;
		public string BannerBitmapFile
		{
			get{return m_BannerBitmapFile;}
			set{m_BannerBitmapFile = value;}
		}

        private string m_IconFile;
        public string IconFile
        {
            get { return m_IconFile; }
            set { m_IconFile = value; }
        }

		private string m_OutputMakeFile;
		public string OutputMakeFile
		{
			get{return m_OutputMakeFile;}
			set{m_OutputMakeFile = value;}
		}
		private string m_TemplateInstallerFile;
		public string TemplateInstallerFile
		{
			get{return m_TemplateInstallerFile;}
			set{m_TemplateInstallerFile = value;}
		}

		private string m_TemplateConfigFile;
		/// <summary>
		/// Name of the file template. If null the default template is used.
		/// </summary>
		public string TemplateConfigFile
		{
			get{return m_TemplateConfigFile;}
			set{m_TemplateConfigFile = value;}
		}

		private System.Collections.Specialized.StringCollection m_AvailableTemplates = new System.Collections.Specialized.StringCollection();
		/// <summary>
		/// The list of available config files.
		/// </summary>
		public System.Collections.Specialized.StringCollection AvailableTemplates
		{
			get{return m_AvailableTemplates;}
		}

		protected override void OnCreate()
		{
			m_TemplateConfigFile = null;
			m_TemplateInstallerFile = "";
			m_AvailableTemplates.Clear();
		}


		protected override void OnLoad(System.IO.IsolatedStorage.IsolatedStorageFileStream p_File, int p_CurrentVersion)
		{            
			Read(p_File, out m_OutputMakeFile);
			Read(p_File, out m_BannerBitmapFile);
			Read(p_File, out m_TemplateInstallerFile);

            if (p_CurrentVersion > 2)
            {
                Read(p_File, out m_IconFile);
            }
			
            //Version 2
            if (p_CurrentVersion > 1)
            {
                Read(p_File, out m_TemplateConfigFile);

                int l_NumberOfTemplates;
                m_AvailableTemplates.Clear();
                Read(p_File, out l_NumberOfTemplates);
                for (int i = 0; i < l_NumberOfTemplates; i++)
                {
                    string tmp;
                    Read(p_File, out tmp);
                    m_AvailableTemplates.Add(tmp);
                }
            }
		}

		protected override void OnSave(System.IO.IsolatedStorage.IsolatedStorageFileStream p_File)
		{
			base.OnSave(p_File);

			Write(p_File, m_OutputMakeFile);
			Write(p_File, m_BannerBitmapFile);
			Write(p_File, m_TemplateInstallerFile);

            //Version 3
            Write(p_File, m_IconFile);

			//Version 2
			Write(p_File, m_TemplateConfigFile);
			Write(p_File, m_AvailableTemplates.Count);
			for (int i = 0; i < m_AvailableTemplates.Count; i++)
				Write(p_File, m_AvailableTemplates[i]);
		}
	}
}
