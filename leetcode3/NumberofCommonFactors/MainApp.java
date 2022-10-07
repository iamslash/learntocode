// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 25.00% 41.1MB 50.00%
class Solution {
    public int commonFactors(int a, int b) {
        int ans = 1;
        int bnd = Math.min(a, b);
        for (int factor = 2; factor <= bnd; ++factor) {
            if (a % factor == 0 && b % factor == 0) {
                ans++;
            }
        }
        return ans;
    }
}

// 0ms 100.00% 40.9MB 75.00%z
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public int commonFactors(int a, int b) {
        int ans = 1, bnd = gcd(a, b);
        for (int factor = 2; factor <= bnd; ++factor) {
            if (a % factor == 0 && b % factor == 0) {
                ans++;
            }
        }
        return ans;
    }
}
