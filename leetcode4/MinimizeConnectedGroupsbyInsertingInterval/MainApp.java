// Copyright (C) 2025 by iamslash

import java.util.*;


//         k: 3
// intervals: 1,3 5,6 8,10
//
//            . . .
//                    . .
//                          . . .
//                - - -
//                      - - -

// Idea: sort, sliding window
//
// Sort intervals[][].
// Get gaps[][].
// Get covered gaps[][].
//
// The answer is gaps - covered gaps + 1

// 93ms 82.35% 106.72MB 17.65%
// sort, sliding window
// O(NlgN) O(N)
class Solution {
    public int minConnectedGroups(int[][] intervals, int k) {
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        List<int[]> gapList = new ArrayList<>();
        int end = intervals[0][1], n = intervals.length;

        // Build gapList
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > end) {
                gapList.add(new int[]{end, intervals[i][0]});                
            }
            end = Math.max(end, intervals[i][1]);            
        }

        // Get coveredGapCnt
        int m = gapList.size(), coveredGapCnt = 0;
        for (int i = 0, j = 0; j < m; ++j) {
            int wndLen = gapList.get(j)[1] - gapList.get(i)[0];
            while (i < j && wndLen > k) {
                i++;
                wndLen = gapList.get(j)[1] - gapList.get(i)[0];
            }
            if (wndLen <= k) {
                coveredGapCnt = Math.max(coveredGapCnt, j - i + 1);
            }            
        }

        return gapList.size() - coveredGapCnt + 1;
    }
}
