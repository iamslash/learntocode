// Copyright (C) 2023 by iamslash

import java.util.*;

// binomial coefficient
// O(N) O(N)
// difficult
class Solution {
    public int countGoodSubsequences(String s) {
        int n = s.length(), mod = 1_000_000_007;
        int[] freqs = new int[26];
        for (char c : s.toCharArray()) {
            freqs[c - 'a']++;
        }
        long[] coefs = new long[26];
        long[] invs = new long[n + 1];
        Arrays.fill(coefs, 1);
        invs[0] = invs[1] = 1;
        long ans = 0;
        for (int x = 1; x <= n; ++x) {
            long val = 1;
            if (x >= 2) {
                invs[x] = mod - mod/x * invs[mod % x] % mod;
            }
            for (int i = 0; i < 26; ++i) {
                coefs[i] = coefs[i] * (freqs[i] - x + 1) % mod;
                coefs[i] = coefs[i] * invs[x] % mod;
                val = val * (1 + coefs[i]) % mod;
            }
            ans = (ans + val - 1) % mod;
        }
        return (int)ans;
    }
}
