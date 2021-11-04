// Copyright (C) 2021 by iamslash

import java.util.*;

//                              i
//         s: * * | * * | * * * |
//         q: 2,5 5,9
// candleMap: 2 5 9
//            2 4 7

// 99ms 26.14% 86.1MB 88.34%
// hash map
// O(NlgN) O(N)
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        // build map
        TreeMap<Integer, Integer> candleMap = new TreeMap<>();
        int plateCnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '*') {
                plateCnt++;
            } else {
                candleMap.put(i, plateCnt);
            }
        }
        // query
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            Integer fr = candleMap.ceilingKey(queries[i][0]);
            Integer to = candleMap.floorKey(queries[i][1]);
            if (fr != null && to != null && fr < to) {
                ans[i] = candleMap.get(to) - candleMap.get(fr);
            }
        }
        return ans;
    }
}

// 7ms 97.19% 98.3MB 45.71%
// partial sum
// O(N) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length();
        int[] ps = new int[n], dnIdxs = new int[n], upIdxs = new int[n];
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (s.charAt(i) == '*') {
                cnt++;
            } 
            ps[i] = cnt;
            
        }
        for (int i = 0, prv = -1; i < n; ++i) {
            if (s.charAt(i) == '|') {
                prv = i;
            }
            dnIdxs[i] = prv;
        }
        for (int i = n-1, prv = n; i >= 0; --i) {
            if (s.charAt(i) == '|') {
                prv = i;
            }
            upIdxs[i] = prv;
        }
        // dump(ps);
        // dump(dnIdxs);
        // dump(upIdxs);
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int beg = upIdxs[queries[i][0]];
            int end = dnIdxs[queries[i][1]];

            if (beg < n && end >= 0 && beg < end) {
                ans[i] = ps[end] - ps[beg];
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
