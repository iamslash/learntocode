// Copyright (C) 2023 by iamslash

import java.util.*;

// 17ms 81.78% 58.3MB 42.38%
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
        Map<Integer, Integer> sumFreqMap = new HashMap<>();
        int sum = 0;
        // Right side of pos
        for (int i = pos; i < n; ++i) {
            sum += nums[i] > k ? 1 : (nums[i] < k ? -1 : 0);
            sumFreqMap.put(sum, sumFreqMap.getOrDefault(sum, 0) + 1);
        }
        // Left side of pos
        sum = 0;
        for (int i = pos; i >= 0; --i) {
            sum += nums[i] > k ? 1 : (nums[i] < k ? -1 : 0);
            ans += sumFreqMap.getOrDefault(0 - sum, 0);
            ans += sumFreqMap.getOrDefault(1 - sum, 0);
        }
        return (int)ans;
    }
}
