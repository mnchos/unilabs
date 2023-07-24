using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using Microsoft.Win32;
using System.Diagnostics;
namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        List<string> list = new List<string>();
        
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Aboba.Items.Clear();
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            var fileContent = string.Empty;
            var filePath = string.Empty;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";

            if (openFileDialog.ShowDialog() == true) ;
            filePath = openFileDialog.FileName;
            var fileStream = openFileDialog.OpenFile();
            fileContent = File.ReadAllText(filePath);
            string[] words=fileContent.Split(' ', '.', ',', '!', '?', '/', '\t', '\n');          
           foreach (string strTemp in words)
           {
             string str = strTemp;
                if (!list.Contains(str))
                {
                    list.Add(str);
                    Aboba.Items.Add(str);
                }
           }
            stopWatch.Stop();
            
       
        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                int max = Convert.ToInt32(jija.Text);


                Aboba.Items.Clear();
                string[] arr2;
                arr2 = list.ToArray();
                for (int i = 0; i < list.Count - 1; i++)
                {
                    for (int j = i; j < list.Count - 1; j++)
                    {
                        if (i != j)
                        {
                            int schet = Distance(arr2[i], arr2[j]);
                            if (schet <= max)
                            {
                                Aboba.Items.Add("Расстояние между словами: " + arr2[i] + " и " + arr2[j] + " = " + schet);
                            }
                        }
                    }
                }

            }
            catch { }
        }
        public static int Distance(string str1Param, string str2Param)
        {
            if ((str1Param == null) || (str2Param == null)) return -1;
            int str1Len = str1Param.Length;
            int str2Len = str2Param.Length;
            //Если хотя бы одна строка пустая, возвращается длина другой строки
            if ((str1Len == 0) && (str2Len == 0)) return 0;
            if (str1Len == 0) return str2Len;
            if (str2Len == 0) return str1Len;
            //Приведение строк к верхнему регистру
            string str1 = str1Param.ToUpper();
            string str2 = str2Param.ToUpper();
            //Объявление матрицы
            int[,] matrix = new int[str1Len + 1, str2Len + 1];
            //Инициализация нулевой строки и нулевого столбца матрицы
            for (int i = 0; i <= str1Len; i++) matrix[i, 0] = i;
            for (int j = 0; j <= str2Len; j++) matrix[0, j] = j;

            //Вычисление расстояния Дамерау-Левенштейна
            for (int i = 1; i <= str1Len; i++)
            {
                for (int j = 1; j <= str2Len; j++)
                {
                    //Эквивалентность символов, переменная symbEqual соответствует m(s1[i], s2[j])
                    int symbEqual = ((str1.Substring(i - 1, 1) == str2.Substring(j
                    - 1, 1)) ? 0 : 1);
                    int ins = matrix[i, j - 1] + 1; //Добавление
                    int del = matrix[i - 1, j] + 1; //Удаление
                    int subst = matrix[i - 1, j - 1] + symbEqual; //Замена
                                                                  //Элемент матрицы вычисляется как минимальный из трех случаев
                    matrix[i, j] = Math.Min(Math.Min(ins, del), subst);
                    //Дополнение Дамерау по перестановке соседних символов
                    if ((i > 1) && (j > 1) &&
                     (str1.Substring(i - 1, 1) == str2.Substring(j - 2, 1)) &&
                     (str1.Substring(i - 2, 1) == str2.Substring(j - 1, 1)))
                    {
                        matrix[i, j] = Math.Min(matrix[i, j], matrix[i - 2, j - 2]
                       + symbEqual);
                    }
                }
            }
            //Возвращается нижний правый элемент матрицы
            return matrix[str1Len, str2Len];
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Aboba.Items.Clear();
            string [] arr2 ;
            arr2 = list.ToArray();
                for (int i=0;i<list.Count-1;i++)
                { 
                for(int j = i; j < list.Count-1; j++)
                    {
                    if (i != j)
                    {
                        int schet = Distance(arr2[i], arr2[j]);
                        Aboba.Items.Add("Расстояние между словами: " + arr2[i] + " и " + arr2[j] + " = " + schet);
                    }
                    }
                }
        }

        private void jija_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
