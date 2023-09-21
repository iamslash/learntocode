// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 1
// nums: 6 0 3 3 6 7 2 7
//                     i
//       0 2 3 3 6 6 7 7
//       .     .       .

// Idea: greedy
//
// Sort nums and consider these cases.
// 1. No selecting anyone
// 2. Selecting and no selecting
// 3. Selecting every ones
//
// 33ms 90.43% 56.7MB 19.33%
// greedy, sort
// O(NlgN) O(1)
class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            int sel = i + 1;
            if (sel > nums.get(i)) {
                if (i == n - 1) {
                    // Last one
                    cnt++;
                } else if (i < n - 1 && sel < nums.get(i + 1)) {
                    cnt++;
                } 
            }
        }
        // System.out.println(cnt);
        // No selecting anyone
        if (nums.get(0) > 0) {
            cnt++;
        }
        // System.out.println(cnt);
        return cnt;
    }
}
