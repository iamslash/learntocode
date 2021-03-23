// Copyright (C) 2021 by iamslash

import java.util.*;

// 36ms 100.00% 83.3%MB 100.00%
// heap
// O(NlgN) O(N)
class Solution {
	public int getNumberOfBacklogOrders(int[][] orders) {
		int MOD = 1_000_000_007;
		Queue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
		Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
		for (int[] order : orders) {
			if (order[2] == 0) {
				maxHeap.offer(order);
			} else {
				minHeap.offer(order);
			}
			while (!maxHeap.isEmpty() &&
						 !minHeap.isEmpty() &&
						 maxHeap.peek()[0] >= minHeap.peek()[0]) {
				int[] buyOrder = maxHeap.peek();
				int[] sellOrder = minHeap.peek();
				int k = Math.min(buyOrder[1], sellOrder[1]);
				buyOrder[1] -= k;
				sellOrder[1] -= k;
				if (buyOrder[1] == 0) {
					maxHeap.poll();
				}
				if (sellOrder[1] == 0) {
					minHeap.poll();
				}
			}
		}
		int ans = 0;
		for (int[] order : maxHeap) {
			ans = (ans + order[1]) % MOD;
		}
		for (int[] order : minHeap) {
			ans = (ans + order[1]) % MOD;
		}
		return ans;
	}
}
