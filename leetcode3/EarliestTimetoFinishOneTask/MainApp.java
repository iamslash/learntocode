// Copyright (C) 2025 by iamslash

import java.util.*;


// 1ms 90.00% 46.88MB 47.47%
// math
// O(N) O(1)
class Solution {
    public int earliestTime(int[][] tasks) {
        int minEndTime = Integer.MAX_VALUE;

        for (int[] task : tasks) {
            minEndTime = Math.min(minEndTime, task[0] + task[1]);
        }

        return minEndTime;
    }
}
