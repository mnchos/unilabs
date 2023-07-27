using System;

using System.Collections.Generic;

using System.Linq;

using System.Threading.Tasks;

using System.Windows.Forms;

namespace sii_5

{

    static class Program

    {

        public static int[,] Train = {

{

1,0,0,0,1,//Н

1,0,0,0,1,

1,1,1,1,1,

1,0,0,0,1,

1,0,0,0,1

},

{

1,0,0,0,1,//И

1,0,0,1,1,

1,0,1,0,1,

1,1,0,0,1,

1,0,0,0,1

},

{

1,0,0,0,1, //М

1,0,0,0,1,

1,1,0,1,1,

1,0,1,0,1,

1,0,1,0,1

},

{

1,1,1,1,1,//О

1,0,0,0,1,

1,0,0,0,1,

1,0,0,0,1,

1,1,1,1,1

},

};

        public static int[,] MatrN = {

{

1,0,0,0,1,//Н

1,0,0,0,1,

1,1,1,1,1,

1,0,0,0,1,

1,0,0,0,1

}

};

        public static int[,] MatrI = {

{

1,0,0,0,1,//И

1,0,0,1,1,

1,0,1,0,1,

1,1,0,0,1,

1,0,0,0,1

}

};

        public static int[,] MatrM = {

{

1,0,0,0,1, //М

1,0,0,0,1,

1,1,0,1,1,

1,0,1,0,1,

1,0,1,0,1

}

};

        public static int[,] MatrO = {

{

1,1,1,1,1,//О

1,0,0,0,1,

1,0,0,0,1,

1,0,0,0,1,

1,1,1,1,1

},

};

        public static int[,] y =

        {

{3, -1, -1, -1},

{-1, 3, -1, -1},

{-1, -1, 3, -1},

{-1, -1, -1, 3}

};

        public static double[,] Weght = new double[4, 25];

        [STAThread]

        static void Main()

        {

            Application.EnableVisualStyles();

            Application.SetCompatibleTextRenderingDefault(false);

            Application.Run(new Form1());

        }

    }

}