// Copyright (C) 2024 by iamslash

import java.util.*;

//               i
// nums: 3 2 -3 -4
//  prv: 3 5  2

// 0ms 100.00% 41.9MB 78.59%
// math
// O(N) O(1)
class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int cur = 0, cnt = 0;
        for (int num : nums) {
            cur += num;
            if (cur == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}
