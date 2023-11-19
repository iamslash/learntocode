// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 43.4MB 100.00%
// greedy
// O(N) O(1)
class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int bnd = Math.min(n1, Math.min(n2, n3));
        int maxLen = 0;
        for (int i = 0; i < bnd; ++i) {
            if (s1.charAt(i) == s2.charAt(i) &&
                s2.charAt(i) == s3.charAt(i)) {
                maxLen++;
            } else {
                break;
            }
        }
        if (maxLen == 0) {
            return -1;
        }
        return n1 + n2 + n3 - 3 * maxLen;
    }
}
