// Copyright (C) 2022 by iamslash

import java.util.*;

// intervals: 0,30 5,10 15,20
//                     i
//     start:  0  5 15
//       end: 10 20 30
//                j

// intervals: 7,10 2,4
//                i
//      begs: 2 7
//      ends: 4 10
//               j

// 4ms 95.90% 44.9MB 63.22%
// sort, two pointers
// O(NlgN) O(1)
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length, ans = 0;
        int[] begs = new int[n];
        int[] ends = new int[n];
        for (int i = 0; i < n; ++i) {
            begs[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        Arrays.sort(begs);
        Arrays.sort(ends);
        for (int i = 0, j = 0; i < n; ++j) {
            while (i < n && begs[i] < ends[j]) {
                i++;
                ans = Math.max(ans, i - j);
            }
        }
        return ans;
    }
}
