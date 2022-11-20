// Copyright (C) 2022 by iamslash

import java.util.*;

// 129ms 27.73% 89.9MB 97.25%
// partial sum, hash map
// O(NlgN) O(N)
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        TreeMap<Integer, Integer> cntMap = new TreeMap<>();
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '*') {
                cnt++;
            } else {
                cntMap.put(i, cnt);
            }
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int[] qry = queries[i];
            Integer fr = cntMap.ceilingKey(qry[0]);
            Integer to = cntMap.floorKey(qry[1]);
            if (fr != null && to != null && fr < to) {
                ans[i] = cntMap.get(to) - cntMap.get(fr);
            }
        }
        return ans;        
    }
}


//         i
//      s: * | * | *
//           j
//     ps: 1 1 2 2
//  lefts: - 1 1 3
// rights: 1 1 3 3 5

// 25ms 65.77% 143.4MB 32.28%
// partial sum
// O(N) O(N)
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length(), m = queries.length;
        int[] ps = new int[n];
        int[] lefts = new int[n];
        int[] rights = new int[n];
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
            lefts[i] = left;
        }
        for (int i = n-1, right = n; i >= 0; --i) {
            if (s.charAt(i) == '|') {
                right = i;
            }
            rights[i] = right;
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int beg = rights[queries[i][0]];
            int end = lefts[queries[i][1]];
            if (beg >= 0 && end < n && beg < end) {
                ans[i] = ps[end] - ps[beg];
            }
        }
        return ans;
    }
}
