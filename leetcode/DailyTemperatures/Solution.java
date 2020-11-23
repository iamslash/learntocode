// Copyright (C) 2020 by iamslash

import java.util.*;


// 21ms 44.24% 73.8MB 5.03%
// stack
// O(N) O(N)
class Solution {
	public int[] dailyTemperatures(int[] T) {
		Deque<Integer> deque = new ArrayDeque<>();
		int[] ans = new int[T.length];
		for (int i = 0; i < T.length; ++i) {
			while (!deque.isEmpty() && T[deque.peekLast()] < T[i]) {
				int j = deque.pollLast();
				ans[j] = i - j;
        // System.out.printf("\tj: %d, T[j]: %d\n", j, T[j]);
			}
      // System.out.printf("i:%d, T[i]: %d\n", i, T[i]);
			deque.addLast(i);
		}
		return ans;
	}
}
