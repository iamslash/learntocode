// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 97.83% 40.3MB 90.22%
// iterative dynamic programming
// O(2^N*N) O(N)
// difficult
class Solution {
    public int selfDivisiblePermutationCount(int n) {
        int bnd = 1 << n;
        int[] C = new int[bnd];
        C[0] = 1;

        for (int i = 1; i < bnd; i++) {
            int ones = Integer.bitCount(i);
            for (int j = n - 1; j >= 0; j--) {
                if (((i >> j) & 1) == 1 && gcd(ones, j + 1) == 1) {
                    C[i] += C[i ^ (1 << j)];
                }
            }
        }

        return C[bnd - 1];
    }

    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
