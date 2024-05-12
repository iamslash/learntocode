// Copyright (C) 2024 by iamslash

import java.util.*;

// 6ms 80.27% 46.2MB 12.98%
// sort
// O(NlgN) O(1)
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
                if (a[0] == b[0]) {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            });

        int prvEnd = -1;
        for (int[] interval : intervals) {
            if (prvEnd > interval[0]) {
                return false;
            }
            prvEnd = interval[1];
        }

        return true;
    }
}
