// Copyright (C) 2024 by iamslash

//  zero: 1
//   one: 1
// limit: 2
//
// ans:
// 1 0
// 0 1


// 120ms 77.73% 44.8MB 85.45%
// iterative dynamic programming
// O(ZO) O(ZO)
// Z: zero
// O: one
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1_000_000_007;
        // C[i][j][k]
        // i: count of zero
        // j: count of one
        // k: ends with k
        long[][][] C = new long[zero + 1][one + 1][2];
        C[0][0][0] = C[0][0][1] = 1;

        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                for (int k = 1; k <= limit; ++k) {
                    if (i - k >= 0) {
                        C[i][j][1] = (C[i][j][1] + C[i - k][j][0]) % mod;
                    }
                    if (j - k >= 0) {
                        C[i][j][0] = (C[i][j][0] + C[i][j - k][1]) % mod;
                    }
                }
            }
        }

        return (int)((C[zero][one][0] + C[zero][one][1]) % mod);
    }
}
