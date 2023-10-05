// Copyright (C) 2023 by iamslash

import java.util.*;

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

//  tgt: 4
// nums: 1 1 1 2 3
//  sum: 8
//   ps: 16
//                           i
//       1 1 1 2 3 1 1 1 2 3
//  map: 0 1 2 3 5 8 9 10 11 13 16
//       - 0 1 2 3 4 5  6  7  8  9
//  ans: 2

//  tgt: 3
// nums: 2 4 6 8
//  sum: 20
//   ps: 40
//                       i
//       2 4 6 8 2 4 6 8
//  map: 0 2 6 12 20 22 26 32 40
//       - 0 1  2  3  4  5  6  7
//  ans: 4


// sliding window
// O(N) O(1)
class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int n = nums.length, ans = Integer.MAX_VALUE, 
    }
}
