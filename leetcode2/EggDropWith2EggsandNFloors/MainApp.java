// Copyright (C) 2023 by iamslash

// 44ms 33.13% 40.4MB 26.93%
// recursive dynamic programming, minmax
// O(N) O(N)
class Solution {
    int[] C = new int[1001];
    public int twoEggDrop(int n) {
        // memo
        if (C[n] > 0) {
            return C[n];
        }
        // recursion
        C[n] = n;
        for (int i = 1; i <= n; ++i) {
            C[n] = Math.min(C[n], 1 + Math.max(i - 1, twoEggDrop(n - i)));
        }
        return C[n];
    }
}

// 0ms 100.00% 39.5MB 85.45%
// math
// O(N) O(N)
class Solution {
    public int twoEggDrop(int n) {
        int ans = 1;
        while (ans * (ans + 1) / 2 < n) {
            ans++;
        }
        return ans;
    }
}
