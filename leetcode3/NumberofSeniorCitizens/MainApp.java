// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int countSeniors(String[] details) {
        int cnt = 0;
        for (String entry : details) {
            int age = (entry.charAt(11) - '0') * 10 + (entry.charAt(12) - '0');
            if (age > 60) {
                cnt++;
            }
        }
        return cnt;
    }
}
