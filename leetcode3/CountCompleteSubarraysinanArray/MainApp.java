// Copyright (C) 2023 by iamslash

import java.util.*;


//      k: 3
//             i
//   nums: 1 3 1 2 2
//                 j
// cntMap: 
//         
//    ans: 4
//
//         1 3 1 2
//           3 1 2
//         1 3 1 2 2
//           3 1 2 2

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
                cntMap.put(nums[j], cntMap.get(nums[j]) - 1);
                if (cntMap.get(nums[j]) == 0) {
                    k++;
                }
                i++;
            }
            ans += i;
        }
        return ans;
    }
}
