// Copyright (C) 2024 by iamslash

import java.util.*;

//                  i
// internals: 1,3 2,6 8,10 15,18
// mergedSrc: 1,3 
// mergedDst:

// 10ms 28.51% 46.8MB 16.42%
// sort
// O(NlgN) O(N)
class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length, pos = 0;
        int[][] mergedSrc = new int[n][2]; 
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        for (int[] interval : intervals) {
            if (pos == 0 || mergedSrc[pos - 1][1] < interval[0]) {
                mergedSrc[pos][0] = interval[0];
                mergedSrc[pos][1] = interval[1];
                pos++;
            } else {
                mergedSrc[pos - 1][1] = Math.max(mergedSrc[pos - 1][1], interval[1]);
            }
        }

        // build answer
        int[][] mergedDst = new int[pos][2];
        for (int i = 0; i < pos; ++i) {
            mergedDst[i][0] = mergedSrc[i][0];
            mergedDst[i][1] = mergedSrc[i][1];
        }

        return mergedDst;
    }
}
