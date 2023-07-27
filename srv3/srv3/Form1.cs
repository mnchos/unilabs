using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
namespace srv3
{
    public partial class Form1 : Form
    {
        string fileContent = string.Empty;
        string filePath = string.Empty;
        string filesavepath = string.Empty;
        public Form1()
        {
            InitializeComponent();
        }
       
       
        private async void button1_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    //Get the path of specified file
                    filePath = openFileDialog.FileName;

                    //Read the contents of the file into a stream
                    var fileStream = openFileDialog.OpenFile();

                    using (StreamReader reader = new StreamReader(fileStream))
                    {
                        fileContent = reader.ReadToEnd();
                    }
                }
            }
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            // получаем выбранный файл
            filesavepath = saveFileDialog1.FileName;
            // сохраняем текст в файл
            MessageBox.Show(filesavepath);
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            string UserDirectory = filePath;

            using (StreamReader SourceReader = File.OpenText(UserDirectory))
            {
                using (StreamWriter DestinationWriter = File.CreateText(filesavepath))
                {
                    await CopyFilesAsync(SourceReader, DestinationWriter);
                }
            }
        }
        public async Task CopyFilesAsync(StreamReader Source, StreamWriter Destination)
        {
            char[] buffer = new char[0x1000];
            int numRead;
            while ((numRead = await Source.ReadAsync(buffer, 0, buffer.Length)) != 0)         
            {
                string test = new string(buffer);
                listBox1.Items.Add(test);
                await Destination.WriteAsync(buffer, 0, numRead);
            }
        }
    }
}
