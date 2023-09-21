using System;
using System.Windows.Forms;

namespace TestTimer
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new TestTimerForm());
        }
    }
}