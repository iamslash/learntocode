// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: hash map
//
// S[i..j]: sum of nums[i]..nums[j]
// S[i..j]: S[0..j] - S[0..i-1]
// S[i..j] % k == 0 means
//   (S[0..j] - S[0..i-1]) % k == 0
//   S[0..j] % k == S[0..i-1] % k

// 25ms 38.31% 57.2MB 93.79%
// hash map
// O(N) O(N)
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;

        Map<Integer, Integer> modIdxMap = new HashMap<>();
        modIdxMap.put(0, -1);

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                nums[i] += nums[i-1];
            }

            int mod = nums[i] % k;
            if (modIdxMap.containsKey(mod)) {
                if (i - modIdxMap.get(mod) >= 2) {
                    return true;
                }
            } else {
                modIdxMap.put(mod, i);
            }
        }

        return false;
    }
}
