using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing.Design;

namespace InstallerLib
{
    public abstract class ControlText : Control
    {
        public ControlText(ControlType type)
            : base(type)
        {

        }

        private string m_text = "Lorem ipsum";
        [Description("Control text.")]
        [Category("Text")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string Text
        {
            get
            {
                return m_text;
            }
            set
            {
                m_text = value;

                if (OnTextChanged != null)
                {
                    OnTextChanged(this, null);
                }
            }
        }

        private string m_font_name = "MS Shell Dlg";
        [Description("Font face name.")]
        [Category("Text")]
        [Required]
        public string FontName
        {
            get { return m_font_name; }
            set { m_font_name = value; }
        }

        private int m_font_size = 9;
        [Description("Font point size.")]
        [Category("Text")]
        [Required]
        public int FontSize
        {
            get { return m_font_size; }
            set { m_font_size = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "text", ref m_text);
            ReadAttributeValue(e, "font_name", ref m_font_name);
            ReadAttributeValue(e, "font_size", ref m_font_size);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("text", m_text);
            e.XmlWriter.WriteAttributeString("font_name", m_font_name);
            e.XmlWriter.WriteAttributeString("font_size", m_font_size.ToString());
        }

        public EventHandler OnTextChanged;
    }
}
