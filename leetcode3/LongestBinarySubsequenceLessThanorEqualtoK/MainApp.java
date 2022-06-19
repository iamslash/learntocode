// Copyright (C) 2022 by iamslash

import java.util.*;

//    s: 1 0 0 0 0 1
//       0 0 0 0 1 1
//       1 1 0 0 0 0

//    k: 4
//    s: 1 0 0 1 0 1 0
//       i
//  ans: 5
// cost: 8


// Idea: greedy
//
// Take all zeros
// Take as many 1 from the right as we can

//    k: 2
//    s: 1 0 0 0 0 1
//               i
// zero: 4
//  one: 1 
//  val: 1
//  pow: 2

// 1ms 100.00% 40.5MB 83.33%x
// greedy
// O(N) O(1)
class Solution {
    public int longestSubsequence(String s, int k) {
        int zeroCnt = 0, oneCnt = 0, n = s.length();
        for (char c : s.toCharArray()) {
            if (c == '0') {
                zeroCnt++;
            }
        }
        int val = 0, pow = 1;
        for (int i = n-1; i >= 0 && val + pow <= k; --i) {
            if (s.charAt(i) == '1') {
                oneCnt++;
                val += pow;
            }
            pow <<= 1;
        }
        return zeroCnt + oneCnt;
    }
}
