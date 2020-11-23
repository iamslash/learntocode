// Copyright (C) 2020 by iamslash

import java.util.Queue;
import java.util.PriorityQueue;

// priority queue
// O(NlgN) O(N)
class Solution {
	public int lastStoneWeight(int[] S) {
		Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
		for (int s : S)
			pq.offer(s);
		while (pq.size() > 1) {
			int a = pq.poll();
			int b = pq.poll();
			if (a > b)
				pq.offer(a-b);
		}
		Integer r = pq.poll();
        if (r == null)
					return 0;
        return r;
	}
}
