using System;
using System.ComponentModel;

namespace InstallerLib
{
    public class RequiredPropertyDescriptor : PropertyDescriptor
    {
        PropertyDescriptor m_basePropertyDescriptor;

        public RequiredPropertyDescriptor(PropertyDescriptor basePropertyDescriptor)
            : base(basePropertyDescriptor)
        {
            this.m_basePropertyDescriptor = basePropertyDescriptor;
        }

        public override string DisplayName
        {
            get
            {
                return m_basePropertyDescriptor.DisplayName + " *";
            }
        }

        public override bool CanResetValue(object component)
        {
            return m_basePropertyDescriptor.CanResetValue(component);
        }

        public override Type ComponentType
        {
            get
            {
                return m_basePropertyDescriptor.ComponentType;
            }
        }

        public override object GetValue(object component)
        {
            return m_basePropertyDescriptor.GetValue(component);
        }

        public override bool IsReadOnly
        {
            get
            {
                return m_basePropertyDescriptor.IsReadOnly;
            }
        }

        public override Type PropertyType
        {
            get
            {
                return m_basePropertyDescriptor.PropertyType;
            }
        }

        public override void ResetValue(object component)
        {
            m_basePropertyDescriptor.ResetValue(component);
        }

        public override void SetValue(object component, object value)
        {
            if (value == null || string.IsNullOrEmpty(value.ToString()))
            {
                throw new ArgumentException("A value is required for '" + m_basePropertyDescriptor.DisplayName + "'");
            }

            m_basePropertyDescriptor.SetValue(component, value);
        }

        public override bool ShouldSerializeValue(object component)
        {
            return m_basePropertyDescriptor.ShouldSerializeValue(component);
        }
    }
}
