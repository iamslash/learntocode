// Copyright (C) 2022 by iamslash

import java.util.*;

//               i
// milestones: 1 2 5
//             

// 2ms 99.55% 52MB 99.55%
// greedy
// O(N) O(1)
class Solution {
    public long numberOfWeeks(int[] milestones) {
        int maxMilestone = -1;
        long sum = 0;
        for (int milestone : milestones) {
            maxMilestone = Math.max(maxMilestone, milestone);
            sum += milestone;
        }
        long remain = sum - maxMilestone;
        if (remain + 1 < maxMilestone) {
            return remain + remain + 1;
        }
        return sum;                                    
    }
}
