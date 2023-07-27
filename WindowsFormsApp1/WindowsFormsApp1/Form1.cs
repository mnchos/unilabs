using System;

using System.Collections.Generic;

using System.ComponentModel;

using System.Data;

using System.Drawing;

using System.Linq;

using System.Text;

using System.Threading.Tasks;

using System.Windows.Forms;

namespace sii_5

{

    public partial class Form1 : Form

    {

        public Form1()

        {

            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e)

        {

        }

        private void button1_Click(object sender, EventArgs e) //button обучить

        {

            Random rnd = new Random();

            for (int iter = 0; iter < 500000; iter++)

            {

                int randint = rnd.Next(0, 4);

                for (int i = 0; i < 4; i++)

                {

                    for (int j = 0; j < 25; j++)

                    {

                        Program.Weght[i, j] += 0.1 * Program.Train[randint, j] * Program.y[randint, i];

                    }

                }

            }

        }

        private void button2_Click(object sender, EventArgs e) // веса

        {

            dataGridView1.RowCount = 4;

            dataGridView1.ColumnCount = 25;

            for (int i = 0; i < 4; i++)

            {

                for (int j = 0; j < 25; j++)

                {

                    dataGridView1.Rows[i].Cells[j].Value = Program.Weght[i, j];

                }

            }

        }

        private void button3_Click(object sender, EventArgs e) //C

        {

            int index = 0;

            double[] sum = { 0, 0, 0, 0 };

            for (int i = 0; i < 4; i++)

            {

                for (int j = 0; j < 25; j++)

                {

                    sum[i] += Program.MatrN[0, j] * Program.Weght[i, j];

                }

            }

            double max = sum[0];

            for (int k = 0; k < sum.Length; k++)

            {

                if (sum[k] > max)

                {

                    max = sum[k];

                    index = k;

                }

            }

            if (index == 0)

                MessageBox.Show("Это Н?");

            if (index == 1)

                MessageBox.Show("Это И?");

            if (index == 2)

                MessageBox.Show("Это М?");

            if (index == 3)

                MessageBox.Show("Это О?");

        }

        private void button4_Click(object sender, EventArgs e)

        {

            int index = 0;

            double[] sum = { 0, 0, 0, 0 };

            for (int i = 0; i < 4; i++)

            {

                for (int j = 0; j < 25; j++)

                {

                    sum[i] += Program.MatrI[0, j] * Program.Weght[i, j];

                }

            }

            double max = sum[0];

            for (int k = 0; k < sum.Length; k++)

            {

                if (sum[k] > max)

                {

                    max = sum[k];

                    index = k;

                }

            }

            if (index == 0)

                MessageBox.Show("Это Н?");

            if (index == 1)

                MessageBox.Show("Это И?");

            if (index == 2)

                MessageBox.Show("Это М?");

            if (index == 3)

                MessageBox.Show("Это О?");

        }

        private void button5_Click(object sender, EventArgs e)

        {

            int index = 0;

            double[] sum = { 0, 0, 0, 0 };

            for (int i = 0; i < 4; i++)

            {

                for (int j = 0; j < 25; j++)

                {

                    sum[i] += Program.MatrM[0, j] * Program.Weght[i, j];

                }

            }

            double max = sum[0];

            for (int k = 0; k < sum.Length; k++)

            {

                if (sum[k] > max)

                {

                    max = sum[k];

                    index = k;

                }

            }

            if (index == 0)

                MessageBox.Show("Это Н?");

            if (index == 1)

                MessageBox.Show("Это И?");

            if (index == 2)

                MessageBox.Show("Это М?");

            if (index == 3)

                MessageBox.Show("Это О?");

        }

        private void button6_Click(object sender, EventArgs e)

        {

            int index = 0;

            double[] sum = { 0, 0, 0, 0 };

            for (int i = 0; i < 4; i++)

            {

                for (int j = 0; j < 25; j++)

                {

                    sum[i] += Program.MatrO[0, j] * Program.Weght[i, j];

                }

            }

            double max = sum[0];

            for (int k = 0; k < sum.Length; k++)

            {

                if (sum[k] > max)

                {

                    max = sum[k];

                    index = k;

                }

            }

            if (index == 0)

                MessageBox.Show("Это Н?");

            if (index == 1)

                MessageBox.Show("Это И?");

            if (index == 2)

                MessageBox.Show("Это М?");

            if (index == 3)

                MessageBox.Show("Это О?");

        }

    }

}