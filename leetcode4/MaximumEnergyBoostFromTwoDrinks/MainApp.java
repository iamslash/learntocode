// Copyright (C) 2025 by iamslash

import java.util.*;

//           i
//  A: 1 3 1
//  B: 3 1 1
//     
// a1: 1 4 5
// b1: 3 4 5
// a0: 1 4 5
// b0: 3 4 5

// Idea: iterative dynamic programming
//
// a[i]: max energy at i hours ending with A
// b[i]: max energy at i hours ending with B
//
// a[i] = max(a[i - 1] + A[i], b[i - 1])
// b[i] = max(b[i - 1] + B[i], a[i - 1])
//
// a0: a[i - 1]
// a1: a[i]
// b0: b[i - 1]
// b1: b[i]
//
// 3ms 100.00% 57.83MB 82.97%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        long a0 = 0, a1 = 0, b0 = 0, b1 = 0, n = energyDrinkA.length;

        for (int i = 0; i < n; ++i) {
            a1 = Math.max(a0 + energyDrinkA[i], b0);
            b1 = Math.max(b0 + energyDrinkB[i], a0);
            a0 = a1;
            b0 = b1;
        }

        return Math.max(a1, b1);
    }
}
