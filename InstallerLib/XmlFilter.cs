using System;
using System.Collections.Generic;
using System.Text;

namespace InstallerLib
{
    public interface XmlFilter
    {
        bool IsSupported(XmlClass clazz);
    }
}
