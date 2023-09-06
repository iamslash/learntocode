// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 99.90% 41.4MB 97.87%
// brute force
// O(1) O(1)
class Solution {
    public boolean canBeEqual(String s1, String s2) {
        char[] a = s1.toCharArray(), b = s2.toCharArray();
        boolean evenValid = (a[0] == b[0] && a[2] == b[2]) ||
            (a[0] == b[2] && a[2] == b[0]);
        boolean oddValid = (a[1] == b[1] && a[3] == b[3]) ||
            (a[1] == b[3] && a[3] == b[1]);
        return evenValid && oddValid;
    }
}
