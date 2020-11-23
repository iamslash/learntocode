// Copyright (C) 2018 by iamslash

using System;
using System.Linq;
using System.Collections.Generic;

namespace Main
{
    // recursive way
    // 432ms 44.44%
    public class Solution {

        private List<int> m_rslt = new List<int>();
        private int m_n;

        private void dfs() {
            int last = m_rslt.Last() * 10;

            // base
            if (last > m_n)
                return;

            // recursion
            for (int i = last; i <= last+9; ++i) {
                m_rslt.Add(i);
                if (i >= m_n)
                    break;
                dfs();
            }
            return;
        }        
        
        public IList<int> LexicalOrder(int n) {
            m_n = n;
            for (int i = 1; i <= 9; ++i) {
                m_rslt.Add(i);
                if (i >= n)
                    break;
                dfs();
            }
            return m_rslt;
        }
    }
    
    /// <summary>
    /// MainApp startup class for Real-World
    /// </summary>
    class MainApp
    {
        /// <summary>
        /// Entry point into console application.
        /// </summary>
        static void Main()
        {
            Solution sln = new Solution();
            var rslt = sln.LexicalOrder(13);
            foreach (int a in rslt)
                System.Console.Write(a + " ");
        }
    }
}
