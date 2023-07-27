using System;
using System.Linq;
using System.Collections.Generic;
namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] chekarray=new int [n];
            int[] cheked = new int[n];
            int[] myArray = new int[n];
            for (int i=0;i<n;i++)
            {
                myArray[i] =Convert.ToInt32(Console.ReadLine());
            }
            int counter1 = 0;
            int counter2 = 0;
            PrintDublicates_HashSet(myArray);
        }
        static void PrintDublicates_HashSet(int[] n)
        {
            var set = new HashSet<int>();
            foreach (var item in n)
                if (!set.Add(item))
                    Console.WriteLine(item);
        }
    }
}
