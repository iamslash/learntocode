// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 3 2 4 5 0
// 

// heap
// O(NlgN) O(N)
class Solution {
    public int convertArray(int[] nums) {
        int n = nums.length, cnt1 = 0, cnt2 = 0, diff = 0;
        Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; ++i) {
            if (!maxHeap.isEmpty() && maxHeap.peek() >= nums[i]) {
                diff = maxHeap.poll() - nums[i];
                cnt1 += diff;
                maxHeap.offer(nums[i]);
            }
            maxHeap.offer(nums[i]);
        }
        diff = 0;
        Queue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            if (!minHeap.isEmpty() && minHeap.peek() <= nums[i]) {
                diff = nums[i] - minHeap.poll();
                cnt2 += diff;
                minHeap.offer(nums[i]);
            }
            minHeap.offer(nums[i]);
        }
        return Math.min(cnt1, cnt2);
    }
}
