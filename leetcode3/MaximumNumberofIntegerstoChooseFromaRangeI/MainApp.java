// Copyright (C) 2023 by iamslash

import java.util.*;

// 57ms 75.35% 43.1MB 93.93%
// hash set
// O(N) O(N)
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> numSet = new HashSet<>();
        for (int a : banned) {
            numSet.add(a);
        }
        int cnt = 0;
        for (int a = 1; a <= n; ++a) {
            if (numSet.contains(a)) {
                continue;
            }
            if (a > maxSum) {
                break;
            }
            maxSum -= a;
            cnt++;
        }
        return cnt;
    }
}
