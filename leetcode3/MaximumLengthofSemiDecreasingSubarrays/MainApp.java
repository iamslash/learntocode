// Copyright (C) 2023 by iamslash

import java.util.*;

// 13ms 61.70% 57.9MB 17.02%
// mono stack
// O(N) O(N)
class Solution {
    public int maxSubarrayLength(int[] nums) {
        Stack<Integer> stck = new Stack<>();
        int n = nums.length;
        for (int i = n - 1; i >= 0; --i) {
            if (stck.isEmpty() || nums[i] < nums[stck.peek()]) {
                stck.push(i);
            }
        }
        int ans = 0, maxNum = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            while (!stck.isEmpty() && stck.peek() <= i) {
                stck.pop();
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                while (!stck.isEmpty() && nums[stck.peek()] < maxNum) {
                    ans = Math.max(ans, stck.peek() - i + 1);
                    stck.pop();
                }
            }
        }
        return ans;
    }
}
