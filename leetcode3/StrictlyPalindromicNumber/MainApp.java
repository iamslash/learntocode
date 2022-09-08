// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 45.42% 41.1MB 37.32%
// brute force
// O(N^2) O(1)
class Solution {
    private boolean valid(int num, int base) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % base);
            num /= base;
        }
        // System.out.printf("%s %s\n", sb.toString(), sb.reverse().toString());
        return sb.toString() == sb.reverse().toString();
    }
    public boolean isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; ++base) {
            if (!valid(n, base)) {
                return false;
            }
        }
        return true;
    }
}
