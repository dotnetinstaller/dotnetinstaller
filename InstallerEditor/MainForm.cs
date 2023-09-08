using System;
using System.Drawing;
using System.Collections.Generic;
using System.Windows.Forms;
using InstallerLib;
using System.IO;
using SourceLibrary.Windows.Forms;
using Microsoft.Win32;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for MainForm.
    /// </summary>
    public class MainForm : System.Windows.Forms.Form, IMRUClient
    {
        private System.Windows.Forms.MainMenu mainMenu;
        private MenuItem mnFile;
        private MenuItem mnNew;
        private MenuItem mnClose;
        private MenuItem mnSave;
        private MenuItem mnExit;
        private MenuItem mnOpen;
        private MenuItem menuItem1;
        private MenuItem menuItem2;
        private MenuItem mnCreateExe;
        private MenuItem menuItem4;
        private System.Windows.Forms.TreeView configurationTree;
        private System.Windows.Forms.PropertyGrid propertyGrid;
        private System.Windows.Forms.ImageList imageList;
        private System.Windows.Forms.ContextMenu contextMenuTreeView;
        private System.Windows.Forms.Splitter splitter1;
        private MenuItem mnAdd;
        private MenuItem mnAddSetupConfiguration;
        private MenuItem mnAddWebConfiguration;
        private MenuItem menuSep2;
        private MenuItem mnDelete;
        private MenuItem mnAddDownloadFile;
        private MenuItem mnView;
        private MenuItem mnRefresh;
        private MenuItem mnAddMsiComponent;
        private MenuItem mnAddMspComponent;
        private MenuItem mnAddCommandComponent;
        private MenuItem mnAddInstalledCheckRegistry;
        private MenuItem mnAddInstalledCheckFile;
        private MenuItem mnAddDownloadDialog;
        private MenuItem mnSaveAs;
        private MenuItem mnEditWithNotepad;
        private MenuItem mnTools;
        private MenuItem mnTemplates;
        private MenuItem mnHelp;
        private MenuItem mnHomePage;
        private MenuItem mnAddOpenFileComponent;
        private MenuItem mnHelpAbout;
        private MenuItem mnCustomizeTemplates;
        private MenuItem mnAddComponentWizard2;
        private MenuItem mnAddInstalledCheckProduct;
        private MenuItem mnAddEmbedFile;
        private MenuItem mnAddInstalledCheckOperator;
        private SplitContainer mainSplitContainer;
        private TextBox txtComment;
        private MenuItem mnMove;
        private MenuItem mnMoveUp;
        private MenuItem mnMoveDown;
        private MenuItem menuSep1;
        private MenuItem mnExpandAll;
        private MenuItem mnCollapseAll;
        private StatusStrip statusStrip;
        private ToolStripStatusLabel statusLabel;
        private MenuItem mnUsersGuide;
        private MenuItem menuItem10;
        private MenuItem mnAddEmbedFolder;
        private MenuItem mnAddMsuComponent;
        private MenuItem mnAddInstalledCheckDirectory;
        private MenuItem menuConfigurations;
        private MenuItem menuComponents;
        private MenuItem menuSep3;
        private MenuItem menuChecks;
        private MenuItem menuDownload;
        private MenuItem menuEmbed;
        private MenuItem mnAddLabelControl;
        private MenuItem mnAddCheckboxControl;
        private MenuItem menuControls;
        private MenuItem mnAddEditControl;
        private MenuItem mnAddBrowseControl;
        private MenuItem menuSep4;
        private MenuItem mnAddLicenseAgreement;
        private MenuItem mnAddHyperlinkControl;
        private MenuItem mnEdit;
        private MenuItem mnAddExeComponent;
        private System.ComponentModel.IContainer components;
        private MenuItem mnOpenRecent;
        private MenuItem menuItem3;

        public const string registryPath = @"Software\dotNetInstaller\InstallerEditor";
        private MRUManager m_recentFiles = new MRUManager();
        private MRUManager m_templateFiles = new MRUManager();
        private RegistryKey m_makeExeRegistry;
        private MenuItem mnAddImageControl;
        private RegistryKey m_settingsRegistry;
        private FileSystemWatcher m_configFileWatcher;

        public MainForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (components != null)
                {
                    components.Dispose();
                }
            }
            base.Dispose(disposing);
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
            this.mainMenu = new System.Windows.Forms.MainMenu(this.components);
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
            this.mnOpenRecent = new System.Windows.Forms.MenuItem();
            this.menuItem3 = new System.Windows.Forms.MenuItem();
            this.mnExit = new System.Windows.Forms.MenuItem();
            this.mnEdit = new System.Windows.Forms.MenuItem();
            this.mnAdd = new System.Windows.Forms.MenuItem();
            this.menuConfigurations = new System.Windows.Forms.MenuItem();
            this.mnAddSetupConfiguration = new System.Windows.Forms.MenuItem();
            this.mnAddWebConfiguration = new System.Windows.Forms.MenuItem();
            this.menuComponents = new System.Windows.Forms.MenuItem();
            this.mnAddComponentWizard2 = new System.Windows.Forms.MenuItem();
            this.menuSep3 = new System.Windows.Forms.MenuItem();
            this.mnAddMsiComponent = new System.Windows.Forms.MenuItem();
            this.mnAddMsuComponent = new System.Windows.Forms.MenuItem();
            this.mnAddMspComponent = new System.Windows.Forms.MenuItem();
            this.mnAddExeComponent = new System.Windows.Forms.MenuItem();
            this.mnAddCommandComponent = new System.Windows.Forms.MenuItem();
            this.mnAddOpenFileComponent = new System.Windows.Forms.MenuItem();
            this.menuChecks = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckRegistry = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckFile = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckDirectory = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckOperator = new System.Windows.Forms.MenuItem();
            this.mnAddInstalledCheckProduct = new System.Windows.Forms.MenuItem();
            this.menuDownload = new System.Windows.Forms.MenuItem();
            this.mnAddDownloadDialog = new System.Windows.Forms.MenuItem();
            this.mnAddDownloadFile = new System.Windows.Forms.MenuItem();
            this.menuEmbed = new System.Windows.Forms.MenuItem();
            this.mnAddEmbedFile = new System.Windows.Forms.MenuItem();
            this.mnAddEmbedFolder = new System.Windows.Forms.MenuItem();
            this.menuControls = new System.Windows.Forms.MenuItem();
            this.mnAddLabelControl = new System.Windows.Forms.MenuItem();
            this.mnAddEditControl = new System.Windows.Forms.MenuItem();
            this.mnAddCheckboxControl = new System.Windows.Forms.MenuItem();
            this.mnAddBrowseControl = new System.Windows.Forms.MenuItem();
            this.mnAddHyperlinkControl = new System.Windows.Forms.MenuItem();
            this.menuSep4 = new System.Windows.Forms.MenuItem();
            this.mnAddLicenseAgreement = new System.Windows.Forms.MenuItem();
            this.mnMove = new System.Windows.Forms.MenuItem();
            this.mnMoveUp = new System.Windows.Forms.MenuItem();
            this.mnMoveDown = new System.Windows.Forms.MenuItem();
            this.menuSep1 = new System.Windows.Forms.MenuItem();
            this.mnExpandAll = new System.Windows.Forms.MenuItem();
            this.mnCollapseAll = new System.Windows.Forms.MenuItem();
            this.menuSep2 = new System.Windows.Forms.MenuItem();
            this.mnDelete = new System.Windows.Forms.MenuItem();
            this.mnView = new System.Windows.Forms.MenuItem();
            this.mnRefresh = new System.Windows.Forms.MenuItem();
            this.mnTools = new System.Windows.Forms.MenuItem();
            this.mnTemplates = new System.Windows.Forms.MenuItem();
            this.mnCustomizeTemplates = new System.Windows.Forms.MenuItem();
            this.mnHelp = new System.Windows.Forms.MenuItem();
            this.mnUsersGuide = new System.Windows.Forms.MenuItem();
            this.menuItem10 = new System.Windows.Forms.MenuItem();
            this.mnHomePage = new System.Windows.Forms.MenuItem();
            this.mnHelpAbout = new System.Windows.Forms.MenuItem();
            this.contextMenuTreeView = new System.Windows.Forms.ContextMenu();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.mainSplitContainer = new System.Windows.Forms.SplitContainer();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.propertyGrid = new System.Windows.Forms.PropertyGrid();
            this.configurationTree = new System.Windows.Forms.TreeView();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.statusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.txtComment = new System.Windows.Forms.TextBox();
            this.mnAddImageControl = new System.Windows.Forms.MenuItem();
            this.mainSplitContainer.Panel1.SuspendLayout();
            this.mainSplitContainer.Panel2.SuspendLayout();
            this.mainSplitContainer.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainMenu
            // 
            this.mainMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnFile,
            this.mnEdit,
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
            this.mnOpenRecent,
            this.menuItem3,
            this.mnExit});
            this.mnFile.Text = "&File";
            this.mnFile.Click += new System.EventHandler(this.mnFile_Click);
            // 
            // mnNew
            // 
            this.mnNew.Index = 0;
            this.mnNew.Shortcut = System.Windows.Forms.Shortcut.CtrlN;
            this.mnNew.Text = "&New";
            this.mnNew.Click += new System.EventHandler(this.mnNew_Click);
            // 
            // mnOpen
            // 
            this.mnOpen.Index = 1;
            this.mnOpen.Shortcut = System.Windows.Forms.Shortcut.CtrlO;
            this.mnOpen.Text = "&Open...";
            this.mnOpen.Click += new System.EventHandler(this.mnOpen_Click);
            // 
            // mnClose
            // 
            this.mnClose.Enabled = false;
            this.mnClose.Index = 2;
            this.mnClose.Text = "&Close";
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
            this.mnSave.Shortcut = System.Windows.Forms.Shortcut.CtrlS;
            this.mnSave.Text = "&Save";
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
            this.mnCreateExe.Enabled = false;
            this.mnCreateExe.Index = 8;
            this.mnCreateExe.Shortcut = System.Windows.Forms.Shortcut.F10;
            this.mnCreateExe.Text = "Create Exe...";
            this.mnCreateExe.Click += new System.EventHandler(this.mnCreateExe_Click);
            // 
            // menuItem4
            // 
            this.menuItem4.Index = 9;
            this.menuItem4.Text = "-";
            // 
            // mnOpenRecent
            // 
            this.mnOpenRecent.Index = 10;
            this.mnOpenRecent.Text = "&Recent Files";
            // 
            // menuItem3
            // 
            this.menuItem3.Index = 11;
            this.menuItem3.Text = "-";
            // 
            // mnExit
            // 
            this.mnExit.Index = 12;
            this.mnExit.Shortcut = System.Windows.Forms.Shortcut.AltF4;
            this.mnExit.Text = "E&xit";
            this.mnExit.Click += new System.EventHandler(this.mnExit_Click);
            // 
            // mnEdit
            // 
            this.mnEdit.Index = 1;
            this.mnEdit.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAdd,
            this.mnMove,
            this.menuSep1,
            this.mnExpandAll,
            this.mnCollapseAll,
            this.menuSep2,
            this.mnDelete});
            this.mnEdit.Text = "&Edit";
            this.mnEdit.Popup += new System.EventHandler(this.mnEdit_Popup);
            // 
            // mnAdd
            // 
            this.mnAdd.Index = 0;
            this.mnAdd.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.menuConfigurations,
            this.menuComponents,
            this.menuChecks,
            this.menuDownload,
            this.menuEmbed,
            this.menuControls});
            this.mnAdd.Text = "&Add";
            // 
            // menuConfigurations
            // 
            this.menuConfigurations.Index = 0;
            this.menuConfigurations.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddSetupConfiguration,
            this.mnAddWebConfiguration});
            this.menuConfigurations.Text = "&Configurations";
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
            // menuComponents
            // 
            this.menuComponents.Index = 1;
            this.menuComponents.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddComponentWizard2,
            this.menuSep3,
            this.mnAddMsiComponent,
            this.mnAddMsuComponent,
            this.mnAddMspComponent,
            this.mnAddExeComponent,
            this.mnAddCommandComponent,
            this.mnAddOpenFileComponent});
            this.menuComponents.Text = "Co&mponents";
            // 
            // mnAddComponentWizard2
            // 
            this.mnAddComponentWizard2.Index = 0;
            this.mnAddComponentWizard2.Text = "Component Wizard ...";
            this.mnAddComponentWizard2.Click += new System.EventHandler(this.mnAddComponentWizard2_Click);
            // 
            // menuSep3
            // 
            this.menuSep3.Index = 1;
            this.menuSep3.Text = "-";
            // 
            // mnAddMsiComponent
            // 
            this.mnAddMsiComponent.Index = 2;
            this.mnAddMsiComponent.Text = "Msi Component";
            this.mnAddMsiComponent.Click += new System.EventHandler(this.mnAddMsiComponent_Click);
            // 
            // mnAddMsuComponent
            // 
            this.mnAddMsuComponent.Index = 3;
            this.mnAddMsuComponent.Text = "Msu Component";
            this.mnAddMsuComponent.Click += new System.EventHandler(this.mnAddMsuComponent_Click);
            // 
            // mnAddMspComponent
            // 
            this.mnAddMspComponent.Index = 4;
            this.mnAddMspComponent.Text = "Msp Component";
            this.mnAddMspComponent.Click += new System.EventHandler(this.mnAddMspComponent_Click);
            // 
            // mnAddExeComponent
            // 
            this.mnAddExeComponent.Index = 5;
            this.mnAddExeComponent.Text = "Exe Component";
            this.mnAddExeComponent.Click += new System.EventHandler(this.mnAddExeComponent_Click);
            // 
            // mnAddCommandComponent
            // 
            this.mnAddCommandComponent.Index = 6;
            this.mnAddCommandComponent.Text = "Command Component";
            this.mnAddCommandComponent.Click += new System.EventHandler(this.mnAddCommandComponent_Click);
            // 
            // mnAddOpenFileComponent
            // 
            this.mnAddOpenFileComponent.Index = 7;
            this.mnAddOpenFileComponent.Text = "OpenFile Component";
            this.mnAddOpenFileComponent.Click += new System.EventHandler(this.mnAddOpenFileComponent_Click);
            // 
            // menuChecks
            // 
            this.menuChecks.Index = 2;
            this.menuChecks.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddInstalledCheckRegistry,
            this.mnAddInstalledCheckFile,
            this.mnAddInstalledCheckDirectory,
            this.mnAddInstalledCheckOperator,
            this.mnAddInstalledCheckProduct});
            this.menuChecks.Text = "Chec&ks";
            // 
            // mnAddInstalledCheckRegistry
            // 
            this.mnAddInstalledCheckRegistry.Index = 0;
            this.mnAddInstalledCheckRegistry.Text = "Installed Check Registry";
            this.mnAddInstalledCheckRegistry.Click += new System.EventHandler(this.mnAddInstalledCheckRegistry_Click);
            // 
            // mnAddInstalledCheckFile
            // 
            this.mnAddInstalledCheckFile.Index = 1;
            this.mnAddInstalledCheckFile.Text = "Installed Check File";
            this.mnAddInstalledCheckFile.Click += new System.EventHandler(this.mnInstalledCheckFile_Click);
            // 
            // mnAddInstalledCheckDirectory
            // 
            this.mnAddInstalledCheckDirectory.Index = 2;
            this.mnAddInstalledCheckDirectory.Text = "Installed Check Directory";
            this.mnAddInstalledCheckDirectory.Click += new System.EventHandler(this.mnAddInstalledCheckDirectory_Click);
            // 
            // mnAddInstalledCheckOperator
            // 
            this.mnAddInstalledCheckOperator.Index = 3;
            this.mnAddInstalledCheckOperator.Text = "Installed Check Operator";
            this.mnAddInstalledCheckOperator.Click += new System.EventHandler(this.mnAddInstalledCheckOperator_Click);
            // 
            // mnAddInstalledCheckProduct
            // 
            this.mnAddInstalledCheckProduct.Index = 4;
            this.mnAddInstalledCheckProduct.Text = "Installed Check ProductCode";
            this.mnAddInstalledCheckProduct.Click += new System.EventHandler(this.mnAddInstalledCheckProduct_Click);
            // 
            // menuDownload
            // 
            this.menuDownload.Index = 3;
            this.menuDownload.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddDownloadDialog,
            this.mnAddDownloadFile});
            this.menuDownload.Text = "&Download";
            // 
            // mnAddDownloadDialog
            // 
            this.mnAddDownloadDialog.Index = 0;
            this.mnAddDownloadDialog.Text = "Download Dialog";
            this.mnAddDownloadDialog.Click += new System.EventHandler(this.mnAddDownloadDialog_Click);
            // 
            // mnAddDownloadFile
            // 
            this.mnAddDownloadFile.Index = 1;
            this.mnAddDownloadFile.Text = "Download File";
            this.mnAddDownloadFile.Click += new System.EventHandler(this.mnAddDownloadFile_Click);
            // 
            // menuEmbed
            // 
            this.menuEmbed.Index = 4;
            this.menuEmbed.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddEmbedFile,
            this.mnAddEmbedFolder});
            this.menuEmbed.Text = "&Embed";
            // 
            // mnAddEmbedFile
            // 
            this.mnAddEmbedFile.Index = 0;
            this.mnAddEmbedFile.Text = "&Embed File";
            this.mnAddEmbedFile.Click += new System.EventHandler(this.mnAddEmbedFile_Click);
            // 
            // mnAddEmbedFolder
            // 
            this.mnAddEmbedFolder.Index = 1;
            this.mnAddEmbedFolder.Text = "Embed Folder";
            this.mnAddEmbedFolder.Click += new System.EventHandler(this.mnAddEmbedFolder_Click);
            // 
            // menuControls
            // 
            this.menuControls.Index = 5;
            this.menuControls.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnAddLabelControl,
            this.mnAddEditControl,
            this.mnAddCheckboxControl,
            this.mnAddBrowseControl,
            this.mnAddHyperlinkControl,
            this.mnAddImageControl,
            this.menuSep4,
            this.mnAddLicenseAgreement});
            this.menuControls.Text = "Contro&ls";
            // 
            // mnAddLabelControl
            // 
            this.mnAddLabelControl.Index = 0;
            this.mnAddLabelControl.Text = "&Label";
            this.mnAddLabelControl.Click += new System.EventHandler(this.mnAddLabelControl_Click);
            // 
            // mnAddEditControl
            // 
            this.mnAddEditControl.Index = 1;
            this.mnAddEditControl.Text = "&Edit";
            this.mnAddEditControl.Click += new System.EventHandler(this.mnAddEditControl_Click);
            // 
            // mnAddCheckboxControl
            // 
            this.mnAddCheckboxControl.Index = 2;
            this.mnAddCheckboxControl.Text = "&Checkbox";
            this.mnAddCheckboxControl.Click += new System.EventHandler(this.mnAddCheckboxControl_Click);
            // 
            // mnAddBrowseControl
            // 
            this.mnAddBrowseControl.Index = 3;
            this.mnAddBrowseControl.Text = "&Browse";
            this.mnAddBrowseControl.Click += new System.EventHandler(this.mnAddBrowseControl_Click);
            // 
            // mnAddHyperlinkControl
            // 
            this.mnAddHyperlinkControl.Index = 4;
            this.mnAddHyperlinkControl.Text = "&Hyperlink";
            this.mnAddHyperlinkControl.Click += new System.EventHandler(this.mnAddHyperlinkControl_Click);
            // 
            // menuSep4
            // 
            this.menuSep4.Index = 6;
            this.menuSep4.Text = "-";
            // 
            // mnAddLicenseAgreement
            // 
            this.mnAddLicenseAgreement.Index = 7;
            this.mnAddLicenseAgreement.Text = "License &Agreement";
            this.mnAddLicenseAgreement.Click += new System.EventHandler(this.mnAddLicenseAgreement_Click);
            // 
            // mnMove
            // 
            this.mnMove.Index = 1;
            this.mnMove.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnMoveUp,
            this.mnMoveDown});
            this.mnMove.Text = "&Move";
            // 
            // mnMoveUp
            // 
            this.mnMoveUp.Index = 0;
            this.mnMoveUp.Text = "&Up";
            this.mnMoveUp.Click += new System.EventHandler(this.mnMoveUp_Click);
            // 
            // mnMoveDown
            // 
            this.mnMoveDown.Index = 1;
            this.mnMoveDown.Text = "&Down";
            this.mnMoveDown.Click += new System.EventHandler(this.mnMoveDown_Click);
            // 
            // menuSep1
            // 
            this.menuSep1.Index = 2;
            this.menuSep1.Text = "-";
            // 
            // mnExpandAll
            // 
            this.mnExpandAll.Index = 3;
            this.mnExpandAll.Text = "&Expand All";
            this.mnExpandAll.Click += new System.EventHandler(this.mnExpandAll_Click);
            // 
            // mnCollapseAll
            // 
            this.mnCollapseAll.Index = 4;
            this.mnCollapseAll.Text = "&Collapse All";
            this.mnCollapseAll.Click += new System.EventHandler(this.mnCollapseAll_Click);
            // 
            // menuSep2
            // 
            this.menuSep2.Index = 5;
            this.menuSep2.Text = "-";
            // 
            // mnDelete
            // 
            this.mnDelete.Index = 6;
            this.mnDelete.Text = "&Delete";
            this.mnDelete.Click += new System.EventHandler(this.mnDelete_Click);
            // 
            // mnView
            // 
            this.mnView.Index = 2;
            this.mnView.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnRefresh});
            this.mnView.Text = "&View";
            // 
            // mnRefresh
            // 
            this.mnRefresh.Index = 0;
            this.mnRefresh.Shortcut = System.Windows.Forms.Shortcut.F5;
            this.mnRefresh.Text = "&Refresh";
            this.mnRefresh.Click += new System.EventHandler(this.mnRefresh_Click);
            // 
            // mnTools
            // 
            this.mnTools.Index = 3;
            this.mnTools.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnTemplates,
            this.mnCustomizeTemplates});
            this.mnTools.Text = "&Tools";
            // 
            // mnTemplates
            // 
            this.mnTemplates.Index = 0;
            this.mnTemplates.Text = "Template For New &Item";
            // 
            // mnCustomizeTemplates
            // 
            this.mnCustomizeTemplates.Index = 1;
            this.mnCustomizeTemplates.Text = "&Customize Templates";
            this.mnCustomizeTemplates.Click += new System.EventHandler(this.mnCustomizeTemplates_Click);
            // 
            // mnHelp
            // 
            this.mnHelp.Index = 4;
            this.mnHelp.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnUsersGuide,
            this.menuItem10,
            this.mnHomePage,
            this.mnHelpAbout});
            this.mnHelp.Text = "Help";
            // 
            // mnUsersGuide
            // 
            this.mnUsersGuide.Index = 0;
            this.mnUsersGuide.Text = "&Users Guide";
            this.mnUsersGuide.Click += new System.EventHandler(this.mnUsersGuide_Click);
            // 
            // menuItem10
            // 
            this.menuItem10.Index = 1;
            this.menuItem10.Text = "-";
            // 
            // mnHomePage
            // 
            this.mnHomePage.Index = 2;
            this.mnHomePage.Text = "&Home Page";
            this.mnHomePage.Click += new System.EventHandler(this.mnHomePage_Click);
            // 
            // mnHelpAbout
            // 
            this.mnHelpAbout.Index = 3;
            this.mnHelpAbout.Text = "&About";
            this.mnHelpAbout.Click += new System.EventHandler(this.mnHelpAbout_Click);
            // 
            // contextMenuTreeView
            // 
            this.contextMenuTreeView.Popup += new System.EventHandler(this.contextMenuTreeView_Popup);
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
            this.imageList.Images.SetKeyName(15, "");
            this.imageList.Images.SetKeyName(16, "");
            this.imageList.Images.SetKeyName(17, "");
            this.imageList.Images.SetKeyName(18, "");
            this.imageList.Images.SetKeyName(19, "");
            this.imageList.Images.SetKeyName(20, "");
            this.imageList.Images.SetKeyName(21, "");
            this.imageList.Images.SetKeyName(22, "");
            this.imageList.Images.SetKeyName(23, "");
            this.imageList.Images.SetKeyName(24, "");
            this.imageList.Images.SetKeyName(25, "");
            this.imageList.Images.SetKeyName(26, "");
            // 
            // mainSplitContainer
            // 
            this.mainSplitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainSplitContainer.Location = new System.Drawing.Point(0, 0);
            this.mainSplitContainer.Name = "mainSplitContainer";
            this.mainSplitContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // mainSplitContainer.Panel1
            // 
            this.mainSplitContainer.Panel1.Controls.Add(this.splitter1);
            this.mainSplitContainer.Panel1.Controls.Add(this.propertyGrid);
            this.mainSplitContainer.Panel1.Controls.Add(this.configurationTree);
            // 
            // mainSplitContainer.Panel2
            // 
            this.mainSplitContainer.Panel2.Controls.Add(this.statusStrip);
            this.mainSplitContainer.Panel2.Controls.Add(this.txtComment);
            this.mainSplitContainer.Size = new System.Drawing.Size(620, 346);
            this.mainSplitContainer.SplitterDistance = 278;
            this.mainSplitContainer.TabIndex = 4;
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(176, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 278);
            this.splitter1.TabIndex = 4;
            this.splitter1.TabStop = false;
            // 
            // propertyGrid
            // 
            this.propertyGrid.AccessibleName = "propertyGrid";
            this.propertyGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.propertyGrid.LineColor = System.Drawing.SystemColors.ScrollBar;
            this.propertyGrid.Location = new System.Drawing.Point(176, 0);
            this.propertyGrid.Name = "propertyGrid";
            this.propertyGrid.Size = new System.Drawing.Size(444, 278);
            this.propertyGrid.TabIndex = 3;
            this.propertyGrid.PropertyValueChanged += new System.Windows.Forms.PropertyValueChangedEventHandler(this.propertyGrid_PropertyValueChanged);
            // 
            // configurationTree
            // 
            this.configurationTree.AccessibleName = "configurationTree";
            this.configurationTree.AllowDrop = true;
            this.configurationTree.ContextMenu = this.contextMenuTreeView;
            this.configurationTree.Dock = System.Windows.Forms.DockStyle.Left;
            this.configurationTree.HideSelection = false;
            this.configurationTree.ImageIndex = 0;
            this.configurationTree.ImageList = this.imageList;
            this.configurationTree.Location = new System.Drawing.Point(0, 0);
            this.configurationTree.Name = "configurationTree";
            this.configurationTree.SelectedImageIndex = 0;
            this.configurationTree.Size = new System.Drawing.Size(176, 278);
            this.configurationTree.TabIndex = 1;
            this.configurationTree.DragDrop += new System.Windows.Forms.DragEventHandler(this.treeView_DragDrop);
            this.configurationTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView_AfterSelect);
            this.configurationTree.MouseDown += new System.Windows.Forms.MouseEventHandler(this.treeView_MouseDown);
            this.configurationTree.DragEnter += new System.Windows.Forms.DragEventHandler(this.treeView_DragEnter);
            this.configurationTree.KeyUp += new System.Windows.Forms.KeyEventHandler(this.treeView_KeyUp);
            this.configurationTree.BeforeSelect += new System.Windows.Forms.TreeViewCancelEventHandler(this.treeView_BeforeSelect);
            this.configurationTree.KeyDown += new System.Windows.Forms.KeyEventHandler(this.treeView_KeyDown);
            this.configurationTree.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.treeView_ItemDrag);
            this.configurationTree.DragOver += new System.Windows.Forms.DragEventHandler(this.treeView_DragOver);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusLabel});
            this.statusStrip.Location = new System.Drawing.Point(0, 42);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(620, 22);
            this.statusStrip.TabIndex = 1;
            this.statusStrip.Text = "statusStrip";
            // 
            // statusLabel
            // 
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(39, 17);
            this.statusLabel.Text = "Ready";
            // 
            // txtComment
            // 
            this.txtComment.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.txtComment.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtComment.Location = new System.Drawing.Point(0, 0);
            this.txtComment.Multiline = true;
            this.txtComment.Name = "txtComment";
            this.txtComment.Size = new System.Drawing.Size(620, 64);
            this.txtComment.TabIndex = 0;
            this.txtComment.Visible = false;
            // 
            // mnAddImageControl
            // 
            this.mnAddImageControl.Index = 5;
            this.mnAddImageControl.Text = "&Image";
            this.mnAddImageControl.Click += new System.EventHandler(this.mnAddImageControl_Click);
            // 
            // MainForm
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(620, 346);
            this.Controls.Add(this.mainSplitContainer);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Menu = this.mainMenu;
            this.Name = "MainForm";
            this.Text = "Installer Editor";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Closing += new System.ComponentModel.CancelEventHandler(this.MainForm_Closing);
            this.mainSplitContainer.Panel1.ResumeLayout(false);
            this.mainSplitContainer.Panel2.ResumeLayout(false);
            this.mainSplitContainer.Panel2.PerformLayout();
            this.mainSplitContainer.ResumeLayout(false);
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.ResumeLayout(false);

        }

        void treeView_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                // delete
                case Keys.Delete:
                    if (mnDelete.Enabled) mnDelete_Click(sender, e);
                    break;
                // insert
                case Keys.Insert:
                    contextMenuTreeView.Show(configurationTree, configurationTree.SelectedNode != null
                        ? new Point(configurationTree.SelectedNode.Bounds.Location.X + 5, configurationTree.SelectedNode.Bounds.Location.Y + 5)
                        : new Point(0, 0));
                    break;
            }
        }

        #endregion

        private void mnExit_Click(object sender, System.EventArgs e)
        {
            try
            {
                Close();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private TreeNodeConfigFile m_TreeNodeConfigFile = null;

        private bool NewConfiguration()
        {
            try
            {
                CloseConfiguration();
                m_TreeNodeConfigFile = new TreeNodeConfigFile(new ConfigFile());
                m_TreeNodeConfigFile.IsDirty = true;
                m_TreeNodeConfigFile.CreateChildNodes();
                RefreshMenu();
                LoadTreeView(m_TreeNodeConfigFile);
                statusLabel.Text = "Ready";
                return true;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
                return false;
            }
        }

        private bool OpenConfiguration()
        {
            OpenFileDialog l_dg = new OpenFileDialog();
            l_dg.Filter = "Xml Files(*.xml)|*.xml|All Files(*.*)|*.*";
            l_dg.DefaultExt = "xml";
            if (l_dg.ShowDialog(this) == DialogResult.OK)
            {
                return OpenConfiguration(l_dg.FileName);
            }

            return false;
        }

        private bool OpenConfiguration(string filename)
        {
            if (!CloseConfiguration())
                return false;

            try
            {
                ConfigFile l_File = new ConfigFile();
                l_File.Load(filename);

                if (!l_File.editor.IsCurrent())
                {
                    DialogResult convertResult = MessageBox.Show(this, string.Format("Do you want to convert configuration file version {0} to {1}?",
                        l_File.editor.loaded_version, l_File.editor.current_version), "Convert config file?",
                        MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                    if (convertResult == DialogResult.No)
                    {
                        return false;
                    }
                }

                MonitorChanges(filename);

                m_TreeNodeConfigFile = new TreeNodeConfigFile(l_File);
                m_TreeNodeConfigFile.IsDirty = !l_File.editor.IsCurrent();
                m_TreeNodeConfigFile.CreateChildNodes();

                RefreshMenu();
                LoadTreeView(m_TreeNodeConfigFile);
                statusLabel.Text = string.Format("Loaded {0}", m_TreeNodeConfigFile.Instance.filename);
                m_recentFiles.Add(Path.GetFullPath(m_TreeNodeConfigFile.Instance.filename));
            }
            catch
            {
                m_recentFiles.Remove(filename);
                throw;
            }

            return true;
        }

        private bool CloseConfiguration()
        {
            MonitorChanges(null);

            if (m_TreeNodeConfigFile != null)
            {
                if (m_TreeNodeConfigFile.IsDirty)
                {
                    DialogResult l_ret = MessageBox.Show(this, "Do you want to save your changes?", "Setup Installer", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);
                    if (l_ret == DialogResult.Yes)
                    {
                        if (SaveConfiguration() == false)
                            return false;
                    }
                    else if (l_ret == DialogResult.Cancel)
                    {
                        return false;
                    }
                }
            }

            m_TreeNodeConfigFile = null;
            CloseTreeView();
            propertyGrid.SelectedObject = null;
            RefreshMenu();
            statusLabel.Text = "Ready";
            return true;
        }

        private void MonitorChanges(string filename)
        {
            if (m_configFileWatcher != null)
            {
                m_configFileWatcher.EnableRaisingEvents = false;
                m_configFileWatcher = null;
            }

            if (!string.IsNullOrEmpty(filename))
            {
                m_configFileWatcher = new FileSystemWatcher();
                m_configFileWatcher.Path = Path.GetDirectoryName(filename);
                m_configFileWatcher.Changed += new FileSystemEventHandler(MonitorChanges_Changed);
                m_configFileWatcher.EnableRaisingEvents = true;
            }
        }

        private void ReopenConfiguration(string configFile)
        {
            if (!String.IsNullOrEmpty(configFile))
            {
                CloseConfiguration();
                OpenConfiguration(configFile);
            }
        }

        private delegate void DelegateReopenConfiguration(string configFile);


        private void MonitorChanges_Changed(object sender, FileSystemEventArgs e)
        {
            if (e.FullPath == m_TreeNodeConfigFile.Instance.filename)
            {
                switch (e.ChangeType)
                {
                    case WatcherChangeTypes.Changed:
                        m_configFileWatcher.EnableRaisingEvents = false;
                        if (MessageBox.Show("File '" + e.FullPath + "' has changed. Reload?", "File Changed",
                            MessageBoxButtons.YesNo) == DialogResult.Yes)
                        {
                            configurationTree.Invoke(new DelegateReopenConfiguration(ReopenConfiguration),
                                new object[] { e.FullPath });
                        }
                        else
                        {
                            m_configFileWatcher.EnableRaisingEvents = true;
                        }
                        break;
                }
            }
        }

        private bool SaveConfiguration()
        {
            if (m_TreeNodeConfigFile != null)
            {
                if (m_TreeNodeConfigFile.Instance.filename == null)
                {
                    SaveFileDialog l_dg = new SaveFileDialog();
                    l_dg.Filter = "Xml Files(*.xml)|*.xml|All Files(*.*)|*.*";
                    l_dg.DefaultExt = "xml";
                    if (l_dg.ShowDialog(this) == DialogResult.OK)
                    {
                        m_TreeNodeConfigFile.Instance.SaveAs(l_dg.FileName);
                        MonitorChanges(l_dg.FileName);
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    MonitorChanges(null);
                    m_TreeNodeConfigFile.Instance.Save();
                    MonitorChanges(m_TreeNodeConfigFile.Instance.filename);
                }
            }

            m_TreeNodeConfigFile.IsDirty = false;
            statusLabel.Text = string.Format("Written {0}", m_TreeNodeConfigFile.Instance.filename);
            m_recentFiles.Add(m_TreeNodeConfigFile.Instance.filename);
            RefreshMenu();
            return true;
        }

        private void RefreshMenu()
        {
            mnClose.Enabled = (m_TreeNodeConfigFile != null);
            mnSaveAs.Enabled = (m_TreeNodeConfigFile != null);

            if (m_TreeNodeConfigFile != null &&
                m_TreeNodeConfigFile.Instance != null &&
                m_TreeNodeConfigFile.Instance.filename != null)
            {
                Text = "Installer Editor - " + m_TreeNodeConfigFile.Instance.filename;
                mnEditWithNotepad.Enabled = true;
                mnSave.Enabled = true;
                mnCreateExe.Enabled = true;
            }
            else
            {
                Text = "Installer Editor";
                mnEditWithNotepad.Enabled = false;
                mnSave.Enabled = false;
                mnCreateExe.Enabled = false;
            }

            RefreshCommentPanel();
        }

        private void RefreshCommentPanel()
        {
            if (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Tag is XmlClass)
            {
                txtComment.Visible = true;
                txtComment.Text = ((XmlClass)configurationTree.SelectedNode.Tag).Comment;
            }
            else
            {
                txtComment.Visible = false;
                txtComment.Text = string.Empty;
            }
        }

        private void mnSave_Click(object sender, System.EventArgs e)
        {
            try
            {
                configurationTree.Select();
                SaveConfiguration();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnClose_Click(object sender, System.EventArgs e)
        {
            try
            {
                CloseConfiguration();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        public ConfigFile ConfigFile
        {
            get { return m_TreeNodeConfigFile.Instance; }
            set { m_TreeNodeConfigFile.Instance = value; }
        }

        private void CloseTreeView()
        {
            configurationTree.Nodes.Clear();
        }

        private void LoadTreeView(TreeNodeConfigFile p_Configuration)
        {
            CloseTreeView();
            configurationTree.Nodes.Add(p_Configuration);
            configurationTree.ExpandAll();
            configurationTree.SelectedNode = p_Configuration;
        }

        private void mnNew_Click(object sender, System.EventArgs e)
        {
            try
            {
                NewConfiguration();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnOpen_Click(object sender, System.EventArgs e)
        {
            try
            {
                OpenConfiguration();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void treeView_AfterSelect(object sender, System.Windows.Forms.TreeViewEventArgs e)
        {
            try
            {
                propertyGrid.SelectedObject = e.Node.Tag;
                RefreshNodeContextMenu();
                RefreshCommentPanel();
                statusLabel.Text = m_TreeNodeConfigFile != null
                    ? m_TreeNodeConfigFile.Instance.filename
                    : string.Empty;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void RefreshNodeContextMenu()
        {
            if (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Tag is XmlClass)
            {
                XmlClass item = (XmlClass)configurationTree.SelectedNode.Tag;
                mnDelete.Enabled = true;
                mnAddSetupConfiguration.Enabled = (item.Children.CanAdd(typeof(SetupConfiguration)));
                mnAddWebConfiguration.Enabled = (item.Children.CanAdd(typeof(WebConfiguration)));
                mnAddCommandComponent.Enabled = (item.Children.CanAdd(typeof(ComponentCmd)));
                mnAddExeComponent.Enabled = (item.Children.CanAdd(typeof(ComponentExe)));
                mnAddMsiComponent.Enabled = (item.Children.CanAdd(typeof(ComponentMsi)));
                mnAddMsuComponent.Enabled = (item.Children.CanAdd(typeof(ComponentMsu)));
                mnAddMspComponent.Enabled = (item.Children.CanAdd(typeof(ComponentMsp)));
                mnAddOpenFileComponent.Enabled = (item.Children.CanAdd(typeof(ComponentOpenFile)));
                mnAddEmbedFile.Enabled = (item.Children.CanAdd(typeof(EmbedFile)));
                mnAddEmbedFolder.Enabled = (item.Children.CanAdd(typeof(EmbedFolder)));
                mnAddDownloadDialog.Enabled = (item.Children.CanAdd(typeof(DownloadDialog)));
                mnAddDownloadFile.Enabled = (item.Children.CanAdd(typeof(Download)));
                mnAddInstalledCheckFile.Enabled = (item.Children.CanAdd(typeof(InstalledCheckFile)));
                mnAddInstalledCheckDirectory.Enabled = (item.Children.CanAdd(typeof(InstalledCheckDirectory)));
                mnAddInstalledCheckRegistry.Enabled = (item.Children.CanAdd(typeof(InstalledCheckRegistry)));
                mnAddInstalledCheckProduct.Enabled = (item.Children.CanAdd(typeof(InstalledCheckProduct)));
                mnAddInstalledCheckOperator.Enabled = (item.Children.CanAdd(typeof(InstalledCheckOperator)));
                mnAddComponentWizard2.Enabled = (item is SetupConfiguration);
                mnMoveUp.Enabled = (configurationTree.SelectedNode.PrevNode != null);
                mnMoveDown.Enabled = (configurationTree.SelectedNode.NextNode != null);
                mnMove.Enabled = mnMoveUp.Enabled || mnMoveDown.Enabled;
                mnAddLabelControl.Enabled = (item.Children.CanAdd(typeof(ControlLabel)));
                mnAddCheckboxControl.Enabled = (item.Children.CanAdd(typeof(ControlCheckBox)));
                mnAddEditControl.Enabled = (item.Children.CanAdd(typeof(ControlEdit)));
                mnAddBrowseControl.Enabled = (item.Children.CanAdd(typeof(ControlBrowse)));
                mnAddLicenseAgreement.Enabled = (item.Children.CanAdd(typeof(ControlLicense)));
                mnAddHyperlinkControl.Enabled = (item.Children.CanAdd(typeof(ControlHyperlink)));
                mnAddImageControl.Enabled = (item.Children.CanAdd(typeof(ControlImage)));
            }
            else
            {
                mnDelete.Enabled = false;
                mnAddSetupConfiguration.Enabled = false;
                mnAddWebConfiguration.Enabled = false;
                mnAddCommandComponent.Enabled = false;
                mnAddExeComponent.Enabled = false;
                mnAddMsiComponent.Enabled = false;
                mnAddMsuComponent.Enabled = false;
                mnAddOpenFileComponent.Enabled = false;
                mnAddEmbedFile.Enabled = false;
                mnAddEmbedFolder.Enabled = false;
                mnAddDownloadDialog.Enabled = false;
                mnAddInstalledCheckFile.Enabled = false;
                mnAddInstalledCheckDirectory.Enabled = false;
                mnAddInstalledCheckRegistry.Enabled = false;
                mnAddInstalledCheckProduct.Enabled = false;
                mnAddInstalledCheckOperator.Enabled = false;
                mnAddComponentWizard2.Enabled = false;
                mnMove.Enabled = false;
                mnMoveUp.Enabled = false;
                mnMoveDown.Enabled = false;
                mnAddLabelControl.Enabled = false;
                mnAddCheckboxControl.Enabled = false;
                mnAddEditControl.Enabled = false;
                mnAddBrowseControl.Enabled = false;
                mnAddLicenseAgreement.Enabled = false;
                mnAddHyperlinkControl.Enabled = false;
                mnAddImageControl.Enabled = false;
            }
        }

        #region Nodes

        private T Add<T>(XmlClass parent)
            where T : XmlClass, new()
        {
            T component = new T();
            parent.Children.Add(component);
            return component;
        }

        private void AddTreeNode(TreeNode node, XmlTreeNodeImpl treeNode)
        {
            node.Nodes.Add(treeNode);
            m_TreeNodeConfigFile.IsDirty = true;
            node.Expand();
            configurationTree.SelectedNode = treeNode;
            treeNode.ExpandAll();
        }

        private void AddTreeNode<T>()
            where T : XmlClass, new()
        {
            T xmlitem = new T();
            ((XmlClass)configurationTree.SelectedNode.Tag).Children.Add(xmlitem);
            XmlTreeNodeImpl xmlitemnode = XmlTreeNodeImpl.CreateNode(xmlitem);
            AddTreeNode(configurationTree.SelectedNode, xmlitemnode);
        }

        private void AddTreeNode_Click<T>()
            where T : XmlClass, new()
        {
            try
            {
                AddTreeNode<T>();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnAddEmbedFolder_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<EmbedFolder>();
        }

        private void mnAddInstalledCheckProduct_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<InstalledCheckProduct>();
        }

        private void mnAddMsuComponent_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ComponentMsu>();
        }

        private void mnAddInstalledCheckDirectory_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<InstalledCheckDirectory>();
        }

        private void mnAddLabelControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlLabel>();
        }

        private void mnAddCheckboxControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlCheckBox>();
        }

        private void mnAddEditControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlEdit>();
        }

        private void mnAddBrowseControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlBrowse>();
        }

        private void mnAddOpenFileComponent_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<ComponentOpenFile>();
        }

        private void mnAddLicenseAgreement_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlLicense>();
        }

        private void mnAddSetupConfiguration_Click(object sender, System.EventArgs e)
        {
            configurationTree.SelectedNode = m_TreeNodeConfigFile;
            AddTreeNode_Click<SetupConfiguration>();
        }

        private void mnAddWebConfiguration_Click(object sender, System.EventArgs e)
        {
            configurationTree.SelectedNode = m_TreeNodeConfigFile;
            AddTreeNode_Click<WebConfiguration>();
        }

        private void mnAddDownloadFile_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<Download>();
        }

        private void mnAddMsiComponent_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<ComponentMsi>();
        }

        private void mnAddMspComponent_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<ComponentMsp>();
        }

        private void mnAddCommandComponent_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<ComponentCmd>();
        }

        private void mnAddInstalledCheckRegistry_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<InstalledCheckRegistry>();
        }

        private void mnInstalledCheckFile_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<InstalledCheckFile>();
        }

        private void mnAddDownloadDialog_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<DownloadDialog>();
        }

        private void mnAddEmbedFile_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<EmbedFile>();
        }

        private void mnAddInstalledCheckOperator_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<InstalledCheckOperator>();
        }

        private void mnAddHyperlinkControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlHyperlink>();
        }


        private void mnAddImageControl_Click(object sender, EventArgs e)
        {
            AddTreeNode_Click<ControlImage>();
        }

        #endregion

        private void MainForm_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (CloseConfiguration() == false)
            {
                e.Cancel = true;
                return;
            }

            if (WindowState != FormWindowState.Minimized)
            {
                m_settingsRegistry.SetValue("WindowState", WindowState.ToString());
                m_settingsRegistry.SetValue("Bounds", XmlRectangle.ToString(Bounds));
            }

            m_settingsRegistry.SetValue("ConfigurationTreeWidth", configurationTree.Width);
            m_settingsRegistry.SetValue("CommentsDistance", mainSplitContainer.SplitterDistance);
        }

        private void mnDelete_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Parent != null)
                {
                    if (configurationTree.SelectedNode.Tag is XmlClass && configurationTree.SelectedNode.Parent.Tag is XmlClass)
                    {
                        XmlClass item = (XmlClass)configurationTree.SelectedNode.Tag;
                        XmlClass parent = (XmlClass)configurationTree.SelectedNode.Parent.Tag;
                        parent.Children.Remove(item);
                        configurationTree.SelectedNode.Remove();
                        m_TreeNodeConfigFile.IsDirty = true;
                    }
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnRefresh_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (m_TreeNodeConfigFile != null && m_TreeNodeConfigFile.Instance != null)
                {
                    m_TreeNodeConfigFile = new TreeNodeConfigFile(m_TreeNodeConfigFile.Instance);
                    m_TreeNodeConfigFile.CreateChildNodes();
                    LoadTreeView(m_TreeNodeConfigFile);
                }

                statusLabel.Text = "Ready";
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void treeView_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            try
            {
                TreeNode l_Node = configurationTree.GetNodeAt(e.X, e.Y);
                if (l_Node != null)
                {
                    configurationTree.SelectedNode = l_Node;
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnSaveAs_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (m_TreeNodeConfigFile != null && m_TreeNodeConfigFile.Instance != null)
                {
                    m_TreeNodeConfigFile.Instance.filename = null;
                    SaveConfiguration();
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnEditWithNotepad_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (m_TreeNodeConfigFile.Instance.filename != null)
                {
                    System.Diagnostics.ProcessStartInfo p = new System.Diagnostics.ProcessStartInfo("NOTEPAD.EXE", "\"" + m_TreeNodeConfigFile.Instance.filename + "\"");
                    p.UseShellExecute = false;
                    System.Diagnostics.Process process = new System.Diagnostics.Process();
                    process.StartInfo = p;
                    process.Start();
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnHomePage_Click(object sender, System.EventArgs e)
        {
            try
            {
                SourceLibrary.Utility.Shell.ExecCommand("http://www.codeplex.com/dotnetinstaller/");
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void LoadSettings()
        {
            try
            {
                bool migrateSettings = (Registry.CurrentUser.OpenSubKey(registryPath) == null);

                m_settingsRegistry = Registry.CurrentUser.CreateSubKey(registryPath);
                m_recentFiles.Initialize(this, mnOpenRecent, registryPath + @"\RecentFiles");
                m_templateFiles.Initialize(this, null, registryPath + @"\TemplateFiles");
                m_templateFiles.MaxMRULength = 48;
                m_makeExeRegistry = Registry.CurrentUser.CreateSubKey(registryPath + @"\MakeExe");

                if (migrateSettings)
                {
                    MigrateLegacySettings();
                }

                RefreshTemplateFilesMenu();

                // window state, don't start minimized
                FormWindowState windowState = (FormWindowState)Enum.Parse(typeof(FormWindowState), (string)m_settingsRegistry.GetValue("WindowState", WindowState.ToString()));
                if (windowState != FormWindowState.Minimized)
                {
                    WindowState = windowState;
                    // bounds are invalid for a minimized window
                    Rectangle bounds = XmlRectangle.FromString((string)m_settingsRegistry.GetValue("Bounds", XmlRectangle.ToString(Bounds)));
                    if (!bounds.IsEmpty) Bounds = bounds;
                }
                // configuration tree width
                int configurationTreeWidth = (int)m_settingsRegistry.GetValue("ConfigurationTreeWidth", configurationTree.Width);
                if (configurationTreeWidth >= 0) configurationTree.Width = configurationTreeWidth;
                // comments splitter distance
                int commentsDistance = (int)m_settingsRegistry.GetValue("CommentsDistance", mainSplitContainer.SplitterDistance);
                if (commentsDistance >= 0) mainSplitContainer.SplitterDistance = commentsDistance;
            }
            catch (Exception err)
            {
                ErrorDialog.Show(this, err, "Error loading settings");
            }
        }

        private void MainForm_Load(object sender, System.EventArgs e)
        {
            LoadSettings();

            try
            {
                if (!string.IsNullOrEmpty(InstallerEditor.CmdArgs.configfile))
                {
                    OpenConfiguration(InstallerEditor.CmdArgs.configfile);
                }
            }
            catch (FileNotFoundException err)
            {
                Environment.ExitCode = -2;
                ErrorDialog.Show(this, err, "Error");
                Close();
            }
            catch (Exception err)
            {
                Environment.ExitCode = -3;
                ErrorDialog.Show(this, err, "Error");
                Close();
            }
        }

        private void MigrateLegacySettings()
        {
            AppSetting legacyAppSetting = new AppSetting();
            legacyAppSetting.Load();

            if (legacyAppSetting.BannerBitmapFile != null)
                m_makeExeRegistry.SetValue("BannerBitmap", legacyAppSetting.BannerBitmapFile);
            if (legacyAppSetting.IconFile != null)
                m_makeExeRegistry.SetValue("IconFile", legacyAppSetting.IconFile);
            if (legacyAppSetting.OutputMakeFile != null)
                m_makeExeRegistry.SetValue("OutputFile", legacyAppSetting.OutputMakeFile);
            if (legacyAppSetting.TemplateConfigFile != null)
                m_makeExeRegistry.SetValue("TemplateFile", legacyAppSetting.TemplateConfigFile);

            if (legacyAppSetting.TemplateConfigFile != null)
                m_settingsRegistry.SetValue("TemplateConfigFile", legacyAppSetting.TemplateConfigFile);

            foreach (string template in legacyAppSetting.AvailableTemplates)
            {
                m_templateFiles.Add(template);
            }

            legacyAppSetting.Reset();
        }

        /// <summary>
        /// Select a template from previously saved settings.
        /// </summary>
        private void SelectTemplate()
        {
            foreach (MenuItemTemplate menuItem in mnTemplates.MenuItems)
            {
                if (menuItem.AreEqual((string)m_settingsRegistry.GetValue("TemplateConfigFile", "English")))
                {
                    menuItem.PerformClick();
                    return;
                }
            }

            mnTemplates.MenuItems[0].PerformClick();
        }

        private void mnCreateExe_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (m_TreeNodeConfigFile == null || m_TreeNodeConfigFile.Instance == null)
                {
                    throw new ApplicationException("Missing configuration");
                }

                MakeExe l_frmMakeExe = new MakeExe();
                l_frmMakeExe.TemplateFile = (string)m_makeExeRegistry.GetValue("TemplateFile", string.Empty);
                l_frmMakeExe.BannerBitmapFile = (string)m_makeExeRegistry.GetValue("BannerBitmapFile", string.Empty);
                l_frmMakeExe.IconFile = (string)m_makeExeRegistry.GetValue("IconFile", string.Empty);
                l_frmMakeExe.OutputFileName = (string)m_makeExeRegistry.GetValue("OutputFileName", string.Empty);
                l_frmMakeExe.SplashBitmapFile = (string)m_makeExeRegistry.GetValue("SplashBitmapFile", string.Empty);
                l_frmMakeExe.ManifestFile = (string)m_makeExeRegistry.GetValue("ManifestFile", string.Empty);
                l_frmMakeExe.Embed = ((int)m_makeExeRegistry.GetValue("Embed", 1) != 0);
                l_frmMakeExe.ConfigFile = Path.GetTempFileName();

                try
                {
                    m_TreeNodeConfigFile.Instance.WriteTo(l_frmMakeExe.ConfigFile);
                    l_frmMakeExe.ShowDialog(this);
                }
                finally
                {
                    File.Delete(l_frmMakeExe.ConfigFile);
                }

                m_makeExeRegistry.SetValue("TemplateFile", l_frmMakeExe.TemplateFile);
                m_makeExeRegistry.SetValue("BannerBitmapFile", l_frmMakeExe.BannerBitmapFile);
                m_makeExeRegistry.SetValue("IconFile", l_frmMakeExe.IconFile);
                m_makeExeRegistry.SetValue("OutputFileName", l_frmMakeExe.OutputFileName);
                m_makeExeRegistry.SetValue("SplashBitmapFile", l_frmMakeExe.SplashBitmapFile);
                m_makeExeRegistry.SetValue("ManifestFile", l_frmMakeExe.ManifestFile);
                m_makeExeRegistry.SetValue("Embed", l_frmMakeExe.Embed ? 1 : 0);
            }
            catch (Exception err)
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
            editors.AvailableTemplateFiles = new List<String>(m_templateFiles);
            if (editors.ShowDialog(this) == DialogResult.OK)
            {
                m_templateFiles.Clear();
                m_templateFiles.AddRange(editors.AvailableTemplateFiles);
                RefreshTemplateFilesMenu();
            }
        }

        private void RefreshTemplateFilesMenu()
        {
            mnTemplates.MenuItems.Clear();

            foreach (Template template in Template.EmbeddedTemplates)
            {
                MenuItemTemplateInstance templateMenuItem = new MenuItemTemplateInstance(template);
                templateMenuItem.Click += new EventHandler(
                    delegate(object sender, EventArgs e)
                    {
                        m_settingsRegistry.SetValue("TemplateConfigFile", templateMenuItem.Text);
                    }
                );
                mnTemplates.MenuItems.Add(templateMenuItem);
            }

            foreach (string file in m_templateFiles)
            {
                try
                {
                    MenuItemTemplateFile templateFileMenuItem = new MenuItemTemplateFile(file);
                    templateFileMenuItem.Click += new EventHandler(
                        delegate(object sender, EventArgs e)
                        {
                            m_settingsRegistry.SetValue("TemplateConfigFile", file);
                        }
                    );
                    mnTemplates.MenuItems.Add(templateFileMenuItem);
                }
                catch (Exception err)
                {
                    ErrorDialog.Show(this, err, "Error");
                }
            }

            SelectTemplate();
        }

        private void mnAddComponentWizard2_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Tag is SetupConfiguration)
                {
                    SetupConfiguration l_Setup = (SetupConfiguration)configurationTree.SelectedNode.Tag;
                    ComponentWizard2 l_frmWizard = new ComponentWizard2();

                    if (l_frmWizard.ShowDialog(this) == DialogResult.OK)
                    {
                        foreach (Component c in l_frmWizard.SelectedComponents)
                        {
                            l_Setup.Children.Add(c);
                            TreeNodeComponent<Component> componentNode = new TreeNodeComponent<Component>(c);
                            componentNode.CreateChildNodes();
                            AddTreeNode(configurationTree.SelectedNode, componentNode);
                        }
                    }
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void treeView_BeforeSelect(object sender, TreeViewCancelEventArgs e)
        {
            if (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Tag is XmlClass)
            {
                ((XmlClass)configurationTree.SelectedNode.Tag).Comment = txtComment.Text;
            }
        }

        private void mnMoveUp_Click(object sender, EventArgs e)
        {
            configurationTree.BeginUpdate();
            try
            {
                if (configurationTree.SelectedNode == null)
                    throw new ApplicationException("Missing node");

                if (configurationTree.SelectedNode.PrevNode == null)
                    throw new ApplicationException("Missing previous node");

                if (configurationTree.Parent == null)
                    throw new ApplicationException("Missing parent node");

                XmlTreeNodeImpl nodeMoved = (XmlTreeNodeImpl)configurationTree.SelectedNode;
                nodeMoved.MoveTo(nodeMoved.Index - 1);
                m_TreeNodeConfigFile.IsDirty = true;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
            finally
            {
                configurationTree.EndUpdate();
            }
        }

        private void mnMoveDown_Click(object sender, EventArgs e)
        {
            configurationTree.BeginUpdate();

            try
            {
                if (configurationTree.SelectedNode == null)
                    throw new ApplicationException("Missing node");

                if (configurationTree.SelectedNode.NextNode == null)
                    throw new ApplicationException("Missing next node");

                if (configurationTree.Parent == null)
                    throw new ApplicationException("Missing parent node");

                XmlTreeNodeImpl nodeMoved = (XmlTreeNodeImpl)configurationTree.SelectedNode;
                nodeMoved.MoveTo(nodeMoved.Index + 1);
                m_TreeNodeConfigFile.IsDirty = true;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
            finally
            {
                configurationTree.EndUpdate();
            }
        }

        private void treeView_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Control)
            {
                switch (e.KeyCode)
                {
                    case Keys.Up:
                        // up
                        if (mnMoveUp.Enabled) mnMoveUp_Click(sender, e);
                        break;
                    case Keys.Down:
                        //down
                        if (mnMoveDown.Enabled) mnMoveDown_Click(sender, e);
                        break;
                }
            }
        }

        #region Drag and Drop

        /// <summary>
        /// A node container for drag-and-drop
        /// </summary>
        private class TreeNodeImplContainer
        {
            private XmlTreeNodeImpl m_data = null;

            public XmlTreeNodeImpl NodeData
            {
                get
                {
                    return m_data;
                }
            }

            public TreeNodeImplContainer(XmlTreeNodeImpl value)
            {
                m_data = value;
            }
        }

        private void treeView_ItemDrag(object sender, ItemDragEventArgs e)
        {
            TreeNodeImplContainer container = new TreeNodeImplContainer((XmlTreeNodeImpl)e.Item);
            DoDragDrop(container, DragDropEffects.Move);
        }

        private void treeView_DragDrop(object sender, DragEventArgs e)
        {
            configurationTree.BeginUpdate();

            try
            {
                if (!e.Data.GetDataPresent(typeof(TreeNodeImplContainer)))
                    return;

                // target node
                Point pos = configurationTree.PointToClient(new Point(e.X, e.Y));
                XmlTreeNodeImpl targetNode = (XmlTreeNodeImpl)configurationTree.GetNodeAt(pos);

                // node being dragged
                XmlTreeNodeImpl dropNode = ((TreeNodeImplContainer)e.Data.GetData(typeof(TreeNodeImplContainer))).NodeData;

                // check that this node data type can be dropped here at all
                XmlClass dropItem = (XmlClass)dropNode.Tag;

                dropNode.MoveTo(targetNode);
                m_TreeNodeConfigFile.IsDirty = true;
            }
            finally
            {
                configurationTree.EndUpdate();
            }
        }

        private void treeView_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = (e.Data.GetDataPresent(typeof(TreeNodeImplContainer)))
                ? DragDropEffects.Move
                : DragDropEffects.None;
        }

        private void treeView_DragOver(object sender, DragEventArgs e)
        {
            if (!e.Data.GetDataPresent(typeof(TreeNodeImplContainer)))
            {
                e.Effect = DragDropEffects.None;
                return;
            }

            // target node
            Point pos = configurationTree.PointToClient(new Point(e.X, e.Y));
            TreeNode targetNode = configurationTree.GetNodeAt(pos);

            if (targetNode == null)
            {
                e.Effect = DragDropEffects.None;
                return;
            }

            // if the target node is selected, don't validate again
            if (configurationTree.SelectedNode == targetNode)
                return;

            configurationTree.SelectedNode = targetNode;

            // node being dragged
            XmlTreeNodeImpl dropNode = ((TreeNodeImplContainer)e.Data.GetData(typeof(TreeNodeImplContainer))).NodeData;
            if (dropNode.Parent == targetNode)
            {
                e.Effect = DragDropEffects.None;
                return;
            }

            // check that this node data type can be dropped here at all
            XmlClass dropItem = (XmlClass)dropNode.Tag;
            XmlClass targetItem = (XmlClass)targetNode.Tag;
            if (!targetItem.Children.CanAdd(dropItem))
            {
                e.Effect = DragDropEffects.None;
                return;
            }

            // check that the selected node is not the dropNode and also that it is not a child of the dropNode
            while (targetNode != null)
            {
                if (targetNode == dropNode)
                {
                    e.Effect = DragDropEffects.None;
                    return;
                }

                targetNode = targetNode.Parent;
            }

            e.Effect = DragDropEffects.Move;
        }

        #endregion

        private void mnExpandAll_Click(object sender, EventArgs e)
        {
            try
            {
                configurationTree.SelectedNode.ExpandAll();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnCollapseAll_Click(object sender, EventArgs e)
        {
            try
            {
                configurationTree.SelectedNode.Collapse(false);
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void mnUsersGuide_Click(object sender, EventArgs e)
        {
            try
            {
                string chm = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), @"..\doc\dotNetInstaller.chm");
                System.Diagnostics.ProcessStartInfo p = new System.Diagnostics.ProcessStartInfo(chm);
                p.UseShellExecute = true;
                System.Diagnostics.Process process = new System.Diagnostics.Process();
                process.StartInfo = p;
                process.Start();
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void propertyGrid_PropertyValueChanged(object s, PropertyValueChangedEventArgs e)
        {
            if (m_TreeNodeConfigFile != null)
            {
                m_TreeNodeConfigFile.IsDirty = true;
            }
        }

        private void mnEdit_Popup(object sender, EventArgs e)
        {
            mnAdd.Enabled = (m_TreeNodeConfigFile != null);
            mnDelete.Enabled = (configurationTree.SelectedNode != null);
            mnExpandAll.Enabled = (configurationTree.SelectedNode != null && configurationTree.SelectedNode.Nodes.Count > 0);
            mnCollapseAll.Enabled = (configurationTree.SelectedNode != null && configurationTree.SelectedNode.IsExpanded);
            mnMove.Enabled = (m_TreeNodeConfigFile != null);
        }

        private void contextMenuTreeView_Popup(object sender, EventArgs e)
        {
            mnEdit_Popup(sender, e);
            contextMenuTreeView.MenuItems.Clear();
            contextMenuTreeView.MergeMenu(mnEdit);
        }

        private void mnAddExeComponent_Click(object sender, System.EventArgs e)
        {
            AddTreeNode_Click<ComponentExe>();
        }

        private void mnFile_Click(object sender, EventArgs e)
        {
            if (mnOpenRecent.MenuItems.Count == 0)
            {
                mnOpenRecent.Enabled = false;
            }
        }

        #region IMRUClient Members

        public void OpenMRUFile(string fileName)
        {
            OpenConfiguration(fileName);
        }

        #endregion
    }
}
