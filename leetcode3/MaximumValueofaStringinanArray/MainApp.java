// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 75.12% 41.5MB 79.01%
// brute force
// O(N) O(1)
class Solution {
    private int getValue(String s) {
        for (char c : s.toCharArray()) {
            if (c < '0' || c > '9') {
                return s.length();
            }
        }
        return Integer.parseInt(s);
    }
    public int maximumValue(String[] strs) {
        int maxVal = 0;
        for (String s : strs) {
            maxVal = Math.max(maxVal, getValue(s));
        }
        return maxVal;
    }
}
