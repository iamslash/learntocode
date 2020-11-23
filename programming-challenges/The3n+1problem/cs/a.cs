// Copyright (C) 2016 by iamslash
//
// > C:\Program Files\Unity\Editor\Data\MonoBleedingEdge\lib\mono\4.5\mono a.exe

using System;

namespace Main
{
    /// <summary>
    /// MainApp startup class for Real-World
    /// </summary>
    class MainApp
    {
        private int[] CACHE = new int[1000000];

        private int CycleLen(int n) {
            // base condition
            if (n == 1)
                return 1;

            // memoization
            if (CACHE [n] > 0)
                return CACHE [n];

            // recursion
            int r = 0;
            if (n % 2 == 0)
                r = 1 + CycleLen(n / 2);
            else
                r = 1 + CycleLen(n * 3 + 1);				
            CACHE [n] = r;

            return CACHE[n];
        }

        public void Solve() {
            string line;
            while ((line = Console.ReadLine ()) != null) {
                for (int i = 0; i < CACHE.Length; i++) {
                    CACHE[i] = -1;
                }

                string[] split = line.Split (new char[] { ' ' }, StringSplitOptions.None);
                int I = Int32.Parse (split [0]);
                int J = Int32.Parse (split [1]);

                int r = 0;
                for (int i = I; i <= J; ++i) {
                    r = System.Math.Max (r, CycleLen (i));
                }
                Console.WriteLine (string.Format ("{0} {1} {2}", I, J, r));
            }
        }
        
        /// <summary>
        /// Entry point into console application.
        /// </summary>
        static void Main()
        {           
            MainApp mainapp = new MainApp ();
            mainapp.Solve ();
        }
    }
}
