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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Process[] proc;

        void GetAllProcess()
        {
            proc = Process.GetProcesses();
            listbox.Items.Clear();
            foreach (Process p in proc)
            {
                listbox.Items.Add(p.ProcessName);               
            }
           
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            GetAllProcess();
        }

        private void btnEndTask_Click(object sender, EventArgs e)
        {
            try
            {
                proc[listbox.SelectedIndex].Kill();
                GetAllProcess();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void runNewTuskToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using(frmRunTusk frm=new frmRunTusk())
            {
                if (frm.ShowDialog() == DialogResult.OK)
                    GetAllProcess();
            }
        }
    }
}
