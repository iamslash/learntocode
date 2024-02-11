// Copyright (C) 2024 by iamslash

import java.util.*;


//             l
//       i
// nums: 2 2 3 3 4 4 5 7 7
//         j
//                       r



//  tgt: 0
// nums: 1 0 -1 0 -2 2
//               l
//        i
//       -2 -1 0 0 1 2
//             j
//                   r


//  tgt: 8
//       i
// nums: 2 2 2 2 2
//         j

// Idea: two pointers, sort
//
// The index should be distinct.
// It's ok same numbers.
// The quadruplets are distinct.

// 19ms 45.70% 45MB 27.50%
// two pointers, sort
// O(N^3) O(1)
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> ans = new HashSet<>();        
        int n = nums.length;
        Arrays.sort(nums);

        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip same nums[j]
                if (i + 1 < j && nums[j - 1] == nums[j]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                long sum = 0;
                while (l < r) {
                    sum = nums[i]; sum += nums[j];
                    sum += nums[l]; sum += nums[r];
                    if (sum == target) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
                        l++;
                        while (l < r && nums[l - 1] == nums[l]) {
                            l++;
                        }
                        r--;
                        while (l < r && nums[r] == nums[r + 1]) {
                            r--;
                        }                        
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        
        return new ArrayList<List<Integer>>(ans);
    }
}
