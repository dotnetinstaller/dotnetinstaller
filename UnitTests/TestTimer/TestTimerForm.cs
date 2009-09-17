using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
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