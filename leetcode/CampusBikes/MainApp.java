// Copyright (C) 2021 by iamslash

import java.util.*;

// 50ms 82.44% 70.1MB 94.01%
// brute force
// O(WB) O(WB)
class Solution {
	public int[] assignBikes(int[][] workers, int[][] bikes) {
		List<List<int[]>> dist2pairs = new ArrayList<>();
		for (int i = 0; i < 2001; ++i) {
			dist2pairs.add(new ArrayList<>());
		}
		for (int i = 0; i < workers.length; ++i) {
			for (int j = 0; j < bikes.length; ++j) {
				int d = Math.abs(workers[i][0] - bikes[j][0]) +
						Math.abs(workers[i][1] - bikes[j][1]);
				dist2pairs.get(d).add(new int[]{i, j});
			}
		}
		int[] ans = new int[workers.length];
		Arrays.fill(ans, -1);
		boolean[] usedBike = new boolean[bikes.length];
		for (int d = 0; d < 2000; ++d) {
			for (int[] pair : dist2pairs.get(d)) {
				int workerIdx = pair[0];
				int bikeIdx = pair[1];
				if (ans[workerIdx] < 0 && !usedBike[bikeIdx]) {
					ans[workerIdx] = bikeIdx;
					usedBike[bikeIdx] = true;
				}
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
		// 0 2 1
		Solution sln = new Solution();
		System.out.println(Arrays.toString(sln.assignBikes(
				new int[][]{{0,0},{2,1}},
				new int[][]{{1,2},{3,3}})));
  }
}
