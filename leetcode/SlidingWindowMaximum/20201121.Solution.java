// Copyright (C) 2020 by iamslash

import java.util.*;

// 18ms 42.29% 54.5MB 39.20%
// deque
// O(N) O(K)
class Solution {
	public int[] maxSlidingWindow(int[] A, int k) {
		List<Integer> ans = new ArrayList<>();
		Deque<Integer> deq = new ArrayDeque<>();
		for (int i = 0; i < A.length; ++i) {
			while (deq.size() > 0 && A[deq.peekLast()] < A[i])
				deq.removeLast();
			deq.addLast(i);
			
			if (deq.size() > 0 && i >= k - 1)
				ans.add(A[deq.peekFirst()]);

			if (deq.size() > 0 && deq.peekFirst() <= i - k + 1)
				deq.removeFirst();
		}
		return ans.stream().mapToInt(a -> a).toArray();
	}
}
