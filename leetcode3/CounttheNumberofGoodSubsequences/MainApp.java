// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: combination
//
// (1+C(n1,k)) * (1+C(n2,k)) * ...... * (1+C(n26,k)) - 1
// C(n1, k) means combinations of character 'a' and frequency is k.
// 1+ means not choosing any
// -1 means empty sequences
// loops k from 1 to max frequency of [a..z]

// 139ms 34.43% 41.9MB 93.44%
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

// 30ms 70.49% 42.3MB 62.30%
// binomial coefficient
// O(N) O(1)
class Solution {
    private static long[] fact = new long[10001];
    private static long[] inv = new long[10001];
    private static int mod = 1_000_000_007;
    static {
        fact[0] = 1;
        inv[0] = 1;
        for (int a = 1; a <= 10_000; ++a) {
            fact[a] = (fact[a-1] * a) % mod;
            inv[a] = powmod(fact[a], mod-2, mod);
        }
    }
    private static long powmod(long a, long b, int p) {
        long ans = 1, base = a;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * base) % p;
            }
            base = (base * base) % p;
            b >>= 1;
        }
        return ans;
    }
    private long combi(long n, long k, int p) {
        return (((fact[(int)n] * inv[(int)k]) % p) * inv[(int)(n-k)]) % p;
    }
    public int countGoodSubsequences(String s) {
        long ans = 0, maxFreq = 0, n = s.length();
        int[] freqs = new int[26];
        for (int i = 0; i < n; ++i) {
            freqs[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            maxFreq = Math.max(maxFreq, freqs[i]);
        }
        for (int k = 1; k <= maxFreq; ++k) {
            long cnt = 1;
            for (int i = 0; i < 26; ++i) {
                if (freqs[i] >= k) {
                    cnt = (cnt * (1 + combi(freqs[i], k, mod))) % mod;
                }
            }
            cnt--;
            ans = (ans + cnt) % mod;
        }
        return (int)ans;
    }
}
