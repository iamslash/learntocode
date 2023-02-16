// Copyright (C) 2023 by iamslash

import java.util.*;

// lower: 3
// upper: 6
//        i
//  nums: 0 1 4 4 5 7
//                  j
//   ans: 
//

// 27ms 73.35% 59.6MB 93.88%
// sort
// O(NlgN) O(1)
class Solution {
    private long countLess(int[] nums, int bnd) {
        long ans = 0;
        int n = nums.length;
        for (int i = 0, j = n - 1; i < j; ++i) {
            while (i < j && nums[i] + nums[j] > bnd) {
                j--;
            }
            ans += j - i;
        }
        // System.out.printf("bnd: %d, ans: %d\n", bnd, ans);
        return ans;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        int i = 0, j = 0, n = nums.length;
        return countLess(nums, upper) - countLess(nums, lower - 1);
    }
}
