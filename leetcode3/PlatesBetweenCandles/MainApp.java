// Copyright (C) 2022 by iamslash

import java.util.*;

//     i
// s: ***|**|*****|**||**|*
//                     j
// q: 1,17 4,5 14,17 5,11 15,16

// // 234ms 5.95% 139.6MB 55.48%
// // hash map
// // O(NlgN) O(N)
// class Solution {
//     public int[] platesBetweenCandles(String s, int[][] queries) {
//         TreeMap<Integer, Integer> cntMap = new TreeMap<>();
//         int cnt = 0;
//         for (int i = 0; i < s.length(); ++i) {            
//             if (s.charAt(i) == '*') {
//                 cnt++;
//             } else {
//                 cntMap.put(i, cnt);
//             }
//         }
//         int[] ans = new int[queries.length];
//         for (int i = 0; i < queries.length; ++i) {
//             Integer fr = cntMap.ceilingKey(queries[i][0]);
//             Integer to = cntMap.floorKey(queries[i][1]);
//             if (fr != null && to != null && fr < to) {
//                 ans[i] = cntMap.get(to) - cntMap.get(fr);
//             }
//         }
//         return ans;
//     }
// }

// 20ms 7636% 162.6MB 11.61%
// prefix sum
// O(N) O(N)
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length(), m = queries.length;
        int[] ps = new int[n], leftIdxs = new int[n], rightIdxs = new int[n];
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (s.charAt(i) == '*') {
                cnt++;
            }                
            ps[i] = cnt; 
        }
        for (int i = 0, left = -1; i < n; ++i) {
            if (s.charAt(i) == '|') {
                left = i;
            }
            leftIdxs[i] = left;
        }
        for (int i = n-1, right = n; i >= 0; --i) {
            if (s.charAt(i) == '|') {
                right = i;
            }
            rightIdxs[i] = right;
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int beg = rightIdxs[queries[i][0]];
            int end = leftIdxs[queries[i][1]];
            if (beg >= 0 && end < n && beg < end) {
                ans[i] = ps[end] - ps[beg];
            }
        }
        return ans;
    }
}
