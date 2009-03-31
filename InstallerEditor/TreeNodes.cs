using System;
using System.Windows.Forms;
using InstallerLib;

namespace InstallerEditor
{
    public class TreeNodeImpl : TreeNode
    {
        public TreeNodeImpl()
        {

        }

        public void CreateChildNodes()
        {
            IXmlClass item = (IXmlClass) Tag;
            foreach (IXmlClass child in item.Children)
            {
                TreeNodeImpl childnode = CreateNode(child);
                Nodes.Add(childnode);
                childnode.CreateChildNodes();
            }
        }

        public static TreeNodeImpl CreateNode(IXmlClass item)
        {
            if (item is ConfigFile)
                return new TreeNodeConfigFile((ConfigFile)item);
            else if (item is Configuration)
                return new TreeNodeConfiguration((Configuration)item);
            else if (item is DownloadDialog)
                return new TreeNodeDownloadDialog((DownloadDialog)item);
            else if (item is Download)
                return new TreeNodeDownload((Download)item);
            else if (item is EmbedFile)
                return new TreeNodeEmbedFile((EmbedFile)item);
            else if (item is Component)
                return new TreeNodeComponent((Component)item);
            else if (item is InstalledCheck)
                return new TreeNodeInstalledCheck((InstalledCheck)item);
            else if (item is InstalledCheckOperator)
                return new TreeNodeInstalledCheckOperator((InstalledCheckOperator)item);
            else
                throw new Exception(string.Format("Unsupported type: {0}", item.GetType().Name));
        }

        public void MoveTo(TreeNodeImpl newParent)
        {
            MoveTo(newParent, newParent.Nodes.Count);
        }

        public void MoveTo(TreeNodeImpl newParent, int index)
        {
            if (newParent.Tag is IXmlClass && Tag is IXmlClass)
            {
                IXmlClass currentParentComponent = (IXmlClass)Parent.Tag;
                IXmlClass newParentComponent = (IXmlClass) newParent.Tag;
                // if the two items are part of the same compoenent, indexes will be off
                IXmlClass item = (IXmlClass)Tag;
                // remove self from current parent
                currentParentComponent.Children.Remove(item);
                // add self to new parent
                newParentComponent.Children.Insert(index, item);
                // remove the current node
                Remove();
                // insert to the parent node
                newParent.Nodes.Insert(index, this);
                this.EnsureVisible();
                TreeView.SelectedNode = this;
            }
        }

        public void MoveTo(int index)
        {
            if (Parent == null)
                throw new ApplicationException("Missing parent node");

            MoveTo((TreeNodeImpl) Parent, index);
        }
    }

	public class TreeNodeConfigFile : TreeNodeImpl
	{
		public TreeNodeConfigFile(ConfigFile p_Config)
		{
			base.Text = "Config File";
			base.ImageIndex = 0;
			base.SelectedImageIndex = 0;

			m_ConfigFile = p_Config;

			base.Tag = p_Config;
		}

		private ConfigFile m_ConfigFile;
		public ConfigFile ConfigFile
		{
			get{return m_ConfigFile;}
			set{m_ConfigFile = value;}
		}
	}

	public class TreeNodeConfiguration : TreeNodeImpl
	{
		public TreeNodeConfiguration(Configuration p_Config)
		{
			base.Text = p_Config.ToString();
			if (p_Config is WebConfiguration)
			{
				base.ImageIndex = 1;
				base.SelectedImageIndex = 1;
			}
            else if (p_Config is SetupConfiguration)
            {
                base.ImageIndex = 3;
                base.SelectedImageIndex = 3;
            }
            else
            {
                throw new ApplicationException("Invalid configuration");
            }

			m_Configuration = p_Config;
			base.Tag = p_Config;
			p_Config.LCIDChanged +=new EventHandler(p_Config_LCIDChanged);
		}

		private Configuration m_Configuration;
		public Configuration Configuration
		{
			get{return m_Configuration;}
			set{m_Configuration = value;}
		}

		private void p_Config_LCIDChanged(object sender, EventArgs e)
		{
			Text = Tag.ToString();
		}
	}

	public class TreeNodeDownloadDialog : TreeNodeImpl
	{
		public TreeNodeDownloadDialog(DownloadDialog p_Dialog)
		{
			base.Text = "Download Dialog";
			base.ImageIndex = 5;
			base.SelectedImageIndex = 5;
			m_DownloadDialog = p_Dialog;
			base.Tag = p_Dialog;
		}

		private DownloadDialog m_DownloadDialog;
		public DownloadDialog DownloadDialog
		{
			get{return m_DownloadDialog;}
			set{m_DownloadDialog = value;}
		}
	}

	public class TreeNodeDownload : TreeNodeImpl
	{
		public TreeNodeDownload(Download p_Download)
		{
			base.Text = p_Download.componentname;
			base.ImageIndex = 6;
			base.SelectedImageIndex = 6;
			m_Download = p_Download;
			base.Tag = p_Download;
			p_Download.ComponentNameChanged += new EventHandler(p_Download_ComponentNameChanged);
		}

		private Download m_Download;
		public Download Download
		{
			get{return m_Download;}
			set{m_Download = value;}
		}

		private void p_Download_ComponentNameChanged(object sender, EventArgs e)
		{
			Text = m_Download.componentname;
		}
	}

    public class TreeNodeEmbedFile : TreeNodeImpl
    {
        public TreeNodeEmbedFile(EmbedFile p_EmbedFile)
        {
            base.ImageIndex = 13;
            base.SelectedImageIndex = 13;
            m_EmbedFile = p_EmbedFile;
            base.Tag = p_EmbedFile;
            base.Text = p_EmbedFile.Name;
            p_EmbedFile.SourceFilePathChanged += new EventHandler(p_EmbedFile_SourceFilePathChanged);
        }

        void p_EmbedFile_SourceFilePathChanged(object sender, EventArgs e)
        {
            Text = m_EmbedFile.Name;
        }

        private EmbedFile m_EmbedFile;
        public EmbedFile EmbedFile
        {
            get { return m_EmbedFile; }
            set { m_EmbedFile = value; }
        }
    }

    public class TreeNodeEmbedFolder : TreeNodeImpl
    {
        public TreeNodeEmbedFolder(EmbedFolder p_EmbedFolder)
        {
            base.ImageIndex = 15;
            base.SelectedImageIndex = 15;
            m_EmbedFolder = p_EmbedFolder;
            base.Tag = p_EmbedFolder;
            base.Text = p_EmbedFolder.Name;
            p_EmbedFolder.SourceFilePathChanged += new EventHandler(p_EmbedFolder_SourceFolderPathChanged);
        }

        void p_EmbedFolder_SourceFolderPathChanged(object sender, EventArgs e)
        {
            Text = m_EmbedFolder.Name;
        }

        private EmbedFolder m_EmbedFolder;
        public EmbedFolder EmbedFolder
        {
            get { return m_EmbedFolder; }
            set { m_EmbedFolder = value; }
        }
    }

	public class TreeNodeComponent : TreeNodeImpl
	{
		public TreeNodeComponent(Component p_Component)
		{
			base.Text = p_Component.description;

			if (p_Component is ComponentMsi)
			{
				base.ImageIndex = 11;
				base.SelectedImageIndex = 11;
			}
			else if (p_Component is ComponentCmd)
			{
				base.ImageIndex = 4;
				base.SelectedImageIndex = 4;
			}
            else if (p_Component is ComponentOpenFile)
            {
                base.ImageIndex = 12;
                base.SelectedImageIndex = 12;
            }

			m_Component = p_Component;

			base.Tag = p_Component;

			p_Component.DescriptionChanged +=new EventHandler(p_Component_DescriptionChanged);
        }

		private Component m_Component;
		public Component Component
		{
			get{return m_Component;}
			set{m_Component = value;}
		}

		private void p_Component_DescriptionChanged(object sender, EventArgs e)
		{
			Text = m_Component.description;
		}
	}

	public class TreeNodeInstalledCheck : TreeNodeImpl
	{
        InstalledCheck m_InstalledCheck = null;

		public TreeNodeInstalledCheck(InstalledCheck p_InstalledCheck)
		{
            base.Tag = m_InstalledCheck = p_InstalledCheck;
            p_InstalledCheck.DescriptionChanged += new EventHandler(p_InstalledCheck_DescriptionChanged);
            p_InstalledCheck_DescriptionChanged(this, null);

			if (p_InstalledCheck is InstalledCheckFile)
			{
				base.ImageIndex = 9;
				base.SelectedImageIndex = 9;
			}
			else if (p_InstalledCheck is InstalledCheckRegistry)
			{
				base.ImageIndex = 10;
				base.SelectedImageIndex = 10;
			}
        }

        void p_InstalledCheck_DescriptionChanged(object sender, EventArgs e)
        {
            Text = string.Format("{0} ({1})", m_InstalledCheck.description, m_InstalledCheck.type);
        }
	}

    public class TreeNodeInstalledCheckOperator : TreeNodeImpl
    {
        InstalledCheckOperator m_InstalledCheckOperator = null;

        public TreeNodeInstalledCheckOperator(InstalledCheckOperator p_InstalledCheckOperator)
        {
            base.Tag = m_InstalledCheckOperator = p_InstalledCheckOperator;
            base.ImageIndex = 14;
            base.SelectedImageIndex = 14;
            p_InstalledCheckOperator.DescriptionChanged += new EventHandler(p_InstalledCheckOperator_DescriptionChanged);
            p_InstalledCheckOperator_DescriptionChanged(this, null);
        }

        void p_InstalledCheckOperator_DescriptionChanged(object sender, EventArgs e)
        {
            Text = string.Format("{0} ({1})", m_InstalledCheckOperator.description, m_InstalledCheckOperator.type);
        }
    }
}
