using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel;
using System.Diagnostics;
namespace Srv
{
    public partial class frmRunTusk : Form
    {
        public frmRunTusk()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(!string.IsNullOrEmpty(txtOpen.Text))
            {
                try
                {
                    Process proc = new Process();
                    proc.StartInfo.FileName = txtOpen.Text;
                    proc.Start(); 
                }
                catch(Exception ex)
                {
                    MessageBox.Show(ex.Message, "message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}
