// Copyright (C) 2023 by iamslash

import java.util.*;

// 11ms 33.33% 44.3MB 16.67%
// brute foce
// O(N) O(N)
class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        for (int i = 0; i < n / 2; ++i) {
            if (chars[n-1-i] < chars[i]) {
                chars[i] = chars[n-1-i];
            }
            chars[n-1-i] = chars[i];
        }
        return new String(chars);
    }
}
