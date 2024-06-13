// Copyright (C) 2024 by iamslash

import java.util.*;

// 1 1  1  1
// 1 2  3  4
// 1 3  6 10
// 1 4 10 20
// 1 5 15 35
// 1 6 21 56

// brute force
// O(NK) O(N)
class Solution {
    public int valueAfterKSeconds(int n, int k) {
        int mod = 1_000_000_007;
        int[] ps = new int[n];
        Arrays.fill(ps, 1);

        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                ps[i] = (ps[i - 1] + ps[i]) % mod;
            }
        }

        return ps[n - 1];
    }
}
