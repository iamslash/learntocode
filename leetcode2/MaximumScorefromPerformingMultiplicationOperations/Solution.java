// Copyright (C) 2021 by iamslash

import java.util.*;

// 136ms 16.67% 50.1MB 83.33%
// recursive dynamic programming
// O(M^2) O(M^2)
class Solution {
	private int dfs(int[] nums, int[] mults, int[][] C, int l, int i) {
		// base
		if (i >= mults.length) {
			return 0;
		}
		// C
		if (C[l][i] > Integer.MIN_VALUE) {
			return C[l][i];
		}
		// recursion
		int r = nums.length - 1 - (i - l);
		int pickLeft = nums[l] * mults[i] +
				dfs(nums, mults, C, l+1, i+1);
		int pickRight =  nums[r] * mults[i] +
				dfs(nums, mults, C, l, i+1);
		return C[l][i] = Math.max(pickLeft, pickRight);
	}
	public int maximumScore(int[] nums, int[] mults) {
		int m = mults.length;
		int[][] C = new int[m][m];
		for (int i = 0; i < m; ++i) {
			Arrays.fill(C[i], Integer.MIN_VALUE);
		}
		return dfs(nums, mults, C, 0, 0);
	}
}

// 156ms 16.67% 65.9MB 33.33%
// recursive dynamic programming
// O(M^2) O(M^2)
class Solution {
	private int dfs(int[] nums, int[] mults, Integer[][] C, int l, int i) {
		// base
		if (i >= mults.length) {
			return 0;
		}
		// C
		if (C[l][i] != null) {
			return C[l][i];
		}
		// recursion
		int r = nums.length - 1 - (i - l);
		int pickLeft = nums[l] * mults[i] +
				dfs(nums, mults, C, l+1, i+1);
		int pickRight =  nums[r] * mults[i] +
				dfs(nums, mults, C, l, i+1);
		return C[l][i] = Math.max(pickLeft, pickRight);
	}
	public int maximumScore(int[] nums, int[] mults) {
		int m = mults.length;
		Integer[][] C = new Integer[m][m];
		return dfs(nums, mults, C, 0, 0);
	}
}


//   1 2 3
// 3       
// 2     
// 1     
// 52ms 100.00% 49MB 100.00%
// iterative dynamic programming
// O(M^2) O(M^2)
class Solution {
	public int maximumScore(int[] nums, int[] mults) {
		int n = nums.length;
		int m = mults.length;
		int[][] C = new int[m+1][m+1];
		for (int[] arr : C) {
			Arrays.fill(arr, Integer.MIN_VALUE);
		}
		for (int i = 0; i <= m; i++) {
			C[i][m-i] = 0;
		}
		for (int i = m-1; i >= 0; i--) {
			for (int l = 0; l <= i; l++) {
				int r = i-l;
				C[l][r] = Math.max(C[l+1][r] + nums[l] * mults[i],
													 C[l][r+1] + nums[n-r-1] * mults[i]);
			}
		}
		return C[0][0];
	}
}
