// Copyright (C) 2021 by iamslash

import java.util.*;

// 168ms 44.16% 135.3MB 30.61%
// priority queue
// O(NlgN) O(N)
class Solution {
	public int[] getOrder(int[][] tasks) {
		int n = tasks.length;
		int[] ans = new int[n];
		// index, start, end
		int[][] extTasks = new int[n][3];
		for (int i = 0; i < n; ++i) {
			extTasks[i][0] = i;
			extTasks[i][1] = tasks[i][0];
			extTasks[i][2] = tasks[i][1];
		}
		Arrays.sort(extTasks, (a, b) -> a[1] - b[1]);
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
				if (a[2] == b[2]) {
					return a[0] - b[0];
				}
				return a[2] - b[2];
		});
		int time = 0, ansIdx = 0, taskIdx = 0;
		while (ansIdx < n) {
			while (taskIdx < n && extTasks[taskIdx][1] <= time) {
				pq.offer(extTasks[taskIdx++]);
			}
			if (pq.isEmpty()) {
				time = extTasks[taskIdx][1];
				continue;
			}
			int[] top = pq.poll();
			ans[ansIdx++] = top[0];
			time += top[2];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
