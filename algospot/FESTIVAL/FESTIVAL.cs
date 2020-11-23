using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {

   static void Main(String[] args) {
      //C
      string line = Console.ReadLine().Trim();
      int C       = int.Parse(line);
      List<float> l_r = new List<float>();

      for(int n=0; n<C; ++n)
      {
         //L, N    
         List<int> l_line_2 = GetArrFromLine(Console.ReadLine().Trim());
         int N = l_line_2[0]; // 6
         int L = l_line_2[1]; // 3
         //l_costs
         List<int> l_costs = GetArrFromLine(Console.ReadLine().Trim());

         List<float> l_rr = new List<float>();

         for(int i=0; i<N-L+1; ++i)
            for(int j=i+L; j<N+1; ++j)
            {
               int len = j-i;
               //Console.WriteLine( i.ToString() + " " + len.ToString() );
               List<int> l = l_costs.GetRange(i, len);
               float f = l.Aggregate(0, (acc, x) => acc + x) / (float)l.Count; 
               l_rr.Add(f);
            }
         l_r.Add(l_rr.Min(x => x));
      }

      foreach(float f in l_r)
         Console.WriteLine(f.ToString("F11"));
   }

   static List<int> GetArrFromLine(string line)
   {
      List<int> l = new List<int>();

      string[] words = line.Split(' ');
      foreach(string w in words)
      {
         l.Add(int.Parse(w));   
      }

      return l;
   }



}
