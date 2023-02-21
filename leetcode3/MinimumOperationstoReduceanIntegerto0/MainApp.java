// Copyright (C) 2023 by iamslash

import java.util.*;

//                i
//   n: 1 1 0 1 1 0
// cnt: 0

//      i
//   n: 1 0 0 1 1 1
//      1 0 1 0 0 0
// cntL 2

// Idea: bit manipulation
//
// continuous 1 means +1
//     single 1 means +1
//     single 0 means +0

// 0ms 100.00% 38.9MB 77.46%
// bit manipulation
// O(N) O(1)
class Solution {
    public int minOperations(int n) {
        // System.out.println(Integer.toBinaryString(n));
        int cnt = 0;
        while (n > 0) {
            // System.out.printf("n: %s, cnt: %d\n", Integer.toBinaryString(n), cnt);
            if ((n & 3) == 3) {
                cnt++;
                n++;
            } else {
                cnt += (n & 1);
            }
            n >>= 1;
        }
        return cnt;
    }
}
