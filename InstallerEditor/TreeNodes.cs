using System;
using System.Windows.Forms;
using InstallerLib;

namespace InstallerEditor
{
    #region TreeNodeImpl

    public abstract class XmlTreeNodeImpl : TreeNode
    {
        public XmlTreeNodeImpl()
        {

        }

        protected abstract string XmlNodeText { get; }

        public XmlClass XmlInstance
        {
            get
            {
                return (XmlClass)this.Tag;
            }
            set
            {
                this.Tag = value;
                Text = XmlNodeText;
            }
        }

        public void CreateChildNodes()
        {
            foreach (XmlClass child in XmlInstance.Children)
            {
                XmlTreeNodeImpl childnode = CreateNode(child);
                Nodes.Add(childnode);
                childnode.CreateChildNodes();
            }
        }

        public void MoveTo(XmlTreeNodeImpl newParent)
        {
            MoveTo(newParent, newParent.Nodes.Count);
        }

        public void MoveTo(XmlTreeNodeImpl newParent, int index)
        {
            if (Parent != null && newParent.Tag is XmlClass && Tag is XmlClass)
            {
                XmlClass currentParentComponent = (XmlClass)Parent.Tag;
                XmlClass newParentComponent = newParent.XmlInstance;
                // if the two items are part of the same compoenent, indexes will be off
                XmlClass item = (XmlClass)Tag;
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

            MoveTo((XmlTreeNodeImpl)Parent, index);
        }

        public static XmlTreeNodeImpl CreateNode(XmlClass item)
        {
            XmlTreeNodeImpl node = null;
            if (item is ConfigFile) node = new TreeNodeConfigFile(item as ConfigFile);
            else if (item is SetupConfiguration) node = new TreeNodeSetupConfguration(item as SetupConfiguration);
            else if (item is WebConfiguration) node = new TreeNodeWebConfguration(item as WebConfiguration);
            else if (item is DownloadDialog) node = new TreeNodeDownloadDialog(item as DownloadDialog);
            else if (item is Download) node = new TreeNodeDownload(item as Download);
            else if (item is EmbedFile) node = new TreeNodeEmbedFile(item as EmbedFile);
            else if (item is EmbedFolder) node = new TreeNodeEmbedFolder(item as EmbedFolder);
            else if (item is ComponentCmd) node = new TreeNodeComponentCmd(item as ComponentCmd);
            else if (item is ComponentMsi) node = new TreeNodeComponentMsi(item as ComponentMsi);
            else if (item is ComponentMsu) node = new TreeNodeComponentMsu(item as ComponentMsu);
            else if (item is ComponentMsp) node = new TreeNodeComponentMsp(item as ComponentMsp);
            else if (item is ComponentOpenFile) node = new TreeNodeComponentOpenFile(item as ComponentOpenFile);
            else if (item is InstalledCheckFile) node = new TreeNodenstalledCheckFile(item as InstalledCheckFile);
            else if (item is InstalledCheckDirectory) node = new TreeNodenstalledCheckDirectory(item as InstalledCheckDirectory);
            else if (item is InstalledCheckRegistry) node = new TreeNodenstalledCheckRegistry(item as InstalledCheckRegistry);
            else if (item is InstalledCheckOperator) node = new TreeNodeInstalledCheckOperator(item as InstalledCheckOperator);
            else if (item is InstalledCheckProduct) node = new TreeNodeInstalledCheckProduct(item as InstalledCheckProduct);
            else if (item is ControlCheckBox) node = new TreeNodeControlCheckbox(item as ControlCheckBox);
            else if (item is ControlLabel) node = new TreeNodeControlLabel(item as ControlLabel);
            else if (item is ControlEdit) node = new TreeNodeControlEdit(item as ControlEdit);
            else if (item is ControlBrowse) node = new TreeNodeControlBrowse(item as ControlBrowse);
            else if (item is ControlLicense) node = new TreeNodeControlLicense(item as ControlLicense);
            else if (item is ControlHyperlink) node = new TreeNodeControlHyperlink(item as ControlHyperlink);
            else
                throw new Exception(string.Format("Unsupported type: {0}", item.GetType().Name));

            return node;
        }

        public static string Cut(string text)
        {
            const int textCutOff = 15;
            return text.Length > textCutOff
                ? string.Format("{0} ...", text.Substring(0, textCutOff))
                : text;
        }
    }

    public abstract class TreeNodeImpl<T> : XmlTreeNodeImpl
        where T : XmlClass
    {
        public TreeNodeImpl(T value)
        {
            Instance = value;
        }

        public virtual T Instance
        {
            get
            {
                return (T)XmlInstance;
            }
            set
            {
                XmlInstance = value;
            }
        }
    }

    #endregion

    #region ConfigFile

    public class TreeNodeConfigFile : TreeNodeImpl<ConfigFile>
    {
        private bool m_dirty = false;

        public TreeNodeConfigFile(ConfigFile value)
            : base(value)
        {
            ImageIndex = 0;
            SelectedImageIndex = 0;
        }

        protected override string XmlNodeText
        {
            get
            {
                return "Config File";
            }
        }

        public bool IsDirty
        {
            get { return m_dirty; }
            set { m_dirty = value; }
        }
    }

    #endregion

    #region Configuration

    public class TreeNodeConfiguration<T> : TreeNodeImpl<T>
        where T : Configuration
    {
        public TreeNodeConfiguration(T value)
            : base(value)
        {
        }

        public override T Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                Text = value.ToString();
                value.LCIDChanged += new EventHandler(OnLCIDChanged);
                base.Instance = value;
            }
        }

        private void OnLCIDChanged(object sender, EventArgs e)
        {
            Text = Instance.ToString();
        }

        protected override string XmlNodeText
        {
            get
            {
                return Instance.ToString();
            }
        }
    }

    public class TreeNodeWebConfguration : TreeNodeConfiguration<WebConfiguration>
    {
        public TreeNodeWebConfguration(WebConfiguration value)
            : base(value)
        {
            ImageIndex = 1;
            SelectedImageIndex = 1;
        }
    }

    public class TreeNodeSetupConfguration : TreeNodeConfiguration<SetupConfiguration>
    {
        public TreeNodeSetupConfguration(SetupConfiguration value)
            : base(value)
        {
            ImageIndex = 3;
            SelectedImageIndex = 3;
        }
    }

    #endregion

    #region Download

    public class TreeNodeDownloadDialog : TreeNodeImpl<DownloadDialog>
    {
        public TreeNodeDownloadDialog(DownloadDialog value)
            : base(value)
        {
            ImageIndex = 5;
            SelectedImageIndex = 5;
        }

        protected override string XmlNodeText
        {
            get
            {
                return "Download Dialog";
            }
        }
    }

    public class TreeNodeDownload : TreeNodeImpl<Download>
    {
        public TreeNodeDownload(Download value)
            : base(value)
        {
            ImageIndex = 6;
            SelectedImageIndex = 6;
        }

        public override Download Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                value.ComponentNameChanged += new EventHandler(OnComponentNameChanged);
                base.Instance = value;
            }
        }

        protected override string XmlNodeText
        {
            get
            {
                return Instance.componentname;
            }
        }

        private void OnComponentNameChanged(object sender, EventArgs e)
        {
            Text = Instance.componentname;
        }
    }

    #endregion

    #region Embed

    public class TreeNodeEmbedFile : TreeNodeImpl<EmbedFile>
    {
        public TreeNodeEmbedFile(EmbedFile value)
            : base(value)
        {
            ImageIndex = 13;
            SelectedImageIndex = 13;
        }

        public override EmbedFile Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                value.SourceFilePathChanged += new EventHandler(OnSourceFilePathChanged);
                base.Instance = value;
            }
        }

        protected override string XmlNodeText
        {
            get
            {
                return Instance.Name;
            }
        }

        private void OnSourceFilePathChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }
    }

    public class TreeNodeEmbedFolder : TreeNodeImpl<EmbedFolder>
    {
        public TreeNodeEmbedFolder(EmbedFolder value)
            : base(value)
        {
            ImageIndex = 15;
            SelectedImageIndex = 15;
        }

        public override EmbedFolder Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                Text = value.Name;
                value.SourceFilePathChanged += new EventHandler(OnSourceFolderPathChanged);
                base.Instance = value;
            }
        }

        void OnSourceFolderPathChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Instance.Name;
            }
        }
    }

    #endregion

    #region Component

    public class TreeNodeComponent<T> : TreeNodeImpl<T>
        where T : Component
    {
        public TreeNodeComponent(T value)
            : base(value)
        {

        }

        public override T Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                value.IdChanged += new EventHandler(OnIdChanged);
                base.Instance = value;
            }
        }

        protected override string XmlNodeText
        {
            get
            {
                return Instance.id != Instance.display_name
                    ? string.Format("{0} ({1})", Instance.display_name, Instance.id)
                    : Instance.id;
            }
        }

        private void OnIdChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }
    }

    public class TreeNodeComponentMsi : TreeNodeComponent<ComponentMsi>
    {
        public TreeNodeComponentMsi(ComponentMsi value)
            : base(value)
        {
            ImageIndex = 11;
            SelectedImageIndex = 11;
        }
    }

    public class TreeNodeComponentCmd : TreeNodeComponent<ComponentCmd>
    {
        public TreeNodeComponentCmd(ComponentCmd value)
            : base(value)
        {
            ImageIndex = 4;
            SelectedImageIndex = 4;
        }
    }

    public class TreeNodeComponentOpenFile : TreeNodeComponent<ComponentOpenFile>
    {
        public TreeNodeComponentOpenFile(ComponentOpenFile value)
            : base(value)
        {
            ImageIndex = 12;
            SelectedImageIndex = 12;
        }
    }

    public class TreeNodeComponentMsu : TreeNodeComponent<ComponentMsu>
    {
        public TreeNodeComponentMsu(ComponentMsu value)
            : base(value)
        {
            ImageIndex = 16;
            SelectedImageIndex = 16;
        }
    }

    public class TreeNodeComponentMsp : TreeNodeComponent<ComponentMsp>
    {
        public TreeNodeComponentMsp(ComponentMsp value)
            : base(value)
        {
            ImageIndex = 24;
            SelectedImageIndex = 24;
        }
    }

    #endregion

    #region Check

    public abstract class TreeNodeInstalledCheck<T> : TreeNodeImpl<T>
        where T : InstalledCheck
    {
        public TreeNodeInstalledCheck(T value)
            : base(value)
        {
        }

        public override T Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.DescriptionChanged += new EventHandler(OnDescriptionChanged);
                OnDescriptionChanged(this, null);
            }
        }

        protected override string XmlNodeText
        {
            get
            {
                return string.Format("{0} ({1})", Instance.description, Instance.type);
            }
        }

        private void OnDescriptionChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }
    }

    public class TreeNodenstalledCheckFile : TreeNodeInstalledCheck<InstalledCheckFile>
    {
        public TreeNodenstalledCheckFile(InstalledCheckFile value)
            : base(value)
        {
            ImageIndex = 9;
            SelectedImageIndex = 9;
        }
    }

    public class TreeNodeInstalledCheckProduct : TreeNodeInstalledCheck<InstalledCheckProduct>
    {
        public TreeNodeInstalledCheckProduct(InstalledCheckProduct value)
            : base(value)
        {
            ImageIndex = 11;
            SelectedImageIndex = 11;
        }
    }

    public class TreeNodenstalledCheckDirectory : TreeNodeInstalledCheck<InstalledCheckDirectory>
    {
        public TreeNodenstalledCheckDirectory(InstalledCheckDirectory value)
            : base(value)
        {
            ImageIndex = 17;
            SelectedImageIndex = 17;
        }
    }

    public class TreeNodenstalledCheckRegistry : TreeNodeInstalledCheck<InstalledCheckRegistry>
    {
        public TreeNodenstalledCheckRegistry(InstalledCheckRegistry value)
            : base(value)
        {
            ImageIndex = 10;
            SelectedImageIndex = 10;
        }
    }

    #endregion

    #region InstalledCheck Operator

    public class TreeNodeInstalledCheckOperator : TreeNodeImpl<InstalledCheckOperator>
    {
        public TreeNodeInstalledCheckOperator(InstalledCheckOperator value)
            : base(value)
        {
            ImageIndex = 14;
            SelectedImageIndex = 14;
        }

        public override InstalledCheckOperator Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.DescriptionChanged += new EventHandler(OnDescriptionChanged);
                OnDescriptionChanged(this, null);
            }
        }
        void OnDescriptionChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return string.Format("{0} ({1})", Instance.description, Instance.type);
            }
        }
    }

    #endregion

    #region Control

    public abstract class TreeNodeControl<T> : TreeNodeImpl<T>
        where T : InstallerLib.Control
    {
        public TreeNodeControl(T value)
            : base(value)
        {
        }

        public override T Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                Text = value.ToString();
                base.Instance = value;
            }
        }
    }

    public class TreeNodeControlLabel : TreeNodeControl<ControlLabel>
    {
        public TreeNodeControlLabel(ControlLabel value)
            : base(value)
        {
            ImageIndex = 18;
            SelectedImageIndex = 18;
        }

        public override ControlLabel Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    public class TreeNodeControlEdit : TreeNodeControl<ControlEdit>
    {
        public TreeNodeControlEdit(ControlEdit value)
            : base(value)
        {
            ImageIndex = 19;
            SelectedImageIndex = 19;
        }

        public override ControlEdit Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    public class TreeNodeControlBrowse : TreeNodeControl<ControlBrowse>
    {
        public TreeNodeControlBrowse(ControlBrowse value)
            : base(value)
        {
            ImageIndex = 21;
            SelectedImageIndex = 21;
        }

        public override ControlBrowse Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    public class TreeNodeControlCheckbox : TreeNodeControl<ControlCheckBox>
    {
        public TreeNodeControlCheckbox(ControlCheckBox value)
            : base(value)
        {
            ImageIndex = 20;
            SelectedImageIndex = 20;
        }

        public override ControlCheckBox Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    public class TreeNodeControlLicense : TreeNodeControl<ControlLicense>
    {
        public TreeNodeControlLicense(ControlLicense value)
            : base(value)
        {
            ImageIndex = 22;
            SelectedImageIndex = 22;
        }

        public override ControlLicense Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    public class TreeNodeControlHyperlink : TreeNodeControl<ControlHyperlink>
    {
        public TreeNodeControlHyperlink(ControlHyperlink value)
            : base(value)
        {
            ImageIndex = 23;
            SelectedImageIndex = 23;
        }

        public override ControlHyperlink Instance
        {
            get
            {
                return base.Instance;
            }
            set
            {
                base.Instance = value;
                value.OnTextChanged += new EventHandler(OnTextChanged);
            }
        }

        private void OnTextChanged(object sender, EventArgs e)
        {
            Text = XmlNodeText;
        }

        protected override string XmlNodeText
        {
            get
            {
                return Cut(Instance.Text);
            }
        }
    }

    #endregion
}
