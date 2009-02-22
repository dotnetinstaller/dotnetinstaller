using System;
using System.Drawing;
using System.Collections;
using System.Windows.Forms;
using System.Data;
using InstallerLib;

namespace InstallerEditor
{
	/// <summary>
	/// Summary description for MainForm.
	/// </summary>
	public class MainForm : System.Windows.Forms.Form
	{
		private System.Windows.Forms.MainMenu mainMenu1;
		private System.Windows.Forms.MenuItem mnFile;
		private System.Windows.Forms.MenuItem mnNew;
		private System.Windows.Forms.MenuItem mnClose;
		private System.Windows.Forms.MenuItem mnSave;
		private System.Windows.Forms.MenuItem mnExit;
		private System.Windows.Forms.MenuItem mnOpen;
		private System.Windows.Forms.MenuItem menuItem1;
		private System.Windows.Forms.MenuItem menuItem2;
		private System.Windows.Forms.MenuItem mnCreateExe;
		private System.Windows.Forms.MenuItem menuItem4;
		private System.Windows.Forms.TreeView treeView;
		private System.Windows.Forms.PropertyGrid propertyGrid;
		private System.Windows.Forms.ImageList imageList;
		private System.Windows.Forms.ContextMenu contextMenuTreeView;
		private System.Windows.Forms.Splitter splitter1;
		private System.Windows.Forms.MenuItem mnAdd;
		private System.Windows.Forms.MenuItem mnAddSetupConfiguration;
		private System.Windows.Forms.MenuItem mnAddWebConfiguration;
		private System.Windows.Forms.MenuItem menuItem7;
		private System.Windows.Forms.MenuItem mnDelete;
		private System.Windows.Forms.MenuItem menuItem3;
		private System.Windows.Forms.MenuItem mnAddDownloadFile;
		private System.Windows.Forms.MenuItem mnView;
		private System.Windows.Forms.MenuItem mnRefresh;
		private System.Windows.Forms.MenuItem menuItem5;
		private System.Windows.Forms.MenuItem mnAddMsiComponent;
		private System.Windows.Forms.MenuItem mnAddCommandComponent;
		private System.Windows.Forms.MenuItem menuItem6;
		private System.Windows.Forms.MenuItem mnAddInstalledCheckRegistry;
		private System.Windows.Forms.MenuItem mnAddInstalledCheckFile;
		private System.Windows.Forms.MenuItem mnAddDownloadDialog;
		private System.Windows.Forms.MenuItem mnSaveAs;
		private System.Windows.Forms.MenuItem mnEditWithNotepad;
		private System.Windows.Forms.MenuItem mnTools;
		private System.Windows.Forms.MenuItem mnLanguageForNewItem;
		private System.Windows.Forms.MenuItem mnHelp;
		private System.Windows.Forms.MenuItem mnHomePage;
		private System.Windows.Forms.MenuItem mnAddOpenFileComponent;
		private System.Windows.Forms.MenuItem mnAddComponentWizard;
		private System.Windows.Forms.MenuItem mnHelpAbout;
		private System.Windows.Forms.MenuItem mnCustomizeTemplates;
		private System.Windows.Forms.MenuItem mnAddComponentWizard2;
        private MenuItem menuItem8;
        private MenuItem mnAddEmbedFile;
        private MenuItem mnAddInstalledCheckOperator;
		private System.ComponentModel.IContainer components;

		public MainForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.mainMenu1 = new System.Windows.Forms.MainMenu(this.components);
            this.mnFile = new System.Windows.Forms.MenuItem();
            this.mnNew = new System.Windows.Forms.MenuItem();
            this.mnOpen = new System.Windows.Forms.MenuItem();
            this.mnClose = new System.Windows.Forms.MenuItem();
            this.menuItem1 = new System.Windows.Forms.MenuItem();
            this.mnSave = new System.Windows.Forms.MenuItem();
            this.mnSaveAs = new System.Windows.Forms.MenuItem();
            this.menuItem2 = new System.Windows.Forms.MenuItem();
            this.mnEditWithNotepad = new System.Windows.Forms.MenuItem();
            this.mnCreateExe = new System.Windows.Forms.MenuItem();
            this.menuItem4 = new System.Windows.Forms.MenuItem();
            this.mnExit = new System.Windows.Forms.MenuItem();
            this.mnView = new System.Windows.Forms.MenuItem();
            this.mnRefresh = new System.Windows.Forms.MenuItem();
            this.mnTools = new System.Windows.Forms.MenuItem();
            this.mnLanguageForNewItem = new System.Windows.Forms.MenuItem();
            this.mnCustomizeTemplates = new System.Windows.Forms.MenuItem();
            this.mnHelp = new System.Windows.Forms.MenuItem();
            this.mnHomePage = new System.Windows.Forms.MenuItem();
            this.mnHelpAbout = new System.Windows.Forms.MenuItem();
            this.treeView = new System.Windows.Forms.TreeView();
            this.contextMenuTreeView = new System.Windows.Forms.ContextMenu();
            this.mnAdd = new System.Windows.Forms.MenuItem();
            this.mnAddSetupConfiguration = new System.Windows.Forms.MenuItem();
            this.mnAddWebConfiguration = new System.Windows.Forms.MenuItem();
            this.menuItem3 = new System.Windows.Forms.MenuItem();
            this.mnAddDownloadDialog = new System.Windows.Forms.MenuItem();
            this.mnAddDownloadFile = new System.Windows.Forms.MenuItem();
            this.menuItem5 = new System.Windows.Forms.MenuItem();
            this.mnAddComponentWizard2 = new System.Windows.Forms.MenuItem();
            this.mnAddComponentWizard = new System.Windows.Forms.MenuItem();
            this.mnAddMsiComponent = new System.Windows.Forms.MenuItem();
            this.mnAddCommandComponent = new System.Windows.Forms.MenuItem();
            this.mnAddOpenFileComponent = new System.Windows.Forms.MenuItem();
            this.menuItem6 = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckRegistry = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckFile = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckOperator = new System.Windows.Forms.MenuItem();
            this.menuItem8 = new System.Windows.Forms.MenuItem();
            this.mnAddEmbedFile = new System.Windows.Forms.MenuItem();
            this.menuItem7 = new System.Windows.Forms.MenuItem();
            this.mnDelete = new System.Windows.Forms.MenuItem();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.propertyGrid = new System.Windows.Forms.PropertyGrid();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.SuspendLayout();
            // 
            // mainMenu1
            // 
            this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnFile,
            this.mnView,
            this.mnTools,
            this.mnHelp});
            // 
            // mnFile
            // 
            this.mnFile.Index = 0;
            this.mnFile.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnNew,
            this.mnOpen,
            this.mnClose,
            this.menuItem1,
            this.mnSave,
            this.mnSaveAs,
            this.menuItem2,
            this.mnEditWithNotepad,
            this.mnCreateExe,
            this.menuItem4,
            this.mnExit});
            this.mnFile.Text = "File";
            // 
            // mnNew
            // 
            this.mnNew.Index = 0;
            this.mnNew.Text = "New...";
            this.mnNew.Click += new System.EventHandler(this.mnNew_Click);
            // 
            // mnOpen
            // 
            this.mnOpen.Index = 1;
            this.mnOpen.Text = "Open...";
            this.mnOpen.Click += new System.EventHandler(this.mnOpen_Click);
            // 
            // mnClose
            // 
            this.mnClose.Enabled = false;
            this.mnClose.Index = 2;
            this.mnClose.Text = "Close";
            this.mnClose.Click += new System.EventHandler(this.mnClose_Click);
            // 
            // menuItem1
            // 
            this.menuItem1.Index = 3;
            this.menuItem1.Text = "-";
            // 
            // mnSave
            // 
            this.mnSave.Enabled = false;
            this.mnSave.Index = 4;
            this.mnSave.Text = "Save";
            this.mnSave.Click += new System.EventHandler(this.mnSave_Click);
            // 
            // mnSaveAs
            // 
            this.mnSaveAs.Enabled = false;
            this.mnSaveAs.Index = 5;
            this.mnSaveAs.Text = "Save As...";
            this.mnSaveAs.Click += new System.EventHandler(this.mnSaveAs_Click);
            // 
            // menuItem2
            // 
            this.menuItem2.Index = 6;
            this.menuItem2.Text = "-";
            // 
            // mnEditWithNotepad
            // 
            this.mnEditWithNotepad.Enabled = false;
            this.mnEditWithNotepad.Index = 7;
            this.mnEditWithNotepad.Text = "Edit With Notepad";
            this.mnEditWithNotepad.Click += new System.EventHandler(this.mnEditWithNotepad_Click);
            // 
            // mnCreateExe
            // 
            this.mnCreateExe.Index = 8;
            this.mnCreateExe.Text = "Create Exe...";
            this.mnCreateExe.Click += new System.EventHandler(this.mnCreateExe_Click);
            // 
            // menuItem4
            // 
            this.menuItem4.Index = 9;
            this.menuItem4.Text = "-";
            // 
            // mnExit
            // 
            this.mnExit.Index = 10;
            this.mnExit.Text = "Exit";
            this.mnExit.Click += new System.EventHandler(this.mnExit_Click);
            // 
            // mnView
            // 
            this.mnView.Index = 1;
            this.mnView.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnRefresh});
            this.mnView.Text = "View";
            // 
            // mnRefresh
            // 
            this.mnRefresh.Index = 0;
            this.mnRefresh.Text = "Refresh";
            this.mnRefresh.Click += new System.EventHandler(this.mnRefresh_Click);
            // 
            // mnTools
            // 
            this.mnTools.Index = 2;
            this.mnTools.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnLanguageForNewItem,
            this.mnCustomizeTemplates});
            this.mnTools.Text = "Tools";
            // 
            // mnLanguageForNewItem
            // 
            this.mnLanguageForNewItem.Index = 0;
            this.mnLanguageForNewItem.Text = "Template For New Item";
            // 
            // mnCustomizeTemplates
            // 
            this.mnCustomizeTemplates.Index = 1;
            this.mnCustomizeTemplates.Text = "Customize Templates";
            this.mnCustomizeTemplates.Click += new System.EventHandler(this.mnCustomizeTemplates_Click);
            // 
            // mnHelp
            // 
            this.mnHelp.Index = 3;
            this.mnHelp.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnHomePage,
            this.mnHelpAbout});
            this.mnHelp.Text = "Help";
            // 
            // mnHomePage
            // 
            this.mnHomePage.Index = 0;
            this.mnHomePage.Text = "Home Page";
            this.mnHomePage.Click += new System.EventHandler(this.mnHomePage_Click);
            // 
            // mnHelpAbout
            // 
            this.mnHelpAbout.Index = 1;
            this.mnHelpAbout.Text = "About";
            this.mnHelpAbout.Click += new System.EventHandler(this.mnHelpAbout_Click);
            // 
            // treeView
            // 
            this.treeView.ContextMenu = this.contextMenuTreeView;
            this.treeView.Dock = System.Windows.Forms.DockStyle.Left;
            this.treeView.HideSelection = false;
            this.treeView.ImageIndex = 0;
            this.treeView.ImageList = this.imageList;
            this.treeView.Location = new System.Drawing.Point(0, 0);
            this.treeView.Name = "treeView";
            this.treeView.SelectedImageIndex = 0;
            this.treeView.Size = new System.Drawing.Size(176, 346);
            this.treeView.TabIndex = 0;
            this.treeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView_AfterSelect);
            this.treeView.MouseDown += new System.Windows.Forms.MouseEventHandler(this.treeView_MouseDown);
            this.treeView.KeyUp += new System.Windows.Forms.KeyEventHandler(this.treeView_KeyUp);
            // 
            // contextMenuTreeView
            // 
            this.contextMenuTreeView.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAdd,
            this.menuItem7,
            this.mnDelete});
            this.contextMenuTreeView.Popup += new EventHandler(contextMenuTreeView_Popup);
            // 
            // mnAdd
            // 
            this.mnAdd.Index = 0;
            this.mnAdd.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddSetupConfiguration,
            this.mnAddWebConfiguration,
            this.menuItem3,
            this.mnAddDownloadDialog,
            this.mnAddDownloadFile,
            this.menuItem5,
            this.mnAddComponentWizard2,
            this.mnAddComponentWizard,
            this.mnAddMsiComponent,
            this.mnAddCommandComponent,
            this.mnAddOpenFileComponent,
            this.menuItem6,
            this.mnAddInstalledCheckRegistry,
            this.mnAddInstalledCheckFile,
            this.mnAddInstalledCheckOperator,
            this.menuItem8,
            this.mnAddEmbedFile});
            this.mnAdd.Text = "Add";
            // 
            // mnAddSetupConfiguration
            // 
            this.mnAddSetupConfiguration.Index = 0;
            this.mnAddSetupConfiguration.Text = "Setup Configuration";
            this.mnAddSetupConfiguration.Click += new System.EventHandler(this.mnAddSetupConfiguration_Click);
            // 
            // mnAddWebConfiguration
            // 
            this.mnAddWebConfiguration.Index = 1;
            this.mnAddWebConfiguration.Text = "Web Configuration";
            this.mnAddWebConfiguration.Click += new System.EventHandler(this.mnAddWebConfiguration_Click);
            // 
            // menuItem3
            // 
            this.menuItem3.Index = 2;
            this.menuItem3.Text = "-";
            // 
            // mnAddDownloadDialog
            // 
            this.mnAddDownloadDialog.Index = 3;
            this.mnAddDownloadDialog.Text = "Download Dialog";
            this.mnAddDownloadDialog.Click += new System.EventHandler(this.mnAddDownloadDialog_Click);
            // 
            // mnAddDownloadFile
            // 
            this.mnAddDownloadFile.Index = 4;
            this.mnAddDownloadFile.Text = "Download File";
            this.mnAddDownloadFile.Click += new System.EventHandler(this.mnAddDownloadFile_Click);
            // 
            // menuItem5
            // 
            this.menuItem5.Index = 5;
            this.menuItem5.Text = "-";
            // 
            // mnAddComponentWizard2
            // 
            this.mnAddComponentWizard2.Index = 6;
            this.mnAddComponentWizard2.Text = "Component Wizard ...";
            this.mnAddComponentWizard2.Click += new System.EventHandler(this.mnAddComponentWizard2_Click);
            // 
            // mnAddComponentWizard
            // 
            this.mnAddComponentWizard.Index = 7;
            this.mnAddComponentWizard.Text = "Component Wizard ...";
            this.mnAddComponentWizard.Visible = false;
            this.mnAddComponentWizard.Click += new System.EventHandler(this.mnAddComponentWizard_Click);
            // 
            // mnAddMsiComponent
            // 
            this.mnAddMsiComponent.Index = 8;
            this.mnAddMsiComponent.Text = "Msi Component";
            this.mnAddMsiComponent.Click += new System.EventHandler(this.mnAddMsiComponent_Click);
            // 
            // mnAddCommandComponent
            // 
            this.mnAddCommandComponent.Index = 9;
            this.mnAddCommandComponent.Text = "Command Component";
            this.mnAddCommandComponent.Click += new System.EventHandler(this.mnAddCommandComponent_Click);
            // 
            // mnAddOpenFileComponent
            // 
            this.mnAddOpenFileComponent.Index = 10;
            this.mnAddOpenFileComponent.Text = "OpenFile Component";
            this.mnAddOpenFileComponent.Click += new System.EventHandler(this.mnAddOpenFileComponent_Click);
            // 
            // menuItem6
            // 
            this.menuItem6.Index = 11;
            this.menuItem6.Text = "-";
            // 
            // mnAddInstalledCheckRegistry
            // 
            this.mnAddInstalledCheckRegistry.Index = 12;
            this.mnAddInstalledCheckRegistry.Text = "Installed Check Registry";
            this.mnAddInstalledCheckRegistry.Click += new System.EventHandler(this.mnAddInstalledCheckRegistry_Click);
            // 
            // mnAddInstalledCheckFile
            // 
            this.mnAddInstalledCheckFile.Index = 13;
            this.mnAddInstalledCheckFile.Text = "Installed Check File";
            this.mnAddInstalledCheckFile.Click += new System.EventHandler(this.mnInstalledCheckFile_Click);
            // 
            // mnAddInstalledCheckOperator
            // 
            this.mnAddInstalledCheckOperator.Index = 14;
            this.mnAddInstalledCheckOperator.Text = "Installed Check &Operator";
            this.mnAddInstalledCheckOperator.Click += new System.EventHandler(this.mnAddInstalledCheckOperator_Click);
            // 
            // menuItem8
            // 
            this.menuItem8.Index = 15;
            this.menuItem8.Text = "-";
            // 
            // mnAddEmbedFile
            // 
            this.mnAddEmbedFile.Index = 16;
            this.mnAddEmbedFile.Text = "&Embed File";
            this.mnAddEmbedFile.Click += new System.EventHandler(this.mnAddEmbedFile_Click);
            // 
            // menuItem7
            // 
            this.menuItem7.Index = 1;
            this.menuItem7.Text = "-";
            // 
            // mnDelete
            // 
            this.mnDelete.Index = 2;
            this.mnDelete.Text = "Delete";
            this.mnDelete.Click += new System.EventHandler(this.mnDelete_Click);
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "");
            this.imageList.Images.SetKeyName(1, "");
            this.imageList.Images.SetKeyName(2, "");
            this.imageList.Images.SetKeyName(3, "");
            this.imageList.Images.SetKeyName(4, "");
            this.imageList.Images.SetKeyName(5, "");
            this.imageList.Images.SetKeyName(6, "");
            this.imageList.Images.SetKeyName(7, "");
            this.imageList.Images.SetKeyName(8, "");
            this.imageList.Images.SetKeyName(9, "");
            this.imageList.Images.SetKeyName(10, "");
            this.imageList.Images.SetKeyName(11, "");
            this.imageList.Images.SetKeyName(12, "");
            this.imageList.Images.SetKeyName(13, "");
            this.imageList.Images.SetKeyName(14, "");
            // 
            // propertyGrid
            // 
            this.propertyGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.propertyGrid.LineColor = System.Drawing.SystemColors.ScrollBar;
            this.propertyGrid.Location = new System.Drawing.Point(176, 0);
            this.propertyGrid.Name = "propertyGrid";
            this.propertyGrid.Size = new System.Drawing.Size(444, 346);
            this.propertyGrid.TabIndex = 2;
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(176, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 346);
            this.splitter1.TabIndex = 3;
            this.splitter1.TabStop = false;
            // 
            // MainForm
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(620, 346);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.propertyGrid);
            this.Controls.Add(this.treeView);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Menu = this.mainMenu1;
            this.Name = "MainForm";
            this.Text = "Installer Editor";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Closed += new System.EventHandler(this.MainForm_Closed);
            this.Closing += new System.ComponentModel.CancelEventHandler(this.MainForm_Closing);
            this.ResumeLayout(false);

		}

        void contextMenuTreeView_Popup(object sender, EventArgs e)
        {
            if (m_TreeNodeConfigFile != null)
            {
                mnAdd.Enabled = true;
                mnDelete.Enabled = (treeView.SelectedNode != null);
            }
            else
            {
                mnAdd.Enabled = false;
                mnDelete.Enabled = false;
            }
        }

        void treeView_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyValue)
            {
                // delete
                case 46:
                    if (mnDelete.Enabled) mnDelete_Click(sender, e);
                    break;
                // insert
                case 45:
                    contextMenuTreeView.Show(treeView, treeView.SelectedNode != null 
                        ? new Point(treeView.SelectedNode.Bounds.Location.X + 5, treeView.SelectedNode.Bounds.Location.Y + 5)
                        : new Point(0, 0));
                    break;
            }
        }

		#endregion

		private void mnExit_Click(object sender, System.EventArgs e)
		{
			Close();
		}

		private TreeNodeConfigFile m_TreeNodeConfigFile = null;


		private bool NewConfiguration()
		{
			try
			{
				CloseConfiguration();

				SaveFileDialog l_dg = new SaveFileDialog();
				l_dg.Filter = "Xml Files(*.xml)|*.xml|All Files(*.*)|*.*";
				l_dg.DefaultExt = "xml";
				if (l_dg.ShowDialog(this) == DialogResult.OK)
				{
					m_TreeNodeConfigFile = new TreeNodeConfigFile(new ConfigFile());
					m_TreeNodeConfigFile.ConfigFile.Create(l_dg.FileName);
					RefreshMenu();
				}
				else
					return false;

				LoadTreeView(m_TreeNodeConfigFile);

				return true;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
				return false;
			}
		}

		private bool OpenConfiguration()
		{
			try
			{
				CloseConfiguration();

				OpenFileDialog l_dg = new OpenFileDialog();
				l_dg.Filter = "Xml Files(*.xml)|*.xml|All Files(*.*)|*.*";
				l_dg.DefaultExt = "xml";
				if (l_dg.ShowDialog(this) == DialogResult.OK)
				{
					ConfigFile l_File = new ConfigFile();

					string l_CheckDescription;
					if (l_File.IsCurrentSchemaVersion(l_dg.FileName, out l_CheckDescription) == false)
					{
						if (MessageBox.Show(this, "Invalid file version :" + l_CheckDescription + " \r\n Configuration file must converted to the format used by this version of InstallerEditor. \r\n If you choose to convert this file you will lose some properties and some new properties will be added. \r\n Convert this file?", "Convert config file?", MessageBoxButtons.YesNo, MessageBoxIcon.Question)
							== DialogResult.No)
						{
							return false;
						}
					}

					l_File.Load(l_dg.FileName);

					m_TreeNodeConfigFile = new TreeNodeConfigFile(l_File);
				}
				else
					return false;

				RefreshMenu();
				LoadTreeView(m_TreeNodeConfigFile);

				return true;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
				return false;
			}
		}
		private bool CloseConfiguration()
		{
			try
			{
				if (m_TreeNodeConfigFile!=null)
				{
					DialogResult l_ret = MessageBox.Show(this, "Do you want to save your changes?","Setup Installer", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);
					if (l_ret == DialogResult.Yes)
					{
						if (SaveConfiguration()==false)
							return false;
					}
					else if (l_ret == DialogResult.Cancel)
					{
						return false;
					}
				}

				m_TreeNodeConfigFile = null;

				CloseTreeView();

                propertyGrid.SelectedObject = null;

				RefreshMenu();

				return true;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);

				return false;
			}
		}
		private bool SaveConfiguration()
		{
			try
			{
				if (m_TreeNodeConfigFile != null)
				{
					if (m_TreeNodeConfigFile.ConfigFile.FileName==null)
					{
						SaveFileDialog l_dg = new SaveFileDialog();
						l_dg.Filter = "Xml Files(*.xml)|*.xml|All Files(*.*)|*.*";
						l_dg.DefaultExt = "xml";
						if (l_dg.ShowDialog(this) == DialogResult.OK)
						{
							m_TreeNodeConfigFile.ConfigFile.SaveAs(l_dg.FileName);
						}
						else
							return false;
					}
					else
						m_TreeNodeConfigFile.ConfigFile.Save();
				}

				return true;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
				return false;
			}
		}

		private void RefreshMenu()
		{
			if (m_TreeNodeConfigFile != null)
			{
				mnClose.Enabled = true;
				//mnCreateExe.Enabled = true;
				mnNew.Enabled = false;
				mnOpen.Enabled = false;
				mnSave.Enabled = true;
				mnSaveAs.Enabled = true;
				mnEditWithNotepad.Enabled = true;
			}
			else
			{
				mnClose.Enabled = false;
				//mnCreateExe.Enabled = false;
				mnNew.Enabled = true;
				mnOpen.Enabled = true;
				mnSave.Enabled = false;
				mnSaveAs.Enabled = false;
				mnEditWithNotepad.Enabled = false;
			}

            if (m_TreeNodeConfigFile != null &&
                m_TreeNodeConfigFile.ConfigFile != null &&
                m_TreeNodeConfigFile.ConfigFile.FileName != null)
            {
                Text = "Installer Editor - " + m_TreeNodeConfigFile.ConfigFile.FileName;
            }
            else
            {
                Text = "Installer Editor";
            }
		}

		private void mnSave_Click(object sender, System.EventArgs e)
		{
			SaveConfiguration();
		}

		private void mnClose_Click(object sender, System.EventArgs e)
		{
			CloseConfiguration();
		}

		public ConfigFile ConfigFile
		{
			get{return m_TreeNodeConfigFile.ConfigFile;}
			set{m_TreeNodeConfigFile.ConfigFile = value;}
		}
		
		private void CloseTreeView()
		{
			treeView.Nodes.Clear();
		}

		private void LoadTreeView(TreeNodeConfigFile p_Configuration)
		{
			CloseTreeView();

			//configuration
			treeView.Nodes.Add(p_Configuration);
			

		}

		private void mnNew_Click(object sender, System.EventArgs e)
		{
			NewConfiguration();
		}

		private void mnOpen_Click(object sender, System.EventArgs e)
		{
			OpenConfiguration();
		}

		private void treeView_AfterSelect(object sender, System.Windows.Forms.TreeViewEventArgs e)
		{
			try
			{
				propertyGrid.SelectedObject = e.Node.Tag;

				RefreshNodeContextMenu();
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void RefreshNodeContextMenu()
		{
			if (treeView.SelectedNode != null)
			{
				mnAddDownloadFile.Enabled = false;
				mnAddSetupConfiguration.Enabled = false;
				mnAddWebConfiguration.Enabled = false;
				mnDelete.Enabled = false;
				mnAddCommandComponent.Enabled = false;
				mnAddMsiComponent.Enabled = false;
				mnAddInstalledCheckRegistry.Enabled = false;
				mnAddInstalledCheckFile.Enabled = false;
                mnAddInstalledCheckOperator.Enabled = false;
				mnAddDownloadDialog.Enabled = false;
				mnAddOpenFileComponent.Enabled = false;
				mnAddComponentWizard.Enabled = false;
				mnAddComponentWizard2.Enabled = false;
                mnAddEmbedFile.Enabled = false;

				if (treeView.SelectedNode.Tag is ConfigFile)
				{
					mnAddSetupConfiguration.Enabled = true;
					mnAddWebConfiguration.Enabled = true;
                }
				else if (treeView.SelectedNode.Tag is WebConfiguration)
				{
					mnDelete.Enabled = true;
				}
				else if (treeView.SelectedNode.Tag is SetupConfiguration)
				{
					mnDelete.Enabled = true;
					mnAddCommandComponent.Enabled = true;
					mnAddMsiComponent.Enabled = true;
					mnAddOpenFileComponent.Enabled = true;
					mnAddComponentWizard.Enabled = true;
					mnAddComponentWizard2.Enabled = true;
                    mnAddEmbedFile.Enabled = true;
                }
				else if (treeView.SelectedNode.Tag is DownloadDialog)
				{
					mnAddDownloadFile.Enabled = true;
					mnDelete.Enabled = true; //questo delete è valido solo nel caso in cui la classe downloaddialog non si trovi sotto un component
				}
				else if (treeView.SelectedNode.Tag is Download)
				{
					mnDelete.Enabled = true;
                    mnAddEmbedFile.Enabled = true;
                }
				else if (treeView.SelectedNode.Tag is Component)
				{
					mnAddInstalledCheckRegistry.Enabled = true;
					mnAddInstalledCheckFile.Enabled = true;
                    mnAddInstalledCheckOperator.Enabled = true;
					mnDelete.Enabled = true;
					mnAddDownloadDialog.Enabled = true;
                    mnAddEmbedFile.Enabled = true;
                }
                else if (treeView.SelectedNode.Tag is InstalledCheckOperator)
                {
                    mnAddInstalledCheckOperator.Enabled = true;
                    mnAddInstalledCheckRegistry.Enabled = true;
                    mnAddInstalledCheckFile.Enabled = true;
                    mnDelete.Enabled = true;
                }
                else if (treeView.SelectedNode.Tag is InstalledCheck)
                {
                    mnDelete.Enabled = true;
                }
                else if (treeView.SelectedNode.Tag is EmbedFile)
                {
                    mnDelete.Enabled = true;
                }
			}
		}

		private Configuration AddWebConfiguration()
		{
			WebConfiguration l_Config = new WebConfiguration();
			m_TreeNodeConfigFile.ConfigFile.Configurations.Add(l_Config);
			return l_Config;
		}

		private Configuration AddSetupConfiguration()
		{
			SetupConfiguration l_Config = new SetupConfiguration();
			m_TreeNodeConfigFile.ConfigFile.Configurations.Add(l_Config);
			return l_Config;
		}

		private Download AddDownload(DownloadDialog p_Dialog)
		{
			Download d = new Download();
			p_Dialog.Downloads.Add(d);
			return d;
		}

		private Component AddMsiComponent(SetupConfiguration p_Config)
		{
			ComponentMsi l_Component = new ComponentMsi();
			p_Config.Components.Add(l_Component);
			return l_Component;
		}

		private Component AddCmdComponent(SetupConfiguration p_Config)
		{
			ComponentCmd l_Component = new ComponentCmd();
			p_Config.Components.Add(l_Component);
			return l_Component;
		}

		private Component AddOpenFileComponent(SetupConfiguration p_Config)
		{
			ComponentOpenFile l_Component = new ComponentOpenFile();
			p_Config.Components.Add(l_Component);
			return l_Component;
		}

		private InstalledCheck AddInstalledCheckRegistry(Component p_Component)
		{
			InstalledCheckRegistry l_Check = new InstalledCheckRegistry();
			p_Component.installedchecks.Add(l_Check);
			return l_Check;
		}

		private InstalledCheck AddInstalledCheckFile(Component p_Component)
		{
			InstalledCheckFile l_Check = new InstalledCheckFile();
			p_Component.installedchecks.Add(l_Check);
			return l_Check;
		}

        private InstalledCheck AddInstalledCheckRegistry(InstalledCheckOperator p_InstalledCheckOperator)
        {
            InstalledCheckRegistry l_Check = new InstalledCheckRegistry();
            p_InstalledCheckOperator.installedchecks.Add(l_Check);
            return l_Check;
        }

        private InstalledCheck AddInstalledCheckFile(InstalledCheckOperator p_InstalledCheckOperator)
        {
            InstalledCheckFile l_Check = new InstalledCheckFile();
            p_InstalledCheckOperator.installedchecks.Add(l_Check);
            return l_Check;
        }

        private InstalledCheckOperator AddInstalledCheckOperator(Component p_Component)
        {
            InstalledCheckOperator l_Operator = new InstalledCheckOperator();
            p_Component.installedcheckoperators.Add(l_Operator);
            return l_Operator;
        }

        private InstalledCheckOperator AddInstalledCheckOperator(InstalledCheckOperator p_Operator)
        {
            InstalledCheckOperator l_Operator = new InstalledCheckOperator();
            p_Operator.installedcheckoperators.Add(l_Operator);
            return l_Operator;
        }

		private DownloadDialog AddDownloadDIalogToComponetnt(Component p_Component)
		{
			if (p_Component.DownloadDialog != null)
				throw new ApplicationException("There is already one download dialog for this component");
			DownloadDialog l_DownloadDialog = new DownloadDialog();
			p_Component.DownloadDialog = l_DownloadDialog;
			return l_DownloadDialog;
		}

        private EmbedFile AddEmbedFileSetupConfiguration(SetupConfiguration p_Config)
        {
            EmbedFile l_SetupConfigurationEmbedFile = new EmbedFile();
            p_Config.EmbedFiles.Add(l_SetupConfigurationEmbedFile);
            return l_SetupConfigurationEmbedFile;
        }

        private EmbedFile AddEmbedFileComponent(Component p_Component)
        {
            EmbedFile l_ComponentEmbedFile = new EmbedFile();
            p_Component.embedfiles.Add(l_ComponentEmbedFile);
            return l_ComponentEmbedFile;
        }

		private void mnAddSetupConfiguration_Click(object sender, System.EventArgs e)
		{
			try
			{
				m_TreeNodeConfigFile.Nodes.Add(new TreeNodeConfiguration(AddSetupConfiguration()));
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnAddWebConfiguration_Click(object sender, System.EventArgs e)
		{
			try
			{
				m_TreeNodeConfigFile.Nodes.Add(new TreeNodeConfiguration(AddWebConfiguration()));
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void MainForm_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			if (CloseConfiguration()==false)
				e.Cancel = true;
		}

		private void mnAddDownloadFile_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is DownloadDialog)
				{
					DownloadDialog d = (DownloadDialog)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeDownload( AddDownload(d) ));
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void DeleteConfiguration(Configuration p_Config, TreeNode p_CurrentNode)
		{
            if (p_CurrentNode.Parent.Tag is ConfigFile)
            {
                ConfigFile l_config = (ConfigFile)p_CurrentNode.Parent.Tag;
                l_config.Configurations.Remove(p_Config);
                p_CurrentNode.Remove();
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
		}

		private void DeleteDownload(Download p_Download, TreeNode p_CurrentNode)
		{
            if (p_CurrentNode.Parent.Tag is DownloadDialog)
            {
                DownloadDialog l_DownloadDialog = (DownloadDialog)p_CurrentNode.Parent.Tag;
                l_DownloadDialog.Downloads.Remove(p_Download);
                p_CurrentNode.Remove();
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
		}

		private void DeleteComponent(Component p_Component, TreeNode p_CurrentNode)
		{
			if (p_CurrentNode.Parent.Tag is SetupConfiguration)
			{
				SetupConfiguration l_SetupConfiguration = (SetupConfiguration)p_CurrentNode.Parent.Tag;
				l_SetupConfiguration.Components.Remove(p_Component);
				p_CurrentNode.Remove();
			}
			else
				throw new ApplicationException("Invalid node");
		}

		private void DeleteInstalledCheck(InstalledCheck p_Check, TreeNode p_CurrentNode)
		{
            if (p_CurrentNode.Parent.Tag is Component)
            {
                Component l_Component = (Component)p_CurrentNode.Parent.Tag;
                l_Component.installedchecks.Remove(p_Check);
                p_CurrentNode.Remove();
            }
            else if (p_CurrentNode.Parent.Tag is InstalledCheckOperator)
            {
                InstalledCheckOperator l_Operator = (InstalledCheckOperator)p_CurrentNode.Parent.Tag;
                l_Operator.installedchecks.Remove(p_Check);
                p_CurrentNode.Remove();
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
		}

        private void DeleteInstalledCheckOperator(InstalledCheckOperator p_Operator, TreeNode p_CurrentNode)
        {
            if (p_CurrentNode.Parent.Tag is Component)
            {
                Component l_Component = (Component)p_CurrentNode.Parent.Tag;
                l_Component.installedcheckoperators.Remove(p_Operator);
                p_CurrentNode.Remove();
            }
            else if (p_CurrentNode.Parent.Tag is InstalledCheckOperator)
            {
                InstalledCheckOperator l_Operator = (InstalledCheckOperator) p_CurrentNode.Parent.Tag;
                l_Operator.installedcheckoperators.Remove(p_Operator);
                p_CurrentNode.Remove();
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
        }

        private void DeleteEmbedFile(EmbedFile p_File, TreeNode p_CurrentNode)
        {
            if (p_CurrentNode.Parent.Tag is Component)
            {
                Component l_Component = (Component)p_CurrentNode.Parent.Tag;
                l_Component.embedfiles.Remove(p_File);
                p_CurrentNode.Remove();
            }
            else if (p_CurrentNode.Parent.Tag is SetupConfiguration)
            {
                SetupConfiguration l_Configuration = (SetupConfiguration)p_CurrentNode.Parent.Tag;
                l_Configuration.EmbedFiles.Remove(p_File);
                p_CurrentNode.Remove();
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
        }

		private void DeleteDownloadDialogFromComp(DownloadDialog p_DownloadDlg, TreeNode p_CurrentNode)
		{
			if (p_CurrentNode.Parent.Tag is Component)
			{
				Component l_Component = (Component)p_CurrentNode.Parent.Tag;
				if (l_Component.DownloadDialog != p_DownloadDlg)
					throw new ApplicationException("Invalid download dialog");
				l_Component.DownloadDialog = null;
				p_CurrentNode.Remove();
			}
            else if (p_CurrentNode.Parent.Tag is WebConfiguration)
            {
                throw new ApplicationException("This element cannot be deleted");
            }
            else
            {
                throw new ApplicationException("Invalid node");
            }
		}

		private void mnDelete_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null)
				{
					if (treeView.SelectedNode.Tag is Configuration)
					{
						DeleteConfiguration((Configuration)treeView.SelectedNode.Tag, treeView.SelectedNode);
					}
					else if (treeView.SelectedNode.Tag is Download)
					{
						DeleteDownload((Download)treeView.SelectedNode.Tag, treeView.SelectedNode);
					}
					else if (treeView.SelectedNode.Tag is Component)
					{
						DeleteComponent((Component)treeView.SelectedNode.Tag, treeView.SelectedNode);
					}		
					else if (treeView.SelectedNode.Tag is InstalledCheck)
					{
						DeleteInstalledCheck((InstalledCheck)treeView.SelectedNode.Tag, treeView.SelectedNode);
					}
					else if (treeView.SelectedNode.Tag is DownloadDialog)
					{
						DeleteDownloadDialogFromComp((DownloadDialog) treeView.SelectedNode.Tag, treeView.SelectedNode);
					}
                    else if (treeView.SelectedNode.Tag is InstalledCheckOperator)
                    {
                        DeleteInstalledCheckOperator((InstalledCheckOperator)treeView.SelectedNode.Tag, treeView.SelectedNode);
                    }
                    else if (treeView.SelectedNode.Tag is EmbedFile)
                    {
                        DeleteEmbedFile((EmbedFile)treeView.SelectedNode.Tag, treeView.SelectedNode);
                    }
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnRefresh_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (m_TreeNodeConfigFile!=null && m_TreeNodeConfigFile.ConfigFile != null )
				{
					m_TreeNodeConfigFile = new TreeNodeConfigFile(m_TreeNodeConfigFile.ConfigFile);
					LoadTreeView(m_TreeNodeConfigFile);
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnAddMsiComponent_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
				{
					SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeComponent( AddMsiComponent(l_Setup) ));
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnAddCommandComponent_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
				{
					SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeComponent( AddCmdComponent(l_Setup) ));
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnAddInstalledCheckRegistry_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is Component)
				{
					Component l_Component = (Component)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheck( AddInstalledCheckRegistry(l_Component) ));
				}
                else if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is InstalledCheckOperator)
                {
                    InstalledCheckOperator l_Operator = (InstalledCheckOperator)treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheck(AddInstalledCheckRegistry(l_Operator)));
                }
            }
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnInstalledCheckFile_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is Component)
				{
					Component l_Component = (Component)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheck( AddInstalledCheckFile(l_Component) ));
				}
                else if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is InstalledCheckOperator)
                {
                    InstalledCheckOperator l_Operator = (InstalledCheckOperator) treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheck(AddInstalledCheckFile(l_Operator)));
                }
            }
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnAddDownloadDialog_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is Component)
				{
					Component l_Component = (Component)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeDownloadDialog( AddDownloadDIalogToComponetnt(l_Component) ));
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void treeView_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			try
			{
				TreeNode l_Node = treeView.GetNodeAt(e.X, e.Y);
				if (l_Node != null)
					treeView.SelectedNode = l_Node;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnSaveAs_Click(object sender, System.EventArgs e)
		{
			if (m_TreeNodeConfigFile != null && m_TreeNodeConfigFile.ConfigFile != null)
			{
				m_TreeNodeConfigFile.ConfigFile.FileName = null;
				SaveConfiguration();
			}
		}

		private void mnEditWithNotepad_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (m_TreeNodeConfigFile.ConfigFile.FileName!=null)
				{
					System.Diagnostics.ProcessStartInfo p = new System.Diagnostics.ProcessStartInfo("NOTEPAD.EXE", "\"" + m_TreeNodeConfigFile.ConfigFile.FileName + "\"");
					p.UseShellExecute = false;
					System.Diagnostics.Process process = new System.Diagnostics.Process();
					process.StartInfo = p;
					process.Start();
					//SourceLibrary.Utility.Shell.ExecCommand("NOTEPAD.EXE \"" + m_TreeNodeConfigFile.ConfigFile.FileName + "\"");
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnHomePage_Click(object sender, System.EventArgs e)
		{
			try
			{
				SourceLibrary.Utility.Shell.ExecCommand("http://www.devage.com");
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

//		private void mnLanguageEnglish_Click(object sender, System.EventArgs e)
//		{
//			mnLanguageEnglish.Checked = true;
//			mnLanguageItalian.Checked = false;
//			LanguageUI.Language = SupportedLanguage.English;
//		}
//
//		private void mnLanguageItalian_Click(object sender, System.EventArgs e)
//		{
//			mnLanguageItalian.Checked = true;
//			mnLanguageEnglish.Checked = false;
//			LanguageUI.Language = SupportedLanguage.Italian;
//		}

		private AppSetting m_AppSetting;
		private void MainForm_Load(object sender, System.EventArgs e)
		{
			m_AppSetting = new AppSetting();
			m_AppSetting.Load();

			try
			{
				RefreshTemplateFilesMenu();

				if (m_AppSetting.TemplateConfigFile != null &&
					m_AppSetting.TemplateConfigFile.Length > 0)
				{
					System.IO.FileInfo fl = new System.IO.FileInfo(m_AppSetting.TemplateConfigFile);
					using (System.IO.Stream st = fl.OpenRead())
					{
						Template.CurrentTemplate = new Template(st, fl.Name);
					}
				}
			}
			catch(Exception err)
			{
				SourceLibrary.Windows.Forms.ErrorDialog.Show(err, "Error");
			}
		}

		private void MainForm_Closed(object sender, System.EventArgs e)
		{
			m_AppSetting.Save();
		}

		private void mnCreateExe_Click(object sender, System.EventArgs e)
		{
			try
			{
				MakeExe l_frmMakeExe = new MakeExe();
				l_frmMakeExe.TemplateFile = m_AppSetting.TemplateInstallerFile;
				l_frmMakeExe.BannerBitmapFile = m_AppSetting.BannerBitmapFile;
                l_frmMakeExe.IconFile = m_AppSetting.IconFile;
				l_frmMakeExe.OutputFileName = m_AppSetting.OutputMakeFile;
				if (m_TreeNodeConfigFile!=null && m_TreeNodeConfigFile.ConfigFile!=null)
					l_frmMakeExe.Configuration = m_TreeNodeConfigFile.ConfigFile.FileName;

				l_frmMakeExe.ShowDialog(this);

				m_AppSetting.TemplateInstallerFile = l_frmMakeExe.TemplateFile;
				m_AppSetting.BannerBitmapFile = l_frmMakeExe.BannerBitmapFile;
                m_AppSetting.IconFile = l_frmMakeExe.IconFile;
				m_AppSetting.OutputMakeFile = l_frmMakeExe.OutputFileName;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		private void mnAddOpenFileComponent_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
				{
					SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
					treeView.SelectedNode.Nodes.Add(new TreeNodeComponent( AddOpenFileComponent(l_Setup) ));
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnAddComponentWizard_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
				{
					SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
					
					ComponentWizard l_frmWizard = new ComponentWizard();

					if (l_frmWizard.ShowDialog(this) == DialogResult.OK)
					{
						foreach (Component c in l_frmWizard.SelectedComponents)
						{
							treeView.SelectedNode.Nodes.Add(new TreeNodeComponent(c));
							l_Setup.Components.Add(c);
						}
					}
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}		
		}

		private void mnHelpAbout_Click(object sender, System.EventArgs e)
		{
			About a = new About();
			a.ShowDialog(this);
		}

		private void mnCustomizeTemplates_Click(object sender, System.EventArgs e)
		{
			TemplatesEditor editors = new TemplatesEditor();
			editors.AvailableTemplateFiles = m_AppSetting.AvailableTemplates;
			if (editors.ShowDialog(this) == DialogResult.OK)
			{
				RefreshTemplateFilesMenu();
			}
		}

		private void RefreshTemplateFilesMenu()
		{
			mnLanguageForNewItem.MenuItems.Clear();

			MenuItem defTemplate = new MenuItem("Default (English)");
			defTemplate.Click += new EventHandler(defTemplate_Click);
			defTemplate.RadioCheck = true;

			mnLanguageForNewItem.MenuItems.Add(defTemplate);

			//mnLanguageForNewItem.MenuItems.Add(new MenuItem("-"));

			bool foundTemplate = false;
			for (int i = 0; i < m_AppSetting.AvailableTemplates.Count; i++)
			{
				try
				{
					MenuItemTemplateFile tmpMenu = new MenuItemTemplateFile(m_AppSetting, m_AppSetting.AvailableTemplates[i]);
					mnLanguageForNewItem.MenuItems.Add(tmpMenu);

					if (m_AppSetting.AvailableTemplates[i] == m_AppSetting.TemplateConfigFile)
					{
						tmpMenu.Checked = true;
						foundTemplate = true;
					}
				}
				catch(Exception err)
				{
					SourceLibrary.Windows.Forms.ErrorDialog.Show(this, err, "Error");
				}
			}

			if (foundTemplate == false)
			{
				defTemplate.PerformClick();
			}
		}

		private void defTemplate_Click(object sender, EventArgs e)
		{
			m_AppSetting.TemplateConfigFile = null;
			((MenuItem)sender).Checked = true;

			foreach (System.Windows.Forms.MenuItem mn in ((MenuItem)sender).Parent.MenuItems)
				if (mn != sender)
					mn.Checked = false;
		}

		private void mnAddComponentWizard2_Click(object sender, System.EventArgs e)
		{
			try
			{
				if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
				{
					SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
					
					ComponentWizard2 l_frmWizard = new ComponentWizard2();

					if (l_frmWizard.ShowDialog(this) == DialogResult.OK)
					{
						foreach (Component c in l_frmWizard.SelectedComponents)
						{
							treeView.SelectedNode.Nodes.Add(new TreeNodeComponent(c));
							l_Setup.Components.Add(c);
						}
					}
				}
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

        private void mnAddEmbedFile_Click(object sender, EventArgs e)
        {
            try
            {
                if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is SetupConfiguration)
                {
                    SetupConfiguration l_Setup = (SetupConfiguration)treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeEmbedFile(AddEmbedFileSetupConfiguration(l_Setup)));
                }
                else if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is Component)
                {
                    Component l_Component = (Component)treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeEmbedFile(AddEmbedFileComponent(l_Component)));
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void AddInstalledCheckOperator(object sender, EventArgs e)
        {
            try
            {
                if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is Component)
                {
                    Component l_Component = (Component)treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheckOperator(
                        AddInstalledCheckOperator(l_Component)));
                }
                else if (treeView.SelectedNode != null && treeView.SelectedNode.Tag is InstalledCheckOperator)
                {
                    InstalledCheckOperator l_InstalledCheckOperator = (InstalledCheckOperator)treeView.SelectedNode.Tag;
                    treeView.SelectedNode.Nodes.Add(new TreeNodeInstalledCheckOperator(
                        AddInstalledCheckOperator(l_InstalledCheckOperator)));
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnAddInstalledCheckOperator_Click(object sender, EventArgs e)
        {
            AddInstalledCheckOperator(sender, e);
        }
	}
}
