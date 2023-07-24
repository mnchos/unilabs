using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Based
{
    public partial class Form1 : Form

    {
        SqlConnection sqlConnection;

        int last = 0;

        public Form1()

        {

            InitializeComponent();
        }

        private async void Form1_Load(object sender, EventArgs e)

        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Спортивный_клуб". При необходимости она может быть перемещена или удалена.
            this.спортивный_клубTableAdapter.Fill(this.спортDataSet5.Спортивный_клуб);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_результатов". При необходимости она может быть перемещена или удалена.
            this.представление_результатовTableAdapter.Fill(this.спортDataSet5.Представление_результатов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_результатов_весеннего_турнира". При необходимости она может быть перемещена или удалена.
            this.представление_результатов_весеннего_турнираTableAdapter.Fill(this.спортDataSet5.Представление_результатов_весеннего_турнира);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet10.Представление_результатов_летней_универсиады". При необходимости она может быть перемещена или удалена.
            this.представление_результатов_летней_универсиадыTableAdapter.Fill(this.спортDataSet10.Представление_результатов_летней_универсиады);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet10.Представление_результатов_зимнего_универсиады". При необходимости она может быть перемещена или удалена.
            this.представление_результатов_зимнего_универсиадыTableAdapter.Fill(this.спортDataSet10.Представление_результатов_зимнего_универсиады);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet10.Представление_всех_результатов". При необходимости она может быть перемещена или удалена.
            this.представление_всех_результатовTableAdapter.Fill(this.спортDataSet10.Представление_всех_результатов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_прыжков_в_высоту". При необходимости она может быть перемещена или удалена.
            this.представление_прыжков_в_высотуTableAdapter.Fill(this.спортDataSet5.Представление_прыжков_в_высоту);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_бега". При необходимости она может быть перемещена или удалена.
            this.представление_бегаTableAdapter.Fill(this.спортDataSet5.Представление_бега);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_всех_результатов". При необходимости она может быть перемещена или удалена.
            this.представление_всех_результатовTableAdapter.Fill(this.спортDataSet5.Представление_всех_результатов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Представление_прыжков_в_длинну". При необходимости она может быть перемещена или удалена.
            this.представление_прыжков_в_длиннуTableAdapter.Fill(this.спортDataSet5.Представление_прыжков_в_длинну);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet9.Просмотр_Анализа_спортсменов". При необходимости она может быть перемещена или удалена.
            this.просмотр_Анализа_спортсменовTableAdapter.Fill(this.спортDataSet9.Просмотр_Анализа_спортсменов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet9.Представление_разрядов_спортсменов". При необходимости она может быть перемещена или удалена.
            this.представление_разрядов_спортсменовTableAdapter.Fill(this.спортDataSet9.Представление_разрядов_спортсменов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet8.Представление_разрядов_спортсменов". При необходимости она может быть перемещена или удалена.
            this.представление_разрядов_спортсменовTableAdapter.Fill(this.спортDataSet8.Представление_разрядов_спортсменов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet7.Представление_разрядов". При необходимости она может быть перемещена или удалена.
            this.представление_разрядовTableAdapter.Fill(this.спортDataSet7.Представление_разрядов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet6.Представление_спортсменов". При необходимости она может быть перемещена или удалена.
            this.представление_спортсменовTableAdapter.Fill(this.спортDataSet6.Представление_спортсменов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet5.Просмотр_регистрации_клубов". При необходимости она может быть перемещена или удалена.
            this.просмотр_регистрации_клубовTableAdapter.Fill(this.спортDataSet5.Просмотр_регистрации_клубов);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet.Просмотр_регистрации_на_события". При необходимости она может быть перемещена или удалена.
            this.просмотр_регистрации_на_событияTableAdapter.Fill(this.спортDataSet.Просмотр_регистрации_на_события);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet4.Просмотр_Спортсменов_с_Разрядом". При необходимости она может быть перемещена или удалена.
            this.просмотр_Спортсменов_с_РазрядомTableAdapter.Fill(this.спортDataSet4.Просмотр_Спортсменов_с_Разрядом);

            // TODO: данная строка кода позволяет загрузить данные в таблицу "спортDataSet.Просмотр_регистраций_спортсменов". При необходимости она может быть перемещена или удалена.
            this.просмотр_регистраций_спортсменовTableAdapter.Fill(this.спортDataSet.Просмотр_регистраций_спортсменов);


            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";

            sqlConnection = new SqlConnection(connectionString);
            await sqlConnection.OpenAsync();
            SqlDataReader sqlReader = null;
            SqlCommand command = new SqlCommand("SELECT * FROM Представление_разрядов", sqlConnection);
            try
            {
                sqlReader = await command.ExecuteReaderAsync();
                while (await sqlReader.ReadAsync())
                {
                    listBox1.Items.Add(Convert.ToString(sqlReader["Разряд"]) + ":" + Convert.ToString(sqlReader["Количество_Спортсменов_с_Разрядом"]) );
                }
            }
            catch (Exception ex1)
            {
                MessageBox.Show(ex1.Message.ToString(), ex1.Source.ToString(), MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
            finally
            {
                if (sqlReader != null)

                    sqlReader.Close();
            }

        }

        private void выхходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (sqlConnection != null && sqlConnection.State != ConnectionState.Connecting)
                sqlConnection.Close();
            Application.Exit();
        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private async void button1_Click(object sender, EventArgs e)
        {

            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label16.Visible)
            { label16.Visible = false; }
            if (!string.IsNullOrEmpty(textBox1.Text) && !string.IsNullOrWhiteSpace(textBox1.Text) && !string.IsNullOrEmpty(textBox2.Text) && !string.IsNullOrWhiteSpace(textBox2.Text) &&
        !string.IsNullOrEmpty(textBox3.Text) && !string.IsNullOrWhiteSpace(textBox3.Text) && !string.IsNullOrEmpty(textBox4.Text) && !string.IsNullOrWhiteSpace(textBox4.Text)
            && !string.IsNullOrEmpty(textBox5.Text) && !string.IsNullOrWhiteSpace(textBox5.Text) && !string.IsNullOrEmpty(textBox6.Text) && !string.IsNullOrWhiteSpace(textBox6.Text) &&
            !string.IsNullOrEmpty(textBox7.Text) && !string.IsNullOrWhiteSpace(textBox7.Text))
            {
                string sqlExpression = "Новый_спортсмен_с_разрядом";
                SqlCommand command = new SqlCommand(sqlExpression, sqlConnection);
                command.CommandType = System.Data.CommandType.StoredProcedure;
                command.Parameters.AddWithValue("@Имя", textBox1.Text);
                command.Parameters.AddWithValue("@Фамилия", textBox2.Text);
                command.Parameters.AddWithValue("@Отчетсво", textBox3.Text);
                command.Parameters.AddWithValue("@Клуб", Convert.ToInt32(textBox4.Text));
                command.Parameters.AddWithValue("@Разряд", textBox5.Text);
                command.Parameters.AddWithValue("@Дата_разряда", Convert.ToDateTime(textBox6.Text));
                command.Parameters.AddWithValue("@ID_Вид_спорта", Convert.ToInt32(textBox7.Text));
                await command.ExecuteNonQueryAsync();
            }
            else
            {
                label16.Visible = true;
                label16.Text = "Проверьте правильность заполнения полей";
            }
        }


        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }
        private async void button2_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label17.Visible)
            { label17.Visible = false; }
            if (!string.IsNullOrEmpty(textBox8.Text) && !string.IsNullOrWhiteSpace(textBox8.Text) && !string.IsNullOrEmpty(textBox9.Text) && !string.IsNullOrWhiteSpace(textBox9.Text) &&
        !string.IsNullOrEmpty(textBox10.Text) && !string.IsNullOrWhiteSpace(textBox10.Text))
            {
                try
                {
                    SqlCommand command = new SqlCommand($"INSERT INTO [Регистрация_спортсмена](Дата_регистрации,ID_События,ID_Спортсмена) VALUES (@Дата,@Событие,@Спортсмен)", sqlConnection);

                    DateTime date = DateTime.Parse(textBox8.Text);
                    command.Parameters.AddWithValue("@Дата", $"{date.Day}/{date.Month}/{date.Year}");
                    command.Parameters.AddWithValue("@Событие", Convert.ToInt32(textBox10.Text));
                    command.Parameters.AddWithValue("@Спортсмен", Convert.ToInt32(textBox9.Text));
                    await command.ExecuteNonQueryAsync();
                }
                catch(Exception ex)
                {
                    label17.Visible = true;                   
                    label17.Text = ex.Message.ToString();
                }
            }
            else
            {
                label17.Visible = true;
                label17.Text = "Проверьте правильность заполнения полей";
            }
        }
        private async void обновитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            this.спортивный_клубTableAdapter.Fill(this.спортDataSet5.Спортивный_клуб);
            this.представление_результатовTableAdapter.Fill(this.спортDataSet5.Представление_результатов);
            this.представление_результатов_весеннего_турнираTableAdapter.Fill(this.спортDataSet5.Представление_результатов_весеннего_турнира);
            this.представление_результатов_летней_универсиадыTableAdapter.Fill(this.спортDataSet10.Представление_результатов_летней_универсиады);
            this.представление_результатов_зимнего_универсиадыTableAdapter.Fill(this.спортDataSet10.Представление_результатов_зимнего_универсиады);
            this.представление_всех_результатовTableAdapter.Fill(this.спортDataSet10.Представление_всех_результатов);
            this.представление_прыжков_в_высотуTableAdapter.Fill(this.спортDataSet5.Представление_прыжков_в_высоту);
            this.представление_бегаTableAdapter.Fill(this.спортDataSet5.Представление_бега);
            this.представление_всех_результатовTableAdapter.Fill(this.спортDataSet5.Представление_всех_результатов);
            this.представление_прыжков_в_длиннуTableAdapter.Fill(this.спортDataSet5.Представление_прыжков_в_длинну);
            this.просмотр_Анализа_спортсменовTableAdapter.Fill(this.спортDataSet9.Просмотр_Анализа_спортсменов);
            this.представление_разрядов_спортсменовTableAdapter.Fill(this.спортDataSet9.Представление_разрядов_спортсменов);
            this.представление_разрядов_спортсменовTableAdapter.Fill(this.спортDataSet8.Представление_разрядов_спортсменов);
            this.представление_разрядовTableAdapter.Fill(this.спортDataSet7.Представление_разрядов);
            this.представление_спортсменовTableAdapter.Fill(this.спортDataSet6.Представление_спортсменов);
            this.просмотр_регистрации_клубовTableAdapter.Fill(this.спортDataSet5.Просмотр_регистрации_клубов);
            this.просмотр_регистрации_на_событияTableAdapter.Fill(this.спортDataSet.Просмотр_регистрации_на_события);
            this.просмотр_Спортсменов_с_РазрядомTableAdapter.Fill(this.спортDataSet4.Просмотр_Спортсменов_с_Разрядом);
            this.просмотр_регистраций_спортсменовTableAdapter.Fill(this.спортDataSet.Просмотр_регистраций_спортсменов);
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";

            sqlConnection = new SqlConnection(connectionString);
            await sqlConnection.OpenAsync();
            SqlDataReader sqlReader = null;
            SqlCommand command = new SqlCommand("SELECT * FROM Представление_разрядов", sqlConnection);
            try
            {
                sqlReader = await command.ExecuteReaderAsync();
                while (await sqlReader.ReadAsync())
                {
                    listBox1.Items.Add(Convert.ToString(sqlReader["Разряд"]) + ":" + Convert.ToString(sqlReader["Количество_Спортсменов_с_Разрядом"]));
                }
            }
            catch (Exception ex1)
            {
                MessageBox.Show(ex1.Message.ToString(), ex1.Source.ToString(), MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                if (sqlReader != null)

                    sqlReader.Close();
            }
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private async void button3_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label17.Visible)
            { label17.Visible = false; }
            if (!string.IsNullOrEmpty(textBox11.Text) && !string.IsNullOrWhiteSpace(textBox11.Text) && !string.IsNullOrEmpty(textBox12.Text) && !string.IsNullOrWhiteSpace(textBox12.Text) &&
        !string.IsNullOrEmpty(textBox13.Text) && !string.IsNullOrWhiteSpace(textBox13.Text))
            {
                SqlCommand command = new SqlCommand($"INSERT INTO [Регистрация_клуба](Дата_Регистрации,ID_Спортивного_мероприятия,ID_Клуба) VALUES (@Дата,@Мероприятие,@Клуб)", sqlConnection);
                DateTime date = DateTime.Parse(textBox11.Text);
                command.Parameters.AddWithValue("@Дата", $"{date.Day}/{date.Month}/{date.Year}");
                command.Parameters.AddWithValue("@Мероприятие", Convert.ToInt32(textBox13.Text));
                command.Parameters.AddWithValue("@Клуб", Convert.ToInt32(textBox12.Text));
                await command.ExecuteNonQueryAsync();
            }
            else
            {
                label17.Visible = true;
                label17.Text = "Проверьте правильность заполнения полей";
            }
        } 
            private async void button4_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label16.Visible)
            { label16.Visible = false; }
            if (!string.IsNullOrEmpty(textBox1.Text) && !string.IsNullOrWhiteSpace(textBox1.Text) && !string.IsNullOrEmpty(textBox2.Text) && !string.IsNullOrWhiteSpace(textBox2.Text) &&
        !string.IsNullOrEmpty(textBox3.Text) && !string.IsNullOrWhiteSpace(textBox3.Text) && !string.IsNullOrEmpty(textBox4.Text) && !string.IsNullOrWhiteSpace(textBox4.Text))
            {
                string sqlExpression = "Новый_спортсмен";
                SqlCommand command = new SqlCommand(sqlExpression, sqlConnection);
                command.CommandType = System.Data.CommandType.StoredProcedure;
                command.Parameters.AddWithValue("@Имя", textBox1.Text);
                command.Parameters.AddWithValue("@Фамилия", textBox2.Text);
                command.Parameters.AddWithValue("@Отчетсво", textBox3.Text);
                command.Parameters.AddWithValue("@Клуб", Convert.ToInt32(textBox4.Text));                
                await command.ExecuteNonQueryAsync();
            }
            else
            {
                label16.Visible = true;
                label16.Text = "Проверьте правильность заполнения полей";
            }
        }

        private async void button5_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label16.Visible)
            { label16.Visible = false; }
            if (!string.IsNullOrEmpty(textBox14.Text) && !string.IsNullOrWhiteSpace(textBox14.Text))
            {
                SqlCommand command = new SqlCommand($"DELETE FROM [Спортсмен] WHERE [ID_Спортсмена]=@ID", sqlConnection);               
                command.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox14.Text));
                await command.ExecuteNonQueryAsync();
            }
            else
            {
                label16.Visible = true;
                label16.Text = "Введите ID Спортсмена";
            }
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private async void button6_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=DESKTOP-4HMH34R;Initial Catalog=Спорт;Integrated Security=True";
            using (SqlConnection sqlConnection = new SqlConnection(connectionString)) ;
            if (label16.Visible)
            { label16.Visible = false; }
            if (!string.IsNullOrEmpty(textBox15.Text) && !string.IsNullOrWhiteSpace(textBox15.Text))
            {
                int kol = 0;
                SqlCommand command = new SqlCommand("Новый_клуб", sqlConnection);
                command.CommandType = System.Data.CommandType.StoredProcedure;
                command.Parameters.AddWithValue("@Название",textBox15.Text);
                command.Parameters.AddWithValue("@Количество", kol);
                await command.ExecuteNonQueryAsync();
            }    
            else
            {
                label16.Visible = true;
                label16.Text = "Введите название клуба";
            }
        }
    }
}