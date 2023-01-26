// Copyright (C) 2023 by iamslash

import java.util.*;

// plantTimes: 1 4 3
//  growTimes: 2 3 1
//
// plantTimes: 4 1 3
//  growTimes: 3 2 1

// 95ms 44.80% 126.2MB 12.98%
// sort
// O(NlgN) O(N)
class Solution {
    public int earliestFullBloom(int[] plantTimes, int[] growTimes) {
        int n = plantTimes.length;
        int[][] times = new int[n][2];
        for (int i = 0; i < n; ++i) {
            times[i][0] = plantTimes[i];
            times[i][1] = growTimes[i];
        }
        Arrays.sort(times, (a, b) -> b[1] - a[1]);
        int ans = 0, plantTimeSum = 0;
        for (int i = 0; i < n; ++i) {
            plantTimeSum += times[i][0];
            ans = Math.max(ans, plantTimeSum + times[i][1]);
        }
        return ans;
    }
}
