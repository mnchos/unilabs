using System.Collections.Generic;

using System.Windows;

using System.Windows.Controls;

using System.Windows.Media;

using System;

using System.Linq;

using System.Text;

using System.Windows.Data;

using System.Windows.Documents;

using System.Windows.Input;

using System.Windows.Media.Imaging;

using System.Windows.Navigation;

using System.Windows.Shapes;

using System.Collections.ObjectModel;

using System.IO;

namespace WpfApplication3

{

    public partial class MainWindow : Window

    {

        public MainWindow()

        {

            InitializeComponent();

        }

        private void Stephen(object sender, RoutedEventArgs e)

        {

            try

            {

                double digit01 = Convert.ToDouble(digitbox.Text.Trim());

                double digit02 = Convert.ToDouble(digitbox2.Text.Trim());

                double result = Convert.ToDouble(Math.Pow(digit01, digit02));

                resultbox.Text = result.ToString();

            }

            catch (Exception ex)

            {

                MessageBox.Show(ex.Message);

            }

        }

        private void Quad(object sender, RoutedEventArgs e)

        {

            try

            {

                double digit01 = Convert.ToDouble(digitbox.Text.Trim());

                double result = Convert.ToDouble(Math.Sqrt(digit01));

                resultbox.Text = result.ToString();

            }

            catch (Exception ex)

            {

                MessageBox.Show(ex.Message);

            }

        }

        private void Factorial(object sender, RoutedEventArgs e)

        {

            try

            {

                double digit01 = Convert.ToDouble(digitbox.Text.Trim());

                double result = 1;

                for (int i = 2; i <= digit01; i++)

                {

                    result = result * i;

                }

                resultbox.Text = result.ToString();

            }

            catch (Exception ex)

            {

                MessageBox.Show(ex.Message);

            }

        }

    }

}