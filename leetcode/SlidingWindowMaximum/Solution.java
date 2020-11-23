// Copyright (C) 2020 by iamslash

import java.util.*;

// 29ms 34.95% 56.4MB 22.43%
// sliding window, double ended queue
// O(N) O(N)
class Solution {
	public int[] maxSlidingWindow(int[] nums, int k) {
		int[] ans = new int[nums.length-k+1];
		Deque<Integer> deq = new ArrayDeque<>();
		for (int i = 0; i < nums.length; ++i) {
			// make descending order
			while (deq.size() > 0 && nums[deq.getLast()] < nums[i]) {
				deq.pollLast();
			}
			deq.addLast(i);
			// add max val
			if (deq.size() > 0 && i >= k - 1) {
				ans[i-k+1] = nums[deq.getFirst()];
			}
			// remove one out of index
			while (deq.size() > 0 && deq.getFirst() <= i-k+1) {
				deq.pollFirst();
			}
		}
		return ans;
	}
}
