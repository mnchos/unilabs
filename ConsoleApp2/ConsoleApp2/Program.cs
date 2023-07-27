 
using System;
using System.Security.Cryptography;
using System.Text;
using System.Numerics;

namespace ConsoleApp2
{
    
    class Program
    {
        static void Main(string[] args)
        {
            long[] resutdvoy;

            Console.WriteLine("Введите p");
            int p = Convert.ToInt32(Console.ReadLine()) - 1;
            Console.WriteLine("Введите q");
            int q = Convert.ToInt32(Console.ReadLine()) - 1;
            int s = 0;
           s=findkey(p, q, s);
            for (int i = 15; i < 100; i++)
            {
                s = i;
                if (NOD(s, p) == 1 && NOD(s, q) == 1)
                { Console.WriteLine("Открытый ключ={0} ", s); break; }

            }
            int x1 = p * q;

            int x;
            int y;
            Console.WriteLine("НОД(X,S): " + Gcd(x1, s, out x, out y));

            Console.WriteLine("Закрытый ключ t=: " + x);        
            resutdvoy = Step(s);
            int[] shortnum=new int[32];
            for (int i = 0; i < 32; i++)
            {
                if (resutdvoy[i] != 0)
                {
                    shortnum[i] = Convert.ToInt32(Math.Pow(2, i));
                }         
            }                            
            Console.WriteLine("Введите число для шифрования");
          //  Console.WriteLine("------------------");
          int[] massost = new int[32];
            long j = 0;
            long mod = (p+1) * (q+1) ;
            long encrypt = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("------------------");
            for (int i=0;i<shortnum.Length;i++)
            {
                if (shortnum[i]!=0)
                {
                    massost[j]=( Convert.ToInt32((Math.Pow(encrypt, shortnum[i])) % mod));
                    j++;
                }                
            }
          /*  Console.WriteLine("--------shortnum----------");
            for (int i = 0; i < 32; i++)
            {
                Console.WriteLine(shortnum[i]);
            }
            Console.WriteLine("------------------");
            Console.WriteLine("massost");
            Console.WriteLine("------------------");
            for (int i = 0; i < 32; i++)
            {
                Console.WriteLine(massost[i]);
            }*/
            Console.WriteLine("------------------");
            long shifr =1;
            for (int i = 0; i < massost.Length; i++)
            {
                if (massost[i] == 0)
                    break;
                else
                {
                    shifr = shifr * massost[i];
                }
            }
            
            Console.WriteLine("------------------");
            shifr = shifr % mod;
            Console.WriteLine("Зашифрованное сообщение= "+shifr);
            shifr = 1;
            j = 0;
            resutdvoy = new long[32];
            shortnum = new int[32];
            massost = new int[32];
            if (x<0)
            {
                x = s + x;
            }
            Console.WriteLine(x);
            resutdvoy = Step(x);
           
            for (int i = 0; i < 32; i++)
            {
                if (resutdvoy[i] != 0)
                {
                    shortnum[i] = Convert.ToInt32(Math.Pow(2, i));
                }
            }
            BigInteger[] trymass = new BigInteger[32];
            Console.WriteLine("Введите число для дешифрования");
            Console.WriteLine("---------------");
            int decrypt = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < shortnum.Length; i++)
            {
                if (shortnum[i] != 0)
                {
                    trymass[j] = (BigInteger.Pow(decrypt, shortnum[i]));
                    j++;
                }
            }
          /* Console.WriteLine("----bigint---------");
            for (int i = 0; i < 32; i++)
            {
                Console.WriteLine(trymass[i]);
            }*/
            BigInteger result=1;
            BigInteger test = mod;
            Console.WriteLine("---------------");
            for (int i = 0; i < shortnum.Length; i++)
            {
                result = (trymass[i] % test);
                massost[i] =(int)result;
                    j++;
              
            }
         
         /*   for (int i = 0; i < 32; i++)
            {
                Console.WriteLine(shortnum[i]);
            }
            Console.WriteLine("-----massost----------");
            for (int i = 0; i < 32; i++)
            {
                Console.WriteLine(massost[i]);
            }*/
            for (int i = 0; i < massost.Length; i++)
            {
                if (massost[i] == 0)
                    break;
                else
                {
                    shifr = shifr * massost[i];
                }
            }
            Console.WriteLine("------------------");
            shifr = shifr % mod;
            Console.WriteLine("Дешифрованное сообщение= " + shifr);
        }
        public static int findkey(int s, int p, int q)
        {
            
            return s;
        }
        public static int NOD(int a,int b)
        {
            if (a == b)
                return a;
            else
               if (a > b)
                return NOD(a - b, b);
            else
                return NOD(b - a, a);
        }
      public static int Gcd(int a, int b, out int x, out int y)
        {
            if (b < a)
            {
                var t = a;
                a = b;
                b = t;
            }

            if (a == 0)
            {
                x = 0;
                y = 1;
                return b;
            }

            int gcd = Gcd(b % a, a, out x, out y);

            int newY = x;
            int newX = y - (b / a) * x;

            x = newX;
            y = newY;
            return gcd;
        }
        public static long [] Step(int s)
        {
            long[] dvoy = new long[32];

            string shit = Convert.ToString(s, 2);
          
            int test = Convert.ToInt32(shit);
            for (int i = 0; i < 32; i++)
            {
                if (test > 0)
                {
                    dvoy[i] = test%10;
                    test = test / 10;
                                    
                }
                
                else { break; };
               
            }
            
            return dvoy;
            
        }
        
    }
    
}
