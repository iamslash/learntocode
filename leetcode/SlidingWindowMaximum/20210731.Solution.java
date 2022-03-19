// Copyright (C) 2020 by iamslash

import java.util.*;

// 29ms 33.48% 53.7MB 62.01%
// deque
// O(N) O(N)
class Solution {
	public int[] maxSlidingWindow(int[] nums, int k) {
		int n = nums.length;
		Deque<Integer> deq = new ArrayDeque();
		int[] ans = new int[n-k+1];
		for (int i = 0; i < n; ++i) {
			// make deq ordered desc
			while (deq.size() > 0 && nums[deq.peekLast()] < nums[i]) {
				deq.pollLast();
			}
			deq.offer(i);	
			// insert max to ans
			if (deq.size() > 0 && i >= k-1) {
				ans[i-k+1] = nums[deq.peekFirst()];
			}
			// remove
			while (deq.size() > 0 && deq.peekFirst() <= i-k+1) {
				deq.pollFirst();
			}
		}
		return ans;
	}
}
