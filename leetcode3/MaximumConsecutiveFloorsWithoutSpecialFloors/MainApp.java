// Copyright (C) 2022 by iamslash

import java.util.*;

// 35ms 97.35% 57.7MB 90.43%
// sort
// O(N) O(1)
class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int maxDiff = special[0] - bottom, n = special.length;
        for (int i = 1; i < n; ++i) {
            maxDiff = Math.max(maxDiff, special[i] - special[i-1] - 1);
        }
        return Math.max(maxDiff, top - special[n-1]);
    }
}
