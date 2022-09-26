// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 42.7MB 9.86%
// hash map
// O(1) O(1)
class Solution {
    int[] days = new int[]{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    private int dayOfYear(String s) {
        return days[(s.charAt(0) - '0') * 10 + (s.charAt(1) - '0') - 1] +
            (s.charAt(3) - '0') * 10 + (s.charAt(4) - '0');
    }
    public int countDaysTogether(String aa, String la,
                                 String ab, String lb) {
        return Math.max(0,
                        Math.min(dayOfYear(la), dayOfYear(lb)) -
                        Math.max(dayOfYear(aa), dayOfYear(ab)) + 1);
    }
}
