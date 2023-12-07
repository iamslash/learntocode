// Copyright (C) 2023 by iamslash

import java.util.*;

//          i
// num: 35427

// 836ms 5.02% 50.3MB 5.51%
// brute force
// O(N) O(N)
class Solution {
    public String largestOddNumber(String num) {
        StringBuilder buf = new StringBuilder();
        String ans = "";
        for (char c : num.toCharArray()) {
            buf.append(c);
            if ((c - '0') % 2 > 0) {
                ans = buf.toString();
            }
        }
        return ans;
    }
}

// 1ms 100.00% 44.5MB 47.65%
// backward traversal
// O(N) O(1)
class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; --i) {
            char c = num.charAt(i);
            int digit = c - '0';
            if (digit % 2 == 1) {
                return num.substring(0, i + 1);
            }
        }
        return "";
    }
}
