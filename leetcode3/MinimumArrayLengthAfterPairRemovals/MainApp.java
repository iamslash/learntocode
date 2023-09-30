// Copyright (C) 2023 by iamslash

import java.util.*;

//           i
// nums: 1 4 3 9
//               j
//
//         i
// nums: 2 3 6 9
//             j
//
//       i
// nums: 1 1 2
//         j
//
//           i
// nums: 2 2 2 2
//               j
//
//           i
// nums: 2 2 2 2 2
//                 j
//

// Idea: greedy
//
// nums are sorted non-decreasing (increasing)
//
// 5ms 98.85% 58.2MB 85.75%
// greedy
// O(N) O(1)
class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        int n = nums.size(), i = 0, j = (n + 1)/2, cnt = n;
         while (j < n) {
            int a = nums.get(i), b = nums.get(j);
            if (a < b) {
                cnt -= 2;
            }
            i++;
            j++;
        }
        return cnt;
    }
}
