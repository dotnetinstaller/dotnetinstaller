using System;
using System.Drawing;
using System.Collections;
using System.Windows.Forms;
using InstallerLib;

namespace InstallerEditor
{
	/// <summary>
	/// Summary description for ComponentWizard.
	/// </summary>
	public class ComponentWizard : System.Windows.Forms.Form
	{
		private System.Windows.Forms.CheckedListBox chkListComponents;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.RadioButton rdbDownloaded;
		private System.Windows.Forms.RadioButton rdbStandAlone;
		private System.Windows.Forms.GroupBox groupBoxDownloaded;
		private System.Windows.Forms.TextBox txtSupportFilesWebSite;
		private System.Windows.Forms.TextBox txtSupportFilesFileSystem;
		private System.Windows.Forms.Button btBrowseSupportFilesFileSystem;
		private System.Windows.Forms.Button btCancel;
		private System.Windows.Forms.Button btOK;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.GroupBox groupBoxSupportFilesFileSystem;
		private System.Windows.Forms.Label lbLanguage;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public ComponentWizard()
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
				if(components != null)
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
			this.chkListComponents = new System.Windows.Forms.CheckedListBox();
			this.label1 = new System.Windows.Forms.Label();
			this.rdbDownloaded = new System.Windows.Forms.RadioButton();
			this.rdbStandAlone = new System.Windows.Forms.RadioButton();
			this.groupBoxDownloaded = new System.Windows.Forms.GroupBox();
			this.txtSupportFilesWebSite = new System.Windows.Forms.TextBox();
			this.groupBoxSupportFilesFileSystem = new System.Windows.Forms.GroupBox();
			this.txtSupportFilesFileSystem = new System.Windows.Forms.TextBox();
			this.btBrowseSupportFilesFileSystem = new System.Windows.Forms.Button();
			this.btCancel = new System.Windows.Forms.Button();
			this.btOK = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.lbLanguage = new System.Windows.Forms.Label();
			this.groupBoxDownloaded.SuspendLayout();
			this.groupBoxSupportFilesFileSystem.SuspendLayout();
			this.SuspendLayout();
			// 
			// chkListComponents
			// 
			this.chkListComponents.CheckOnClick = true;
			this.chkListComponents.Location = new System.Drawing.Point(8, 24);
			this.chkListComponents.Name = "chkListComponents";
			this.chkListComponents.Size = new System.Drawing.Size(460, 79);
			this.chkListComponents.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(8, 4);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(312, 20);
			this.label1.TabIndex = 1;
			this.label1.Text = "Components to install";
			// 
			// rdbDownloaded
			// 
			this.rdbDownloaded.Location = new System.Drawing.Point(12, 108);
			this.rdbDownloaded.Name = "rdbDownloaded";
			this.rdbDownloaded.Size = new System.Drawing.Size(272, 20);
			this.rdbDownloaded.TabIndex = 0;
			this.rdbDownloaded.Text = "Downloaded from Internet";
			this.rdbDownloaded.CheckedChanged += new System.EventHandler(this.rdbDownloaded_CheckedChanged);
			// 
			// rdbStandAlone
			// 
			this.rdbStandAlone.Checked = true;
			this.rdbStandAlone.Location = new System.Drawing.Point(12, 180);
			this.rdbStandAlone.Name = "rdbStandAlone";
			this.rdbStandAlone.Size = new System.Drawing.Size(292, 16);
			this.rdbStandAlone.TabIndex = 1;
			this.rdbStandAlone.TabStop = true;
			this.rdbStandAlone.Text = "Distribuited with dotNetInstaller";
			this.rdbStandAlone.CheckedChanged += new System.EventHandler(this.rdbStandAlone_CheckedChanged);
			// 
			// groupBoxDownloaded
			// 
			this.groupBoxDownloaded.Controls.Add(this.txtSupportFilesWebSite);
			this.groupBoxDownloaded.Location = new System.Drawing.Point(8, 128);
			this.groupBoxDownloaded.Name = "groupBoxDownloaded";
			this.groupBoxDownloaded.Size = new System.Drawing.Size(464, 44);
			this.groupBoxDownloaded.TabIndex = 3;
			this.groupBoxDownloaded.TabStop = false;
			// 
			// txtSupportFilesWebSite
			// 
			this.txtSupportFilesWebSite.Location = new System.Drawing.Point(4, 16);
			this.txtSupportFilesWebSite.Name = "txtSupportFilesWebSite";
			this.txtSupportFilesWebSite.Size = new System.Drawing.Size(424, 20);
			this.txtSupportFilesWebSite.TabIndex = 1;
			this.txtSupportFilesWebSite.Text = "http://www.myWebSite.com/MyApp/SupportFiles";
			// 
			// groupBoxSupportFilesFileSystem
			// 
			this.groupBoxSupportFilesFileSystem.Controls.Add(this.txtSupportFilesFileSystem);
			this.groupBoxSupportFilesFileSystem.Controls.Add(this.btBrowseSupportFilesFileSystem);
			this.groupBoxSupportFilesFileSystem.Location = new System.Drawing.Point(8, 196);
			this.groupBoxSupportFilesFileSystem.Name = "groupBoxSupportFilesFileSystem";
			this.groupBoxSupportFilesFileSystem.Size = new System.Drawing.Size(464, 44);
			this.groupBoxSupportFilesFileSystem.TabIndex = 4;
			this.groupBoxSupportFilesFileSystem.TabStop = false;
			// 
			// txtSupportFilesFileSystem
			// 
			this.txtSupportFilesFileSystem.Location = new System.Drawing.Point(4, 16);
			this.txtSupportFilesFileSystem.Name = "txtSupportFilesFileSystem";
			this.txtSupportFilesFileSystem.Size = new System.Drawing.Size(424, 20);
			this.txtSupportFilesFileSystem.TabIndex = 1;
			this.txtSupportFilesFileSystem.Text = "#APPPATH\\SupportFiles";
			// 
			// btBrowseSupportFilesFileSystem
			// 
			this.btBrowseSupportFilesFileSystem.Location = new System.Drawing.Point(432, 16);
			this.btBrowseSupportFilesFileSystem.Name = "btBrowseSupportFilesFileSystem";
			this.btBrowseSupportFilesFileSystem.Size = new System.Drawing.Size(28, 20);
			this.btBrowseSupportFilesFileSystem.TabIndex = 0;
			this.btBrowseSupportFilesFileSystem.Text = "...";
			// 
			// btCancel
			// 
			this.btCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btCancel.Location = new System.Drawing.Point(396, 300);
			this.btCancel.Name = "btCancel";
			this.btCancel.TabIndex = 5;
			this.btCancel.Text = "Cancel";
			// 
			// btOK
			// 
			this.btOK.Location = new System.Drawing.Point(308, 300);
			this.btOK.Name = "btOK";
			this.btOK.TabIndex = 6;
			this.btOK.Text = "OK";
			this.btOK.Click += new System.EventHandler(this.btOK_Click);
			// 
			// label2
			// 
			this.label2.BackColor = System.Drawing.SystemColors.Info;
			this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label2.ForeColor = System.Drawing.SystemColors.InfoText;
			this.label2.Location = new System.Drawing.Point(8, 252);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(292, 72);
			this.label2.TabIndex = 0;
			this.label2.Text = "The wizard automatically add the relative path of each component based on the sta" +
				"ndard structure of the SupportFiles directory that you can download from: www.de" +
				"vage.com . Here you must only write the root path of the SupportFiles directory." +
				"";
			// 
			// lbLanguage
			// 
			this.lbLanguage.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lbLanguage.Location = new System.Drawing.Point(304, 276);
			this.lbLanguage.Name = "lbLanguage";
			this.lbLanguage.Size = new System.Drawing.Size(168, 20);
			this.lbLanguage.TabIndex = 7;
			// 
			// ComponentWizard
			// 
			this.AcceptButton = this.btOK;
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.CancelButton = this.btCancel;
			this.ClientSize = new System.Drawing.Size(478, 329);
			this.Controls.Add(this.lbLanguage);
			this.Controls.Add(this.btOK);
			this.Controls.Add(this.btCancel);
			this.Controls.Add(this.groupBoxSupportFilesFileSystem);
			this.Controls.Add(this.groupBoxDownloaded);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.chkListComponents);
			this.Controls.Add(this.rdbDownloaded);
			this.Controls.Add(this.rdbStandAlone);
			this.Controls.Add(this.label2);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "ComponentWizard";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
			this.Text = "ComponentWizard";
			this.Load += new System.EventHandler(this.ComponentWizard_Load);
			this.groupBoxDownloaded.ResumeLayout(false);
			this.groupBoxSupportFilesFileSystem.ResumeLayout(false);
			this.ResumeLayout(false);

		}
		#endregion

		private void rdbDownloaded_CheckedChanged(object sender, System.EventArgs e)
		{
			RefreshGroupBox();
		}

		private void rdbStandAlone_CheckedChanged(object sender, System.EventArgs e)
		{
			RefreshGroupBox();
		}

		private void RefreshGroupBox()
		{
			if (rdbDownloaded.Checked)
			{
				groupBoxDownloaded.Enabled = true;
				groupBoxSupportFilesFileSystem.Enabled = false;
			}
			else
			{
				groupBoxDownloaded.Enabled = false;
				groupBoxSupportFilesFileSystem.Enabled = true;
			}
		}

		private void ComponentWizard_Load(object sender, System.EventArgs e)
		{
			RefreshGroupBox();

			lbLanguage.Text = Template.CurrentTemplate.Name;

			//supported component
			chkListComponents.Items.Clear();
			chkListComponents.Items.Add(new ListComponent_NT4Sp6a());
			chkListComponents.Items.Add(new ListComponent_2000Sp4Express_English());
			chkListComponents.Items.Add(new ListComponent_2000Sp4Full_English());
			chkListComponents.Items.Add(new ListComponent_IE6Sp1());
			chkListComponents.Items.Add(new ListComponent_MDAC27sp1());
			chkListComponents.Items.Add(new ListComponent_MDAC28());
			chkListComponents.Items.Add(new ListComponent_Jet40Sp8_English());
			chkListComponents.Items.Add(new ListComponent_DotNet1_1_English());
		}

		private ComponentCollection m_SelectedComponents = new ComponentCollection();

		private void btOK_Click(object sender, System.EventArgs e)
		{
			try
			{
				foreach (WizardComponent w in chkListComponents.CheckedItems)
				{
					if (rdbDownloaded.Checked)
						m_SelectedComponents.AddRange(w.CreateComponent(txtSupportFilesWebSite.Text, true));
					else
						m_SelectedComponents.AddRange(w.CreateComponent(txtSupportFilesFileSystem.Text, false));
				}
				
				DialogResult = DialogResult.OK;
			}
			catch(Exception err)
			{
				AppUtility.ShowError(this, err);
			}
		}

		public ComponentCollection SelectedComponents
		{
			get{return m_SelectedComponents;}
		}

		private abstract class WizardComponent
		{
			private string m_Description;
			public WizardComponent(string p_Description)
			{
				m_Description = p_Description;
			}

			public override string ToString()
			{
				return m_Description;
			}

			public abstract Component[] CreateComponent(string p_Path, bool p_Download);
		}

		private class ListComponent_DotNet1_1_English : WizardComponent
		{
			public ListComponent_DotNet1_1_English():base("Microsoft .NET 1.1 English")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Microsoft .NET Framework 1.1";

				InstalledCheckRegistry l_InstallCheck = new InstalledCheckRegistry();
				l_InstallCheck.comparison = installcheck_comparison.match;
				l_InstallCheck.fieldname = "Install";
				l_InstallCheck.fieldtype = installcheck_registrytype.REG_DWORD;
				l_InstallCheck.fieldvalue = "1";
				l_InstallCheck.path = "SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v1.1.4322";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("dotNET1_1_en");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/dotNet1.1/English/dotnetfx.exe";
				l_downloadDlg.Downloads.Add(l_Download);


				//before for windows 2000
				ComponentCmd l_component1 = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component1.command = "\"" + l_Download.destinationpath + "\\dotnetfx.exe\" /q:a /c:\"install /l /qb\"";
					l_component1.DownloadDialog = l_downloadDlg;
					l_component1.note = "English - WebSetup - ";
				}
				else
				{
					l_component1.command = "\"" + p_Path + "\\dotNet1.1\\English\\dotnetfx.exe\" /q:a /c:\"install /l /qb\"";
					l_component1.note = "English - Standard - ";
				}
				l_component1.mustreboot = true; //in win 98 I must force a reboot for some problem with the shortcut,maybe the problem occurs when installing Windows Installer that is installed with .NET
				l_component1.os_filter_lcid = "";
				l_component1.os_filter_greater = "";
				l_component1.os_filter_smaller = "45";
				l_component1.installedchecks.Add(l_InstallCheck);
				l_component1.note += ".NET Framework 1.1 for all operating system before windows 2000, require a reboot";


				//for windows 2000 and before Windows 2003
				ComponentCmd l_component2 = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component2.command = "\"" + l_Download.destinationpath + "\\dotnetfx.exe\" /q:a /c:\"install /l /qb\"";
					l_component2.DownloadDialog = l_downloadDlg;
					l_component2.note = "English - WebSetup - ";
				}
				else
				{
					l_component2.command = "\"" + p_Path + "\\dotNet1.1\\English\\dotnetfx.exe\" /q:a /c:\"install /l /qb\"";
					l_component2.note = "English - Standard - ";
				}
				l_component2.mustreboot = false;
				l_component2.os_filter_lcid = "";
				l_component2.os_filter_greater = "44";
				l_component2.os_filter_smaller = "90";
				l_component2.installedchecks.Add(l_InstallCheck);
				l_component2.note += ".NET Framework 1.1 for Windows 2000 and Windows XP";

				return new Component[]{l_component1, l_component2};
			}
		}

		private class ListComponent_MDAC27sp1 : WizardComponent
		{
			public ListComponent_MDAC27sp1():base("Microsoft MDAC 2.7 Sp1 English")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Microsoft Data Access Components 2.7 Sp1";

				InstalledCheckRegistry l_InstallCheck = new InstalledCheckRegistry();
				l_InstallCheck.comparison = installcheck_comparison.version;
				l_InstallCheck.fieldname = "Version";
				l_InstallCheck.fieldtype = installcheck_registrytype.REG_SZ;
				l_InstallCheck.fieldvalue = "2.71.0.0";
				l_InstallCheck.path = "SOFTWARE\\Microsoft\\DataAccess";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("MDAC27Sp1");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/MDAC2.7Sp1Refresh/English/Win_98_ME_NT_2000/mdac_typ.exe";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = ListComponent_MDAC28.Build_MDAC_cmd(l_Download.destinationpath + "\\mdac_typ.exe");
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "English - WebSetup - ";
				}
				else
				{
					l_component.command = ListComponent_MDAC28.Build_MDAC_cmd(p_Path + "\\MDAC2.7Sp1Refresh\\English\\Win_98_ME_NT_2000\\mdac_typ.exe");
					l_component.note = "English - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "";
				l_component.os_filter_smaller = "75";
				l_component.installedchecks.Add(l_InstallCheck);
				l_component.note += "MDAC 2.7 Sp1 for Win98, ME, NT4, 2000. Quit mode.";

				return new Component[]{l_component};
			}
		}

		private class ListComponent_MDAC28 : WizardComponent
		{
			public ListComponent_MDAC28():base("Microsoft MDAC 2.8 English")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Microsoft Data Access Components 2.8";

				InstalledCheckRegistry l_InstallCheck = new InstalledCheckRegistry();
				l_InstallCheck.comparison = installcheck_comparison.version;
				l_InstallCheck.fieldname = "Version";
				l_InstallCheck.fieldtype = installcheck_registrytype.REG_SZ;
				l_InstallCheck.fieldvalue = "2.80.0.0";
				l_InstallCheck.path = "SOFTWARE\\Microsoft\\DataAccess";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("MDAC28");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/MDAC2.8/English/Win_98_ME_NT_2000_XP/MDAC_TYP.EXE";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = Build_MDAC_cmd(l_Download.destinationpath + "\\MDAC_TYP.EXE");
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "English - WebSetup - ";
				}
				else
				{
					l_component.command = Build_MDAC_cmd(p_Path + "\\MDAC2.8\\English\\Win_98_ME_NT_2000_XP\\MDAC_TYP.EXE");
					l_component.note = "English - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "14";
				l_component.os_filter_smaller = "90";
				l_component.installedchecks.Add(l_InstallCheck);
				l_component.note += "MDAC 2.8 for Win98, ME, NT4, 2000 and XP. Quit mode.";

				return new Component[]{l_component};
			}

			static public string Build_MDAC_cmd(string path)
			{
				//MDAC_TYP.EXE /q:a /c:"dasetup.exe /q"
				string quot = "\"";
				return quot + path + quot + " /q:a /c:" + quot + "dasetup.exe /q" + quot;
			}
		}


		private class ListComponent_IE6Sp1 : WizardComponent
		{
			public ListComponent_IE6Sp1():base("Microsoft Internet Explorer 6 Sp1 English (5.01 Required)")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Microsoft Internet Explorer 6 Sp1";

				//<InstalledCheck type="check_registry_value" path="SOFTWARE\Microsoft\Internet Explorer" fieldname="Version" fieldvalue="5.50.4134.0100" fieldtype="REG_SZ" comparison="version" />
				InstalledCheckRegistry l_InstallCheck = new InstalledCheckRegistry();
				l_InstallCheck.comparison = installcheck_comparison.version;
				l_InstallCheck.fieldname = "Version";
				l_InstallCheck.fieldtype = installcheck_registrytype.REG_SZ;
				l_InstallCheck.fieldvalue = "5.00.2920.0000";
				l_InstallCheck.path = "SOFTWARE\\Microsoft\\Internet Explorer";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("IE6SP1");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/InternetExplorer6.0Sp1/English/ie6setup.exe";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = "\"" + l_Download.destinationpath + "\\ie6setup.exe\"";
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "English - WebSetup - ";
				}
				else
				{
					l_component.command = "\"" + p_Path + "\\InternetExplorer6.0Sp1\\English\\ie6setup.exe\"";
					l_component.note = "English - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "";
				l_component.os_filter_smaller = "80";
				l_component.installedchecks.Add(l_InstallCheck);
				l_component.note += "Internet Explorer 6Sp1 (IE 5.01 Required)";

				return new Component[]{l_component};
			}
		}

		private class ListComponent_Jet40Sp8_English : WizardComponent
		{
			public ListComponent_Jet40Sp8_English():base("Microsoft JET 4.0 Sp8 English")
			{
			}

			private const string m_ComponentName = "Microsoft JET 4.0 Sp8";

			private InstalledCheck CreateInstalledCheck()
			{
				//File Msjet40.dll - 4.0.8015.0
				InstalledCheckFile l_InstallCheck = new InstalledCheckFile();
				l_InstallCheck.comparison = installcheck_comparison.version;
				l_InstallCheck.filename = "#SYSTEMPATH\\Msjet40.dll";
				l_InstallCheck.fileversion = "4.0.8015.0";

				return l_InstallCheck;
			}

			private Component CreateComponentJET(string p_Path, 
												bool p_Download, 
												string JetRelativePath, 
												string JetFileName, 
												string ExecParameter,
												string osFilterSmaller, 
												string osFilterGreater,
												string osNote)
			{
				DownloadDialog l_downloadDlg = new DownloadDialog(m_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("JET4Sp8");
				l_Download.componentname = m_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/Jet40Sp8/English/" + JetRelativePath + "/" + JetFileName;
				l_downloadDlg.Downloads.Add(l_Download);

				ComponentCmd l_component1 = new ComponentCmd(m_ComponentName);
				if (p_Download) //download
				{
					l_component1.command = "\"" + l_Download.destinationpath + "\\" + JetFileName + "\" " + ExecParameter;
					l_component1.DownloadDialog = l_downloadDlg;
					l_component1.note = "English - WebSetup - ";
				}
				else
				{
					l_component1.command = "\"" + p_Path + "\\Jet40Sp8\\English\\" + JetRelativePath + "\\" + JetFileName + "\" " + ExecParameter;
					l_component1.note = "English - Standard - ";
				}
				l_component1.mustreboot = false;
				l_component1.os_filter_lcid = "";
				l_component1.os_filter_greater = osFilterGreater;
				l_component1.os_filter_smaller = osFilterSmaller;
				l_component1.installedchecks.Add( CreateInstalledCheck() );
				l_component1.note += "Jet 4.0 Sp8 for " + osNote;

				return l_component1;
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				return new Component[]{
										CreateComponentJET(p_Path, p_Download, "95_98_NT4", "Jet40SP8_9xNT.exe", "/Q", "25", "4", "95 and 98"),
										  CreateComponentJET(p_Path, p_Download, "95_98_NT4", "Jet40SP8_9xNT.exe", "/Q", "41", "29", "NT4"),
										  CreateComponentJET(p_Path, p_Download, "2000", "Windows2000-KB829558-x86-ENU.exe", "/quiet", "66", "44", "2000"),
										  CreateComponentJET(p_Path, p_Download, "ME", "jet40sp8_Wme.exe", "/Q", "26", "24", "ME"),
										  CreateComponentJET(p_Path, p_Download, "Server2003", "WindowsServer2003-KB829558-x86-ENU.exe", "/quiet", "91", "89", "Server 2003"),
										  CreateComponentJET(p_Path, p_Download, "XP", "WindowsXP-KB829558-x86-ENU.exe", "/quiet", "83", "74", "XP"),
										};
			}
		}

		private class ListComponent_NT4Sp6a : WizardComponent
		{
			public ListComponent_NT4Sp6a():base("Windows NT 4 Service Pack 6a English")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Windows NT 4 Service Pack 6a English";

				//<component os_filter_greater="29" os_filter_smaller="40" os_filter_lcid="" type="cmd" installcompletemessage="" mustreboot="False" description="Windows NT 4 Service Pack 6a English" installmessage="Click Next to install Service Pack 6a for Windows NT4 (English)" note="" command="&quot;#APPPATH\SupportFiles\ServicePack\NT4_SP6a_English\sp6i386.exe&quot;" />

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("NT4Sp6a");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/ServicePacks/NT4_SP6a/HighEncryption_x86/Network/English/sp6i386.exe";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = "\"" + l_Download.destinationpath + "\\sp6i386.exe\"";
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "Neutral - WebSetup - ";
				}
				else
				{
					l_component.command = "\"" + p_Path + "\\ServicePacks\\NT4_SP6a\\HighEncryption_x86\\Network\\English\\sp6i386.exe\"";
					l_component.note = "Neutral - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "29";
				l_component.os_filter_smaller = "40";
				l_component.note += "Windows NT 4 Service Pack 6a";

				return new Component[]{l_component};
			}
		}

		private class ListComponent_2000Sp4Full_English : WizardComponent
		{
			public ListComponent_2000Sp4Full_English():base("Windows 2000 Sp4 Full - English (Sp3 Required)")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Windows 2000 Service Pack 4 English";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("Win2000Sp4");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/ServicePacks/2000_SP4/Network/English/W2KSP4_EN.EXE";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = "\"" + l_Download.destinationpath + "\\W2KSP4_EN.EXE\"";
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "English - WebSetup - ";
				}
				else
				{
					l_component.command = "\"" + p_Path + "\\ServicePacks\\2000_SP4\\Network\\English\\W2KSP4_EN.EXE\"";
					l_component.note = "English - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "44";
				l_component.os_filter_smaller = "59";
				l_component.note += "Windows 2000 Sp4 Full (Sp3 Required)";

				return new Component[]{l_component};
			}
		}

		private class ListComponent_2000Sp4Express_English : WizardComponent
		{
			public ListComponent_2000Sp4Express_English():base("Windows 2000 Sp4 Express - English (Sp3 Required)")
			{
			}

			public override Component[] CreateComponent(string p_Path, bool p_Download)
			{
				string l_ComponentName = "Windows 2000 Service Pack 4 English";

				DownloadDialog l_downloadDlg = new DownloadDialog(l_ComponentName);
				l_downloadDlg.autostartdownload = false;
				Download l_Download = new Download("Win2000Sp4");
				l_Download.componentname = l_ComponentName;
				l_Download.destinationfilename = "";
				l_Download.sourceurl = p_Path + "/ServicePacks/2000_SP4/Express/English/SP4Express_EN.exe";
				l_downloadDlg.Downloads.Add(l_Download);


				ComponentCmd l_component = new ComponentCmd(l_ComponentName);
				if (p_Download) //download
				{
					l_component.command = "\"" + l_Download.destinationpath + "\\SP4Express_EN.exe\"";
					l_component.DownloadDialog = l_downloadDlg;
					l_component.note = "English - WebSetup - ";
				}
				else
				{
					l_component.command = "\"" + p_Path + "\\ServicePacks\\2000_SP4\\Express\\English\\SP4Express_EN.exe\"";
					l_component.note = "English - Standard - ";
				}
				l_component.mustreboot = false;
				l_component.os_filter_lcid = "";
				l_component.os_filter_greater = "44";
				l_component.os_filter_smaller = "59";
				l_component.note += "Windows 2000 Sp4 Express (Sp3 Required)";

				return new Component[]{l_component};
			}
		}
	}

}
