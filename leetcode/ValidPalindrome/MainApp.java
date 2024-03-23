// Copyright (C) 2024 by iamslash

import java.util.*;

//           i
// amanaplanacanalpanama
//           j

// 22ms 98.99% 42.8MB 74.45%
// brute force
// O(N) O(N)
class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();
        char[] chrs = new char[n];
        int j = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)) {
                chrs[j++] = Character.toLowerCase(c);
            }
        }
        j--;
        for (int i = 0; i < j; ++i, --j) {
            if (chrs[i] != chrs[j]) {
                return false;
            }
        }
        return true;
    }
}
