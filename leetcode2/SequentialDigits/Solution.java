// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.Queue;
import java.util.ArrayList;
import java.util.ArrayDeque;

// 0ms 100.00% 36.7MB 100.00%
// BFS
// O(N) O(N)
class Solution {
	public List<Integer> sequentialDigits(int low, int high) {
		List<Integer> ans = new ArrayList<>();
		Queue<Integer> bfsq = new ArrayDeque<>();
		for (int i = 1; i < 10; i++)
			bfsq.offer(i);
		while (bfsq.size() > 0) {
			int u = bfsq.poll();
			int r = u % 10;
			if (u >= low && u <= high) {
				ans.add(u);
			}
			if (u > high || r == 9) {
				continue;
			}			
			int v = u * 10 + r + 1;
			bfsq.add(v);			
		}
		return ans;
	}
}
