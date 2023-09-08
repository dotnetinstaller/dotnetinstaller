using System;
using System.Windows.Forms;
using InstallerLib;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for MakeExe.
    /// </summary>
    public class MakeExe : System.Windows.Forms.Form
    {
        private System.Windows.Forms.TextBox txtBannerBitmap;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btBrowseBannerBitmap;
        private System.Windows.Forms.Button btCancel;
        private System.Windows.Forms.Button btMake;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btBrowseTemplateFile;
        private System.Windows.Forms.TextBox txtTemplateFile;
        private System.Windows.Forms.CheckBox chkEmbed;
        private TextBox txtIcon;
        private Button btBrowseIcon;
        private Label label4;
        private TextBox txtSplashBitmap;
        private Button btBrowseSplashBitmap;
        private Label label5;
        private TextBox txtManifest;
        private Button btBrowseManifest;
        private Label label6;
        private string m_ConfigFile;

        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public MakeExe()
        {
            //
            // Required for Windows Form Designer support
            //
            InitializeComponent();

            //
            // TODO: Add any constructor code after InitializeComponent call
            //
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
            this.btCancel = new System.Windows.Forms.Button();
            this.btMake = new System.Windows.Forms.Button();
            this.txtBannerBitmap = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btBrowseBannerBitmap = new System.Windows.Forms.Button();
            this.btBrowseTemplateFile = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.txtTemplateFile = new System.Windows.Forms.TextBox();
            this.chkEmbed = new System.Windows.Forms.CheckBox();
            this.txtIcon = new System.Windows.Forms.TextBox();
            this.btBrowseIcon = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtSplashBitmap = new System.Windows.Forms.TextBox();
            this.btBrowseSplashBitmap = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.txtManifest = new System.Windows.Forms.TextBox();
            this.btBrowseManifest = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btCancel
            // 
            this.btCancel.AccessibleName = "btCancel";
            this.btCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btCancel.Location = new System.Drawing.Point(308, 210);
            this.btCancel.Name = "btCancel";
            this.btCancel.Size = new System.Drawing.Size(75, 23);
            this.btCancel.TabIndex = 0;
            this.btCancel.Text = "Cancel";
            // 
            // btMake
            // 
            this.btMake.AccessibleName = "btMake";
            this.btMake.Location = new System.Drawing.Point(220, 210);
            this.btMake.Name = "btMake";
            this.btMake.Size = new System.Drawing.Size(75, 23);
            this.btMake.TabIndex = 8;
            this.btMake.Text = "Make";
            this.btMake.Click += new System.EventHandler(this.btMake_Click);
            // 
            // txtBannerBitmap
            // 
            this.txtBannerBitmap.AccessibleName = "txtBannerBitmap";
            this.txtBannerBitmap.Location = new System.Drawing.Point(10, 66);
            this.txtBannerBitmap.Name = "txtBannerBitmap";
            this.txtBannerBitmap.Size = new System.Drawing.Size(344, 20);
            this.txtBannerBitmap.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(9, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(240, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Banner Bitmap (optional)";
            // 
            // btBrowseBannerBitmap
            // 
            this.btBrowseBannerBitmap.Location = new System.Drawing.Point(357, 66);
            this.btBrowseBannerBitmap.Name = "btBrowseBannerBitmap";
            this.btBrowseBannerBitmap.Size = new System.Drawing.Size(24, 20);
            this.btBrowseBannerBitmap.TabIndex = 3;
            this.btBrowseBannerBitmap.Text = "...";
            this.btBrowseBannerBitmap.Click += new System.EventHandler(this.btBrowseBannerBitmap_Click);
            // 
            // btBrowseTemplateFile
            // 
            this.btBrowseTemplateFile.Location = new System.Drawing.Point(357, 27);
            this.btBrowseTemplateFile.Name = "btBrowseTemplateFile";
            this.btBrowseTemplateFile.Size = new System.Drawing.Size(24, 20);
            this.btBrowseTemplateFile.TabIndex = 1;
            this.btBrowseTemplateFile.Text = "...";
            this.btBrowseTemplateFile.Click += new System.EventHandler(this.btBrowseTemplateFile_Click);
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(9, 10);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(240, 16);
            this.label3.TabIndex = 9;
            this.label3.Text = "Template dotNetInstaller.exe File";
            // 
            // txtTemplateFile
            // 
            this.txtTemplateFile.AccessibleDescription = "";
            this.txtTemplateFile.AccessibleName = "txtTemplateFile";
            this.txtTemplateFile.Location = new System.Drawing.Point(10, 27);
            this.txtTemplateFile.Name = "txtTemplateFile";
            this.txtTemplateFile.Size = new System.Drawing.Size(344, 20);
            this.txtTemplateFile.TabIndex = 9;
            // 
            // chkEmbed
            // 
            this.chkEmbed.AccessibleName = "chkEmbed";
            this.chkEmbed.AutoSize = true;
            this.chkEmbed.Checked = true;
            this.chkEmbed.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkEmbed.Location = new System.Drawing.Point(9, 210);
            this.chkEmbed.Name = "chkEmbed";
            this.chkEmbed.Size = new System.Drawing.Size(131, 17);
            this.chkEmbed.TabIndex = 7;
            this.chkEmbed.Text = "&Embed Dependencies";
            this.chkEmbed.UseVisualStyleBackColor = true;
            // 
            // txtIcon
            // 
            this.txtIcon.AccessibleName = "txtIcon";
            this.txtIcon.Location = new System.Drawing.Point(10, 140);
            this.txtIcon.Name = "txtIcon";
            this.txtIcon.Size = new System.Drawing.Size(344, 20);
            this.txtIcon.TabIndex = 13;
            // 
            // btBrowseIcon
            // 
            this.btBrowseIcon.Location = new System.Drawing.Point(357, 140);
            this.btBrowseIcon.Name = "btBrowseIcon";
            this.btBrowseIcon.Size = new System.Drawing.Size(24, 20);
            this.btBrowseIcon.TabIndex = 5;
            this.btBrowseIcon.Text = "...";
            this.btBrowseIcon.Click += new System.EventHandler(this.btBrowseIcon_Click);
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(9, 124);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(240, 16);
            this.label4.TabIndex = 13;
            this.label4.Text = "Icon (optional)";
            // 
            // txtSplashBitmap
            // 
            this.txtSplashBitmap.AccessibleName = "txtSplashBitmap";
            this.txtSplashBitmap.Location = new System.Drawing.Point(10, 103);
            this.txtSplashBitmap.Name = "txtSplashBitmap";
            this.txtSplashBitmap.Size = new System.Drawing.Size(344, 20);
            this.txtSplashBitmap.TabIndex = 12;
            // 
            // btBrowseSplashBitmap
            // 
            this.btBrowseSplashBitmap.Location = new System.Drawing.Point(357, 103);
            this.btBrowseSplashBitmap.Name = "btBrowseSplashBitmap";
            this.btBrowseSplashBitmap.Size = new System.Drawing.Size(24, 20);
            this.btBrowseSplashBitmap.TabIndex = 4;
            this.btBrowseSplashBitmap.Text = "...";
            this.btBrowseSplashBitmap.Click += new System.EventHandler(this.btBrowseSplashBitmap_Click);
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(9, 87);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(240, 16);
            this.label5.TabIndex = 16;
            this.label5.Text = "Splash Bitmap (optional)";
            // 
            // txtManifest
            // 
            this.txtManifest.AccessibleName = "txtManifest";
            this.txtManifest.Location = new System.Drawing.Point(10, 177);
            this.txtManifest.Name = "txtManifest";
            this.txtManifest.Size = new System.Drawing.Size(344, 20);
            this.txtManifest.TabIndex = 14;
            // 
            // btBrowseManifest
            // 
            this.btBrowseManifest.Location = new System.Drawing.Point(357, 177);
            this.btBrowseManifest.Name = "btBrowseManifest";
            this.btBrowseManifest.Size = new System.Drawing.Size(24, 20);
            this.btBrowseManifest.TabIndex = 6;
            this.btBrowseManifest.Text = "...";
            this.btBrowseManifest.Click += new System.EventHandler(this.btBrowseManifest_Click);
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(9, 161);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(240, 16);
            this.label6.TabIndex = 19;
            this.label6.Text = "Manifest (optional)";
            // 
            // MakeExe
            // 
            this.AccessibleName = "createExe";
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btCancel;
            this.ClientSize = new System.Drawing.Size(393, 245);
            this.Controls.Add(this.txtManifest);
            this.Controls.Add(this.btBrowseManifest);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtSplashBitmap);
            this.Controls.Add(this.btBrowseSplashBitmap);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtIcon);
            this.Controls.Add(this.btBrowseIcon);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btBrowseTemplateFile);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtTemplateFile);
            this.Controls.Add(this.txtBannerBitmap);
            this.Controls.Add(this.btBrowseBannerBitmap);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btMake);
            this.Controls.Add(this.btCancel);
            this.Controls.Add(this.chkEmbed);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MakeExe";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Create Executable";
            this.ResumeLayout(false);
            this.PerformLayout();

        }
        #endregion

        private void btMake_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (!System.IO.File.Exists(txtTemplateFile.Text))
                    throw new ApplicationException("Template file '" + txtTemplateFile.Text + "' is missing");

                if (!System.IO.File.Exists(ConfigFile))
                    throw new ApplicationException("Configuration file '" + ConfigFile + " ' is missing");

                SaveFileDialog l_dg = new SaveFileDialog();
                l_dg.FileName = m_OutputFileName;
                l_dg.Filter = "Exe File (*.exe)|*.exe|All Files(*.*)|*.*";
                l_dg.DefaultExt = "exe";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                {
                    InstallerLinkerArguments args = new InstallerLinkerArguments();
                    args.banner = txtBannerBitmap.Text;
                    args.icon = txtIcon.Text;
                    args.config = ConfigFile;
                    args.output = l_dg.FileName;
                    args.template = txtTemplateFile.Text;
                    args.embed = chkEmbed.Checked;
                    args.manifest = txtManifest.Text;
                    args.splash = txtSplashBitmap.Text;
                    InstallerLinker.CreateInstaller(args);
                    m_OutputFileName = l_dg.FileName;
                    DialogResult = DialogResult.OK;
                    Close();
                }
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private string m_OutputFileName;
        public string OutputFileName
        {
            get { return m_OutputFileName; }
            set { m_OutputFileName = value; }
        }

        public string TemplateFile
        {
            get { return txtTemplateFile.Text; }
            set { txtTemplateFile.Text = value; }
        }

        public string BannerBitmapFile
        {
            get { return txtBannerBitmap.Text; }
            set { txtBannerBitmap.Text = value; }
        }

        public string IconFile
        {
            get { return txtIcon.Text; }
            set { txtIcon.Text = value; }
        }

        public string ConfigFile
        {
            get { return m_ConfigFile; }
            set { m_ConfigFile = value; }
        }

        public string SplashBitmapFile
        {
            get { return txtSplashBitmap.Text; }
            set { txtSplashBitmap.Text = value; }
        }

        public string ManifestFile
        {
            get { return txtManifest.Text; }
            set { txtManifest.Text = value; }
        }

        public bool Embed
        {
            get { return chkEmbed.Checked; }
            set { chkEmbed.Checked = value; }
        }

        private void btBrowseTemplateFile_Click(object sender, System.EventArgs e)
        {
            try
            {
                OpenFileDialog l_dg = new OpenFileDialog();
                l_dg.Filter = "Exe File (*.exe)|*.exe|All Files(*.*)|*.*";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                    txtTemplateFile.Text = l_dg.FileName;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void btBrowseBannerBitmap_Click(object sender, System.EventArgs e)
        {
            try
            {
                OpenFileDialog l_dg = new OpenFileDialog();
                l_dg.Filter = "Bitmap File (*.bmp)|*.bmp|All Files(*.*)|*.*";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                    txtBannerBitmap.Text = l_dg.FileName;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void btBrowseIcon_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog l_dg = new OpenFileDialog();
                l_dg.Filter = "Icon File (*.ico)|*.ico|All Files(*.*)|*.*";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                    txtIcon.Text = l_dg.FileName;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void btBrowseManifest_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog l_dg = new OpenFileDialog();
                l_dg.Filter = "Manifest File (*.manifest)|*.manifest|All Files(*.*)|*.*";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                    txtManifest.Text = l_dg.FileName;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }

        private void btBrowseSplashBitmap_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog l_dg = new OpenFileDialog();
                l_dg.Filter = "Bitmap File (*.bmp)|*.bmp|All Files(*.*)|*.*";
                if (l_dg.ShowDialog(this) == DialogResult.OK)
                    txtSplashBitmap.Text = l_dg.FileName;
            }
            catch (Exception err)
            {
                AppUtility.ShowError(this, err);
            }
        }
    }
}
