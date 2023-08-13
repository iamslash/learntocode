// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: sliding window
//
//           i
// nums: 1 3 1 2 2 3
//             j
//       1 3 1 2
//         3 1 2
//
//           i
// nums: 1 3 1 2 2 3
//               j
//       1 3 1 2 2
//         3 1 2 2
//
//           i
// nums: 1 3 1 2 2 3
//                 j
//       1 3 1 2 2
//         3 1 2 2

// 7ms 90.19% 44MB 34.11%
// sliding window, hash map
// O(N) O(N)
class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        int n = nums.length, k = numSet.size(), ans = 0, i = 0;
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int j = 0; j < n; ++j) {
            if (cntMap.getOrDefault(nums[j], 0) == 0) {
                k--;
            }
            cntMap.put(nums[j], cntMap.getOrDefault(nums[j], 0) + 1);
            while (k == 0) {
                cntMap.put(nums[i], cntMap.get(nums[i]) - 1);
                if (cntMap.get(nums[i]) == 0) {
                    k++;
                }
                i++;
            }
            ans += i;
        }
        return ans;
    }
}

//      k: 1
//               i
//   nums: 1 3 1 2 2 3
//                   j
// cntMap: 1 2 3
//         0 2 1
//    ans: 7
//
//         1 3 1 2
//           3 1 2
//         1 3 1 2 2
//           3 1 2 2
//         1 3 1 2 2 3
//           3 1 2 2 3
//             1 2 2 3



