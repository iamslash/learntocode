// Copyright (C) 2021 by iamslash

//         g
// groups: 1,-1,-1 3,-2,0
//         i 
//   nums: 1 -1 0 1 -1 -1 3 -2 0
//         j

// 0ms 100.00% 38.8MB 100.00%
// greedy algorithm
// O(G^2N) O(N)
class Solution {
	private boolean arrayEquals(int[] a, int [] b, int s) {
    // System.out.printf("\ta: %d, b: %d\n", a.length, b.length - s + 1);
    if (a.length > b.length - s) {
      return false;
    }
		for (int i = 0, j = s; i < a.length && j < b.length; ++i, ++j) {
			if (a[i] != b[j]) {
				return false;
			}
		}
		return true;
	}
	public boolean canChoose(int[][] groups, int[] nums) {
		int i = 0, j = 0, n = nums.length;
		for (int[] group : groups) {
			boolean found = false;
			for (j = i; j < n; ++j) {
				found = arrayEquals(group, nums, j);
        // System.out.printf("i: %d, j: %d, found: %b\n", i, j, found);
				if (found) {
					break;
				}
			}
			if (found) {
				i = j + group.length;
			} else {
				return false;
			}
		}
		return true;
	}
}
