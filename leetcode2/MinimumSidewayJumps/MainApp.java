// Copyright (C) 2021 by iamslash

import java.util.*;

// . x . . .
// f . x . .
// . . . x .

// Time Limit Exceeded
// BFS
// O(N) O(N)
class Solution {
	public int minSideJumps(int[] obstacles) {
		int n = obstacles.length;
		// lane, point, side jumps
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[]{2,0,0});
		while (q.size() > 0) {
			int[] item = q.poll();
			int lane = item[0];
			int point = item[1];
			int jumps = item[2];
      // System.out.printf("lane: %d, point: %d, jumps: %d\n", lane, point, jumps);
			if (point >= n-1) {
				return jumps;
			}
			if (obstacles[point+1] != lane) {
				q.offer(new int[]{lane, point+1, jumps});
			} else {
				for (int nlane = 1; nlane <= 3 ; ++nlane) {
					if (lane != nlane && obstacles[point] != nlane) {
						q.offer(new int[]{nlane, point, jumps+1});
					}
				}
			}
		}
		return 0;
	}
}

// iterative dynamic programming
// O(N) O(1)
class Solution {
	private final int MAXVAL = 1000000;
	public int minsideJumps(int[] obstacles) {
		// C[i]: minimum side jumps at i lane
		int C = {1, 0, 1};
		for (int obs in obstacles) {
			if (obs > 0) {
				C[obs-1] = MAXVAL;
			}
			for (int i = 0; i < 3; ++i) {
				if (obs != i + 1) {
					C[i] = Math.min(C[i], Math.min(C[(i+1)%3], C[(i+2)%3]) + 1);
				}
			}
		}
		return Math.min(C[0], Math.min(C[1], C[2]));
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
