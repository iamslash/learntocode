// Copyright (C) 2023 by iamslash

import java.util.*;


//       i
// s: 101101
//         j
//    

// Idea: hash map
//
// val ^ first = second
// val ^ 0 = 5
// val = 101 ^ 0
// val = 101
//
// val ^ 1 = 2
// val = 10 ^ 01
// val = 11
// val = first ^ second
//
// It's more convenience to create binary number
// from left to right with mupliplying 2.

// 36ms 85.59% 99.9MB 77.66%
// hash map
// O(N^2) O(N)
class Solution {
    public int[][] substringXorQueries(String s, int[][] queries) {
        int n = s.length(), m = queries.length;
        Map<Integer, int[]> map = new HashMap<>();
        // Fill the map
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                map.putIfAbsent(0, new int[]{i, i});
                continue;
            }
            int num = 0;
            for (int j = i; j < n && j < i + 32; j++) {
                num <<= 1;
                num += (s.charAt(j) - '0');
                map.putIfAbsent(num, new int[]{i, j});
            }
        }
        // Fill the answer
        int[][] ans = new int[m][2];
        int i = 0;
        for (int[] query : queries) {
            int val = query[0] ^ query[1];
            ans[i++] = map.getOrDefault(val, new int[]{-1, -1});
        }
        return ans;
    }
}
