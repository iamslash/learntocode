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

// 3ms 99.71% 43.9MB 65.62%
// two pointers, sort
// O(N^3) O(N)
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();        
        int n = nums.length;
        Arrays.sort(nums);

        for (int i = 0; i < n - 3; ++i) {
            // Pruning: 
            if (i > 0 && nums[i] == nums[i - 1]) { continue; } 
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) { break; }
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) { continue; }
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Pruning: 
                if (j > i + 1 && nums[j] == nums[j - 1]) { continue; } 
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) { break; }
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) { continue; }
                
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long sum = nums[i]; sum += nums[j];
                    sum += nums[l]; sum += nums[r];
                    if (sum == target) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
                        l++;
                        // Skip same nums[l]
                        while (l < r && nums[l - 1] == nums[l]) {
                            l++;
                        }
                        r--;
                        // Skip same nums[r]
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
        
        return ans;
    }
}
