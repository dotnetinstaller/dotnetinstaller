using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for TemplatesEditor.
    /// </summary>
    public class TemplatesEditor : System.Windows.Forms.Form
    {
        private SourceGrid2.Grid gridList;
        private System.Windows.Forms.Button btCancel;
        private System.Windows.Forms.Button btOK;
        private System.Windows.Forms.Label label1;
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public TemplatesEditor()
        {
            InitializeComponent();
        }

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
            this.gridList = new SourceGrid2.Grid();
            this.btCancel = new System.Windows.Forms.Button();
            this.btOK = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // gridList
            // 
            this.gridList.AccessibleName = "gridList";
            this.gridList.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.gridList.AutoSizeMinHeight = 10;
            this.gridList.AutoSizeMinWidth = 10;
            this.gridList.AutoStretchColumnsToFitWidth = false;
            this.gridList.AutoStretchRowsToFitHeight = false;
            this.gridList.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.gridList.ContextMenuStyle = SourceGrid2.ContextMenuStyle.None;
            this.gridList.CustomSort = false;
            this.gridList.FocusStyle = SourceGrid2.FocusStyle.None;
            this.gridList.GridToolTipActive = true;
            this.gridList.Location = new System.Drawing.Point(8, 36);
            this.gridList.Name = "gridList";
            this.gridList.Size = new System.Drawing.Size(308, 232);
            this.gridList.SpecialKeys = ((SourceGrid2.GridSpecialKeys)(((((((((((SourceGrid2.GridSpecialKeys.Ctrl_C | SourceGrid2.GridSpecialKeys.Ctrl_V)
                        | SourceGrid2.GridSpecialKeys.Ctrl_X)
                        | SourceGrid2.GridSpecialKeys.Delete)
                        | SourceGrid2.GridSpecialKeys.Arrows)
                        | SourceGrid2.GridSpecialKeys.Tab)
                        | SourceGrid2.GridSpecialKeys.PageDownUp)
                        | SourceGrid2.GridSpecialKeys.Enter)
                        | SourceGrid2.GridSpecialKeys.Escape)
                        | SourceGrid2.GridSpecialKeys.Control)
                        | SourceGrid2.GridSpecialKeys.Shift)));
            this.gridList.TabIndex = 0;
            // 
            // btCancel
            // 
            this.btCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btCancel.Location = new System.Drawing.Point(240, 272);
            this.btCancel.Name = "btCancel";
            this.btCancel.Size = new System.Drawing.Size(75, 23);
            this.btCancel.TabIndex = 1;
            this.btCancel.Text = "Cancel";
            // 
            // btOK
            // 
            this.btOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btOK.Location = new System.Drawing.Point(152, 272);
            this.btOK.Name = "btOK";
            this.btOK.Size = new System.Drawing.Size(75, 23);
            this.btOK.TabIndex = 2;
            this.btOK.Text = "OK";
            this.btOK.Click += new System.EventHandler(this.btOK_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(8, 4);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(308, 28);
            this.label1.TabIndex = 3;
            this.label1.Text = "Customize the available list of template files:";
            // 
            // TemplatesEditor
            // 
            this.AcceptButton = this.btOK;
            this.AccessibleName = "templatesEditor";
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btCancel;
            this.ClientSize = new System.Drawing.Size(324, 299);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btOK);
            this.Controls.Add(this.btCancel);
            this.Controls.Add(this.gridList);
            this.Name = "TemplatesEditor";
            this.Text = "Customize Templates";
            this.Load += new System.EventHandler(this.TemplatesEditor_Load);
            this.ResumeLayout(false);

        }
        #endregion

        private void TemplatesEditor_Load(object sender, System.EventArgs e)
        {
            SourceGrid2.DataModels.EditorTextBoxButton editorBtn = new SourceGrid2.DataModels.EditorTextBoxButton(typeof(string));
            editorBtn.AttachEditorControl(gridList.ScrollablePanel);
            editorBtn.GetEditorTextBoxTypedButton(gridList.ScrollablePanel).DialogOpen += new EventHandler(TemplatesEditor_DialogOpen);

            gridList.ColumnsCount = 1;
            for (int r = 0; r < AvailableTemplateFiles.Count; r++)
            {
                gridList.Rows.Insert(r);
                gridList[r, 0] = new SourceGrid2.Cells.Real.Cell(AvailableTemplateFiles[r], editorBtn);
            }

            for (int r = AvailableTemplateFiles.Count; r < AvailableTemplateFiles.Count + 20; r++)
            {
                gridList.Rows.Insert(r);
                gridList[r, 0] = new SourceGrid2.Cells.Real.Cell("", editorBtn);
            }

            gridList.AutoSizeMinHeight = gridList.Font.Height;
            gridList.AutoStretchColumnsToFitWidth = true;
            gridList.StretchColumnsToFitWidth();
        }

        private void TemplatesEditor_DialogOpen(object sender, EventArgs e)
        {
            SourceLibrary.Windows.Forms.TextBoxTypedButton txtBtn = (SourceLibrary.Windows.Forms.TextBoxTypedButton)sender;
            OpenFileDialog dlg = new OpenFileDialog();
            if (txtBtn.Value is String)
                dlg.FileName = (string)txtBtn.Value;
            dlg.Filter = "Xml Files|*.xml|All Files|*.*";
            if (dlg.ShowDialog(this) == DialogResult.OK)
            {
                txtBtn.Value = dlg.FileName;
            }
        }

        private List<String> m_AvailableTemplateFiles;

        private void btOK_Click(object sender, System.EventArgs e)
        {
            try
            {
                for (int r = 0; r < gridList.RowsCount; r++)
                {
                    string file = gridList[r, 0].DisplayText;
                    if (file != null &&
                        file.Length > 0)
                    {
                        file = file.Trim();
                        if (System.IO.File.Exists(file))
                        {
                        }
                        else
                        {
                            MessageBox.Show(this, "File not exist:" + file);
                            return;
                        }
                    }
                }

                AvailableTemplateFiles.Clear();
                for (int r = 0; r < gridList.RowsCount; r++)
                {
                    string file = gridList[r, 0].DisplayText;
                    if (file != null &&
                        file.Length > 0)
                    {
                        file = file.Trim();
                        if (System.IO.File.Exists(file))
                        {
                            if (AvailableTemplateFiles.Contains(file) == false)
                                AvailableTemplateFiles.Add(file);
                        }
                        else
                        {
                            throw new ApplicationException("Invalid file");
                        }
                    }
                }

                DialogResult = DialogResult.OK;
            }
            catch (Exception err)
            {
                SourceLibrary.Windows.Forms.ErrorDialog.Show(this, err, "Error");
            }
        }

        public List<String> AvailableTemplateFiles
        {
            get { return m_AvailableTemplateFiles; }
            set { m_AvailableTemplateFiles = value; }
        }
    }
}
