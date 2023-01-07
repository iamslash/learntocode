// Copyright (C) 2023 by iamslash

import java.util.*;

//      k: 1
//   nums: 2 5 1 4 3 6
//             1
//             1 4
//           5 1

//      k: 1
//   nums: 2 5 1 4 3 6
//         i
//    sum: 2 1 0 1 2 3
// sumMap:     0 1 2 3
//             1 1 1 1
//         

// 17ms 91.70% 56.2MB 81.26%
// hash map
// O(N) O(N)
class Solution {
    public int countSubarrays(int[] nums, int k) {
        int pos = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                pos = i;
                break;
            }
        }
        long ans = 0;
        Map<Integer, Integer> sumMap = new HashMap<>();
        int sum = 0;
        // right side of pos
        for (int i = pos; i < n; ++i) {
            if (nums[i] > k) {
                sum += 1;
            } else if (nums[i] < k) {
                sum -= 1;
            }
            sumMap.put(sum, sumMap.getOrDefault(sum, 0) + 1);
        }
        System.out.println(sumMap);
        // left side of pos
        sum = 0;
        for (int i = pos; i >= 0; --i) {
            if (nums[i] > k) {
                sum += 1;
            } else if (nums[i] < k) {
                sum -= 1;
            }
            ans += sumMap.getOrDefault(0 - sum, 0);  // median of odd
            ans += sumMap.getOrDefault(1 - sum, 0);  // median of even
            System.out.printf("i: %d, sum: %d, ans: %d\n", i, sum, ans);
        }
        
        return (int)ans;
    }
}
