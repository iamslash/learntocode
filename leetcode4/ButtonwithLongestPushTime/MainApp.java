// Copyright (C) 2024 by iamslash

import java.util.*;

// [[7,1],[19,3],[9,4],[12,5],[2,8],[15,10],[18,12],[7,14],[19,16]]

// 8ms 6.46% 45.1MB 21.44%
// hash map
// O(N) O(1)
class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int[] diffs = new int[100001];
        int maxIdx = 0, maxDiff = 0;

        for (int i = 0; i < events.length; ++i) {
            int idx = events[i][0];
            int diff = i > 0 ? events[i][1] - events[i - 1][1] : events[i][1];
            diffs[idx] = diff;

            if (maxDiff < diffs[idx]) {
                maxIdx = idx;
                maxDiff = diffs[idx];
            } else if (maxDiff == diffs[idx]) {
                maxIdx = Math.min(maxIdx, idx);
            }
        }

        return maxIdx;
    }
}


// 1ms 32.90% 44.9MB 50.85%
// brute force
// O(N) O(1)
class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int maxIdx = events[0][0], maxDiff = events[0][1];
        
        for (int i = 1; i < events.length; ++i) {
            int idx = events[i][0];
            int diff = events[i][1] - events[i - 1][1];

            if (maxDiff < diff) {
                maxIdx = idx;
                maxDiff = diff;
            } else if (maxDiff == diff) {
                maxIdx = Math.min(maxIdx, idx);
            }
        }

        return maxIdx;
    }
}
