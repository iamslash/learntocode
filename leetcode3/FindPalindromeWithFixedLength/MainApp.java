// Copyright (C) 2022 by iamslash

import java.util.*;

// intLength: 3
//   queries: 1 2 3 4 5 90
//

// Idea: 
// when digit is 1, half is 1, the count is 10
// 0
// 1
// 2
// ...
// 9
//
// when digit is 2, half is 1, the count is 9
// 11
// 22
// ...
// 99
//
// when digit is 3, half is 2, the count is 90
// 101
// 111
// 121
// ...
// 191
// 202
// 212
// ...
// 999
//
// when digit is 4, half is 2, the count is 90
// 1001
// 1111
// 1221
// ...
// 1991
// 2002
// 2112
// ...
// 9999
//
// when digit is 5, half is 3, the count is 900
// 10001
// 10101
// 10201
// ...
// 10901
// ...
// 19991
// ...
// 99999
//
// We can make a formula:
// half: (len + 1) / 2
//  beg: 10^(half-1)
//  end: 10^(half) - 1

// 89ms 61.04% 52.2MB 93.63%
// brute force
// O(N) O(N)
class Solution {
    public long[] kthPalindrome(int[] queries, int len) {
        int n = queries.length;
        int half = (len + 1) / 2;
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            int query = queries[i];
            int beg = (int)Math.pow(10, half-1);
            int end = (int)Math.pow(10, half) - 1;
            int cnt = end - beg + 1;
            if (query <= cnt) {
                StringBuilder sb = new StringBuilder();
                sb.append(Integer.toString(beg + query - 1));
                String part1 = sb.toString();
                String part2 = sb.reverse().substring(len % 2);
                ans[i] = Long.valueOf(part1 + part2);
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
}
