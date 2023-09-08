using System.ComponentModel;

namespace InstallerLib
{
    public class ControlLicense : ControlText
    {
        public ControlLicense()
            : base(ControlType.license)
        {
            Text = "I have read and accepted the license agreement.";
            DisplayUninstall = false;
        }

        private string m_resource_id = "RES_LICENSE";
        [Description("Resource id.")]
        [Category("License")]
        [Required]
        public string ResourceId
        {
            get { return m_resource_id; }
            set { m_resource_id = value; }
        }

        private bool m_accepted = false;
        [Description("Default accepted state of the license agreement checkbox.")]
        [Category("License")]
        [Required]
        public bool Accepted
        {
            get { return m_accepted; }
            set { m_accepted = value; }
        }

        private string m_accept_message = @"You must accept the license agreement.";
        [Description("Message displayed when a user attempts to install without accepting the license agreement.")]
        [Category("License")]
        [Required]
        public string AcceptMessage
        {
            get { return m_accept_message; }
            set { m_accept_message = value; }
        }

        private string m_license_file = @"#APPPATH\license.txt";
        [Description("License file.")]
        [Category("License")]
        [Required]
        public string LicenseFile
        {
            get { return m_license_file; }
            set { m_license_file = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "accepted", ref m_accepted);
            ReadAttributeValue(e, "resource_id", ref m_resource_id);
            ReadAttributeValue(e, "license_file", ref m_license_file);
            ReadAttributeValue(e, "accept_message", ref m_accept_message);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("accepted", m_accepted.ToString());
            e.XmlWriter.WriteAttributeString("resource_id", m_resource_id);
            e.XmlWriter.WriteAttributeString("license_file", m_license_file);
            e.XmlWriter.WriteAttributeString("accept_message", m_accept_message);
        }

        public override ResourceFileCollection GetResources(string supportdir)
        {
            ResourceFileCollection files = base.GetResources(supportdir);
            if (!string.IsNullOrEmpty(LicenseFile))
            {
                files.Add(m_resource_id, LicenseFile);
            }
            return files;
        }
    }
}
