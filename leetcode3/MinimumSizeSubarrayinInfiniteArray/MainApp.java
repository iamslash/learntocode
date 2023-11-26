// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea:
//
// The answer is the shortest subarray of the array infinite nums.
// Let's focus on subarray.
//
// Let's say there is a nums[] [a, b, c], target is b + c. ps is an
// incremental sum of nums[i].  `i - index of (ps - target)` is a
// candidate.
//
// a
// a b
// a b c          ps - target = a
// a b c a
// a b c a b      
// a b c a b c    ps - target = a b c a  
//
// Let's use psIdxMap for partial sum, index.
// At first, consider the target is multiple of sum.
// The target should be less than sum.
// target = target % sum.
//
// 48ms 22.98% 73MB 13.35% 
// partial sum, iterative dynamic programming
// O(N) O(N)
class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        long sum = 0L, ps = 0L;
        for (int num : nums) {
            sum += num;
        }
        int n = nums.length;
        int quo = (int)(target / sum);
        int ans = n;
        target %= sum;
        // target == quo * sum
        if (target == 0) {
            return quo * n;
        }
        // target != quo * sum
        HashMap<Long, Integer> psIdxMap = new HashMap<>();
        psIdxMap.put(0L, -1);
        for (int i = 0; i < 2 * n; ++i) {
            ps += nums[i % n];
            if (psIdxMap.containsKey(ps - target)) {
                ans = Math.min(ans, i - psIdxMap.get(ps - target));
            }
            psIdxMap.put(ps, i);
        }
        if (ans == n) {
            return -1;
        }
        return ans + quo * n;
    }
}

//  tgt: 5
// nums: 1 2 3
//  sum: 6
//   ps: 0
//       i
// nums: 1 2 3 1 2 3
//  map: 0 
//       - 
//  ans: 0

//  tgt: 8
// nums: 1 2 3
//  sum: 6
//   ps: 0
//       i
// nums: 1 2 3 1 2 3
//  map: 0 
//       - 
//  ans: 0

