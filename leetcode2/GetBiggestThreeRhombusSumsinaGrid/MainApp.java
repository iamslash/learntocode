// Copyright (C) 2021 by iamslash

import java.util.*;

// 153ms 35.54% 40.7MB 68.07%
// brute force
// O(HW) O(HW)
class Solution {
	private int getRhombusSum(int[][] grid, int len, int y, int x) {
		int sum = 0;
		for (int k = 1; k < len; ++k) {
			sum += grid[y - k][x + k];
			sum += grid[y + k][x + k];
			sum += grid[y - k][x + 2 * len - k];
			sum += grid[y + k][x + 2 * len - k];			
		}
		sum += grid[y][x];
		sum += grid[y][x + 2 * len];
		sum += grid[y + len][x + len];
		sum += grid[y - len][x + len];
		return sum;
	}
	public int[] getBiggestThree(int[][] grid) {
		int h = grid.length, w = grid[0].length;
		Set<Integer> rhombusSet = new HashSet<>();
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; ++x) {
				rhombusSet.add(grid[y][x]);
				for (int len = 1; len <= 25; ++len) {
					if (y - len < 0 || y + len >= h ||
							(x + 2 * len) >= w) {
						continue;
					}
					int rhombusSum = getRhombusSum(grid, len, y, x);
					if (rhombusSum >= 0) {
						rhombusSet.add(rhombusSum);
					}
				}
			}
		}
		return rhombusSet.stream()
				.sorted(Comparator.reverseOrder())
				.limit(3)
				.mapToInt(Integer::intValue)
				.toArray();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
