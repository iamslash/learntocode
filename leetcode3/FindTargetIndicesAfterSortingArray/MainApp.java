// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 57.14% 39.2MB 42.86%
// sort
// O(NlgN) O(N)
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans.add(i);
            }
        }
        return ans;
    }
}

// 0ms 100.00% 39MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> ans = new ArrayList<>();
        int targetCnt = 0, startIdx = 0;
        for (int num : nums) {
            if (num < target) {
                startIdx++;
            } else if (num == target) {
                targetCnt++;
            }
        }
        while (targetCnt-- > 0) {
            ans.add(startIdx++);
        }
        return ans;
    }
}
