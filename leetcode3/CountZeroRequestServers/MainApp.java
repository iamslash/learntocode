// Copyright (C) 2023 by iamslash

import java.util.*;

//    n: 3
//    x: 2
//                       i
// logs: 2,1 3,1 1,2 2,4
//                 j
// qrys: 3 4
// cnts: 1 2 3
//       1 1 0

//    n: 6
//    x: 10
//          i
// logs: 1,21
//        
// qrys: 12 16 20 24 25 26 28 31 35
// cnts: 1 2 3 4 5 6
//       0 0 0 0 0 0

// 23ms 100.00% 83.6MB 72.33%
// sort, sliding window
// O(NlgN) O(N)
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int m = queries.length, i = 0, j = 0, used = 0;
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);
        Integer[] idxs = new Integer[m];
        for (int k = 0; k < m; ++k) {
            idxs[k] = k;
        }
        Arrays.sort(idxs, (a, b) -> queries[a] - queries[b]);
        int[] cnts = new int[n + 1];
        int[] ans = new int[m];
        for (int k : idxs) {
            int fr = queries[k] - x;
            int to = queries[k];
            // Add server count 
            while (i < logs.length && logs[i][1] <= to) {
                if (++cnts[logs[i][0]] == 1) {
                    used++;
                }
                i++;
            }
            // Sub server count
            while (j < logs.length && logs[j][1] < fr) {
                if (--cnts[logs[j][0]] == 0) {
                    used--;
                }
                j++;
            }
            // System.out.printf("k: %d, fr: %d, to: %d, i: %d, j: %d, used: %d\n", k, fr, to, i, j, used);
            ans[k] = n - used;
        }
        return ans;
    }
}
