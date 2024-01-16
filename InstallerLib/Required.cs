using System;

namespace InstallerLib
{
    // Summary:
    //     Specifies whether the property this attribute is bound to is required or
    //     optional. This class cannot be inherited
    public sealed class Required : Attribute
    {
        private bool m_required;

        // Summary:
        //     Specifies the default value for the InstallerLib.RequiredAttribute,
        //     which is InstallerLib.RequiredAttribute.No (that is, the property
        //     this attribute is optional). This static field is read-only.
        public static readonly Required Default = No;
        //
        // Summary:
        //     Specifies that the property this attribute is bound to is optional and
        //     can be cleared. This static field is read-only.
        public static readonly Required No = new Required(false);
        //
        // Summary:
        //     Specifies that the property this attribute is bound to is required and cannot
        //     be unset. This static field is read-only.
        public static readonly Required Yes = new Required(true);

        // Summary:
        //     Initializes a new instance of the InstallerLib.RequiredAttribute
        //     class.
        //
        // Parameters:
        //   isRequired:
        //     true to show that the property this attribute is bound to is required; false
        //     to show that the property is optional.
        public Required(bool isRequired)
        {
            m_required = isRequired;
        }

        public Required()
        {
            m_required = true;
        }

        // Summary:
        //     Gets a value indicating whether the property this attribute is bound to is
        //     required.
        //
        // Returns:
        //     true if the property this attribute is bound to is required; false if the
        //     property is optional.
        public bool IsRequired
        {
            get
            {
                return m_required;
            }
        }

        // Summary:
        //     Indicates whether this instance and a specified object are equal.
        //
        // Parameters:
        //   value:
        //     Another object to compare to.
        //
        // Returns:
        //     true if value is equal to this instance; otherwise, false.
        public override bool Equals(object value)
        {
            if (value is Boolean || value is bool)
                return ((bool)value == IsRequired);
            else if (value is Required)
                return (value as Required).IsRequired == IsRequired;
            else
                return false;
        }

        //
        // Summary:
        //     Returns the hash code for this instance.
        //
        // Returns:
        //     A hash code for the current InstallerLib.RequiredAttribute.
        public override int GetHashCode()
        {
            return this.IsRequired.GetHashCode();
        }

        //
        // Summary:
        //     Determines if this attribute is the default.
        //
        // Returns:
        //     true if the attribute is the default value for this attribute class; otherwise,
        //     false.
        public override bool IsDefaultAttribute()
        {
            return this == Default;
        }
    }
}
