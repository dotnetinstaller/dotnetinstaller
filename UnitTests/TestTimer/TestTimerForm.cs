using System;
using System.Windows.Forms;

namespace TestTimer
{
    public partial class TestTimerForm : Form
    {
        public TestTimerForm()
        {
            InitializeComponent();
        }

        private void closingTimer_Tick(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}