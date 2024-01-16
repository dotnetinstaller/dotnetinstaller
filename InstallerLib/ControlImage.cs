using System;
using System.ComponentModel;

namespace InstallerLib
{
    public class ControlImage : Control
    {
        public ControlImage()
            : base(ControlType.image)
        {

        }

        private string m_resource_id = "RES_IMAGE";
        [Description("A unique resource ID.")]
        [Category("Image")]
        [Required]
        public string ResourceId
        {
            get { return m_resource_id; }
            set { m_resource_id = value; }
        }

        private string m_image_file = @"#APPPATH\image.bmp";
        [Description("Image file.")]
        [Category("Image")]
        [Required]
        public string ImageFile
        {
            get { return m_image_file; }
            set
            {
                m_image_file = value;
                if (OnTextChanged != null)
                {
                    OnTextChanged(this, null);
                }
            }
        }

        private bool m_center = false;
        [Description("Center the image. If the image is larger than the control, it will be clipped. If it is smaller than the control, the empty space around the image will be filled by the color of the pixel in the upper left corner of the bitmap.")]
        [Category("Image")]
        [Required]
        public bool Center
        {
            get { return m_center; }
            set { m_center = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "image_file", ref m_image_file);
            ReadAttributeValue(e, "resource_id", ref m_resource_id);
            ReadAttributeValue(e, "center", ref m_center);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("image_file", m_image_file);
            e.XmlWriter.WriteAttributeString("resource_id", m_resource_id);
            e.XmlWriter.WriteAttributeString("center", m_center.ToString());
        }

        public EventHandler OnTextChanged;

        public override ResourceFileCollection GetResources(string supportdir)
        {
            ResourceFileCollection files = base.GetResources(supportdir);
            if (!string.IsNullOrEmpty(ImageFile))
            {
                files.Add(m_resource_id, ImageFile);
            }
            return files;
        }
    }
}
