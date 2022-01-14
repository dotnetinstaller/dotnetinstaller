using System;
using System.Collections.Generic;
using System.Text;

namespace InstallerLib
{
    public enum OperatingSystem
    {
        winNone = 0,

        winXP = 75,
        winXPsp1 = 80,
        winXPsp2 = 82,
        winXPsp3 = 84,
        winXPMax = 89,

        winServer2003 = 90,
        winServer2003R2 = 91,
        winServer2003sp1 = 92,
        winServer2003R2sp1 = 93,
        winServer2003sp2 = 94,
        winServer2003R2sp2 = 95,
        winServer2003Max = 99,

        winVista = 100,
        winVistaSp1 = 102,
        winVistaSp2 = 103,
        winVistaMax = 109,

        winServer2008 = 110,
        winServer2008sp2 = 111,
        winServer2008R2 = 112,
        winServer2008R2sp1 = 113,
        winServer2008Max = 119,

        win7 = 120,
        win7sp1 = 121,
        win7Max = 129,

        win8 = 130,
        win8_1 = 131,
        win8Max = 139,

        win8Server = 140, // Windows Server 2012
        win8ServerR2 = 141, // Windows Server 2012 R2
        win8ServerMax = 149,

        win10 = 150, // build 1507
        win10_1511 = 151,
        win10_1607 = 152,
        win10_1703 = 153,
        win10_1709 = 154,
        win10_1803 = 155,
        win10_1809 = 156,
        win10_1903 = 157,
        win10_1909 = 158,
        win10_2004 = 159,
        win10_20H2 = 160,
        win10_21H1 = 161,
        win10_21H2 = 162,
        win10Max = 169,

        win10Server = 170, // Windows Server 2016
        win10ServerMax = 179,

        winServer2019 = 180,
        winServer2019Max = 189,

        winServer2022 = 190,
        winServer2022Max = 199,

        win11 = 200,
        win11Max = 209,

        winMax = 255,
    }
}
