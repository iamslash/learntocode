// Copyright (C) 2024 by iamslash

import java.util.*;

// intervals:
//        i
// begs:  0  5 15
// ends: 10 20 30
//        j
//
//  ans:  2

// 3ms 99.80% 45.8Mb 75.18%
// sort
// O(NlgN) O(N)
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] begs = new int[n];
        int[] ends = new int[n];

        for (int i = 0; i < n; ++i) {
            begs[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        Arrays.sort(begs);
        Arrays.sort(ends);

        int cnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (begs[i] < ends[j]) {
                cnt++;
            } else {
                j++;
            }
        }

        return cnt;
    }
}
