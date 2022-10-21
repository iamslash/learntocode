// Copyright (C) 2022 by iamslash

import java.util.*;

//            
// s: 0 0 1 1 0 1
//    0   1   0
//    0     1 0
//      0 1   0
//      0   1 0
//        1   0 1
//          1 0 1

// Idea: iterative dynamic programming
//
//  _1: count ends with 1
// _01: count ends with 01
//  _0: count ends with 0
// _10: count ends with 10
//
//   current character is 0
//      total count: total count + _01
//       _0 += 1
//      _10 += _1
//   current character is 1
//      total count: total count + _10
//       _1 += 1
//      _01 += _0

// 34ms 85.67% 69MB 35.54%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long numberOfWays(String s) {
        long cnt = 0;
        // count ends with 1, 01, 0, 10
        long _1 = 0, _01 = 0, _0 = 0, _10 = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') {
                cnt += _01;
                _0++;
                _10 += _1;
            } else {
                cnt += _10;
                _1++;
                _01 += _0;
            }
        }
        return cnt;
    }
}
