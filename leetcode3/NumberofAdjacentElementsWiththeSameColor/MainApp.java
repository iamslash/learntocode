// Copyright (C) 2023 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // brute force
// // O(QN) O(Q)
// class Solution {
//     private void dump(int[] A) {
//         for (int a : A) {
//             System.out.printf("%d ", a);
//         }
//         System.out.println();
//     }
//     public int[] colorTheArray(int n, int[][] queries) {
//         int m = queries.length;
//         int[] ans = new int[m];
//         int[] colors = new int[n];
//         for (int i = 0; i < m; ++i) {
//             colors[queries[i][0]] = queries[i][1];
//             // dump(colors);
//             for (int j = 1; j < n; ++j) {
//                 if (colors[j] != 0 && colors[j-1] == colors[j]) {
//                     ans[i]++;
//                 } 
//             }
//         }
//         return ans;            
//     }
// }

//
//  colors: 2 1 1 1
//     cnt: 2
//                            i 
// queries: 0,2 1,2 3,1 1,1 2,1
//     ans: 0 1 1 0 2

// 6ms 93.77% 104.6MB 55.56%
// hash map
// O(N) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    public int[] colorTheArray(int n, int[][] queries) {
        int m = queries.length, cnt = 0;
        int[] colors = new int[n], ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = queries[i][0], color = queries[i][1];
            int prev = (j > 0) ? colors[j - 1] : 0;
            int next = (j < n - 1) ? colors[j + 1] : 0;

            if (colors[j] != 0 && colors[j] == prev) {
                cnt--;
            }
            if (colors[j] != 0 && colors[j] == next) {
                cnt--;
            }
            colors[j] = color;
            if (colors[j] == prev) {
                cnt++;
            }
            if (colors[j] == next) {
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
}
