// Copyright (C) 2021 by iamslash

//         g
// groups: 1,-1,-1 3,-2,0
//         i 
//   nums: 1 -1 0 1 -1 -1 3 -2 0
//         j

// greedy algorithm
// O(G^2N) O(N)
class Solution {
	private boolean arrayEquals(int[] a, int [] b, int s) {
		for (int i = 0, j = s; i < a.length && j < b.length; ++i, ++j) {
			if (a[i] != b[j]) {
				return false;
			}
		}
		return true;
	}
	public boolean canChoose(int[][] groups, int[] nums) {
		int i = 0, n = nums.length;
		for (int[] group : groups) {
			boolean found = false;
			for (int j = i; j < n; ++j) {
				found = arrayEquals(group, nums, j);
			}
			if (!found) {
				return false;
			}
		}
		return true;
	}
}
