// Copyright (C) 2023 by iamslash

import java.util.*;

//   divisor1: 2
//   divisor2: 7
// uniqueCnt1: 1
// uniqueCnt2: 3
//
//       arr1: 1
//       arr2: 2 3 4

// Idea: binary serach (left most equal)
//
// Let's find last number when we combine arr1, arr2.
//   lcm(div1, div2) = div1 * div2 / gcd(div1, div2) 
//     mi: last number
//   cnt1: count of arr1 = mi - mi / div1
//   cnt2: count of arr2 = mi - mi / div2
// cntAll: count of arr1, arr2 = mi - mi / lcm(div1, div2)

// 0ms 100.00% 39MB 67.32%
// binary search (left most equal)
// O(lgN) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public int minimizeSet(int divisor1, int divisor2,
                           int uniqueCnt1, int uniqueCnt2) {
        long lo = 1, hi = (int)10e10;
        long ans = hi;
        long lcm = ((long)divisor1 * (long)divisor2) / gcd(divisor1, divisor2);
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            int cnt1 = (int)(mi - mi / divisor1);
            int cnt2 = (int)(mi - mi / divisor2);
            int cntAll = (int)(mi - mi / lcm);
            if (cnt1 < uniqueCnt1 || cnt2 < uniqueCnt2 || cntAll < uniqueCnt1 + uniqueCnt2) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return (int)lo;
    }
}
