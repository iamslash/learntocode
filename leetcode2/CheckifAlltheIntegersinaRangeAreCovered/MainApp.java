// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 47.51% 37.1MB 85.06%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean isCovered(int[][] ranges, int left, int right) {
		Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
		for (int[] range : ranges) {
			if (left >= range[0] && left <= range[1]) {
				left = range[1] + 1;
			}
		}
		return left > right;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
