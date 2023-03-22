// Copyright (C) 2023 by iamslash

import java.util.*;

//  cars: 10
// ranks: 1 2 3 4
//        7 1 1 1    49  2  3  4    49
//        4 2 2 2    16  8 12 16    16
//        1 3 3 3     1 18 27 36    36

// Idea: binary search
// A mechanic spend `r * n * n` mins to repair n cars.
//   r: rank, n: the number of cars
// We need to find mid minutes to repair total cars.
// Binary search `mid` minutes from 0 to 10^14.
//   r * n * n = mid
//       n * n = mid / r
//           n = sqrt(mid / r)
// A mechanic repair `sqrt(mid / r)` cars for mid minutes.

// 138ms 36.89% 50.1MB 76.33%
// binary search (left most equal)
// O(NlgN) O(1)
class Solution {
    public long repairCars(int[] ranks, int cars) {
        long lo = 0, hi = (long)1e14;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            long repaired = 0;
            for (int rank : ranks) {
                repaired += Math.sqrt(mi / rank);
            }
            if (repaired < cars) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
}
