using System;
using System.Xml;
using System.ComponentModel;
using System.Drawing;

namespace InstallerLib
{
    /// <summary>
    /// Control type.
    /// </summary>
    public enum ControlType
    {
        /// <summary>
        /// Undefined.
        /// </summary>
        undefined,
        /// <summary>
        /// Label with static text.
        /// </summary>
        label,
        /// <summary>
        /// Checkbox.
        /// </summary>
        checkbox,
        /// <summary>
        /// Edit box.
        /// </summary>
        edit,
        /// <summary>
        /// Browse for file or folder button.
        /// </summary>
        browse,
        /// <summary>
        /// License checkbox and link.
        /// </summary>
        license,
        /// <summary>
        /// Hyperlink.
        /// </summary>
        hyperlink,
        /// <summary>
        /// Image.
        /// </summary>
        image
    }

    /// <summary>
    /// Controls whether the nested installed check applies to control's enabled, display or both properties.
    /// </summary>
    public enum ControlCheckType
    {
        /// <summary>
        /// Apply to the enabled property.
        /// </summary>
        enabled,
        /// <summary>
        /// Apply to the display property.
        /// </summary>
        display,
        /// <summary>
        /// Apply to both enabled and display property.
        /// </summary>
        both
    };

    /// <summary>
    /// A dynamic dialog control.
    /// </summary>
    [XmlChild(typeof(InstalledCheck))]
    [XmlChild(typeof(InstalledCheckOperator))]
    public abstract class Control : XmlClass
    {
        public Control(ControlType type)
        {
            m_type = type;
        }

        private ControlType m_type = ControlType.undefined;
        [Description("Control type.")]
        [Required]
        public ControlType type
        {
            get
            {
                return m_type;
            }
        }

        private Rectangle m_position;
        [Description("Control position and size.")]
        [Category("Layout")]
        public Rectangle Position
        {
            get { return m_position; }
            set { m_position = value; }
        }

        private bool m_enabled = true;
        [Description("Default enabled state.")]
        [Category("Layout")]
        [Required]
        public bool Enabled
        {
            get { return m_enabled; }
            set { m_enabled = value; }
        }

        private bool m_has_value_disabled = false;
        [Description("When 'true', collect value even if the control is disabled.")]
        [Category("Value")]
        [Required]
        public bool HasValueDisabled
        {
            get { return m_has_value_disabled; }
            set { m_has_value_disabled = value; }
        }

        private bool m_display_install = true;
        [Description("Display control on install.")]
        [Category("Layout")]
        [Required]
        public bool DisplayInstall
        {
            get { return m_display_install; }
            set { m_display_install = value; }
        }

        private bool m_display_uninstall = true;
        [Description("Display control on uninstall.")]
        [Category("Layout")]
        [Required]
        public bool DisplayUninstall
        {
            get { return m_display_uninstall; }
            set { m_display_uninstall = value; }
        }

        private ControlCheckType m_check = ControlCheckType.enabled;
        [Description("Defines how to apply a nested installed check ('enable', 'display' or 'both').")]
        [Category("Layout")]
        [Required]
        public ControlCheckType Check
        {
            get { return m_check; }
            set { m_check = value; }
        }

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "control"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("type", m_type.ToString());
            e.XmlWriter.WriteAttributeString("position", XmlRectangle.ToString(m_position));
            e.XmlWriter.WriteAttributeString("enabled", m_enabled.ToString());
            e.XmlWriter.WriteAttributeString("display_install", m_display_install.ToString());
            e.XmlWriter.WriteAttributeString("display_uninstall", m_display_uninstall.ToString());
            e.XmlWriter.WriteAttributeString("check", m_check.ToString());
            e.XmlWriter.WriteAttributeString("has_value_disabled", m_has_value_disabled.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            // type
            ControlType type = ControlType.undefined;
            ReadAttributeValue(e, "type", ref type);
            if (type != m_type)
            {
                throw new Exception(string.Format("Unexpected type: {0}", type));
            }
            // other
            ReadAttributeValue(e, "position", ref m_position);
            ReadAttributeValue(e, "enabled", ref m_enabled);
            ReadAttributeValue(e, "display_install", ref m_display_install);
            ReadAttributeValue(e, "display_uninstall", ref m_display_uninstall);
            ReadAttributeValue(e, "check", ref m_check);
            ReadAttributeValue(e, "has_value_disabled", ref m_has_value_disabled);
            base.OnXmlReadTag(e);
        }

        public static Control CreateFromXml(XmlElement element)
        {
            string xmltype = element.Attributes["type"].InnerText;
            Control control = null;
            ControlType type = (ControlType)Enum.Parse(typeof(ControlType), xmltype);
            switch (type)
            {
                case ControlType.label:
                    control = new ControlLabel();
                    break;
                case ControlType.checkbox:
                    control = new ControlCheckBox();
                    break;
                case ControlType.edit:
                    control = new ControlEdit();
                    break;
                case ControlType.browse:
                    control = new ControlBrowse();
                    break;
                case ControlType.license:
                    control = new ControlLicense();
                    break;
                case ControlType.hyperlink:
                    control = new ControlHyperlink();
                    break;
                case ControlType.image:
                    control = new ControlImage();
                    break;
                default:
                    throw new Exception(string.Format("Invalid type: {0}", xmltype));
            }
            control.FromXml(element);
            return control;
        }
    }
}
