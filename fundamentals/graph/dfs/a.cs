// Copyright (C) 2016 by iamslash
//
// > C:\Program Files\Unity\Editor\Data\MonoBleedingEdge\lib\mono\4.5\mono a.exe

using System;
using System.Collections.Generic;
using System.Linq;

namespace Main
{
    class MainApp
    {
        int N = 5;
        List<List<int>> adj = new List<List<int>>();
        List<int> discovered = new List<int>();
        int counter = 0;

        void BuildGraph(int n) {
            adj = Enumerable.Repeat(new List<int>(), n).ToList();
            discovered = Enumerable.Repeat(-1, n).ToList();
            counter = 0;

            adj[0].Add(1);
            adj[1].Add(2);
            adj[1].Add(3);
            adj[2].Add(3);            
        }

        void Dfs(int here) {
            Console.Write(string.Format("{0} ", here));
            discovered[here] = counter++;

            for (int i = 0; i < adj[i].Count; ++i) {
                int there = adj[here][i];
                if (discovered[there] == -1) {
                    Dfs(there);
                }
            }
        }
        
        void Solve() {
            BuildGraph(N);

            for (int i = 0; i < N; ++i) {
                if (discovered[i] == -1)
                    Dfs(i);
            }
        }
        
        static void Main()
        {           
            MainApp mainapp = new MainApp ();
            mainapp.Solve ();
        }
    }
}
