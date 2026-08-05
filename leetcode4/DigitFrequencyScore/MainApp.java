// Copyright (C) 2026 by iamslash

// 0ms 100.00% 42.57MB 70.82%
// math
// O(N) O(1)
class Solution {
    public int digitFrequencyScore(int n) {
        int ans = 0;

        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
}
