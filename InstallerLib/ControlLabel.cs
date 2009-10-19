using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing.Design;

namespace InstallerLib
{
    public class ControlLabel : ControlText
    {
        public ControlLabel()
            : base(ControlType.label)
        {

        }
    }
}
