// Copyright (C) 2021 by iamslash

import java.util.*;

// k: 1
// matrix:
// 5 2
// 1 6

// 320ms 49.73% 167.5MB 78.31%
// priority queue
// O(N^2lgK) O(K)
class Solution {
	public int kthLargestValue(int[][] matrix, int k) {
		int h = matrix.length, w = matrix[0].length;
		Queue<Integer> pq = new PriorityQueue<>();
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int num = matrix[y][x];
				if (y > 0) {
					num ^= matrix[y-1][x];
				}
				if (x > 0) {
					num ^= matrix[y][x-1];
				}
				if (y > 0 && x > 0) {
					num ^= matrix[y-1][x-1];
				}
				matrix[y][x] = num;
				pq.offer(num);
				while (pq.size() > k) {
					pq.poll();
				}
			}
		}
		return pq.peek();
	}
}
