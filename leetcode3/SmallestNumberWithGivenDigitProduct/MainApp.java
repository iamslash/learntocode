// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 41MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public String smallestNumber(long n) {
        if (n == 1) {
            return "1";
        }
        StringBuilder sb = new StringBuilder();
        while (n > 1) {
            boolean found = false;
            for (int mod = 9; mod > 1; --mod) {
                if (n % mod == 0) {
                    sb.append((char)('0' + mod));
                    found = true;
                    n /= mod;
                    // System.out.printf("n: %d, mod: %d\n", n, mod);
                    break;
                }
            }
            if (!found) {
                return "-1";
            }
        }
        return sb.reverse().toString();
    }
}
